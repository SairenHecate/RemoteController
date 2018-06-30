#include <string>

// 生成一个控制信令(cmd:arg - 冒号中间没有空格, arg为空表示无参数)
inline std::string MAKE_CMD(const char *cmd, const char *arg)
{
	char buffer[64];
	sprintf_s(buffer, "%s%s%s", cmd, arg ? ":" : "", arg ? arg : "");
	return buffer;
}

// 解析一个控制信令(返回参数信息)
inline std::string PARSE_CMD(const char *msg, char *out_cmd)
{
	const char *p = msg;
	while (*p && ':' != *p) ++p;
	memcpy(out_cmd, msg, p - msg);
	return (':' == *p) ? p + 1 : "";
}

// 默认心跳周期（秒）
#define ALIVE_TIME 120

#define RESTART			"restart"		// 重启程序

#define REFRESH			"refresh"		// 刷新现实

#define STOP			"stop"			// 停止程序

#define START			"start"			// 启动程序

#define SHUTDOWN		"shutdown"		// 关机

#define REBOOT			"reboot"		// 重启电脑

#define REGISTER		"register"		// 注册=>register:success

#define KEEPALIVE		"keepAlive"		// 心跳=>keeAlive:AliveTime

#define UPDATE			"update"		// 升级程序=>update:a

#define SETTIME			"settime"		// 校时=>settime:年,月,日,时,分,秒
