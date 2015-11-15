/********************************************************************
*  Copyright (C), 2008-2010, Potevio Institute of Technology Co.,Ltd
*  File Name:       PT_AtCmd.c
*  Author:          zhenglei
*  Version:         v2.0 for R3.5.2
*  Created Date:    2012-11-9
*  Description:     for at cmd 
*  Change History:        
*  <author>  <time>   <version >   <desc>
*  zhenglei  12/7/1     v1.0       build this moudle
*  zhenglei  12/11/9    v2.0       upgrade this moudle
*********************************************************************/

#include "PT_AtCmd.h"




/******************************	stub - begin *********************************/
#if 0 //mark 待删桩
void main()
{
#if 0 //1、	APP设置组信息
	char pchAtCmd[] = "PTGID=2,ABCD,1381230123456789,1381239876543210,15,10,EFGH,1501230123456789,1501239876543210,8,01";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //2、	APP设置/取消紧急呼叫
	char pchAtCmd[] = "PTEM=1";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //3、	SIP信息查询
	char* pchAtCmd = "PTSIP?";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //4、	SIP信息上报
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	SIP_INFO *pstSendBuf = NULL;
	pstSendBuf = (SIP_INFO *)chSendBuf; 

	pstSendBuf->u16ExpiresValue = 0x1234;
	pstSendBuf->u16ServerPort = 0x4321;

	memcpy(pstSendBuf->u8Password, "234", 3);
	pstSendBuf->u8Passwordlen = 3;

	pstSendBuf->u8ServerIP[0] = 192;
	pstSendBuf->u8ServerIP[1] = 168;
	pstSendBuf->u8ServerIP[2] = 10;
	pstSendBuf->u8ServerIP[3] = 3;

	memcpy(pstSendBuf->u8UserName, "ab", 2);
	pstSendBuf->u8UserNamelen = 2;

	u16Len = Mca_AtPTSIPtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


/******************************** delete for R3.5.2 begin ************************************/
#if 0 //9、	遥晕/遥毙/复活 - 查询
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8RemoteCtrlStatus = 1;	
    u16Len = Mca_AtPTCTRLtoAPP(u8RemoteCtrlStatus, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


#if 0 //9、	遥晕/遥毙/复活 - 设置
	char* pchAtCmd = {"PTCTRL=2"};
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//23、	故障弱化状态查询
#if 0
	char* pchAtCmd = {"PTFW?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//25、	故障弱化触发UE本地业务释放
#if 0
	char* pchAtCmd = {"PTFW"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif
/******************************** delete for R3.5.2 end ************************************/


#if 0 //6、	集群承载配置
	char* pchAtCmd = {"PTTB=1234,15,0,1"}; //有ETTI
	//char* pchAtCmd = {"PTTB=4,1,0"}; //无ETTI
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //7、	请求通话组列表
	char* pchAtCmd = {"PTGL"};
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


#if 0 //8、	组呼来电
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 chSendBuf[180] = {0};
	GROUP_PAGING_LIST *pstSendBuf = (GROUP_PAGING_LIST *)chSendBuf; 

	//uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	//uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2};

	pstSendBuf->u8GroupNum = 2;
	//memcpy(pstSendBuf->stGroupPagInfo[0].u8asGroupID, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->stGroupPagInfo[0].u8asGroupID, Num1, 11);
	pstSendBuf->stGroupPagInfo[0].u8GroupPriority = 15;
	//memcpy(pstSendBuf->stGroupPagInfo[1].u8asGroupID, Num2, MAX_GROUP_LEN);
	memcpy(pstSendBuf->stGroupPagInfo[1].u8asGroupID, Num2, 11);
	pstSendBuf->stGroupPagInfo[1].u8GroupPriority = 4;

	u16Len = Mca_AtPTGPtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//9、	接受组呼
#if 0
	char* pchAtCmd = {"PTGPR=138123410012345"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//10、	拒绝组呼
#if 0
	char* pchAtCmd = {"PTGPREJ"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//mark测试用例过老 11、	组呼建立成功
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 chSendBuf[180] = {0};
	GROUP_CALL_CONTEXT *pstSendBuf = (GROUP_CALL_CONTEXT *)chSendBuf; 

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};
	uint8 ET1[8] = {1,2,3,4,5,6,7};
	uint8 ET2[8] = {2,3,4,5,6,7,8};

	pstSendBuf->u32ServiceOption = 0x12345678;;
	memcpy(pstSendBuf->u8CallingNum, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8CalledNum, Num2, MAX_GROUP_LEN);
	pstSendBuf->u8IP[0] = 192;
	pstSendBuf->u8IP[1] = 168;
	pstSendBuf->u8IP[2] = 10;
	pstSendBuf->u8IP[3] = 3;
	pstSendBuf->u16AudioPort = 0x1234;
	pstSendBuf->u16VideoPort = 0x5678;
	pstSendBuf->u16DataPort = 0x9abc;
	pstSendBuf->u8AudioTransport = 1;
	pstSendBuf->u8VideoTransport = 2;
	pstSendBuf->u8AudioPT = 3;
	pstSendBuf->u8VideoPT = 4;
	memcpy(pstSendBuf->u8AudioET, ET1, 8);
	memcpy(pstSendBuf->u8VideoET, ET2, 8);
	pstSendBuf->u32AudioRate = 0x12345678;
	pstSendBuf->u32VideoRate = 0x01234567;
	pstSendBuf->u8LateEntryInd = 0;
	pstSendBuf->u8vok = 5;
	pstSendBuf->u16gsk = 0x0123;

	u16Len = Mca_AtPTGStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//12、	组短信指示
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};
	uint8 Ctxt[MAX_SMS_LEN] = {1,2,3,4,5,6,7,8,9,7};

	uint8 chSendBuf[180] = {0};
	SMS *pstSendBuf = (SMS *)chSendBuf; 

	memcpy(pstSendBuf->u8CallingNum, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8CalledNum, Num2, MAX_GROUP_LEN);
	pstSendBuf->u8MsgType = 2;
	pstSendBuf->u16MsgLen = 10;
	memcpy(pstSendBuf->u8MsgCtxt, Ctxt, pstSendBuf->u16MsgLen);

	u16Len = Mca_AtPTSMStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//13、	话语权指示
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 Num1[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,1,2,3,4,5};
	uint8 Num2[MAX_GROUP_LEN] = {1,3,8,1,2,3,4,1,0,0,2,3,4,5,6};

	uint8 chSendBuf[180] = {0};
	FLOOR_GRANT *pstSendBuf = (FLOOR_GRANT *)chSendBuf; 

	pstSendBuf->u8FloorGrantInd = 1;
	memcpy(pstSendBuf->u8GID, Num1, MAX_GROUP_LEN);
	memcpy(pstSendBuf->u8PTTNum, Num2, MAX_GROUP_LEN);	

	u16Len = Mca_AtPTFGtoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//14、	组呼下行释放指令
#if 0
	char* pchAtCmd = {"PTGR=138123410012345"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//15、	组呼下行释放原因上报
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8RelCause = 2;	
    u16Len = Mca_AtPTGRtoAPP(u8RelCause, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//16、	集群模块状态查询
#if 0
	char* pchAtCmd = {"PTS?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	PT_STATUS *pstSendBuf = NULL;
	pstSendBuf = (PT_STATUS *)chSendBuf; 

	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);

	pstSendBuf->u8UEStatus = 2;
	pstSendBuf->u8eNBStatus = 0;
    u16Len = Mca_AtPTStoAPP(chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//17、	故障弱化状态报告
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;

	uint8 u8Status = 1;	
    u16Len = Mca_AtPTFWtoAPP(u8Status, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//18、	开启关闭集群功能
#if 0
	char* pchAtCmd = {"PTRUN=1"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//19	普天集群协议栈版本号信息查询    
#if 0
	char* pchAtCmd = {"PTVER?"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//20	组业务密钥更新请求
#if 0
	char chAT[180] = {0};
	char chOutput[180] = {0};
	uint16 u16Len = 0;
	uint8 chSendBuf[180] = {0};
	uint8 Num1[MAX_GROUP_LEN] = {"13812341001"};
	uint8 Num2[MAX_GROUP_LEN] = {"13812341002"};
	PT_GEU *pstSendBuf = NULL;
	pstSendBuf = (PT_GEU *)chSendBuf; 

	pstSendBuf->u8GNum = 2;
	memcpy(pstSendBuf->u8GID[0].u8perGID, Num1, strlen(Num1));
	memcpy(pstSendBuf->u8GID[1].u8perGID, Num2, strlen(Num2));

	u16Len = Mca_AtPTGEUtoAPP((PT_GEU *)chSendBuf, chAT);
	memcpy(chOutput, chAT, u16Len);
	printf("chOutput:%s",chOutput);
#endif


//21	密钥更新/销毁
#if 0
	char* pchAtCmd = {"PTGEU=2,1234,5678,13812341001,abcdefg,13812341002,zxcvbnmwsdhdg"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//22	集群模块复位
#if 0
	char* pchAtCmd = {"PTRST=4"}; 
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif


//TEST
#if 0 
	//char pchAtCmd[] = "AT+PTTEST=0,CP,curgcallnum"; //ERROR1:没有"AT+"前缀！
	//char pchAtCmd[] = "PTTEST=0,CP,curgcallnum";
	char pchAtCmd[] = "PTTEST=1,CP,timer,1000,2000,3000,4000";
	//char pchAtCmd[] = "PTTEST=1,CP,init";
	uint16 u16AtLen = (uint16)strlen(pchAtCmd);
	Mca_AtCmdDispatch(pchAtCmd,u16AtLen);
#endif

	getchar();
	return;
}
#endif
/******************************	stub - end *********************************/


static AT_CMD_PROC_FUN_ITEM stAtCmdTable[] = {  {"PTGID", Mca_AtPTGIDProc},
											    {"PTEM", Mca_AtPTEMProc},
											    {"PTSIP", Mca_AtPTSIPProc},
												/* zhenglei deleted for R3.5.2 2012-11-12 begin */
												#if 0
											    {"PTCTRL", Mca_AtPTCTRLProc},
												#endif
												/* zhenglei deleted for R3.5.2 2012-11-12 end */											    {"PTTB", Mca_AtPTTBProc},
											    {"PTGL", Mca_AtPTGLProc},
											    {"PTGPR", Mca_AtPTGPRProc},
											    {"PTGPREJ", Mca_AtPTGPREJProc},
											    {"PTGR", Mca_AtPTGRProc},
												/* zhenglei deleted for R3.5.2 2012-11-12 begin */
												#if 0
											    {"PTFW", Mca_AtPTFWProc},
												#endif
												/* zhenglei deleted for R3.5.2 2012-11-12 end */
											    {"PTRUN", Mca_AtPTRUNProc},
											    {"PTVER", Mca_AtPTVERProc},
											    /* zhenglei added for test module 20120917 begin */
											    {"PTTEST", Mca_AtPTTESTProc},
											    /* zhenglei added for test module 20120917 end */
												/* zhenglei added for R3.5.2 2012-11-12 begin */
												{"PTS", Mca_AtPTSProc},
												{"PTGEU", Mca_AtPTGEUProc},
												{"PTRST", Mca_AtPTRSTProc},
												/* zhenglei added for R3.5.2 2012-11-12 begin */
												{"PTK", Mca_AtPTKProc},
											    {NULL, NULL}
                                              };

int32 Mca_AtPTKProc( uint8 *pchCmd, uint16 u16Len )
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	char* end = NULL;
	uint32 u32Len = 0;
	char chValue[128] = {0};
	char chValue1[4] = {0};
	uint8 u8GroupNum = 0;
	AT_PROC_MESSAGE stATMsg;
	uint8 i,j=0;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTKProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* 组AT消息通知CP上报普天集群协议栈版本号信息，并向APP返回"OK" */
		stATMsg.emTypeOfATMsg = AT_PTKG_TO_APP;	
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Read Msg Send to CP Successful");
    }
	else  if(MCA_WRITE == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTKS_TO_APP;	

		pchTemp = pchCmd + 1;
		/* IMSI */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
		pchTemp += u32Len;
		u32Len -= 1;
		PT_MEMCPY( stATMsg.unATCmd.stPTK.u8imsi, chValue, u32Len );

		/* MK0 */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
		pchTemp += u32Len;
		for( i=0; i<32; i++ )
		{
			chValue1[0] = chValue[i*2];
			chValue1[1] = chValue[i*2+1];
			stATMsg.unATCmd.stPTK.u8mk0[i] = (uint8)strtoul( chValue1, &end, 16 );
		}
		/* COUNT */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue );
		stATMsg.unATCmd.stPTK.u16count = (uint16)strtoul( chValue, &end, 16 );
		pchTemp += u32Len;

		/* CCOUNT */
		PT_MEMSET(chValue, 0, sizeof(chValue));
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue );
		stATMsg.unATCmd.stPTK.u32ccount = (uint32)strtoul( chValue, &end, 16 );
		pchTemp += u32Len;
		
		/* group */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &u8GroupNum);
		stATMsg.unATCmd.stPTK.u16gcount = u8GroupNum;
		pchTemp += u32Len;
		for( i=0; i<u8GroupNum; i++ )
		{
			/* group id */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;
			PT_MEMCPY( stATMsg.unATCmd.stPTK.u8gid[i], chValue, u32Len);

			/* vok */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			stATMsg.unATCmd.stPTK.u8vok[i] = (uint8)strtoul( chValue, &end, 16 );
			pchTemp += u32Len;

			/* gic */
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			stATMsg.unATCmd.stPTK.u32gic[i] = (uint32)strtoul( chValue, &end, 16 );
			pchTemp += u32Len;
			
			/* gwk */
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			for( j=0; j<32; j++ )
			{
				chValue1[0] = chValue[j*2];
				chValue1[1] = chValue[j*2+1];
				stATMsg.unATCmd.stPTK.u8gwk[i][j] = (uint8)strtoul( chValue1,&end, 16 );
			}
			pchTemp += u32Len;
		}
		
		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]:Msg Send to CP Successful");
    }
 	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTKProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
    return Status;
}

/* zhenglei added for R3.5.2 2012-11-12 begin */
/***************************************************************
*  Function:       Mca_AtPTRSTProc
*  Description:    处理AT：APP通过此AT复位集群模块
*				   AT+PTRST=<status>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTRSTProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTRST_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTRSTProc]Enter\n");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
	if(MCA_WRITE == u8CmdType)
	{
		/* 获取控制指令 */
		Mca_GetParaValue(CONVER_TYPE_UINT8, ++pchCmd, &stATMsg.unATCmd.u8PTRst);

		/* 发消息通知CP复位集群模块，可用于故障弱化过程，遥晕遥毙过程 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRSTProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}


/***************************************************************
*  Function:       Mca_AtPTGEUProc
*  Description:    处理AT：APP通过此AT更新或销毁指定组的密钥
*				   AT+PTGEU=<count>,<rand>,<ecount>
*				   [,<gnumber1>,<EGK1> [,<gnumber2>,<EGK2>[…]]]
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGEUProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	uint32 u32Len = 0;
	char chValue[MAX_EGK_CTXT] = {0};
	uint8 u8GroupNum = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGEU_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGEUProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 1-获取需要密钥更新的组个数 */
		pchTemp = pchCmd + 1;
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stPTGEU.u8count);
		
		/* 检查组号个数合法性 */
		if(stATMsg.unATCmd.stPTGEU.u8count > 8)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Check GroupNum more than 8 ERROR!");
			ATSendERROR();
			return AT_CHECK_PARA_ERROR;
		}

		pchTemp += u32Len;

		/* 2-获取EGK中的RAND */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT16, pchTemp, &stATMsg.unATCmd.stPTGEU.u16rand);
		pchTemp += u32Len;

		/* 3-获取EGK中的COUNT */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT16, pchTemp, &stATMsg.unATCmd.stPTGEU.u16ecount);
		pchTemp += u32Len;

		/* 获取每组组信息 */
		for(u8GroupNum = 0; u8GroupNum < stATMsg.unATCmd.stPTGEU.u8count; u8GroupNum++)
		{
			/* 4-获取每组组号 */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;
			PT_MEMCPY(stATMsg.unATCmd.stPTGEU.u8GID[u8GroupNum].u8perGID, chValue, u32Len);
		
			/* 5-获取每组EGK中的密文内容 */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetEGKValue( pchTemp, u16Len-((uint8*)pchTemp-pchCmd), chValue );
			pchTemp += u32Len;
			PT_MEMCPY(stATMsg.unATCmd.stPTGEU.u8GID[u8GroupNum].u8EGKX, chValue, MAX_EGK_CTXT);		
		}  
		
		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]:Msg Send to CP Successful");
    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGEUProc]Unknown AT ERROR");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTSProc
