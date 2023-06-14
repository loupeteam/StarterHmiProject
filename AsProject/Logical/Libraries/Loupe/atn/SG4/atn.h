/* Automation Studio generated header file */
/* Do not edit ! */
/* atn 0.05.1 */

#ifndef _ATN_
#define _ATN_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _atn_VERSION
#define _atn_VERSION 0.05.1
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "stringext.h"
		#include "vartools.h"
#endif
#ifdef _SG4
		#include "stringext.h"
		#include "vartools.h"
#endif
#ifdef _SGC
		#include "stringext.h"
		#include "vartools.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define MAI_ATN_ACTIONS 99U
 #define MAI_ATN_ACTIONLISTS 9U
 #define MAI_ATN_ACT_ACTIONS 10U
 #define MAI_ATN_ACT_THREADS 0U
 #define ATN_ACTION_NAME_LEN 20U
 #define ATN_NAMESPACE_LEN 20U
#else
 _GLOBAL_CONST unsigned char MAI_ATN_ACTIONS;
 _GLOBAL_CONST unsigned char MAI_ATN_ACTIONLISTS;
 _GLOBAL_CONST unsigned char MAI_ATN_ACT_ACTIONS;
 _GLOBAL_CONST unsigned char MAI_ATN_ACT_THREADS;
 _GLOBAL_CONST unsigned char ATN_ACTION_NAME_LEN;
 _GLOBAL_CONST unsigned char ATN_NAMESPACE_LEN;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum ATN_SST_enum
{	ATN_SS_INIT
} ATN_SST_enum;

typedef enum ATN_ST_enum
{	ATN_IDLE,
	ATN_EXECUTE,
	ATN_WAITING,
	ATN_DONE,
	ATN_ABORT,
	ATN_ERROR,
	ATN_BYPASSED
} ATN_ST_enum;

typedef enum ATN_ERROR_enum
{	ATN_ERROR_OK = 0,
	ATN_ERROR_ACTIVE,
	ATN_ERROR_ABORTED,
	ATN_ERROR_ACTIONS_FULL,
	ATN_ERROR_BUSY = 65535
} ATN_ERROR_enum;

typedef enum ATN_RESPONSE_ST
{	ATN_RESPONSE_ST_NONE,
	ATN_RESPONSE_ST_ERROR,
	ATN_RESPONSE_ST_STEP_DONE,
	ATN_RESPONSE_ST_NEXT_STEP,
	ATN_RESPONSE_ST_STATE_DONE,
	ATN_RESPONSE_ST_BUSY
} ATN_RESPONSE_ST;

typedef enum ATN_PLCOPEN_FUB_STATE_enum
{	ATN_PLCOPEN_FUB_IDLE,
	ATN_PLCOPEN_FUB_NEW_COMMAND,
	ATN_PLCOPEN_FUB_ABORT_OLD,
	ATN_PLCOPEN_FUB_WRITE_PAR,
	ATN_PLCOPEN_FUB_SET_COMMAND,
	ATN_PLCOPEN_FUB_WORKING,
	ATN_PLCOPEN_FUB_STATUS,
	ATN_PLCOPEN_FUB_CLEANUP,
	ATN_PLCOPEN_FUB_DONE,
	ATN_PLCOPEN_FUB_ABORTED
} ATN_PLCOPEN_FUB_STATE_enum;

typedef struct AtnInCmd_typ
{	plcbit abort;
	plcbit forceQuit;
} AtnInCmd_typ;

typedef struct AtnInPar_typ
{	plcstring category[21];
	unsigned char ID;
} AtnInPar_typ;

typedef struct AtnIn_typ
{	struct AtnInCmd_typ cmd;
	struct AtnInPar_typ par;
} AtnIn_typ;

typedef struct AtnOutStatus_typ
{	plcbit blocked;
	plcbit busy;
	plcbit done;
	plcbit error;
} AtnOutStatus_typ;

