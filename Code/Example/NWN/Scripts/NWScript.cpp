#include "NWN/Scripts/NWScript.hpp"

namespace nwn::vm
{

int Random(int nMaxInteger)
{
    vm::impl::push_int(nMaxInteger);
    vm::impl::call_builtin(0);
    return vm::impl::pop_int();
}

void PrintString(CExoString sString)
{
    vm::impl::push_string(sString);
    vm::impl::call_builtin(1);
}

void PrintFloat(float fFloat, int nWidth, int nDecimals)
{
    vm::impl::push_int(nDecimals);
    vm::impl::push_int(nWidth);
    vm::impl::push_float(fFloat);
    vm::impl::call_builtin(2);
}

CExoString FloatToString(float fFloat, int nWidth, int nDecimals)
{
    vm::impl::push_int(nDecimals);
    vm::impl::push_int(nWidth);
    vm::impl::push_float(fFloat);
    vm::impl::call_builtin(3);
    return vm::impl::pop_string();
}

void PrintInteger(int nInteger)
{
    vm::impl::push_int(nInteger);
    vm::impl::call_builtin(4);
}

void PrintObject(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(5);
}

void ExecuteScript(CExoString sScript, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_string(sScript);
    vm::impl::call_builtin(8);
}

void ClearAllActions(int nClearCombatState)
{
    vm::impl::push_int(nClearCombatState);
    vm::impl::call_builtin(9);
}

void SetFacing(float fDirection)
{
    vm::impl::push_float(fDirection);
    vm::impl::call_builtin(10);
}

void SetCalendar(int nYear, int nMonth, int nDay)
{
    vm::impl::push_int(nDay);
    vm::impl::push_int(nMonth);
    vm::impl::push_int(nYear);
    vm::impl::call_builtin(11);
}

void SetTime(int nHour, int nMinute, int nSecond, int nMillisecond)
{
    vm::impl::push_int(nMillisecond);
    vm::impl::push_int(nSecond);
    vm::impl::push_int(nMinute);
    vm::impl::push_int(nHour);
    vm::impl::call_builtin(12);
}

int GetCalendarYear()
{
    vm::impl::call_builtin(13);
    return vm::impl::pop_int();
}

int GetCalendarMonth()
{
    vm::impl::call_builtin(14);
    return vm::impl::pop_int();
}

int GetCalendarDay()
{
    vm::impl::call_builtin(15);
    return vm::impl::pop_int();
}

int GetTimeHour()
{
    vm::impl::call_builtin(16);
    return vm::impl::pop_int();
}

int GetTimeMinute()
{
    vm::impl::call_builtin(17);
    return vm::impl::pop_int();
}

int GetTimeSecond()
{
    vm::impl::call_builtin(18);
    return vm::impl::pop_int();
}

int GetTimeMillisecond()
{
    vm::impl::call_builtin(19);
    return vm::impl::pop_int();
}

void ActionRandomWalk()
{
    vm::impl::call_builtin(20);
}

void ActionMoveToLocation(Loc lDestination, int bRun)
{
    vm::impl::push_int(bRun);
    vm::impl::push_loc(lDestination);
    vm::impl::call_builtin(21);
}

void ActionMoveToObject(OID oMoveTo, int bRun, float fRange)
{
    vm::impl::push_float(fRange);
    vm::impl::push_int(bRun);
    vm::impl::push_oid(oMoveTo);
    vm::impl::call_builtin(22);
}

void ActionMoveAwayFromObject(OID oFleeFrom, int bRun, float fMoveAwayRange)
{
    vm::impl::push_float(fMoveAwayRange);
    vm::impl::push_int(bRun);
    vm::impl::push_oid(oFleeFrom);
    vm::impl::call_builtin(23);
}

OID GetArea(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(24);
    return vm::impl::pop_oid();
}

OID GetEnteringObject()
{
    vm::impl::call_builtin(25);
    return vm::impl::pop_oid();
}

OID GetExitingObject()
{
    vm::impl::call_builtin(26);
    return vm::impl::pop_oid();
}

Vec3 GetPosition(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(27);
    return vm::impl::pop_vec();
}

float GetFacing(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(28);
    return vm::impl::pop_float();
}

OID GetItemPossessor(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(29);
    return vm::impl::pop_oid();
}

OID GetItemPossessedBy(OID oCreature, CExoString sItemTag)
{
    vm::impl::push_string(sItemTag);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(30);
    return vm::impl::pop_oid();
}

OID CreateItemOnObject(CExoString sItemTemplate, OID oTarget, int nStackSize, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_int(nStackSize);
    vm::impl::push_oid(oTarget);
    vm::impl::push_string(sItemTemplate);
    vm::impl::call_builtin(31);
    return vm::impl::pop_oid();
}

void ActionEquipItem(OID oItem, int nInventorySlot)
{
    vm::impl::push_int(nInventorySlot);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(32);
}

void ActionUnequipItem(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(33);
}

void ActionPickUpItem(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(34);
}

void ActionPutDownItem(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(35);
}

OID GetLastAttacker(OID oAttackee)
{
    vm::impl::push_oid(oAttackee);
    vm::impl::call_builtin(36);
    return vm::impl::pop_oid();
}

void ActionAttack(OID oAttackee, int bPassive)
{
    vm::impl::push_int(bPassive);
    vm::impl::push_oid(oAttackee);
    vm::impl::call_builtin(37);
}

OID GetNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, OID oTarget, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue)
{
    vm::impl::push_int(nThirdCriteriaValue);
    vm::impl::push_int(nThirdCriteriaType);
    vm::impl::push_int(nSecondCriteriaValue);
    vm::impl::push_int(nSecondCriteriaType);
    vm::impl::push_int(nNth);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nFirstCriteriaValue);
    vm::impl::push_int(nFirstCriteriaType);
    vm::impl::call_builtin(38);
    return vm::impl::pop_oid();
}

void ActionSpeakString(CExoString sStringToSpeak, int nTalkVolume)
{
    vm::impl::push_int(nTalkVolume);
    vm::impl::push_string(sStringToSpeak);
    vm::impl::call_builtin(39);
}

void ActionPlayAnimation(int nAnimation, float fSpeed, float fDurationSeconds)
{
    vm::impl::push_float(fDurationSeconds);
    vm::impl::push_float(fSpeed);
    vm::impl::push_int(nAnimation);
    vm::impl::call_builtin(40);
}

float GetDistanceToObject(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(41);
    return vm::impl::pop_float();
}

int GetIsObjectValid(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(42);
    return vm::impl::pop_int();
}

void ActionOpenDoor(OID oDoor)
{
    vm::impl::push_oid(oDoor);
    vm::impl::call_builtin(43);
}

void ActionCloseDoor(OID oDoor)
{
    vm::impl::push_oid(oDoor);
    vm::impl::call_builtin(44);
}

void SetCameraFacing(float fDirection, float fDistance, float fPitch, int nTransitionType)
{
    vm::impl::push_int(nTransitionType);
    vm::impl::push_float(fPitch);
    vm::impl::push_float(fDistance);
    vm::impl::push_float(fDirection);
    vm::impl::call_builtin(45);
}

void PlaySound(CExoString sSoundName)
{
    vm::impl::push_string(sSoundName);
    vm::impl::call_builtin(46);
}

OID GetSpellTargetObject()
{
    vm::impl::call_builtin(47);
    return vm::impl::pop_oid();
}

void ActionCastSpellAtObject(int nSpell, OID oTarget, int nMetaMagic, int bCheat, int nDomainLevel, int nProjectilePathType, int bInstantSpell)
{
    vm::impl::push_int(bInstantSpell);
    vm::impl::push_int(nProjectilePathType);
    vm::impl::push_int(nDomainLevel);
    vm::impl::push_int(bCheat);
    vm::impl::push_int(nMetaMagic);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(48);
}

int GetCurrentHitPoints(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(49);
    return vm::impl::pop_int();
}

int GetMaxHitPoints(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(50);
    return vm::impl::pop_int();
}

int GetLocalInt(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(51);
    return vm::impl::pop_int();
}

float GetLocalFloat(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(52);
    return vm::impl::pop_float();
}

CExoString GetLocalString(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(53);
    return vm::impl::pop_string();
}

OID GetLocalObject(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(54);
    return vm::impl::pop_oid();
}

void SetLocalInt(OID oObject, CExoString sVarName, int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(55);
}

void SetLocalFloat(OID oObject, CExoString sVarName, float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(56);
}

void SetLocalString(OID oObject, CExoString sVarName, CExoString sValue)
{
    vm::impl::push_string(sValue);
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(57);
}

void SetLocalObject(OID oObject, CExoString sVarName, OID oValue)
{
    vm::impl::push_oid(oValue);
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(58);
}

int GetStringLength(CExoString sString)
{
    vm::impl::push_string(sString);
    vm::impl::call_builtin(59);
    return vm::impl::pop_int();
}

CExoString GetStringUpperCase(CExoString sString)
{
    vm::impl::push_string(sString);
    vm::impl::call_builtin(60);
    return vm::impl::pop_string();
}

CExoString GetStringLowerCase(CExoString sString)
{
    vm::impl::push_string(sString);
    vm::impl::call_builtin(61);
    return vm::impl::pop_string();
}

CExoString GetStringRight(CExoString sString, int nCount)
{
    vm::impl::push_int(nCount);
    vm::impl::push_string(sString);
    vm::impl::call_builtin(62);
    return vm::impl::pop_string();
}

CExoString GetStringLeft(CExoString sString, int nCount)
{
    vm::impl::push_int(nCount);
    vm::impl::push_string(sString);
    vm::impl::call_builtin(63);
    return vm::impl::pop_string();
}

CExoString InsertString(CExoString sDestination, CExoString sString, int nPosition)
{
    vm::impl::push_int(nPosition);
    vm::impl::push_string(sString);
    vm::impl::push_string(sDestination);
    vm::impl::call_builtin(64);
    return vm::impl::pop_string();
}

CExoString GetSubString(CExoString sString, int nStart, int nCount)
{
    vm::impl::push_int(nCount);
    vm::impl::push_int(nStart);
    vm::impl::push_string(sString);
    vm::impl::call_builtin(65);
    return vm::impl::pop_string();
}

int FindSubString(CExoString sString, CExoString sSubString, int nStart)
{
    vm::impl::push_int(nStart);
    vm::impl::push_string(sSubString);
    vm::impl::push_string(sString);
    vm::impl::call_builtin(66);
    return vm::impl::pop_int();
}

float fabs(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(67);
    return vm::impl::pop_float();
}

float cos(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(68);
    return vm::impl::pop_float();
}

float sin(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(69);
    return vm::impl::pop_float();
}

float tan(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(70);
    return vm::impl::pop_float();
}

float acos(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(71);
    return vm::impl::pop_float();
}

float asin(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(72);
    return vm::impl::pop_float();
}

float atan(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(73);
    return vm::impl::pop_float();
}

float log(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(74);
    return vm::impl::pop_float();
}

float pow(float fValue, float fExponent)
{
    vm::impl::push_float(fExponent);
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(75);
    return vm::impl::pop_float();
}

float sqrt(float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::call_builtin(76);
    return vm::impl::pop_float();
}

int abs(int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::call_builtin(77);
    return vm::impl::pop_int();
}

Effect EffectHeal(int nDamageToHeal)
{
    vm::impl::push_int(nDamageToHeal);
    vm::impl::call_builtin(78);
    return vm::impl::pop_effect();
}

Effect EffectDamage(int nDamageAmount, int nDamageType, int nDamagePower)
{
    vm::impl::push_int(nDamagePower);
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nDamageAmount);
    vm::impl::call_builtin(79);
    return vm::impl::pop_effect();
}

Effect EffectAbilityIncrease(int nAbilityToIncrease, int nModifyBy)
{
    vm::impl::push_int(nModifyBy);
    vm::impl::push_int(nAbilityToIncrease);
    vm::impl::call_builtin(80);
    return vm::impl::pop_effect();
}

Effect EffectDamageResistance(int nDamageType, int nAmount, int nLimit)
{
    vm::impl::push_int(nLimit);
    vm::impl::push_int(nAmount);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(81);
    return vm::impl::pop_effect();
}

Effect EffectResurrection()
{
    vm::impl::call_builtin(82);
    return vm::impl::pop_effect();
}

Effect EffectSummonCreature(CExoString sCreatureResref, int nVisualEffectId, float fDelaySeconds, int nUseAppearAnimation)
{
    vm::impl::push_int(nUseAppearAnimation);
    vm::impl::push_float(fDelaySeconds);
    vm::impl::push_int(nVisualEffectId);
    vm::impl::push_string(sCreatureResref);
    vm::impl::call_builtin(83);
    return vm::impl::pop_effect();
}

int GetCasterLevel(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(84);
    return vm::impl::pop_int();
}

Effect GetFirstEffect(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(85);
    return vm::impl::pop_effect();
}

Effect GetNextEffect(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(86);
    return vm::impl::pop_effect();
}

void RemoveEffect(OID oCreature, Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(87);
}

int GetIsEffectValid(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(88);
    return vm::impl::pop_int();
}

int GetEffectDurationType(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(89);
    return vm::impl::pop_int();
}

int GetEffectSubType(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(90);
    return vm::impl::pop_int();
}

OID GetEffectCreator(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(91);
    return vm::impl::pop_oid();
}

CExoString IntToString(int nInteger)
{
    vm::impl::push_int(nInteger);
    vm::impl::call_builtin(92);
    return vm::impl::pop_string();
}

OID GetFirstObjectInArea(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(93);
    return vm::impl::pop_oid();
}

OID GetNextObjectInArea(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(94);
    return vm::impl::pop_oid();
}

int d2(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(95);
    return vm::impl::pop_int();
}

int d3(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(96);
    return vm::impl::pop_int();
}

int d4(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(97);
    return vm::impl::pop_int();
}

int d6(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(98);
    return vm::impl::pop_int();
}

int d8(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(99);
    return vm::impl::pop_int();
}

int d10(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(100);
    return vm::impl::pop_int();
}

int d12(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(101);
    return vm::impl::pop_int();
}

int d20(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(102);
    return vm::impl::pop_int();
}

int d100(int nNumDice)
{
    vm::impl::push_int(nNumDice);
    vm::impl::call_builtin(103);
    return vm::impl::pop_int();
}

float VectorMagnitude(Vec3 vVector)
{
    vm::impl::push_vec(vVector);
    vm::impl::call_builtin(104);
    return vm::impl::pop_float();
}

int GetMetaMagicFeat()
{
    vm::impl::call_builtin(105);
    return vm::impl::pop_int();
}

int GetObjectType(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(106);
    return vm::impl::pop_int();
}

int GetRacialType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(107);
    return vm::impl::pop_int();
}

int FortitudeSave(OID oCreature, int nDC, int nSaveType, OID oSaveVersus)
{
    vm::impl::push_oid(oSaveVersus);
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nDC);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(108);
    return vm::impl::pop_int();
}

int ReflexSave(OID oCreature, int nDC, int nSaveType, OID oSaveVersus)
{
    vm::impl::push_oid(oSaveVersus);
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nDC);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(109);
    return vm::impl::pop_int();
}

int WillSave(OID oCreature, int nDC, int nSaveType, OID oSaveVersus)
{
    vm::impl::push_oid(oSaveVersus);
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nDC);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(110);
    return vm::impl::pop_int();
}

int GetSpellSaveDC()
{
    vm::impl::call_builtin(111);
    return vm::impl::pop_int();
}

Effect MagicalEffect(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(112);
    return vm::impl::pop_effect();
}

Effect SupernaturalEffect(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(113);
    return vm::impl::pop_effect();
}

Effect ExtraordinaryEffect(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(114);
    return vm::impl::pop_effect();
}

Effect EffectACIncrease(int nValue, int nModifyType, int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nModifyType);
    vm::impl::push_int(nValue);
    vm::impl::call_builtin(115);
    return vm::impl::pop_effect();
}

int GetAC(OID oObject, int nForFutureUse)
{
    vm::impl::push_int(nForFutureUse);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(116);
    return vm::impl::pop_int();
}

Effect EffectSavingThrowIncrease(int nSave, int nValue, int nSaveType)
{
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nValue);
    vm::impl::push_int(nSave);
    vm::impl::call_builtin(117);
    return vm::impl::pop_effect();
}