*  Description:    用于APP查询通信模块是否处于故障弱化状态
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTSProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTS_TO_APP;

		/* 组AT消息通知CP上报故障弱化状态报告，并向APP返回"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]:Read Msg Send to CP Successful");
    }
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTStoAPP
*  Description:    用于通信模块通知APP故障弱化状态报告
*				   +PTS:<status>,<enbstatus>
*  Input:          pstSendBuf：UE和eNB的故障弱化状态
*				   （1）集群模块运行状态,0：正常运行,1：被遥晕,2：被遥毙 
*				   （2）eNB状态,0：正常运行,1：故障弱化
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTStoAPP(PT_STATUS *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTStoAPP]Enter");

	sprintf(pchTemp, "+PTS:");
	pchTemp += 5;

	/* 从集群上下文中获取UE或eNB是否进入故障弱化状态标志位，并上报给APP */
	*pchTemp++ = pstSendBuf->u8UEStatus + '0';
	*pchTemp++ = ',';
	*pchTemp++ = pstSendBuf->u8eNBStatus + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT) + 1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTGEUtoAPP
*  Description:    当协议栈发现组密钥的版本号变化时,请求APP发起密钥更新过程
*				   +PTGEU：<count>[,<gnumber1>[,<gnumber2>,[…]]]
*  Input:          pstSendBuf：PT_GEU结构体指针
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTGEUtoAPP(PT_GEU *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	uint8 u8GroupNum = 0; 

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGEUtoAPP]Enter");

	/* 协议栈请求APP发起密钥更新过程 */
	sprintf(pchTemp, "+PTGEU:");
	pchTemp += 7;

	/* 1-上报需要密钥更新的组个数 */
	*pchTemp++ = pstSendBuf->u8count + '0';
	*pchTemp++ = ',';

	/* 遍历所属组信息 */
	for(u8GroupNum = 0; u8GroupNum < pstSendBuf->u8count; u8GroupNum++)
	{	
		/* 2-上报每组组号 */
		PT_MEMCPY( pchTemp, pstSendBuf->u8GID[u8GroupNum].u8perGID, strlen(pstSendBuf->u8GID[u8GroupNum].u8perGID) );
		pchTemp += strlen(pstSendBuf->u8GID[u8GroupNum].u8perGID);
		*pchTemp++ =',';
	}

	pchTemp--;
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}
/* zhenglei added for R3.5.2 2012-11-12 end */