typedef struct AtnActiveThread_typ
{	plcstring action[21];
	unsigned long busyModule[11];
	unsigned long errorModule[11];
	struct AtnOutStatus_typ status;
} AtnActiveThread_typ;

typedef struct AtnOut_typ
{	struct AtnActiveThread_typ activeThreads[1];
	plcbit busy;
	plcbit done;
	plcbit error;
} AtnOut_typ;

typedef struct AtnActionCmdData_typ
{	plcstring name[21];
	unsigned long pParameters;
	unsigned long sParameters;
	unsigned long pStatusStructure;
} AtnActionCmdData_typ;

typedef struct AtnThread_typ
{	unsigned char ID;
	struct AtnActionCmdData_typ request;
	struct AtnActionCmdData_typ activeRequest;
	enum ATN_ST_enum state;
	unsigned long substate;
	unsigned long nextSubState;
	plcbit abort;
	plcbit forceQuit;
	enum ATN_RESPONSE_ST responseStatus;
	unsigned long actions;
	unsigned long actionCount;
	unsigned long substateRequestModule;
	unsigned long busyModule[11];
	unsigned long blockingModule[11];
	unsigned long errorModule[11];
	unsigned long activeActions[11];
	struct AtnOutStatus_typ status;
} AtnThread_typ;

typedef struct AtnInternal_typ
{	struct AtnThread_typ thread;
} AtnInternal_typ;

typedef struct Atn_typ
{	struct AtnIn_typ in;
	struct AtnOut_typ out;
	struct AtnInternal_typ internal;
} Atn_typ;

typedef struct AtnApiStatus_typ
{	plcbit active;
	plcbit busy;
	plcbit done;
	plcbit aborted;
	plcbit error;
	unsigned long errorID;
} AtnApiStatus_typ;

typedef struct AtnApiStatusLocal_typ
{	plcbit active;
	plcbit busy;
	plcbit done;
	plcbit aborted;
	plcbit error;
	unsigned long errorID;
	struct AtnApiStatus_typ remote;
} AtnApiStatusLocal_typ;

typedef struct AtnAPI_typ
{	plcstring moduleName[81];
	plcstring moduleStatus[81];
	plcstring request[21];
	enum ATN_ST_enum state;
	enum ATN_ST_enum response;
	unsigned long subState;
	unsigned long subStateReq;
	plcbit oneShot;
	plcbit moduleBypass;
	plcbit moduleIsBypassed;
	unsigned long* activeThread;
	unsigned long* waitingThread;
	unsigned char waitingDirectorID;
} AtnAPI_typ;

typedef struct AtnAPIState_typ
{	plcstring moduleName[81];
	plcstring moduleStatus[81];
	plcbit moduleBypass;
	plcbit moduleIsBypassed;
	plcbit active;
} AtnAPIState_typ;

typedef struct AtnActionList_typ
{	plcstring name[21];
	unsigned long maxActions;
	struct AtnActionData_typ* pActions;
} AtnActionList_typ;

typedef struct AtnActionData_typ
{	plcstring name[21];
	unsigned long pParameters;
	unsigned long sParameters;
	struct AtnAPI_typ* pAction;
} AtnActionData_typ;

typedef struct AtnPlcOpenCall
{	plcbit abort;
} AtnPlcOpenCall;

typedef struct AtnPlcOpenInternal
{	unsigned long fbk;
	plcbit trig;
} AtnPlcOpenInternal;

typedef struct AtnPlcOpenStatus
{	plcstring activeCommand[81];
	signed long status;
	plcbit parametersWritten;
	plcbit bypass;
	struct AtnPlcOpenInternal internal;
} AtnPlcOpenStatus;

typedef struct AtnRunAction
{
	/* VAR_INPUT (analog) */
	unsigned long director;
	plcstring action[21];
	unsigned long pParameters;
	unsigned long parameterSize;
	/* VAR (analog) */
	struct AtnApiStatus_typ status;
	/* VAR_INPUT (digital) */
	plcbit execute;
	/* VAR_OUTPUT (digital) */
	plcbit busy;
	plcbit done;
	plcbit active;
	plcbit aborted;
	plcbit error;
	/* VAR (digital) */
	plcbit _execute;
} AtnRunAction_typ;