Effect EffectAttackIncrease(int nBonus, int nModifierType)
{
    vm::impl::push_int(nModifierType);
    vm::impl::push_int(nBonus);
    vm::impl::call_builtin(118);
    return vm::impl::pop_effect();
}

Effect EffectDamageReduction(int nAmount, int nDamagePower, int nLimit)
{
    vm::impl::push_int(nLimit);
    vm::impl::push_int(nDamagePower);
    vm::impl::push_int(nAmount);
    vm::impl::call_builtin(119);
    return vm::impl::pop_effect();
}

Effect EffectDamageIncrease(int nBonus, int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nBonus);
    vm::impl::call_builtin(120);
    return vm::impl::pop_effect();
}

float RoundsToSeconds(int nRounds)
{
    vm::impl::push_int(nRounds);
    vm::impl::call_builtin(121);
    return vm::impl::pop_float();
}

float HoursToSeconds(int nHours)
{
    vm::impl::push_int(nHours);
    vm::impl::call_builtin(122);
    return vm::impl::pop_float();
}

float TurnsToSeconds(int nTurns)
{
    vm::impl::push_int(nTurns);
    vm::impl::call_builtin(123);
    return vm::impl::pop_float();
}

int GetLawChaosValue(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(124);
    return vm::impl::pop_int();
}

int GetGoodEvilValue(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(125);
    return vm::impl::pop_int();
}

int GetAlignmentLawChaos(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(126);
    return vm::impl::pop_int();
}

int GetAlignmentGoodEvil(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(127);
    return vm::impl::pop_int();
}

OID GetFirstObjectInShape(int nShape, float fSize, Loc lTarget, int bLineOfSight, int nObjectFilter, Vec3 vOrigin)
{
    vm::impl::push_vec(vOrigin);
    vm::impl::push_int(nObjectFilter);
    vm::impl::push_int(bLineOfSight);
    vm::impl::push_loc(lTarget);
    vm::impl::push_float(fSize);
    vm::impl::push_int(nShape);
    vm::impl::call_builtin(128);
    return vm::impl::pop_oid();
}

OID GetNextObjectInShape(int nShape, float fSize, Loc lTarget, int bLineOfSight, int nObjectFilter, Vec3 vOrigin)
{
    vm::impl::push_vec(vOrigin);
    vm::impl::push_int(nObjectFilter);
    vm::impl::push_int(bLineOfSight);
    vm::impl::push_loc(lTarget);
    vm::impl::push_float(fSize);
    vm::impl::push_int(nShape);
    vm::impl::call_builtin(129);
    return vm::impl::pop_oid();
}

Effect EffectEntangle()
{
    vm::impl::call_builtin(130);
    return vm::impl::pop_effect();
}

void SignalEvent(OID oObject, Event evToRun)
{
    vm::impl::push_event(evToRun);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(131);
}

Event EventUserDefined(int nUserDefinedEventNumber)
{
    vm::impl::push_int(nUserDefinedEventNumber);
    vm::impl::call_builtin(132);
    return vm::impl::pop_event();
}

Effect EffectDeath(int nSpectacularDeath, int nDisplayFeedback)
{
    vm::impl::push_int(nDisplayFeedback);
    vm::impl::push_int(nSpectacularDeath);
    vm::impl::call_builtin(133);
    return vm::impl::pop_effect();
}

Effect EffectKnockdown()
{
    vm::impl::call_builtin(134);
    return vm::impl::pop_effect();
}

void ActionGiveItem(OID oItem, OID oGiveTo)
{
    vm::impl::push_oid(oGiveTo);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(135);
}

void ActionTakeItem(OID oItem, OID oTakeFrom)
{
    vm::impl::push_oid(oTakeFrom);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(136);
}

Vec3 VectorNormalize(Vec3 vVector)
{
    vm::impl::push_vec(vVector);
    vm::impl::call_builtin(137);
    return vm::impl::pop_vec();
}

Effect EffectCurse(int nStrMod, int nDexMod, int nConMod, int nIntMod, int nWisMod, int nChaMod)
{
    vm::impl::push_int(nChaMod);
    vm::impl::push_int(nWisMod);
    vm::impl::push_int(nIntMod);
    vm::impl::push_int(nConMod);
    vm::impl::push_int(nDexMod);
    vm::impl::push_int(nStrMod);
    vm::impl::call_builtin(138);
    return vm::impl::pop_effect();
}

int GetAbilityScore(OID oCreature, int nAbilityType, int nBaseAbilityScore)
{
    vm::impl::push_int(nBaseAbilityScore);
    vm::impl::push_int(nAbilityType);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(139);
    return vm::impl::pop_int();
}

int GetIsDead(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(140);
    return vm::impl::pop_int();
}

void PrintVector(Vec3 vVector, int bPrepend)
{
    vm::impl::push_int(bPrepend);
    vm::impl::push_vec(vVector);
    vm::impl::call_builtin(141);
}

Vec3 Vector(float x, float y, float z)
{
    vm::impl::push_float(z);
    vm::impl::push_float(y);
    vm::impl::push_float(x);
    vm::impl::call_builtin(142);
    return vm::impl::pop_vec();
}

void SetFacingPoint(Vec3 vTarget)
{
    vm::impl::push_vec(vTarget);
    vm::impl::call_builtin(143);
}

Vec3 AngleToVector(float fAngle)
{
    vm::impl::push_float(fAngle);
    vm::impl::call_builtin(144);
    return vm::impl::pop_vec();
}

float VectorToAngle(Vec3 vVector)
{
    vm::impl::push_vec(vVector);
    vm::impl::call_builtin(145);
    return vm::impl::pop_float();
}

int TouchAttackMelee(OID oTarget, int bDisplayFeedback)
{
    vm::impl::push_int(bDisplayFeedback);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(146);
    return vm::impl::pop_int();
}

int TouchAttackRanged(OID oTarget, int bDisplayFeedback)
{
    vm::impl::push_int(bDisplayFeedback);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(147);
    return vm::impl::pop_int();
}

Effect EffectParalyze()
{
    vm::impl::call_builtin(148);
    return vm::impl::pop_effect();
}

Effect EffectSpellImmunity(int nImmunityToSpell)
{
    vm::impl::push_int(nImmunityToSpell);
    vm::impl::call_builtin(149);
    return vm::impl::pop_effect();
}

Effect EffectDeaf()
{
    vm::impl::call_builtin(150);
    return vm::impl::pop_effect();
}

float GetDistanceBetween(OID oObjectA, OID oObjectB)
{
    vm::impl::push_oid(oObjectB);
    vm::impl::push_oid(oObjectA);
    vm::impl::call_builtin(151);
    return vm::impl::pop_float();
}

void SetLocalLocation(OID oObject, CExoString sVarName, Loc lValue)
{
    vm::impl::push_loc(lValue);
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(152);
}

Loc GetLocalLocation(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(153);
    return vm::impl::pop_loc();
}

Effect EffectSleep()
{
    vm::impl::call_builtin(154);
    return vm::impl::pop_effect();
}

OID GetItemInSlot(int nInventorySlot, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nInventorySlot);
    vm::impl::call_builtin(155);
    return vm::impl::pop_oid();
}

Effect EffectCharmed()
{
    vm::impl::call_builtin(156);
    return vm::impl::pop_effect();
}

Effect EffectConfused()
{
    vm::impl::call_builtin(157);
    return vm::impl::pop_effect();
}

Effect EffectFrightened()
{
    vm::impl::call_builtin(158);
    return vm::impl::pop_effect();
}

Effect EffectDominated()
{
    vm::impl::call_builtin(159);
    return vm::impl::pop_effect();
}

Effect EffectDazed()
{
    vm::impl::call_builtin(160);
    return vm::impl::pop_effect();
}

Effect EffectStunned()
{
    vm::impl::call_builtin(161);
    return vm::impl::pop_effect();
}

void SetCommandable(int bCommandable, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(bCommandable);
    vm::impl::call_builtin(162);
}

int GetCommandable(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(163);
    return vm::impl::pop_int();
}

Effect EffectRegenerate(int nAmount, float fIntervalSeconds)
{
    vm::impl::push_float(fIntervalSeconds);
    vm::impl::push_int(nAmount);
    vm::impl::call_builtin(164);
    return vm::impl::pop_effect();
}

Effect EffectMovementSpeedIncrease(int nPercentChange)
{
    vm::impl::push_int(nPercentChange);
    vm::impl::call_builtin(165);
    return vm::impl::pop_effect();
}

int GetHitDice(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(166);
    return vm::impl::pop_int();
}

void ActionForceFollowObject(OID oFollow, float fFollowDistance)
{
    vm::impl::push_float(fFollowDistance);
    vm::impl::push_oid(oFollow);
    vm::impl::call_builtin(167);
}

CExoString GetTag(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(168);
    return vm::impl::pop_string();
}

int ResistSpell(OID oCaster, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oCaster);
    vm::impl::call_builtin(169);
    return vm::impl::pop_int();
}

int GetEffectType(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(170);
    return vm::impl::pop_int();
}

Effect EffectAreaOfEffect(int nAreaEffectId, CExoString sOnEnterScript, CExoString sHeartbeatScript, CExoString sOnExitScript)
{
    vm::impl::push_string(sOnExitScript);
    vm::impl::push_string(sHeartbeatScript);
    vm::impl::push_string(sOnEnterScript);
    vm::impl::push_int(nAreaEffectId);
    vm::impl::call_builtin(171);
    return vm::impl::pop_effect();
}

int GetFactionEqual(OID oFirstObject, OID oSecondObject)
{
    vm::impl::push_oid(oSecondObject);
    vm::impl::push_oid(oFirstObject);
    vm::impl::call_builtin(172);
    return vm::impl::pop_int();
}

void ChangeFaction(OID oObjectToChangeFaction, OID oMemberOfFactionToJoin)
{
    vm::impl::push_oid(oMemberOfFactionToJoin);
    vm::impl::push_oid(oObjectToChangeFaction);
    vm::impl::call_builtin(173);
}

int GetIsListening(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(174);
    return vm::impl::pop_int();
}

void SetListening(OID oObject, int bValue)
{
    vm::impl::push_int(bValue);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(175);
}

void SetListenPattern(OID oObject, CExoString sPattern, int nNumber)
{
    vm::impl::push_int(nNumber);
    vm::impl::push_string(sPattern);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(176);
}

int TestStringAgainstPattern(CExoString sPattern, CExoString sStringToTest)
{
    vm::impl::push_string(sStringToTest);
    vm::impl::push_string(sPattern);
    vm::impl::call_builtin(177);
    return vm::impl::pop_int();
}

CExoString GetMatchedSubstring(int nString)
{
    vm::impl::push_int(nString);
    vm::impl::call_builtin(178);
    return vm::impl::pop_string();
}

int GetMatchedSubstringsCount()
{
    vm::impl::call_builtin(179);
    return vm::impl::pop_int();
}

Effect EffectVisualEffect(int nVisualEffectId, int nMissEffect)
{
    vm::impl::push_int(nMissEffect);
    vm::impl::push_int(nVisualEffectId);
    vm::impl::call_builtin(180);
    return vm::impl::pop_effect();
}

OID GetFactionWeakestMember(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(181);
    return vm::impl::pop_oid();
}

OID GetFactionStrongestMember(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(182);
    return vm::impl::pop_oid();
}

OID GetFactionMostDamagedMember(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(183);
    return vm::impl::pop_oid();
}

OID GetFactionLeastDamagedMember(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(184);
    return vm::impl::pop_oid();
}

int GetFactionGold(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(185);
    return vm::impl::pop_int();
}

int GetFactionAverageReputation(OID oSourceFactionMember, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oSourceFactionMember);
    vm::impl::call_builtin(186);
    return vm::impl::pop_int();
}

int GetFactionAverageGoodEvilAlignment(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(187);
    return vm::impl::pop_int();
}

int GetFactionAverageLawChaosAlignment(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(188);
    return vm::impl::pop_int();
}

int GetFactionAverageLevel(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(189);
    return vm::impl::pop_int();
}

int GetFactionAverageXP(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(190);
    return vm::impl::pop_int();
}

int GetFactionMostFrequentClass(OID oFactionMember)
{
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(191);
    return vm::impl::pop_int();
}

OID GetFactionWorstAC(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(192);
    return vm::impl::pop_oid();
}

OID GetFactionBestAC(OID oFactionMember, int bMustBeVisible)
{
    vm::impl::push_int(bMustBeVisible);
    vm::impl::push_oid(oFactionMember);
    vm::impl::call_builtin(193);
    return vm::impl::pop_oid();
}

void ActionSit(OID oChair)
{
    vm::impl::push_oid(oChair);
    vm::impl::call_builtin(194);
}

int GetListenPatternNumber()
{
    vm::impl::call_builtin(195);
    return vm::impl::pop_int();
}

void ActionJumpToObject(OID oToJumpTo, int bWalkStraightLineToPoint)
{
    vm::impl::push_int(bWalkStraightLineToPoint);
    vm::impl::push_oid(oToJumpTo);
    vm::impl::call_builtin(196);
}

OID GetWaypointByTag(CExoString sWaypointTag)
{
    vm::impl::push_string(sWaypointTag);
    vm::impl::call_builtin(197);
    return vm::impl::pop_oid();
}

OID GetTransitionTarget(OID oTransition)
{
    vm::impl::push_oid(oTransition);
    vm::impl::call_builtin(198);
    return vm::impl::pop_oid();
}

Effect EffectLinkEffects(Effect eChildEffect, Effect eParentEffect)
{
    vm::impl::push_effect(eParentEffect);
    vm::impl::push_effect(eChildEffect);
    vm::impl::call_builtin(199);
    return vm::impl::pop_effect();
}

OID GetObjectByTag(CExoString sTag, int nNth)
{
    vm::impl::push_int(nNth);
    vm::impl::push_string(sTag);
    vm::impl::call_builtin(200);
    return vm::impl::pop_oid();
}

void AdjustAlignment(OID oSubject, int nAlignment, int nShift, int bAllPartyMembers)
{
    vm::impl::push_int(bAllPartyMembers);
    vm::impl::push_int(nShift);
    vm::impl::push_int(nAlignment);
    vm::impl::push_oid(oSubject);
    vm::impl::call_builtin(201);
}

void ActionWait(float fSeconds)
{
    vm::impl::push_float(fSeconds);
    vm::impl::call_builtin(202);
}

void SetAreaTransitionBMP(int nPredefinedAreaTransition, CExoString sCustomAreaTransitionBMP)
{
    vm::impl::push_string(sCustomAreaTransitionBMP);
    vm::impl::push_int(nPredefinedAreaTransition);
    vm::impl::call_builtin(203);
}

void ActionStartConversation(OID oObjectToConverseWith, CExoString sDialogResRef, int bPrivateConversation, int bPlayHello)
{
    vm::impl::push_int(bPlayHello);
    vm::impl::push_int(bPrivateConversation);
    vm::impl::push_string(sDialogResRef);
    vm::impl::push_oid(oObjectToConverseWith);
    vm::impl::call_builtin(204);
}

void ActionPauseConversation()
{
    vm::impl::call_builtin(205);
}

void ActionResumeConversation()
{
    vm::impl::call_builtin(206);
}

Effect EffectBeam(int nBeamVisualEffect, OID oEffector, int nBodyPart, int bMissEffect)
{
    vm::impl::push_int(bMissEffect);
    vm::impl::push_int(nBodyPart);
    vm::impl::push_oid(oEffector);
    vm::impl::push_int(nBeamVisualEffect);
    vm::impl::call_builtin(207);
    return vm::impl::pop_effect();
}

int GetReputation(OID oSource, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oSource);
    vm::impl::call_builtin(208);
    return vm::impl::pop_int();
}

void AdjustReputation(OID oTarget, OID oSourceFactionMember, int nAdjustment)
{
    vm::impl::push_int(nAdjustment);
    vm::impl::push_oid(oSourceFactionMember);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(209);
}

OID GetSittingCreature(OID oChair)
{
    vm::impl::push_oid(oChair);
    vm::impl::call_builtin(210);
    return vm::impl::pop_oid();
}

OID GetGoingToBeAttackedBy(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(211);
    return vm::impl::pop_oid();
}

Effect EffectSpellResistanceIncrease(int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::call_builtin(212);
    return vm::impl::pop_effect();
}

