#pragma once

namespace nwn
{

static constexpr uint32_t ACTION_IN_PROGRESS = 1;
static constexpr uint32_t ACTION_COMPLETE = 2;
static constexpr uint32_t ACTION_FAILED = 3;

static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_INTEGER = 1;
static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_FLOAT   = 2;
static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_OBJECT  = 3;
static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_STRING  = 4;
static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_ACTION  = 5;
static constexpr uint32_t CNWSOBJECTACTION_PARAMETER_BYTE    = 6;

static constexpr uint8_t COBJECT_TYPE_GUI                = 1;
static constexpr uint8_t COBJECT_TYPE_TILE               = 2;
static constexpr uint8_t COBJECT_TYPE_MODULE             = 3;
static constexpr uint8_t COBJECT_TYPE_AREA               = 4;
static constexpr uint8_t COBJECT_TYPE_CREATURE           = 5;
static constexpr uint8_t COBJECT_TYPE_ITEM               = 6;
static constexpr uint8_t COBJECT_TYPE_TRIGGER            = 7;
static constexpr uint8_t COBJECT_TYPE_PROJECTILE         = 8;
static constexpr uint8_t COBJECT_TYPE_PLACEABLE          = 9;
static constexpr uint8_t COBJECT_TYPE_DOOR               = 10;
static constexpr uint8_t COBJECT_TYPE_AREAOFEFFECTOBJECT = 11;
static constexpr uint8_t COBJECT_TYPE_WAYPOINT           = 12;
static constexpr uint8_t COBJECT_TYPE_ENCOUNTER          = 13;
static constexpr uint8_t COBJECT_TYPE_STORE              = 14;
static constexpr uint8_t COBJECT_TYPE_PORTAL             = 15;
static constexpr uint8_t COBJECT_TYPE_SOUND              = 16;

static constexpr uint32_t CSERVERAIMASTER_AIACTION_INVALID                      = 0;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_MOVETOPOINT                  = 1;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVETOOBJECT            = 2;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVEAWAYFROMOBJECT      = 3;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKINTERAREAPATHFINDING    = 4;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_JUMPTOPOINT                  = 5;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_PLAYANIMATION                = 6;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_PICKUPITEM                   = 7;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_EQUIPITEM                    = 8;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DROPITEM                     = 9;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVETOPOINT             = 10;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_UNEQUIPITEM                  = 11;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_ATTACKOBJECT                 = 12;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_REPOSITORYMOVE               = 13;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_SPEAK                        = 14;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CASTSPELL                    = 15;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_WAITFORENDOFROUND            = 16;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVETOOBJECTRADIUS      = 17;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVETOPOINTRADIUS       = 18;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHANGEFACINGOBJECT           = 19;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_OPENDOOR                     = 20;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CLOSEDOOR                    = 21;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_ORIENTCAMERA                 = 22;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_PLAYSOUND                    = 23;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DIALOGOBJECT                 = 24;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DISABLETRAP                  = 25;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_RECOVERTRAP                  = 26;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_FLAGTRAP                     = 27;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_EXAMINETRAP                  = 28;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_SETTRAP                      = 29;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_WAIT                         = 30;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_PAUSEDIALOG                  = 31;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_RESUMEDIALOG                 = 32;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_SPEAKSTRREF                  = 33;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_GIVEITEM                     = 34;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_TAKEITEM                     = 35;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_ENCOUNTERCREATUREDESTROYSELF = 36;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DOCOMMAND                    = 37;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_OPENLOCK                     = 38;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_LOCK                         = 39;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_USEOBJECT                    = 40;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_ANIMALEMPATHY                = 41;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_REST                         = 42;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_TAUNT                        = 43;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKMOVEAWAYFROMLOCATION    = 44;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_RANDOMWALK                   = 45;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_ITEMCASTSPELL                = 46;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_SETCOMMANDABLE               = 47;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_JUMPTOOBJECT                 = 48;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHANGEFACINGPOINT            = 49;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_COUNTERSPELL                 = 50;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DRIVE                        = 51;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_APPEAR                       = 52;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_DISAPPEAR                    = 53;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_PICKPOCKET                   = 54;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_FORCEFOLLOWOBJECT            = 55;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_HEAL                         = 56;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_SIT                          = 57;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_CHECKFORCEFOLLOWOBJECT       = 58;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_BARTER                       = 59;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_AREAWAIT                     = 60;
static constexpr uint32_t CSERVERAIMASTER_AIACTION_EXAMINE                      = 61;

static constexpr int32_t NWANIMBASE_ANIM_PAUSE                 = 0;
static constexpr int32_t NWANIMBASE_ANIM_READY                 = 1;
static constexpr int32_t NWANIMBASE_ANIM_WALKING               = 2;
static constexpr int32_t NWANIMBASE_ANIM_WALKINGBACKWARDS      = 3;
static constexpr int32_t NWANIMBASE_ANIM_RUNNING               = 4;
static constexpr int32_t NWANIMBASE_ANIM_KNOCKDOWN_FRONT       = 5;
static constexpr int32_t NWANIMBASE_ANIM_DEAD_FRONT            = 6;
static constexpr int32_t NWANIMBASE_ANIM_KNOCKDOWN_BUTT        = 7;
static constexpr int32_t NWANIMBASE_ANIM_DEAD_BUTT             = 8;
static constexpr int32_t NWANIMBASE_ANIM_ATTACK                = 9;
static constexpr int32_t NWANIMBASE_ANIM_THROW                 = 10;
static constexpr int32_t NWANIMBASE_ANIM_DODGE                 = 11;
static constexpr int32_t NWANIMBASE_ANIM_PARRY                 = 12;
static constexpr int32_t NWANIMBASE_ANIM_SHIELD                = 13;
static constexpr int32_t NWANIMBASE_ANIM_DAMAGE                = 14;
static constexpr int32_t NWANIMBASE_ANIM_CONJURE_1             = 15;
static constexpr int32_t NWANIMBASE_ANIM_CONJURE_2             = 16;
static constexpr int32_t NWANIMBASE_ANIM_CAST_1                = 17;
static constexpr int32_t NWANIMBASE_ANIM_CAST_2                = 18;
static constexpr int32_t NWANIMBASE_ANIM_CAST_3                = 19;
static constexpr int32_t NWANIMBASE_ANIM_CAST_4                = 20;
static constexpr int32_t NWANIMBASE_ANIM_OPEN                  = 21;
static constexpr int32_t NWANIMBASE_ANIM_CLOSED                = 22;
static constexpr int32_t NWANIMBASE_ANIM_SPASM                 = 23;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_FRONT     = 24;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_BACK      = 25;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_LEFT      = 26;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_RIGHT     = 27;
static constexpr int32_t NWANIMBASE_ANIM_TAUNT                 = 28;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_GREETING      = 29;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_LISTEN        = 30;
static constexpr int32_t NWANIMBASE_ANIM_MEDITATE              = 32;
static constexpr int32_t NWANIMBASE_ANIM_WORSHIP               = 33;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_SALUTE        = 34;
static constexpr int32_t NWANIMBASE_ANIM_BOW                   = 35;
static constexpr int32_t NWANIMBASE_ANIM_SITTING               = 36;
static constexpr int32_t NWANIMBASE_ANIM_STEAL                 = 37;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_TALK_NORMAL   = 38;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_TALK_PLEADING = 39;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_TALK_FORCEFUL = 40;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_TALK_LAUGH    = 41;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_DUMMY     = 42;
static constexpr int32_t NWANIMBASE_ANIM_VICTORY_FIGHTER       = 44;
static constexpr int32_t NWANIMBASE_ANIM_VICTORY_MAGE          = 45;
static constexpr int32_t NWANIMBASE_ANIM_VICTORY_THIEF         = 46;
static constexpr int32_t NWANIMBASE_ANIM_SIT_CROSS_LEGS        = 47;
static constexpr int32_t NWANIMBASE_ANIM_LOOK_FAR              = 48;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_STEP_DUMMY_FB  = 49;
static constexpr int32_t NWANIMBASE_ANIM_OPENED1               = 50;
static constexpr int32_t NWANIMBASE_ANIM_OPENED2               = 51;
static constexpr int32_t NWANIMBASE_ANIM_PAUSE2                = 52;
static constexpr int32_t NWANIMBASE_ANIM_HEADTURN_LEFT         = 53;
static constexpr int32_t NWANIMBASE_ANIM_HEADTURN_RIGHT        = 54;
static constexpr int32_t NWANIMBASE_ANIM_PAUSE_SCRATCHHEAD     = 55;
static constexpr int32_t NWANIMBASE_ANIM_PAUSE_BORED           = 56;
static constexpr int32_t NWANIMBASE_ANIM_PAUSE_TIRED           = 57;
static constexpr int32_t NWANIMBASE_ANIM_PAUSE_DRUNK           = 58;
static constexpr int32_t NWANIMBASE_ANIM_GETLOW                = 59;
static constexpr int32_t NWANIMBASE_ANIM_GETMID                = 60;
static constexpr int32_t NWANIMBASE_ANIM_CAST_5                = 61;
static constexpr int32_t NWANIMBASE_ANIM_FLOWN                 = 62;
static constexpr int32_t NWANIMBASE_ANIM_ARRIVED               = 63;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_DRINK         = 70;
static constexpr int32_t NWANIMBASE_ANIM_OVERLAY_READ          = 71;
static constexpr int32_t NWANIMBASE_ANIM_DESTROYED             = 72;
static constexpr int32_t NWANIMBASE_ANIM_PLACEABLE_ACTIVATED   = 73;
static constexpr int32_t NWANIMBASE_ANIM_PLACEABLE_DEACTIVATED = 74;
static constexpr int32_t NWANIMBASE_ANIM_PLACEABLE_OPENED      = 75;
static constexpr int32_t NWANIMBASE_ANIM_PLACEABLE_CLOSED      = 76;
static constexpr int32_t NWANIMBASE_ANIM_DAMAGE_STAB           = 77;
static constexpr int32_t NWANIMBASE_ANIM_WALKINGLEFT           = 78;
static constexpr int32_t NWANIMBASE_ANIM_WALKINGRIGHT          = 79;
static constexpr int32_t NWANIMBASE_ANIM_TURNONSPOT_RIGHT      = 80;
static constexpr int32_t NWANIMBASE_ANIM_TURNONSPOT_LEFT       = 81;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_TURN_RIGHT     = 82;
static constexpr int32_t NWANIMBASE_ANIM_COMBAT_TURN_LEFT      = 83;
static constexpr int32_t NWANIMBASE_ANIM_WALKINGFORWARDLEFT    = 84;
static constexpr int32_t NWANIMBASE_ANIM_WALKINGFORWARDRIGHT   = 85;
static constexpr int32_t NWANIMBASE_ANIM_RUNNINGFORWARDLEFT    = 86;
static constexpr int32_t NWANIMBASE_ANIM_RUNNINGFORWARDRIGHT   = 87;
static constexpr int32_t NWANIMBASE_ANIM_DIALOG_NO_ANIM        = 88;
static constexpr int32_t NWANIMBASE_ANIM_FAKE_ATTACK           = 89;
static constexpr int32_t NWANIMBASE_ANIM_FAKE_DODGE_SIDE       = 90;
static constexpr int32_t NWANIMBASE_ANIM_FAKE_DODGE_DUCK       = 91;
static constexpr int32_t NWANIMBASE_ANIM_WHIRLWIND             = 92;
static constexpr int32_t NWANIMBASE_ANIM_SPASM_LOOPING         = 93;
static constexpr int32_t NWANIMBASE_ANIM_FLOWN2                = 94;
static constexpr int32_t NWANIMBASE_ANIM_ARRIVED2              = 95;
static constexpr int32_t NWANIMBASE_ANIM_CAST_CREATURE         = 96;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM1               = 97;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM2               = 98;
static constexpr int32_t NWANIMBASE_ANIM_DAMAGE_LEFT           = 99;
static constexpr int32_t NWANIMBASE_ANIM_DAMAGE_RIGHT          = 100;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM3               = 101;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM4               = 102;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM5               = 103;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM6               = 104;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM7               = 105;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM8               = 106;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM9               = 107;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM10              = 108;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM11              = 109;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM12              = 110;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM13              = 111;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM14              = 112;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM15              = 113;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM16              = 114;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM17              = 115;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM18              = 116;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM19              = 117;
static constexpr int32_t NWANIMBASE_ANIM_CUSTOM20              = 118;
static constexpr int32_t NWANIMBASE_ANIM_MOUNT1                = 119;
static constexpr int32_t NWANIMBASE_ANIM_DISMOUNT1             = 120;

static constexpr uint32_t UPDATE_OBJECT_POSITION_FLAG                   = 0x00000001;
static constexpr uint32_t UPDATE_OBJECT_ORIENTATION_FLAG                = 0x00000002;
static constexpr uint32_t UPDATE_OBJECT_ANIMATION_FLAG                  = 0x00000004;
static constexpr uint32_t UPDATE_OBJECT_VISUAL_EFFECT_FLAG              = 0x00000008;
static constexpr uint32_t UPDATE_OBJECT_TRAPS_AND_LOCKS_FLAG            = 0x00000010;
static constexpr uint32_t UPDATE_OBJECT_PORTRAIT_FLAG                   = 0x00000020;
static constexpr uint32_t UPDATE_OBJECT_NAME_FLAG                       = 0x00080000;
static constexpr uint32_t UPDATE_OBJECT_VISUAL_TRANSFORM_FLAG           = 0x00100000;
static constexpr uint32_t UPDATE_OBJECT_MATERIAL_SHADER_PARAMETERS_FLAG = 0x00200000;

}
