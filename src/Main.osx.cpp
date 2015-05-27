// Main.osx.cpp
// Main function for the final executable on OS X

#include "NomadInterface.h"

#include <string>

int main(int argc, const char * argv[]) {
  if (argc == 2) {
    
    const char* arg = argv[argc - 1];
    if (strcmp(arg, "-v") == 0) {
      printf(OPENSOLVER::VERSION);
      return EXIT_SUCCESS;
    } else if (strcmp(arg, "-nv") == 0) {
      printf("%s", NOMAD::VERSION.c_str());
      return EXIT_SUCCESS;
    }
  } else if (argc > 2) {
    //error
  }
  return OPENSOLVER::RunNomadAndLoadResult();
}