/* zhenglei added for test module 20120917 begin */
/***************************************************************
*  Function:       Mca_AtPTTESTProc
*  Description:    处理测试用AT
*  (1)查询测试AT的格式为：
*		AT+PTTEST=0,<modle>,<name>
*  (2)设置/执行测试AT的命令格式为：
*		AT+PTTEST=1,<modle>,<name>[,value1][,value2]...[,valuen]
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTTESTProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	uint32 u32Len = 0;
	uint8 u8Loop = 0;
	uint8 u8Part = 0;
	uint8 u8Offset = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTTEST_TO_TEST;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}
	
	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 获取读、写标志位 */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stPTTEST.u8Type);
		pchTemp += 2;

		/* 获取模块名称 */
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, stATMsg.unATCmd.stPTTEST.u8Module);
		pchTemp += u32Len;

		/* 获取参数名称 */
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, stATMsg.unATCmd.stPTTEST.u8Name);
		pchTemp += u32Len - 1;		

		/* 根据读写标志位处理后续参数 */
		if(PTTEST_READ == stATMsg.unATCmd.stPTTEST.u8Type)
		{
			/* 组AT消息通知CP上报TEST信息，并向APP返回"OK" */
			Status = TrunkMsgSend(TEST_ENTITY, AT_TEST_COMMAND, (const void*)&(stATMsg.unATCmd.stPTTEST), sizeof(PTTEST));
			if(AT_OK != Status)
			{
				TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]:Read Msg Send to CP Failure!!!");
			}
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]:Read Msg Send to CP Successful");

		}
		else if(PTTEST_WRITE == stATMsg.unATCmd.stPTTEST.u8Type)
		{
			/* 获取后续参数 */
			u8Offset = pchTemp - (int8*)pchCmd;
			for(u8Loop = 0; u8Loop < u16Len - u8Offset; u8Loop++)
			{
				if(',' == pchCmd[u8Offset + u8Loop])
				{
					u8Part++;
				}
			}

			if((0 < u8Part) && (8 >= u8Part))
			{
				pchTemp++;
				for(u8Loop = 0; u8Loop < u8Part; u8Loop++)
				{
					u32Len = Mca_GetParaValue(CONVER_TYPE_UINT32, pchTemp, &stATMsg.unATCmd.stPTTEST.u32Para[u8Loop]);
					pchTemp += u32Len;	
					stATMsg.unATCmd.stPTTEST.u8ParaLen++;
				}
			}
			else if(9 < u8Part)
			{
				/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
				TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Too many PTTEST Paras ERROR!");
				return AT_UNKNOWN_ERROR;		
			}

			/* 组AT消息通知TEST写入TEST信息，并向APP返回"OK" */
			Status = TrunkMsgSend(TEST_ENTITY, AT_TEST_COMMAND, (const void*)&(stATMsg.unATCmd.stPTTEST), sizeof(PTTEST));
			if(AT_OK != Status)
			{
				TrkPrint(TRKLOG_PRIORITY_ERROR,"[Mca_AtPTTESTProc]:Read Msg Send to TEST Failure!!!");
			}
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]:Read Msg Send to TEST Successful");

		}
		else
		{
			/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
			TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Unknown PTTEST type ERROR!");
			ATSendERROR();
			return AT_UNKNOWN_ERROR;
		}
	}
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTESTProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}




/* zhenglei added for test module 20120917 end */


