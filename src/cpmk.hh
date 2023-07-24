#pragma once

#include <memory>
#include <string>

struct Cpmk {
  Cpmk(const std::string &language, const std::string &project_name)
      : language(language), project_name(project_name) {}

  std::string language;
  std::string project_name;
};

void setup_project(std::unique_ptr<Cpmk> cpmk);