typedef struct stateAllTrueFb
{
	/* VAR_INPUT (analog) */
	plcstring state[81];
	/* VAR (analog) */
	unsigned long* cache;
	/* VAR_INPUT (digital) */
	plcbit update;
	plcbit fallback;
	/* VAR_OUTPUT (digital) */
	plcbit value;
} stateAllTrueFb_typ;

typedef struct stateAnyTrueFb
{
	/* VAR_INPUT (analog) */
	plcstring state[81];
	/* VAR (analog) */
	unsigned long* cache;
	/* VAR_INPUT (digital) */
	plcbit update;
	plcbit fallback;
	/* VAR_OUTPUT (digital) */
	plcbit value;
} stateAnyTrueFb_typ;

typedef struct stateAllFalseFb
{
	/* VAR_INPUT (analog) */
	plcstring state[81];
	/* VAR (analog) */
	unsigned long* cache;
	/* VAR_INPUT (digital) */
	plcbit update;
	plcbit fallback;
	/* VAR_OUTPUT (digital) */
	plcbit value;
} stateAllFalseFb_typ;

typedef struct stateAnyFalseFb
{
	/* VAR_INPUT (analog) */
	plcstring state[81];
	/* VAR (analog) */
	unsigned long* cache;
	/* VAR_INPUT (digital) */
	plcbit update;
	plcbit fallback;
	/* VAR_OUTPUT (digital) */
	plcbit value;
} stateAnyFalseFb_typ;

typedef struct AtnPLCOpen
{
	/* VAR_INPUT (analog) */
	plcstring Command[81];
	signed long Fallback;
	/* VAR_OUTPUT (analog) */
	signed long Status;
	plcstring StatusMessage[10][81];
	/* VAR (analog) */
	unsigned char _state;
	unsigned long _command;
	struct AtnPlcOpenCall _call;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Done;
	plcbit Aborted;
	plcbit Error;
	/* VAR (digital) */
	plcbit _execute;
} AtnPLCOpen_typ;

