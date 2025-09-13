import pyghidra
from pathlib import Path

def export_consolidated_code_and_data():
    """Export all C code to one file and all data to another file"""
    
    # Setup paths
    script_dir = Path(__file__).parent
    ghidra_install_dir = script_dir.parent / "Ghidra_full_open_source_install" / "ghidra_11.4.2_PUBLIC"
    ghidra_install_dir_str = str(ghidra_install_dir.resolve())
    
    project_dir = Path("./ghidra_projects").resolve()
    output_dir = Path("./decompiled_output")
    output_dir.mkdir(exist_ok=True)
    
    # Find project
    rep_files = list(project_dir.glob("*.rep"))
    if not rep_files:
        print(f"No projects found")
        return
    
    project_name = rep_files[0].stem
    print(f"Found project: {project_name}")
    
    print("Starting Ghidra...")
    pyghidra.start(ghidra_install_dir_str)
    
    from ghidra.base.project import GhidraProject
    from ghidra.app.decompiler import DecompInterface
    from ghidra.program.model.listing import Data
    from ghidra.program.model.symbol import SymbolType
    from ghidra.program.model.mem import MemoryBlock
    from java.lang import Object
    
    print("Opening Ghidra project...")
    
    try:
        project = GhidraProject.openProject(str(project_dir), project_name, False)
        project_data = project.getProjectData()
        root_folder = project_data.getRootFolder()
        
        domain_files = []
        for df in root_folder.getFiles():
            if df.getContentType() == "Program":
                domain_files.append(df)
        
        if not domain_files:
            print("No programs found")
            return
        
        consumer = Object()
        program = domain_files[0].getDomainObject(consumer, False, False, None)
        
        print(f"Opened program: {program.getName()}")
        
        # ========== CREATE CONSOLIDATED C CODE FILE ==========
        print("Consolidating all C functions...")
        
        all_functions_file = output_dir / "ALL_FUNCTIONS.c"
        
        decompiler = DecompInterface()
        decompiler.openProgram(program)
        
        function_manager = program.getFunctionManager()
        functions = function_manager.getFunctions(True)
        
        function_count = 0
        
        with open(all_functions_file, 'w', encoding='utf-8') as f:
            # Write header
            f.write("/*" + "=" * 78 + "\n")
            f.write(" * CONSOLIDATED DECOMPILED FUNCTIONS\n")
            f.write(f" * Program: {program.getName()}\n")
            f.write(f" * Generated: {program.getCreationDate()}\n")
            f.write(" * " + "=" * 76 + "\n")
            f.write(" */\n\n")
            
            f.write("#include <stdio.h>\n")
            f.write("#include <stdlib.h>\n")
            f.write("#include <string.h>\n\n")
            
            # Process each function
            for function in functions:
                func_name = function.getName()
                
                # Skip system functions
                if func_name.startswith("__") or "@plt" in func_name:
                    continue
                
                print(f"Adding function: {func_name}")
                
                try:
                    results = decompiler.decompileFunction(function, 30, None)
                    if results.decompileCompleted():
                        decompiled_code = results.getDecompiledFunction().getC()
                        
                        # Write function separator
                        f.write("/" + "*" * 77 + "\n")
                        f.write(f" * Function: {func_name}\n")
                        f.write(f" * Address: {function.getEntryPoint()}\n")
                        f.write(f" * Size: {function.getBody().getNumAddresses()} bytes\n")
                        f.write(" " + "*" * 77 + "/\n\n")
                        
                        # Write the actual decompiled code
                        f.write(decompiled_code)
                        f.write("\n\n")
                        
                        function_count += 1
                        
                except Exception as e:
                    f.write(f"/* ERROR: Could not decompile {func_name}: {e} */\n\n")
        
        # ========== CREATE CONSOLIDATED DATA FILE ==========
        print("Consolidating all data...")
        
        all_data_file = output_dir / "ALL_DATA.txt"
        
        listing = program.getListing()
        memory = program.getMemory()
        
        data_count = 0
        string_count = 0
        symbol_count = 0
        
        with open(all_data_file, 'w', encoding='utf-8') as f:
            # Write header
            f.write("=" * 80 + "\n")
            f.write("CONSOLIDATED DATA EXPORT\n")
            f.write(f"Program: {program.getName()}\n")
            f.write(f"Generated: {program.getCreationDate()}\n")
            f.write("=" * 80 + "\n\n")
            
            # ========== MEMORY BLOCKS AND DATA ==========
            f.write("/" + "*" * 78 + "\n")
            f.write(" * MEMORY BLOCKS AND DATA SECTIONS\n")
            f.write(" " + "*" * 78 + "/\n\n")
            
            for block in memory.getBlocks():
                block_name = block.getName()
                block_start = block.getStart()
                block_end = block.getEnd()
                
                f.write(f"Block: {block_name}\n")
                f.write(f"Range: {block_start} - {block_end}\n")
                f.write(f"Size: {block.getSize()} bytes\n")
                f.write("-" * 60 + "\n")
                
                # Get data in this block
                data_iterator = listing.getDefinedData(block_start, True)
                block_data_count = 0
                
                for data_item in data_iterator:
                    if data_item.getAddress().compareTo(block_end) > 0:
                        break
                    
                    data_type = data_item.getDataType()
                    data_address = data_item.getAddress()
                    
                    try:
                        data_value = data_item.getValue()
                        data_str = str(data_value) if data_value else "undefined"
                    except:
                        data_str = "undefined"
                    
                    f.write(f"  {data_address}: {data_type} = {data_str}\n")
                    block_data_count += 1
                    data_count += 1
                
                f.write(f"Items in block: {block_data_count}\n\n")
            
            # ========== STRINGS ==========
            f.write("/" + "*" * 78 + "\n")
            f.write(" * STRING DATA\n")
            f.write(" " + "*" * 78 + "/\n\n")
            
            data_iterator = listing.getDefinedData(True)
            for data_item in data_iterator:
                data_type = data_item.getDataType()
                
                # Check if it's a string type
                if "string" in str(data_type).lower() or "char" in str(data_type).lower():
                    try:
                        value = data_item.getValue()
                        if value and len(str(value)) > 1:
                            f.write(f"{data_item.getAddress()}: {data_type} = {repr(str(value))}\n")
                            string_count += 1
                    except:
                        pass
            
            f.write(f"\nTotal strings: {string_count}\n\n")
            
            # ========== SYMBOLS ==========
            f.write("/" + "*" * 78 + "\n")
            f.write(" * SYMBOL TABLE\n")
            f.write(" " + "*" * 78 + "/\n\n")
            
            symbol_table = program.getSymbolTable()
            symbols = symbol_table.getAllSymbols(True)
            
            # Group symbols by type
            symbol_types = {}
            for symbol in symbols:
                symbol_type = str(symbol.getSymbolType())
                if symbol_type not in symbol_types:
                    symbol_types[symbol_type] = []
                symbol_types[symbol_type].append(symbol)
                symbol_count += 1
            
            # Write symbols grouped by type
            for sym_type, sym_list in symbol_types.items():
                f.write(f"--- {sym_type} ({len(sym_list)} symbols) ---\n")
                for symbol in sym_list[:50]:  # Limit to 50 per type to avoid huge files
                    f.write(f"  {symbol.getAddress()}: {symbol.getName()}\n")
                if len(sym_list) > 50:
                    f.write(f"  ... and {len(sym_list) - 50} more\n")
                f.write("\n")
            
            # ========== SUMMARY ==========
            f.write("=" * 80 + "\n")
            f.write("EXPORT SUMMARY\n")
            f.write("=" * 80 + "\n")
            f.write(f"Functions exported: {function_count}\n")
            f.write(f"Data items: {data_count}\n")
            f.write(f"Strings: {string_count}\n")
            f.write(f"Symbols: {symbol_count}\n")
            f.write("=" * 80 + "\n")
        
        # Cleanup
        decompiler.dispose()
        
        print("Consolidated export completed!")
        print(f"ALL_FUNCTIONS.c: {function_count} functions")
        print(f"ALL_DATA.txt: {data_count} data items, {string_count} strings, {symbol_count} symbols")
        print(f"Output directory: {output_dir.resolve()}")
        
        # Show file sizes
        functions_size = all_functions_file.stat().st_size
        data_size = all_data_file.stat().st_size
        print(f"Functions file size: {functions_size:,} bytes")
        print(f"Data file size: {data_size:,} bytes")
        
    finally:
        if 'program' in locals():
            program.release(consumer)
        if 'project' in locals():
            project.close()

# Run the consolidated export
# export_consolidated_code_and_data()