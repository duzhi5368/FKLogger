//--------------------------------------------------------------------
#include "../FKLogger/FKLogger.h"
#include <stdio.h>
#include <string>
using std::string;
//--------------------------------------------------------------------
#if defined (DEBUG) || defined (_DEBUG)
#pragma comment( lib, "FKLoggerD.lib")
#pragma comment( lib, "Ws2_32.lib")
#else
#pragma comment( lib, "FKLogger.lib")
#pragma comment( lib, "Ws2_32.lib")
#endif
//--------------------------------------------------------------------
int main()
{
    // 默认Console输出
    LogError( "测试上課那肯定會瑾謹還都");
    LogDebug( "测试LogDebug测试LogDebug测试LogDebug测试LogDebug测试LogDebug" );
    LogTrace( "12dsdsads" );
    string szTest = "dsadasd你好";
    LogInfo( "%s", szTest.c_str() );

    // 开始文件输出
    FKLogger::SFileLoggerInitParams tagParams;
    tagParams.m_pFileName = "MyLog.txt";
    if( InitFKLogger( FKLogger::ELOM_File, (void*)&tagParams ) < 0 )
    {
        return -1;
    }
    LogError( "的撒嬌快回答");
    LogDebug( "還都好撒謊837的撒旦宝贝计划*（……&*&……  将比南京吧\n" );
    LogTrace( "12dsdsads" );
    szTest = "款到发货vjsd";
    LogInfo( "%s", szTest.c_str() );

    DeInitFKLogger();

    // 远程Sock传输
    FKLogger::SSocketLoggerInitParams tagSockParams;
    tagSockParams.m_pServer = "127.0.0.1";
    tagSockParams.m_nPort = 9999;
    if( InitFKLogger( FKLogger::ELOM_Socket, (void*)&tagSockParams ) < 0 )
    {
        return -2;
    }
    LogError( "的撒嬌快回答");
    LogDebug( "還都好撒謊837的撒旦宝贝计划*（……&*&……  将比南京吧\n" );
    LogTrace( "12dsdsads" );
    szTest = "款到发货vjsd";
    LogInfo( "%s", szTest.c_str() );

    DeInitFKLogger();

    getchar();
    return 0;
}
//--------------------------------------------------------------------