import os
import subprocess
import platform
def setup_cmake_build(build_folder="build"):
    project_dir = os.getcwd()
    build_path = os.path.join(project_dir, build_folder)
    if not os.path.exists(build_path):
        os.makedirs(build_path)
    try:
        subprocess.run(["cmake", ".."], cwd=build_path, check=True)
    except subprocess.CalledProcessError as e:
        print(f"\n[?] Error: {e}")
    except FileNotFoundError:
        print("\n[?] No CMake")
if __name__ == "__main__":
    folder_name = platform.system()
    setup_cmake_build(folder_name)