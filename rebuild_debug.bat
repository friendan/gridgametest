@echo off
chcp 65001 >nul
cls
@echo 正在强制重新编译 Debug 版本...
cmake --build build --config Debug -- /t:Rebuild
@echo.
@echo ------------------------------
@echo 编译完成！窗口保持打开可输入命令
@echo ------------------------------
@echo.
@cmd /k