Loc GetLocation(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(213);
    return vm::impl::pop_loc();
}

void ActionJumpToLocation(Loc lLocation)
{
    vm::impl::push_loc(lLocation);
    vm::impl::call_builtin(214);
}

Loc Location(OID oArea, Vec3 vPosition, float fOrientation)
{
    vm::impl::push_float(fOrientation);
    vm::impl::push_vec(vPosition);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(215);
    return vm::impl::pop_loc();
}

void ApplyEffectAtLocation(int nDurationType, Effect eEffect, Loc lLocation, float fDuration)
{
    vm::impl::push_float(fDuration);
    vm::impl::push_loc(lLocation);
    vm::impl::push_effect(eEffect);
    vm::impl::push_int(nDurationType);
    vm::impl::call_builtin(216);
}

int GetIsPC(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(217);
    return vm::impl::pop_int();
}

float FeetToMeters(float fFeet)
{
    vm::impl::push_float(fFeet);
    vm::impl::call_builtin(218);
    return vm::impl::pop_float();
}

float YardsToMeters(float fYards)
{
    vm::impl::push_float(fYards);
    vm::impl::call_builtin(219);
    return vm::impl::pop_float();
}

void ApplyEffectToObject(int nDurationType, Effect eEffect, OID oTarget, float fDuration)
{
    vm::impl::push_float(fDuration);
    vm::impl::push_oid(oTarget);
    vm::impl::push_effect(eEffect);
    vm::impl::push_int(nDurationType);
    vm::impl::call_builtin(220);
}

void SpeakString(CExoString sStringToSpeak, int nTalkVolume)
{
    vm::impl::push_int(nTalkVolume);
    vm::impl::push_string(sStringToSpeak);
    vm::impl::call_builtin(221);
}

Loc GetSpellTargetLocation()
{
    vm::impl::call_builtin(222);
    return vm::impl::pop_loc();
}

Vec3 GetPositionFromLocation(Loc lLocation)
{
    vm::impl::push_loc(lLocation);
    vm::impl::call_builtin(223);
    return vm::impl::pop_vec();
}

OID GetAreaFromLocation(Loc lLocation)
{
    vm::impl::push_loc(lLocation);
    vm::impl::call_builtin(224);
    return vm::impl::pop_oid();
}

float GetFacingFromLocation(Loc lLocation)
{
    vm::impl::push_loc(lLocation);
    vm::impl::call_builtin(225);
    return vm::impl::pop_float();
}

OID GetNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, Loc lLocation, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue)
{
    vm::impl::push_int(nThirdCriteriaValue);
    vm::impl::push_int(nThirdCriteriaType);
    vm::impl::push_int(nSecondCriteriaValue);
    vm::impl::push_int(nSecondCriteriaType);
    vm::impl::push_int(nNth);
    vm::impl::push_loc(lLocation);
    vm::impl::push_int(nFirstCriteriaValue);
    vm::impl::push_int(nFirstCriteriaType);
    vm::impl::call_builtin(226);
    return vm::impl::pop_oid();
}

OID GetNearestObject(int nObjectType, OID oTarget, int nNth)
{
    vm::impl::push_int(nNth);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nObjectType);
    vm::impl::call_builtin(227);
    return vm::impl::pop_oid();
}

OID GetNearestObjectToLocation(int nObjectType, Loc lLocation, int nNth)
{
    vm::impl::push_int(nNth);
    vm::impl::push_loc(lLocation);
    vm::impl::push_int(nObjectType);
    vm::impl::call_builtin(228);
    return vm::impl::pop_oid();
}

OID GetNearestObjectByTag(CExoString sTag, OID oTarget, int nNth)
{
    vm::impl::push_int(nNth);
    vm::impl::push_oid(oTarget);
    vm::impl::push_string(sTag);
    vm::impl::call_builtin(229);
    return vm::impl::pop_oid();
}

float IntToFloat(int nInteger)
{
    vm::impl::push_int(nInteger);
    vm::impl::call_builtin(230);
    return vm::impl::pop_float();
}

int FloatToInt(float fFloat)
{
    vm::impl::push_float(fFloat);
    vm::impl::call_builtin(231);
    return vm::impl::pop_int();
}

int StringToInt(CExoString sNumber)
{
    vm::impl::push_string(sNumber);
    vm::impl::call_builtin(232);
    return vm::impl::pop_int();
}

float StringToFloat(CExoString sNumber)
{
    vm::impl::push_string(sNumber);
    vm::impl::call_builtin(233);
    return vm::impl::pop_float();
}

void ActionCastSpellAtLocation(int nSpell, Loc lTargetLocation, int nMetaMagic, int bCheat, int nProjectilePathType, int bInstantSpell)
{
    vm::impl::push_int(bInstantSpell);
    vm::impl::push_int(nProjectilePathType);
    vm::impl::push_int(bCheat);
    vm::impl::push_int(nMetaMagic);
    vm::impl::push_loc(lTargetLocation);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(234);
}

int GetIsEnemy(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(235);
    return vm::impl::pop_int();
}

int GetIsFriend(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(236);
    return vm::impl::pop_int();
}

int GetIsNeutral(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(237);
    return vm::impl::pop_int();
}

OID GetPCSpeaker()
{
    vm::impl::call_builtin(238);
    return vm::impl::pop_oid();
}

CExoString GetStringByStrRef(int nStrRef, int nGender)
{
    vm::impl::push_int(nGender);
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(239);
    return vm::impl::pop_string();
}

void ActionSpeakStringByStrRef(int nStrRef, int nTalkVolume)
{
    vm::impl::push_int(nTalkVolume);
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(240);
}

void DestroyObject(OID oDestroy, float fDelay)
{
    vm::impl::push_float(fDelay);
    vm::impl::push_oid(oDestroy);
    vm::impl::call_builtin(241);
}

OID GetModule()
{
    vm::impl::call_builtin(242);
    return vm::impl::pop_oid();
}

OID CreateObject(int nObjectType, CExoString sTemplate, Loc lLocation, int bUseAppearAnimation, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_int(bUseAppearAnimation);
    vm::impl::push_loc(lLocation);
    vm::impl::push_string(sTemplate);
    vm::impl::push_int(nObjectType);
    vm::impl::call_builtin(243);
    return vm::impl::pop_oid();
}

Event EventSpellCastAt(OID oCaster, int nSpell, int bHarmful)
{
    vm::impl::push_int(bHarmful);
    vm::impl::push_int(nSpell);
    vm::impl::push_oid(oCaster);
    vm::impl::call_builtin(244);
    return vm::impl::pop_event();
}

OID GetLastSpellCaster()
{
    vm::impl::call_builtin(245);
    return vm::impl::pop_oid();
}

int GetLastSpell()
{
    vm::impl::call_builtin(246);
    return vm::impl::pop_int();
}

int GetUserDefinedEventNumber()
{
    vm::impl::call_builtin(247);
    return vm::impl::pop_int();
}

int GetSpellId()
{
    vm::impl::call_builtin(248);
    return vm::impl::pop_int();
}

CExoString RandomName(int nNameType)
{
    vm::impl::push_int(nNameType);
    vm::impl::call_builtin(249);
    return vm::impl::pop_string();
}

Effect EffectPoison(int nPoisonType)
{
    vm::impl::push_int(nPoisonType);
    vm::impl::call_builtin(250);
    return vm::impl::pop_effect();
}

Effect EffectDisease(int nDiseaseType)
{
    vm::impl::push_int(nDiseaseType);
    vm::impl::call_builtin(251);
    return vm::impl::pop_effect();
}

Effect EffectSilence()
{
    vm::impl::call_builtin(252);
    return vm::impl::pop_effect();
}

CExoString GetName(OID oObject, int bOriginalName)
{
    vm::impl::push_int(bOriginalName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(253);
    return vm::impl::pop_string();
}

OID GetLastSpeaker()
{
    vm::impl::call_builtin(254);
    return vm::impl::pop_oid();
}

int BeginConversation(CExoString sResRef, OID oObjectToDialog)
{
    vm::impl::push_oid(oObjectToDialog);
    vm::impl::push_string(sResRef);
    vm::impl::call_builtin(255);
    return vm::impl::pop_int();
}

OID GetLastPerceived()
{
    vm::impl::call_builtin(256);
    return vm::impl::pop_oid();
}

int GetLastPerceptionHeard()
{
    vm::impl::call_builtin(257);
    return vm::impl::pop_int();
}

int GetLastPerceptionInaudible()
{
    vm::impl::call_builtin(258);
    return vm::impl::pop_int();
}

int GetLastPerceptionSeen()
{
    vm::impl::call_builtin(259);
    return vm::impl::pop_int();
}

OID GetLastClosedBy()
{
    vm::impl::call_builtin(260);
    return vm::impl::pop_oid();
}

int GetLastPerceptionVanished()
{
    vm::impl::call_builtin(261);
    return vm::impl::pop_int();
}

OID GetFirstInPersistentObject(OID oPersistentObject, int nResidentObjectType, int nPersistentZone)
{
    vm::impl::push_int(nPersistentZone);
    vm::impl::push_int(nResidentObjectType);
    vm::impl::push_oid(oPersistentObject);
    vm::impl::call_builtin(262);
    return vm::impl::pop_oid();
}

OID GetNextInPersistentObject(OID oPersistentObject, int nResidentObjectType, int nPersistentZone)
{
    vm::impl::push_int(nPersistentZone);
    vm::impl::push_int(nResidentObjectType);
    vm::impl::push_oid(oPersistentObject);
    vm::impl::call_builtin(263);
    return vm::impl::pop_oid();
}

OID GetAreaOfEffectCreator(OID oAreaOfEffectObject)
{
    vm::impl::push_oid(oAreaOfEffectObject);
    vm::impl::call_builtin(264);
    return vm::impl::pop_oid();
}

void DeleteLocalInt(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(265);
}

void DeleteLocalFloat(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(266);
}

void DeleteLocalString(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(267);
}

void DeleteLocalObject(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(268);
}

void DeleteLocalLocation(OID oObject, CExoString sVarName)
{
    vm::impl::push_string(sVarName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(269);
}

Effect EffectHaste()
{
    vm::impl::call_builtin(270);
    return vm::impl::pop_effect();
}

Effect EffectSlow()
{
    vm::impl::call_builtin(271);
    return vm::impl::pop_effect();
}

CExoString ObjectToString(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(272);
    return vm::impl::pop_string();
}

Effect EffectImmunity(int nImmunityType)
{
    vm::impl::push_int(nImmunityType);
    vm::impl::call_builtin(273);
    return vm::impl::pop_effect();
}

int GetIsImmune(OID oCreature, int nImmunityType, OID oVersus)
{
    vm::impl::push_oid(oVersus);
    vm::impl::push_int(nImmunityType);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(274);
    return vm::impl::pop_int();
}

Effect EffectDamageImmunityIncrease(int nDamageType, int nPercentImmunity)
{
    vm::impl::push_int(nPercentImmunity);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(275);
    return vm::impl::pop_effect();
}

int GetEncounterActive(OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::call_builtin(276);
    return vm::impl::pop_int();
}

void SetEncounterActive(int nNewValue, OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::push_int(nNewValue);
    vm::impl::call_builtin(277);
}

int GetEncounterSpawnsMax(OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::call_builtin(278);
    return vm::impl::pop_int();
}

void SetEncounterSpawnsMax(int nNewValue, OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::push_int(nNewValue);
    vm::impl::call_builtin(279);
}

int GetEncounterSpawnsCurrent(OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::call_builtin(280);
    return vm::impl::pop_int();
}

void SetEncounterSpawnsCurrent(int nNewValue, OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::push_int(nNewValue);
    vm::impl::call_builtin(281);
}

OID GetModuleItemAcquired()
{
    vm::impl::call_builtin(282);
    return vm::impl::pop_oid();
}

OID GetModuleItemAcquiredFrom()
{
    vm::impl::call_builtin(283);
    return vm::impl::pop_oid();
}

void SetCustomToken(int nCustomTokenNumber, CExoString sTokenValue)
{
    vm::impl::push_string(sTokenValue);
    vm::impl::push_int(nCustomTokenNumber);
    vm::impl::call_builtin(284);
}

int GetHasFeat(int nFeat, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nFeat);
    vm::impl::call_builtin(285);
    return vm::impl::pop_int();
}

int GetHasSkill(int nSkill, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(286);
    return vm::impl::pop_int();
}

void ActionUseFeat(int nFeat, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nFeat);
    vm::impl::call_builtin(287);
}

void ActionUseSkill(int nSkill, OID oTarget, int nSubSkill, OID oItemUsed)
{
    vm::impl::push_oid(oItemUsed);
    vm::impl::push_int(nSubSkill);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(288);
}

int GetObjectSeen(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(289);
    return vm::impl::pop_int();
}

int GetObjectHeard(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(290);
    return vm::impl::pop_int();
}

OID GetLastPlayerDied()
{
    vm::impl::call_builtin(291);
    return vm::impl::pop_oid();
}

OID GetModuleItemLost()
{
    vm::impl::call_builtin(292);
    return vm::impl::pop_oid();
}

OID GetModuleItemLostBy()
{
    vm::impl::call_builtin(293);
    return vm::impl::pop_oid();
}

Event EventConversation()
{
    vm::impl::call_builtin(295);
    return vm::impl::pop_event();
}

void SetEncounterDifficulty(int nEncounterDifficulty, OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::push_int(nEncounterDifficulty);
    vm::impl::call_builtin(296);
}

int GetEncounterDifficulty(OID oEncounter)
{
    vm::impl::push_oid(oEncounter);
    vm::impl::call_builtin(297);
    return vm::impl::pop_int();
}

float GetDistanceBetweenLocations(Loc lLocationA, Loc lLocationB)
{
    vm::impl::push_loc(lLocationB);
    vm::impl::push_loc(lLocationA);
    vm::impl::call_builtin(298);
    return vm::impl::pop_float();
}

int GetReflexAdjustedDamage(int nDamage, OID oTarget, int nDC, int nSaveType, OID oSaveVersus)
{
    vm::impl::push_oid(oSaveVersus);
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nDC);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nDamage);
    vm::impl::call_builtin(299);
    return vm::impl::pop_int();
}

void PlayAnimation(int nAnimation, float fSpeed, float fSeconds)
{
    vm::impl::push_float(fSeconds);
    vm::impl::push_float(fSpeed);
    vm::impl::push_int(nAnimation);
    vm::impl::call_builtin(300);
}

Talent TalentSpell(int nSpell)
{
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(301);
    return vm::impl::pop_talent();
}

Talent TalentFeat(int nFeat)
{
    vm::impl::push_int(nFeat);
    vm::impl::call_builtin(302);
    return vm::impl::pop_talent();
}

Talent TalentSkill(int nSkill)
{
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(303);
    return vm::impl::pop_talent();
}

int GetHasSpellEffect(int nSpell, OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(304);
    return vm::impl::pop_int();
}

int GetEffectSpellId(Effect eSpellEffect)
{
    vm::impl::push_effect(eSpellEffect);
    vm::impl::call_builtin(305);
    return vm::impl::pop_int();
}

int GetCreatureHasTalent(Talent tTalent, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_talent(tTalent);
    vm::impl::call_builtin(306);
    return vm::impl::pop_int();
}

Talent GetCreatureTalentRandom(int nCategory, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nCategory);
    vm::impl::call_builtin(307);
    return vm::impl::pop_talent();
}

Talent GetCreatureTalentBest(int nCategory, int nCRMax, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nCRMax);
    vm::impl::push_int(nCategory);
    vm::impl::call_builtin(308);
    return vm::impl::pop_talent();
}

void ActionUseTalentOnObject(Talent tChosenTalent, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_talent(tChosenTalent);
    vm::impl::call_builtin(309);
}

void ActionUseTalentAtLocation(Talent tChosenTalent, Loc lTargetLocation)
{
    vm::impl::push_loc(lTargetLocation);
    vm::impl::push_talent(tChosenTalent);
    vm::impl::call_builtin(310);
}

int GetGoldPieceValue(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(311);
    return vm::impl::pop_int();
}

int GetIsPlayableRacialType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(312);
    return vm::impl::pop_int();
}

void JumpToLocation(Loc lDestination)
{
    vm::impl::push_loc(lDestination);
    vm::impl::call_builtin(313);
}

