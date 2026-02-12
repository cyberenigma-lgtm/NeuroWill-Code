# FAQ / Preguntas Frecuentes

## General Questions / Preguntas Generales

### 1. What is the "120% Compatibility"? / ¿Qué es la "Compatibilidad del 120%"?
It refers to NWC's ability to not only consume NUASM generated binaries but also dynamically invoke the assembler to generate code from human semantic intents on the fly. 

### 2. Is it safe to inject binary code? / ¿Es seguro inyectar código binario?
NWC is a low-level tool. It should be used within the **Neuro-OS Sandboxed Environment** to prevent unauthorized system calls.

---

### 3. Will it work with my language? / ¿Funcionará con mi idioma?
NWC supports all languages in the `nuasm` project (51 as of today). If your language is in `Neuro-Universal-ASM/languages/`, it works!