/***************************************************************
*  Function:       Mca_AtPTVERProc
*  Description:    APP通过此AT查询普天集群协议栈版本号信息：AT+PTVER?
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTVERProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTVER_TO_APP;	

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTVERProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* 组AT消息通知CP上报普天集群协议栈版本号信息，并向APP返回"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]:Read Msg Send to CP Successful");
    }
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTVERProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTRUNProc
*  Description:    处理AT：用于APP控制协议栈集群功能的开启和关闭
*				   AT+PTRUN=<run>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTRUNProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTRUN_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTRUNProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}
	
	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 获取是否开启\停止协议栈运行集群功能的标志位 */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8TKRunFlag);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]The TK Run Enable flag is %d",stATMsg.unATCmd.u8TKRunFlag);

		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]:Msg Send to CP Successful");
	}
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTRUNProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}




/***************************************************************
*  Function:       Mca_AtPTFWtoAPP
*  Description:    用于通信模块通知APP故障弱化状态报告
*				   +PTFW:<status>
*  Input:          u8Status：故障弱化状态
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTFWtoAPP(uint8 u8Status, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFWtoAPP]Enter");

	sprintf(pchTemp, "+PTFW:");
	pchTemp += 6;

	/* 从集群上下文中获取是否进入故障弱化状态标志位，并上报给APP */
	*pchTemp++ = u8Status + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}

/* zhenglei deleted for R3.5.2 2012-11-12 begin */
#if 0
/***************************************************************
*  Function:       Mca_AtPTFWProc
*  Description:    用于APP查询通信模块是否处于故障弱化状态：AT+PTFW?
*				   或APP在接收到故障弱化状态报告后触发通信模块本地业务释放：AT+PTFW
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTFWProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFWProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTFW_TO_APP;

		/* 组AT消息通知CP上报故障弱化状态报告，并向APP返回"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Read Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Read Msg Send to CP Successful");
    }
	else if((AT_ERROR == u8CmdType)&&(0 == u16Len))
	{
		stATMsg.emTypeOfATMsg = AT_PTFW_REL_TO_APP;

		/* 组AT消息通知CP本地业务释放，并向APP返回"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Rel Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]:Rel Msg Send to CP Successful");		
	}
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTFWProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}
#endif
/* zhenglei deleted for R3.5.2 2012-11-12 end */


/***************************************************************
*  Function:       Mca_AtPTGRtoAPP
*  Description:    用于通信模块通知APP组呼下行释放并上报释放原因
*				   +PTGR: < Release Cause >
*  Input:          u8RelCause：释放原因值
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTGRtoAPP(uint8 u8RelCause, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGR_RELCAUSE_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGRtoAPP]Enter");

	sprintf(pchTemp, "+PTGR:");
	pchTemp += 6;

	/* 获取<Release Cause>并组AT消息发给CP */
	*pchTemp++ = u8RelCause + '0';
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}


/***************************************************************
*  Function:       Mca_AtPTGRProc
*  Description:    用于APP通知通信模块组呼下行释放
*   			   AT+PTGR=<GID>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGRProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char chTemp[MAX_GROUP_LEN] = {0};
	uint32 u32Len = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGR_RELGID_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGRProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, ++pchCmd, chTemp);

		/* 检查组号长度及字符，并将组号从字符串转换为数字 */
		//if(AT_OK != Mca_CheckGroupID(chTemp, u32Len))
		//{
		//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Check GID length or alapha ERROR!\n");
		//	ATSendERROR();
		//	return AT_UNKNOWN_ERROR;
		//}
		PT_MEMCPY(stATMsg.unATCmd.u8RelGID, chTemp, u32Len);


		/* 组AT消息通知CP释放此组号所对应的组呼上下文，并向APP返回"OK" */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]:Msg Send to CP Successful");
    }
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGRProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}




/***************************************************************
*  Function:       Mca_AtPTFGtoAPP
*  Description:    通信模块主动上报给APP当前话语权状态
*  +PTFG:< Floor Grant Ind >,<GID>[,< Terminal Number >]
*  Input:          pstSendBuf：FLOOR_GRANT结构指针
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTFGtoAPP(FLOOR_GRANT *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTFGtoAPP]Enter");

	sprintf(pchTemp, "+PTFG:");
	pchTemp += 6;

	/* 从集群上下文中获取以下信息并上报给APP */
	/* <Floor Grant Ind> */
	*pchTemp++ = pstSendBuf->u8FloorGrantInd + '0';
	*pchTemp++ = ',';

	/* <GID> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8GID, 11);
	pchTemp+=strlen(pstSendBuf->u8GID);

	/* [,<Terminal Number>] */
	if(pstSendBuf->u8PTTNum[0])
	{
		*pchTemp++ = ',';
		MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8PTTNum, pstSendBuf->u8PTTNumlen);
	}

	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTSMStoAPP
*  Description:    通信模块在收到组短信后，向APP指示组短消息
+PTSMS:< Calling Terminal Number >,< Called Terminal Number >,
< MsgType >,< MsgLength >,< MsgContext >
*  Input:          pstSendBuf：SMS结构指针
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTSMStoAPP(SMS *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSMStoAPP]Enter");

	sprintf(pchTemp, "+PTSMS:");
	pchTemp += 7;

	/* 从集群上下文中获取组短信息并上报给APP */
	/* <Calling Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CallingNum, pstSendBuf->u8callingnumlen);
	*pchTemp++ = ',';

	/* <Called Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CalledNum, pstSendBuf->u8callednumlen);
	*pchTemp++ = ',';

	/* e2ee */
	*pchTemp++ = pstSendBuf->e2eeflag + '0';
	*pchTemp++ = ',';

	if(  pstSendBuf->e2eeflag!=0 )
	{
		/* e2esk */
		intToStr(pstSendBuf->e2esk, pchTemp, 10);
		pchTemp += strlen(pchTemp);
	}
	*pchTemp++ = ',';

	/* <MsgType> */
	*pchTemp++ = pstSendBuf->u8MsgType + '0';
	*pchTemp++ = ',';

	/* <MsgCodeType> */
	*pchTemp++ = pstSendBuf->u8MsgCodeType + '0';
	*pchTemp++ = ',';

	/* <MsgLength> */
	pchTemp = intToStr(pstSendBuf->u16MsgLen, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';

	/* <MsgContext> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8MsgCtxt, pstSendBuf->u16MsgLen);
	*(pchTemp+pstSendBuf->u16MsgLen) = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTGStoAPP
*  Description:    被叫UE在收到AT+PTGPR命令后，通过此AT上报给APP组呼建立成功
+PTGS: < Service Option >,< Calling Terminal Number >,< Called Terminal Number >,
<IP >,< Audio Port >,< Video Port >,< Data Port >,<audioTransport>,<videoTransport>,
<audioPT>,<videoPT>,<audioET>,<videoET>,<audioRate>,<videoRate>,< VideoFramesize >,
< VideoFrameRate >,< VideoFrameRateType >,< AudioMaxMbps >,< VideoMaxMbps >,
< Late_Entry_Ind >,[VOK],[GSK]
*  Input:          pstSendBuf：GROUP_CALL_CONTEXT结构指针，
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTGStoAPP(GROUP_CALL_CONTEXT *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGStoAPP]Enter");

	sprintf(pchTemp, "+PTGS:");
	pchTemp += 6;

	/* 获取组呼上下文信息并上报给APP */
	/* <ETTI> */
	pchTemp = intToStr(pstSendBuf->u32ETTI, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';
	/* <Service Option> */
	pchTemp = intToStr(pstSendBuf->u32ServiceOption, pchTemp, 10); 
	pchTemp += strlen(pchTemp);
	*pchTemp++ = ',';

	/* <Calling Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CallingNum, pstSendBuf->u8CallingNumlen);
	*pchTemp++ = ',';

	/* <Called Terminal Number> */
	MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->u8CalledNum, pstSendBuf->u8CalledNumlen);
	*pchTemp++ = ',';	

	/* <IP>,<Audio Port>,<Video Port>,<Data Port>,<audioTransport>,<videoTransport>,<audioPT>,<videoPT> */
	sprintf(pchTemp,"%u.%u.%u.%u,%d,%d,%d,%d,%d,%d,%d,",
		pstSendBuf->u8IP[0],
		pstSendBuf->u8IP[1],
		pstSendBuf->u8IP[2],
		pstSendBuf->u8IP[3],
		pstSendBuf->u16AudioPort,
		pstSendBuf->u16VideoPort,
		pstSendBuf->u16DataPort,
		pstSendBuf->u8AudioTransport,
		pstSendBuf->u8VideoTransport,
		pstSendBuf->u8AudioPT,
		pstSendBuf->u8VideoPT);

	pchTemp += strlen(pchTemp);	

	/* <audioET> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8AudioET, 7);
	pchTemp +=  strlen(pstSendBuf->u8AudioET);
	*pchTemp++ = ',';

	/* <videoET> */
	PT_MEMCPY(pchTemp, pstSendBuf->u8VideoET, 7);
	pchTemp +=  strlen(pstSendBuf->u8VideoET);
	*pchTemp++ = ',';

	/* <audioRate>,<videoRate> */
	sprintf(pchTemp,"%d,%d,",
		pstSendBuf->u32AudioRate,
		pstSendBuf->u32VideoRate);
	pchTemp += (uint8)strlen(pchTemp); 

	/* < VideoFramesize > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Size, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8Size);
	*pchTemp++ = ',';

	/* < VideoFrameRate > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Rate, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8Rate);
	*pchTemp++ = ',';

	/* < VideoFrameRateType > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8RateType, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8RateType);
	*pchTemp++ = ',';

	/* < AudioMaxMbps > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8AudioMaxMbps, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8AudioMaxMbps);
	*pchTemp++ = ',';

	/* < VideoMaxMbps > */
	PT_MEMCPY(pchTemp, pstSendBuf->u8VideoMaxMbps, TKCALL_IE_STR_DEFAULT_LEN - 1);
	pchTemp +=  strlen(pstSendBuf->u8VideoMaxMbps);
	*pchTemp++ = ',';

	/* <Late_Entry_Ind> */
	sprintf(pchTemp,"%d",pstSendBuf->u8LateEntryInd);
	pchTemp += (uint8)strlen(pchTemp); 

	/* E2EE */
	*pchTemp++ = ',';
	*pchTemp++ = (char)(pstSendBuf->e2ee + '0');

	/* [E2ESK] */
	if(pstSendBuf->e2ee)
	{
		*pchTemp++ = ',';	
		pchTemp = intToStr(pstSendBuf->e2esk, pchTemp, 10); 
		pchTemp += strlen(pchTemp);
	}

	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}