Effect EffectTemporaryHitpoints(int nHitPoints)
{
    vm::impl::push_int(nHitPoints);
    vm::impl::call_builtin(314);
    return vm::impl::pop_effect();
}

int GetSkillRank(int nSkill, OID oTarget, int nBaseSkillRank)
{
    vm::impl::push_int(nBaseSkillRank);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(315);
    return vm::impl::pop_int();
}

OID GetAttackTarget(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(316);
    return vm::impl::pop_oid();
}

int GetLastAttackType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(317);
    return vm::impl::pop_int();
}

int GetLastAttackMode(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(318);
    return vm::impl::pop_int();
}

OID GetMaster(OID oAssociate)
{
    vm::impl::push_oid(oAssociate);
    vm::impl::call_builtin(319);
    return vm::impl::pop_oid();
}

int GetIsInCombat(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(320);
    return vm::impl::pop_int();
}

int GetLastAssociateCommand(OID oAssociate)
{
    vm::impl::push_oid(oAssociate);
    vm::impl::call_builtin(321);
    return vm::impl::pop_int();
}

void GiveGoldToCreature(OID oCreature, int nGP)
{
    vm::impl::push_int(nGP);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(322);
}

void SetIsDestroyable(int bDestroyable, int bRaiseable, int bSelectableWhenDead)
{
    vm::impl::push_int(bSelectableWhenDead);
    vm::impl::push_int(bRaiseable);
    vm::impl::push_int(bDestroyable);
    vm::impl::call_builtin(323);
}

void SetLocked(OID oTarget, int bLocked)
{
    vm::impl::push_int(bLocked);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(324);
}

int GetLocked(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(325);
    return vm::impl::pop_int();
}

OID GetClickingObject()
{
    vm::impl::call_builtin(326);
    return vm::impl::pop_oid();
}

void SetAssociateListenPatterns(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(327);
}

OID GetLastWeaponUsed(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(328);
    return vm::impl::pop_oid();
}

void ActionInteractObject(OID oPlaceable)
{
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(329);
}

OID GetLastUsedBy()
{
    vm::impl::call_builtin(330);
    return vm::impl::pop_oid();
}

int GetAbilityModifier(int nAbility, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nAbility);
    vm::impl::call_builtin(331);
    return vm::impl::pop_int();
}

int GetIdentified(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(332);
    return vm::impl::pop_int();
}

void SetIdentified(OID oItem, int bIdentified)
{
    vm::impl::push_int(bIdentified);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(333);
}

void SummonAnimalCompanion(OID oMaster)
{
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(334);
}

void SummonFamiliar(OID oMaster)
{
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(335);
}

OID GetBlockingDoor()
{
    vm::impl::call_builtin(336);
    return vm::impl::pop_oid();
}

int GetIsDoorActionPossible(OID oTargetDoor, int nDoorAction)
{
    vm::impl::push_int(nDoorAction);
    vm::impl::push_oid(oTargetDoor);
    vm::impl::call_builtin(337);
    return vm::impl::pop_int();
}

void DoDoorAction(OID oTargetDoor, int nDoorAction)
{
    vm::impl::push_int(nDoorAction);
    vm::impl::push_oid(oTargetDoor);
    vm::impl::call_builtin(338);
}

OID GetFirstItemInInventory(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(339);
    return vm::impl::pop_oid();
}

OID GetNextItemInInventory(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(340);
    return vm::impl::pop_oid();
}

int GetClassByPosition(int nClassPosition, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nClassPosition);
    vm::impl::call_builtin(341);
    return vm::impl::pop_int();
}

int GetLevelByPosition(int nClassPosition, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nClassPosition);
    vm::impl::call_builtin(342);
    return vm::impl::pop_int();
}

int GetLevelByClass(int nClassType, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nClassType);
    vm::impl::call_builtin(343);
    return vm::impl::pop_int();
}

int GetDamageDealtByType(int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(344);
    return vm::impl::pop_int();
}

int GetTotalDamageDealt()
{
    vm::impl::call_builtin(345);
    return vm::impl::pop_int();
}

OID GetLastDamager(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(346);
    return vm::impl::pop_oid();
}

OID GetLastDisarmed()
{
    vm::impl::call_builtin(347);
    return vm::impl::pop_oid();
}

OID GetLastDisturbed()
{
    vm::impl::call_builtin(348);
    return vm::impl::pop_oid();
}

OID GetLastLocked()
{
    vm::impl::call_builtin(349);
    return vm::impl::pop_oid();
}

OID GetLastUnlocked()
{
    vm::impl::call_builtin(350);
    return vm::impl::pop_oid();
}

Effect EffectSkillIncrease(int nSkill, int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(351);
    return vm::impl::pop_effect();
}

int GetInventoryDisturbType()
{
    vm::impl::call_builtin(352);
    return vm::impl::pop_int();
}

OID GetInventoryDisturbItem()
{
    vm::impl::call_builtin(353);
    return vm::impl::pop_oid();
}

OID GetHenchman(OID oMaster, int nNth)
{
    vm::impl::push_int(nNth);
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(354);
    return vm::impl::pop_oid();
}

Effect VersusAlignmentEffect(Effect eEffect, int nLawChaos, int nGoodEvil)
{
    vm::impl::push_int(nGoodEvil);
    vm::impl::push_int(nLawChaos);
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(355);
    return vm::impl::pop_effect();
}

Effect VersusRacialTypeEffect(Effect eEffect, int nRacialType)
{
    vm::impl::push_int(nRacialType);
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(356);
    return vm::impl::pop_effect();
}

Effect VersusTrapEffect(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(357);
    return vm::impl::pop_effect();
}

int GetGender(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(358);
    return vm::impl::pop_int();
}

int GetIsTalentValid(Talent tTalent)
{
    vm::impl::push_talent(tTalent);
    vm::impl::call_builtin(359);
    return vm::impl::pop_int();
}

void ActionMoveAwayFromLocation(Loc lMoveAwayFrom, int bRun, float fMoveAwayRange)
{
    vm::impl::push_float(fMoveAwayRange);
    vm::impl::push_int(bRun);
    vm::impl::push_loc(lMoveAwayFrom);
    vm::impl::call_builtin(360);
}

OID GetAttemptedAttackTarget()
{
    vm::impl::call_builtin(361);
    return vm::impl::pop_oid();
}

int GetTypeFromTalent(Talent tTalent)
{
    vm::impl::push_talent(tTalent);
    vm::impl::call_builtin(362);
    return vm::impl::pop_int();
}

int GetIdFromTalent(Talent tTalent)
{
    vm::impl::push_talent(tTalent);
    vm::impl::call_builtin(363);
    return vm::impl::pop_int();
}

OID GetAssociate(int nAssociateType, OID oMaster, int nTh)
{
    vm::impl::push_int(nTh);
    vm::impl::push_oid(oMaster);
    vm::impl::push_int(nAssociateType);
    vm::impl::call_builtin(364);
    return vm::impl::pop_oid();
}

void AddHenchman(OID oMaster, OID oHenchman)
{
    vm::impl::push_oid(oHenchman);
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(365);
}

void RemoveHenchman(OID oMaster, OID oHenchman)
{
    vm::impl::push_oid(oHenchman);
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(366);
}

void AddJournalQuestEntry(CExoString szPlotID, int nState, OID oCreature, int bAllPartyMembers, int bAllPlayers, int bAllowOverrideHigher)
{
    vm::impl::push_int(bAllowOverrideHigher);
    vm::impl::push_int(bAllPlayers);
    vm::impl::push_int(bAllPartyMembers);
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nState);
    vm::impl::push_string(szPlotID);
    vm::impl::call_builtin(367);
}

void RemoveJournalQuestEntry(CExoString szPlotID, OID oCreature, int bAllPartyMembers, int bAllPlayers)
{
    vm::impl::push_int(bAllPlayers);
    vm::impl::push_int(bAllPartyMembers);
    vm::impl::push_oid(oCreature);
    vm::impl::push_string(szPlotID);
    vm::impl::call_builtin(368);
}

CExoString GetPCPublicCDKey(OID oPlayer, int nSinglePlayerCDKey)
{
    vm::impl::push_int(nSinglePlayerCDKey);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(369);
    return vm::impl::pop_string();
}

CExoString GetPCIPAddress(OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(370);
    return vm::impl::pop_string();
}

CExoString GetPCPlayerName(OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(371);
    return vm::impl::pop_string();
}

void SetPCLike(OID oPlayer, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(372);
}

void SetPCDislike(OID oPlayer, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(373);
}

void SendMessageToPC(OID oPlayer, CExoString szMessage)
{
    vm::impl::push_string(szMessage);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(374);
}

OID GetAttemptedSpellTarget()
{
    vm::impl::call_builtin(375);
    return vm::impl::pop_oid();
}

OID GetLastOpenedBy()
{
    vm::impl::call_builtin(376);
    return vm::impl::pop_oid();
}

int GetHasSpell(int nSpell, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(377);
    return vm::impl::pop_int();
}

void OpenStore(OID oStore, OID oPC, int nBonusMarkUp, int nBonusMarkDown)
{
    vm::impl::push_int(nBonusMarkDown);
    vm::impl::push_int(nBonusMarkUp);
    vm::impl::push_oid(oPC);
    vm::impl::push_oid(oStore);
    vm::impl::call_builtin(378);
}

Effect EffectTurned()
{
    vm::impl::call_builtin(379);
    return vm::impl::pop_effect();
}

OID GetFirstFactionMember(OID oMemberOfFaction, int bPCOnly)
{
    vm::impl::push_int(bPCOnly);
    vm::impl::push_oid(oMemberOfFaction);
    vm::impl::call_builtin(380);
    return vm::impl::pop_oid();
}

OID GetNextFactionMember(OID oMemberOfFaction, int bPCOnly)
{
    vm::impl::push_int(bPCOnly);
    vm::impl::push_oid(oMemberOfFaction);
    vm::impl::call_builtin(381);
    return vm::impl::pop_oid();
}

void ActionForceMoveToLocation(Loc lDestination, int bRun, float fTimeout)
{
    vm::impl::push_float(fTimeout);
    vm::impl::push_int(bRun);
    vm::impl::push_loc(lDestination);
    vm::impl::call_builtin(382);
}

void ActionForceMoveToObject(OID oMoveTo, int bRun, float fRange, float fTimeout)
{
    vm::impl::push_float(fTimeout);
    vm::impl::push_float(fRange);
    vm::impl::push_int(bRun);
    vm::impl::push_oid(oMoveTo);
    vm::impl::call_builtin(383);
}

int GetJournalQuestExperience(CExoString szPlotID)
{
    vm::impl::push_string(szPlotID);
    vm::impl::call_builtin(384);
    return vm::impl::pop_int();
}

void JumpToObject(OID oToJumpTo, int nWalkStraightLineToPoint)
{
    vm::impl::push_int(nWalkStraightLineToPoint);
    vm::impl::push_oid(oToJumpTo);
    vm::impl::call_builtin(385);
}

void SetMapPinEnabled(OID oMapPin, int nEnabled)
{
    vm::impl::push_int(nEnabled);
    vm::impl::push_oid(oMapPin);
    vm::impl::call_builtin(386);
}

Effect EffectHitPointChangeWhenDying(float fHitPointChangePerRound)
{
    vm::impl::push_float(fHitPointChangePerRound);
    vm::impl::call_builtin(387);
    return vm::impl::pop_effect();
}

void PopUpGUIPanel(OID oPC, int nGUIPanel)
{
    vm::impl::push_int(nGUIPanel);
    vm::impl::push_oid(oPC);
    vm::impl::call_builtin(388);
}

void ClearPersonalReputation(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(389);
}

void SetIsTemporaryFriend(OID oTarget, OID oSource, int bDecays, float fDurationInSeconds)
{
    vm::impl::push_float(fDurationInSeconds);
    vm::impl::push_int(bDecays);
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(390);
}

void SetIsTemporaryEnemy(OID oTarget, OID oSource, int bDecays, float fDurationInSeconds)
{
    vm::impl::push_float(fDurationInSeconds);
    vm::impl::push_int(bDecays);
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(391);
}

void SetIsTemporaryNeutral(OID oTarget, OID oSource, int bDecays, float fDurationInSeconds)
{
    vm::impl::push_float(fDurationInSeconds);
    vm::impl::push_int(bDecays);
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(392);
}

void GiveXPToCreature(OID oCreature, int nXpAmount)
{
    vm::impl::push_int(nXpAmount);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(393);
}

void SetXP(OID oCreature, int nXpAmount)
{
    vm::impl::push_int(nXpAmount);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(394);
}

int GetXP(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(395);
    return vm::impl::pop_int();
}

CExoString IntToHexString(int nInteger)
{
    vm::impl::push_int(nInteger);
    vm::impl::call_builtin(396);
    return vm::impl::pop_string();
}

int GetBaseItemType(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(397);
    return vm::impl::pop_int();
}

int GetItemHasItemProperty(OID oItem, int nProperty)
{
    vm::impl::push_int(nProperty);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(398);
    return vm::impl::pop_int();
}

void ActionEquipMostDamagingMelee(OID oVersus, int bOffHand)
{
    vm::impl::push_int(bOffHand);
    vm::impl::push_oid(oVersus);
    vm::impl::call_builtin(399);
}

void ActionEquipMostDamagingRanged(OID oVersus)
{
    vm::impl::push_oid(oVersus);
    vm::impl::call_builtin(400);
}

int GetItemACValue(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(401);
    return vm::impl::pop_int();
}

void ActionRest(int bCreatureToEnemyLineOfSightCheck)
{
    vm::impl::push_int(bCreatureToEnemyLineOfSightCheck);
    vm::impl::call_builtin(402);
}

void ExploreAreaForPlayer(OID oArea, OID oPlayer, int bExplored)
{
    vm::impl::push_int(bExplored);
    vm::impl::push_oid(oPlayer);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(403);
}

void ActionEquipMostEffectiveArmor()
{
    vm::impl::call_builtin(404);
}

int GetIsDay()
{
    vm::impl::call_builtin(405);
    return vm::impl::pop_int();
}

int GetIsNight()
{
    vm::impl::call_builtin(406);
    return vm::impl::pop_int();
}

int GetIsDawn()
{
    vm::impl::call_builtin(407);
    return vm::impl::pop_int();
}

int GetIsDusk()
{
    vm::impl::call_builtin(408);
    return vm::impl::pop_int();
}

int GetIsEncounterCreature(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(409);
    return vm::impl::pop_int();
}

OID GetLastPlayerDying()
{
    vm::impl::call_builtin(410);
    return vm::impl::pop_oid();
}

Loc GetStartingLocation()
{
    vm::impl::call_builtin(411);
    return vm::impl::pop_loc();
}

void ChangeToStandardFaction(OID oCreatureToChange, int nStandardFaction)
{
    vm::impl::push_int(nStandardFaction);
    vm::impl::push_oid(oCreatureToChange);
    vm::impl::call_builtin(412);
}

void SoundObjectPlay(OID oSound)
{
    vm::impl::push_oid(oSound);
    vm::impl::call_builtin(413);
}

void SoundObjectStop(OID oSound)
{
    vm::impl::push_oid(oSound);
    vm::impl::call_builtin(414);
}

void SoundObjectSetVolume(OID oSound, int nVolume)
{
    vm::impl::push_int(nVolume);
    vm::impl::push_oid(oSound);
    vm::impl::call_builtin(415);
}

void SoundObjectSetPosition(OID oSound, Vec3 vPosition)
{
    vm::impl::push_vec(vPosition);
    vm::impl::push_oid(oSound);
    vm::impl::call_builtin(416);
}

void SpeakOneLinerConversation(CExoString sDialogResRef, OID oTokenTarget)
{
    vm::impl::push_oid(oTokenTarget);
    vm::impl::push_string(sDialogResRef);
    vm::impl::call_builtin(417);
}

int GetGold(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(418);
    return vm::impl::pop_int();
}

OID GetLastRespawnButtonPresser()
{
    vm::impl::call_builtin(419);
    return vm::impl::pop_oid();
}

int GetIsDM(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(420);
    return vm::impl::pop_int();
}

void PlayVoiceChat(int nVoiceChatID, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nVoiceChatID);
    vm::impl::call_builtin(421);
}

