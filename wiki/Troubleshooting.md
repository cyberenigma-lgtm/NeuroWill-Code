# Troubleshooting / Solución de Problemas

Typical errors and how to solve them. / Errores típicos y cómo solucionarlos.

---

## 1. "Python not found" / "Python no encontrado"
- **Cause**: The `TranslateWill` method calls `python` via system call.
- **Solution**: Ensure Python is in your system BIOS/PATH or update the absolute path to the interpreter in `bridge.cpp`.

## 2. "NUASM Path Error" / "Error de Ruta de NUASM"
- **Cause**: The bridge cannot locate `unasm.py`.
- **Solution**: Verify that `Neuro-Universal-ASM` is at the same level as `Neurowill-Code` or adjust the `nuasmPath` variable in `bridge.cpp`.

## 3. "Empty Bytecode Buffer" / "Buffer de Bytecode Vacío"
- **Cause**: Compilation failed due to syntax error in the source `.asm`.
- **Solution**: Check the console output for specific NUASM errors (e.g., "Unknown Opcode").

---

## FAQ / Preguntas Frecuentes

**Q: Does it support ARM?**
A: Currently, NWC/NUASM focuses on x86-64. ARM support is planned for future symbiotic kernels.

**Q: Can I use it in Unreal Engine?**
A: Yes. Integrate `nwcore` as a third-party module and use the bridge to handle dynamic logic.

**P: ¿Soporta ARM?**
R: Actualmente se enfoca en x86-64. El soporte para ARM está planeado para kernels simbióticos futuros.