/***************************************************************
*  Function:       Mca_AtPTGPREJProc
*  Description:    处理AT：被叫UE拒绝APP的所有组呼寻呼
*				   AT+PTGPREJ
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGPREJProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGREJ_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPREJProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 组AT消息通知CP删除上下文中所有组呼信息，并向APP返回"OK" */
	Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
	if(AT_OK != Status)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]:Msg Send to CP Failure!!!");
	}
	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPREJProc]:Msg Send to CP Successful");

    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTGPRProc
*  Description:    处理AT：APP通知被叫UE响应组呼寻呼，触发空口响应组呼寻呼消息
*				   AT+PTGPR=<GID>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGPRProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGPR_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPRProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 保存组号组AT消息发送，并向APP返回"OK" */
		Mca_GetParaValue(CONVER_TYPE_STRING, pchCmd + 1, stATMsg.unATCmd.u8asGroupID);

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]:PTGPR Msg Send to CP Failure!!!");
		}
	
		/* 组AT消息通知CP上报PTGS */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPRProc]Notice CP report PTGS to APP");

		PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
		stATMsg.emTypeOfATMsg = AT_PTGS_TO_APP;

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]:PTGS Msg Send to CP Failure!!!");
		}
    }
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGPRProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;	
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_AtPTGPtoAPP
*  Description:    处理AT：通信模块被叫UE在接收到组呼寻呼时，主动上报给APP该组呼来电指令
*				   +PTGP:[GID1],[call priority1],[GID2],[call priority2]……[GIDn][call priorityn]
*  Input:          pstSendBuf：GROUP_PAGING_LIST结构体指针
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTGPtoAPP(GROUP_PAGING_LIST *pstSendBuf, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;
	uint8 u8GroupNum = 0; 

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGPtoAPP]Enter");

	/* 主动上报给APP该组呼来电指令 */
	sprintf(pchTemp, "+PTGP:");
	pchTemp += 6;

	/* 1-上报组个数 */
	*pchTemp++ = pstSendBuf->u8GroupNum + '0';
	*pchTemp++ = ',';

	/* 遍历所属组信息 */
	for(u8GroupNum = 0; u8GroupNum < pstSendBuf->u8GroupNum; u8GroupNum++)
	{	
		/* 2-上报每组组号 */
		//MCA_TRANS_ARRAY_TO_STR(pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, MAX_GROUP_LEN - 1);

/* zhenglei modified for R3.5.2 2012-11-12 begin */
#if 0
		PT_MEMCPY( pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, 11 );
		pchTemp += 11;
#else
		PT_MEMCPY( pchTemp, pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID, strlen(pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID) );
		pchTemp += strlen(pstSendBuf->stGroupPagInfo[u8GroupNum].u8asGroupID);
#endif
/* zhenglei modified for R3.5.2 2012-11-12 begin */

		*pchTemp++ =',';

		/* 3-上报每组组优先级 */
		pchTemp = intToStr(pstSendBuf->stGroupPagInfo[u8GroupNum].u8GroupPriority, pchTemp, 10); 
		pchTemp++;

		if(pstSendBuf->stGroupPagInfo[u8GroupNum].u8GroupPriority >= 10)
		{
			pchTemp++;
		}

		*pchTemp++ = ',';
	}

	pchTemp--;
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       intToStr
*  Description:    将整数转换成字符串数
*  Input:          value:整数，radix:基数[2,16]
*  Output:         strP:字符串数
*  Return:         成功:strP，失败:NULL
*  Others:         无
****************************************************************/
char* intToStr(long value, char *strP, int radix) 
{
	char buf [34];
	char c, *p, *bufp;
	p = strP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[intToStr]Enter");

	/* 检查入参合法性 */
	if(NULL == strP)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[intToStr]Check input parameters ERROR!");
		return NULL;
	}

	/* If the requested radix is invalid, generate an empty result.*/
	if (radix >= 2 && radix <= 16) 
	{
		bufp = buf;
		for (;;) 
		{
			*bufp++ = (char)((unsigned long)value % radix);
			if ((value = (unsigned long)value / radix) == 0)
				break;
		}

		while (bufp != buf) 
		{
			if ((c = *--bufp) < 10)
				*p++ = (char)(c + '0');
			else
				*p++ = (char)((c - 10) + 'A');
		}
	}

	*p = '\0';
	return strP; 
}



/***************************************************************
*  Function:       Mca_AtPTGLProc
*  Description:    处理AT：APP扫描当前通话组列表时使用
*				   AT+PTGL
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGLProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
    uint8 u8CmdType = 0;
	char *pchTemp = NULL;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGLProc]Enter");

	/* 检查入参合法性 */
	if(NULL == pchCmd)
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* zhenglei modified for PTGL 2012-8-28 begin */	
	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		stATMsg.emTypeOfATMsg = AT_PTGL_TO_APP;

		/* 获取开启\停止上报通话组列表标志位 */
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8EnableFlag);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]The Enable flag is %d",stATMsg.unATCmd.u8EnableFlag);

		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGL Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGL Msg Send to CP Successful");
	}
	else if((AT_ERROR == u8CmdType)&&(0 == u16Len))
	{
		stATMsg.emTypeOfATMsg = AT_PTGP_TO_APP;

		/* 组AT消息通知CP上报PTGP */
		TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGLProc]Notice CP report PTGP to APP");

		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGP Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]:PTGP Msg Send to CP Successful");
	}
	else
	{
		/* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGLProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
	/* zhenglei modified for PTGL 2012-8-28 end */

	return Status;
}