int GetIsWeaponEffective(OID oVersus, int bOffHand)
{
    vm::impl::push_int(bOffHand);
    vm::impl::push_oid(oVersus);
    vm::impl::call_builtin(422);
    return vm::impl::pop_int();
}

int GetLastSpellHarmful()
{
    vm::impl::call_builtin(423);
    return vm::impl::pop_int();
}

Event EventActivateItem(OID oItem, Loc lTarget, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_loc(lTarget);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(424);
    return vm::impl::pop_event();
}

void MusicBackgroundPlay(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(425);
}

void MusicBackgroundStop(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(426);
}

void MusicBackgroundSetDelay(OID oArea, int nDelay)
{
    vm::impl::push_int(nDelay);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(427);
}

void MusicBackgroundChangeDay(OID oArea, int nTrack)
{
    vm::impl::push_int(nTrack);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(428);
}

void MusicBackgroundChangeNight(OID oArea, int nTrack)
{
    vm::impl::push_int(nTrack);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(429);
}

void MusicBattlePlay(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(430);
}

void MusicBattleStop(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(431);
}

void MusicBattleChange(OID oArea, int nTrack)
{
    vm::impl::push_int(nTrack);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(432);
}

void AmbientSoundPlay(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(433);
}

void AmbientSoundStop(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(434);
}

void AmbientSoundChangeDay(OID oArea, int nTrack)
{
    vm::impl::push_int(nTrack);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(435);
}

void AmbientSoundChangeNight(OID oArea, int nTrack)
{
    vm::impl::push_int(nTrack);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(436);
}

OID GetLastKiller()
{
    vm::impl::call_builtin(437);
    return vm::impl::pop_oid();
}

OID GetSpellCastItem()
{
    vm::impl::call_builtin(438);
    return vm::impl::pop_oid();
}

OID GetItemActivated()
{
    vm::impl::call_builtin(439);
    return vm::impl::pop_oid();
}

OID GetItemActivator()
{
    vm::impl::call_builtin(440);
    return vm::impl::pop_oid();
}

Loc GetItemActivatedTargetLocation()
{
    vm::impl::call_builtin(441);
    return vm::impl::pop_loc();
}

OID GetItemActivatedTarget()
{
    vm::impl::call_builtin(442);
    return vm::impl::pop_oid();
}

int GetIsOpen(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(443);
    return vm::impl::pop_int();
}

void TakeGoldFromCreature(int nAmount, OID oCreatureToTakeFrom, int bDestroy)
{
    vm::impl::push_int(bDestroy);
    vm::impl::push_oid(oCreatureToTakeFrom);
    vm::impl::push_int(nAmount);
    vm::impl::call_builtin(444);
}

int IsInConversation(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(445);
    return vm::impl::pop_int();
}

Effect EffectAbilityDecrease(int nAbility, int nModifyBy)
{
    vm::impl::push_int(nModifyBy);
    vm::impl::push_int(nAbility);
    vm::impl::call_builtin(446);
    return vm::impl::pop_effect();
}

Effect EffectAttackDecrease(int nPenalty, int nModifierType)
{
    vm::impl::push_int(nModifierType);
    vm::impl::push_int(nPenalty);
    vm::impl::call_builtin(447);
    return vm::impl::pop_effect();
}

Effect EffectDamageDecrease(int nPenalty, int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nPenalty);
    vm::impl::call_builtin(448);
    return vm::impl::pop_effect();
}

Effect EffectDamageImmunityDecrease(int nDamageType, int nPercentImmunity)
{
    vm::impl::push_int(nPercentImmunity);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(449);
    return vm::impl::pop_effect();
}

Effect EffectACDecrease(int nValue, int nModifyType, int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nModifyType);
    vm::impl::push_int(nValue);
    vm::impl::call_builtin(450);
    return vm::impl::pop_effect();
}

Effect EffectMovementSpeedDecrease(int nPercentChange)
{
    vm::impl::push_int(nPercentChange);
    vm::impl::call_builtin(451);
    return vm::impl::pop_effect();
}

Effect EffectSavingThrowDecrease(int nSave, int nValue, int nSaveType)
{
    vm::impl::push_int(nSaveType);
    vm::impl::push_int(nValue);
    vm::impl::push_int(nSave);
    vm::impl::call_builtin(452);
    return vm::impl::pop_effect();
}

Effect EffectSkillDecrease(int nSkill, int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(453);
    return vm::impl::pop_effect();
}

Effect EffectSpellResistanceDecrease(int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::call_builtin(454);
    return vm::impl::pop_effect();
}

int GetPlotFlag(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(455);
    return vm::impl::pop_int();
}

void SetPlotFlag(OID oTarget, int nPlotFlag)
{
    vm::impl::push_int(nPlotFlag);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(456);
}

Effect EffectInvisibility(int nInvisibilityType)
{
    vm::impl::push_int(nInvisibilityType);
    vm::impl::call_builtin(457);
    return vm::impl::pop_effect();
}

Effect EffectConcealment(int nPercentage, int nMissType)
{
    vm::impl::push_int(nMissType);
    vm::impl::push_int(nPercentage);
    vm::impl::call_builtin(458);
    return vm::impl::pop_effect();
}

Effect EffectDarkness()
{
    vm::impl::call_builtin(459);
    return vm::impl::pop_effect();
}

Effect EffectDispelMagicAll(int nCasterLevel)
{
    vm::impl::push_int(nCasterLevel);
    vm::impl::call_builtin(460);
    return vm::impl::pop_effect();
}

Effect EffectUltravision()
{
    vm::impl::call_builtin(461);
    return vm::impl::pop_effect();
}

Effect EffectNegativeLevel(int nNumLevels, int bHPBonus)
{
    vm::impl::push_int(bHPBonus);
    vm::impl::push_int(nNumLevels);
    vm::impl::call_builtin(462);
    return vm::impl::pop_effect();
}

Effect EffectPolymorph(int nPolymorphSelection, int nLocked)
{
    vm::impl::push_int(nLocked);
    vm::impl::push_int(nPolymorphSelection);
    vm::impl::call_builtin(463);
    return vm::impl::pop_effect();
}

Effect EffectSanctuary(int nDifficultyClass)
{
    vm::impl::push_int(nDifficultyClass);
    vm::impl::call_builtin(464);
    return vm::impl::pop_effect();
}

Effect EffectTrueSeeing()
{
    vm::impl::call_builtin(465);
    return vm::impl::pop_effect();
}

Effect EffectSeeInvisible()
{
    vm::impl::call_builtin(466);
    return vm::impl::pop_effect();
}

Effect EffectTimeStop()
{
    vm::impl::call_builtin(467);
    return vm::impl::pop_effect();
}

Effect EffectBlindness()
{
    vm::impl::call_builtin(468);
    return vm::impl::pop_effect();
}

int GetIsReactionTypeFriendly(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(469);
    return vm::impl::pop_int();
}

int GetIsReactionTypeNeutral(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(470);
    return vm::impl::pop_int();
}

int GetIsReactionTypeHostile(OID oTarget, OID oSource)
{
    vm::impl::push_oid(oSource);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(471);
    return vm::impl::pop_int();
}

Effect EffectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed, int nSpellSchool)
{
    vm::impl::push_int(nSpellSchool);
    vm::impl::push_int(nTotalSpellLevelsAbsorbed);
    vm::impl::push_int(nMaxSpellLevelAbsorbed);
    vm::impl::call_builtin(472);
    return vm::impl::pop_effect();
}

Effect EffectDispelMagicBest(int nCasterLevel)
{
    vm::impl::push_int(nCasterLevel);
    vm::impl::call_builtin(473);
    return vm::impl::pop_effect();
}

void ActivatePortal(OID oTarget, CExoString sIPaddress, CExoString sPassword, CExoString sWaypointTag, int bSeemless)
{
    vm::impl::push_int(bSeemless);
    vm::impl::push_string(sWaypointTag);
    vm::impl::push_string(sPassword);
    vm::impl::push_string(sIPaddress);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(474);
}

int GetNumStackedItems(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(475);
    return vm::impl::pop_int();
}

void SurrenderToEnemies()
{
    vm::impl::call_builtin(476);
}

Effect EffectMissChance(int nPercentage, int nMissChanceType)
{
    vm::impl::push_int(nMissChanceType);
    vm::impl::push_int(nPercentage);
    vm::impl::call_builtin(477);
    return vm::impl::pop_effect();
}

int GetTurnResistanceHD(OID oUndead)
{
    vm::impl::push_oid(oUndead);
    vm::impl::call_builtin(478);
    return vm::impl::pop_int();
}

int GetCreatureSize(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(479);
    return vm::impl::pop_int();
}

Effect EffectDisappearAppear(Loc lLocation, int nAnimation)
{
    vm::impl::push_int(nAnimation);
    vm::impl::push_loc(lLocation);
    vm::impl::call_builtin(480);
    return vm::impl::pop_effect();
}

Effect EffectDisappear(int nAnimation)
{
    vm::impl::push_int(nAnimation);
    vm::impl::call_builtin(481);
    return vm::impl::pop_effect();
}

Effect EffectAppear(int nAnimation)
{
    vm::impl::push_int(nAnimation);
    vm::impl::call_builtin(482);
    return vm::impl::pop_effect();
}

void ActionUnlockObject(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(483);
}

void ActionLockObject(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(484);
}

Effect EffectModifyAttacks(int nAttacks)
{
    vm::impl::push_int(nAttacks);
    vm::impl::call_builtin(485);
    return vm::impl::pop_effect();
}

OID GetLastTrapDetected(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(486);
    return vm::impl::pop_oid();
}

Effect EffectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nRandomAmount);
    vm::impl::push_int(nDamageAmount);
    vm::impl::call_builtin(487);
    return vm::impl::pop_effect();
}

OID GetNearestTrapToObject(OID oTarget, int nTrapDetected)
{
    vm::impl::push_int(nTrapDetected);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(488);
    return vm::impl::pop_oid();
}

CExoString GetDeity(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(489);
    return vm::impl::pop_string();
}

CExoString GetSubRace(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(490);
    return vm::impl::pop_string();
}

int GetFortitudeSavingThrow(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(491);
    return vm::impl::pop_int();
}

int GetWillSavingThrow(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(492);
    return vm::impl::pop_int();
}

int GetReflexSavingThrow(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(493);
    return vm::impl::pop_int();
}

float GetChallengeRating(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(494);
    return vm::impl::pop_float();
}

int GetAge(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(495);
    return vm::impl::pop_int();
}

int GetMovementRate(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(496);
    return vm::impl::pop_int();
}

int GetFamiliarCreatureType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(497);
    return vm::impl::pop_int();
}

int GetAnimalCompanionCreatureType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(498);
    return vm::impl::pop_int();
}

CExoString GetFamiliarName(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(499);
    return vm::impl::pop_string();
}

CExoString GetAnimalCompanionName(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(500);
    return vm::impl::pop_string();
}

void ActionCastFakeSpellAtObject(int nSpell, OID oTarget, int nProjectilePathType)
{
    vm::impl::push_int(nProjectilePathType);
    vm::impl::push_oid(oTarget);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(501);
}

void ActionCastFakeSpellAtLocation(int nSpell, Loc lTarget, int nProjectilePathType)
{
    vm::impl::push_int(nProjectilePathType);
    vm::impl::push_loc(lTarget);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(502);
}

void RemoveSummonedAssociate(OID oMaster, OID oAssociate)
{
    vm::impl::push_oid(oAssociate);
    vm::impl::push_oid(oMaster);
    vm::impl::call_builtin(503);
}

void SetCameraMode(OID oPlayer, int nCameraMode)
{
    vm::impl::push_int(nCameraMode);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(504);
}

int GetIsResting(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(505);
    return vm::impl::pop_int();
}

OID GetLastPCRested()
{
    vm::impl::call_builtin(506);
    return vm::impl::pop_oid();
}

void SetWeather(OID oTarget, int nWeather)
{
    vm::impl::push_int(nWeather);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(507);
}

int GetLastRestEventType()
{
    vm::impl::call_builtin(508);
    return vm::impl::pop_int();
}

void StartNewModule(CExoString sModuleName)
{
    vm::impl::push_string(sModuleName);
    vm::impl::call_builtin(509);
}

Effect EffectSwarm(int nLooping, CExoString sCreatureTemplate1, CExoString sCreatureTemplate2, CExoString sCreatureTemplate3, CExoString sCreatureTemplate4)
{
    vm::impl::push_string(sCreatureTemplate4);
    vm::impl::push_string(sCreatureTemplate3);
    vm::impl::push_string(sCreatureTemplate2);
    vm::impl::push_string(sCreatureTemplate1);
    vm::impl::push_int(nLooping);
    vm::impl::call_builtin(510);
    return vm::impl::pop_effect();
}

int GetWeaponRanged(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(511);
    return vm::impl::pop_int();
}

void DoSinglePlayerAutoSave()
{
    vm::impl::call_builtin(512);
}

int GetGameDifficulty()
{
    vm::impl::call_builtin(513);
    return vm::impl::pop_int();
}

void SetTileMainLightColor(Loc lTileLocation, int nMainLight1Color, int nMainLight2Color)
{
    vm::impl::push_int(nMainLight2Color);
    vm::impl::push_int(nMainLight1Color);
    vm::impl::push_loc(lTileLocation);
    vm::impl::call_builtin(514);
}

void SetTileSourceLightColor(Loc lTileLocation, int nSourceLight1Color, int nSourceLight2Color)
{
    vm::impl::push_int(nSourceLight2Color);
    vm::impl::push_int(nSourceLight1Color);
    vm::impl::push_loc(lTileLocation);
    vm::impl::call_builtin(515);
}

void RecomputeStaticLighting(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(516);
}

int GetTileMainLight1Color(Loc lTile)
{
    vm::impl::push_loc(lTile);
    vm::impl::call_builtin(517);
    return vm::impl::pop_int();
}

int GetTileMainLight2Color(Loc lTile)
{
    vm::impl::push_loc(lTile);
    vm::impl::call_builtin(518);
    return vm::impl::pop_int();
}

int GetTileSourceLight1Color(Loc lTile)
{
    vm::impl::push_loc(lTile);
    vm::impl::call_builtin(519);
    return vm::impl::pop_int();
}

int GetTileSourceLight2Color(Loc lTile)
{
    vm::impl::push_loc(lTile);
    vm::impl::call_builtin(520);
    return vm::impl::pop_int();
}

void SetPanelButtonFlash(OID oPlayer, int nButton, int nEnableFlash)
{
    vm::impl::push_int(nEnableFlash);
    vm::impl::push_int(nButton);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(521);
}

int GetCurrentAction(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(522);
    return vm::impl::pop_int();
}

void SetStandardFactionReputation(int nStandardFaction, int nNewReputation, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nNewReputation);
    vm::impl::push_int(nStandardFaction);
    vm::impl::call_builtin(523);
}

int GetStandardFactionReputation(int nStandardFaction, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nStandardFaction);
    vm::impl::call_builtin(524);
    return vm::impl::pop_int();
}

void FloatingTextStrRefOnCreature(int nStrRefToDisplay, OID oCreatureToFloatAbove, int bBroadcastToFaction)
{
    vm::impl::push_int(bBroadcastToFaction);
    vm::impl::push_oid(oCreatureToFloatAbove);
    vm::impl::push_int(nStrRefToDisplay);
    vm::impl::call_builtin(525);
}

void FloatingTextStringOnCreature(CExoString sStringToDisplay, OID oCreatureToFloatAbove, int bBroadcastToFaction)
{
    vm::impl::push_int(bBroadcastToFaction);
    vm::impl::push_oid(oCreatureToFloatAbove);
    vm::impl::push_string(sStringToDisplay);
    vm::impl::call_builtin(526);
}

int GetTrapDisarmable(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(527);
    return vm::impl::pop_int();
}

int GetTrapDetectable(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(528);
    return vm::impl::pop_int();
}

int GetTrapDetectedBy(OID oTrapObject, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(529);
    return vm::impl::pop_int();
}

int GetTrapFlagged(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(530);
    return vm::impl::pop_int();
}

int GetTrapBaseType(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(531);
    return vm::impl::pop_int();
}

int GetTrapOneShot(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(532);
    return vm::impl::pop_int();
}

OID GetTrapCreator(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(533);
    return vm::impl::pop_oid();
}

CExoString GetTrapKeyTag(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(534);
    return vm::impl::pop_string();
}

