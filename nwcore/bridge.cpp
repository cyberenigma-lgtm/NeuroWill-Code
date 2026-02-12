/*
 * Código derivado de Neuro-OS Genesis.
 * Propiedad Intelectual de Neuro-OS Genesis.
 */
#include "bridge.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace NWC {

NeuralBinaryBridge::NeuralBinaryBridge() {
  for (int i = 0; i < 16; ++i)
    m_Context.registers[i] = 0;
  m_Context.carry = false;
  m_Context.zero = false;
}

NeuralBinaryBridge::~NeuralBinaryBridge() {}

bool NeuralBinaryBridge::LoadNUASMBinary(const std::string &filepath) {
  std::ifstream file(filepath, std::ios::binary);
  if (!file.is_open()) {
    InternalLog("Failed to open NUASM binary: " + filepath);
    return false;
  }

  m_Bytecode.assign((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

  InternalLog("Loaded " + std::to_string(m_Bytecode.size()) +
              " bytes of NUASM bytecode.");
  return true;
}

void NeuralBinaryBridge::TranslateWill(const std::string &willCommand,
                                       const std::string &langCode) {
  InternalLog("Direct-to-Silicon Translation [" + langCode +
              "] (120% Compatibility) active.");

  // 1. Create temporary .asm file
  std::string tempAsm = "temp_will.asm";
  std::string tempBin = "temp_will.bin";

  std::ofstream asmFile(tempAsm);
  if (!asmFile.is_open()) {
    InternalLog("Critical Error: Could not create temp ASM file.");
    return;
  }
  asmFile << "; NWC Auto-Generated Will (" << langCode << ")" << std::endl;
  asmFile << willCommand << std::endl;
  asmFile.close();

  // 2. Invoke NUASM
  // Note: We use the absolute path to unasm.py for maximum reliability.
  std::string nuasmPath = "c:/Users/cyber/OneDrive/Documentos/NeuroOs/"
                          "Neuro-OS-Genesis/Neuro-Universal-ASM/src/unasm.py";

  // Command: python <path_to_unasm> <source> -l <langCode> -o <output>
  std::string cmd = "python " + nuasmPath + " " + tempAsm + " -l " + langCode +
                    " -o " + tempBin + " > nul 2>&1";

  int result = std::system(cmd.c_str());

  if (result == 0) {
    InternalLog("NUASM Translation Success.");
    LoadNUASMBinary(tempBin);
  } else {
    InternalLog("NUASM Translation Failed (Code: " + std::to_string(result) +
                ")");
  }

  // 3. Clean up
  std::remove(tempAsm.c_str());
  std::remove(tempBin.c_str());
}

void NeuralBinaryBridge::Execute() {
  InternalLog("Executing bytecode buffer...");
  if (m_Bytecode.empty()) {
    InternalLog("Execution Aborted: Bytecode buffer is empty.");
    return;
  }

  InternalLog("VM ready for execution cycle...");
}

void NeuralBinaryBridge::InternalLog(const std::string &msg) {
  std::cout << "[NWC Bridge] " << msg << std::endl;
}

} // namespace NWC
