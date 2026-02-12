# Usage Modes / Modos de Uso

NWC is designed for versatility. There are two primary ways to use the bridge:

---

## 1. Dynamic C++ Integration / Integración Dinámica en C++
This is the most powerful mode, allowing for real-time translation of "Will" commands during application runtime.

### Steps:
1. Include `nwcore/bridge.h` in your project.
2. Instantiate `NWC::NeuralBinaryBridge`.
3. Call `TranslateWill(command, langCode)`.
4. Use `GetBytecode()` to access the machine code.

```cpp
NWC::NeuralBinaryBridge bridge;
bridge.TranslateWill("pon rax, 5", "es");
std::vector<uint8_t> code = bridge.GetBytecode();
```

---

## 2. CLI Tooling / Herramientas de Línea de Comandos
For static compilation of `.asm` files using the NUASM backend.

### Command Example:
```bash
# Translate a Spanish assembly file to binary
python Neuro-Universal-ASM/src/unasm.py examples/test_es.asm -l es -o bin/test.bin
```

---

## Modos de Uso (Español)
NWC está diseñado para ser versátil. Hay dos formas principales de usar el puente:

1. **Integración Dinámica**: Traducción en tiempo real dentro de aplicaciones C++.
2. **Herramientas CLI**: Compilación estática de archivos `.asm` usando el motor de NUASM.
