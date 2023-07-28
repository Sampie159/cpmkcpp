#include "cpmk.hh"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <language> <project_name>"
              << std::endl;
    return 1;
  }

  std::unique_ptr<Cpmk> cpmk = std::make_unique<Cpmk>(argv[1], argv[2]);

  cpmk->setup_project();

  return 0;
}
