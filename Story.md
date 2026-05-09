[简体中文](#zh-cn) | [English](#en-us)

---
<a id="zh-cn"></a>
# 项目背后的小故事

## 1. 一切的开始
本人是一名学生，负责管理班级的交互平板。由于交互平板不能方便地熄屏，午休时我们会选择关机。

交互平板的关机似乎是向 OPS 发送 ACPI 关机信号来完成的。虽然这没什么问题，但总归不是最佳的关机方式。

为了让它可以定时关机，我们决定，写一个小程序，在 Windows 上定时执行，实现关机。

## 2. 小进展
我们知道：Windows 上执行关机，只需要执行 `shutdown -s` 的 CMD 命令就好。

我们又知道：批处理文件（.bat）可以让 Command Prompt 听你的话，非常方便。

于是乎—— `shutdown.bat` 横空出世：
```batch
shutdown -s -t 60
```
伟大的批处理文件生动地诠释了技术“解放人”的作用。

然而，我们也必须考虑到，在班级环境下，屏幕可能被误触，从而意外地执行关机脚本。

于是我们写了另一个批处理文件—— `CancelShutdown.bat`：
```batch
shutdown -a
```
这样，就算不小心执行了关机，还有补救措施。双击脚本可比打开 Windows Terminal 敲出 `shutdown -a` 快多了。

但不知为何，`CancelShutdown.bat` 和 `shutdown.bat` 放在同一个目录下的时候，`CancelShutdown.bat` 总是会激活 `shutdown.bat`，导致递归执行。所以只好先把它们分开。

## 3. 自动化？
刚才说了这么多，没有解决核心问题——**定时**关机。这需要自动化程序。

正巧，我们使用的课表软件 [ClassIsland](https://github.com/ClassIsland/ClassIsland.git) 带有“自动化”功能。

于是尝试。顺便学习了 Linux Crontab 的 cron 格式，以让 ClassIsland 可以定时执行程序。

终于解决了……

## 4. 结束了……吗？
好吧，自动化似乎并不是 ClassIsland 的主业，ClassIsland 的自动化实现也不太稳定，经常失效。

在某次 ClassIsland 自动化又没有执行的时候，我想起一种被埋没的 Windows 的力量。

没错，就是“Windows 任务计划程序”。

我试着创建了一个基本任务。虽然略显麻烦，但确实非常强大，甚至可以精确到秒。

然后继续使用上文提到的 `shutdown.bat` 和 `CancelShutdown.bat`。

这下，自动化的问题是彻底解决了。Windows 基本任务的优点是，只要 Windows 还在跑，它就能用。

## 5. 那为什么还要写这个项目？
因为看着两个文件不顺眼啊。

想想 [Wise Auto Shutdown](https://www.wisecleaner.com/wise-auto-shutdown.html)，人家一个程序可以做各种高级关机任务。

我需要的只是关机和取消关机而已啊。王侯将相，宁有种乎！

开干！

于是，我现在把这个项目呈现在您面前。

## 6. 结局
这个程序是为了班级电脑关机而生，自然也用在了班级电脑上。

仅此而已。

---
<a id="en-us"></a>
# Story Behind the Program

> [!IMPORTANT]
> Due to the author's limited English proficiency, this English version is based on the original Chinese text and has been translated by AI, then manually proofread by the author.
> While we strive for accuracy, there may still be omissions or inappropriate expressions. We appreciate your understanding.

## 1. How It All Began
I'm a student, responsible for managing the interactive display in my class. Since the display doesn't have a convenient way to turn off the screen, we usually shut it down during lunch break.

The shutdown process seems to work by sending an ACPI shutdown signal to the OPS. While that works, it's not exactly the best way to power off.

To enable scheduled shutdowns, we decided to write a small program that runs on Windows at specified times to shut down the system.

## 2. Small Progress
We know that on Windows, you can shut down by simply running the command `shutdown -s` in CMD.

We also know that batch files (`.bat`) let the Command Prompt do your bidding -- very convenient.

So -- `shutdown.bat` was born:
```batch
shutdown -s -t 60
```
This glorious batch file perfectly demonstrates how technology can *liberate people*.

However, we also had to consider that in a classroom environment, the screen might be accidentally touched, triggering the shutdown script by mistake.

So we wrote another batch file -- `CancelShutdown.bat`:
```batch
shutdown -a
```
Now, even if shutdown was triggered accidentally, there was a remedy. Obviously, double-clicking the script is faster than opening Windows Terminal and typing out `shutdown -a`.

But for some reason, when `CancelShutdown.bat` and `shutdown.bat` were placed in the same directory, `CancelShutdown.bat` would always activate `shutdown.bat`, causing a recursive execution. So we had to keep them separate.

## 3. Automation?
After all that, we still hadn't solved the core problem — **scheduled** shutdown. We needed automation.

Coincidentally, the class schedule software we use, [ClassIsland](https://github.com/ClassIsland/ClassIsland.git), comes with an "automation" feature.

So we gave it a try. I also learned the cron format used by Linux Crontab so that ClassIsland could execute programs at scheduled times.

Finally solved it...

## 4. Is It Over...?
Well, it seemed that ClassIsland is not the perfect solution for automation, as it is somewhat unstable -- it often fails.

One day, when ClassIsland's automation didn't trigger again, I remembered a forgotten power of Windows.

Yes, that's it -- "Windows Task Scheduler".

I tried creating a basic task. It was a bit more cumbersome, but very powerful -- accurate to the second, that's amazing.

The `shutdown.bat` and `CancelShutdown.bat` mentioned earlier are still used at that time.

With that, the automation problem was completely solved. The advantage of Windows' basic tasks is that as long as Windows is running, it works.

## 5. So Why Write This Project?
Because the solution using the two batch files is not simple.

Think about [Wise Auto Shutdown](https://www.wisecleaner.com/wise-auto-shutdown.html) — a single program can handle all sorts of advanced shutdown tasks.

All I needed was shutdown and cancel shutdown. If others can do that, why can't I?

Time to get my hands dirty!

And so, here I am presenting this project to you.

## 6. The End
This program was born for the classroom computer — and naturally, it runs on that very same classroom computer.

That's all.