int GetTrapDisarmDC(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(535);
    return vm::impl::pop_int();
}

int GetTrapDetectDC(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(536);
    return vm::impl::pop_int();
}

int GetLockKeyRequired(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(537);
    return vm::impl::pop_int();
}

CExoString GetLockKeyTag(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(538);
    return vm::impl::pop_string();
}

int GetLockLockable(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(539);
    return vm::impl::pop_int();
}

int GetLockUnlockDC(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(540);
    return vm::impl::pop_int();
}

int GetLockLockDC(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(541);
    return vm::impl::pop_int();
}

OID GetPCLevellingUp()
{
    vm::impl::call_builtin(542);
    return vm::impl::pop_oid();
}

int GetHasFeatEffect(int nFeat, OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::push_int(nFeat);
    vm::impl::call_builtin(543);
    return vm::impl::pop_int();
}

void SetPlaceableIllumination(OID oPlaceable, int bIlluminate)
{
    vm::impl::push_int(bIlluminate);
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(544);
}

int GetPlaceableIllumination(OID oPlaceable)
{
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(545);
    return vm::impl::pop_int();
}

int GetIsPlaceableObjectActionPossible(OID oPlaceable, int nPlaceableAction)
{
    vm::impl::push_int(nPlaceableAction);
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(546);
    return vm::impl::pop_int();
}

void DoPlaceableObjectAction(OID oPlaceable, int nPlaceableAction)
{
    vm::impl::push_int(nPlaceableAction);
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(547);
}

OID GetFirstPC()
{
    vm::impl::call_builtin(548);
    return vm::impl::pop_oid();
}

OID GetNextPC()
{
    vm::impl::call_builtin(549);
    return vm::impl::pop_oid();
}

int SetTrapDetectedBy(OID oTrap, OID oDetector, int bDetected)
{
    vm::impl::push_int(bDetected);
    vm::impl::push_oid(oDetector);
    vm::impl::push_oid(oTrap);
    vm::impl::call_builtin(550);
    return vm::impl::pop_int();
}

int GetIsTrapped(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(551);
    return vm::impl::pop_int();
}

Effect EffectTurnResistanceDecrease(int nHitDice)
{
    vm::impl::push_int(nHitDice);
    vm::impl::call_builtin(552);
    return vm::impl::pop_effect();
}

Effect EffectTurnResistanceIncrease(int nHitDice)
{
    vm::impl::push_int(nHitDice);
    vm::impl::call_builtin(553);
    return vm::impl::pop_effect();
}

void PopUpDeathGUIPanel(OID oPC, int bRespawnButtonEnabled, int bWaitForHelpButtonEnabled, int nHelpStringReference, CExoString sHelpString)
{
    vm::impl::push_string(sHelpString);
    vm::impl::push_int(nHelpStringReference);
    vm::impl::push_int(bWaitForHelpButtonEnabled);
    vm::impl::push_int(bRespawnButtonEnabled);
    vm::impl::push_oid(oPC);
    vm::impl::call_builtin(554);
}

void SetTrapDisabled(OID oTrap)
{
    vm::impl::push_oid(oTrap);
    vm::impl::call_builtin(555);
}

OID GetLastHostileActor(OID oVictim)
{
    vm::impl::push_oid(oVictim);
    vm::impl::call_builtin(556);
    return vm::impl::pop_oid();
}

void ExportAllCharacters()
{
    vm::impl::call_builtin(557);
}

int MusicBackgroundGetDayTrack(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(558);
    return vm::impl::pop_int();
}

int MusicBackgroundGetNightTrack(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(559);
    return vm::impl::pop_int();
}

void WriteTimestampedLogEntry(CExoString sLogEntry)
{
    vm::impl::push_string(sLogEntry);
    vm::impl::call_builtin(560);
}

CExoString GetModuleName()
{
    vm::impl::call_builtin(561);
    return vm::impl::pop_string();
}

OID GetFactionLeader(OID oMemberOfFaction)
{
    vm::impl::push_oid(oMemberOfFaction);
    vm::impl::call_builtin(562);
    return vm::impl::pop_oid();
}

void SendMessageToAllDMs(CExoString szMessage)
{
    vm::impl::push_string(szMessage);
    vm::impl::call_builtin(563);
}

void EndGame(CExoString sEndMovie)
{
    vm::impl::push_string(sEndMovie);
    vm::impl::call_builtin(564);
}

void BootPC(OID oPlayer, CExoString sReason)
{
    vm::impl::push_string(sReason);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(565);
}

void ActionCounterSpell(OID oCounterSpellTarget)
{
    vm::impl::push_oid(oCounterSpellTarget);
    vm::impl::call_builtin(566);
}

void AmbientSoundSetDayVolume(OID oArea, int nVolume)
{
    vm::impl::push_int(nVolume);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(567);
}

void AmbientSoundSetNightVolume(OID oArea, int nVolume)
{
    vm::impl::push_int(nVolume);
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(568);
}

int MusicBackgroundGetBattleTrack(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(569);
    return vm::impl::pop_int();
}

int GetHasInventory(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(570);
    return vm::impl::pop_int();
}

float GetStrRefSoundDuration(int nStrRef)
{
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(571);
    return vm::impl::pop_float();
}

void AddToParty(OID oPC, OID oPartyLeader)
{
    vm::impl::push_oid(oPartyLeader);
    vm::impl::push_oid(oPC);
    vm::impl::call_builtin(572);
}

void RemoveFromParty(OID oPC)
{
    vm::impl::push_oid(oPC);
    vm::impl::call_builtin(573);
}

int GetStealthMode(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(574);
    return vm::impl::pop_int();
}

int GetDetectMode(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(575);
    return vm::impl::pop_int();
}

int GetDefensiveCastingMode(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(576);
    return vm::impl::pop_int();
}

int GetAppearanceType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(577);
    return vm::impl::pop_int();
}

void SpawnScriptDebugger()
{
    vm::impl::call_builtin(578);
}

int GetModuleItemAcquiredStackSize()
{
    vm::impl::call_builtin(579);
    return vm::impl::pop_int();
}

void DecrementRemainingFeatUses(OID oCreature, int nFeat)
{
    vm::impl::push_int(nFeat);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(580);
}

void DecrementRemainingSpellUses(OID oCreature, int nSpell)
{
    vm::impl::push_int(nSpell);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(581);
}

CExoString GetResRef(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(582);
    return vm::impl::pop_string();
}

Effect EffectPetrify()
{
    vm::impl::call_builtin(583);
    return vm::impl::pop_effect();
}

OID CopyItem(OID oItem, OID oTargetInventory, int bCopyVars)
{
    vm::impl::push_int(bCopyVars);
    vm::impl::push_oid(oTargetInventory);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(584);
    return vm::impl::pop_oid();
}

Effect EffectCutsceneParalyze()
{
    vm::impl::call_builtin(585);
    return vm::impl::pop_effect();
}

int GetDroppableFlag(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(586);
    return vm::impl::pop_int();
}

int GetUseableFlag(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(587);
    return vm::impl::pop_int();
}

int GetStolenFlag(OID oStolen)
{
    vm::impl::push_oid(oStolen);
    vm::impl::call_builtin(588);
    return vm::impl::pop_int();
}

void SetCampaignFloat(CExoString sCampaignName, CExoString sVarName, float flFloat, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_float(flFloat);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(589);
}

void SetCampaignInt(CExoString sCampaignName, CExoString sVarName, int nInt, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_int(nInt);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(590);
}

void SetCampaignVector(CExoString sCampaignName, CExoString sVarName, Vec3 vVector, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_vec(vVector);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(591);
}

void SetCampaignLocation(CExoString sCampaignName, CExoString sVarName, Loc locLocation, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_loc(locLocation);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(592);
}

void SetCampaignString(CExoString sCampaignName, CExoString sVarName, CExoString sString, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sString);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(593);
}

void DestroyCampaignDatabase(CExoString sCampaignName)
{
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(594);
}

float GetCampaignFloat(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(595);
    return vm::impl::pop_float();
}

int GetCampaignInt(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(596);
    return vm::impl::pop_int();
}

Vec3 GetCampaignVector(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(597);
    return vm::impl::pop_vec();
}

Loc GetCampaignLocation(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(598);
    return vm::impl::pop_loc();
}

CExoString GetCampaignString(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(599);
    return vm::impl::pop_string();
}

OID CopyObject(OID oSource, Loc locLocation, OID oOwner, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_oid(oOwner);
    vm::impl::push_loc(locLocation);
    vm::impl::push_oid(oSource);
    vm::impl::call_builtin(600);
    return vm::impl::pop_oid();
}

void DeleteCampaignVariable(CExoString sCampaignName, CExoString sVarName, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(601);
}

int StoreCampaignObject(CExoString sCampaignName, CExoString sVarName, OID oObject, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_oid(oObject);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(602);
    return vm::impl::pop_int();
}

OID RetrieveCampaignObject(CExoString sCampaignName, CExoString sVarName, Loc locLocation, OID oOwner, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_oid(oOwner);
    vm::impl::push_loc(locLocation);
    vm::impl::push_string(sVarName);
    vm::impl::push_string(sCampaignName);
    vm::impl::call_builtin(603);
    return vm::impl::pop_oid();
}

Effect EffectCutsceneDominated()
{
    vm::impl::call_builtin(604);
    return vm::impl::pop_effect();
}

int GetItemStackSize(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(605);
    return vm::impl::pop_int();
}

void SetItemStackSize(OID oItem, int nSize)
{
    vm::impl::push_int(nSize);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(606);
}

int GetItemCharges(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(607);
    return vm::impl::pop_int();
}

void SetItemCharges(OID oItem, int nCharges)
{
    vm::impl::push_int(nCharges);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(608);
}

void AddItemProperty(int nDurationType, ItemProperty ipProperty, OID oItem, float fDuration)
{
    vm::impl::push_float(fDuration);
    vm::impl::push_oid(oItem);
    vm::impl::push_iprop(ipProperty);
    vm::impl::push_int(nDurationType);
    vm::impl::call_builtin(609);
}

void RemoveItemProperty(OID oItem, ItemProperty ipProperty)
{
    vm::impl::push_iprop(ipProperty);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(610);
}

int GetIsItemPropertyValid(ItemProperty ipProperty)
{
    vm::impl::push_iprop(ipProperty);
    vm::impl::call_builtin(611);
    return vm::impl::pop_int();
}

ItemProperty GetFirstItemProperty(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(612);
    return vm::impl::pop_iprop();
}

ItemProperty GetNextItemProperty(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(613);
    return vm::impl::pop_iprop();
}

int GetItemPropertyType(ItemProperty ip)
{
    vm::impl::push_iprop(ip);
    vm::impl::call_builtin(614);
    return vm::impl::pop_int();
}

int GetItemPropertyDurationType(ItemProperty ip)
{
    vm::impl::push_iprop(ip);
    vm::impl::call_builtin(615);
    return vm::impl::pop_int();
}

