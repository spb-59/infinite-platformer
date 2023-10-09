
import subprocess
import os
import re

def runCommand(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    
    if process.returncode == 0:
        return f"Command: {command}\nSuccessfully run\n"
    else:
        return f"Command: {command}\nError: {stderr.decode('utf-8')}"

def exe_name(filename):
    filename = filename.replace(".cpp", "")
    filename = filename.replace("main", "run")
    return filename


    

command = "g++ main-1-1.cpp player.cpp -Wpedantic"


file_list = os.listdir(".")
cpp_files = [file_name for file_name in file_list if file_name.endswith(".cpp")]
mains = [file_name for file_name in cpp_files if re.match(r"main-\d+-\d+.cpp", file_name)]
others = [file_name for file_name in cpp_files if file_name not in mains]


starter = "g++ "
ender = " " + " ".join(others) + " -I/opt/homebrew/Cellar/sfml/2.6.0/include -L//opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system -o "

for file_name in mains:
    command  = starter + file_name + ender + exe_name(file_name)
    print(runCommand(command))