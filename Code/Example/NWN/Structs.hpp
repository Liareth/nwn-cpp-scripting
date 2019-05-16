#pragma once

#include <math.h>
#include <stdint.h>
#include <string.h>

namespace nwn
{

namespace impl
{

template <int size, int desiredSize>
struct CheckSize { static_assert(size == desiredSize, "Struct size mismatch!"); };

#define CHECK_SIZE_CAT2(x, y) x##y
#define CHECK_SIZE_CAT1(x, y) CHECK_SIZE_CAT2(x, y)
#define CHECK_SIZE(type, size) \
    namespace { ::nwn::impl::CheckSize<sizeof(type), size> CHECK_SIZE_CAT1(check_size_, __COUNTER__); }

}

using OID = uint32_t;

struct CNWSAnimBase;
struct CNWSArea;
struct CNWSDialog;
struct CScriptLog;
struct CTlkTable;
struct CVirtualMachine;
struct CVirtualMachineCache;
using CVirtualMachineFile = char[44];

template <typename T>
struct CExoArrayList
{
    T* element;
    int32_t num;
    int32_t array_size;
}; CHECK_SIZE(CExoArrayList<void>, 12);

struct CExoLinkedListNode
{
    CExoLinkedListNode* pPrev;
    CExoLinkedListNode* pNext;
    void* pObject;
}; CHECK_SIZE(CExoLinkedListNode, 12);

struct CExoLinkedListInternal
{
    CExoLinkedListNode* pHead;
    CExoLinkedListNode* pTail;
    uint32_t m_nCount;
}; CHECK_SIZE(CExoLinkedListInternal, 12);

template <typename T>
struct CExoLinkedList
{
    CExoLinkedListInternal* m_pcExoLinkedListInternal;
}; CHECK_SIZE(CExoLinkedList<void>, 4);

struct CExoString
{
    char* m_sString;
    uint32_t m_nBufferLength;

