// Main.win32.cpp
// Functions that are exported in the Windows DLL

#include "NomadInterface.h"

#include <atlbase.h>

extern "C" BSTR _stdcall NomadVersion() {
  return CComBSTR(NOMAD::VERSION.c_str());
}

extern "C" BSTR _stdcall NomadDLLVersion() {
  return CComBSTR(OPENSOLVER::VERSION);
}

// This function must be called directly within VBA using
// retCode = NomadMain(SolveRelaxation).
// If Application.Run is used, the Excel12f calls will fail in 64-bit Office.
// TODO: try to remove this unused bool, seems to crash Excel if we take it out
extern "C" int _stdcall NomadMain(bool /*SolveRelaxation*/) {
  return OPENSOLVER::RunNomad();
}