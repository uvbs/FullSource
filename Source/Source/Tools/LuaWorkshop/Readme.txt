1 编辑功能
	关联.lua文件后双击自动打开
	语法高亮显示
	自动语法补齐
		补齐规则定义在Rule.txt中
			----Keyword----为定义开始标记
			第一行 为匹配字符串，自动匹配激活提示窗口
			剩余的行 为补齐字符串
			| 为补齐后光标的位置
			[><]为分隔符
	自动标识符补齐
		自动提取local global function后的标识符加入语法补齐提示列表
		每次当前行发生变化时会重新分析全文
	自动函数参数提示
		需要在Rule.txt中手动加入
			----Param Hints----为参数提示开始标记
			第一行 为匹配字符串，按(后才显示提示窗口
			剩余的行 为提示参数表 最多3行
	树型列表根目录
		需要在Rule.txt中手动加入
			----Root Path----为定义开始标记
			可以加多个根目录
	修改Engine的文件名
		需要在Rule.txt中加入
			----Engine Name----为定义开始标记
			下一行为新Engine的文件名		
	无限制Undo/Redo
	查找	Ctrl+F	
		继续查找	F3
	列复制粘贴
		按住Alt键操作
	块文字缩进调整（对应于VC中的Tab和Shift+Tab）
		Ctrl+Shift+U	Ctrl+Shift+I
2 编译功能
	F7调用运行目录下的compile.exe
		出错输出显示在下方窗口
		自动定位到出错行和指定标识符
		出错行绿底红字显示
3 调试功能
	Attach / Detach， 绑定或者解除绑定指定进程
	F4 Quick Attach，快速绑定
		第一次默认为GameServer.exe
		Attach选择进程后，自动替换为该进程
	在左侧行号栏点击鼠标左键，可以设置断点，断点只和行号相关，和脚本文件无关
	Attach后
		每次执行新脚本文件
			会自动打开对应脚本文件，路径为"执行路径"\"脚本文件路径"
			脚本文件若不存在，会在下方窗口提示
			自动中断在首行
		Ctrl+B，进入中断状态，下次脚本运行时，会自动中断
		F5，进入运行状态，只有遇到断点才会中断
		F10，单步执行，总是进入子函数
		Ctrl+R，重新载入脚本，必须在中断状态下才有效，效果要到下次运行脚本时才出现
		在中断状态下，右侧窗口显示脚本相关内容
			Info中为当前脚本全路径和当前运行的函数名
			Global中为全局变量的名称与数值（目前只支持显示str和int类型）
			Local中为局部变量的名称与数值（同上）
			变量名后括号内为变量类型，不支持显示数值的变量类型显示在数值列
			变量发生改变后，在列表中自动提前
			修改变量值后，按回车可修改变量值，成功会有提示对话框（只支持str和int）
			Watch窗口中，可以设定要查看的变量名，支持拖放
			Call Stack窗口中，可以查看函数调用堆栈，支持双击定位
			
4 KLuaScript类的相关修改
	增加回调函数LuaProcessDebugInfo
	Lua的虚拟机每次执行一行代码前，都会先回调该函数
		注意：也就是说，当没有Lua代码执行时，该回调函数对程序没有控制权
	保存了脚本名称到m_szScriptName（该变量为以前定义，但未使用）
	在调试状态（Attach后）时，每次执行脚本前，设定脚本名指针，脚本函数名指针，KLuaScript指针
	注意：当处在调试状态时，游戏循环也停止了，时间过长会导致客户端断线	

5 版本更新
	V0.4.1.108  2004.12.28
        	增加帮助内容
        	双击打开Lua文件时，只会存在一个LuaWorkshop实例
		优化了调试回调函数的性能，没有Attach的时候回调函数直接返回
	V0.4.1.107	2004.12.22
		增加调试时，对于Include命令的支持，自动跳转到相关文件
		解决调试时，自动打开文件时，会重复打开的问题
		解决了Relay上脚本路径出错的问题
		增加自定义监视变量功能，支持拖放
		增加查看调用堆栈功能，支持双击跳转
	V0.3.1.98	2004.12.16
		Rule添加指定Engine.dll文件名的选项,默认为Engine.dll
	V0.3.1.97	2004.12.14
		修正不能修改局部变量的错误
		修正Table变量名重名的错误
	V0.3.1.96	2004.12.13
		修正默认循环变量重名问题
		修正无打开文档时绑定错误
	V0.3.1.95	2004.12.06
		已打开文件不会再次打开，而是自动定位到原已打开的文件
	V0.3.1.94	2004.12.04
		修正了自动补齐关键字的TAB对齐问题
	V0.3.1.93	2004.12.03
		修正编译信息输出缓冲区溢出的问题
	V0.3.1.92	2004.11.30
		修正目录树遍历显示的问题
	V0.3.1.91	2004.11.27
		Rule.txt中可以指定多个根目录
		Rule.txt中各个定义段，都加了开始标记，顺序可以打乱
		可以直接在树状列表中修改文件名，目录名不支持修改
	V0.3.1.87	2004.11.26
		添加左侧目录树状列表，Rule中第一行是根目录路径
		添加标签控制的多文本显示
		树状窗口和变量显示窗口可隐藏
		如果打开的文件是只读属性的，则不能改写
	V0.2.2.85	2004.11.18
		脚本运行中断时，自动将窗口提前
		添加捕捉执行期错误的功能（Relay上脚本报错输出到控制台，看不到）
		针对Relay上的脚本路径作了修正
		修正昨日重写变量名提取引入的参数表显示问题
	V0.2.1.79	2004.11.17
		修正了删除空行上括号的出错问题
		重写了变量名的提取
		去除global的关键字显示
		编译成功消除原出错行的高亮显示
		修正了选择文字块的问题
	V0.2.1.74	2004.11.16
		修正参数表和代码表同时显示的问题
		修正函数参数在括号嵌套时的显示问题
		修改了代码提示框的显示规则
		修正参数表说明文字和单个参数显示问题
		修正参数表显示问题
		修正回车跳动的问题
		修正XP下双击打开的问题
		修正取当前标识符为空报错的问题					
	
