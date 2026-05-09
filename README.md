# ShutdownAutomation
[简体中文](#zh-cn) | [English](#en-us)

---
<a id="zh-cn"></a>
## 简体中文版
这是一个用于 Windows 的关机程序。

### 使用方法
1. 关机：请附加 `--shutdown` 参数启动程序。执行程序后，系统会在 1 分钟后关机。
2. 取消关机：请直接启动程序。

> [!TIP]
> 建议搭配“Windows 任务计划程序”或类似自动化程序使用。

> [!NOTE]
> 为了防止误触，仅当附加 `--shutdown` 参数时，才会执行关机指令。
>
> 在以下情况下，程序默认取消关机：
> 
> | 参数数量 | 参数内容 |
> | --- | --- |
> | 0 | （无） |
> | 1 | 非 `--shutdown` 的任何内容 |
> | 2 个及以上 | 任意内容 |

---
<a id="en-us"></a>
## English Version
This is a shutdown tool for Windows.

### Usage
1. Shutdown: Please launch the program with an additional `--shutdown` parameter. The system will shutdown in 1 minute.
2. Cancel shutdown: Please launch the program directly.

> [!TIP]
> It is recommended to use this program with "Windows Task Scheduler" or similar automation program.

> [!NOTE]
> To avoid unexpected shutdown, the program will only proceed with the shutdown command if the `--shutdown` parameter is provided.
> 
> These circumstances will cancel shutdown by default:
> 
> | Number of Parameters | Parameter Content |
> | --- | --- |
> | 0 | (None) |
> | 1 | Anything other than `--shutdown` |
> | 2 or more | Anything |