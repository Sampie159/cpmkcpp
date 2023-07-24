#include "cpmk.hh"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

static bool is_valid(const std::string &language);
static void create_directories(const std::string &project_path);
static void create_files(const std::string &project_path,
                         const std::string &project_name,
                         const std::string &language);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                          PUBLIC FUNCTIONS                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void setup_project(std::unique_ptr<Cpmk> cpmk) {
  if (!is_valid(cpmk->language)) {
    std::cout << "Invalid language: " << cpmk->language << "\n";
    std::cout << "Please try again with \"c\" or \"cpp\".\n";

    return;
  }

  std::string cwd = std::filesystem::current_path();
  std::string project_path = cwd + "/" + cpmk->project_name;

  create_directories(project_path);
  create_files(project_path, cpmk->project_name, cpmk->language);

  std::cout << "Project \"" << cpmk->project_name
            << "\" created successfully.\n";
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                          PRIVATE FUNCTIONS                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static bool is_valid(const std::string &language) {
  return language == "c" || language == "cpp";
}

static void create_directories(const std::string &project_path) {
  std::filesystem::create_directory(project_path);
  std::filesystem::create_directory(project_path + "/src");
}

static void create_files(const std::string &project_path,
                         const std::string &project_name,
                         const std::string &language) {
  std::string src_path = project_path + "/src";

  std::string cmake_file = project_path + "/CMakeLists.txt";
  std::string src_file = src_path + "/main." + language;
  std::string src_cmake_file = src_path + "/CMakeLists.txt";

  std::string src_content;
  if (language == "c") {
    src_content = "#include <stdio.h>\n\nint main() {\n  printf(\"Hello, "
                  "World!\\n\");\n\n  return 0;\n}\n";
  } else {
    src_content = "#include <iostream>\n\nint main() {\n  std::cout << "
                  "\"Hello, World!\\n\";\n\n  return 0;\n}\n";
  }
  std::string cmake_content = "cmake_minimum_required(VERSION 3.10)\n\n"
                              "project(" +
                              project_name + ")\n\n";
  if (language == "c") {
    cmake_content += "set(CMAKE_C_STANDARD 17)\n"
                     "set(CMAKE_C_STANDARD_REQUIRED True)\n\n";
  }

  cmake_content += "set(CMAKE_CXX_STANDARD 17)\n"
                   "set(CMAKE_CXX_STANDARD_REQUIRED True)\n\n"
                   "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})\n\n"
                   "add_subdirectory(src)\n";

  std::string src_cmake_content = "cmake_minimum_required(VERSION 3.10)\n\n"
                                  "add_executable(\n  " +
                                  project_name + "\n  main." + language +
                                  "\n)\n";

  std::ofstream src(src_file);
  src << src_content;
  src.close();

  std::ofstream cmake(cmake_file);
  cmake << cmake_content;
  cmake.close();

  std::ofstream src_cmake(src_cmake_file);
  src_cmake << src_cmake_content;
  src_cmake.close();
}