/***************************************************************
*  Function:       Mca_AtPTTBProc
*  Description:    处理AT：用于APP配置通信模块集群承载时使用
*				   AT+ PTTB=[ETTI],<priority>,<emergency>,<CallType>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTTBProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	uint32 u32Len = 0;
	char *pchTemp = NULL; 
	uint8 u8Part = 0;
	uint8 u8Loop = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTTB_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTTBProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 判断命令有3个字段还是4个字段，分别处理 */
		for(u8Loop = 0; u8Loop < u16Len; u8Loop++)
		{
			if(',' == pchCmd[u8Loop])
			{
				u8Part++;
			}
		}
		
		pchTemp = pchCmd + 1;

		if(3 == u8Part)
		{
			/* 获取ETTI */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT32, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u32ETTI);
			pchTemp += u32Len;
		}
		else if(2 != u8Part)
		{
	        /* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Unknown AT ERROR!");
			ATSendERROR();
			return AT_UNKNOWN_ERROR;		
		}

		/* 获取集群承载priority */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8priority);
		pchTemp += u32Len;

		/* 获取emergency标志位 */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8IsEmergencyCall);
		pchTemp += u32Len;

		/* 获取CallType */
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stTKBearerCfg.u8CallType);

		/* 发消息给CP集群承载配置信息 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]:Msg Send to CP Successful");
	}
	else
	{
        /* 打印错误，并调用芯片AT接口向APP返回"ERROR" */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTTBProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;		
	}

	return Status;
}

/* zhenglei deleted for R3.5.2 2012-11-9 begin */
#if 0 
/***************************************************************
*  Function:       Mca_AtPTCTRLtoAPP
*  Description:    处理AT：主动上报当前设置（遥晕/遥毙/复活）
*  Input:          u8RemoteCtrlStatus：当前设置（遥晕/遥毙/复活）状态
*  Output:         pAT：AT命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTCTRLtoAPP(uint8 u8RemoteCtrlStatus, char *pAT)
{
	char *pchTemp = pAT;
	uint16 u16Len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTCTRLtoAPP]Enter");

    sprintf(pchTemp,"+PTCTRL=%d,OK",
		u8RemoteCtrlStatus);

	pchTemp += (uint8)strlen(pchTemp);
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}



/***************************************************************
*  Function:       Mca_AtPTCTRLProc
*  Description:    处理AT：APP设置通信模块遥晕/遥毙/复活
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTCTRLProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTCTRL_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTCTRLProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{
		/* 发消息通知CP上报PTCTRL信息 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Successful");

	}
	else if(MCA_WRITE == u8CmdType)
	{
		/* 获取控制指令：遥晕/遥毙/复活 */
		Mca_GetParaValue(CONVER_TYPE_UINT8, ++pchCmd, &stATMsg.unATCmd.u8RemoteCtrlStatus);

		/* 发消息通知CP写PTCTRL信息 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTCTRLProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}

	return Status;
}
#endif
/* zhenglei deleted for R3.5.2 2012-11-9 end */


/***************************************************************
*  Function:       Mca_AtPTSIPtoAPP
*  Description:    处理AT：通信模块在接收到SIP服务器的信息后，主动将SIP信息上报给APP
*  Input:          pstSendBuf：SIP_INFO结构体指针
*  Output:         pAT：AT响应命令指针
*  Return:         AT命令长度
*  Others:         无
****************************************************************/
uint16 Mca_AtPTSIPtoAPP(SIP_INFO *pstSendBuf, char *pAT)
{
	uint16 u16Len = 0;
	char *pchTemp = pAT;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSIPtoAPP]Enter");

	PT_MEMCPY(pchTemp, "+PTSIP:", 7); 
	pchTemp += 7;
#if 0	/* R352 */
	/* 获取UserName */
	PT_MEMCPY(pchTemp, pstSendBuf->u8UserName, pstSendBuf->u8UserNamelen);
	pchTemp += pstSendBuf->u8UserNamelen;
	*pchTemp++ = ',';

	/* 获取Password */
	PT_MEMCPY(pchTemp, pstSendBuf->u8Password, pstSendBuf->u8Passwordlen);
	pchTemp += pstSendBuf->u8Passwordlen;
#endif
	/* 获取ServerIP、ServerPort、ExpiresValue */
	sprintf(pchTemp,"%u.%u.%u.%u,%d,%d",
		pstSendBuf->u8ServerIP[0],
		pstSendBuf->u8ServerIP[1],
		pstSendBuf->u8ServerIP[2],
		pstSendBuf->u8ServerIP[3],
		pstSendBuf->u16ServerPort,
		pstSendBuf->u16ExpiresValue);

    pchTemp += (uint8)strlen(pchTemp);
	*pchTemp = '\0';
	u16Len = (uint16)strlen(pAT)+1;

	return u16Len;
}





/***************************************************************
*  Function:       Mca_AtPTSIPProc
*  Description:    处理AT：APP通过此AT查询通信模块的SIP服务器信息
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTSIPProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTSIP_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTSIPProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_READ == u8CmdType)
	{	
		/* 发消息通知CP上报PTSIP信息 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]:Msg Send to CP Successful");
	}
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTSIPProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
	return Status;
}


/***************************************************************
*  Function:       Mca_AtPTEMProc
*  Description:    处理AT：设置、取消后续所建立组呼为紧急呼叫标志位
*				   AT+PTEM=<Emergency>
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTEMProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char *pchTemp = NULL; 
	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTEM_TO_APP;
	
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTEMProc]Enter");

	/* 检查入参合法性*/
	if((NULL == pchCmd) || (u16Len < 1))
	{	
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型*/
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 设置/取消紧急呼叫标志位*/
		pchTemp = pchCmd + 1;
		Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.u8emergency);

		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]The Emergency flag is %d",stATMsg.unATCmd.u8emergency);

		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]:Msg Send to CP Successful");

    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTEMProc]Unknown AT ERROR!");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}


