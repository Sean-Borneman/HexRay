def export_with_pyghidra():
    """Export decompiled code using pyghidra"""
    
    import pyghidra
    from pathlib import Path
    
    # Setup paths
    ghidra_install_dir = r"C:\Users\Sean\Documents\school\CMU\PPP\ghidra_11.4.2_PUBLIC_20250826\ghidra_11.4.2_PUBLIC"
    project_dir = Path("./ghidra_projects").resolve()
    project_name = "engine_analysis"
    output_dir = Path("./decompiled_txt")
    output_dir.mkdir(exist_ok=True)
    
    print(f"🚀 Using pyghidra to export decompiled code...")
    print(f"📁 Project: {project_name}")
    print(f"💾 Output: {output_dir}")
    
    # Initialize pyghidra
    print("🔧 Starting Ghidra...")
    pyghidra.start(ghidra_install_dir)
    
    # Import Ghidra classes
    from pyghidra.launcher import HeadlessGhidraLauncher
    from ghidra.base.project import GhidraProject
    from ghidra.app.decompiler import DecompInterface
    from ghidra.program.model.listing import FunctionManager
    
    print("📂 Opening existing Ghidra project...")
    
    # Open project
    project = GhidraProject.openProject(str(project_dir), project_name, False)
    programs = project.getViewedPrograms()
    
    if not programs:
        print("❌ No programs found in project")
        return
    
    program = programs[0]  # Get the first (and likely only) program
    print(f"📄 Opened program: {program.getName()}")
    
    # Setup decompiler
    print("🔧 Setting up decompiler...")
    decompiler = DecompInterface()
    decompiler.openProgram(program)
    
    # Get all functions
    function_manager = program.getFunctionManager()
    functions = function_manager.getFunctions(True)  # True = forward iterator
    
    print("🔄 Extracting functions...")
    
    count = 0
    functions_exported = []
    
    for function in functions:
        func_name = function.getName()
        
        # Skip system functions
        if func_name.startswith("__") or "@plt" in func_name:
            continue
        
        print(f"📝 Processing: {func_name}")
        
        try:
            # Decompile the function
            results = decompiler.decompileFunction(function, 30, None)
            
            if results.decompileCompleted():
                decompiled_code = results.getDecompiledFunction().getC()
                
                # Clean filename
                clean_name = "".join(c for c in func_name if c.isalnum() or c in "._-")
                output_file = output_dir / f"{clean_name}.txt"
                
                # Write to file
                with open(output_file, 'w') as f:
                    f.write(f"Function: {func_name}\n")
                    f.write(f"Address: {function.getEntryPoint()}\n")
                    f.write(f"Size: {function.getBody().getNumAddresses()} bytes\n")
                    f.write("=" * 60 + "\n\n")
                    f.write(decompiled_code)
                
                functions_exported.append((func_name, clean_name))
                count += 1
                
            else:
                print(f"⚠️ Failed to decompile: {func_name}")
                
        except Exception as e:
            print(f"❌ Error processing {func_name}: {e}")
    
    # Create summary file
    print("📋 Creating summary...")
    summary_file = output_dir / "00_SUMMARY.txt"
    with open(summary_file, 'w') as f:
        f.write("DECOMPILED FUNCTIONS SUMMARY\n")
        f.write(f"Generated from: {program.getName()}\n")
        f.write(f"Total functions exported: {count}\n")
        f.write("=" * 50 + "\n\n")
        
        for func_name, filename in functions_exported:
            f.write(f"File: {filename}.txt\n")
            f.write(f"Function: {func_name}\n")
            f.write("-" * 30 + "\n")
    
    # Cleanup
    decompiler.dispose()
    project.close()
    
    print(f"✅ Export completed!")
    print(f"📄 Exported {count} functions")
    print(f"📁 Files saved to: {output_dir}")
    
    # Show what was created
    txt_files = list(output_dir.glob("*.txt"))
    if txt_files:
        print(f"\n📝 Created files:")
        for f in sorted(txt_files)[:10]:
            print(f"   - {f.name}")
        if len(txt_files) > 10:
            print(f"   ... and {len(txt_files) - 10} more")
            
        # Show a sample
        non_summary_files = [f for f in txt_files if f.name != "00_SUMMARY.txt"]
        if non_summary_files:
            sample_file = non_summary_files[0]
            print(f"\n📖 Sample from {sample_file.name}:")
            print("-" * 40)
            with open(sample_file, 'r') as f:
                lines = f.readlines()[:10]
                print(''.join(lines))
            print("-" * 40)

# Run the export
export_with_pyghidra()