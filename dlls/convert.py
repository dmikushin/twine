import re
import argparse

def parse_makefile(makefile_content):
    data = {}
    current_key = None
    for line in makefile_content.splitlines():
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        if '=' in line:
            key, value = line.split('=', 1)
            current_key = key.strip()
            data[current_key] = value.replace(
                '\\', '').replace('-D', '').replace('(','{').replace(')','}').strip()
        elif current_key:
            data[current_key] += ' ' + line.replace(
                '\\', '').replace('-D', '').replace('(','{').replace(')','}').strip()
    return data

def convert_to_cmake(data):
    if 'STATICLIB' in data:
        cmake_content = "add_wine_staticlib({}\n".format(data.get('STATICLIB', '').replace('.a', ''))
    elif 'MODULE' in data:
        cmake_content = "add_wine_dll({}\n".format(data.get('MODULE', '').replace('.dll',''))
    else:
        raise ValueError("Error: Neither MODULE nor STATICLIB is present in the Makefile.")

    for key, value in data.items():
        if key in ['MODULE', 'STATICLIB']:
            continue
        cmake_content += "    {}\n".format(key)
        for item in re.split(r'\s+', value.strip()):
            cmake_content += "        {}\n".format(item)
    cmake_content += ")\n"
    return cmake_content

def main():
    parser = argparse.ArgumentParser(description='Convert Makefile to CMake format.')
    parser.add_argument('input_filename', type=str, help='The input Makefile.in filename')
    parser.add_argument('output_filename', type=str, help='The output CMakeLists.txt filename')
    args = parser.parse_args()

    with open(args.input_filename, 'r') as file:
        makefile_content = file.read()

    data = parse_makefile(makefile_content)
    cmake_content = convert_to_cmake(data)

    with open(args.output_filename, 'w') as file:
        file.write(cmake_content)

    print(f"Output has been written to {args.output_filename}")

if __name__ == "__main__":
    main()