    CExoString();
    CExoString(const char* str);
    CExoString(const CExoString& other);
    CExoString& operator=(const CExoString& other);
    ~CExoString();
}; CHECK_SIZE(CExoString, 8);

struct ExoLocString
{
    int32_t nID;
    CExoString sString;
}; // no reference

struct CExoLocStringInternal
{
    CExoLinkedList<ExoLocString> m_lstString;
    uint32_t m_nStringCount;
}; CHECK_SIZE(CExoLocStringInternal, 8);

struct CExoLocString
{
    CExoLocStringInternal* m_pExoLocStringInternal;
    uint32_t m_dwStringRef;
}; CHECK_SIZE(CExoLocString, 8);

struct Vec3
{
    float x;
    float y;
    float z;
}; CHECK_SIZE(Vec3, 12);

inline Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

inline Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

inline Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

inline float dot(const Vec3& lhs, const Vec3& rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

inline Vec3 cross(const Vec3& lhs, const Vec3& rhs)
{
    return 
    {
        (lhs.y * rhs.z) - (lhs.z * rhs.y),
        (lhs.z * rhs.x) - (lhs.x * rhs.z),
        (lhs.x * rhs.y) - (lhs .y * rhs.x)
    };
}

inline float magnitudeSqr(const Vec3& lhs)
{
    return dot(lhs, lhs);
}

inline float magnitude(const Vec3& lhs)
{
    return sqrtf(magnitudeSqr(lhs));
}

struct CVirtualMachineStack
{
    int32_t m_nStackPointer;
    int32_t m_nBasePointer;
    int32_t m_nTotalSize;
    char* m_pchStackTypes;
    int32_t* m_pStackNodes;
    CVirtualMachine* m_pVMachine;
}; CHECK_SIZE(CVirtualMachineStack, 24);

struct CVirtualMachineScript
{
    CVirtualMachineStack* m_pStack;
    int32_t m_nStackSize;
    int32_t m_nInstructPtr;
    int32_t m_nSecondaryInstructPtr;
    char* m_pCode;
    int32_t m_nCodeSize;
    CExoString m_sScriptName;
    int32_t m_nLoadedFromSave;
}; CHECK_SIZE(CVirtualMachineScript, 36);

struct CVirtualMachineCmdImplementer
{
    void** m_vtable;
    int32_t m_bValidObjectRunScript;
    uint32_t m_oidObjectRunScript;
}; // no reference

struct CNWVirtualMachineCommands : public CVirtualMachineCmdImplementer
{
    void* m_pVirtualMachineCommands;
};  CHECK_SIZE(CNWVirtualMachineCommands, 16); // no reference

struct CVirtualMachine
{
    int32_t m_nReturnValueParameterType;
    void* m_pReturnValue;
    uint32_t m_nInstructionsExecuted;
    int32_t m_nRecursionLevel;
    CVirtualMachineScript m_pVirtualMachineScript[8];
    int32_t m_bValidObjectRunScript[8];
    uint32_t m_oidObjectRunScript[8];
    CVirtualMachineStack m_cRunTimeStack;
    int32_t m_nInstructPtrLevel;
    int32_t m_pnRunTimeInstructPtr[128];
    int32_t m_nSecondaryInstructionPointer;
    int32_t m_nStackSizeToSave;
    int32_t m_nBaseStackSizeToSave;
    CVirtualMachineCmdImplementer* m_pCmdImplementer;
    int32_t m_bDebugGUIRequired;
    int32_t m_bDebuggerSpawned;
    CVirtualMachineFile m_cVMFile;
    CVirtualMachineCache* m_pCache;
    CScriptLog* m_pLog;
    CExoArrayList<CScriptLog*> m_aScriptLog;
    int32_t m_bEnableScriptLogging;
    int32_t m_bEnableScriptProfiling;
    uint32_t m_nScriptStartTime;
    uint32_t m_nScriptEndTime;
    uint32_t m_nInstructionLimit;
}; CHECK_SIZE(CVirtualMachine, 1016);

struct CGameEffect
{
    uint64_t m_nID;
    uint16_t m_nType;
    uint16_t m_nSubType;
    float m_fDuration;
    uint32_t m_nExpiryCalendarDay;
    uint32_t m_nExpiryTimeOfDay;
    OID m_oidCreator;
    uint32_t m_nSpellId;
    int32_t m_bExpose;
    int32_t m_bShowIcon;
    int32_t m_nCasterLevel;
    CGameEffect* m_pLinkLeft;
    CGameEffect* m_pLinkRight;
    int32_t m_nNumIntegers;
    int32_t* m_nParamInteger;
    float m_nParamFloat[4];
    CExoString m_sParamString[6];
    OID m_oidParamObjectID[4];
    int32_t m_bSkipOnLoad;
    uint64_t m_nItemPropertySourceId;
    CExoString m_sCustomTag;
}; CHECK_SIZE(CGameEffect, 160);

struct CScriptEvent
{
    uint16_t m_nType;
    CExoArrayList<int> m_nParamInteger;
    CExoArrayList<float> m_fParamFloat;
    CExoArrayList<CExoString> m_sParamString;
    CExoArrayList<OID> m_oidParamObjectID;
}; CHECK_SIZE(CScriptEvent, 52);

static_assert(sizeof(CScriptEvent) == 52);

struct CScriptLocation
{
    Vec3 m_vPosition;
    Vec3 m_vOrientation;
    OID m_oArea;
}; CHECK_SIZE(CScriptLocation, 28);

struct CScriptTalent
{
    int32_t m_nType;
    int32_t m_nID;
    uint8_t m_nMultiClass;
    OID m_oidItem;
    int32_t m_nItemPropertyIndex;
    uint8_t m_nCasterLevel;
    uint8_t m_nMetaType;
}; CHECK_SIZE(CScriptTalent, 24);

struct CNWSObjectActionNode
{
    uint32_t m_nActionId;
    uint32_t m_nParamType[12];
    void* m_pParameter[12];
    uint16_t m_nGroupActionId;
    uint16_t m_nParameters;
    int32_t m_bInterruptable;
}; CHECK_SIZE(CNWSObjectActionNode, 108);

struct CGameObject
{
    void** m_vtable;
    OID m_idSelf;
    uint8_t m_nObjectType;
    void* m_pNwnxData;
}; CHECK_SIZE(CGameObject, 16);

struct CResRef
{
    char m_resRefLowerCase[16];
    char m_resRef[16];
}; CHECK_SIZE(CResRef, 32);

struct CNWSScriptVar
{
    CExoString m_sName;
    uint32_t m_nType;
    void* m_pValue;
}; // no reference

struct CNWSCreature;

struct CNWSScriptVarTable
{
    CExoArrayList<CNWSScriptVar> m_lVarList;
    CNWSCreature* m_pCreature;
}; CHECK_SIZE(CNWSScriptVarTable, 16);

struct CNWSTransition
{
    CExoString m_sTransitionTarget;
    uint32_t m_oidCachedTransitionTarget;
}; CHECK_SIZE(CNWSTransition, 12);

struct ObjectVisualTransformData
{
    Vec3 m_scale;
    Vec3 m_rotate;
    Vec3 m_translate;
    float m_animationSpeed;
}; // no reference

struct MaterialShaderParam
{
    enum Type
    {
        Unset = 0,
        Int = 1,
        Vec4 = 2
    };

    Type m_nType;
    char m_sMaterialName[17];
    char m_sParamName[65];
    uint8_t _padding[2];
    int32_t m_nValue;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
}; // no reference

struct CLoopingVisualEffect;
struct CNWSExpression;

struct CNWSObject : public CGameObject
{
    CExoLocString m_sForGCC;
    uint16_t m_nGroupID;
    uint16_t m_nLastGroupID;
    CExoString m_sTag;
    CExoString m_sTemplate;
    CResRef m_cPortrait;
    uint16_t m_nPortraitId;
    CNWSDialog* m_pDialog;
    uint32_t m_nDialogDelayCalendar;
    uint32_t m_nDialogDelayTimeOfDay;
    int32_t m_bDialogStored;
    uint32_t m_nDialogStoredEntry;
    int32_t m_bDialogPaused;
    OID m_oidDialogOwner;
    int32_t m_nDialogAnimation;
    int32_t m_nAILevel;
    int32_t m_bLock;
    CExoLinkedListNode* m_pAIPosList;
    uint16_t m_nCurrentAction;
    uint32_t m_oidCurrentActionTarget;
    CNWSAnimBase* m_pAnimation;
    uint32_t m_oidArea;
    Vec3 m_vPosition;
    Vec3 m_vOrientation;
    uint32_t m_nLastUpdateCalendarDay;
    uint32_t m_nLastUpdateTimeOfDay;
    uint32_t m_nStartActionCalendarDay;
    uint32_t m_nStartActionTimeOfDay;
    uint32_t m_nLastAnimationCalendarDay;
    uint32_t m_nLastAnimationTimeOfDay;
    uint32_t m_nAIUpdateDifference;
    int32_t m_nAnimation;
    float m_fAnimSpeed;
    int32_t m_nCurrentHitPoints;
    int32_t m_nBaseHitPoints;
    int32_t m_nTemporaryHitPoints;
    int32_t m_bAbleToModifyActionQueue;
    int32_t m_bDestroyable;
    int32_t m_bRaiseable;
    int32_t m_bSelectableWhenDead;
    int32_t m_bPlotObject;
    CExoLinkedList<CNWSObjectActionNode> m_lQueuedActions;
    CNWSScriptVarTable m_ScriptVars;
    CExoArrayList<CGameEffect*> m_appliedEffects;
    CExoArrayList<CLoopingVisualEffect*> m_lstLoopingVisualEffects;
    CExoArrayList<OID> m_lstEffectTargets;
    int32_t m_bPendingEffectRemoval;
    uint32_t m_nSavingThrowSpellId;
    int32_t m_nCustomScriptEventId;
    uint32_t m_oidKiller;
    uint32_t m_oidLastHostileActor;
    uint32_t m_oidLastAttacker;
    uint32_t m_oidLastDamager;
    uint32_t m_oidLastDisturbed;
    int32_t* m_pLastDamageList;
    uint16_t m_nLastAttackType;
    uint8_t m_nLastAttackMode;
    uint32_t m_oidLastWeaponAttackedWith;
    uint32_t m_oidInventoryDisturbItem;
    int32_t m_nInventoryDisturbType;
    uint32_t m_oidLastSpeaker;
    int32_t m_bPrivateConversation;
    int32_t m_nConversationPlayHello;
    CExoString m_sLastConversationResref;
    CExoArrayList<CNWSExpression> m_aListenExpressions;
    int32_t m_nMatchedPos;
    int32_t m_bListening;
    CExoArrayList<CExoString*> m_aExpressionStrings;
    char* m_nDamageImmunity;
    Vec3 m_vLastSpellTarget;
    uint32_t m_oidLastSpellTarget;
    uint32_t m_nLastSpellId;
    uint8_t m_nLastDomainLevel;
    uint32_t m_nLastSpellProjectileTime;
    int32_t m_bLastSpellCast;
    int32_t m_bLastSpellCastSpontaneous;
    uint8_t m_nLastSpellCastMulticlass;
    uint8_t m_nLastSpellCastMetaType;
    uint32_t m_oidLastSpellCastAtMeCaster;
    uint32_t m_nLastSpellCastAtMe;
    int32_t m_bLastSpellCastAtMeHarmful;
    uint16_t m_nLastSpellCastFeat;
    CNWSObjectActionNode* m_pExecutingAIAction;
    uint16_t m_nEffectArrayIndex;
    int32_t m_bApplyingPostProcessEffects;
    int32_t m_bOpenDoorAnimationPlayed;
    CNWSTransition m_pTransition;
    ObjectVisualTransformData m_pVisualTransformData;
    CExoArrayList<MaterialShaderParam> m_lMaterialShaderParameters;
}; CHECK_SIZE(CNWSObject, 532);

struct CNWSQuickbarButton
{
    uint32_t m_oidItem;
    uint32_t m_oidSecondaryItem;
    uint8_t m_nObjectType;
    uint8_t m_nMultiClass;
    CResRef m_cResRef;
    CExoString m_sCommandLabel;
    CExoString m_sCommandLine;
    CExoString m_sToolTip;
    int32_t m_nINTParam1;
    uint8_t m_nMetaType;
    uint8_t m_nDomainLevel;
    uint16_t m_nAssociateType;
    uint32_t m_oidAssociate;
}; // no reference

struct CNWActionNode
{
    uint16_t nGroupId;
    uint16_t nActionId;
    uint16_t nSpecialAttackId;
    uint32_t nSpellId;
    Vec3 vTargetPos;
    uint32_t oidTarget;
}; // no reference

struct CNWSInvitationDetails
{
    uint32_t m_oidCreature;
    uint32_t m_nCalenderDay;
    uint32_t m_nTimeOfDay;
}; // no reference

struct CNWSInventory
{
    void** m_vtable;
    OID m_pEquipSlot[18];
}; CHECK_SIZE(CNWSInventory, 76);

struct CItemRepository
{
    uint8_t m_nWidth;
    uint8_t m_nHeight;
    uint32_t m_nBoundary;
    OID m_oidParent;
    int32_t m_bScalable;
    CExoLinkedList<OID> m_oidItems;
}; CHECK_SIZE(CItemRepository, 20);

struct CNWSCreatureAppearanceInfo
{
    uint32_t m_oidLeftHandItem;
    uint32_t m_oidRightHandItem;
    uint8_t m_nRightHandItemVFX;
    uint8_t m_nLeftHandItemVFX;
    uint32_t m_oidChestItem;
    uint32_t m_oidHeadItem;
    uint16_t m_nAppearanceType;
    uint8_t m_nPhenoType;
    uint8_t m_nGender;
    uint8_t m_nSkinColor;
    uint8_t m_nHairColor;
    uint8_t m_nTattooColor1;
    uint8_t m_nTattooColor2;
    uint8_t m_pPartVariation[19];
    uint8_t m_nHeadVariation;
    uint32_t m_nTailVariation;
    uint32_t m_nWingVariation;
    int32_t m_bForceArmorAppearanceUpdate;
    uint32_t m_oidCloakItem;
    ObjectVisualTransformData m_pRightHandItemVisualTransform;
    ObjectVisualTransformData m_pLeftHandItemVisualTransform;
}; // no reference

struct CFeatUseListEntry
{
    uint16_t m_nFeat;
    uint8_t m_nUsedToday;
}; // no reference

struct CNWLevelStats
{
    CExoArrayList<uint32_t> m_pAddedKnownSpellList[10];
    CExoArrayList<uint32_t> m_pRemovedKnownSpellList[10];
    CExoArrayList<uint16_t> m_lstFeats;
    char* m_lstSkillRanks;
    uint16_t m_nSkillPointsRemaining;
    uint8_t m_nAbilityGain;
    uint8_t m_nHitDie;
    uint8_t m_nClass;
    int32_t m_bEpic;
}; CHECK_SIZE(CNWLevelStats, 268);

struct CCombatInformationNode
{
    char m_nModifier;
    uint8_t m_nModifierType;
    uint8_t m_nWeaponWield;
    uint8_t m_nVersusAlignLawChaos;
    uint8_t m_nVersusAlignGoodEvil;
    uint8_t m_nVersusRace;
}; CHECK_SIZE(CCombatInformationNode, 6);

struct CCombatInformation
{
    uint8_t m_nNumAttacks;
    char m_nOnHandAttackModifier;
    char m_nOnHandDamageModifier;
    char m_nOffHandAttackModifier;
    char m_nOffHandDamageModifier;
    uint8_t m_nSpellResistance;
    uint8_t m_nArcaneSpellFailure;
    uint8_t m_nArmorCheckPenalty;
    uint8_t m_nUnarmedDamageDice;
    uint8_t m_nUnarmedDamageDie;
    uint8_t m_nCreatureDamageDice[3];
    uint8_t m_nCreatureDamageDie[3];
    char m_nCreatureDamageModifier[3];
    uint8_t m_nOnHandCriticalHitRange;
    uint8_t m_nOnHandCriticalHitMultiplier;
    int32_t m_bOffHandWeaponEquipped;
    uint8_t m_nOffHandCriticalHitRange;
    uint8_t m_nOffHandCriticalHitMultiplier;
    CExoArrayList<CCombatInformationNode*> m_pAttackList;
    CExoArrayList<CCombatInformationNode*> m_pDamageList;
    uint32_t m_oidRightEquipped;
    uint32_t m_oidLeftEquipped;
    CExoString m_sRightEquipped;
    CExoString m_sLeftEquipped;
    uint8_t m_nDamageDice;
    uint8_t m_nDamageDie;
}; CHECK_SIZE(CCombatInformation, 84);

struct CNWSStats_Spell
{
    uint32_t m_nSpellId;
    int32_t m_bReadied;
    uint8_t m_nMetaType;
    int32_t m_bDomainSpell;
}; CHECK_SIZE(CNWSStats_Spell, 16);

struct CNWSCreatureStats_ClassInfo
{
    CExoArrayList<uint32_t> m_pKnownSpellList[10];
    CExoArrayList<CNWSStats_Spell> m_pMemorizedSpellList[10];
    uint32_t m_nBonusSpellsList[10];
    uint8_t m_nSpellsPerDayLeft[10];
    uint8_t m_nMaxSpellsPerDayLeft[10];
    uint8_t m_nClass;
    uint8_t m_nLevel;
    uint8_t m_nNegativeLevels;
    uint8_t m_nSchool;
    uint8_t m_nDomain[2];
    int32_t m_bHasLostClassAbilities;
}; CHECK_SIZE(CNWSCreatureStats_ClassInfo, 312);

struct CNWSStats_SpellLikeAbility
{
    uint32_t m_nSpellId;
    int32_t m_bReadied;
    uint8_t m_nCasterLevel;
}; CHECK_SIZE(CNWSStats_SpellLikeAbility, 12);

struct CNWSCreatureStats
{
    CExoArrayList<uint16_t> m_lstFeats;
    CExoArrayList<CFeatUseListEntry*> m_lstFeatUses;
    CExoArrayList<uint16_t> m_lstBonusFeats;
    CNWSCreature* m_pBaseCreature;
    CExoArrayList<CNWLevelStats*> m_lstLevelStats;
    CExoLocString m_lsFirstName;
    CExoLocString m_lsLastName;
    CResRef m_cDialog;
    int32_t m_bDialogInterruptable;
    CExoLocString m_sDescription;
    CExoString m_sDescriptionOverride;
    int32_t m_nAge;
    uint8_t m_nGender;
    uint32_t m_nExperience;
    int32_t m_bIsPC;
    int32_t m_bIsDM;
    int32_t m_bIsDMFile;
    int32_t m_bIsAIDisabledPossess;
    int32_t m_bIsAIDisabledOverride;
    int32_t m_bDMManifested;
    uint8_t m_nMultiClassLeveledUpIn;
    int32_t m_nFactionId;
    int32_t m_nOriginalFactionId;
    int32_t m_nPreDominationFactionId;
    float m_fChallengeRating;
    uint8_t m_nStartingPackage;
    uint8_t m_nNumMultiClasses;
    CNWSCreatureStats_ClassInfo m_ClassInfo[3];
    uint16_t m_nRace;
    CExoString m_sSubRace;
    uint8_t m_nStrengthBase;
    char m_nStrengthModifier;
    uint8_t m_nDexterityBase;
    char m_nDexterityModifier;
    uint8_t m_nConstitutionBase;
    char m_nConstitutionModifier;
    uint8_t m_nIntelligenceBase;
    char m_nIntelligenceModifier;
    uint8_t m_nWisdomBase;
    char m_nWisdomModifier;
    uint8_t m_nCharismaBase;
    char m_nCharismaModifier;
    char m_nACNaturalBase;
    char m_nACArmorBase;
    char m_nACShieldBase;
    char m_nACArmorMod;
    char m_nACArmorNeg;
    char m_nACDeflectionMod;
    char m_nACDeflectionNeg;
    char m_nACShieldMod;
    char m_nACShieldNeg;
    char m_nACNaturalMod;
    char m_nACNaturalNeg;
    char m_nACDodgeMod;
    char m_nACDodgeNeg;
    uint8_t m_nBaseAttackBonus;
    uint8_t m_nOverrideBaseAttackBonus;
    char m_nEnemyAttackBonus;
    char* m_nDamageImmunity;
    int32_t m_nDamageRoll;
    int32_t m_nCriticalHitRoll;
    int32_t m_nCriticalHitMultiplier;
    uint8_t m_nAttacksPerRound;
    CCombatInformation* m_pCombatInformation;
    char m_nArcaneSpellFailure;
    uint8_t m_nBaseArmorArcaneSpellFailure;
    uint8_t m_nBaseShieldArcaneSpellFailure;
    uint8_t m_pSpellFailure[9];
    char m_nSpellResistance;
    char m_nSpellResistancePenalty;
    CExoArrayList<CNWSStats_SpellLikeAbility>* m_pSpellLikeAbilityList;
    uint16_t m_nTempHitpointsPtr;
    uint16_t m_nACVersusPtr;
    uint16_t m_nAttackBonusPtr;
    uint16_t m_nDamageReductionPtr;
    uint16_t m_nDamageResistancePtr;
    uint16_t m_nDamageBonusPtr;
    uint16_t m_nAIStatePtr;
    uint16_t m_nEffectIconPtr;
    uint16_t m_nSanctuaryPtr;
    uint16_t m_nInvisibilityPtr;
    uint16_t m_nSpellResistancePtr;
    uint16_t m_nAbilityPtr;
    uint16_t m_nSeeInvisiblePtr;
    uint16_t m_nUltraVisionPtr;
    uint16_t m_nMissChancePtr;
    uint16_t m_nConcealmentPtr;
    uint16_t m_nBlindnessPtr;
    uint16_t m_nWalkAnimationPtr;
    uint16_t m_nSpellLevelAbsorptionPtr;
    uint16_t m_nSpellImmunityPtr;
    uint16_t m_nDamageShieldPtr;
    uint16_t m_nSkillBonusPtr;
    uint16_t m_nSavingThrowBonusPtr;
    uint16_t m_nHastePtr;
    uint16_t m_nEffectImmunityPtr;
    uint16_t m_nLimitMovementSpeedPtr;
    uint16_t m_nMovementSpeedDecreasePtr;
    uint16_t m_nSkillPointsRemaining;
    char* m_lstSkillRanks;
    char m_nArmorCheckPenalty;
    char m_nShieldCheckPenalty;
    CResRef m_cPortrait;
    int16_t m_nAlignmentGoodEvil;
    int16_t m_nAlignmentLawChaos;
    uint8_t m_nSkinColor;
    uint8_t m_nHairColor;
    uint8_t m_nTattoo1Color;
    uint8_t m_nTattoo2Color;
    uint16_t m_nAppearanceType;
    uint8_t m_nPhenoType;
    uint8_t m_nHeadVariation;
    uint8_t m_pPartVariation[19];
    uint32_t m_nTailVariation;
    uint32_t m_nWingVariation;
    int32_t m_nMovementRate;
    float m_fMovementRunSpeed;
    float m_fMovementWalkSpeed;
    char m_nFortSavingThrowMisc;
    char m_nWillSavingThrowMisc;
    char m_nReflexSavingThrowMisc;
    int32_t m_nAnimalCompanionCreatureType;
    int32_t m_nFamiliarCreatureType;
    CExoString m_sAnimalCompanionName;
    CExoString m_sFamiliarName;
    CExoString m_sDeity;
}; CHECK_SIZE(CNWSCreatureStats, 1384);

struct CPathfindInformation;
struct CEffectIconObject;
struct CNWSCombatRound;
struct CNWSJournal;
struct CNWSBarter;
struct CNWSPersonalReputation;
struct CNWSPVPEntry;

struct CNWVisibilityNode
{
    uint32_t m_oidCreature;
    uint8_t m_bSeen : 1;
    uint8_t m_bHeard : 1;
    uint8_t m_nSanctuary : 2;
    uint8_t m_bInvisible : 1;
}; // no reference

struct CNWSCreature : public CNWSObject
{
    int32_t m_bPonyRide;
    uint16_t m_nEquipArrayIndex;
    OID m_poidCntrSpellObjects[10];
    int32_t m_nNumCntrSpellObjects;
    CExoString m_sScripts[13];
    CExoString m_sOriginalScripts[13];
    CNWSQuickbarButton* m_pQuickbarButton;
    int32_t m_bLootable;
    uint32_t m_nDecayTime;
    OID m_oidBodyBag;
    OID m_oidDesiredArea;
    Vec3 m_vDesiredAreaLocation;
    int32_t m_bDesiredAreaUpdateComplete;
    CExoArrayList<OID> m_aLinkedAreaOfEffectObjects;
    CExoArrayList<OID> m_aInSubAreas;
    uint32_t m_oidBlockingDoor;
    CPathfindInformation* m_pcPathfindInformation;
    float m_fMovementScaleFactor;
    int32_t m_bUpdateCombatInformation;
    int32_t m_nNumCharSheetViewers;
    int32_t m_bUpdateSpellSlots;
    int32_t m_bOnCreationScriptExecuted;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nHeartbeatInterval;
    uint32_t m_nLastRestRadiusCheckDay;
    uint32_t m_nLastRestRadiusCheckTimeOfDay;
    uint32_t m_oidLastTrapDetected;
    uint32_t m_nLastTrapCheckCalendarDay;
    uint32_t m_nLastTrapCheckTimeOfDay;
    uint32_t m_nLastStealthCheckCalendarDay;
    uint32_t m_nLastStealthCheckTimeOfDay;
    uint32_t m_nExcitedStateTimer;
    uint32_t m_nLastVisibleCreaturesCheckCalendarDay;
    uint32_t m_nLastVisibleCreaturesCheckTimeOfDay;
    int32_t m_nChecksVisibleList;
    uint32_t m_nChecksHeartbeat;
    uint32_t m_nMoveSpeedTimer;
    int32_t m_bPendingRealization;
    uint8_t m_nPersonalReputationHeartbeatCount;
    int32_t m_nLastActionQueueUpdateDay;
    int32_t m_nLastActionQueueUpdateTimeOfDay;
    CNWActionNode m_pActionQueue[10];
    uint8_t m_nAmbientAnimationState;
    CExoString m_sModelType;
    CExoArrayList<OID> m_oidAutoMapAreaList;
    uint8_t** m_nAutoMapTileData;
    int32_t m_bAutoMapAutoExplores;
    uint8_t m_nLastExploredTileX;
    uint8_t m_nLastExploredTileY;
    uint32_t oidLastExploredArea;
    uint8_t m_nDetectMode;
    uint8_t m_nStealthMode;
    uint8_t m_nDefensiveCastingMode;
    uint8_t m_nCombatMode;
    uint8_t m_nDesiredCombatMode;
    uint32_t m_oidCounterSpellTarget;
    uint8_t m_nInitiativeRoll;
    int32_t m_bInitiativeExpired;
    int32_t m_bCombatState;
    int32_t m_nCombatStateTimer;
    int32_t m_bPassiveAttackBehaviour;
    int32_t m_bHasArms;
    int32_t m_bHasLegs;
    int32_t m_bDisarmable;
    int32_t m_nCreatureSize;
    float m_fPreferredAttackDistance;
    float m_fWeaponScale;
    uint32_t m_oidAttackTarget;
    uint32_t m_oidAttemptedAttackTarget;
    Vec3 m_vLastAttackPosition;
    uint32_t m_oidGoingToBeAttackedBy;
    uint32_t m_oidAttemptedSpellTarget;
    uint32_t m_oidSpellTarget;
    int32_t m_nLastAmmoWarning;
    int32_t m_nLastCombatRoundUpdate;
    int32_t m_nLastRunningAOOUpdate;
    int32_t m_bBroadcastedAOOTo;
    int32_t m_nLastRunningAOOTimeOut;
    int32_t m_bExternalCombatModeEnabled;
    int32_t m_bSilent;
    int32_t m_bHasted;
    int32_t m_bSlowed;
    int32_t m_bTaunt;
    int32_t m_bForcedWalk;
    uint8_t m_nVisionType;
    uint8_t m_nState;
    uint32_t m_nEffectSpellId;
    CExoArrayList<CEffectIconObject*> m_aEffectIcons;
    int32_t m_bCutsceneCameraMode;
    float m_fCutsceneCameraMoveFactor;
    int32_t m_bWasPlotCreature;
    int32_t m_bCutsceneGhost;
    uint32_t m_oidLastPerception;
    int32_t m_bLastPerceptionHeard;
    int32_t m_bLastPerceptionSeen;
    int32_t m_bLastPerceptionInaudible;
    int32_t m_bLastPerceptionVanished;
    float m_fSpotCheckDistance;
    float m_fMaxSpotCheckDistance;
    float m_fListenCheckDistance;
    float m_fMaxListenCheckDistance;
    float m_fBlindsightDistance;
    uint8_t m_nLastHideRoll;
    uint8_t m_nLastMoveSilentlyRoll;
    uint8_t m_nLastSpotRoll;
    uint8_t m_nLastListenRoll;
    CExoArrayList<CNWVisibilityNode*> m_pVisibleCreaturesList;
    uint32_t m_oidInvitedToPartyBy;
    int32_t m_bInvitedToParty;
    uint32_t m_nInvitedToPartyDay;
    uint32_t m_nInvitedToPartyTimeOfDay;
    CExoArrayList<CNWSInvitationDetails>* m_pInvitationsOffered;
    CExoArrayList<CNWSInvitationDetails>* m_pInvitationsIgnored;
    uint32_t m_oidLockOnTargetObj;
    int32_t m_nLastCounterSpellID;
    uint8_t m_nLastCounterSpellClass;
    uint8_t m_nLastCounterMetaType;
    uint8_t m_nLastCounterDomainLevel;
    CExoArrayList<OID> m_poidSpellIdentified;
    uint32_t m_oidLastSpellCastItem;
    int32_t m_bLastSpellUnReadied;
    int32_t m_bLastItemCastSpell;
    int32_t m_nLastItemCastSpellLevel;
    int32_t m_bItemCastSpellBroadcastAOO;
    uint32_t m_oidSittingObject;
    int32_t m_bStealAnimationPlayed;
    int32_t m_bStealAttemptDetected;
    int32_t m_bHealAnimationPlayed;
    int32_t m_bTrapAnimationPlayed;
    int32_t m_bUnlockAnimationPlayed;
    int32_t m_bLockAnimationPlayed;
    int32_t m_bDropItemAnimationPlayed;
    int32_t m_bPickUpItemAnimationPlayed;
    int32_t m_bTauntAnimationPlayed;
    uint32_t m_nRestDurationPerHPGain;
    uint32_t m_nRestHPToRecover;
    uint32_t m_nRestDurationPerSpellLevelGain;
    uint32_t m_nRestSpellLevelToRecover;
    int32_t m_bFacingAndAnimationDone;
    int32_t m_bMagicalArrowsEquipped;
    int32_t m_bMagicalBoltsEquipped;
    int32_t m_bMagicalBulletsEquipped;
    uint32_t* m_pSkillTimer;
    CNWSCombatRound* m_pcCombatRound;
    CNWSJournal* m_pJournal;
    CNWSBarter* m_pBarterInfo;
    uint32_t m_nGold;
    int32_t m_bPlayerCharacter;
    uint16_t m_nSoundSet;
    int32_t m_nFootstepType;
    uint8_t m_nBodyBag;
    int32_t m_nInTransit;
    int32_t m_bPoisoned;
    int32_t m_bDiseased;
    int32_t m_bIsImmortal;
    int32_t m_bNoPermDeath;
    CExoString m_sDisplayName;
    int32_t m_bUpdateDisplayName;
    uint16_t m_nAIState;
    uint8_t m_nAIStateAction;
    uint32_t m_oidAIStateActee;
    uint8_t m_nAIStateOutput;
    uint32_t m_nActivities;
    uint32_t m_nActivitiesLocked;
    float m_fMovementRateFactor;
    float m_fDriveModeMoveFactor;
    uint8_t m_nWalkAnimation;
    int32_t m_bDriveMode;
    int32_t m_bJumpedRecently;
    uint32_t m_oidMaster;
    CExoArrayList<OID>* m_pAssociateList;
    uint16_t m_nAssociateType;
    int32_t m_nLastAssociateCommand;
    int32_t m_bSummonedAnimalCompanion;
    int32_t m_bSummonedFamiliar;
    int32_t m_bMasterDroppedFromServer;
    uint32_t m_nMasterDroppedCalendarDay;
    uint32_t m_nMasterDroppedTimeOfDay;
    int32_t m_nOriginalFactionId;
    CExoArrayList<CNWSPersonalReputation>* m_pPersonalReputationList;
    CExoArrayList<int>* m_pReputation;
    CExoArrayList<CNWSPVPEntry>* m_pPVPList;
    uint32_t m_oidEncounter;
    int32_t m_bAlreadyRemovedFromEncounter;
    CNWSInventory* m_pInventory;
    CItemRepository* m_pcItemRepository;
    uint16_t m_nRepositoryArrayIndex;
    uint16_t m_nItemContainerArrayIndex;
    uint32_t m_oidCurrentItemContainer;
    int32_t m_nEquippedWeight;
    int32_t m_bComputeWeightCarried;
    int32_t m_nEncumbranceState;
    int32_t m_bLastPickupFailed;
    int32_t m_nTotalWeightCarried;
    uint32_t m_pPrePolymorphedItems[18];
    CResRef m_refPrePolymorphPortrait;
    uint16_t m_nPrePolymorphPortraitId;
    int32_t m_bIsPolymorphed;
    uint16_t m_nPrePolymorphAppearanceType;
    uint8_t m_nPrePolymorphSTR;
    uint8_t m_nPrePolymorphCON;
    uint8_t m_nPrePolymorphDEX;
    uint16_t m_nPrePolymorphRacialType;
    int16_t m_nPrePolymorphHP;
    int32_t m_nPolymorphSpellId1;
    int32_t m_nPolymorphSpellId2;
    int32_t m_nPolymorphSpellId3;
    uint64_t m_nPolymorphACBonusEffect;
    uint64_t m_nPolymorphHPBonusEffect;
    int32_t m_bHasPrePolymorphCreatureWeaponProficiency;
    int32_t m_bPolymorphing;
    int32_t m_bPolymorphLocked;
    CNWSCreatureAppearanceInfo m_cAppearance;
    CNWSCreatureStats* m_pStats;
    uint32_t m_nLastRestCalendarDay;
    uint32_t m_nLastRestTimeOfDay;
}; CHECK_SIZE(CNWSCreature, 2168);

struct CClientExoApp;
struct CServerExoApp;
struct CNWTileSetManager;
struct CObjectTableManager;
struct CNWReentrantServerStats;

struct CAppManager
{
    CClientExoApp* m_pClientExoApp;
    CServerExoApp* m_pServerExoApp;
    CNWTileSetManager* m_pNWTileSetManager;
    CObjectTableManager* m_pClientObjectTableManager;
    CObjectTableManager* m_pServerObjectTableManager;
    CNWReentrantServerStats* m_pReentrantServerStats;
    int32_t m_bDungeonMasterEXERunning;
    uint32_t m_nApplicationId;
    int32_t m_bMultiplayerEnabled;
    int32_t m_bWasPaused;
    int32_t m_bDigitalDistributionModule;
    uint8_t* m_pDDCipher;
    uint32_t m_nDDOffset;
    uint32_t m_nPlayerTimeout;
    int32_t m_bLogModelErrors;
}; CHECK_SIZE(CAppManager, 60);

}