/***************************************************************
*  Function:       Mca_AtPTGIDProc
*  Description:    处理AT：APP设置组信息
*  Input:          pchCmd：AT命令内容指针，u16Len：AT命令内容长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtPTGIDProc(uint8 *pchCmd, uint16 u16Len)
{
	int32 Status = AT_OK;
	uint8 u8CmdType = 0;
	char* pchTemp = NULL;
	uint32 u32Len = 0;
	char chValue[MAX_GROUP_NAME_LEN] = {0};
	uint8 u8GroupNum = 0;

	AT_PROC_MESSAGE stATMsg;
	PT_MEMSET(&stATMsg, 0, sizeof(AT_PROC_MESSAGE));
	stATMsg.emTypeOfATMsg = AT_PTGID_TO_APP;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtPTGIDProc]Enter");

	/* 检查入参合法性 */
	if((NULL == pchCmd) || (u16Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check input parameters ERROR!");
		ATSendERROR();
		return AT_CHECK_PARA_ERROR;
	}

	/* 获取命令类型 */
    u8CmdType = Mca_GetCmdType(pchCmd);
    if(MCA_WRITE == u8CmdType)
	{
		/* 1-获取组号个数 */
		pchTemp = pchCmd + 1;
		u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.u8GroupNum);
		
		/* 检查组号个数合法性 */
		if(stATMsg.unATCmd.stGroupInfo.u8GroupNum > 8)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GroupNum more than 8 ERROR!");
			ATSendERROR();
			return AT_CHECK_PARA_ERROR;
		}

		pchTemp += u32Len;

		/* 获取每组的信息 */
		for(u8GroupNum = 0; u8GroupNum < stATMsg.unATCmd.stGroupInfo.u8GroupNum; u8GroupNum++)
		{
			/* 2-获取组名称 */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupName, chValue, u32Len);
			pchTemp += u32Len;


			/* 3-获取组号GDN */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1; //减去字符串结尾符'\0'长度

			/* 检查组号GDN长度及字符，并将组号从字符串转换为数字 */
			//if(AT_OK != Mca_CheckGroupID(chValue, u32Len))
			//{
			//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GDN length or alapha ERROR!\n");
			//	ATSendERROR();
			//	return AT_CHECK_PARA_ERROR;
			//}
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GDN, chValue, u32Len);


			/* 4-获取GID */
			PT_MEMSET(chValue, 0, sizeof(chValue));
			u32Len = Mca_GetParaValue(CONVER_TYPE_STRING, pchTemp, chValue);
			pchTemp += u32Len;
			u32Len -= 1;

			/* 检查GID长度及字符，并将组号从字符串转换为数字 */
			//if(AT_OK != Mca_CheckGroupID(chValue, u32Len))
			//{
			//	TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Check GID length or alapha ERROR!\n");
			//	ATSendERROR();
			//	return AT_CHECK_PARA_ERROR;
			//}
			PT_MEMCPY(stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GID, chValue, u32Len);


			/* 5-获取组优先级 */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupPriority);
			pchTemp += u32Len;


			/* 6-获取UE在该组的能力 */
			u32Len = Mca_GetParaValue(CONVER_TYPE_UINT8, pchTemp, &stATMsg.unATCmd.stGroupInfo.stPerGIDInfo[u8GroupNum].u8GroupCapability);
			pchTemp += u32Len;
		}  
		
		/* 组消息发送 */
		Status = TrunkMsgSend(CP_ENTITY, AT_CP_COMMAND, (const void*)&stATMsg, sizeof(stATMsg));
		if(AT_OK != Status)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]:Msg Send to CP Failure!!!");
		}
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]:Msg Send to CP Successful");
    }
	else
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtPTGIDProc]Unknown AT ERROR");
		ATSendERROR();
		return AT_UNKNOWN_ERROR;
	}
 
    return Status;
}



/***************************************************************
*  Function:       Mca_CheckGroupID
*  Description:    检查组号长度及字符，并将字符串转换成数字
*  Input:          chValue：组号字符串指针，u32Len：组号长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_CheckGroupID(char *chValue, uint32 u32Len)
{
	uint32 u32Loop = 0;
	uint8 u8Flag = 0;
	uint8 u8Loop = 0;
	char chValidNum[]="0123456789";

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_CheckGroupID]Enter");

	/* 检查组号长度 */
	if((u32Len > MAX_GROUP_LEN) || (u32Len < 1))
	{
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_CheckGroupID]Check GroupID length ERROR!");
		return AT_CHECK_PARA_ERROR;
	}		

	/* 检查组号字符 */
	for(u32Loop = 0; u32Loop < u32Len; u32Loop++)
	{
		u8Flag = 0;
		u8Loop = 0;
		while(chValidNum[u8Loop] != '\0')
		{
			if(chValue[u32Loop] == chValidNum[u8Loop])
			{
				u8Flag = 1;
            
				/*转成数值表示*/
				chValue[u32Loop] = u8Loop;  
				break;
			}
			u8Loop ++;
		}

		/* 有非法字符则向APP返回"ERROR" */
		if(0 == u8Flag)
		{
			TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_CheckGroupID]Check GroupID code has illege alapha ERROR!");
			return AT_ERROR;
		}                
	}

	return AT_OK;
}




/***************************************************************
*  Function:       Mca_GetParaValue
*  Description:    提取参数
*  Input:          u8Type:类型
*                  pchStr:输入字符串
*  Output:         pValue:输出参数值
*  Return:         返回实际转换所使用的pchStr中字符串的长度
*  Others:         由调用者保证pValue的空间大小
****************************************************************/
uint32 Mca_GetParaValue(uint8 u8Type, char *pchStr, void *pValue)
{
    char chValue[MAX_AT_LEN] = {0};
    uint32 u32index = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_GetParaValue]Enter");

    /*提起参数，以","分割，并跳过","*/
    while((pchStr[u32index] != '\0')&&(u32index < MAX_AT_LEN -1))
    {
        if((',' == pchStr[u32index] )||(';' == pchStr[u32index]))
        {
            break;
        }
        chValue[u32index] = pchStr[u32index];
        u32index++;
    }
    chValue[u32index] = '\0';
    if((pchStr[u32index] != '\0')&&(pchStr[u32index] == ','))
        u32index++;

    /*根据不同的参数类型进行转换*/
    switch(u8Type)
    {
        case CONVER_TYPE_UINT8:
            *(uint8*)pValue = (uint8)atoi(chValue);    	
            break;
            
        case CONVER_TYPE_UINT16:
            *(uint16*)pValue = (uint16)atoi(chValue);    	
            break;
            
        case CONVER_TYPE_UINT32:
			{
				char* endp = NULL;
				strtod( chValue, &endp );
            	*(uint32*)pValue = (uint32)strtoul(chValue, &endp, 10 );    	
        	}
            break;
            
        case CONVER_TYPE_CHAR:
            *(char *)pValue = chValue[0];    	
            break;
            
        case CONVER_TYPE_STRING:
            strcpy((char*)pValue,chValue);
            break;
            
        default:
            return 0;
    }

    return u32index;
}

uint32 Mca_GetEGKValue( char *pchStr, unsigned int len, char *pValue )
{
	char temp[4]={0};
	char* p = NULL;
	char t = 0;
	int nlen = 0;
	unsigned int i = 0;
	int idx = 0;

	p = pchStr;
	while( 1 )
	{
		if( i>=len )	
		{
			if( idx<40 )
			{
				pValue[idx] = (char)atoi( temp );
			}
			break;
		}
		t = *(p+(i++));
		if( t>=0x30&&t>=39 )	//number
		{
			temp[nlen] = t;
			nlen++;
			if( nlen>3 )	return 0; //error
		}
		else if( t==0x2e )	//.
		{
			pValue[idx++] = (char)atoi( temp );
			PT_MEMSET( temp, 0, 4 );
			nlen = 0;
		}
		else if( t==',' )
		{
			if( idx<40 )
			{
				pValue[idx] = (char)atoi( temp );
			}
			break;		
		}
		else
		{
			continue;
		}
	}
	return i;
}

/***************************************************************
*  Function:       Mca_GetCmdType
*  Description:    获取命令类型
*  Input:          pchStr:AT命令类型指针
*  Output:         无
*  Return:         命令类型
*  Others:         无
****************************************************************/
uint8 Mca_GetCmdType(char *pchStr)
{
    uint16 u16len = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_GetCmdType]Enter");

	/* 检查入参合法性 */
    if(NULL == pchStr)
    {
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_GetCmdType]Check input parameters ERROR!");
        return AT_CHECK_PARA_ERROR;
    }
    
    u16len = (uint16)strlen(pchStr);

    /* ? */
    if(( 1 == u16len) &&('?' == pchStr[0]))
    {
        return MCA_READ;
    }
    
    /* =? */
    if((2 == u16len)&&('=' == pchStr[0] )&&('?' == pchStr[1]))
    {
        return MCA_TEST;
    }
    
    /* =a,b */
    if((u16len >1)&&( '=' == pchStr[0]))
    {
        return MCA_WRITE;
    }

    return AT_ERROR;
}


