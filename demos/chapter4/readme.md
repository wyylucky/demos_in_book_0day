##实验环境
	windows 2000； 
	Kali
##命令
- use exploit/windows/win (Tab)
- 	show options
- 	set **
- 	exploit 
##遇到问题
1. exploit脚本放在~/.msf4/modules下无法加载   
	解决方法（一）：将脚本放在Metasploit 的exploits下！  
	`目录：/usr/share/metasploit-framework/modules/exploits/windows/wins`
	
	`locate modules/exploits `找到存放exploits的目录，分类挺清晰的

	方法(二)： reload_all (本人在.msf4/modules下建了与/usr下modules相同的目录结构，方便后续use自动补全)
2. rb语法错误——根据提示修改脚本（可以找一个现有的脚本作为模板，然后修改对应部分的值）
3. msf 切换session ——得到meterpreter后切换到了background（后台运行），运用`session -i` 可以查看后台有啥session，然后用`session -i -$id` 切换回来
4. meterpreter用法，可以网上搜搜！
	1. 介绍：[http://www.2cto.com/Article/201310/248124.html](http://www.2cto.com/Article/201310/248124.html)
	2. 应用：[https://wizardforcel.gitbooks.io/daxueba-kali-linux-tutorial/content/32.html](https://wizardforcel.gitbooks.io/daxueba-kali-linux-tutorial/content/32.html)
	3. [https://www.91ri.org/8476.html](https://www.91ri.org/8476.html)
1. **注意：Release 版本 vs Debug版本**
	1. 在实验时，如果选用debug版本没有效果，运行Release版本下的.exe
	2. Build ---batch build
##参考链接
1. [如何加载metasploit的攻击module](http://blog.163.com/netman_do/blog/static/244782003201541702830919/)  
1. [使用metasploit进行栈溢出攻击-4](http://www.cnblogs.com/baizx/p/4114811.html)
2. [ (看雪论坛)0day第十章第六节实验疑问！](http://bbs.pediy.com/showthread.php?p=851151)