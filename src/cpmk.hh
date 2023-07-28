#pragma once

#include <memory>
#include <string>

struct Cpmk {
public:
  Cpmk(const std::string &language, const std::string &project_name)
      : language(language), project_name(project_name) {}
  void setup_project();

private:
  std::string language;
  std::string project_name;
};