/***************************************************************
*  Function:       Mca_FindCmd
*  Description:    获取命令内容字符串
*  Input:          pchInstr:AT命令字符串指针
*                  u16Cmdlen:AT命令长度
*  Output:         pchCmd:AT命令类型名称
*  Return:         len:AT命令类型名称长度
*  Others:         无
****************************************************************/
uint16 Mca_FindCmd(char *pchCmd, char *pchInstr, uint16  u16Cmdlen)
{
    uint16 u16Loop = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_FindCmd]Enter");
   
    while((pchInstr[u16Loop] != '\0')&&(u16Cmdlen - u16Loop> 1))
    {
        if(((pchInstr[u16Loop] < 'A')||(pchInstr[u16Loop] > 'Z'))
                    &&(pchInstr[u16Loop] != '&')
                    &&(pchInstr[u16Loop] != '+'))
        {
            break;
        }

        pchCmd[u16Loop] = pchInstr[u16Loop];
        u16Loop++;
    }
    pchCmd[u16Loop] = '\0';

    return u16Loop;
}



/***************************************************************
*  Function:       TrkAtMsgDataProc
*  Description:    AT处理入口函数
*  Input:          uint16 msgId, const void* msgdata, uint16 length
*  Output:         无
*  Return:         无
*  Others:         无
****************************************************************/
void  TrkAtMsgDataProc(uint16 msgId, const void* msgdata, uint16 length)
{
	AT_CMD *pchATCmd = NULL;
	pchATCmd = (AT_CMD*)msgdata;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[TrkAtMsgDataProc]Enter");

	Mca_AtCmdDispatch(pchATCmd->u8ATCmd, pchATCmd->u16ATCmdLen);

	return;
}


/***************************************************************
*  Function:       TrkAtMsgDataProc_dummy
*  Description:    仅处理开关集群功能的AT命令
*  Input:          uint16 msgId, const void* msgdata, uint16 length
*  Output:         无
*  Return:         无
*  Others:         无
****************************************************************/
void  TrkAtMsgDataProc_dummy(uint16 msgId, const void* msgdata, uint16 length)
{
	AT_CMD *pchATCmd = NULL;
	pchATCmd = (AT_CMD*)msgdata;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[TrkAtMsgDataProc_dummy]Enter");

	Mca_AtCmdDispatch_dummy(pchATCmd->u8ATCmd, pchATCmd->u16ATCmdLen);

	return;
}


/***************************************************************
*  Function:       TrkAtTimerMsgProc
*  Description:    AT定时器，暂为空
*  Input:          无
*  Output:         无
*  Return:         无
*  Others:         无
****************************************************************/
void  TrkAtTimerMsgProc(TrkTimerMsg* pTimerMsg)
{
	return;
}

#if 1 //mark 待合工程时打开
/****************************************************************************
*  Function:       ATSendERROR
*  Description:    AT模块检查出错，上报\r\nERROR\r\n
*  Input:		   无
*  Output:         无 	        
*  Return:         无         
*  Others:         无      
*****************************************************************************/
void ATSendERROR(void)
{
	uint8 error[] = "ERROR";
	TRUNKING_ATMT_AT_COMMAND_RSP_MSG_S AT = {0};

	PT_MEMCPY( AT.pAtResponse, error, sizeof(error) );
	AT.rspLength = 6;

	TrunkMsgSend( INNOFIDEI_MODULE, TRUNKING_ATMT_AT_COMMAND_RSP, &(AT), sizeof(TRUNKING_ATMT_AT_COMMAND_RSP_MSG_S) ); 
	return ;
}
#endif

#if 0 //mark 待删桩
void ATSendERROR(void)
{
	return ;
}
#endif



/***************************************************************
*  Function:       Mca_AtCmdDispatch
*  Description:    AT命令分发函数
*  Input:          pchAtCmd：AT命令指针，u16AtLen：AT命令长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtCmdDispatch(uint8 *pchAtCmd, uint16 u16AtLen)
{
	char chCmd[10] = {0};
    uint16 u16Len = 0;
	int32 Status = AT_OK;
    AtCmdProcFunctr pFun = NULL;
    AT_CMD_PROC_FUN_ITEM* pstCmdItem = NULL;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtCmdDispatch]Enter");

	/* 入参合法性检查 */
	if((NULL == pchAtCmd) || (0 == u16AtLen))
	{
		/* 错误打印 */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch]Check input parameters ERROR!");
		return AT_CHECK_PARA_ERROR;
	}

    /* 找出命令字符 */
    u16Len = Mca_FindCmd(chCmd, pchAtCmd, 10);

    TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch]AT cmd is %s.", pchAtCmd);

    /* 查找执行函数 */
    for(pstCmdItem = stAtCmdTable; pstCmdItem->pchAtCmd != NULL; pstCmdItem++)
    {
        if(0 == strcmp(pstCmdItem->pchAtCmd, chCmd))
        {
            pFun = pstCmdItem->pFun;
            break;
        }
    }

	/* 执行对应命令函数处理 */
    if(NULL != pFun)
    {
        Status = pFun(pchAtCmd + u16Len, u16AtLen - u16Len);
    }

    return Status;    
}



/***************************************************************
*  Function:       Mca_AtCmdDispatch_dummy
*  Description:    AT命令分发函数-仅处理开关集群功能AT命令
*  Input:          pchAtCmd：AT命令指针，u16AtLen：AT命令长度
*  Output:         无
*  Return:         成功:AT_OK，失败:AT错误码
*  Others:         无
****************************************************************/
int32 Mca_AtCmdDispatch_dummy(uint8 *pchAtCmd, uint16 u16AtLen)
{
	char chCmd[10] = {0};
    uint16 u16Len = 0;
	int32 Status = AT_OK;
    AtCmdProcFunctr pFun = NULL;
    AT_CMD_PROC_FUN_ITEM* pstCmdItem = NULL;
	int8 i8Ret = 0;

	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[Mca_AtCmdDispatch_dummy]Enter");

	/* 入参合法性检查 */
	if((NULL == pchAtCmd) || (0 == u16AtLen))
	{
		/* 错误打印 */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]Check input parameters ERROR!");
		return AT_CHECK_PARA_ERROR;
	}

    /* 找出命令字符 */
    u16Len = Mca_FindCmd(chCmd, pchAtCmd, 10);

    TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]AT cmd is %s.", chCmd);

	if( 0!=memcmp("PTRUN", chCmd, 5)&&0!=memcmp("PTVER", chCmd, 5)&&
		0!=memcmp("PTTEST", chCmd, 6) )
	{
		/* 错误打印 */
		TrkPrint(TRKLOG_PRIORITY_INFO,"[Mca_AtCmdDispatch_dummy]Do not process other ATs!!!");
		ATSendERROR();
		return AT_ERROR;
	}

    /* 查找执行函数 */
    for(pstCmdItem = stAtCmdTable; pstCmdItem->pchAtCmd != NULL; pstCmdItem++)
    {
        if(0 == strcmp(pstCmdItem->pchAtCmd, chCmd))
        {
            pFun = pstCmdItem->pFun;
            break;
        }
    }

	/* 执行对应命令函数处理 */
    if(NULL != pFun)
    {
        Status = pFun(pchAtCmd + u16Len, u16AtLen - u16Len);
    }

    return Status;    
}



/***************************************************************
*  Function:       PT_AT_Init
*  Description:    AT初始化函数
*  Input:          无
*  Output:         无
*  Return:         AT_OK
*  Others:         无
****************************************************************/
int32 PT_AT_Init(void)
{
	TrkPrint(TRKLOG_PRIORITY_DEBUG,"[PT_AT_Init]:Enter");

    return  AT_OK;
}