ItemProperty ItemPropertyAbilityBonus(int nAbility, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nAbility);
    vm::impl::call_builtin(616);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyACBonus(int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::call_builtin(617);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyACBonusVsAlign(int nAlignGroup, int nACBonus)
{
    vm::impl::push_int(nACBonus);
    vm::impl::push_int(nAlignGroup);
    vm::impl::call_builtin(618);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyACBonusVsDmgType(int nDamageType, int nACBonus)
{
    vm::impl::push_int(nACBonus);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(619);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyACBonusVsRace(int nRace, int nACBonus)
{
    vm::impl::push_int(nACBonus);
    vm::impl::push_int(nRace);
    vm::impl::call_builtin(620);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyACBonusVsSAlign(int nAlign, int nACBonus)
{
    vm::impl::push_int(nACBonus);
    vm::impl::push_int(nAlign);
    vm::impl::call_builtin(621);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyEnhancementBonus(int nEnhancementBonus)
{
    vm::impl::push_int(nEnhancementBonus);
    vm::impl::call_builtin(622);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyEnhancementBonusVsAlign(int nAlignGroup, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nAlignGroup);
    vm::impl::call_builtin(623);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyEnhancementBonusVsRace(int nRace, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nRace);
    vm::impl::call_builtin(624);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyEnhancementBonusVsSAlign(int nAlign, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nAlign);
    vm::impl::call_builtin(625);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyEnhancementPenalty(int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::call_builtin(626);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyWeightReduction(int nReduction)
{
    vm::impl::push_int(nReduction);
    vm::impl::call_builtin(627);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyBonusFeat(int nFeat)
{
    vm::impl::push_int(nFeat);
    vm::impl::call_builtin(628);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyBonusLevelSpell(int nClass, int nSpellLevel)
{
    vm::impl::push_int(nSpellLevel);
    vm::impl::push_int(nClass);
    vm::impl::call_builtin(629);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyCastSpell(int nSpell, int nNumUses)
{
    vm::impl::push_int(nNumUses);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(630);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageBonus(int nDamageType, int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(631);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageBonusVsAlign(int nAlignGroup, int nDamageType, int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nAlignGroup);
    vm::impl::call_builtin(632);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageBonusVsRace(int nRace, int nDamageType, int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nRace);
    vm::impl::call_builtin(633);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageBonusVsSAlign(int nAlign, int nDamageType, int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::push_int(nDamageType);
    vm::impl::push_int(nAlign);
    vm::impl::call_builtin(634);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageImmunity(int nDamageType, int nImmuneBonus)
{
    vm::impl::push_int(nImmuneBonus);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(635);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamagePenalty(int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::call_builtin(636);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageReduction(int nEnhancement, int nHPSoak)
{
    vm::impl::push_int(nHPSoak);
    vm::impl::push_int(nEnhancement);
    vm::impl::call_builtin(637);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageResistance(int nDamageType, int nHPResist)
{
    vm::impl::push_int(nHPResist);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(638);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDamageVulnerability(int nDamageType, int nVulnerability)
{
    vm::impl::push_int(nVulnerability);
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(639);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDarkvision()
{
    vm::impl::call_builtin(640);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDecreaseAbility(int nAbility, int nModifier)
{
    vm::impl::push_int(nModifier);
    vm::impl::push_int(nAbility);
    vm::impl::call_builtin(641);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDecreaseAC(int nModifierType, int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::push_int(nModifierType);
    vm::impl::call_builtin(642);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyDecreaseSkill(int nSkill, int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(643);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyContainerReducedWeight(int nContainerType)
{
    vm::impl::push_int(nContainerType);
    vm::impl::call_builtin(644);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyExtraMeleeDamageType(int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(645);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyExtraRangeDamageType(int nDamageType)
{
    vm::impl::push_int(nDamageType);
    vm::impl::call_builtin(646);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyHaste()
{
    vm::impl::call_builtin(647);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyHolyAvenger()
{
    vm::impl::call_builtin(648);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyImmunityMisc(int nImmunityType)
{
    vm::impl::push_int(nImmunityType);
    vm::impl::call_builtin(649);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyImprovedEvasion()
{
    vm::impl::call_builtin(650);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyBonusSpellResistance(int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::call_builtin(651);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nBonusType);
    vm::impl::call_builtin(652);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nBaseSaveType);
    vm::impl::call_builtin(653);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyKeen()
{
    vm::impl::call_builtin(654);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyLight(int nBrightness, int nColor)
{
    vm::impl::push_int(nColor);
    vm::impl::push_int(nBrightness);
    vm::impl::call_builtin(655);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyMaxRangeStrengthMod(int nModifier)
{
    vm::impl::push_int(nModifier);
    vm::impl::call_builtin(656);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyNoDamage()
{
    vm::impl::call_builtin(657);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial)
{
    vm::impl::push_int(nSpecial);
    vm::impl::push_int(nSaveDC);
    vm::impl::push_int(nProperty);
    vm::impl::call_builtin(658);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::push_int(nBaseSaveType);
    vm::impl::call_builtin(659);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyReducedSavingThrow(int nBonusType, int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::push_int(nBonusType);
    vm::impl::call_builtin(660);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyRegeneration(int nRegenAmount)
{
    vm::impl::push_int(nRegenAmount);
    vm::impl::call_builtin(661);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertySkillBonus(int nSkill, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nSkill);
    vm::impl::call_builtin(662);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertySpellImmunitySpecific(int nSpell)
{
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(663);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertySpellImmunitySchool(int nSchool)
{
    vm::impl::push_int(nSchool);
    vm::impl::call_builtin(664);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyThievesTools(int nModifier)
{
    vm::impl::push_int(nModifier);
    vm::impl::call_builtin(665);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAttackBonus(int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::call_builtin(666);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAttackBonusVsAlign(int nAlignGroup, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nAlignGroup);
    vm::impl::call_builtin(667);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAttackBonusVsRace(int nRace, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nRace);
    vm::impl::call_builtin(668);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus)
{
    vm::impl::push_int(nBonus);
    vm::impl::push_int(nAlignment);
    vm::impl::call_builtin(669);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAttackPenalty(int nPenalty)
{
    vm::impl::push_int(nPenalty);
    vm::impl::call_builtin(670);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyUnlimitedAmmo(int nAmmoDamage)
{
    vm::impl::push_int(nAmmoDamage);
    vm::impl::call_builtin(671);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyLimitUseByAlign(int nAlignGroup)
{
    vm::impl::push_int(nAlignGroup);
    vm::impl::call_builtin(672);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyLimitUseByClass(int nClass)
{
    vm::impl::push_int(nClass);
    vm::impl::call_builtin(673);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyLimitUseByRace(int nRace)
{
    vm::impl::push_int(nRace);
    vm::impl::call_builtin(674);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyLimitUseBySAlign(int nAlignment)
{
    vm::impl::push_int(nAlignment);
    vm::impl::call_builtin(675);
    return vm::impl::pop_iprop();
}

ItemProperty BadBadReplaceMeThisDoesNothing()
{
    vm::impl::call_builtin(676);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyVampiricRegeneration(int nRegenAmount)
{
    vm::impl::push_int(nRegenAmount);
    vm::impl::call_builtin(677);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyTrap(int nTrapLevel, int nTrapType)
{
    vm::impl::push_int(nTrapType);
    vm::impl::push_int(nTrapLevel);
    vm::impl::call_builtin(678);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyTrueSeeing()
{
    vm::impl::call_builtin(679);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyOnMonsterHitProperties(int nProperty, int nSpecial)
{
    vm::impl::push_int(nSpecial);
    vm::impl::push_int(nProperty);
    vm::impl::call_builtin(680);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyTurnResistance(int nModifier)
{
    vm::impl::push_int(nModifier);
    vm::impl::call_builtin(681);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyMassiveCritical(int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::call_builtin(682);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyFreeAction()
{
    vm::impl::call_builtin(683);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyMonsterDamage(int nDamage)
{
    vm::impl::push_int(nDamage);
    vm::impl::call_builtin(684);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyImmunityToSpellLevel(int nLevel)
{
    vm::impl::push_int(nLevel);
    vm::impl::call_builtin(685);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertySpecialWalk(int nWalkType)
{
    vm::impl::push_int(nWalkType);
    vm::impl::call_builtin(686);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyHealersKit(int nModifier)
{
    vm::impl::push_int(nModifier);
    vm::impl::call_builtin(687);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyWeightIncrease(int nWeight)
{
    vm::impl::push_int(nWeight);
    vm::impl::call_builtin(688);
    return vm::impl::pop_iprop();
}

int GetIsSkillSuccessful(OID oTarget, int nSkill, int nDifficulty)
{
    vm::impl::push_int(nDifficulty);
    vm::impl::push_int(nSkill);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(689);
    return vm::impl::pop_int();
}

Effect EffectSpellFailure(int nPercent, int nSpellSchool)
{
    vm::impl::push_int(nSpellSchool);
    vm::impl::push_int(nPercent);
    vm::impl::call_builtin(690);
    return vm::impl::pop_effect();
}

void SpeakStringByStrRef(int nStrRef, int nTalkVolume)
{
    vm::impl::push_int(nTalkVolume);
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(691);
}

void SetCutsceneMode(OID oCreature, int nInCutscene, int nLeftClickingEnabled)
{
    vm::impl::push_int(nLeftClickingEnabled);
    vm::impl::push_int(nInCutscene);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(692);
}

OID GetLastPCToCancelCutscene()
{
    vm::impl::call_builtin(693);
    return vm::impl::pop_oid();
}

float GetDialogSoundLength(int nStrRef)
{
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(694);
    return vm::impl::pop_float();
}

void FadeFromBlack(OID oCreature, float fSpeed)
{
    vm::impl::push_float(fSpeed);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(695);
}

void FadeToBlack(OID oCreature, float fSpeed)
{
    vm::impl::push_float(fSpeed);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(696);
}

void StopFade(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(697);
}

void BlackScreen(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(698);
}

int GetBaseAttackBonus(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(699);
    return vm::impl::pop_int();
}

void SetImmortal(OID oCreature, int bImmortal)
{
    vm::impl::push_int(bImmortal);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(700);
}

void OpenInventory(OID oCreature, OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(701);
}

void StoreCameraFacing()
{
    vm::impl::call_builtin(702);
}

void RestoreCameraFacing()
{
    vm::impl::call_builtin(703);
}

int LevelUpHenchman(OID oCreature, int nClass, int bReadyAllSpells, int nPackage)
{
    vm::impl::push_int(nPackage);
    vm::impl::push_int(bReadyAllSpells);
    vm::impl::push_int(nClass);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(704);
    return vm::impl::pop_int();
}

void SetDroppableFlag(OID oItem, int bDroppable)
{
    vm::impl::push_int(bDroppable);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(705);
}

int GetWeight(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(706);
    return vm::impl::pop_int();
}

OID GetModuleItemAcquiredBy()
{
    vm::impl::call_builtin(707);
    return vm::impl::pop_oid();
}

int GetImmortal(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(708);
    return vm::impl::pop_int();
}

void DoWhirlwindAttack(int bDisplayFeedback, int bImproved)
{
    vm::impl::push_int(bImproved);
    vm::impl::push_int(bDisplayFeedback);
    vm::impl::call_builtin(709);
}

CExoString Get2DAString(CExoString s2DA, CExoString sColumn, int nRow)
{
    vm::impl::push_int(nRow);
    vm::impl::push_string(sColumn);
    vm::impl::push_string(s2DA);
    vm::impl::call_builtin(710);
    return vm::impl::pop_string();
}

Effect EffectEthereal()
{
    vm::impl::call_builtin(711);
    return vm::impl::pop_effect();
}

int GetAILevel(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(712);
    return vm::impl::pop_int();
}

void SetAILevel(OID oTarget, int nAILevel)
{
    vm::impl::push_int(nAILevel);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(713);
}

int GetIsPossessedFamiliar(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(714);
    return vm::impl::pop_int();
}

void UnpossessFamiliar(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(715);
}

int GetIsAreaInterior(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(716);
    return vm::impl::pop_int();
}

void SendMessageToPCByStrRef(OID oPlayer, int nStrRef)
{
    vm::impl::push_int(nStrRef);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(717);
}

void IncrementRemainingFeatUses(OID oCreature, int nFeat)
{
    vm::impl::push_int(nFeat);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(718);
}

void ExportSingleCharacter(OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(719);
}

void PlaySoundByStrRef(int nStrRef, int nRunAsAction)
{
    vm::impl::push_int(nRunAsAction);
    vm::impl::push_int(nStrRef);
    vm::impl::call_builtin(720);
}

void SetSubRace(OID oCreature, CExoString sSubRace)
{
    vm::impl::push_string(sSubRace);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(721);
}

void SetDeity(OID oCreature, CExoString sDeity)
{
    vm::impl::push_string(sDeity);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(722);
}

int GetIsDMPossessed(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(723);
    return vm::impl::pop_int();
}

int GetWeather(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(724);
    return vm::impl::pop_int();
}

int GetIsAreaNatural(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(725);
    return vm::impl::pop_int();
}

int GetIsAreaAboveGround(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(726);
    return vm::impl::pop_int();
}

OID GetPCItemLastEquipped()
{
    vm::impl::call_builtin(727);
    return vm::impl::pop_oid();
}

OID GetPCItemLastEquippedBy()
{
    vm::impl::call_builtin(728);
    return vm::impl::pop_oid();
}

OID GetPCItemLastUnequipped()
{
    vm::impl::call_builtin(729);
    return vm::impl::pop_oid();
}

OID GetPCItemLastUnequippedBy()
{
    vm::impl::call_builtin(730);
    return vm::impl::pop_oid();
}

OID CopyItemAndModify(OID oItem, int nType, int nIndex, int nNewValue, int bCopyVars)
{
    vm::impl::push_int(bCopyVars);
    vm::impl::push_int(nNewValue);
    vm::impl::push_int(nIndex);
    vm::impl::push_int(nType);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(731);
    return vm::impl::pop_oid();
}

int GetItemAppearance(OID oItem, int nType, int nIndex)
{
    vm::impl::push_int(nIndex);
    vm::impl::push_int(nType);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(732);
    return vm::impl::pop_int();
}

ItemProperty ItemPropertyOnHitCastSpell(int nSpell, int nLevel)
{
    vm::impl::push_int(nLevel);
    vm::impl::push_int(nSpell);
    vm::impl::call_builtin(733);
    return vm::impl::pop_iprop();
}

int GetItemPropertySubType(ItemProperty iProperty)
{
    vm::impl::push_iprop(iProperty);
    vm::impl::call_builtin(734);
    return vm::impl::pop_int();
}

int GetActionMode(OID oCreature, int nMode)
{
    vm::impl::push_int(nMode);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(735);
    return vm::impl::pop_int();
}

void SetActionMode(OID oCreature, int nMode, int nStatus)
{
    vm::impl::push_int(nStatus);
    vm::impl::push_int(nMode);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(736);
}

int GetArcaneSpellFailure(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(737);
    return vm::impl::pop_int();
}

void ActionExamine(OID oExamine)
{
    vm::impl::push_oid(oExamine);
    vm::impl::call_builtin(738);
}

ItemProperty ItemPropertyVisualEffect(int nEffect)
{
    vm::impl::push_int(nEffect);
    vm::impl::call_builtin(739);
    return vm::impl::pop_iprop();
}

void SetLootable(OID oCreature, int bLootable)
{
    vm::impl::push_int(bLootable);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(740);
}

int GetLootable(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(741);
    return vm::impl::pop_int();
}

float GetCutsceneCameraMoveRate(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(742);
    return vm::impl::pop_float();
}

void SetCutsceneCameraMoveRate(OID oCreature, float fRate)
{
    vm::impl::push_float(fRate);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(743);
}

int GetItemCursedFlag(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(744);
    return vm::impl::pop_int();
}

void SetItemCursedFlag(OID oItem, int nCursed)
{
    vm::impl::push_int(nCursed);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(745);
}

void SetMaxHenchmen(int nNumHenchmen)
{
    vm::impl::push_int(nNumHenchmen);
    vm::impl::call_builtin(746);
}

int GetMaxHenchmen()
{
    vm::impl::call_builtin(747);
    return vm::impl::pop_int();
}

int GetAssociateType(OID oAssociate)
{
    vm::impl::push_oid(oAssociate);
    vm::impl::call_builtin(748);
    return vm::impl::pop_int();
}

int GetSpellResistance(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(749);
    return vm::impl::pop_int();
}

void DayToNight(OID oPlayer, float fTransitionTime)
{
    vm::impl::push_float(fTransitionTime);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(750);
}

void NightToDay(OID oPlayer, float fTransitionTime)
{
    vm::impl::push_float(fTransitionTime);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(751);
}

int LineOfSightObject(OID oSource, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oSource);
    vm::impl::call_builtin(752);
    return vm::impl::pop_int();
}

int LineOfSightVector(Vec3 vSource, Vec3 vTarget)
{
    vm::impl::push_vec(vTarget);
    vm::impl::push_vec(vSource);
    vm::impl::call_builtin(753);
    return vm::impl::pop_int();
}

int GetLastSpellCastClass()
{
    vm::impl::call_builtin(754);
    return vm::impl::pop_int();
}

void SetBaseAttackBonus(int nBaseAttackBonus, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nBaseAttackBonus);
    vm::impl::call_builtin(755);
}

void RestoreBaseAttackBonus(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(756);
}

Effect EffectCutsceneGhost()
{
    vm::impl::call_builtin(757);
    return vm::impl::pop_effect();
}

ItemProperty ItemPropertyArcaneSpellFailure(int nModLevel)
{
    vm::impl::push_int(nModLevel);
    vm::impl::call_builtin(758);
    return vm::impl::pop_iprop();
}

int GetStoreGold(OID oidStore)
{
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(759);
    return vm::impl::pop_int();
}

void SetStoreGold(OID oidStore, int nGold)
{
    vm::impl::push_int(nGold);
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(760);
}

int GetStoreMaxBuyPrice(OID oidStore)
{
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(761);
    return vm::impl::pop_int();
}

void SetStoreMaxBuyPrice(OID oidStore, int nMaxBuy)
{
    vm::impl::push_int(nMaxBuy);
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(762);
}

int GetStoreIdentifyCost(OID oidStore)
{
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(763);
    return vm::impl::pop_int();
}

void SetStoreIdentifyCost(OID oidStore, int nCost)
{
    vm::impl::push_int(nCost);
    vm::impl::push_oid(oidStore);
    vm::impl::call_builtin(764);
}

void SetCreatureAppearanceType(OID oCreature, int nAppearanceType)
{
    vm::impl::push_int(nAppearanceType);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(765);
}

int GetCreatureStartingPackage(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(766);
    return vm::impl::pop_int();
}

Effect EffectCutsceneImmobilize()
{
    vm::impl::call_builtin(767);
    return vm::impl::pop_effect();
}

int GetIsInSubArea(OID oCreature, OID oSubArea)
{
    vm::impl::push_oid(oSubArea);
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(768);
    return vm::impl::pop_int();
}

int GetItemPropertyCostTable(ItemProperty iProp)
{
    vm::impl::push_iprop(iProp);
    vm::impl::call_builtin(769);
    return vm::impl::pop_int();
}

int GetItemPropertyCostTableValue(ItemProperty iProp)
{
    vm::impl::push_iprop(iProp);
    vm::impl::call_builtin(770);
    return vm::impl::pop_int();
}

int GetItemPropertyParam1(ItemProperty iProp)
{
    vm::impl::push_iprop(iProp);
    vm::impl::call_builtin(771);
    return vm::impl::pop_int();
}

int GetItemPropertyParam1Value(ItemProperty iProp)
{
    vm::impl::push_iprop(iProp);
    vm::impl::call_builtin(772);
    return vm::impl::pop_int();
}

int GetIsCreatureDisarmable(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(773);
    return vm::impl::pop_int();
}

void SetStolenFlag(OID oItem, int nStolenFlag)
{
    vm::impl::push_int(nStolenFlag);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(774);
}

void ForceRest(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(775);
}

void SetCameraHeight(OID oPlayer, float fHeight)
{
    vm::impl::push_float(fHeight);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(776);
}

void SetSkyBox(int nSkyBox, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nSkyBox);
    vm::impl::call_builtin(777);
}

int GetPhenoType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(778);
    return vm::impl::pop_int();
}

void SetPhenoType(int nPhenoType, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nPhenoType);
    vm::impl::call_builtin(779);
}

void SetFogColor(int nFogType, int nFogColor, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nFogColor);
    vm::impl::push_int(nFogType);
    vm::impl::call_builtin(780);
}

int GetCutsceneMode(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(781);
    return vm::impl::pop_int();
}

int GetSkyBox(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(782);
    return vm::impl::pop_int();
}

int GetFogColor(int nFogType, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nFogType);
    vm::impl::call_builtin(783);
    return vm::impl::pop_int();
}

void SetFogAmount(int nFogType, int nFogAmount, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nFogAmount);
    vm::impl::push_int(nFogType);
    vm::impl::call_builtin(784);
}

int GetFogAmount(int nFogType, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nFogType);
    vm::impl::call_builtin(785);
    return vm::impl::pop_int();
}

int GetPickpocketableFlag(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(786);
    return vm::impl::pop_int();
}

void SetPickpocketableFlag(OID oItem, int bPickpocketable)
{
    vm::impl::push_int(bPickpocketable);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(787);
}

int GetFootstepType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(788);
    return vm::impl::pop_int();
}

void SetFootstepType(int nFootstepType, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nFootstepType);
    vm::impl::call_builtin(789);
}

int GetCreatureWingType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(790);
    return vm::impl::pop_int();
}

void SetCreatureWingType(int nWingType, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nWingType);
    vm::impl::call_builtin(791);
}

int GetCreatureBodyPart(int nPart, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nPart);
    vm::impl::call_builtin(792);
    return vm::impl::pop_int();
}

void SetCreatureBodyPart(int nPart, int nModelNumber, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nModelNumber);
    vm::impl::push_int(nPart);
    vm::impl::call_builtin(793);
}

int GetCreatureTailType(OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::call_builtin(794);
    return vm::impl::pop_int();
}

void SetCreatureTailType(int nTailType, OID oCreature)
{
    vm::impl::push_oid(oCreature);
    vm::impl::push_int(nTailType);
    vm::impl::call_builtin(795);
}

int GetHardness(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(796);
    return vm::impl::pop_int();
}

void SetHardness(int nHardness, OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::push_int(nHardness);
    vm::impl::call_builtin(797);
}

void SetLockKeyRequired(OID oObject, int nKeyRequired)
{
    vm::impl::push_int(nKeyRequired);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(798);
}

void SetLockKeyTag(OID oObject, CExoString sNewKeyTag)
{
    vm::impl::push_string(sNewKeyTag);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(799);
}

void SetLockLockable(OID oObject, int nLockable)
{
    vm::impl::push_int(nLockable);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(800);
}

void SetLockUnlockDC(OID oObject, int nNewUnlockDC)
{
    vm::impl::push_int(nNewUnlockDC);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(801);
}

void SetLockLockDC(OID oObject, int nNewLockDC)
{
    vm::impl::push_int(nNewLockDC);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(802);
}

void SetTrapDisarmable(OID oTrapObject, int nDisarmable)
{
    vm::impl::push_int(nDisarmable);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(803);
}

void SetTrapDetectable(OID oTrapObject, int nDetectable)
{
    vm::impl::push_int(nDetectable);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(804);
}

void SetTrapOneShot(OID oTrapObject, int nOneShot)
{
    vm::impl::push_int(nOneShot);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(805);
}

void SetTrapKeyTag(OID oTrapObject, CExoString sKeyTag)
{
    vm::impl::push_string(sKeyTag);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(806);
}

void SetTrapDisarmDC(OID oTrapObject, int nDisarmDC)
{
    vm::impl::push_int(nDisarmDC);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(807);
}

void SetTrapDetectDC(OID oTrapObject, int nDetectDC)
{
    vm::impl::push_int(nDetectDC);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(808);
}

OID CreateTrapAtLocation(int nTrapType, Loc lLocation, float fSize, CExoString sTag, int nFaction, CExoString sOnDisarmScript, CExoString sOnTrapTriggeredScript)
{
    vm::impl::push_string(sOnTrapTriggeredScript);
    vm::impl::push_string(sOnDisarmScript);
    vm::impl::push_int(nFaction);
    vm::impl::push_string(sTag);
    vm::impl::push_float(fSize);
    vm::impl::push_loc(lLocation);
    vm::impl::push_int(nTrapType);
    vm::impl::call_builtin(809);
    return vm::impl::pop_oid();
}

void CreateTrapOnObject(int nTrapType, OID oObject, int nFaction, CExoString sOnDisarmScript, CExoString sOnTrapTriggeredScript)
{
    vm::impl::push_string(sOnTrapTriggeredScript);
    vm::impl::push_string(sOnDisarmScript);
    vm::impl::push_int(nFaction);
    vm::impl::push_oid(oObject);
    vm::impl::push_int(nTrapType);
    vm::impl::call_builtin(810);
}

void SetWillSavingThrow(OID oObject, int nWillSave)
{
    vm::impl::push_int(nWillSave);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(811);
}

void SetReflexSavingThrow(OID oObject, int nReflexSave)
{
    vm::impl::push_int(nReflexSave);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(812);
}

void SetFortitudeSavingThrow(OID oObject, int nFortitudeSave)
{
    vm::impl::push_int(nFortitudeSave);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(813);
}

CExoString GetTilesetResRef(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(814);
    return vm::impl::pop_string();
}

int GetTrapRecoverable(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(815);
    return vm::impl::pop_int();
}

void SetTrapRecoverable(OID oTrapObject, int nRecoverable)
{
    vm::impl::push_int(nRecoverable);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(816);
}

int GetModuleXPScale()
{
    vm::impl::call_builtin(817);
    return vm::impl::pop_int();
}

void SetModuleXPScale(int nXPScale)
{
    vm::impl::push_int(nXPScale);
    vm::impl::call_builtin(818);
}

CExoString GetKeyRequiredFeedback(OID oObject)
{
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(819);
    return vm::impl::pop_string();
}

void SetKeyRequiredFeedback(OID oObject, CExoString sFeedbackMessage)
{
    vm::impl::push_string(sFeedbackMessage);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(820);
}

int GetTrapActive(OID oTrapObject)
{
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(821);
    return vm::impl::pop_int();
}

void SetTrapActive(OID oTrapObject, int nActive)
{
    vm::impl::push_int(nActive);
    vm::impl::push_oid(oTrapObject);
    vm::impl::call_builtin(822);
}

void LockCameraPitch(OID oPlayer, int bLocked)
{
    vm::impl::push_int(bLocked);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(823);
}

void LockCameraDistance(OID oPlayer, int bLocked)
{
    vm::impl::push_int(bLocked);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(824);
}

void LockCameraDirection(OID oPlayer, int bLocked)
{
    vm::impl::push_int(bLocked);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(825);
}

OID GetPlaceableLastClickedBy()
{
    vm::impl::call_builtin(826);
    return vm::impl::pop_oid();
}

int GetInfiniteFlag(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(827);
    return vm::impl::pop_int();
}

void SetInfiniteFlag(OID oItem, int bInfinite)
{
    vm::impl::push_int(bInfinite);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(828);
}

int GetAreaSize(int nAreaDimension, OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::push_int(nAreaDimension);
    vm::impl::call_builtin(829);
    return vm::impl::pop_int();
}

void SetName(OID oObject, CExoString sNewName)
{
    vm::impl::push_string(sNewName);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(830);
}

int GetPortraitId(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(831);
    return vm::impl::pop_int();
}

void SetPortraitId(OID oTarget, int nPortraitId)
{
    vm::impl::push_int(nPortraitId);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(832);
}

CExoString GetPortraitResRef(OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(833);
    return vm::impl::pop_string();
}

void SetPortraitResRef(OID oTarget, CExoString sPortraitResRef)
{
    vm::impl::push_string(sPortraitResRef);
    vm::impl::push_oid(oTarget);
    vm::impl::call_builtin(834);
}

void SetUseableFlag(OID oPlaceable, int nUseableFlag)
{
    vm::impl::push_int(nUseableFlag);
    vm::impl::push_oid(oPlaceable);
    vm::impl::call_builtin(835);
}

CExoString GetDescription(OID oObject, int bOriginalDescription, int bIdentifiedDescription)
{
    vm::impl::push_int(bIdentifiedDescription);
    vm::impl::push_int(bOriginalDescription);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(836);
    return vm::impl::pop_string();
}

void SetDescription(OID oObject, CExoString sNewDescription, int bIdentifiedDescription)
{
    vm::impl::push_int(bIdentifiedDescription);
    vm::impl::push_string(sNewDescription);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(837);
}

OID GetPCChatSpeaker()
{
    vm::impl::call_builtin(838);
    return vm::impl::pop_oid();
}

CExoString GetPCChatMessage()
{
    vm::impl::call_builtin(839);
    return vm::impl::pop_string();
}

int GetPCChatVolume()
{
    vm::impl::call_builtin(840);
    return vm::impl::pop_int();
}

void SetPCChatMessage(CExoString sNewChatMessage)
{
    vm::impl::push_string(sNewChatMessage);
    vm::impl::call_builtin(841);
}

void SetPCChatVolume(int nTalkVolume)
{
    vm::impl::push_int(nTalkVolume);
    vm::impl::call_builtin(842);
}

int GetColor(OID oObject, int nColorChannel)
{
    vm::impl::push_int(nColorChannel);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(843);
    return vm::impl::pop_int();
}

void SetColor(OID oObject, int nColorChannel, int nColorValue)
{
    vm::impl::push_int(nColorValue);
    vm::impl::push_int(nColorChannel);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(844);
}

ItemProperty ItemPropertyMaterial(int nMaterialType)
{
    vm::impl::push_int(nMaterialType);
    vm::impl::call_builtin(845);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyQuality(int nQuality)
{
    vm::impl::push_int(nQuality);
    vm::impl::call_builtin(846);
    return vm::impl::pop_iprop();
}

ItemProperty ItemPropertyAdditional(int nAdditionalProperty)
{
    vm::impl::push_int(nAdditionalProperty);
    vm::impl::call_builtin(847);
    return vm::impl::pop_iprop();
}

void SetTag(OID oObject, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(848);
}

CExoString GetEffectTag(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(849);
    return vm::impl::pop_string();
}

Effect TagEffect(Effect eEffect, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(850);
    return vm::impl::pop_effect();
}

int GetEffectCasterLevel(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(851);
    return vm::impl::pop_int();
}

int GetEffectDuration(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(852);
    return vm::impl::pop_int();
}

int GetEffectDurationRemaining(Effect eEffect)
{
    vm::impl::push_effect(eEffect);
    vm::impl::call_builtin(853);
    return vm::impl::pop_int();
}

CExoString GetItemPropertyTag(ItemProperty nProperty)
{
    vm::impl::push_iprop(nProperty);
    vm::impl::call_builtin(854);
    return vm::impl::pop_string();
}

ItemProperty TagItemProperty(ItemProperty nProperty, CExoString sNewTag)
{
    vm::impl::push_string(sNewTag);
    vm::impl::push_iprop(nProperty);
    vm::impl::call_builtin(855);
    return vm::impl::pop_iprop();
}

int GetItemPropertyDuration(ItemProperty nProperty)
{
    vm::impl::push_iprop(nProperty);
    vm::impl::call_builtin(856);
    return vm::impl::pop_int();
}

int GetItemPropertyDurationRemaining(ItemProperty nProperty)
{
    vm::impl::push_iprop(nProperty);
    vm::impl::call_builtin(857);
    return vm::impl::pop_int();
}

OID CreateArea(CExoString sResRef, CExoString sNewTag, CExoString sNewName)
{
    vm::impl::push_string(sNewName);
    vm::impl::push_string(sNewTag);
    vm::impl::push_string(sResRef);
    vm::impl::call_builtin(858);
    return vm::impl::pop_oid();
}

int DestroyArea(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(859);
    return vm::impl::pop_int();
}

OID CopyArea(OID oArea)
{
    vm::impl::push_oid(oArea);
    vm::impl::call_builtin(860);
    return vm::impl::pop_oid();
}

OID GetFirstArea()
{
    vm::impl::call_builtin(861);
    return vm::impl::pop_oid();
}

OID GetNextArea()
{
    vm::impl::call_builtin(862);
    return vm::impl::pop_oid();
}

void SetTransitionTarget(OID oTransition, OID oTarget)
{
    vm::impl::push_oid(oTarget);
    vm::impl::push_oid(oTransition);
    vm::impl::call_builtin(863);
}

void SetHiddenWhenEquipped(OID oItem, int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(864);
}

int GetHiddenWhenEquipped(OID oItem)
{
    vm::impl::push_oid(oItem);
    vm::impl::call_builtin(865);
    return vm::impl::pop_int();
}

int SetTileExplored(OID creature, OID area, int x, int y, int newState)
{
    vm::impl::push_int(newState);
    vm::impl::push_int(y);
    vm::impl::push_int(x);
    vm::impl::push_oid(area);
    vm::impl::push_oid(creature);
    vm::impl::call_builtin(866);
    return vm::impl::pop_int();
}

int GetTileExplored(OID creature, OID area, int x, int y)
{
    vm::impl::push_int(y);
    vm::impl::push_int(x);
    vm::impl::push_oid(area);
    vm::impl::push_oid(creature);
    vm::impl::call_builtin(867);
    return vm::impl::pop_int();
}

int SetCreatureExploresMinimap(OID creature, int newState)
{
    vm::impl::push_int(newState);
    vm::impl::push_oid(creature);
    vm::impl::call_builtin(868);
    return vm::impl::pop_int();
}

int GetCreatureExploresMinimap(OID creature)
{
    vm::impl::push_oid(creature);
    vm::impl::call_builtin(869);
    return vm::impl::pop_int();
}

int GetSurfaceMaterial(Loc at)
{
    vm::impl::push_loc(at);
    vm::impl::call_builtin(870);
    return vm::impl::pop_int();
}

float GetGroundHeight(Loc at)
{
    vm::impl::push_loc(at);
    vm::impl::call_builtin(871);
    return vm::impl::pop_float();
}

int GetAttackBonusLimit()
{
    vm::impl::call_builtin(872);
    return vm::impl::pop_int();
}

int GetDamageBonusLimit()
{
    vm::impl::call_builtin(873);
    return vm::impl::pop_int();
}

int GetSavingThrowBonusLimit()
{
    vm::impl::call_builtin(874);
    return vm::impl::pop_int();
}

int GetAbilityBonusLimit()
{
    vm::impl::call_builtin(875);
    return vm::impl::pop_int();
}

int GetAbilityPenaltyLimit()
{
    vm::impl::call_builtin(876);
    return vm::impl::pop_int();
}

int GetSkillBonusLimit()
{
    vm::impl::call_builtin(877);
    return vm::impl::pop_int();
}

void SetAttackBonusLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(878);
}

void SetDamageBonusLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(879);
}

void SetSavingThrowBonusLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(880);
}

void SetAbilityBonusLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(881);
}

void SetAbilityPenaltyLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(882);
}

void SetSkillBonusLimit(int nNewLimit)
{
    vm::impl::push_int(nNewLimit);
    vm::impl::call_builtin(883);
}

int GetIsPlayerConnectionRelayed(OID oPlayer)
{
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(884);
    return vm::impl::pop_int();
}

CExoString GetEventScript(OID oObject, int nHandler)
{
    vm::impl::push_int(nHandler);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(885);
    return vm::impl::pop_string();
}

int SetEventScript(OID oObject, int nHandler, CExoString sScript)
{
    vm::impl::push_string(sScript);
    vm::impl::push_int(nHandler);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(886);
    return vm::impl::pop_int();
}

float GetObjectVisualTransform(OID oObject, int nTransform)
{
    vm::impl::push_int(nTransform);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(887);
    return vm::impl::pop_float();
}

float SetObjectVisualTransform(OID oObject, int nTransform, float fValue)
{
    vm::impl::push_float(fValue);
    vm::impl::push_int(nTransform);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(888);
    return vm::impl::pop_float();
}

void SetMaterialShaderUniformInt(OID oObject, CExoString sMaterial, CExoString sParam, int nValue)
{
    vm::impl::push_int(nValue);
    vm::impl::push_string(sParam);
    vm::impl::push_string(sMaterial);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(889);
}

void SetMaterialShaderUniformVec4(OID oObject, CExoString sMaterial, CExoString sParam, float fValue1, float fValue2, float fValue3, float fValue4)
{
    vm::impl::push_float(fValue4);
    vm::impl::push_float(fValue3);
    vm::impl::push_float(fValue2);
    vm::impl::push_float(fValue1);
    vm::impl::push_string(sParam);
    vm::impl::push_string(sMaterial);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(890);
}

void ResetMaterialShaderUniforms(OID oObject, CExoString sMaterial, CExoString sParam)
{
    vm::impl::push_string(sParam);
    vm::impl::push_string(sMaterial);
    vm::impl::push_oid(oObject);
    vm::impl::call_builtin(891);
}

void Vibrate(OID oPlayer, int nMotor, float fStrength, float fSeconds)
{
    vm::impl::push_float(fSeconds);
    vm::impl::push_float(fStrength);
    vm::impl::push_int(nMotor);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(892);
}

void UnlockAchievement(OID oPlayer, CExoString sId, int nLastValue, int nCurValue, int nMaxValue)
{
    vm::impl::push_int(nMaxValue);
    vm::impl::push_int(nCurValue);
    vm::impl::push_int(nLastValue);
    vm::impl::push_string(sId);
    vm::impl::push_oid(oPlayer);
    vm::impl::call_builtin(893);
}

}