typedef struct AtnPLCOpenWithParameters
{
	/* VAR_INPUT (analog) */
	plcstring Command[81];
	signed long Fallback;
	unsigned long* pParameters;
	unsigned long sParameters;
	/* VAR_OUTPUT (analog) */
	signed long Status;
	plcstring StatusMessage[10][81];
	/* VAR (analog) */
	unsigned char _state;
	unsigned long _command;
	struct AtnPlcOpenCall _call;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Done;
	plcbit Aborted;
	plcbit Error;
	/* VAR (digital) */
	plcbit _execute;
} AtnPLCOpenWithParameters_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void AtnRunAction(struct AtnRunAction* inst);
_BUR_PUBLIC void stateAllTrueFb(struct stateAllTrueFb* inst);
_BUR_PUBLIC void stateAnyTrueFb(struct stateAnyTrueFb* inst);
_BUR_PUBLIC void stateAllFalseFb(struct stateAllFalseFb* inst);
_BUR_PUBLIC void stateAnyFalseFb(struct stateAnyFalseFb* inst);
_BUR_PUBLIC void AtnPLCOpen(struct AtnPLCOpen* inst);
_BUR_PUBLIC void AtnPLCOpenWithParameters(struct AtnPLCOpenWithParameters* inst);
_BUR_PUBLIC unsigned long atninit(unsigned long buff, unsigned long bufsize);
_BUR_PUBLIC unsigned long atncyclic(unsigned long buff, unsigned long bufsize);
_BUR_PUBLIC unsigned char atnRunAction(struct Atn_typ* director, plcstring* action, unsigned long* pParameters, unsigned long parameterSize, struct AtnApiStatus_typ* status);
_BUR_PUBLIC unsigned char atnCyclic(struct Atn_typ* director);
_BUR_PUBLIC unsigned char atnRegisterActionPV(plcstring* category, plcstring* name, plcstring* actionPv, plcstring* parameterPv);
_BUR_PUBLIC unsigned char atnRegisterActionPVLocal(plcstring* category, plcstring* name, plcstring* actionPv, plcstring* parameterPv);
_BUR_PUBLIC unsigned char atnRegisterAction(plcstring* category, plcstring* name, struct AtnAPI_typ* pAction, unsigned long* pParameters, unsigned long parameterSize);
_BUR_PUBLIC unsigned long atnGetActionList(plcstring* gategory);
_BUR_PUBLIC plcbit atnSetActionList(plcstring* gategory, struct AtnActionData_typ* pActions, unsigned long size);
_BUR_PUBLIC plcbit populateActionList(plcstring* listname);
_BUR_PUBLIC unsigned long registerStateBool(plcstring* state, plcstring* moduleName, plcbit* value);
_BUR_PUBLIC unsigned long registerStateBoolAdr(plcstring* state, plcstring* moduleName, plcbit* value);
_BUR_PUBLIC unsigned long registerStateParameters(plcstring* state, plcstring* moduleName, unsigned long* pParameters, unsigned long sParameters);
_BUR_PUBLIC unsigned long registerStateExt1(plcstring* state, plcstring* moduleName, plcstring* pModuleStatus, unsigned long* pParameters, unsigned long sParameters, plcbit* pModuleByPass, plcbit* pActive);
_BUR_PUBLIC unsigned long registerToResource(plcstring* resource, plcstring* moduleName, unsigned long* pResourceUserId, plcbit* pResourceActive);
_BUR_PUBLIC unsigned long subscribeCommandBool(plcstring* commandName, plcstring* moduleName, plcbit* command);
_BUR_PUBLIC unsigned long subscribePLCOpen(plcstring* commandName, plcstring* moduleName, plcbit* command, struct AtnPlcOpenStatus* status);
_BUR_PUBLIC unsigned long subscribePLCOpenWithParameters(plcstring* commandName, plcstring* moduleName, unsigned long* pParameters, unsigned long sParameters, plcbit* command, struct AtnPlcOpenStatus* status);
_BUR_PUBLIC plcbit atnPLCOpenAbort(struct AtnPlcOpenStatus* status);
_BUR_PUBLIC plcbit stateAllTrue(plcstring* state, plcbit fallback);
_BUR_PUBLIC plcbit stateAnyTrue(plcstring* state, plcbit fallback);
_BUR_PUBLIC plcbit stateAllFalse(plcstring* state, plcbit fallback);
_BUR_PUBLIC plcbit stateAnyFalse(plcstring* state, plcbit fallback);
_BUR_PUBLIC signed short stateCount(plcstring* State);
_BUR_PUBLIC plcbit forState(plcstring* State, signed short indexer, plcbit* active, unsigned long* pParameters, unsigned long sParameters);
_BUR_PUBLIC plcbit forStateGetPointer(plcstring* State, signed short indexer, plcbit* active, unsigned long* pParameters, unsigned long* sParameters);
_BUR_PUBLIC plcbit executeCommand(plcstring* Command);
_BUR_PUBLIC plcbit stateTrueStatus(plcstring* state, unsigned long buffer, unsigned long sBuffer);
_BUR_PUBLIC plcbit stateFalseStatus(plcstring* state, unsigned long buffer, unsigned long sBuffer);
_BUR_PUBLIC plcbit stateStatus(plcstring* state, unsigned long buffer, unsigned long sBuffer);
_BUR_PUBLIC plcbit systemJson(unsigned long buffer, unsigned long sBuffer);
_BUR_PUBLIC plcbit resourceIsAvailable(plcstring* resourceName, unsigned long resourceUserId);
_BUR_PUBLIC plcbit isInhibited(plcstring* inhibit);


#ifdef __cplusplus
};
#endif
#endif /* _ATN_ */

