---
layout: pattern
title: Command
folder: command
permalink: /patterns/command/
categories: Behavioral
tags:
 - Gang of Four
---

## Also known as
Action, Transaction

## Intent
Encapsulate a request as an object, thereby letting you 
parameterize clients with different requests, queue or 
log requests, and support undoable operations.
> 将请求封装成对象，以便使用不同的请求、队列、
 或日志将客户端参数化，同时提供可撤销功能。

~~~命令模式可以将“动作的请求者”从“动作的执行者”对象中解耦；
被解耦的二者之间通过命令对象进行沟通。

