@ TODO UNUSED?
SCRIPT_START script_08012B24
	BeginBlock
	SetEntitySpeed 0x0100
	SetAnimationState 0x0004
	EndBlock
	DoPostScriptAction 0x0001
	WalkSouth 0x0008
	SetSyncFlag 0x00000002
	CallWithArg sub_0807FB64, 0xffffffe2
	Call SetPlayerActionNormal
SCRIPT_END