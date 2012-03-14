// File: QMoMGenerated.cpp
// Generated from: MoMTemplate.h

#include <ctype.h>
#include <iomanip>
#include <sstream>

#include <MoMGenerated.h>

#include "QMoMGenerated.h"

namespace MoM {

TreeItemBase* constructTreeItem(Ability_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Ability_Flags maskSummoned_Unit;
    memset(&maskSummoned_Unit, '\0', sizeof(maskSummoned_Unit));
    maskSummoned_Unit.Summoned_Unit = 0xFF;
    if (1 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummoned_Unit));
    else if (2 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummoned_Unit));
    else
        ptree->appendChild("Summoned_Unit", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummoned_Unit));
    Ability_Flags maskLarge_Shield;
    memset(&maskLarge_Shield, '\0', sizeof(maskLarge_Shield));
    maskLarge_Shield.Large_Shield = 0xFF;
    if (1 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLarge_Shield));
    else if (2 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLarge_Shield));
    else
        ptree->appendChild("Large_Shield", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLarge_Shield));
    Ability_Flags maskPlane_Shift;
    memset(&maskPlane_Shift, '\0', sizeof(maskPlane_Shift));
    maskPlane_Shift.Plane_Shift = 0xFF;
    if (1 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlane_Shift));
    else if (2 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlane_Shift));
    else
        ptree->appendChild("Plane_Shift", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlane_Shift));
    Ability_Flags maskWall_Crusher;
    memset(&maskWall_Crusher, '\0', sizeof(maskWall_Crusher));
    maskWall_Crusher.Wall_Crusher = 0xFF;
    if (1 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWall_Crusher));
    else if (2 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWall_Crusher));
    else
        ptree->appendChild("Wall_Crusher", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWall_Crusher));
    Ability_Flags maskHealer;
    memset(&maskHealer, '\0', sizeof(maskHealer));
    maskHealer.Healer = 0xFF;
    if (1 == sizeof(maskHealer))
        ptree->appendChild("Healer", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealer));
    else if (2 == sizeof(maskHealer))
        ptree->appendChild("Healer", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealer));
    else
        ptree->appendChild("Healer", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealer));
    Ability_Flags maskCreate_Outpost;
    memset(&maskCreate_Outpost, '\0', sizeof(maskCreate_Outpost));
    maskCreate_Outpost.Create_Outpost = 0xFF;
    if (1 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Outpost));
    else if (2 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Outpost));
    else
        ptree->appendChild("Create_Outpost", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Outpost));
    Ability_Flags maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 0xFF;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Ability_Flags maskCreate_Undead;
    memset(&maskCreate_Undead, '\0', sizeof(maskCreate_Undead));
    maskCreate_Undead.Create_Undead = 0xFF;
    if (1 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Undead));
    else if (2 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Undead));
    else
        ptree->appendChild("Create_Undead", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Undead));
    Ability_Flags maskLong_Range;
    memset(&maskLong_Range, '\0', sizeof(maskLong_Range));
    maskLong_Range.Long_Range = 0xFF;
    if (1 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLong_Range));
    else if (2 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLong_Range));
    else
        ptree->appendChild("Long_Range", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLong_Range));
    Ability_Flags maskLand_Corruption;
    memset(&maskLand_Corruption, '\0', sizeof(maskLand_Corruption));
    maskLand_Corruption.Land_Corruption = 0xFF;
    if (1 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLand_Corruption));
    else if (2 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLand_Corruption));
    else
        ptree->appendChild("Land_Corruption", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLand_Corruption));
    Ability_Flags maskMeld_With_Node;
    memset(&maskMeld_With_Node, '\0', sizeof(maskMeld_With_Node));
    maskMeld_With_Node.Meld_With_Node = 0xFF;
    if (1 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMeld_With_Node));
    else if (2 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMeld_With_Node));
    else
        ptree->appendChild("Meld_With_Node", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMeld_With_Node));
    Ability_Flags maskNon_Corporeal;
    memset(&maskNon_Corporeal, '\0', sizeof(maskNon_Corporeal));
    maskNon_Corporeal.Non_Corporeal = 0xFF;
    if (1 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNon_Corporeal));
    else if (2 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNon_Corporeal));
    else
        ptree->appendChild("Non_Corporeal", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNon_Corporeal));
    Ability_Flags maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 0xFF;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Ability_Flags maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 0xFF;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Ability_Flags maskPurify;
    memset(&maskPurify, '\0', sizeof(maskPurify));
    maskPurify.Purify = 0xFF;
    if (1 == sizeof(maskPurify))
        ptree->appendChild("Purify", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPurify));
    else if (2 == sizeof(maskPurify))
        ptree->appendChild("Purify", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPurify));
    else
        ptree->appendChild("Purify", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPurify));
    Ability_Flags maskNegate_First_Strike;
    memset(&maskNegate_First_Strike, '\0', sizeof(maskNegate_First_Strike));
    maskNegate_First_Strike.Negate_First_Strike = 0xFF;
    if (1 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNegate_First_Strike));
    else if (2 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNegate_First_Strike));
    else
        ptree->appendChild("Negate_First_Strike", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNegate_First_Strike));
    return ptree;
}

TreeItemBase* constructTreeItem(Attack_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Attack_Flags maskArmor_Piercing;
    memset(&maskArmor_Piercing, '\0', sizeof(maskArmor_Piercing));
    maskArmor_Piercing.Armor_Piercing = 0xFF;
    if (1 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmor_Piercing));
    else if (2 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmor_Piercing));
    else
        ptree->appendChild("Armor_Piercing", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmor_Piercing));
    Attack_Flags maskFirst_Strike;
    memset(&maskFirst_Strike, '\0', sizeof(maskFirst_Strike));
    maskFirst_Strike.First_Strike = 0xFF;
    if (1 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFirst_Strike));
    else if (2 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFirst_Strike));
    else
        ptree->appendChild("First_Strike", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFirst_Strike));
    Attack_Flags maskPoison_attack;
    memset(&maskPoison_attack, '\0', sizeof(maskPoison_attack));
    maskPoison_attack.Poison_attack = 0xFF;
    if (1 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_attack));
    else if (2 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_attack));
    else
        ptree->appendChild("Poison_attack", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_attack));
    Attack_Flags maskLife_Stealing;
    memset(&maskLife_Stealing, '\0', sizeof(maskLife_Stealing));
    maskLife_Stealing.Life_Stealing = 0xFF;
    if (1 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLife_Stealing));
    else if (2 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLife_Stealing));
    else
        ptree->appendChild("Life_Stealing", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLife_Stealing));
    Attack_Flags maskAutomatic_Damage;
    memset(&maskAutomatic_Damage, '\0', sizeof(maskAutomatic_Damage));
    maskAutomatic_Damage.Automatic_Damage = 0xFF;
    if (1 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAutomatic_Damage));
    else if (2 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAutomatic_Damage));
    else
        ptree->appendChild("Automatic_Damage", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAutomatic_Damage));
    Attack_Flags maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 0xFF;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Attack_Flags maskIllusionary_attack;
    memset(&maskIllusionary_attack, '\0', sizeof(maskIllusionary_attack));
    maskIllusionary_attack.Illusionary_attack = 0xFF;
    if (1 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusionary_attack));
    else if (2 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusionary_attack));
    else
        ptree->appendChild("Illusionary_attack", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusionary_attack));
    Attack_Flags maskStoning_Touch;
    memset(&maskStoning_Touch, '\0', sizeof(maskStoning_Touch));
    maskStoning_Touch.Stoning_Touch = 0xFF;
    if (1 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Touch));
    else if (2 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Touch));
    else
        ptree->appendChild("Stoning_Touch", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Touch));
    Attack_Flags maskNo_effect05;
    memset(&maskNo_effect05, '\0', sizeof(maskNo_effect05));
    maskNo_effect05.No_effect05 = 0xFF;
    if (1 == sizeof(maskNo_effect05))
        ptree->appendChild("No_effect05", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect05));
    else if (2 == sizeof(maskNo_effect05))
        ptree->appendChild("No_effect05", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect05));
    else
        ptree->appendChild("No_effect05", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect05));
    Attack_Flags maskDeath_Touch;
    memset(&maskDeath_Touch, '\0', sizeof(maskDeath_Touch));
    maskDeath_Touch.Death_Touch = 0xFF;
    if (1 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Touch));
    else if (2 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Touch));
    else
        ptree->appendChild("Death_Touch", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Touch));
    Attack_Flags maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 0xFF;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Attack_Flags maskDispel_Evil;
    memset(&maskDispel_Evil, '\0', sizeof(maskDispel_Evil));
    maskDispel_Evil.Dispel_Evil = 0xFF;
    if (1 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDispel_Evil));
    else if (2 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDispel_Evil));
    else
        ptree->appendChild("Dispel_Evil", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDispel_Evil));
    Attack_Flags maskNo_effect04_COMBAT;
    memset(&maskNo_effect04_COMBAT, '\0', sizeof(maskNo_effect04_COMBAT));
    maskNo_effect04_COMBAT.No_effect04_COMBAT = 0xFF;
    if (1 == sizeof(maskNo_effect04_COMBAT))
        ptree->appendChild("No_effect04_COMBAT", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect04_COMBAT));
    else if (2 == sizeof(maskNo_effect04_COMBAT))
        ptree->appendChild("No_effect04_COMBAT", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect04_COMBAT));
    else
        ptree->appendChild("No_effect04_COMBAT", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect04_COMBAT));
    Attack_Flags maskNo_effect03_COMBAT;
    memset(&maskNo_effect03_COMBAT, '\0', sizeof(maskNo_effect03_COMBAT));
    maskNo_effect03_COMBAT.No_effect03_COMBAT = 0xFF;
    if (1 == sizeof(maskNo_effect03_COMBAT))
        ptree->appendChild("No_effect03_COMBAT", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect03_COMBAT));
    else if (2 == sizeof(maskNo_effect03_COMBAT))
        ptree->appendChild("No_effect03_COMBAT", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect03_COMBAT));
    else
        ptree->appendChild("No_effect03_COMBAT", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect03_COMBAT));
    Attack_Flags maskEldritch_Weapon_COMBAT;
    memset(&maskEldritch_Weapon_COMBAT, '\0', sizeof(maskEldritch_Weapon_COMBAT));
    maskEldritch_Weapon_COMBAT.Eldritch_Weapon_COMBAT = 0xFF;
    if (1 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon_COMBAT));
    else if (2 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon_COMBAT));
    else
        ptree->appendChild("Eldritch_Weapon_COMBAT", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon_COMBAT));
    Attack_Flags maskWarp_Lightning_COMBAT;
    memset(&maskWarp_Lightning_COMBAT, '\0', sizeof(maskWarp_Lightning_COMBAT));
    maskWarp_Lightning_COMBAT.Warp_Lightning_COMBAT = 0xFF;
    if (1 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Lightning_COMBAT));
    else if (2 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Lightning_COMBAT));
    else
        ptree->appendChild("Warp_Lightning_COMBAT", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Lightning_COMBAT));
    return ptree;
}

TreeItemBase* constructTreeItem(Attribute_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Attribute_Flags maskWeapon_Immunity;
    memset(&maskWeapon_Immunity, '\0', sizeof(maskWeapon_Immunity));
    maskWeapon_Immunity.Weapon_Immunity = 0xFF;
    if (1 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Immunity));
    else if (2 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Immunity));
    else
        ptree->appendChild("Weapon_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Immunity));
    Attribute_Flags maskFlyer;
    memset(&maskFlyer, '\0', sizeof(maskFlyer));
    maskFlyer.Flyer = 0xFF;
    if (1 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlyer));
    else if (2 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlyer));
    else
        ptree->appendChild("Flyer", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlyer));
    Attribute_Flags maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 0xFF;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Attribute_Flags maskSummon_Demons_1;
    memset(&maskSummon_Demons_1, '\0', sizeof(maskSummon_Demons_1));
    maskSummon_Demons_1.Summon_Demons_1 = 0xFF;
    if (1 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_1));
    else if (2 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_1));
    else
        ptree->appendChild("Summon_Demons_1", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_1));
    Attribute_Flags maskSummon_Demons_2;
    memset(&maskSummon_Demons_2, '\0', sizeof(maskSummon_Demons_2));
    maskSummon_Demons_2.Summon_Demons_2 = 0xFF;
    if (1 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_2));
    else if (2 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_2));
    else
        ptree->appendChild("Summon_Demons_2", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_2));
    Attribute_Flags maskCaster_20_MP;
    memset(&maskCaster_20_MP, '\0', sizeof(maskCaster_20_MP));
    maskCaster_20_MP.Caster_20_MP = 0xFF;
    if (1 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_20_MP));
    else if (2 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_20_MP));
    else
        ptree->appendChild("Caster_20_MP", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_20_MP));
    Attribute_Flags maskCaster_40_MP;
    memset(&maskCaster_40_MP, '\0', sizeof(maskCaster_40_MP));
    maskCaster_40_MP.Caster_40_MP = 0xFF;
    if (1 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_40_MP));
    else if (2 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_40_MP));
    else
        ptree->appendChild("Caster_40_MP", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_40_MP));
    Attribute_Flags maskStandard;
    memset(&maskStandard, '\0', sizeof(maskStandard));
    maskStandard.Standard = 0xFF;
    if (1 == sizeof(maskStandard))
        ptree->appendChild("Standard", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStandard));
    else if (2 == sizeof(maskStandard))
        ptree->appendChild("Standard", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStandard));
    else
        ptree->appendChild("Standard", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStandard));
    Attribute_Flags maskHealing_Spell;
    memset(&maskHealing_Spell, '\0', sizeof(maskHealing_Spell));
    maskHealing_Spell.Healing_Spell = 0xFF;
    if (1 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealing_Spell));
    else if (2 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealing_Spell));
    else
        ptree->appendChild("Healing_Spell", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealing_Spell));
    Attribute_Flags maskFire_Ball_Spell;
    memset(&maskFire_Ball_Spell, '\0', sizeof(maskFire_Ball_Spell));
    maskFire_Ball_Spell.Fire_Ball_Spell = 0xFF;
    if (1 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Ball_Spell));
    else if (2 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Ball_Spell));
    else
        ptree->appendChild("Fire_Ball_Spell", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Ball_Spell));
    Attribute_Flags maskDoombolt_Spell;
    memset(&maskDoombolt_Spell, '\0', sizeof(maskDoombolt_Spell));
    maskDoombolt_Spell.Doombolt_Spell = 0xFF;
    if (1 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoombolt_Spell));
    else if (2 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoombolt_Spell));
    else
        ptree->appendChild("Doombolt_Spell", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoombolt_Spell));
    Attribute_Flags maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 0xFF;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Attribute_Flags maskWeb_Spell;
    memset(&maskWeb_Spell, '\0', sizeof(maskWeb_Spell));
    maskWeb_Spell.Web_Spell = 0xFF;
    if (1 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb_Spell));
    else if (2 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb_Spell));
    else
        ptree->appendChild("Web_Spell", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb_Spell));
    Attribute_Flags maskCause_Fear_Spell;
    memset(&maskCause_Fear_Spell, '\0', sizeof(maskCause_Fear_Spell));
    maskCause_Fear_Spell.Cause_Fear_Spell = 0xFF;
    if (1 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCause_Fear_Spell));
    else if (2 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCause_Fear_Spell));
    else
        ptree->appendChild("Cause_Fear_Spell", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCause_Fear_Spell));
    Attribute_Flags maskResistance_to_All;
    memset(&maskResistance_to_All, '\0', sizeof(maskResistance_to_All));
    maskResistance_to_All.Resistance_to_All = 0xFF;
    if (1 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResistance_to_All));
    else if (2 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResistance_to_All));
    else
        ptree->appendChild("Resistance_to_All", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResistance_to_All));
    Attribute_Flags maskHoly_Bonus;
    memset(&maskHoly_Bonus, '\0', sizeof(maskHoly_Bonus));
    maskHoly_Bonus.Holy_Bonus = 0xFF;
    if (1 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Bonus));
    else if (2 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Bonus));
    else
        ptree->appendChild("Holy_Bonus", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Bonus));
    return ptree;
}

TreeItemBase* constructTreeItem(Available_spell_page* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Page_Name", new TreeItem<char[0x10]>(rhs->m_Page_Name));
    TreeItemBase* ptreem_Spells_on_page = ptree;
    if (6 > 3)
    {
        ptreem_Spells_on_page = new TreeItemBase("m_Spells_on_page");
        ptree->appendTree(ptreem_Spells_on_page, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_on_page[" << i << "]";
          ptreem_Spells_on_page->appendChild(oss.str().c_str(), new TreeItem<eSpell16>(&rhs->m_Spells_on_page[i]));
    }
    ptree->appendChild("m_Nr_spells_on_page", new TreeItem<uint8_t>(&rhs->m_Nr_spells_on_page));
    ptree->appendChild("m_Zero", new TreeItem<uint8_t>(&rhs->m_Zero));
    return ptree;
}

TreeItemBase* constructTreeItem(Battle_Unit* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Melee", new TreeItem<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new TreeItem<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new TreeItem<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new TreeItem<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new TreeItem<uint8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new TreeItem<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new TreeItem<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new TreeItem<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new TreeItem<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new TreeItem<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new TreeItem<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Buildings_Required1_UNK", new TreeItem<uint8_t>(&rhs->m_Buildings_Required1_UNK));
    ptree->appendChild("m_Current_Figures", new TreeItem<uint8_t>(&rhs->m_Current_Figures));
    ptree->appendChild("m_graphics_ID_GUESS", new TreeItem<uint8_t>(&rhs->m_graphics_ID_GUESS));
    ptree->appendChild("m_UNK01", new TreeItem<uint8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Hitpoints_per_Figure", new TreeItem<uint8_t>(&rhs->m_Hitpoints_per_Figure));
    ptree->appendChild("m_Scouting_Range", new TreeItem<uint8_t>(&rhs->m_Scouting_Range));
    ptree->appendChild("m_Transport_Capacity_GUESS", new TreeItem<uint8_t>(&rhs->m_Transport_Capacity_GUESS));
    ptree->appendChild("m_Total_Figures", new TreeItem<uint8_t>(&rhs->m_Total_Figures));
    ptree->appendChild("m_Construction_Capacity", new TreeItem<uint8_t>(&rhs->m_Construction_Capacity));
    ptree->appendChild("m_Gaze_Modifier", new TreeItem<uint8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero01", new TreeItem<uint8_t>(&rhs->m_Zero01));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero02", new TreeItem<uint8_t>(&rhs->m_Zero02));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_Zero03", new TreeItem<uint16_t>(&rhs->m_Zero03));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags_Combat_Enchantment, "m_Flags_Combat_Enchantment"), "");
    ptree->appendChild("m_Extra_ToHit_Melee", new TreeItem<uint8_t>(&rhs->m_Extra_ToHit_Melee));
    ptree->appendChild("m_Extra_ToHit_Ranged", new TreeItem<uint8_t>(&rhs->m_Extra_ToHit_Ranged));
    ptree->appendChild("m_Extra_ToDefend", new TreeItem<uint8_t>(&rhs->m_Extra_ToDefend));
    ptree->appendChild("m_Weapon_Type_Plus_1", new TreeItem<uint8_t>(&rhs->m_Weapon_Type_Plus_1));
    ptree->appendTree(constructTreeItem(&rhs->m_Cur_Attack_Flags, "m_Cur_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Item_Attack_Flags, "m_Item_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Flags2_UnitEnchantment, "m_Flags2_UnitEnchantment"), "");
    ptree->appendChild("m_unitNr", new TreeItem<int16_t>(&rhs->m_unitNr));
    ptree->appendChild("m_UNK04", new TreeItem<uint8_t>(&rhs->m_UNK04));
    ptree->appendChild("m_web_", new TreeItem<uint8_t>(&rhs->m_web_));
    ptree->appendChild("m_active__", new TreeItem<uint8_t>(&rhs->m_active__));
    ptree->appendChild("m_Owner", new TreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_cur_total_damage_GUESS", new TreeItem<uint8_t>(&rhs->m_cur_total_damage_GUESS));
    TreeItemBase* ptreem_UNK05 = ptree;
    if (2 > 3)
    {
        ptreem_UNK05 = new TreeItemBase("m_UNK05");
        ptree->appendTree(ptreem_UNK05, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK05[" << i << "]";
          ptreem_UNK05->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK05[i]));
    }
    ptree->appendChild("m_cur_figure_damage_GUESS", new TreeItem<uint8_t>(&rhs->m_cur_figure_damage_GUESS));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags1_UnitEnchantment, "m_Flags1_UnitEnchantment"), "");
    ptree->appendChild("m_Suppression", new TreeItem<uint8_t>(&rhs->m_Suppression));
    ptree->appendChild("m_Mana_points", new TreeItem<uint8_t>(&rhs->m_Mana_points));
    ptree->appendChild("m_Current_mana_", new TreeItem<uint8_t>(&rhs->m_Current_mana_));
    ptree->appendChild("m_Item_nr_charges_", new TreeItem<uint8_t>(&rhs->m_Item_nr_charges_));
    ptree->appendChild("m_Poison_strength_", new TreeItem<uint8_t>(&rhs->m_Poison_strength_));
    ptree->appendChild("m_UNK07a", new TreeItem<uint8_t>(&rhs->m_UNK07a));
    ptree->appendChild("m_xPos", new TreeItem<uint16_t>(&rhs->m_xPos));
    ptree->appendChild("m_yPos", new TreeItem<uint16_t>(&rhs->m_yPos));
    ptree->appendChild("m_xPosHeaded", new TreeItem<uint16_t>(&rhs->m_xPosHeaded));
    ptree->appendChild("m_yPosHeaded", new TreeItem<uint16_t>(&rhs->m_yPosHeaded));
    TreeItemBase* ptreem_UNK07b = ptree;
    if (8 > 3)
    {
        ptreem_UNK07b = new TreeItemBase("m_UNK07b");
        ptree->appendTree(ptreem_UNK07b, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07b[" << i << "]";
          ptreem_UNK07b->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK07b[i]));
    }
    ptree->appendChild("m_Status", new TreeItem<eUnit_Status>(&rhs->m_Status));
    ptree->appendChild("m_UNK08", new TreeItem<uint8_t>(&rhs->m_UNK08));
    ptree->appendChild("m_Confused_State", new TreeItem<int8_t>(&rhs->m_Confused_State));
    TreeItemBase* ptreem_UNK09a = ptree;
    if (13 > 3)
    {
        ptreem_UNK09a = new TreeItemBase("m_UNK09a");
        ptree->appendTree(ptreem_UNK09a, "");
    }
    for (int i = 0; i < 13; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK09a[" << i << "]";
          ptreem_UNK09a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK09a[i]));
    }
    ptree->appendChild("m_Extra_Attack", new TreeItem<uint8_t>(&rhs->m_Extra_Attack));
    ptree->appendChild("m_Extra_Ranged", new TreeItem<uint8_t>(&rhs->m_Extra_Ranged));
    ptree->appendChild("m_Extra_Defense", new TreeItem<uint8_t>(&rhs->m_Extra_Defense));
    ptree->appendChild("m_Extra_Resistance", new TreeItem<uint8_t>(&rhs->m_Extra_Resistance));
    ptree->appendChild("m_Extra_Hitpoints", new TreeItem<uint8_t>(&rhs->m_Extra_Hitpoints));
    TreeItemBase* ptreem_UNK09b = ptree;
    if (5 > 3)
    {
        ptreem_UNK09b = new TreeItemBase("m_UNK09b");
        ptree->appendTree(ptreem_UNK09b, "");
    }
    for (int i = 0; i < 5; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK09b[" << i << "]";
          ptreem_UNK09b->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK09b[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Battlefield* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreefield_0 = ptree;
    if (924 > 3)
    {
        ptreefield_0 = new TreeItemBase("field_0");
        ptree->appendTree(ptreefield_0, "");
    }
    for (int i = 0; i < 924; ++i)
    {
          std::ostringstream oss;
          oss << "field_0[" << i << "]";
          ptreefield_0->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_0[i]));
    }
    ptree->appendChild("field_39C", new TreeItem<uint8_t>(&rhs->field_39C));
    TreeItemBase* ptreefield_39D = ptree;
    if (461 > 3)
    {
        ptreefield_39D = new TreeItemBase("field_39D");
        ptree->appendTree(ptreefield_39D, "");
    }
    for (int i = 0; i < 461; ++i)
    {
          std::ostringstream oss;
          oss << "field_39D[" << i << "]";
          ptreefield_39D->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_39D[i]));
    }
    ptree->appendChild("field_56A", new TreeItem<uint8_t>(&rhs->field_56A));
    TreeItemBase* ptreefield_56B = ptree;
    if (235 > 3)
    {
        ptreefield_56B = new TreeItemBase("field_56B");
        ptree->appendTree(ptreefield_56B, "");
    }
    for (int i = 0; i < 235; ++i)
    {
          std::ostringstream oss;
          oss << "field_56B[" << i << "]";
          ptreefield_56B->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_56B[i]));
    }
    ptree->appendChild("field_656", new TreeItem<uint8_t>(&rhs->field_656));
    ptree->appendChild("field_657", new TreeItem<uint8_t>(&rhs->field_657));
    ptree->appendChild("field_658", new TreeItem<uint8_t>(&rhs->field_658));
    TreeItemBase* ptreefield_659 = ptree;
    if (18 > 3)
    {
        ptreefield_659 = new TreeItemBase("field_659");
        ptree->appendTree(ptreefield_659, "");
    }
    for (int i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "field_659[" << i << "]";
          ptreefield_659->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_659[i]));
    }
    ptree->appendChild("field_66B", new TreeItem<uint8_t>(&rhs->field_66B));
    ptree->appendChild("field_66C", new TreeItem<uint8_t>(&rhs->field_66C));
    ptree->appendChild("field_66D", new TreeItem<uint8_t>(&rhs->field_66D));
    TreeItemBase* ptreefield_66E = ptree;
    if (18 > 3)
    {
        ptreefield_66E = new TreeItemBase("field_66E");
        ptree->appendTree(ptreefield_66E, "");
    }
    for (int i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "field_66E[" << i << "]";
          ptreefield_66E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_66E[i]));
    }
    ptree->appendChild("field_680", new TreeItem<uint8_t>(&rhs->field_680));
    ptree->appendChild("field_681", new TreeItem<uint8_t>(&rhs->field_681));
    ptree->appendChild("field_682", new TreeItem<uint8_t>(&rhs->field_682));
    ptree->appendChild("field_683", new TreeItem<uint8_t>(&rhs->field_683));
    TreeItemBase* ptreefield_684 = ptree;
    if (180 > 3)
    {
        ptreefield_684 = new TreeItemBase("field_684");
        ptree->appendTree(ptreefield_684, "");
    }
    for (int i = 0; i < 180; ++i)
    {
          std::ostringstream oss;
          oss << "field_684[" << i << "]";
          ptreefield_684->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_684[i]));
    }
    ptree->appendChild("field_738", new TreeItem<uint16_t>(&rhs->field_738));
    TreeItemBase* ptreefield_73A = ptree;
    if (668 > 3)
    {
        ptreefield_73A = new TreeItemBase("field_73A");
        ptree->appendTree(ptreefield_73A, "");
    }
    for (int i = 0; i < 668; ++i)
    {
          std::ostringstream oss;
          oss << "field_73A[" << i << "]";
          ptreefield_73A->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_73A[i]));
    }
    ptree->appendChild("field_9D6_Merging_Teleporting", new TreeItem<uint16_t>(&rhs->field_9D6_Merging_Teleporting));
    TreeItemBase* ptreefield_9D8 = ptree;
    if (252 > 3)
    {
        ptreefield_9D8 = new TreeItemBase("field_9D8");
        ptree->appendTree(ptreefield_9D8, "");
    }
    for (int i = 0; i < 252; ++i)
    {
          std::ostringstream oss;
          oss << "field_9D8[" << i << "]";
          ptreefield_9D8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_9D8[i]));
    }
    ptree->appendChild("field_AD4", new TreeItem<uint16_t>(&rhs->field_AD4));
    TreeItemBase* ptreefield_AD6 = ptree;
    if (460 > 3)
    {
        ptreefield_AD6 = new TreeItemBase("field_AD6");
        ptree->appendTree(ptreefield_AD6, "");
    }
    for (int i = 0; i < 460; ++i)
    {
          std::ostringstream oss;
          oss << "field_AD6[" << i << "]";
          ptreefield_AD6->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_AD6[i]));
    }
    ptree->appendChild("field_CA2_sail", new TreeItem<uint16_t>(&rhs->field_CA2_sail));
    TreeItemBase* ptreefield_CA4 = ptree;
    if (460 > 3)
    {
        ptreefield_CA4 = new TreeItemBase("field_CA4");
        ptree->appendTree(ptreefield_CA4, "");
    }
    for (int i = 0; i < 460; ++i)
    {
          std::ostringstream oss;
          oss << "field_CA4[" << i << "]";
          ptreefield_CA4->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_CA4[i]));
    }
    ptree->appendChild("field_E70", new TreeItem<uint16_t>(&rhs->field_E70));
    TreeItemBase* ptreefield_E72 = ptree;
    if (600 > 3)
    {
        ptreefield_E72 = new TreeItemBase("field_E72");
        ptree->appendTree(ptreefield_E72, "");
    }
    for (int i = 0; i < 600; ++i)
    {
          std::ostringstream oss;
          oss << "field_E72[" << i << "]";
          ptreefield_E72->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_E72[i]));
    }
    ptree->appendChild("field_10CA", new TreeItem<uint16_t>(&rhs->field_10CA));
    TreeItemBase* ptreefield_10CC = ptree;
    if (1062 > 3)
    {
        ptreefield_10CC = new TreeItemBase("field_10CC");
        ptree->appendTree(ptreefield_10CC, "");
    }
    for (int i = 0; i < 1062; ++i)
    {
          std::ostringstream oss;
          oss << "field_10CC[" << i << "]";
          ptreefield_10CC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_10CC[i]));
    }
    ptree->appendChild("field_14F2", new TreeItem<uint16_t>(&rhs->field_14F2));
    ptree->appendChild("field_14F4", new TreeItem<uint16_t>(&rhs->field_14F4));
    ptree->appendChild("field_14F6", new TreeItem<uint16_t>(&rhs->field_14F6));
    TreeItemBase* ptreefield_14F8 = ptree;
    if (30 > 3)
    {
        ptreefield_14F8 = new TreeItemBase("field_14F8");
        ptree->appendTree(ptreefield_14F8, "");
    }
    for (int i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_14F8[" << i << "]";
          ptreefield_14F8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_14F8[i]));
    }
    ptree->appendChild("field_1516", new TreeItem<uint16_t>(&rhs->field_1516));
    TreeItemBase* ptreefield_1518 = ptree;
    if (30 > 3)
    {
        ptreefield_1518 = new TreeItemBase("field_1518");
        ptree->appendTree(ptreefield_1518, "");
    }
    for (int i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_1518[" << i << "]";
          ptreefield_1518->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_1518[i]));
    }
    ptree->appendChild("field_1536", new TreeItem<uint16_t>(&rhs->field_1536));
    TreeItemBase* ptreefield_1538 = ptree;
    if (30 > 3)
    {
        ptreefield_1538 = new TreeItemBase("field_1538");
        ptree->appendTree(ptreefield_1538, "");
    }
    for (int i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_1538[" << i << "]";
          ptreefield_1538->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->field_1538[i]));
    }
    ptree->appendChild("field_City_Walls", new TreeItem<uint16_t>(&rhs->field_City_Walls));
    TreeItemBase* ptreefield_Wall_is_whole = ptree;
    if (16 > 3)
    {
        ptreefield_Wall_is_whole = new TreeItemBase("field_Wall_is_whole");
        ptree->appendTree(ptreefield_Wall_is_whole, "");
    }
    for (int i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "field_Wall_is_whole[" << i << "]";
          ptreefield_Wall_is_whole->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->field_Wall_is_whole[i]));
    }
    ptree->appendChild("field_Wall_of_Fire", new TreeItem<uint16_t>(&rhs->field_Wall_of_Fire));
    ptree->appendChild("field_Wall_of_Darkness", new TreeItem<uint16_t>(&rhs->field_Wall_of_Darkness));
    ptree->appendChild("field_157C_plane_GUESS", new TreeItem<uint16_t>(&rhs->field_157C_plane_GUESS));
    ptree->appendChild("field_157E", new TreeItem<uint16_t>(&rhs->field_157E));
    ptree->appendChild("field_1580", new TreeItem<uint16_t>(&rhs->field_1580));
    ptree->appendChild("field_1582", new TreeItem<uint16_t>(&rhs->field_1582));
    ptree->appendChild("field_Cloud_of_Shadow_GUESS", new TreeItem<uint8_t>(&rhs->field_Cloud_of_Shadow_GUESS));
    ptree->appendChild("field_1585", new TreeItem<uint8_t>(&rhs->field_1585));
    ptree->appendChild("field_1586", new TreeItem<uint8_t>(&rhs->field_1586));
    ptree->appendChild("field_1587", new TreeItem<uint8_t>(&rhs->field_1587));
    ptree->appendChild("field_1588", new TreeItem<uint8_t>(&rhs->field_1588));
    ptree->appendChild("field_1589", new TreeItem<uint8_t>(&rhs->field_1589));
    ptree->appendChild("field_158A", new TreeItem<uint8_t>(&rhs->field_158A));
    ptree->appendChild("field_158B", new TreeItem<uint8_t>(&rhs->field_158B));
    ptree->appendChild("field_158C", new TreeItem<uint8_t>(&rhs->field_158C));
    ptree->appendChild("field_158D", new TreeItem<uint8_t>(&rhs->field_158D));
    ptree->appendChild("field_158E", new TreeItem<uint8_t>(&rhs->field_158E));
    ptree->appendChild("field_158F", new TreeItem<uint8_t>(&rhs->field_158F));
    ptree->appendChild("field_1590", new TreeItem<uint8_t>(&rhs->field_1590));
    ptree->appendChild("field_1591", new TreeItem<uint8_t>(&rhs->field_1591));
    ptree->appendChild("field_1592", new TreeItem<uint8_t>(&rhs->field_1592));
    ptree->appendChild("field_Heavenly_Light_GUESS", new TreeItem<uint8_t>(&rhs->field_Heavenly_Light_GUESS));
    return ptree;
}

TreeItemBase* constructTreeItem(BorlandSegmentEntry* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("base", new TreeItem<uint16_t>(&rhs->base));
    ptree->appendChild("size", new TreeItem<uint16_t>(&rhs->size));
    ptree->appendChild("type", new TreeItem<uint16_t>(&rhs->type));
    ptree->appendChild("offset", new TreeItem<uint16_t>(&rhs->offset));
    return ptree;
}

TreeItemBase* constructTreeItem(BorlandStub* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreeint_code = ptree;
    if (2 > 3)
    {
        ptreeint_code = new TreeItemBase("int_code");
        ptree->appendTree(ptreeint_code, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "int_code[" << i << "]";
          ptreeint_code->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->int_code[i]));
    }
    ptree->appendChild("memswap", new TreeItem<uint16_t>(&rhs->memswap));
    ptree->appendChild("fileoff", new TreeItem<uint32_t>(&rhs->fileoff));
    ptree->appendChild("codesize", new TreeItem<uint16_t>(&rhs->codesize));
    ptree->appendChild("relsize", new TreeItem<uint16_t>(&rhs->relsize));
    ptree->appendChild("nentries", new TreeItem<uint16_t>(&rhs->nentries));
    ptree->appendChild("prevstub", new TreeItem<uint16_t>(&rhs->prevstub));
    TreeItemBase* ptreeworkarea = ptree;
    if (0x10 > 3)
    {
        ptreeworkarea = new TreeItemBase("workarea");
        ptree->appendTree(ptreeworkarea, "");
    }
    for (int i = 0; i < 0x10; ++i)
    {
          std::ostringstream oss;
          oss << "workarea[" << i << "]";
          ptreeworkarea->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->workarea[i]));
    }
    TreeItemBase* ptreeentries = ptree;
    if (1 > 3)
    {
        ptreeentries = new TreeItemBase("entries");
        ptree->appendTree(ptreeentries, "");
    }
    for (int i = 0; i < 1; ++i)
    {
          std::ostringstream oss;
          oss << "entries[" << i << "]";
          ptreeentries->appendTree(constructTreeItem(&rhs->entries[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(BorlandStubJmpEntry* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("jmpfar_code", new TreeItem<uint8_t>(&rhs->jmpfar_code));
    ptree->appendChild("offset", new TreeItem<uint16_t>(&rhs->offset));
    ptree->appendChild("base_addr", new TreeItem<uint16_t>(&rhs->base_addr));
    return ptree;
}

TreeItemBase* constructTreeItem(Building_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_BuildingName", new TreeItem<char[20]>(rhs->m_BuildingName));
    ptree->appendChild("m_Prerequisite1", new TreeItem<eBuilding>(&rhs->m_Prerequisite1));
    ptree->appendChild("m_Prerequisite2", new TreeItem<eBuilding>(&rhs->m_Prerequisite2));
    ptree->appendChild("m_Replaces_building", new TreeItem<eBuilding>(&rhs->m_Replaces_building));
    ptree->appendChild("m_Produces_Regulars", new TreeItem<eYesNo16>(&rhs->m_Produces_Regulars));
    ptree->appendChild("m_Produces_Veterans", new TreeItem<eYesNo16>(&rhs->m_Produces_Veterans));
    ptree->appendChild("m_Produces_Magic_Weapons", new TreeItem<eYesNo16>(&rhs->m_Produces_Magic_Weapons));
    ptree->appendChild("m_Upkeep_yield", new TreeItem<int16_t>(&rhs->m_Upkeep_yield));
    ptree->appendChild("m_Food_and_pop_bonus", new TreeItem<uint16_t>(&rhs->m_Food_and_pop_bonus));
    ptree->appendChild("m_Zero_24", new TreeItem<uint16_t>(&rhs->m_Zero_24));
    ptree->appendChild("m_Unk_26", new TreeItem<uint16_t>(&rhs->m_Unk_26));
    ptree->appendChild("m_Mana_produced", new TreeItem<uint16_t>(&rhs->m_Mana_produced));
    ptree->appendChild("m_Unk_2A", new TreeItem<uint16_t>(&rhs->m_Unk_2A));
    ptree->appendChild("m_Building_cost", new TreeItem<uint16_t>(&rhs->m_Building_cost));
    ptree->appendChild("m_Zero_2E", new TreeItem<uint16_t>(&rhs->m_Zero_2E));
    ptree->appendChild("m_Unk_30", new TreeItem<uint16_t>(&rhs->m_Unk_30));
    ptree->appendChild("m_Unk_32", new TreeItem<uint16_t>(&rhs->m_Unk_32));
    return ptree;
}

TreeItemBase* constructTreeItem(Building_Status* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("None", new TreeItem<eBuildingStatus>(&rhs->None));
    ptree->appendChild("Trade_Goods", new TreeItem<eBuildingStatus>(&rhs->Trade_Goods));
    ptree->appendChild("Housing", new TreeItem<eBuildingStatus>(&rhs->Housing));
    ptree->appendChild("Barracks", new TreeItem<eBuildingStatus>(&rhs->Barracks));
    ptree->appendChild("Armory", new TreeItem<eBuildingStatus>(&rhs->Armory));
    ptree->appendChild("Fighters_Guild", new TreeItem<eBuildingStatus>(&rhs->Fighters_Guild));
    ptree->appendChild("Armorers_Guild", new TreeItem<eBuildingStatus>(&rhs->Armorers_Guild));
    ptree->appendChild("War_College", new TreeItem<eBuildingStatus>(&rhs->War_College));
    ptree->appendChild("Smithy", new TreeItem<eBuildingStatus>(&rhs->Smithy));
    ptree->appendChild("Stable", new TreeItem<eBuildingStatus>(&rhs->Stable));
    ptree->appendChild("Animists_Guild", new TreeItem<eBuildingStatus>(&rhs->Animists_Guild));
    ptree->appendChild("Fantastic_Stable", new TreeItem<eBuildingStatus>(&rhs->Fantastic_Stable));
    ptree->appendChild("Shipwright_Guild", new TreeItem<eBuildingStatus>(&rhs->Shipwright_Guild));
    ptree->appendChild("Ship_Yard", new TreeItem<eBuildingStatus>(&rhs->Ship_Yard));
    ptree->appendChild("Maritime_Guild", new TreeItem<eBuildingStatus>(&rhs->Maritime_Guild));
    ptree->appendChild("Sawmill", new TreeItem<eBuildingStatus>(&rhs->Sawmill));
    ptree->appendChild("Library", new TreeItem<eBuildingStatus>(&rhs->Library));
    ptree->appendChild("Sages_Guild", new TreeItem<eBuildingStatus>(&rhs->Sages_Guild));
    ptree->appendChild("Oracle", new TreeItem<eBuildingStatus>(&rhs->Oracle));
    ptree->appendChild("Alchemist_Guild", new TreeItem<eBuildingStatus>(&rhs->Alchemist_Guild));
    ptree->appendChild("University", new TreeItem<eBuildingStatus>(&rhs->University));
    ptree->appendChild("Wizards_Guild", new TreeItem<eBuildingStatus>(&rhs->Wizards_Guild));
    ptree->appendChild("Shrine", new TreeItem<eBuildingStatus>(&rhs->Shrine));
    ptree->appendChild("Temple", new TreeItem<eBuildingStatus>(&rhs->Temple));
    ptree->appendChild("Parthenon", new TreeItem<eBuildingStatus>(&rhs->Parthenon));
    ptree->appendChild("Cathedral", new TreeItem<eBuildingStatus>(&rhs->Cathedral));
    ptree->appendChild("Marketplace", new TreeItem<eBuildingStatus>(&rhs->Marketplace));
    ptree->appendChild("Bank", new TreeItem<eBuildingStatus>(&rhs->Bank));
    ptree->appendChild("Merchants_Guild", new TreeItem<eBuildingStatus>(&rhs->Merchants_Guild));
    ptree->appendChild("Granary", new TreeItem<eBuildingStatus>(&rhs->Granary));
    ptree->appendChild("Farmers_Market", new TreeItem<eBuildingStatus>(&rhs->Farmers_Market));
    ptree->appendChild("Foresters_Guild", new TreeItem<eBuildingStatus>(&rhs->Foresters_Guild));
    ptree->appendChild("Builders_Hall", new TreeItem<eBuildingStatus>(&rhs->Builders_Hall));
    ptree->appendChild("Mechanicians_Guild", new TreeItem<eBuildingStatus>(&rhs->Mechanicians_Guild));
    ptree->appendChild("Miners_Guild", new TreeItem<eBuildingStatus>(&rhs->Miners_Guild));
    ptree->appendChild("City_Walls", new TreeItem<eBuildingStatus>(&rhs->City_Walls));
    return ptree;
}

TreeItemBase* constructTreeItem(City* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Name", new TreeItem<char[14]>(rhs->m_City_Name));
    ptree->appendChild("m_Race", new TreeItem<eRace>(&rhs->m_Race));
    ptree->appendChild("m_XPos", new TreeItem<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new TreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Size", new TreeItem<eCity_Size>(&rhs->m_Size));
    ptree->appendChild("m_Population", new TreeItem<uint8_t>(&rhs->m_Population));
    ptree->appendChild("m_Number_of_farmers_allocated", new TreeItem<uint8_t>(&rhs->m_Number_of_farmers_allocated));
    TreeItemBase* ptreem_UNK01a = ptree;
    if (2 > 3)
    {
        ptreem_UNK01a = new TreeItemBase("m_UNK01a");
        ptree->appendTree(ptreem_UNK01a, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01a[" << i << "]";
          ptreem_UNK01a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK01a[i]));
    }
    ptree->appendChild("m_PopulationDekaPop", new TreeItem<uint8_t>(&rhs->m_PopulationDekaPop));
    ptree->appendChild("m_UNK01b", new TreeItem<uint8_t>(&rhs->m_UNK01b));
    ptree->appendChild("m_Player_as_bitmask_GUESS", new TreeItem<uint8_t>(&rhs->m_Player_as_bitmask_GUESS));
    ptree->appendChild("m_UNK01c", new TreeItem<uint8_t>(&rhs->m_UNK01c));
    ptree->appendChild("m_Producing", new TreeItem<eProducing>(&rhs->m_Producing));
    ptree->appendChild("m_UNK02", new TreeItem<uint8_t>(&rhs->m_UNK02));
    ptree->appendTree(constructTreeItem(&rhs->m_Building_Status, "m_Building_Status"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
    ptree->appendChild("m_Nightshade", new TreeItem<eYesNo8>(&rhs->m_Nightshade));
    ptree->appendChild("m_Hammers", new TreeItem<uint8_t>(&rhs->m_Hammers));
    ptree->appendChild("m_HammersAccumulated", new TreeItem<uint16_t>(&rhs->m_HammersAccumulated));
    ptree->appendChild("m_Coins", new TreeItem<uint8_t>(&rhs->m_Coins));
    ptree->appendChild("m_Maintenance", new TreeItem<uint8_t>(&rhs->m_Maintenance));
    ptree->appendChild("m_Mana_cr", new TreeItem<uint8_t>(&rhs->m_Mana_cr));
    ptree->appendChild("m_Research", new TreeItem<uint8_t>(&rhs->m_Research));
    ptree->appendChild("m_Food_Produced", new TreeItem<uint8_t>(&rhs->m_Food_Produced));
    ptree->appendChild("m_Road_Connection_GUESS", new TreeItem<int8_t>(&rhs->m_Road_Connection_GUESS));
    TreeItemBase* ptreem_UNK03 = ptree;
    if (12 > 3)
    {
        ptreem_UNK03 = new TreeItemBase("m_UNK03");
        ptree->appendTree(ptreem_UNK03, "");
    }
    for (int i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03[" << i << "]";
          ptreem_UNK03->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK03[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(City_Enchantments* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Wall_of_Fire", new TreeItem<eOwner>(&rhs->Wall_of_Fire));
    ptree->appendChild("_Chaos_Rift_", new TreeItem<eOwner>(&rhs->_Chaos_Rift_));
    ptree->appendChild("Dark_Rituals", new TreeItem<eOwner>(&rhs->Dark_Rituals));
    ptree->appendChild("_Evil_Presence_", new TreeItem<eOwner>(&rhs->_Evil_Presence_));
    ptree->appendChild("_Cursed_Lands_", new TreeItem<eOwner>(&rhs->_Cursed_Lands_));
    ptree->appendChild("_Pestilence_", new TreeItem<eOwner>(&rhs->_Pestilence_));
    ptree->appendChild("Cloud_of_Shadow", new TreeItem<eOwner>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("_Famine_", new TreeItem<eOwner>(&rhs->_Famine_));
    ptree->appendChild("Flying_Fortress", new TreeItem<eOwner>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new TreeItem<eOwner>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new TreeItem<eOwner>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new TreeItem<eOwner>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new TreeItem<eOwner>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new TreeItem<eOwner>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new TreeItem<eOwner>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new TreeItem<eOwner>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new TreeItem<eOwner>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new TreeItem<eOwner>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new TreeItem<eOwner>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new TreeItem<eOwner>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new TreeItem<eOwner>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new TreeItem<eOwner>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new TreeItem<eOwner>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new TreeItem<eOwner>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new TreeItem<eOwner>(&rhs->Altar_of_Battle));
    return ptree;
}

TreeItemBase* constructTreeItem(Combat_Enchantment* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Combat_Enchantment maskVertigo;
    memset(&maskVertigo, '\0', sizeof(maskVertigo));
    maskVertigo.Vertigo = 0xFF;
    if (1 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVertigo));
    else if (2 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVertigo));
    else
        ptree->appendChild("Vertigo", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVertigo));
    Combat_Enchantment maskConfusion;
    memset(&maskConfusion, '\0', sizeof(maskConfusion));
    maskConfusion.Confusion = 0xFF;
    if (1 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConfusion));
    else if (2 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConfusion));
    else
        ptree->appendChild("Confusion", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConfusion));
    Combat_Enchantment maskWhirlwind;
    memset(&maskWhirlwind, '\0', sizeof(maskWhirlwind));
    maskWhirlwind.Whirlwind = 0xFF;
    if (1 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWhirlwind));
    else if (2 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWhirlwind));
    else
        ptree->appendChild("Whirlwind", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWhirlwind));
    Combat_Enchantment maskMind_Storm;
    memset(&maskMind_Storm, '\0', sizeof(maskMind_Storm));
    maskMind_Storm.Mind_Storm = 0xFF;
    if (1 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Storm));
    else if (2 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Storm));
    else
        ptree->appendChild("Mind_Storm", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Storm));
    Combat_Enchantment maskShatter;
    memset(&maskShatter, '\0', sizeof(maskShatter));
    maskShatter.Shatter = 0xFF;
    if (1 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskShatter));
    else if (2 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskShatter));
    else
        ptree->appendChild("Shatter", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskShatter));
    Combat_Enchantment maskWeakness;
    memset(&maskWeakness, '\0', sizeof(maskWeakness));
    maskWeakness.Weakness = 0xFF;
    if (1 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeakness));
    else if (2 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeakness));
    else
        ptree->appendChild("Weakness", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeakness));
    Combat_Enchantment maskBlack_Sleep;
    memset(&maskBlack_Sleep, '\0', sizeof(maskBlack_Sleep));
    maskBlack_Sleep.Black_Sleep = 0xFF;
    if (1 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Sleep));
    else if (2 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Sleep));
    else
        ptree->appendChild("Black_Sleep", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Sleep));
    Combat_Enchantment maskWarp_Creature_Attack;
    memset(&maskWarp_Creature_Attack, '\0', sizeof(maskWarp_Creature_Attack));
    maskWarp_Creature_Attack.Warp_Creature_Attack = 0xFF;
    if (1 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Attack));
    else if (2 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Attack));
    else
        ptree->appendChild("Warp_Creature_Attack", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Attack));
    Combat_Enchantment maskWarp_Creature_Defense;
    memset(&maskWarp_Creature_Defense, '\0', sizeof(maskWarp_Creature_Defense));
    maskWarp_Creature_Defense.Warp_Creature_Defense = 0xFF;
    if (1 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Defense));
    else if (2 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Defense));
    else
        ptree->appendChild("Warp_Creature_Defense", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Defense));
    Combat_Enchantment maskWarp_Creature_Resistance;
    memset(&maskWarp_Creature_Resistance, '\0', sizeof(maskWarp_Creature_Resistance));
    maskWarp_Creature_Resistance.Warp_Creature_Resistance = 0xFF;
    if (1 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Resistance));
    else if (2 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Resistance));
    else
        ptree->appendChild("Warp_Creature_Resistance", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Resistance));
    Combat_Enchantment maskMind_Twist;
    memset(&maskMind_Twist, '\0', sizeof(maskMind_Twist));
    maskMind_Twist.Mind_Twist = 0xFF;
    if (1 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Twist));
    else if (2 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Twist));
    else
        ptree->appendChild("Mind_Twist", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Twist));
    Combat_Enchantment maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 0xFF;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Combat_Enchantment maskWeb;
    memset(&maskWeb, '\0', sizeof(maskWeb));
    maskWeb.Web = 0xFF;
    if (1 == sizeof(maskWeb))
        ptree->appendChild("Web", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb));
    else if (2 == sizeof(maskWeb))
        ptree->appendChild("Web", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb));
    else
        ptree->appendChild("Web", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb));
    Combat_Enchantment maskCreature_Binding;
    memset(&maskCreature_Binding, '\0', sizeof(maskCreature_Binding));
    maskCreature_Binding.Creature_Binding = 0xFF;
    if (1 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreature_Binding));
    else if (2 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreature_Binding));
    else
        ptree->appendChild("Creature_Binding", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreature_Binding));
    Combat_Enchantment maskPossession;
    memset(&maskPossession, '\0', sizeof(maskPossession));
    maskPossession.Possession = 0xFF;
    if (1 == sizeof(maskPossession))
        ptree->appendChild("Possession", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPossession));
    else if (2 == sizeof(maskPossession))
        ptree->appendChild("Possession", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPossession));
    else
        ptree->appendChild("Possession", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPossession));
    Combat_Enchantment maskNo_Effect80;
    memset(&maskNo_Effect80, '\0', sizeof(maskNo_Effect80));
    maskNo_Effect80.No_Effect80 = 0xFF;
    if (1 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_Effect80));
    else if (2 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_Effect80));
    else
        ptree->appendChild("No_Effect80", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_Effect80));
    return ptree;
}

TreeItemBase* constructTreeItem(Difficulty_Table* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Growth_multiplier", new TreeItem<int16_t>(&rhs->m_City_Growth_multiplier));
    ptree->appendChild("m_Outpost_Growth_multiplier", new TreeItem<int16_t>(&rhs->m_Outpost_Growth_multiplier));
    ptree->appendChild("m_City_Production_multiplier", new TreeItem<int16_t>(&rhs->m_City_Production_multiplier));
    ptree->appendChild("m_City_Coin_multiplier", new TreeItem<int16_t>(&rhs->m_City_Coin_multiplier));
    ptree->appendChild("m_City_Mana_multiplier", new TreeItem<int16_t>(&rhs->m_City_Mana_multiplier));
    ptree->appendChild("m_City_Research_multiplier", new TreeItem<int16_t>(&rhs->m_City_Research_multiplier));
    ptree->appendChild("m_City_Food_multiplier", new TreeItem<int16_t>(&rhs->m_City_Food_multiplier));
    ptree->appendChild("m_City_Maintenance_multiplier", new TreeItem<int16_t>(&rhs->m_City_Maintenance_multiplier));
    return ptree;
}

TreeItemBase* constructTreeItem(EXE_Header* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("signature", new TreeItem<uint16_t>(&rhs->signature));
    ptree->appendChild("bytes_in_last_block", new TreeItem<uint16_t>(&rhs->bytes_in_last_block));
    ptree->appendChild("blocks_in_file", new TreeItem<uint16_t>(&rhs->blocks_in_file));
    ptree->appendChild("nr_relocation_items", new TreeItem<uint16_t>(&rhs->nr_relocation_items));
    ptree->appendChild("load_module_offset_paragraphs", new TreeItem<uint16_t>(&rhs->load_module_offset_paragraphs));
    ptree->appendChild("min_needed_paragraphs", new TreeItem<uint16_t>(&rhs->min_needed_paragraphs));
    ptree->appendChild("max_needed_paragraphs", new TreeItem<uint16_t>(&rhs->max_needed_paragraphs));
    ptree->appendChild("ss_offset_in_load_module_paragraphs", new TreeItem<uint16_t>(&rhs->ss_offset_in_load_module_paragraphs));
    ptree->appendChild("sp_initial", new TreeItem<uint16_t>(&rhs->sp_initial));
    ptree->appendChild("checksum", new TreeItem<uint16_t>(&rhs->checksum));
    ptree->appendChild("ip_program_entry_point", new TreeItem<uint16_t>(&rhs->ip_program_entry_point));
    ptree->appendChild("cs_offset_in_load_module_paragraphs", new TreeItem<uint16_t>(&rhs->cs_offset_in_load_module_paragraphs));
    ptree->appendChild("relocation_table_offset_bytes", new TreeItem<uint16_t>(&rhs->relocation_table_offset_bytes));
    ptree->appendChild("overlay_number", new TreeItem<uint16_t>(&rhs->overlay_number));
    return ptree;
}

TreeItemBase* constructTreeItem(EXE_Reloc* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("offset", new TreeItem<uint16_t>(&rhs->offset));
    ptree->appendChild("segment", new TreeItem<uint16_t>(&rhs->segment));
    return ptree;
}

TreeItemBase* constructTreeItem(Events_Status* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Turn_Event_triggered_GUESS", new TreeItem<uint16_t>(&rhs->m_Turn_Event_triggered_GUESS));
    ptree->appendChild("m_Meteor_active", new TreeItem<uint16_t>(&rhs->m_Meteor_active));
    ptree->appendChild("m_Meteor_playerNr", new TreeItem<uint16_t>(&rhs->m_Meteor_playerNr));
    ptree->appendChild("m_Meteor_cityNr", new TreeItem<uint16_t>(&rhs->m_Meteor_cityNr));
    ptree->appendChild("m_Gift_of_the_Gods_active", new TreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_active));
    ptree->appendChild("m_Gift_of_the_Gods_playerNr", new TreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_playerNr));
    ptree->appendChild("m_Gift_of_the_Gods_itemNr_GUESS", new TreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_itemNr_GUESS));
    ptree->appendChild("m_Disjunction_active", new TreeItem<uint16_t>(&rhs->m_Disjunction_active));
    ptree->appendChild("m_Diplomatic_Marriage_active", new TreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_active));
    ptree->appendChild("m_Diplomatic_Marriage_playerNr", new TreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_playerNr));
    ptree->appendChild("m_Diplomatic_Marriage_newCityNr_GUESS", new TreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_newCityNr_GUESS));
    ptree->appendChild("m_Diplomatic_Marriage_cityNr_GUESS", new TreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_cityNr_GUESS));
    ptree->appendChild("m_Earthquake_active", new TreeItem<uint16_t>(&rhs->m_Earthquake_active));
    ptree->appendChild("m_Earthquake_playerNr", new TreeItem<uint16_t>(&rhs->m_Earthquake_playerNr));
    ptree->appendChild("m_Earthquake_cityNr", new TreeItem<uint16_t>(&rhs->m_Earthquake_cityNr));
    ptree->appendChild("m_Pirates_active", new TreeItem<uint16_t>(&rhs->m_Pirates_active));
    ptree->appendChild("m_Pirates_playerNr", new TreeItem<uint16_t>(&rhs->m_Pirates_playerNr));
    ptree->appendChild("m_Pirates_gold_stolen", new TreeItem<uint16_t>(&rhs->m_Pirates_gold_stolen));
    ptree->appendChild("m_Plague_active", new TreeItem<uint16_t>(&rhs->m_Plague_active));
    ptree->appendChild("m_Plague_playerNr", new TreeItem<uint16_t>(&rhs->m_Plague_playerNr));
    ptree->appendChild("m_Plague_cityNr", new TreeItem<uint16_t>(&rhs->m_Plague_cityNr));
    ptree->appendChild("m_UNUSED01", new TreeItem<uint16_t>(&rhs->m_UNUSED01));
    ptree->appendChild("m_Rebellion_active", new TreeItem<uint16_t>(&rhs->m_Rebellion_active));
    ptree->appendChild("m_Rebellion_playerNr", new TreeItem<uint16_t>(&rhs->m_Rebellion_playerNr));
    ptree->appendChild("m_Rebellion_cityNr", new TreeItem<uint16_t>(&rhs->m_Rebellion_cityNr));
    ptree->appendChild("m_Donation_active", new TreeItem<uint16_t>(&rhs->m_Donation_active));
    ptree->appendChild("m_Donation_playerNr", new TreeItem<uint16_t>(&rhs->m_Donation_playerNr));
    ptree->appendChild("m_Donation_gold_donated", new TreeItem<uint16_t>(&rhs->m_Donation_gold_donated));
    ptree->appendChild("m_Depletion_active", new TreeItem<uint16_t>(&rhs->m_Depletion_active));
    ptree->appendChild("m_Depletion_playerNr", new TreeItem<uint16_t>(&rhs->m_Depletion_playerNr));
    ptree->appendChild("m_UNUSED02", new TreeItem<uint16_t>(&rhs->m_UNUSED02));
    ptree->appendChild("m_Mine_found_active", new TreeItem<uint16_t>(&rhs->m_Mine_found_active));
    ptree->appendChild("m_Mine_found_playerNr", new TreeItem<uint16_t>(&rhs->m_Mine_found_playerNr));
    ptree->appendChild("m_UNUSED03", new TreeItem<uint16_t>(&rhs->m_UNUSED03));
    ptree->appendChild("m_Population_Boom_active", new TreeItem<uint16_t>(&rhs->m_Population_Boom_active));
    ptree->appendChild("m_Population_Boom_CityNr", new TreeItem<uint16_t>(&rhs->m_Population_Boom_CityNr));
    ptree->appendChild("m_Population_Boom_PlayerNr", new TreeItem<uint16_t>(&rhs->m_Population_Boom_PlayerNr));
    ptree->appendChild("m_UNUSED04", new TreeItem<uint16_t>(&rhs->m_UNUSED04));
    ptree->appendChild("m_Good_Moon_active", new TreeItem<uint16_t>(&rhs->m_Good_Moon_active));
    ptree->appendChild("m_UNUSED05", new TreeItem<uint16_t>(&rhs->m_UNUSED05));
    ptree->appendChild("m_Bad_Moon_active", new TreeItem<uint16_t>(&rhs->m_Bad_Moon_active));
    ptree->appendChild("m_UNUSED06", new TreeItem<uint16_t>(&rhs->m_UNUSED06));
    ptree->appendChild("m_Conjunction_Sorcery_active", new TreeItem<uint16_t>(&rhs->m_Conjunction_Sorcery_active));
    ptree->appendChild("m_UNUSED07", new TreeItem<uint16_t>(&rhs->m_UNUSED07));
    ptree->appendChild("m_Conjunction_Nature_active", new TreeItem<uint16_t>(&rhs->m_Conjunction_Nature_active));
    ptree->appendChild("m_UNUSED08", new TreeItem<uint16_t>(&rhs->m_UNUSED08));
    ptree->appendChild("m_Conjunction_Chaos_active", new TreeItem<uint16_t>(&rhs->m_Conjunction_Chaos_active));
    ptree->appendChild("m_UNUSED09", new TreeItem<uint16_t>(&rhs->m_UNUSED09));
    ptree->appendChild("m_Mana_Short_active", new TreeItem<uint16_t>(&rhs->m_Mana_Short_active));
    ptree->appendChild("m_UNUSED10", new TreeItem<uint16_t>(&rhs->m_UNUSED10));
    return ptree;
}

TreeItemBase* constructTreeItem(Fortress* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Active", new TreeItem<uint8_t>(&rhs->m_Active));
    return ptree;
}

TreeItemBase* constructTreeItem(Game_Data_Save* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Number_of_Wizards", new TreeItem<uint16_t>(&rhs->m_Number_of_Wizards));
    ptree->appendChild("m_Land_Size_setting", new TreeItem<eLand_Size>(&rhs->m_Land_Size_setting));
    ptree->appendChild("m_Magic_Powerful_setting", new TreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    ptree->appendChild("m_Difficulty", new TreeItem<eDifficulty>(&rhs->m_Difficulty));
    ptree->appendChild("m_Number_of_Cities", new TreeItem<uint16_t>(&rhs->m_Number_of_Cities));
    ptree->appendChild("m_Number_of_Units", new TreeItem<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Current_Turn", new TreeItem<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_UnitNr_Active", new TreeItem<uint16_t>(&rhs->m_UnitNr_Active));
    return ptree;
}

TreeItemBase* constructTreeItem(Game_Settings* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Sound_Effects", new TreeItem<eYesNo16>(&rhs->m_Sound_Effects));
    ptree->appendChild("m_Background_Music", new TreeItem<eYesNo16>(&rhs->m_Background_Music));
    ptree->appendChild("m_Event_Music", new TreeItem<eYesNo16>(&rhs->m_Event_Music));
    ptree->appendChild("m_City_Spell_Events", new TreeItem<eYesNo16>(&rhs->m_City_Spell_Events));
    ptree->appendChild("m_Overland_Spell_Events", new TreeItem<eYesNo16>(&rhs->m_Overland_Spell_Events));
    ptree->appendChild("m_Summoning_Events", new TreeItem<eYesNo16>(&rhs->m_Summoning_Events));
    ptree->appendChild("m_End_of_Turn_Summary", new TreeItem<eYesNo16>(&rhs->m_End_of_Turn_Summary));
    ptree->appendChild("m_Raze_City", new TreeItem<eYesNo16>(&rhs->m_Raze_City));
    ptree->appendChild("m_Random_Events", new TreeItem<eYesNo16>(&rhs->m_Random_Events));
    ptree->appendChild("m_End_of_Turn_Wait", new TreeItem<eYesNo16>(&rhs->m_End_of_Turn_Wait));
    ptree->appendChild("m_Stratic_Combat_Only", new TreeItem<eYesNo16>(&rhs->m_Stratic_Combat_Only));
    ptree->appendChild("m_Auto_Unit_Information", new TreeItem<eYesNo16>(&rhs->m_Auto_Unit_Information));
    ptree->appendChild("m_Enemy_Moves", new TreeItem<eYesNo16>(&rhs->m_Enemy_Moves));
    ptree->appendChild("m_Enemy_Spells", new TreeItem<eYesNo16>(&rhs->m_Enemy_Spells));
    ptree->appendChild("m_Spell_Book_Ordering", new TreeItem<eYesNo16>(&rhs->m_Spell_Book_Ordering));
    ptree->appendChild("m_Spell_Animations", new TreeItem<eYesNo16>(&rhs->m_Spell_Animations));
    ptree->appendChild("m_Show_Node_Owners", new TreeItem<eYesNo16>(&rhs->m_Show_Node_Owners));
    ptree->appendChild("m_Expanding_Help", new TreeItem<eYesNo16>(&rhs->m_Expanding_Help));
    ptree->appendChild("m_UNK01", new TreeItem<uint16_t>(&rhs->m_UNK01));
    ptree->appendChild("m_UNK02", new TreeItem<uint16_t>(&rhs->m_UNK02));
    ptree->appendChild("m_Difficulty", new TreeItem<eDifficulty>(&rhs->m_Difficulty));
    ptree->appendChild("m_Nr_Opponents", new TreeItem<uint16_t>(&rhs->m_Nr_Opponents));
    ptree->appendChild("m_Land_Size", new TreeItem<eLand_Size>(&rhs->m_Land_Size));
    ptree->appendChild("m_Magic_Powerful", new TreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful));
    TreeItemBase* ptreem_Slots_Saved = ptree;
    if (8 > 3)
    {
        ptreem_Slots_Saved = new TreeItemBase("m_Slots_Saved");
        ptree->appendTree(ptreem_Slots_Saved, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slots_Saved[" << i << "]";
          ptreem_Slots_Saved->appendChild(oss.str().c_str(), new TreeItem<eYesNo16>(&rhs->m_Slots_Saved[i]));
    }
    TreeItemBase* ptreem_Save_Names = ptree;
    if (8 > 3)
    {
        ptreem_Save_Names = new TreeItemBase("m_Save_Names");
        ptree->appendTree(ptreem_Save_Names, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Names[" << i << "]";
          ptreem_Save_Names->appendTree(constructTreeItem(&rhs->m_Save_Names[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Movement_Animations", new TreeItem<eYesNo16>(&rhs->m_Movement_Animations));
    TreeItemBase* ptreem_Save_Wizard_Names = ptree;
    if (10 > 3)
    {
        ptreem_Save_Wizard_Names = new TreeItemBase("m_Save_Wizard_Names");
        ptree->appendTree(ptreem_Save_Wizard_Names, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Wizard_Names[" << i << "]";
          ptreem_Save_Wizard_Names->appendTree(constructTreeItem(&rhs->m_Save_Wizard_Names[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK03 = ptree;
    if (20 > 3)
    {
        ptreem_UNK03 = new TreeItemBase("m_UNK03");
        ptree->appendTree(ptreem_UNK03, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03[" << i << "]";
          ptreem_UNK03->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_UNK03[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Global_Enchantments* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Eternal_Night", new TreeItem<uint8_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new TreeItem<uint8_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new TreeItem<uint8_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new TreeItem<uint8_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new TreeItem<uint8_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new TreeItem<uint8_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new TreeItem<uint8_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new TreeItem<uint8_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new TreeItem<uint8_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new TreeItem<uint8_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new TreeItem<uint8_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new TreeItem<uint8_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new TreeItem<uint8_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new TreeItem<uint8_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new TreeItem<uint8_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new TreeItem<uint8_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new TreeItem<uint8_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new TreeItem<uint8_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new TreeItem<uint8_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new TreeItem<uint8_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new TreeItem<uint8_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new TreeItem<uint8_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new TreeItem<uint8_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new TreeItem<uint8_t>(&rhs->Awareness));
    return ptree;
}

TreeItemBase* constructTreeItem(Hero_Ability* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Hero_Ability maskLeadership;
    memset(&maskLeadership, '\0', sizeof(maskLeadership));
    maskLeadership.Leadership = 0xFF;
    if (1 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership));
    else if (2 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership));
    else
        ptree->appendChild("Leadership", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership));
    Hero_Ability maskLeadership_X;
    memset(&maskLeadership_X, '\0', sizeof(maskLeadership_X));
    maskLeadership_X.Leadership_X = 0xFF;
    if (1 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership_X));
    else if (2 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership_X));
    else
        ptree->appendChild("Leadership_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership_X));
    Hero_Ability masku1;
    memset(&masku1, '\0', sizeof(masku1));
    masku1.u1 = 0xFF;
    if (1 == sizeof(masku1))
        ptree->appendChild("u1", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku1));
    else if (2 == sizeof(masku1))
        ptree->appendChild("u1", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku1));
    else
        ptree->appendChild("u1", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku1));
    Hero_Ability maskLegendary;
    memset(&maskLegendary, '\0', sizeof(maskLegendary));
    maskLegendary.Legendary = 0xFF;
    if (1 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary));
    else if (2 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary));
    else
        ptree->appendChild("Legendary", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary));
    Hero_Ability maskLegendary_X;
    memset(&maskLegendary_X, '\0', sizeof(maskLegendary_X));
    maskLegendary_X.Legendary_X = 0xFF;
    if (1 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary_X));
    else if (2 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary_X));
    else
        ptree->appendChild("Legendary_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary_X));
    Hero_Ability masku0;
    memset(&masku0, '\0', sizeof(masku0));
    masku0.u0 = 0xFF;
    if (1 == sizeof(masku0))
        ptree->appendChild("u0", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku0));
    else if (2 == sizeof(masku0))
        ptree->appendChild("u0", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku0));
    else
        ptree->appendChild("u0", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku0));
    Hero_Ability maskBlademaster;
    memset(&maskBlademaster, '\0', sizeof(maskBlademaster));
    maskBlademaster.Blademaster = 0xFF;
    if (1 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster));
    else if (2 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster));
    else
        ptree->appendChild("Blademaster", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster));
    Hero_Ability maskBlademaster_X;
    memset(&maskBlademaster_X, '\0', sizeof(maskBlademaster_X));
    maskBlademaster_X.Blademaster_X = 0xFF;
    if (1 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster_X));
    else if (2 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster_X));
    else
        ptree->appendChild("Blademaster_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster_X));
    Hero_Ability masku4;
    memset(&masku4, '\0', sizeof(masku4));
    masku4.u4 = 0xFF;
    if (1 == sizeof(masku4))
        ptree->appendChild("u4", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku4));
    else if (2 == sizeof(masku4))
        ptree->appendChild("u4", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku4));
    else
        ptree->appendChild("u4", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku4));
    Hero_Ability maskArmsmaster;
    memset(&maskArmsmaster, '\0', sizeof(maskArmsmaster));
    maskArmsmaster.Armsmaster = 0xFF;
    if (1 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster));
    else if (2 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster));
    else
        ptree->appendChild("Armsmaster", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster));
    Hero_Ability maskArmsmaster_X;
    memset(&maskArmsmaster_X, '\0', sizeof(maskArmsmaster_X));
    maskArmsmaster_X.Armsmaster_X = 0xFF;
    if (1 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster_X));
    else if (2 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster_X));
    else
        ptree->appendChild("Armsmaster_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster_X));
    Hero_Ability masku3;
    memset(&masku3, '\0', sizeof(masku3));
    masku3.u3 = 0xFF;
    if (1 == sizeof(masku3))
        ptree->appendChild("u3", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku3));
    else if (2 == sizeof(masku3))
        ptree->appendChild("u3", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku3));
    else
        ptree->appendChild("u3", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku3));
    Hero_Ability maskConstitution;
    memset(&maskConstitution, '\0', sizeof(maskConstitution));
    maskConstitution.Constitution = 0xFF;
    if (1 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution));
    else if (2 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution));
    else
        ptree->appendChild("Constitution", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution));
    Hero_Ability maskConstitution_X;
    memset(&maskConstitution_X, '\0', sizeof(maskConstitution_X));
    maskConstitution_X.Constitution_X = 0xFF;
    if (1 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution_X));
    else if (2 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution_X));
    else
        ptree->appendChild("Constitution_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution_X));
    Hero_Ability masku2;
    memset(&masku2, '\0', sizeof(masku2));
    masku2.u2 = 0xFF;
    if (1 == sizeof(masku2))
        ptree->appendChild("u2", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku2));
    else if (2 == sizeof(masku2))
        ptree->appendChild("u2", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku2));
    else
        ptree->appendChild("u2", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku2));
    Hero_Ability maskMight;
    memset(&maskMight, '\0', sizeof(maskMight));
    maskMight.Might = 0xFF;
    if (1 == sizeof(maskMight))
        ptree->appendChild("Might", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight));
    else if (2 == sizeof(maskMight))
        ptree->appendChild("Might", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight));
    else
        ptree->appendChild("Might", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight));
    Hero_Ability maskMight_X;
    memset(&maskMight_X, '\0', sizeof(maskMight_X));
    maskMight_X.Might_X = 0xFF;
    if (1 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight_X));
    else if (2 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight_X));
    else
        ptree->appendChild("Might_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight_X));
    Hero_Ability masku7;
    memset(&masku7, '\0', sizeof(masku7));
    masku7.u7 = 0xFF;
    if (1 == sizeof(masku7))
        ptree->appendChild("u7", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku7));
    else if (2 == sizeof(masku7))
        ptree->appendChild("u7", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku7));
    else
        ptree->appendChild("u7", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku7));
    Hero_Ability maskArcane_Power;
    memset(&maskArcane_Power, '\0', sizeof(maskArcane_Power));
    maskArcane_Power.Arcane_Power = 0xFF;
    if (1 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power));
    else if (2 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power));
    else
        ptree->appendChild("Arcane_Power", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power));
    Hero_Ability maskArcane_Power_X;
    memset(&maskArcane_Power_X, '\0', sizeof(maskArcane_Power_X));
    maskArcane_Power_X.Arcane_Power_X = 0xFF;
    if (1 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power_X));
    else if (2 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power_X));
    else
        ptree->appendChild("Arcane_Power_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power_X));
    Hero_Ability masku6;
    memset(&masku6, '\0', sizeof(masku6));
    masku6.u6 = 0xFF;
    if (1 == sizeof(masku6))
        ptree->appendChild("u6", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku6));
    else if (2 == sizeof(masku6))
        ptree->appendChild("u6", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku6));
    else
        ptree->appendChild("u6", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku6));
    Hero_Ability maskSage;
    memset(&maskSage, '\0', sizeof(maskSage));
    maskSage.Sage = 0xFF;
    if (1 == sizeof(maskSage))
        ptree->appendChild("Sage", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage));
    else if (2 == sizeof(maskSage))
        ptree->appendChild("Sage", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage));
    else
        ptree->appendChild("Sage", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage));
    Hero_Ability maskSage_X;
    memset(&maskSage_X, '\0', sizeof(maskSage_X));
    maskSage_X.Sage_X = 0xFF;
    if (1 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage_X));
    else if (2 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage_X));
    else
        ptree->appendChild("Sage_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage_X));
    Hero_Ability masku5;
    memset(&masku5, '\0', sizeof(masku5));
    masku5.u5 = 0xFF;
    if (1 == sizeof(masku5))
        ptree->appendChild("u5", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku5));
    else if (2 == sizeof(masku5))
        ptree->appendChild("u5", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku5));
    else
        ptree->appendChild("u5", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku5));
    Hero_Ability maskPrayermaster;
    memset(&maskPrayermaster, '\0', sizeof(maskPrayermaster));
    maskPrayermaster.Prayermaster = 0xFF;
    if (1 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster));
    else if (2 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster));
    else
        ptree->appendChild("Prayermaster", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster));
    Hero_Ability maskPrayermaster_X;
    memset(&maskPrayermaster_X, '\0', sizeof(maskPrayermaster_X));
    maskPrayermaster_X.Prayermaster_X = 0xFF;
    if (1 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster_X));
    else if (2 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster_X));
    else
        ptree->appendChild("Prayermaster_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster_X));
    Hero_Ability maskAgility_X;
    memset(&maskAgility_X, '\0', sizeof(maskAgility_X));
    maskAgility_X.Agility_X = 0xFF;
    if (1 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility_X));
    else if (2 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility_X));
    else
        ptree->appendChild("Agility_X", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility_X));
    Hero_Ability maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 0xFF;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Hero_Ability maskCharmed;
    memset(&maskCharmed, '\0', sizeof(maskCharmed));
    maskCharmed.Charmed = 0xFF;
    if (1 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCharmed));
    else if (2 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCharmed));
    else
        ptree->appendChild("Charmed", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCharmed));
    Hero_Ability maskNoble;
    memset(&maskNoble, '\0', sizeof(maskNoble));
    maskNoble.Noble = 0xFF;
    if (1 == sizeof(maskNoble))
        ptree->appendChild("Noble", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNoble));
    else if (2 == sizeof(maskNoble))
        ptree->appendChild("Noble", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNoble));
    else
        ptree->appendChild("Noble", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNoble));
    Hero_Ability masku8;
    memset(&masku8, '\0', sizeof(masku8));
    masku8.u8 = 0xFF;
    if (1 == sizeof(masku8))
        ptree->appendChild("u8", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku8));
    else if (2 == sizeof(masku8))
        ptree->appendChild("u8", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku8));
    else
        ptree->appendChild("u8", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku8));
    Hero_Ability maskAgility;
    memset(&maskAgility, '\0', sizeof(maskAgility));
    maskAgility.Agility = 0xFF;
    if (1 == sizeof(maskAgility))
        ptree->appendChild("Agility", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility));
    else if (2 == sizeof(maskAgility))
        ptree->appendChild("Agility", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility));
    else
        ptree->appendChild("Agility", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility));
    return ptree;
}

TreeItemBase* constructTreeItem(Hero_Choice* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new TreeItem<char[14]>(rhs->m_Name));
    TreeItemBase* ptreem_UNK = ptree;
    if (2 > 3)
    {
        ptreem_UNK = new TreeItemBase("m_UNK");
        ptree->appendTree(ptreem_UNK, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK[" << i << "]";
          ptreem_UNK->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Hero_Stats_Initializer* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Nr_Random_picks", new TreeItem<uint16_t>(&rhs->m_Nr_Random_picks));
    ptree->appendChild("m_Random_pick_type", new TreeItem<eRandomPickType>(&rhs->m_Random_pick_type));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new TreeItem<uint16_t>(&rhs->m_Hero_Casting_Skill));
    TreeItemBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new TreeItemBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new TreeItem<eSpell16>(&rhs->m_Spell[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Hero_stats* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Level_Status", new TreeItem<eHero_Level_Status>(&rhs->m_Level_Status));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new TreeItem<uint8_t>(&rhs->m_Hero_Casting_Skill));
    TreeItemBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new TreeItemBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new TreeItem<eSpell>(&rhs->m_Spell[i]));
    }
    ptree->appendChild("m_Garbage", new TreeItem<uint8_t>(&rhs->m_Garbage));
    return ptree;
}

TreeItemBase* constructTreeItem(Hired_Hero* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Unit_Nr", new TreeItem<int16_t>(&rhs->m_Unit_Nr));
    ptree->appendChild("m_Hero_name", new TreeItem<char[14]>(rhs->m_Hero_name));
    TreeItemBase* ptreem_Items_In_Slot = ptree;
    if (3 > 3)
    {
        ptreem_Items_In_Slot = new TreeItemBase("m_Items_In_Slot");
        ptree->appendTree(ptreem_Items_In_Slot, "");
    }
    for (int i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_In_Slot[" << i << "]";
          ptreem_Items_In_Slot->appendChild(oss.str().c_str(), new TreeItem<int16_t>(&rhs->m_Items_In_Slot[i]));
    }
    TreeItemBase* ptreem_Slot_Types = ptree;
    if (3 > 3)
    {
        ptreem_Slot_Types = new TreeItemBase("m_Slot_Types");
        ptree->appendTree(ptreem_Slot_Types, "");
    }
    for (int i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slot_Types[" << i << "]";
          ptreem_Slot_Types->appendChild(oss.str().c_str(), new TreeItem<eSlot_Type16>(&rhs->m_Slot_Types[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Immunity_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Immunity_Flags maskFire_Immunity;
    memset(&maskFire_Immunity, '\0', sizeof(maskFire_Immunity));
    maskFire_Immunity.Fire_Immunity = 0xFF;
    if (1 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Immunity));
    else if (2 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Immunity));
    else
        ptree->appendChild("Fire_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Immunity));
    Immunity_Flags maskStoning_Immunity;
    memset(&maskStoning_Immunity, '\0', sizeof(maskStoning_Immunity));
    maskStoning_Immunity.Stoning_Immunity = 0xFF;
    if (1 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Immunity));
    else if (2 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Immunity));
    else
        ptree->appendChild("Stoning_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Immunity));
    Immunity_Flags maskMissiles_Immunity;
    memset(&maskMissiles_Immunity, '\0', sizeof(maskMissiles_Immunity));
    maskMissiles_Immunity.Missiles_Immunity = 0xFF;
    if (1 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMissiles_Immunity));
    else if (2 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMissiles_Immunity));
    else
        ptree->appendChild("Missiles_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMissiles_Immunity));
    Immunity_Flags maskIllusions_Immunity;
    memset(&maskIllusions_Immunity, '\0', sizeof(maskIllusions_Immunity));
    maskIllusions_Immunity.Illusions_Immunity = 0xFF;
    if (1 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusions_Immunity));
    else if (2 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusions_Immunity));
    else
        ptree->appendChild("Illusions_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusions_Immunity));
    Immunity_Flags maskCold_Immunity;
    memset(&maskCold_Immunity, '\0', sizeof(maskCold_Immunity));
    maskCold_Immunity.Cold_Immunity = 0xFF;
    if (1 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCold_Immunity));
    else if (2 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCold_Immunity));
    else
        ptree->appendChild("Cold_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCold_Immunity));
    Immunity_Flags maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 0xFF;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Immunity_Flags maskDeath_Immunity;
    memset(&maskDeath_Immunity, '\0', sizeof(maskDeath_Immunity));
    maskDeath_Immunity.Death_Immunity = 0xFF;
    if (1 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Immunity));
    else if (2 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Immunity));
    else
        ptree->appendChild("Death_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Immunity));
    Immunity_Flags maskPoison_Immunity;
    memset(&maskPoison_Immunity, '\0', sizeof(maskPoison_Immunity));
    maskPoison_Immunity.Poison_Immunity = 0xFF;
    if (1 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_Immunity));
    else if (2 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_Immunity));
    else
        ptree->appendChild("Poison_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_Immunity));
    return ptree;
}

TreeItemBase* constructTreeItem(Item* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Item_Name", new TreeItem<char[30]>(rhs->m_Item_Name));
    ptree->appendChild("m_Icon", new TreeItem<eItem_Icon>(&rhs->m_Icon));
    ptree->appendChild("m_Slot_Required", new TreeItem<eSlot_Type8>(&rhs->m_Slot_Required));
    ptree->appendChild("m_Item_Type", new TreeItem<eItem_Type>(&rhs->m_Item_Type));
    ptree->appendChild("m_Cost", new TreeItem<int16_t>(&rhs->m_Cost));
    ptree->appendTree(constructTreeItem(&rhs->m_Bonuses, "m_Bonuses"), "");
    ptree->appendChild("m_Spell_Number_Charged", new TreeItem<eSpell>(&rhs->m_Spell_Number_Charged));
    ptree->appendChild("m_Number_Of_Charges", new TreeItem<int16_t>(&rhs->m_Number_Of_Charges));
    ptree->appendTree(constructTreeItem(&rhs->m_Bitmask_Powers, "m_Bitmask_Powers"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(ItemLBX* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Code = ptree;
    if (4 > 3)
    {
        ptreem_Code = new TreeItemBase("m_Code");
        ptree->appendTree(ptreem_Code, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Code[" << i << "]";
          ptreem_Code->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_Code[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Item, "m_Item"), "");
    TreeItemBase* ptreem_UNK01 = ptree;
    if (2 > 3)
    {
        ptreem_UNK01 = new TreeItemBase("m_UNK01");
        ptree->appendTree(ptreem_UNK01, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01[" << i << "]";
          ptreem_UNK01->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK01[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Item_Bonuses* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Attack", new TreeItem<int8_t>(&rhs->Attack));
    ptree->appendChild("To_Hit", new TreeItem<int8_t>(&rhs->To_Hit));
    ptree->appendChild("Defense", new TreeItem<int8_t>(&rhs->Defense));
    ptree->appendChild("Movement_in_halves", new TreeItem<int8_t>(&rhs->Movement_in_halves));
    ptree->appendChild("Resistance", new TreeItem<int8_t>(&rhs->Resistance));
    ptree->appendChild("Spell_Points", new TreeItem<int8_t>(&rhs->Spell_Points));
    ptree->appendChild("Spell_Save", new TreeItem<int8_t>(&rhs->Spell_Save));
    return ptree;
}

TreeItemBase* constructTreeItem(Item_Powers* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Item_Powers maskVampiric;
    memset(&maskVampiric, '\0', sizeof(maskVampiric));
    maskVampiric.Vampiric = 0xFF;
    if (1 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVampiric));
    else if (2 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVampiric));
    else
        ptree->appendChild("Vampiric", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVampiric));
    Item_Powers maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 0xFF;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Item_Powers maskLightning;
    memset(&maskLightning, '\0', sizeof(maskLightning));
    maskLightning.Lightning = 0xFF;
    if (1 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLightning));
    else if (2 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLightning));
    else
        ptree->appendChild("Lightning", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLightning));
    Item_Powers maskCloak_Of_Fear;
    memset(&maskCloak_Of_Fear, '\0', sizeof(maskCloak_Of_Fear));
    maskCloak_Of_Fear.Cloak_Of_Fear = 0xFF;
    if (1 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_Of_Fear));
    else if (2 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_Of_Fear));
    else
        ptree->appendChild("Cloak_Of_Fear", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_Of_Fear));
    Item_Powers maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 0xFF;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Item_Powers maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 0xFF;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Item_Powers maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 0xFF;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Item_Powers maskPathfinding;
    memset(&maskPathfinding, '\0', sizeof(maskPathfinding));
    maskPathfinding.Pathfinding = 0xFF;
    if (1 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPathfinding));
    else if (2 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPathfinding));
    else
        ptree->appendChild("Pathfinding", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPathfinding));
    Item_Powers maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 0xFF;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Item_Powers maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 0xFF;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Item_Powers maskElemental_Armour;
    memset(&maskElemental_Armour, '\0', sizeof(maskElemental_Armour));
    maskElemental_Armour.Elemental_Armour = 0xFF;
    if (1 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armour));
    else if (2 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armour));
    else
        ptree->appendChild("Elemental_Armour", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armour));
    Item_Powers maskDoom_equals_Chaos;
    memset(&maskDoom_equals_Chaos, '\0', sizeof(maskDoom_equals_Chaos));
    maskDoom_equals_Chaos.Doom_equals_Chaos = 0xFF;
    if (1 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoom_equals_Chaos));
    else if (2 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoom_equals_Chaos));
    else
        ptree->appendChild("Doom_equals_Chaos", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoom_equals_Chaos));
    Item_Powers maskStoning;
    memset(&maskStoning, '\0', sizeof(maskStoning));
    maskStoning.Stoning = 0xFF;
    if (1 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning));
    else if (2 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning));
    else
        ptree->appendChild("Stoning", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning));
    Item_Powers maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 0xFF;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Item_Powers maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 0xFF;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Item_Powers maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 0xFF;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Item_Powers maskDeath;
    memset(&maskDeath, '\0', sizeof(maskDeath));
    maskDeath.Death = 0xFF;
    if (1 == sizeof(maskDeath))
        ptree->appendChild("Death", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath));
    else if (2 == sizeof(maskDeath))
        ptree->appendChild("Death", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath));
    else
        ptree->appendChild("Death", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath));
    Item_Powers maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 0xFF;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Item_Powers maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 0xFF;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Item_Powers maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 0xFF;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Item_Powers maskFlaming;
    memset(&maskFlaming, '\0', sizeof(maskFlaming));
    maskFlaming.Flaming = 0xFF;
    if (1 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlaming));
    else if (2 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlaming));
    else
        ptree->appendChild("Flaming", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlaming));
    Item_Powers maskHoly_Avenger;
    memset(&maskHoly_Avenger, '\0', sizeof(maskHoly_Avenger));
    maskHoly_Avenger.Holy_Avenger = 0xFF;
    if (1 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Avenger));
    else if (2 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Avenger));
    else
        ptree->appendChild("Holy_Avenger", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Avenger));
    Item_Powers maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 0xFF;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Item_Powers maskPhantasmal;
    memset(&maskPhantasmal, '\0', sizeof(maskPhantasmal));
    maskPhantasmal.Phantasmal = 0xFF;
    if (1 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPhantasmal));
    else if (2 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPhantasmal));
    else
        ptree->appendChild("Phantasmal", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPhantasmal));
    Item_Powers maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 0xFF;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Item_Powers maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 0xFF;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Item_Powers maskLion_Heart;
    memset(&maskLion_Heart, '\0', sizeof(maskLion_Heart));
    maskLion_Heart.Lion_Heart = 0xFF;
    if (1 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLion_Heart));
    else if (2 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLion_Heart));
    else
        ptree->appendChild("Lion_Heart", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLion_Heart));
    Item_Powers maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 0xFF;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Item_Powers maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 0xFF;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Item_Powers maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 0xFF;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    Item_Powers maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 0xFF;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Item_Powers maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 0xFF;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

TreeItemBase* constructTreeItem(LBXHEADER* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("n", new TreeItem<uint16_t>(&rhs->n));
    ptree->appendChild("magic_number", new TreeItem<uint32_t>(&rhs->magic_number));
    ptree->appendChild("reserved", new TreeItem<uint16_t>(&rhs->reserved));
    return ptree;
}

TreeItemBase* constructTreeItem(Lair_Inhabitant* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Inhabitant", new TreeItem<eUnit_Type>(&rhs->m_Inhabitant));
    Lair_Inhabitant maskm_Remaining_Nr_of_Inhabitant;
    memset(&maskm_Remaining_Nr_of_Inhabitant, '\0', sizeof(maskm_Remaining_Nr_of_Inhabitant));
    maskm_Remaining_Nr_of_Inhabitant.m_Remaining_Nr_of_Inhabitant = 0xFF;
    if (1 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Remaining_Nr_of_Inhabitant));
    Lair_Inhabitant maskm_Initial_Nr_of_Inhabitant;
    memset(&maskm_Initial_Nr_of_Inhabitant, '\0', sizeof(maskm_Initial_Nr_of_Inhabitant));
    maskm_Initial_Nr_of_Inhabitant.m_Initial_Nr_of_Inhabitant = 0xFF;
    if (1 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Initial_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Initial_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Initial_Nr_of_Inhabitant));
    return ptree;
}

TreeItemBase* constructTreeItem(List_Hero_stats* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->Dwarf, "Dwarf"), "");
    ptree->appendTree(constructTreeItem(&rhs->Barbarian, "Barbarian"), "");
    ptree->appendTree(constructTreeItem(&rhs->Sage, "Sage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Dervish, "Dervish"), "");
    ptree->appendTree(constructTreeItem(&rhs->Beastmaster, "Beastmaster"), "");
    ptree->appendTree(constructTreeItem(&rhs->Bard, "Bard"), "");
    ptree->appendTree(constructTreeItem(&rhs->Orc_Warrior, "Orc_Warrior"), "");
    ptree->appendTree(constructTreeItem(&rhs->Healer, "Healer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Huntress, "Huntress"), "");
    ptree->appendTree(constructTreeItem(&rhs->Thief, "Thief"), "");
    ptree->appendTree(constructTreeItem(&rhs->Druid, "Druid"), "");
    ptree->appendTree(constructTreeItem(&rhs->War_Monk, "War_Monk"), "");
    ptree->appendTree(constructTreeItem(&rhs->Warrior_Mage, "Warrior_Mage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Magician, "Magician"), "");
    ptree->appendTree(constructTreeItem(&rhs->Assassin, "Assassin"), "");
    ptree->appendTree(constructTreeItem(&rhs->Wind_Mage, "Wind_Mage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Ranger, "Ranger"), "");
    ptree->appendTree(constructTreeItem(&rhs->Draconian, "Draconian"), "");
    ptree->appendTree(constructTreeItem(&rhs->Witch, "Witch"), "");
    ptree->appendTree(constructTreeItem(&rhs->Golden_One, "Golden_One"), "");
    ptree->appendTree(constructTreeItem(&rhs->Ninja, "Ninja"), "");
    ptree->appendTree(constructTreeItem(&rhs->Rogue, "Rogue"), "");
    ptree->appendTree(constructTreeItem(&rhs->Amazon, "Amazon"), "");
    ptree->appendTree(constructTreeItem(&rhs->Warlock, "Warlock"), "");
    ptree->appendTree(constructTreeItem(&rhs->Unknown, "Unknown"), "");
    ptree->appendTree(constructTreeItem(&rhs->Illusionist, "Illusionist"), "");
    ptree->appendTree(constructTreeItem(&rhs->Swordsman, "Swordsman"), "");
    ptree->appendTree(constructTreeItem(&rhs->Priestess, "Priestess"), "");
    ptree->appendTree(constructTreeItem(&rhs->Paladin, "Paladin"), "");
    ptree->appendTree(constructTreeItem(&rhs->Black_Knight, "Black_Knight"), "");
    ptree->appendTree(constructTreeItem(&rhs->Elven_Archer, "Elven_Archer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Knight, "Knight"), "");
    ptree->appendTree(constructTreeItem(&rhs->Necromancer, "Necromancer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Chaos_Warrior, "Chaos_Warrior"), "");
    ptree->appendTree(constructTreeItem(&rhs->Chosen, "Chosen"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(Location* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_Bonus* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Bonus_Deposit = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Bonus_Deposit[" << i << "]";
          ptreem_Bonus_Deposit->appendChild(oss.str().c_str(), new TreeItem<eBonusDeposit>(&rhs->m_Bonus_Deposit[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_Exploration* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Explored = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Explored[" << i << "]";
          ptreem_Explored->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_Explored[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_LandMassID* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_LandMassID = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_LandMassID[" << i << "]";
          ptreem_LandMassID->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_LandMassID[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_Movement* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Moves = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Moves[" << i << "]";
          ptreem_Moves->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_Moves[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_Terrain* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Tile = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tile[" << i << "]";
          ptreem_Tile->appendChild(oss.str().c_str(), new TreeItem<eTerrainType>(&rhs->m_Tile[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MapRow_Terrain_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Terrain_Flags = ptree;
    for (int i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Terrain_Flags[" << i << "]";
          ptreem_Terrain_Flags->appendTree(constructTreeItem(&rhs->m_Terrain_Flags[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Map_Attr* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Arcanus_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Bonus_Row = new TreeItemBase("m_Arcanus_Bonus_Row");
        ptree->appendTree(ptreem_Arcanus_Bonus_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Bonus_Row[" << i << "]";
          ptreem_Arcanus_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Bonus_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Bonus_Row = new TreeItemBase("m_Myrror_Bonus_Row");
        ptree->appendTree(ptreem_Myrror_Bonus_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Bonus_Row[" << i << "]";
          ptreem_Myrror_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Bonus_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Arcanus_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Exploration_Row = new TreeItemBase("m_Arcanus_Exploration_Row");
        ptree->appendTree(ptreem_Arcanus_Exploration_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Exploration_Row[" << i << "]";
          ptreem_Arcanus_Exploration_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Exploration_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Exploration_Row = new TreeItemBase("m_Myrror_Exploration_Row");
        ptree->appendTree(ptreem_Myrror_Exploration_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Exploration_Row[" << i << "]";
          ptreem_Myrror_Exploration_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Exploration_Row[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Arcanus_Movement, "m_Arcanus_Movement"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Myrror_Movement, "m_Myrror_Movement"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Events_Status, "m_Events_Status"), "");
    TreeItemBase* ptreem_Arcanus_Terrain_Flags_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Terrain_Flags_Row = new TreeItemBase("m_Arcanus_Terrain_Flags_Row");
        ptree->appendTree(ptreem_Arcanus_Terrain_Flags_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Terrain_Flags_Row[" << i << "]";
          ptreem_Arcanus_Terrain_Flags_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Terrain_Flags_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Terrain_Flags_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Terrain_Flags_Row = new TreeItemBase("m_Myrror_Terrain_Flags_Row");
        ptree->appendTree(ptreem_Myrror_Terrain_Flags_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Terrain_Flags_Row[" << i << "]";
          ptreem_Myrror_Terrain_Flags_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Terrain_Flags_Row[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Map_Movement* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Unused_Row = ptree;
    if (40 > 3)
    {
        ptreem_Unused_Row = new TreeItemBase("m_Unused_Row");
        ptree->appendTree(ptreem_Unused_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unused_Row[" << i << "]";
          ptreem_Unused_Row->appendTree(constructTreeItem(&rhs->m_Unused_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Walking_Row = ptree;
    if (40 > 3)
    {
        ptreem_Walking_Row = new TreeItemBase("m_Walking_Row");
        ptree->appendTree(ptreem_Walking_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Walking_Row[" << i << "]";
          ptreem_Walking_Row->appendTree(constructTreeItem(&rhs->m_Walking_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Forester_Row = ptree;
    if (40 > 3)
    {
        ptreem_Forester_Row = new TreeItemBase("m_Forester_Row");
        ptree->appendTree(ptreem_Forester_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Forester_Row[" << i << "]";
          ptreem_Forester_Row->appendTree(constructTreeItem(&rhs->m_Forester_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Mountaineer_Row = ptree;
    if (40 > 3)
    {
        ptreem_Mountaineer_Row = new TreeItemBase("m_Mountaineer_Row");
        ptree->appendTree(ptreem_Mountaineer_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Mountaineer_Row[" << i << "]";
          ptreem_Mountaineer_Row->appendTree(constructTreeItem(&rhs->m_Mountaineer_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Swimming_Row = ptree;
    if (40 > 3)
    {
        ptreem_Swimming_Row = new TreeItemBase("m_Swimming_Row");
        ptree->appendTree(ptreem_Swimming_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Swimming_Row[" << i << "]";
          ptreem_Swimming_Row->appendTree(constructTreeItem(&rhs->m_Swimming_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Sailing_Row = ptree;
    if (40 > 3)
    {
        ptreem_Sailing_Row = new TreeItemBase("m_Sailing_Row");
        ptree->appendTree(ptreem_Sailing_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Sailing_Row[" << i << "]";
          ptreem_Sailing_Row->appendTree(constructTreeItem(&rhs->m_Sailing_Row[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Map_Tiles* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_Arcanus_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Map_Row = new TreeItemBase("m_Arcanus_Map_Row");
        ptree->appendTree(ptreem_Arcanus_Map_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Map_Row[" << i << "]";
          ptreem_Arcanus_Map_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Map_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Map_Row = new TreeItemBase("m_Myrror_Map_Row");
        ptree->appendTree(ptreem_Myrror_Map_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Map_Row[" << i << "]";
          ptreem_Myrror_Map_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Map_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Arcanus_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Arcanus_UNK01 = new TreeItemBase("m_Arcanus_UNK01");
        ptree->appendTree(ptreem_Arcanus_UNK01, "");
    }
    for (int i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_UNK01[" << i << "]";
          ptreem_Arcanus_UNK01->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Arcanus_UNK01[i]));
    }
    TreeItemBase* ptreem_Myrror_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Myrror_UNK01 = new TreeItemBase("m_Myrror_UNK01");
        ptree->appendTree(ptreem_Myrror_UNK01, "");
    }
    for (int i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_UNK01[" << i << "]";
          ptreem_Myrror_UNK01->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Myrror_UNK01[i]));
    }
    TreeItemBase* ptreem_Arcanus_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_LandMassID_Row = new TreeItemBase("m_Arcanus_LandMassID_Row");
        ptree->appendTree(ptreem_Arcanus_LandMassID_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_LandMassID_Row[" << i << "]";
          ptreem_Arcanus_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_LandMassID_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_LandMassID_Row = new TreeItemBase("m_Myrror_LandMassID_Row");
        ptree->appendTree(ptreem_Myrror_LandMassID_Row, "");
    }
    for (int i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_LandMassID_Row[" << i << "]";
          ptreem_Myrror_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Myrror_LandMassID_Row[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Arcanus_Node_Attr = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Node_Attr = new TreeItemBase("m_Arcanus_Node_Attr");
        ptree->appendTree(ptreem_Arcanus_Node_Attr, "");
    }
    for (int i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Node_Attr[" << i << "]";
          ptreem_Arcanus_Node_Attr->appendTree(constructTreeItem(&rhs->m_Arcanus_Node_Attr[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Attr = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Attr = new TreeItemBase("m_Myrror_Attr");
        ptree->appendTree(ptreem_Myrror_Attr, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Attr[" << i << "]";
          ptreem_Myrror_Attr->appendTree(constructTreeItem(&rhs->m_Myrror_Attr[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Fortresses = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Fortresses = new TreeItemBase("m_Fortresses");
        ptree->appendTree(ptreem_Fortresses, "");
    }
    for (int i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Fortresses[" << i << "]";
          ptreem_Fortresses->appendTree(constructTreeItem(&rhs->m_Fortresses[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Tower_Attr = ptree;
    if (6 > 3)
    {
        ptreem_Tower_Attr = new TreeItemBase("m_Tower_Attr");
        ptree->appendTree(ptreem_Tower_Attr, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tower_Attr[" << i << "]";
          ptreem_Tower_Attr->appendTree(constructTreeItem(&rhs->m_Tower_Attr[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Arcanus_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Arcanus_Towers = new TreeItemBase("m_Arcanus_Towers");
        ptree->appendTree(ptreem_Arcanus_Towers, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Towers[" << i << "]";
          ptreem_Arcanus_Towers->appendTree(constructTreeItem(&rhs->m_Arcanus_Towers[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Myrror_Towers = new TreeItemBase("m_Myrror_Towers");
        ptree->appendTree(ptreem_Myrror_Towers, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Towers[" << i << "]";
          ptreem_Myrror_Towers->appendTree(constructTreeItem(&rhs->m_Myrror_Towers[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Arcanus_Nodes = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Nodes = new TreeItemBase("m_Arcanus_Nodes");
        ptree->appendTree(ptreem_Arcanus_Nodes, "");
    }
    for (int i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Nodes[" << i << "]";
          ptreem_Arcanus_Nodes->appendTree(constructTreeItem(&rhs->m_Arcanus_Nodes[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Myrror_Nodes = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Nodes = new TreeItemBase("m_Myrror_Nodes");
        ptree->appendTree(ptreem_Myrror_Nodes, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Nodes[" << i << "]";
          ptreem_Myrror_Nodes->appendTree(constructTreeItem(&rhs->m_Myrror_Nodes[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Normal_Lairs = ptree;
    if (25 > 3)
    {
        ptreem_Normal_Lairs = new TreeItemBase("m_Normal_Lairs");
        ptree->appendTree(ptreem_Normal_Lairs, "");
    }
    for (int i = 0; i < 25; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Lairs[" << i << "]";
          ptreem_Normal_Lairs->appendTree(constructTreeItem(&rhs->m_Normal_Lairs[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Weak_Lairs = ptree;
    if (32 > 3)
    {
        ptreem_Weak_Lairs = new TreeItemBase("m_Weak_Lairs");
        ptree->appendTree(ptreem_Weak_Lairs, "");
    }
    for (int i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_Weak_Lairs[" << i << "]";
          ptreem_Weak_Lairs->appendTree(constructTreeItem(&rhs->m_Weak_Lairs[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_ExtraLairs_GUESS = ptree;
    if (3 > 3)
    {
        ptreem_ExtraLairs_GUESS = new TreeItemBase("m_ExtraLairs_GUESS");
        ptree->appendTree(ptreem_ExtraLairs_GUESS, "");
    }
    for (int i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_ExtraLairs_GUESS[" << i << "]";
          ptreem_ExtraLairs_GUESS->appendTree(constructTreeItem(&rhs->m_ExtraLairs_GUESS[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MoMDataSegment* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new TreeItem<char[0x19C]>(rhs->m_DataSegmentStart));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Types, "m_Hero_Types"), "");
    TreeItemBase* ptreem_Normal_Units = ptree;
    if (4 + 115 > 3)
    {
        ptreem_Normal_Units = new TreeItemBase("m_Normal_Units");
        ptree->appendTree(ptreem_Normal_Units, "");
    }
    for (int i = 0; i < 4 + 115; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Units[" << i << "]";
          ptreem_Normal_Units->appendTree(constructTreeItem(&rhs->m_Normal_Units[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Summoned_Units = ptree;
    if (44 > 3)
    {
        ptreem_Summoned_Units = new TreeItemBase("m_Summoned_Units");
        ptree->appendTree(ptreem_Summoned_Units, "");
    }
    for (int i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "m_Summoned_Units[" << i << "]";
          ptreem_Summoned_Units->appendTree(constructTreeItem(&rhs->m_Summoned_Units[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_XP_Level_Table = ptree;
    if (9 > 3)
    {
        ptreem_XP_Level_Table = new TreeItemBase("m_XP_Level_Table");
        ptree->appendTree(ptreem_XP_Level_Table, "");
    }
    for (int i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_XP_Level_Table[" << i << "]";
          ptreem_XP_Level_Table->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_XP_Level_Table[i]));
    }
    TreeItemBase* ptreem_Race_Data = ptree;
    if (14 > 3)
    {
        ptreem_Race_Data = new TreeItemBase("m_Race_Data");
        ptree->appendTree(ptreem_Race_Data, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Race_Data[" << i << "]";
          ptreem_Race_Data->appendTree(constructTreeItem(&rhs->m_Race_Data[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK03 = ptree;
    if (0x42 > 3)
    {
        ptreem_UNK03 = new TreeItemBase("m_UNK03");
        ptree->appendTree(ptreem_UNK03, "");
    }
    for (int i = 0; i < 0x42; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03[" << i << "]";
          ptreem_UNK03->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK03[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Upkeep_Enchantments, "m_Upkeep_Enchantments"), "");
    TreeItemBase* ptreem_UNK05 = ptree;
    if (46 > 3)
    {
        ptreem_UNK05 = new TreeItemBase("m_UNK05");
        ptree->appendTree(ptreem_UNK05, "");
    }
    for (int i = 0; i < 46; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK05[" << i << "]";
          ptreem_UNK05->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK05[i]));
    }
    TreeItemBase* ptreem_DifficultyTable = ptree;
    if (eDifficulty_MAX > 3)
    {
        ptreem_DifficultyTable = new TreeItemBase("m_DifficultyTable");
        ptree->appendTree(ptreem_DifficultyTable, "");
    }
    for (int i = 0; i < eDifficulty_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_DifficultyTable[" << i << "]";
          ptreem_DifficultyTable->appendTree(constructTreeItem(&rhs->m_DifficultyTable[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK06a = ptree;
    if (72 > 3)
    {
        ptreem_UNK06a = new TreeItemBase("m_UNK06a");
        ptree->appendTree(ptreem_UNK06a, "");
    }
    for (int i = 0; i < 72; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06a[" << i << "]";
          ptreem_UNK06a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK06a[i]));
    }
    ptree->appendChild("m_NameBuffer1a", new TreeItem<char[0x5E92 - 0x2082]>(rhs->m_NameBuffer1a));
    ptree->appendChild("m_Next_Turn_seed_storage_lo", new TreeItem<uint16_t>(&rhs->m_Next_Turn_seed_storage_lo));
    ptree->appendChild("m_Next_Turn_seed_storage_hi", new TreeItem<uint16_t>(&rhs->m_Next_Turn_seed_storage_hi));
    TreeItemBase* ptreem_UNK_5E96 = ptree;
    if (0x6E9E - 0x5E96 > 3)
    {
        ptreem_UNK_5E96 = new TreeItemBase("m_UNK_5E96");
        ptree->appendTree(ptreem_UNK_5E96, "");
    }
    for (int i = 0; i < 0x6E9E - 0x5E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_5E96[" << i << "]";
          ptreem_UNK_5E96->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_5E96[i]));
    }
    TreeItemBase* ptreem_Tax_Unrest_Table = ptree;
    if (eTax_Rate_MAX > 3)
    {
        ptreem_Tax_Unrest_Table = new TreeItemBase("m_Tax_Unrest_Table");
        ptree->appendTree(ptreem_Tax_Unrest_Table, "");
    }
    for (int i = 0; i < eTax_Rate_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tax_Unrest_Table[" << i << "]";
          ptreem_Tax_Unrest_Table->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Tax_Unrest_Table[i]));
    }
    TreeItemBase* ptreem_UNK_6EAC = ptree;
    if (0x7173 - 0x6EAC > 3)
    {
        ptreem_UNK_6EAC = new TreeItemBase("m_UNK_6EAC");
        ptree->appendTree(ptreem_UNK_6EAC, "");
    }
    for (int i = 0; i < 0x7173 - 0x6EAC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_6EAC[" << i << "]";
          ptreem_UNK_6EAC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_6EAC[i]));
    }
    ptree->appendChild("m_MoM_Version", new TreeItem<char[7]>(rhs->m_MoM_Version));
    TreeItemBase* ptreem_UNK_717A = ptree;
    if (0x71E0 - 0x717A > 3)
    {
        ptreem_UNK_717A = new TreeItemBase("m_UNK_717A");
        ptree->appendTree(ptreem_UNK_717A, "");
    }
    for (int i = 0; i < 0x71E0 - 0x717A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_717A[" << i << "]";
          ptreem_UNK_717A->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_717A[i]));
    }
    ptree->appendChild("m_BIOS_clock_snapshot", new TreeItem<uint32_t>(&rhs->m_BIOS_clock_snapshot));
    TreeItemBase* ptreem_UNK_71E4 = ptree;
    if (0x7846 - 0x71E4 > 3)
    {
        ptreem_UNK_71E4 = new TreeItemBase("m_UNK_71E4");
        ptree->appendTree(ptreem_UNK_71E4, "");
    }
    for (int i = 0; i < 0x7846 - 0x71E4; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_71E4[" << i << "]";
          ptreem_UNK_71E4->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_71E4[i]));
    }
    ptree->appendChild("m_RNG_seed_lo", new TreeItem<uint16_t>(&rhs->m_RNG_seed_lo));
    ptree->appendChild("m_RNG_seed_hi", new TreeItem<uint16_t>(&rhs->m_RNG_seed_hi));
    TreeItemBase* ptreem_UNK06c = ptree;
    if (0x7876 - 0x784A > 3)
    {
        ptreem_UNK06c = new TreeItemBase("m_UNK06c");
        ptree->appendTree(ptreem_UNK06c, "");
    }
    for (int i = 0; i < 0x7876 - 0x784A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06c[" << i << "]";
          ptreem_UNK06c->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK06c[i]));
    }
    ptree->appendChild("m_DEBUG_Off", new TreeItem<uint16_t>(&rhs->m_DEBUG_Off));
    TreeItemBase* ptreem_UNK06d = ptree;
    if (0x912C - 0x7878 > 3)
    {
        ptreem_UNK06d = new TreeItemBase("m_UNK06d");
        ptree->appendTree(ptreem_UNK06d, "");
    }
    for (int i = 0; i < 0x912C - 0x7878; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06d[" << i << "]";
          ptreem_UNK06d->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK06d[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_WizardsExe_Pointers, "m_WizardsExe_Pointers"), "");
    TreeItemBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new TreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (int i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK07 = ptree;
    if (0xBD8E - 0xBB7A > 3)
    {
        ptreem_UNK07 = new TreeItemBase("m_UNK07");
        ptree->appendTree(ptreem_UNK07, "");
    }
    for (int i = 0; i < 0xBD8E - 0xBB7A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07[" << i << "]";
          ptreem_UNK07->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK07[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    TreeItemBase* ptreem_UNK08a = ptree;
    if (0xC588 - 0xBF70 > 3)
    {
        ptreem_UNK08a = new TreeItemBase("m_UNK08a");
        ptree->appendTree(ptreem_UNK08a, "");
    }
    for (int i = 0; i < 0xC588 - 0xBF70; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK08a[" << i << "]";
          ptreem_UNK08a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK08a[i]));
    }
    ptree->appendChild("m_Nr_Battle_Units", new TreeItem<uint16_t>(&rhs->m_Nr_Battle_Units));
    TreeItemBase* ptreem_UNK08b = ptree;
    if (0xC8FA - 0xC58A > 3)
    {
        ptreem_UNK08b = new TreeItemBase("m_UNK08b");
        ptree->appendTree(ptreem_UNK08b, "");
    }
    for (int i = 0; i < 0xC8FA - 0xC58A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK08b[" << i << "]";
          ptreem_UNK08b->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK08b[i]));
    }
    ptree->appendChild("m_offset_Available_spell_pages", new TreeItem<uint16_t>(&rhs->m_offset_Available_spell_pages));
    TreeItemBase* ptreem_UNK08c = ptree;
    if (0xC910 - 0xC8FC > 3)
    {
        ptreem_UNK08c = new TreeItemBase("m_UNK08c");
        ptree->appendTree(ptreem_UNK08c, "");
    }
    for (int i = 0; i < 0xC910 - 0xC8FC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK08c[" << i << "]";
          ptreem_UNK08c->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK08c[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Hero_Spells, "m_addr_Hero_Spells"), "");
    ptree->appendChild("m_Nr_available_spell_pages", new TreeItem<uint16_t>(&rhs->m_Nr_available_spell_pages));
    TreeItemBase* ptreem_UNK08d = ptree;
    if (0xC924 - 0xC916 > 3)
    {
        ptreem_UNK08d = new TreeItemBase("m_UNK08d");
        ptree->appendTree(ptreem_UNK08d, "");
    }
    for (int i = 0; i < 0xC924 - 0xC916; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK08d[" << i << "]";
          ptreem_UNK08d->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK08d[i]));
    }
    ptree->appendChild("m_First_visible_available_spell_page", new TreeItem<uint16_t>(&rhs->m_First_visible_available_spell_page));
    TreeItemBase* ptreem_UNK083 = ptree;
    if (0xEA54 - 0xC926 > 3)
    {
        ptreem_UNK083 = new TreeItemBase("m_UNK083");
        ptree->appendTree(ptreem_UNK083, "");
    }
    for (int i = 0; i < 0xEA54 - 0xC926; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK083[" << i << "]";
          ptreem_UNK083->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK083[i]));
    }
    TreeItemBase* ptreem_PARALIGN09 = ptree;
    if (0x0C > 3)
    {
        ptreem_PARALIGN09 = new TreeItemBase("m_PARALIGN09");
        ptree->appendTree(ptreem_PARALIGN09, "");
    }
    for (int i = 0; i < 0x0C; ++i)
    {
          std::ostringstream oss;
          oss << "m_PARALIGN09[" << i << "]";
          ptreem_PARALIGN09->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_PARALIGN09[i]));
    }
    TreeItemBase* ptreem_StackSegment = ptree;
    if (0x40 > 3)
    {
        ptreem_StackSegment = new TreeItemBase("m_StackSegment");
        ptree->appendTree(ptreem_StackSegment, "");
    }
    for (int i = 0; i < 0x40; ++i)
    {
          std::ostringstream oss;
          oss << "m_StackSegment[" << i << "]";
          ptreem_StackSegment->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_StackSegment[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(MoMMagicDataSegment* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new TreeItem<char[47]>(rhs->m_DataSegmentStart));
    TreeItemBase* ptreem_UNK_2F = ptree;
    if (0x2AD0 - 47 > 3)
    {
        ptreem_UNK_2F = new TreeItemBase("m_UNK_2F");
        ptree->appendTree(ptreem_UNK_2F, "");
    }
    for (int i = 0; i < 0x2AD0 - 47; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2F[" << i << "]";
          ptreem_UNK_2F->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_2F[i]));
    }
    TreeItemBase* ptreem_Wizard_Types = ptree;
    if (ePortrait_MAX > 3)
    {
        ptreem_Wizard_Types = new TreeItemBase("m_Wizard_Types");
        ptree->appendTree(ptreem_Wizard_Types, "");
    }
    for (int i = 0; i < ePortrait_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizard_Types[" << i << "]";
          ptreem_Wizard_Types->appendTree(constructTreeItem(&rhs->m_Wizard_Types[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK_2C1A = ptree;
    if (0x35D0 - 0x2C1A > 3)
    {
        ptreem_UNK_2C1A = new TreeItemBase("m_UNK_2C1A");
        ptree->appendTree(ptreem_UNK_2C1A, "");
    }
    for (int i = 0; i < 0x35D0 - 0x2C1A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2C1A[" << i << "]";
          ptreem_UNK_2C1A->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_2C1A[i]));
    }
    TreeItemBase* ptreem_Hero_Stats_Initializers = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Hero_Stats_Initializers = new TreeItemBase("m_Hero_Stats_Initializers");
        ptree->appendTree(ptreem_Hero_Stats_Initializers, "");
    }
    for (int i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Hero_Stats_Initializers[" << i << "]";
          ptreem_Hero_Stats_Initializers->appendTree(constructTreeItem(&rhs->m_Hero_Stats_Initializers[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK_3846 = ptree;
    if (0x6900 - 0x3846 > 3)
    {
        ptreem_UNK_3846 = new TreeItemBase("m_UNK_3846");
        ptree->appendTree(ptreem_UNK_3846, "");
    }
    for (int i = 0; i < 0x6900 - 0x3846; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_3846[" << i << "]";
          ptreem_UNK_3846->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_3846[i]));
    }
    TreeItemBase* ptreem_Wizards = ptree;
    if (6 > 3)
    {
        ptreem_Wizards = new TreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Spells_selected_of_Realm = ptree;
    if (150 > 3)
    {
        ptreem_Spells_selected_of_Realm = new TreeItemBase("m_Spells_selected_of_Realm");
        ptree->appendTree(ptreem_Spells_selected_of_Realm, "");
    }
    for (int i = 0; i < 150; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_selected_of_Realm[" << i << "]";
          ptreem_Spells_selected_of_Realm->appendChild(oss.str().c_str(), new TreeItem<eSpell16>(&rhs->m_Spells_selected_of_Realm[i]));
    }
    TreeItemBase* ptreem_UNK_86DC = ptree;
    if (0x87C4 - 0x86DC > 3)
    {
        ptreem_UNK_86DC = new TreeItemBase("m_UNK_86DC");
        ptree->appendTree(ptreem_UNK_86DC, "");
    }
    for (int i = 0; i < 0x87C4 - 0x86DC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_86DC[" << i << "]";
          ptreem_UNK_86DC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_86DC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    TreeItemBase* ptreem_UNK_89A6 = ptree;
    if (0x8A14 - 0x89A6 > 3)
    {
        ptreem_UNK_89A6 = new TreeItemBase("m_UNK_89A6");
        ptree->appendTree(ptreem_UNK_89A6, "");
    }
    for (int i = 0; i < 0x8A14 - 0x89A6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_89A6[" << i << "]";
          ptreem_UNK_89A6->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_89A6[i]));
    }
    TreeItemBase* ptreem_Spell_Selected = ptree;
    if (eSpell_MAX > 3)
    {
        ptreem_Spell_Selected = new TreeItemBase("m_Spell_Selected");
        ptree->appendTree(ptreem_Spell_Selected, "");
    }
    for (int i = 0; i < eSpell_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell_Selected[" << i << "]";
          ptreem_Spell_Selected->appendChild(oss.str().c_str(), new TreeItem<eSpell>(&rhs->m_Spell_Selected[i]));
    }
    TreeItemBase* ptreem_UNK_8AEB = ptree;
    if (0x8D52 - 0x8AEB > 3)
    {
        ptreem_UNK_8AEB = new TreeItemBase("m_UNK_8AEB");
        ptree->appendTree(ptreem_UNK_8AEB, "");
    }
    for (int i = 0; i < 0x8D52 - 0x8AEB; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8AEB[" << i << "]";
          ptreem_UNK_8AEB->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_8AEB[i]));
    }
    TreeItemBase* ptreem_Spells_Known_Realm = ptree;
    if (66 > 3)
    {
        ptreem_Spells_Known_Realm = new TreeItemBase("m_Spells_Known_Realm");
        ptree->appendTree(ptreem_Spells_Known_Realm, "");
    }
    for (int i = 0; i < 66; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm[" << i << "]";
          ptreem_Spells_Known_Realm->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Spells_Known_Realm[i]));
    }
    ptree->appendChild("m_UNK_8DD6", new TreeItem<uint16_t>(&rhs->m_UNK_8DD6));
    ptree->appendChild("m_Sorcery_Picks_Divider", new TreeItem<uint16_t>(&rhs->m_Sorcery_Picks_Divider));
    ptree->appendChild("m_Nature_Picks_Divider", new TreeItem<uint16_t>(&rhs->m_Nature_Picks_Divider));
    ptree->appendChild("m_Chaos_Picks_Divider", new TreeItem<uint16_t>(&rhs->m_Chaos_Picks_Divider));
    ptree->appendChild("m_Death_Picks_Divider", new TreeItem<uint16_t>(&rhs->m_Death_Picks_Divider));
    ptree->appendChild("m_Life_Picks_Divider", new TreeItem<uint16_t>(&rhs->m_Life_Picks_Divider));
    TreeItemBase* ptreem_UNK_8DE2 = ptree;
    if (2 > 3)
    {
        ptreem_UNK_8DE2 = new TreeItemBase("m_UNK_8DE2");
        ptree->appendTree(ptreem_UNK_8DE2, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8DE2[" << i << "]";
          ptreem_UNK_8DE2->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_UNK_8DE2[i]));
    }
    TreeItemBase* ptreem_Spells_Known_Realm_Indexed = ptree;
    if (15 > 3)
    {
        ptreem_Spells_Known_Realm_Indexed = new TreeItemBase("m_Spells_Known_Realm_Indexed");
        ptree->appendTree(ptreem_Spells_Known_Realm_Indexed, "");
    }
    for (int i = 0; i < 15; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm_Indexed[" << i << "]";
          ptreem_Spells_Known_Realm_Indexed->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Spells_Known_Realm_Indexed[i]));
    }
    TreeItemBase* ptreem_UNK_8E04 = ptree;
    if (0x8E48 - 0x8E04 > 3)
    {
        ptreem_UNK_8E04 = new TreeItemBase("m_UNK_8E04");
        ptree->appendTree(ptreem_UNK_8E04, "");
    }
    for (int i = 0; i < 0x8E48 - 0x8E04; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E04[" << i << "]";
          ptreem_UNK_8E04->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_8E04[i]));
    }
    ptree->appendChild("m_Select_Wizard_Shown", new TreeItem<ePortrait>(&rhs->m_Select_Wizard_Shown));
    TreeItemBase* ptreem_UNK_8E49 = ptree;
    if (0x8E94 - 0x8E49 > 3)
    {
        ptreem_UNK_8E49 = new TreeItemBase("m_UNK_8E49");
        ptree->appendTree(ptreem_UNK_8E49, "");
    }
    for (int i = 0; i < 0x8E94 - 0x8E49; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E49[" << i << "]";
          ptreem_UNK_8E49->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_8E49[i]));
    }
    ptree->appendChild("m_Total_Picks_Left", new TreeItem<uint16_t>(&rhs->m_Total_Picks_Left));
    TreeItemBase* ptreem_UNK_8E96 = ptree;
    if (0xAA4A - 0x8E96 > 3)
    {
        ptreem_UNK_8E96 = new TreeItemBase("m_UNK_8E96");
        ptree->appendTree(ptreem_UNK_8E96, "");
    }
    for (int i = 0; i < 0xAA4A - 0x8E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E96[" << i << "]";
          ptreem_UNK_8E96->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_8E96[i]));
    }
    TreeItemBase* ptreem_UNK_AA4A = ptree;
    if (0xFE68 - 0xAA4A > 3)
    {
        ptreem_UNK_AA4A = new TreeItemBase("m_UNK_AA4A");
        ptree->appendTree(ptreem_UNK_AA4A, "");
    }
    for (int i = 0; i < 0xFE68 - 0xAA4A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_AA4A[" << i << "]";
          ptreem_UNK_AA4A->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_AA4A[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_1", new TreeItem<char[11]>(rhs->m_Wizards_Name_Shown_1));
    TreeItemBase* ptreem_UNK_FE73 = ptree;
    if (0xFEC2 - 0xFE73 > 3)
    {
        ptreem_UNK_FE73 = new TreeItemBase("m_UNK_FE73");
        ptree->appendTree(ptreem_UNK_FE73, "");
    }
    for (int i = 0; i < 0xFEC2 - 0xFE73; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_FE73[" << i << "]";
          ptreem_UNK_FE73->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK_FE73[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_2", new TreeItem<char[11]>(rhs->m_Wizards_Name_Shown_2));
    return ptree;
}

TreeItemBase* constructTreeItem(Movement_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Movement_Flags maskCavalry;
    memset(&maskCavalry, '\0', sizeof(maskCavalry));
    maskCavalry.Cavalry = 0xFF;
    if (1 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCavalry));
    else if (2 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCavalry));
    else
        ptree->appendChild("Cavalry", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCavalry));
    Movement_Flags maskSailing;
    memset(&maskSailing, '\0', sizeof(maskSailing));
    maskSailing.Sailing = 0xFF;
    if (1 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSailing));
    else if (2 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSailing));
    else
        ptree->appendChild("Sailing", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSailing));
    Movement_Flags maskSwimming;
    memset(&maskSwimming, '\0', sizeof(maskSwimming));
    maskSwimming.Swimming = 0xFF;
    if (1 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSwimming));
    else if (2 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSwimming));
    else
        ptree->appendChild("Swimming", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSwimming));
    Movement_Flags maskFlying;
    memset(&maskFlying, '\0', sizeof(maskFlying));
    maskFlying.Flying = 0xFF;
    if (1 == sizeof(maskFlying))
        ptree->appendChild("Flying", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlying));
    else if (2 == sizeof(maskFlying))
        ptree->appendChild("Flying", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlying));
    else
        ptree->appendChild("Flying", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlying));
    Movement_Flags maskTeleporting;
    memset(&maskTeleporting, '\0', sizeof(maskTeleporting));
    maskTeleporting.Teleporting = 0xFF;
    if (1 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTeleporting));
    else if (2 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTeleporting));
    else
        ptree->appendChild("Teleporting", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTeleporting));
    Movement_Flags maskForester;
    memset(&maskForester, '\0', sizeof(maskForester));
    maskForester.Forester = 0xFF;
    if (1 == sizeof(maskForester))
        ptree->appendChild("Forester", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskForester));
    else if (2 == sizeof(maskForester))
        ptree->appendChild("Forester", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskForester));
    else
        ptree->appendChild("Forester", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskForester));
    Movement_Flags maskMountaineer;
    memset(&maskMountaineer, '\0', sizeof(maskMountaineer));
    maskMountaineer.Mountaineer = 0xFF;
    if (1 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMountaineer));
    else if (2 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMountaineer));
    else
        ptree->appendChild("Mountaineer", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMountaineer));
    Movement_Flags maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 0xFF;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    return ptree;
}

TreeItemBase* constructTreeItem(Node_Attr* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new TreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Power_Node", new TreeItem<uint8_t>(&rhs->m_Power_Node));
    TreeItemBase* ptreem_XPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_XPos_Mana = new TreeItemBase("m_XPos_Mana");
        ptree->appendTree(ptreem_XPos_Mana, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_XPos_Mana[" << i << "]";
          ptreem_XPos_Mana->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_XPos_Mana[i]));
    }
    TreeItemBase* ptreem_YPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_YPos_Mana = new TreeItemBase("m_YPos_Mana");
        ptree->appendTree(ptreem_YPos_Mana, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_YPos_Mana[" << i << "]";
          ptreem_YPos_Mana->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_YPos_Mana[i]));
    }
    ptree->appendChild("m_Node_Type", new TreeItem<eNode_Type>(&rhs->m_Node_Type));
    TreeItemBase* ptreem_UNK01 = ptree;
    if (2 > 3)
    {
        ptreem_UNK01 = new TreeItemBase("m_UNK01");
        ptree->appendTree(ptreem_UNK01, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01[" << i << "]";
          ptreem_UNK01->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK01[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Race_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new TreeItem<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Number_of_prohibited_buildings", new TreeItem<uint16_t>(&rhs->m_Number_of_prohibited_buildings));
    TreeItemBase* ptreem_Prohibited_buildings = ptree;
    if (7 > 3)
    {
        ptreem_Prohibited_buildings = new TreeItemBase("m_Prohibited_buildings");
        ptree->appendTree(ptreem_Prohibited_buildings, "");
    }
    for (int i = 0; i < 7; ++i)
    {
          std::ostringstream oss;
          oss << "m_Prohibited_buildings[" << i << "]";
          ptreem_Prohibited_buildings->appendChild(oss.str().c_str(), new TreeItem<eBuilding>(&rhs->m_Prohibited_buildings[i]));
    }
    ptree->appendChild("m_Outpost_growth_probability", new TreeItem<uint16_t>(&rhs->m_Outpost_growth_probability));
    ptree->appendChild("m_City_population_growth_modifier", new TreeItem<int16_t>(&rhs->m_City_population_growth_modifier));
    ptree->appendChild("m_Housing_picture", new TreeItem<uint16_t>(&rhs->m_Housing_picture));
    return ptree;
}

TreeItemBase* constructTreeItem(SaveGame* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreem_List_Hero_stats = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_List_Hero_stats = new TreeItemBase("m_List_Hero_stats");
        ptree->appendTree(ptreem_List_Hero_stats, "");
    }
    for (int i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_List_Hero_stats[" << i << "]";
          ptreem_List_Hero_stats->appendTree(constructTreeItem(&rhs->m_List_Hero_stats[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    TreeItemBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new TreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (int i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Map_Tiles, "m_Map_Tiles"), "");
    TreeItemBase* ptreem_Items = ptree;
    if (128 > 3)
    {
        ptreem_Items = new TreeItemBase("m_Items");
        ptree->appendTree(ptreem_Items, "");
    }
    for (int i = 0; i < 128; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items[" << i << "]";
          ptreem_Items->appendTree(constructTreeItem(&rhs->m_Items[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Item_Trashcan = ptree;
    if (10 > 3)
    {
        ptreem_Item_Trashcan = new TreeItemBase("m_Item_Trashcan");
        ptree->appendTree(ptreem_Item_Trashcan, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Trashcan[" << i << "]";
          ptreem_Item_Trashcan->appendTree(constructTreeItem(&rhs->m_Item_Trashcan[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Cities = ptree;
    if (gMAX_CITIES > 3)
    {
        ptreem_Cities = new TreeItemBase("m_Cities");
        ptree->appendTree(ptreem_Cities, "");
    }
    for (int i = 0; i < gMAX_CITIES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Cities[" << i << "]";
          ptreem_Cities->appendTree(constructTreeItem(&rhs->m_Cities[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Unit = ptree;
    if (1000 > 3)
    {
        ptreem_Unit = new TreeItemBase("m_Unit");
        ptree->appendTree(ptreem_Unit, "");
    }
    for (int i = 0; i < 1000; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unit[" << i << "]";
          ptreem_Unit->appendTree(constructTreeItem(&rhs->m_Unit[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_Units_Trashcan_GUESS = ptree;
    if (9 > 3)
    {
        ptreem_Units_Trashcan_GUESS = new TreeItemBase("m_Units_Trashcan_GUESS");
        ptree->appendTree(ptreem_Units_Trashcan_GUESS, "");
    }
    for (int i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_Units_Trashcan_GUESS[" << i << "]";
          ptreem_Units_Trashcan_GUESS->appendTree(constructTreeItem(&rhs->m_Units_Trashcan_GUESS[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Map_Attr, "m_Map_Attr"), "");
    ptree->appendChild("m_Grand_Vizier", new TreeItem<eGrand_Vizier>(&rhs->m_Grand_Vizier));
    TreeItemBase* ptreem_Items_in_Game = ptree;
    if (250 > 3)
    {
        ptreem_Items_in_Game = new TreeItemBase("m_Items_in_Game");
        ptree->appendTree(ptreem_Items_in_Game, "");
    }
    for (int i = 0; i < 250; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_in_Game[" << i << "]";
          ptreem_Items_in_Game->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_Items_in_Game[i]));
    }
    TreeItemBase* ptreem_Hero_Choices = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Hero_Choices = new TreeItemBase("m_Hero_Choices");
        ptree->appendTree(ptreem_Hero_Choices, "");
    }
    for (int i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Hero_Choices[" << i << "]";
          ptreem_Hero_Choices->appendTree(constructTreeItem(&rhs->m_Hero_Choices[i], oss.str().c_str()), "");
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Skills* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Alchemy", new TreeItem<eYesNo8>(&rhs->Alchemy));
    ptree->appendChild("Warlord", new TreeItem<eYesNo8>(&rhs->Warlord));
    ptree->appendChild("Chaos_Master", new TreeItem<eYesNo8>(&rhs->Chaos_Master));
    ptree->appendChild("Nature_Master", new TreeItem<eYesNo8>(&rhs->Nature_Master));
    ptree->appendChild("Sorcery_Master", new TreeItem<eYesNo8>(&rhs->Sorcery_Master));
    ptree->appendChild("Infernal_Power", new TreeItem<eYesNo8>(&rhs->Infernal_Power));
    ptree->appendChild("Divine_Power", new TreeItem<eYesNo8>(&rhs->Divine_Power));
    ptree->appendChild("Sage_Master", new TreeItem<eYesNo8>(&rhs->Sage_Master));
    ptree->appendChild("Channeller", new TreeItem<eYesNo8>(&rhs->Channeller));
    ptree->appendChild("Myrran", new TreeItem<eYesNo8>(&rhs->Myrran));
    ptree->appendChild("Archmage", new TreeItem<eYesNo8>(&rhs->Archmage));
    ptree->appendChild("Mana_Focusing", new TreeItem<eYesNo8>(&rhs->Mana_Focusing));
    ptree->appendChild("Node_Mastery", new TreeItem<eYesNo8>(&rhs->Node_Mastery));
    ptree->appendChild("Famous", new TreeItem<eYesNo8>(&rhs->Famous));
    ptree->appendChild("Runemaster", new TreeItem<eYesNo8>(&rhs->Runemaster));
    ptree->appendChild("Conjurer", new TreeItem<eYesNo8>(&rhs->Conjurer));
    ptree->appendChild("Charismatic", new TreeItem<eYesNo8>(&rhs->Charismatic));
    ptree->appendChild("Artificer", new TreeItem<eYesNo8>(&rhs->Artificer));
    return ptree;
}

TreeItemBase* constructTreeItem(Spell_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_SpellName", new TreeItem<char[19]>(rhs->m_SpellName));
    ptree->appendChild("m_Spell_desirability", new TreeItem<int16_t>(&rhs->m_Spell_desirability));
    ptree->appendChild("m_Spell_Category", new TreeItem<int8_t>(&rhs->m_Spell_Category));
    ptree->appendChild("m_Section_in_spell_book", new TreeItem<eSpell_Type>(&rhs->m_Section_in_spell_book));
    ptree->appendChild("m_Magic_Realm", new TreeItem<eRealm_Type>(&rhs->m_Magic_Realm));
    ptree->appendChild("m_Casting_eligibility", new TreeItem<int8_t>(&rhs->m_Casting_eligibility));
    ptree->appendChild("m_UNK01", new TreeItem<int8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Casting_cost", new TreeItem<uint16_t>(&rhs->m_Casting_cost));
    ptree->appendChild("m_Research_cost", new TreeItem<uint16_t>(&rhs->m_Research_cost));
    ptree->appendChild("m_Sound_effect_when_casting_spell", new TreeItem<int16_t>(&rhs->m_Sound_effect_when_casting_spell));
    ptree->appendChild("m_Unit_Summoned_or_Spell_Strength", new TreeItem<eUnit_Type>(&rhs->m_Unit_Summoned_or_Spell_Strength));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(Spells_Cast_in_Battle* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreeTrue_Light = ptree;
    if (2 > 3)
    {
        ptreeTrue_Light = new TreeItemBase("True_Light");
        ptree->appendTree(ptreeTrue_Light, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "True_Light[" << i << "]";
          ptreeTrue_Light->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->True_Light[i]));
    }
    TreeItemBase* ptreeDarkness = ptree;
    if (2 > 3)
    {
        ptreeDarkness = new TreeItemBase("Darkness");
        ptree->appendTree(ptreeDarkness, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Darkness[" << i << "]";
          ptreeDarkness->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Darkness[i]));
    }
    TreeItemBase* ptreeWarp_Reality = ptree;
    if (2 > 3)
    {
        ptreeWarp_Reality = new TreeItemBase("Warp_Reality");
        ptree->appendTree(ptreeWarp_Reality, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Warp_Reality[" << i << "]";
          ptreeWarp_Reality->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Warp_Reality[i]));
    }
    TreeItemBase* ptreeDark_Prayer = ptree;
    if (2 > 3)
    {
        ptreeDark_Prayer = new TreeItemBase("Dark_Prayer");
        ptree->appendTree(ptreeDark_Prayer, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Dark_Prayer[" << i << "]";
          ptreeDark_Prayer->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Dark_Prayer[i]));
    }
    TreeItemBase* ptreeWrack = ptree;
    if (2 > 3)
    {
        ptreeWrack = new TreeItemBase("Wrack");
        ptree->appendTree(ptreeWrack, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Wrack[" << i << "]";
          ptreeWrack->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Wrack[i]));
    }
    TreeItemBase* ptreeMetal_Fires = ptree;
    if (2 > 3)
    {
        ptreeMetal_Fires = new TreeItemBase("Metal_Fires");
        ptree->appendTree(ptreeMetal_Fires, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Metal_Fires[" << i << "]";
          ptreeMetal_Fires->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Metal_Fires[i]));
    }
    TreeItemBase* ptreePrayer = ptree;
    if (2 > 3)
    {
        ptreePrayer = new TreeItemBase("Prayer");
        ptree->appendTree(ptreePrayer, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Prayer[" << i << "]";
          ptreePrayer->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Prayer[i]));
    }
    TreeItemBase* ptreeHigh_Prayer = ptree;
    if (2 > 3)
    {
        ptreeHigh_Prayer = new TreeItemBase("High_Prayer");
        ptree->appendTree(ptreeHigh_Prayer, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "High_Prayer[" << i << "]";
          ptreeHigh_Prayer->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->High_Prayer[i]));
    }
    TreeItemBase* ptreeTerror = ptree;
    if (2 > 3)
    {
        ptreeTerror = new TreeItemBase("Terror");
        ptree->appendTree(ptreeTerror, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Terror[" << i << "]";
          ptreeTerror->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Terror[i]));
    }
    TreeItemBase* ptreeCall_Lightning = ptree;
    if (2 > 3)
    {
        ptreeCall_Lightning = new TreeItemBase("Call_Lightning");
        ptree->appendTree(ptreeCall_Lightning, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Call_Lightning[" << i << "]";
          ptreeCall_Lightning->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Call_Lightning[i]));
    }
    TreeItemBase* ptreeCounter_Magic = ptree;
    if (2 > 3)
    {
        ptreeCounter_Magic = new TreeItemBase("Counter_Magic");
        ptree->appendTree(ptreeCounter_Magic, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Counter_Magic[" << i << "]";
          ptreeCounter_Magic->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Counter_Magic[i]));
    }
    TreeItemBase* ptreeMass_Invisibility = ptree;
    if (2 > 3)
    {
        ptreeMass_Invisibility = new TreeItemBase("Mass_Invisibility");
        ptree->appendTree(ptreeMass_Invisibility, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mass_Invisibility[" << i << "]";
          ptreeMass_Invisibility->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Mass_Invisibility[i]));
    }
    TreeItemBase* ptreeEntangle = ptree;
    if (2 > 3)
    {
        ptreeEntangle = new TreeItemBase("Entangle");
        ptree->appendTree(ptreeEntangle, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Entangle[" << i << "]";
          ptreeEntangle->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Entangle[i]));
    }
    TreeItemBase* ptreeMana_Leak = ptree;
    if (2 > 3)
    {
        ptreeMana_Leak = new TreeItemBase("Mana_Leak");
        ptree->appendTree(ptreeMana_Leak, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mana_Leak[" << i << "]";
          ptreeMana_Leak->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Mana_Leak[i]));
    }
    TreeItemBase* ptreeBlur = ptree;
    if (2 > 3)
    {
        ptreeBlur = new TreeItemBase("Blur");
        ptree->appendTree(ptreeBlur, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Blur[" << i << "]";
          ptreeBlur->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->Blur[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Spells_Known* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("None", new TreeItem<eSpellKnown>(&rhs->None));
    ptree->appendChild("Earth_to_Mud", new TreeItem<eSpellKnown>(&rhs->Earth_to_Mud));
    ptree->appendChild("Resist_Elements", new TreeItem<eSpellKnown>(&rhs->Resist_Elements));
    ptree->appendChild("Wall_of_Stone", new TreeItem<eSpellKnown>(&rhs->Wall_of_Stone));
    ptree->appendChild("Giant_Strength", new TreeItem<eSpellKnown>(&rhs->Giant_Strength));
    ptree->appendChild("Web", new TreeItem<eSpellKnown>(&rhs->Web));
    ptree->appendChild("War_Bears", new TreeItem<eSpellKnown>(&rhs->War_Bears));
    ptree->appendChild("Stone_Skin", new TreeItem<eSpellKnown>(&rhs->Stone_Skin));
    ptree->appendChild("Water_Walking", new TreeItem<eSpellKnown>(&rhs->Water_Walking));
    ptree->appendChild("Sprites", new TreeItem<eSpellKnown>(&rhs->Sprites));
    ptree->appendChild("Earth_Lore", new TreeItem<eSpellKnown>(&rhs->Earth_Lore));
    ptree->appendChild("Cracks_Call", new TreeItem<eSpellKnown>(&rhs->Cracks_Call));
    ptree->appendChild("Natures_eye", new TreeItem<eSpellKnown>(&rhs->Natures_eye));
    ptree->appendChild("Ice_Bolt", new TreeItem<eSpellKnown>(&rhs->Ice_Bolt));
    ptree->appendChild("Giant_Spiders", new TreeItem<eSpellKnown>(&rhs->Giant_Spiders));
    ptree->appendChild("Change_Terrain", new TreeItem<eSpellKnown>(&rhs->Change_Terrain));
    ptree->appendChild("Path_Finding", new TreeItem<eSpellKnown>(&rhs->Path_Finding));
    ptree->appendChild("Cockatrices", new TreeItem<eSpellKnown>(&rhs->Cockatrices));
    ptree->appendChild("Transmute", new TreeItem<eSpellKnown>(&rhs->Transmute));
    ptree->appendChild("Natures_Cures", new TreeItem<eSpellKnown>(&rhs->Natures_Cures));
    ptree->appendChild("Basilisk", new TreeItem<eSpellKnown>(&rhs->Basilisk));
    ptree->appendChild("Elemental_Armor", new TreeItem<eSpellKnown>(&rhs->Elemental_Armor));
    ptree->appendChild("Petrify", new TreeItem<eSpellKnown>(&rhs->Petrify));
    ptree->appendChild("Stone_Giant", new TreeItem<eSpellKnown>(&rhs->Stone_Giant));
    ptree->appendChild("Iron_Skin", new TreeItem<eSpellKnown>(&rhs->Iron_Skin));
    ptree->appendChild("Ice_Storm", new TreeItem<eSpellKnown>(&rhs->Ice_Storm));
    ptree->appendChild("Earthquake", new TreeItem<eSpellKnown>(&rhs->Earthquake));
    ptree->appendChild("Gorgons", new TreeItem<eSpellKnown>(&rhs->Gorgons));
    ptree->appendChild("Move_Fortress", new TreeItem<eSpellKnown>(&rhs->Move_Fortress));
    ptree->appendChild("Gaias_Blessing", new TreeItem<eSpellKnown>(&rhs->Gaias_Blessing));
    ptree->appendChild("Earth_Elemental", new TreeItem<eSpellKnown>(&rhs->Earth_Elemental));
    ptree->appendChild("Regeneration", new TreeItem<eSpellKnown>(&rhs->Regeneration));
    ptree->appendChild("Behemoth", new TreeItem<eSpellKnown>(&rhs->Behemoth));
    ptree->appendChild("Entangle", new TreeItem<eSpellKnown>(&rhs->Entangle));
    ptree->appendChild("Nature_Awareness", new TreeItem<eSpellKnown>(&rhs->Nature_Awareness));
    ptree->appendChild("Call_Lightning", new TreeItem<eSpellKnown>(&rhs->Call_Lightning));
    ptree->appendChild("Colossus", new TreeItem<eSpellKnown>(&rhs->Colossus));
    ptree->appendChild("Earth_Gate", new TreeItem<eSpellKnown>(&rhs->Earth_Gate));
    ptree->appendChild("Herb_Mastery", new TreeItem<eSpellKnown>(&rhs->Herb_Mastery));
    ptree->appendChild("Great_Wyrm", new TreeItem<eSpellKnown>(&rhs->Great_Wyrm));
    ptree->appendChild("Natures_Wrath", new TreeItem<eSpellKnown>(&rhs->Natures_Wrath));
    ptree->appendChild("Resist_Magic", new TreeItem<eSpellKnown>(&rhs->Resist_Magic));
    ptree->appendChild("Dispel_Magic_True", new TreeItem<eSpellKnown>(&rhs->Dispel_Magic_True));
    ptree->appendChild("Floating_Island", new TreeItem<eSpellKnown>(&rhs->Floating_Island));
    ptree->appendChild("Guardian_Wind", new TreeItem<eSpellKnown>(&rhs->Guardian_Wind));
    ptree->appendChild("Phantom_Warriors", new TreeItem<eSpellKnown>(&rhs->Phantom_Warriors));
    ptree->appendChild("Confusion", new TreeItem<eSpellKnown>(&rhs->Confusion));
    ptree->appendChild("Word_of_Recall", new TreeItem<eSpellKnown>(&rhs->Word_of_Recall));
    ptree->appendChild("Counter_Magic", new TreeItem<eSpellKnown>(&rhs->Counter_Magic));
    ptree->appendChild("Nagas", new TreeItem<eSpellKnown>(&rhs->Nagas));
    ptree->appendChild("Psionic_Blast", new TreeItem<eSpellKnown>(&rhs->Psionic_Blast));
    ptree->appendChild("Blur", new TreeItem<eSpellKnown>(&rhs->Blur));
    ptree->appendChild("Disenchant_True", new TreeItem<eSpellKnown>(&rhs->Disenchant_True));
    ptree->appendChild("Vertigo", new TreeItem<eSpellKnown>(&rhs->Vertigo));
    ptree->appendChild("Spell_Lock", new TreeItem<eSpellKnown>(&rhs->Spell_Lock));
    ptree->appendChild("Enchant_Road", new TreeItem<eSpellKnown>(&rhs->Enchant_Road));
    ptree->appendChild("Flight", new TreeItem<eSpellKnown>(&rhs->Flight));
    ptree->appendChild("Wind_Mastery", new TreeItem<eSpellKnown>(&rhs->Wind_Mastery));
    ptree->appendChild("Spell_Blast", new TreeItem<eSpellKnown>(&rhs->Spell_Blast));
    ptree->appendChild("Aura_of_Majesty", new TreeItem<eSpellKnown>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Phantom_Beast", new TreeItem<eSpellKnown>(&rhs->Phantom_Beast));
    ptree->appendChild("Disjunction_True", new TreeItem<eSpellKnown>(&rhs->Disjunction_True));
    ptree->appendChild("Invisibility", new TreeItem<eSpellKnown>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new TreeItem<eSpellKnown>(&rhs->Wind_Walking));
    ptree->appendChild("Banish", new TreeItem<eSpellKnown>(&rhs->Banish));
    ptree->appendChild("Storm_Giant", new TreeItem<eSpellKnown>(&rhs->Storm_Giant));
    ptree->appendChild("Air_Elemental", new TreeItem<eSpellKnown>(&rhs->Air_Elemental));
    ptree->appendChild("Mind_Storm", new TreeItem<eSpellKnown>(&rhs->Mind_Storm));
    ptree->appendChild("Stasis", new TreeItem<eSpellKnown>(&rhs->Stasis));
    ptree->appendChild("Magic_Immunity", new TreeItem<eSpellKnown>(&rhs->Magic_Immunity));
    ptree->appendChild("Haste", new TreeItem<eSpellKnown>(&rhs->Haste));
    ptree->appendChild("Djinn", new TreeItem<eSpellKnown>(&rhs->Djinn));
    ptree->appendChild("Spell_Ward", new TreeItem<eSpellKnown>(&rhs->Spell_Ward));
    ptree->appendChild("Creature_Binding", new TreeItem<eSpellKnown>(&rhs->Creature_Binding));
    ptree->appendChild("Mass_Invisibility", new TreeItem<eSpellKnown>(&rhs->Mass_Invisibility));
    ptree->appendChild("Great_Unsummoning", new TreeItem<eSpellKnown>(&rhs->Great_Unsummoning));
    ptree->appendChild("Spell_Binding", new TreeItem<eSpellKnown>(&rhs->Spell_Binding));
    ptree->appendChild("Flying_Fortress", new TreeItem<eSpellKnown>(&rhs->Flying_Fortress));
    ptree->appendChild("Sky_Drake", new TreeItem<eSpellKnown>(&rhs->Sky_Drake));
    ptree->appendChild("Suppress_Magic", new TreeItem<eSpellKnown>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new TreeItem<eSpellKnown>(&rhs->Time_Stop));
    ptree->appendChild("Warp_Wood", new TreeItem<eSpellKnown>(&rhs->Warp_Wood));
    ptree->appendChild("Disrupt", new TreeItem<eSpellKnown>(&rhs->Disrupt));
    ptree->appendChild("Fire_Bolt", new TreeItem<eSpellKnown>(&rhs->Fire_Bolt));
    ptree->appendChild("Hell_Hounds", new TreeItem<eSpellKnown>(&rhs->Hell_Hounds));
    ptree->appendChild("Corruption", new TreeItem<eSpellKnown>(&rhs->Corruption));
    ptree->appendChild("Eldritch_Weapon", new TreeItem<eSpellKnown>(&rhs->Eldritch_Weapon));
    ptree->appendChild("Wall_of_Fire", new TreeItem<eSpellKnown>(&rhs->Wall_of_Fire));
    ptree->appendChild("Shatter", new TreeItem<eSpellKnown>(&rhs->Shatter));
    ptree->appendChild("Warp_Creature", new TreeItem<eSpellKnown>(&rhs->Warp_Creature));
    ptree->appendChild("Fire_Elemental", new TreeItem<eSpellKnown>(&rhs->Fire_Elemental));
    ptree->appendChild("Lightning_Bolt", new TreeItem<eSpellKnown>(&rhs->Lightning_Bolt));
    ptree->appendChild("Fire_Giant", new TreeItem<eSpellKnown>(&rhs->Fire_Giant));
    ptree->appendChild("Chaos_Channels", new TreeItem<eSpellKnown>(&rhs->Chaos_Channels));
    ptree->appendChild("Flame_Blade", new TreeItem<eSpellKnown>(&rhs->Flame_Blade));
    ptree->appendChild("Gargoyles", new TreeItem<eSpellKnown>(&rhs->Gargoyles));
    ptree->appendChild("Fireball", new TreeItem<eSpellKnown>(&rhs->Fireball));
    ptree->appendChild("Doombat", new TreeItem<eSpellKnown>(&rhs->Doombat));
    ptree->appendChild("Raise_Volcano", new TreeItem<eSpellKnown>(&rhs->Raise_Volcano));
    ptree->appendChild("Immolation", new TreeItem<eSpellKnown>(&rhs->Immolation));
    ptree->appendChild("Chimeras", new TreeItem<eSpellKnown>(&rhs->Chimeras));
    ptree->appendChild("Warp_Lightning", new TreeItem<eSpellKnown>(&rhs->Warp_Lightning));
    ptree->appendChild("Metal_Fires", new TreeItem<eSpellKnown>(&rhs->Metal_Fires));
    ptree->appendChild("Chaos_Spawn", new TreeItem<eSpellKnown>(&rhs->Chaos_Spawn));
    ptree->appendChild("Doom_Bolt", new TreeItem<eSpellKnown>(&rhs->Doom_Bolt));
    ptree->appendChild("Magic_Vortex", new TreeItem<eSpellKnown>(&rhs->Magic_Vortex));
    ptree->appendChild("Efreet", new TreeItem<eSpellKnown>(&rhs->Efreet));
    ptree->appendChild("Fire_Storm", new TreeItem<eSpellKnown>(&rhs->Fire_Storm));
    ptree->appendChild("Warp_Reality", new TreeItem<eSpellKnown>(&rhs->Warp_Reality));
    ptree->appendChild("Flame_Strike", new TreeItem<eSpellKnown>(&rhs->Flame_Strike));
    ptree->appendChild("Chaos_Rift", new TreeItem<eSpellKnown>(&rhs->Chaos_Rift));
    ptree->appendChild("Hydra", new TreeItem<eSpellKnown>(&rhs->Hydra));
    ptree->appendChild("Disintegrate", new TreeItem<eSpellKnown>(&rhs->Disintegrate));
    ptree->appendChild("Meteor_Storm", new TreeItem<eSpellKnown>(&rhs->Meteor_Storm));
    ptree->appendChild("Great_Wasting", new TreeItem<eSpellKnown>(&rhs->Great_Wasting));
    ptree->appendChild("Call_Chaos", new TreeItem<eSpellKnown>(&rhs->Call_Chaos));
    ptree->appendChild("Chaos_Surge", new TreeItem<eSpellKnown>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new TreeItem<eSpellKnown>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Drake", new TreeItem<eSpellKnown>(&rhs->Great_Drake));
    ptree->appendChild("Call_The_Void", new TreeItem<eSpellKnown>(&rhs->Call_The_Void));
    ptree->appendChild("Armageddon", new TreeItem<eSpellKnown>(&rhs->Armageddon));
    ptree->appendChild("Bless", new TreeItem<eSpellKnown>(&rhs->Bless));
    ptree->appendChild("Star_Fires", new TreeItem<eSpellKnown>(&rhs->Star_Fires));
    ptree->appendChild("Endurance", new TreeItem<eSpellKnown>(&rhs->Endurance));
    ptree->appendChild("Holy_Weapon", new TreeItem<eSpellKnown>(&rhs->Holy_Weapon));
    ptree->appendChild("Healing", new TreeItem<eSpellKnown>(&rhs->Healing));
    ptree->appendChild("Holy_Armor", new TreeItem<eSpellKnown>(&rhs->Holy_Armor));
    ptree->appendChild("Just_Cause", new TreeItem<eSpellKnown>(&rhs->Just_Cause));
    ptree->appendChild("True_Light", new TreeItem<eSpellKnown>(&rhs->True_Light));
    ptree->appendChild("Guardian_Spirit", new TreeItem<eSpellKnown>(&rhs->Guardian_Spirit));
    ptree->appendChild("Heroism", new TreeItem<eSpellKnown>(&rhs->Heroism));
    ptree->appendChild("True_Sight", new TreeItem<eSpellKnown>(&rhs->True_Sight));
    ptree->appendChild("Plane_Shift", new TreeItem<eSpellKnown>(&rhs->Plane_Shift));
    ptree->appendChild("Resurrection", new TreeItem<eSpellKnown>(&rhs->Resurrection));
    ptree->appendChild("Dispel_Evil", new TreeItem<eSpellKnown>(&rhs->Dispel_Evil));
    ptree->appendChild("Planar_Seal", new TreeItem<eSpellKnown>(&rhs->Planar_Seal));
    ptree->appendChild("Unicorns", new TreeItem<eSpellKnown>(&rhs->Unicorns));
    ptree->appendChild("Raise_Dead", new TreeItem<eSpellKnown>(&rhs->Raise_Dead));
    ptree->appendChild("Planar_Travel", new TreeItem<eSpellKnown>(&rhs->Planar_Travel));
    ptree->appendChild("Heavenly_Light", new TreeItem<eSpellKnown>(&rhs->Heavenly_Light));
    ptree->appendChild("Prayer", new TreeItem<eSpellKnown>(&rhs->Prayer));
    ptree->appendChild("Lionheart", new TreeItem<eSpellKnown>(&rhs->Lionheart));
    ptree->appendChild("Incarnation", new TreeItem<eSpellKnown>(&rhs->Incarnation));
    ptree->appendChild("Invulnerability", new TreeItem<eSpellKnown>(&rhs->Invulnerability));
    ptree->appendChild("Righteousness", new TreeItem<eSpellKnown>(&rhs->Righteousness));
    ptree->appendChild("Prosperity", new TreeItem<eSpellKnown>(&rhs->Prosperity));
    ptree->appendChild("Altar_of_Battle", new TreeItem<eSpellKnown>(&rhs->Altar_of_Battle));
    ptree->appendChild("Angel", new TreeItem<eSpellKnown>(&rhs->Angel));
    ptree->appendChild("Stream_of_Life", new TreeItem<eSpellKnown>(&rhs->Stream_of_Life));
    ptree->appendChild("Mass_Healing", new TreeItem<eSpellKnown>(&rhs->Mass_Healing));
    ptree->appendChild("Holy_Word", new TreeItem<eSpellKnown>(&rhs->Holy_Word));
    ptree->appendChild("High_Prayer", new TreeItem<eSpellKnown>(&rhs->High_Prayer));
    ptree->appendChild("Inspirations", new TreeItem<eSpellKnown>(&rhs->Inspirations));
    ptree->appendChild("Astral_Gate", new TreeItem<eSpellKnown>(&rhs->Astral_Gate));
    ptree->appendChild("Holy_Arms", new TreeItem<eSpellKnown>(&rhs->Holy_Arms));
    ptree->appendChild("Consecration", new TreeItem<eSpellKnown>(&rhs->Consecration));
    ptree->appendChild("Life_Force", new TreeItem<eSpellKnown>(&rhs->Life_Force));
    ptree->appendChild("Tranquility", new TreeItem<eSpellKnown>(&rhs->Tranquility));
    ptree->appendChild("Crusade", new TreeItem<eSpellKnown>(&rhs->Crusade));
    ptree->appendChild("Arch_Angel", new TreeItem<eSpellKnown>(&rhs->Arch_Angel));
    ptree->appendChild("Charm_of_Life", new TreeItem<eSpellKnown>(&rhs->Charm_of_Life));
    ptree->appendChild("Skeletons", new TreeItem<eSpellKnown>(&rhs->Skeletons));
    ptree->appendChild("Weakness", new TreeItem<eSpellKnown>(&rhs->Weakness));
    ptree->appendChild("Dark_Rituals", new TreeItem<eSpellKnown>(&rhs->Dark_Rituals));
    ptree->appendChild("Cloak_of_Fear", new TreeItem<eSpellKnown>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Sleep", new TreeItem<eSpellKnown>(&rhs->Black_Sleep));
    ptree->appendChild("Ghouls", new TreeItem<eSpellKnown>(&rhs->Ghouls));
    ptree->appendChild("Life_Drain", new TreeItem<eSpellKnown>(&rhs->Life_Drain));
    ptree->appendChild("Terror", new TreeItem<eSpellKnown>(&rhs->Terror));
    ptree->appendChild("Darkness", new TreeItem<eSpellKnown>(&rhs->Darkness));
    ptree->appendChild("Mana_Leak", new TreeItem<eSpellKnown>(&rhs->Mana_Leak));
    ptree->appendChild("Drain_Power", new TreeItem<eSpellKnown>(&rhs->Drain_Power));
    ptree->appendChild("Possession", new TreeItem<eSpellKnown>(&rhs->Possession));
    ptree->appendChild("Lycantrophy", new TreeItem<eSpellKnown>(&rhs->Lycantrophy));
    ptree->appendChild("Black_Prayer", new TreeItem<eSpellKnown>(&rhs->Black_Prayer));
    ptree->appendChild("Black_Channels", new TreeItem<eSpellKnown>(&rhs->Black_Channels));
    ptree->appendChild("Night_Stalker", new TreeItem<eSpellKnown>(&rhs->Night_Stalker));
    ptree->appendChild("Subversion", new TreeItem<eSpellKnown>(&rhs->Subversion));
    ptree->appendChild("Wall_of_Darkness", new TreeItem<eSpellKnown>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Berserk", new TreeItem<eSpellKnown>(&rhs->Berserk));
    ptree->appendChild("Shadow_Demons", new TreeItem<eSpellKnown>(&rhs->Shadow_Demons));
    ptree->appendChild("Wraith_Form", new TreeItem<eSpellKnown>(&rhs->Wraith_Form));
    ptree->appendChild("Wrack", new TreeItem<eSpellKnown>(&rhs->Wrack));
    ptree->appendChild("Evil_Presence", new TreeItem<eSpellKnown>(&rhs->Evil_Presence));
    ptree->appendChild("Wraiths", new TreeItem<eSpellKnown>(&rhs->Wraiths));
    ptree->appendChild("Cloud_of_Shadow", new TreeItem<eSpellKnown>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Warp_Node", new TreeItem<eSpellKnown>(&rhs->Warp_Node));
    ptree->appendChild("Black_Wind", new TreeItem<eSpellKnown>(&rhs->Black_Wind));
    ptree->appendChild("Zombie_Mastery", new TreeItem<eSpellKnown>(&rhs->Zombie_Mastery));
    ptree->appendChild("Famine", new TreeItem<eSpellKnown>(&rhs->Famine));
    ptree->appendChild("Cursed_Lands", new TreeItem<eSpellKnown>(&rhs->Cursed_Lands));
    ptree->appendChild("Cruel_Unminding", new TreeItem<eSpellKnown>(&rhs->Cruel_Unminding));
    ptree->appendChild("Word_of_Death", new TreeItem<eSpellKnown>(&rhs->Word_of_Death));
    ptree->appendChild("Death_Knights", new TreeItem<eSpellKnown>(&rhs->Death_Knights));
    ptree->appendChild("Death_Spell", new TreeItem<eSpellKnown>(&rhs->Death_Spell));
    ptree->appendChild("Animate_dead", new TreeItem<eSpellKnown>(&rhs->Animate_dead));
    ptree->appendChild("Pestilence", new TreeItem<eSpellKnown>(&rhs->Pestilence));
    ptree->appendChild("Eternal_Night", new TreeItem<eSpellKnown>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new TreeItem<eSpellKnown>(&rhs->Evil_Omens));
    ptree->appendChild("Death_Wish", new TreeItem<eSpellKnown>(&rhs->Death_Wish));
    ptree->appendChild("Demon_Lord", new TreeItem<eSpellKnown>(&rhs->Demon_Lord));
    ptree->appendChild("Magic_Spirit", new TreeItem<eSpellKnown>(&rhs->Magic_Spirit));
    ptree->appendChild("Dispel_Magic", new TreeItem<eSpellKnown>(&rhs->Dispel_Magic));
    ptree->appendChild("Summoning_Circle", new TreeItem<eSpellKnown>(&rhs->Summoning_Circle));
    ptree->appendChild("Disenchant_Area", new TreeItem<eSpellKnown>(&rhs->Disenchant_Area));
    ptree->appendChild("Recall_Hero", new TreeItem<eSpellKnown>(&rhs->Recall_Hero));
    ptree->appendChild("Detect_Magic", new TreeItem<eSpellKnown>(&rhs->Detect_Magic));
    ptree->appendChild("Enchant_Item", new TreeItem<eSpellKnown>(&rhs->Enchant_Item));
    ptree->appendChild("Summon_Hero", new TreeItem<eSpellKnown>(&rhs->Summon_Hero));
    ptree->appendChild("Awareness", new TreeItem<eSpellKnown>(&rhs->Awareness));
    ptree->appendChild("Disjunction", new TreeItem<eSpellKnown>(&rhs->Disjunction));
    ptree->appendChild("Create_Artifact", new TreeItem<eSpellKnown>(&rhs->Create_Artifact));
    ptree->appendChild("Summon_Champion", new TreeItem<eSpellKnown>(&rhs->Summon_Champion));
    ptree->appendChild("Spell_Of_Mastery", new TreeItem<eSpellKnown>(&rhs->Spell_Of_Mastery));
    ptree->appendChild("Spell_Of_Return", new TreeItem<eSpellKnown>(&rhs->Spell_Of_Return));
    return ptree;
}

TreeItemBase* constructTreeItem(Terrain_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Terrain_Flags maskVolcano_producing_for_Owner;
    memset(&maskVolcano_producing_for_Owner, '\0', sizeof(maskVolcano_producing_for_Owner));
    maskVolcano_producing_for_Owner.Volcano_producing_for_Owner = 0xFF;
    if (1 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVolcano_producing_for_Owner));
    else if (2 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVolcano_producing_for_Owner));
    else
        ptree->appendChild("Volcano_producing_for_Owner", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVolcano_producing_for_Owner));
    Terrain_Flags maskroad;
    memset(&maskroad, '\0', sizeof(maskroad));
    maskroad.road = 0xFF;
    if (1 == sizeof(maskroad))
        ptree->appendChild("road", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskroad));
    else if (2 == sizeof(maskroad))
        ptree->appendChild("road", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskroad));
    else
        ptree->appendChild("road", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskroad));
    Terrain_Flags maskenchanted_road;
    memset(&maskenchanted_road, '\0', sizeof(maskenchanted_road));
    maskenchanted_road.enchanted_road = 0xFF;
    if (1 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskenchanted_road));
    else if (2 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskenchanted_road));
    else
        ptree->appendChild("enchanted_road", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskenchanted_road));
    Terrain_Flags maskcorruption;
    memset(&maskcorruption, '\0', sizeof(maskcorruption));
    maskcorruption.corruption = 0xFF;
    if (1 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskcorruption));
    else if (2 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskcorruption));
    else
        ptree->appendChild("corruption", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskcorruption));
    Terrain_Flags masku1;
    memset(&masku1, '\0', sizeof(masku1));
    masku1.u1 = 0xFF;
    if (1 == sizeof(masku1))
        ptree->appendChild("u1", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku1));
    else if (2 == sizeof(masku1))
        ptree->appendChild("u1", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku1));
    else
        ptree->appendChild("u1", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku1));
    Terrain_Flags masku2;
    memset(&masku2, '\0', sizeof(masku2));
    masku2.u2 = 0xFF;
    if (1 == sizeof(masku2))
        ptree->appendChild("u2", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku2));
    else if (2 == sizeof(masku2))
        ptree->appendChild("u2", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku2));
    else
        ptree->appendChild("u2", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku2));
    return ptree;
}

TreeItemBase* constructTreeItem(Tower_Attr* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Closed", new TreeItem<uint8_t>(&rhs->m_Closed));
    ptree->appendChild("m_UNK", new TreeItem<uint8_t>(&rhs->m_UNK));
    return ptree;
}

TreeItemBase* constructTreeItem(Tower_Node_Lair* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Status", new TreeItem<eTower_Node_Lair_Status>(&rhs->m_Status));
    ptree->appendChild("m_Type", new TreeItem<eTower_Node_Lair_Type>(&rhs->m_Type));
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant1, "m_Inhabitant1"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant2, "m_Inhabitant2"), "");
    ptree->appendChild("m_UNK01", new TreeItem<uint8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Reward_Gold", new TreeItem<uint16_t>(&rhs->m_Reward_Gold));
    ptree->appendChild("m_Reward_Mana", new TreeItem<uint16_t>(&rhs->m_Reward_Mana));
    ptree->appendChild("m_Reward_Specials", new TreeItem<eReward_Specials>(&rhs->m_Reward_Specials));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags, "m_Flags"), "");
    ptree->appendChild("m_Item_Rewards", new TreeItem<uint16_t>(&rhs->m_Item_Rewards));
    TreeItemBase* ptreem_Item_Value = ptree;
    if (3 > 3)
    {
        ptreem_Item_Value = new TreeItemBase("m_Item_Value");
        ptree->appendTree(ptreem_Item_Value, "");
    }
    for (int i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Value[" << i << "]";
          ptreem_Item_Value->appendChild(oss.str().c_str(), new TreeItem<uint16_t>(&rhs->m_Item_Value[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Tower_Node_Lair_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Tower_Node_Lair_Flags maskm_Prisoner;
    memset(&maskm_Prisoner, '\0', sizeof(maskm_Prisoner));
    maskm_Prisoner.m_Prisoner = 0xFF;
    if (1 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Prisoner));
    else if (2 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Prisoner));
    else
        ptree->appendChild("m_Prisoner", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Prisoner));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant1;
    memset(&maskm_YOU_aware_Inhabitant1, '\0', sizeof(maskm_YOU_aware_Inhabitant1));
    maskm_YOU_aware_Inhabitant1.m_YOU_aware_Inhabitant1 = 0xFF;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant1));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant1));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant1", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant1));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant2;
    memset(&maskm_YOU_aware_Inhabitant2, '\0', sizeof(maskm_YOU_aware_Inhabitant2));
    maskm_YOU_aware_Inhabitant2.m_YOU_aware_Inhabitant2 = 0xFF;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant2));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant2));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant2", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant2));
    Tower_Node_Lair_Flags maskm_Zero;
    memset(&maskm_Zero, '\0', sizeof(maskm_Zero));
    maskm_Zero.m_Zero = 0xFF;
    if (1 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Zero));
    else if (2 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Zero));
    else
        ptree->appendChild("m_Zero", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Zero));
    return ptree;
}

TreeItemBase* constructTreeItem(Unit* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new TreeItem<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new TreeItem<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new TreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new TreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Moves_Total", new TreeItem<int8_t>(&rhs->m_Moves_Total));
    ptree->appendChild("m_Unit_Type", new TreeItem<eUnit_Type>(&rhs->m_Unit_Type));
    ptree->appendChild("m_Hero_Slot_Number", new TreeItem<int8_t>(&rhs->m_Hero_Slot_Number));
    ptree->appendChild("m_Active", new TreeItem<eUnit_Active>(&rhs->m_Active));
    ptree->appendChild("m_Moves_Left", new TreeItem<int8_t>(&rhs->m_Moves_Left));
    ptree->appendChild("m_XPos_of_destination", new TreeItem<int8_t>(&rhs->m_XPos_of_destination));
    ptree->appendChild("m_YPos_of_destination", new TreeItem<int8_t>(&rhs->m_YPos_of_destination));
    ptree->appendChild("m_Status", new TreeItem<eUnit_Status>(&rhs->m_Status));
    ptree->appendChild("m_Level", new TreeItem<eLevel>(&rhs->m_Level));
    ptree->appendChild("m_UNK01", new TreeItem<int8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Experience", new TreeItem<int16_t>(&rhs->m_Experience));
    ptree->appendChild("m_Guess_Lifedrain_Damage", new TreeItem<int8_t>(&rhs->m_Guess_Lifedrain_Damage));
    ptree->appendChild("m_Damage", new TreeItem<int8_t>(&rhs->m_Damage));
    ptree->appendChild("m_Grouping", new TreeItem<uint8_t>(&rhs->m_Grouping));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag1", new TreeItem<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag1));
    ptree->appendChild("m_In_Tower_without_Seal", new TreeItem<int8_t>(&rhs->m_In_Tower_without_Seal));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag3", new TreeItem<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag3));
    ptree->appendChild("m_Scouting_Range", new TreeItem<uint8_t>(&rhs->m_Scouting_Range));
    ptree->appendTree(constructTreeItem(&rhs->m_Weapon_Mutation, "m_Weapon_Mutation"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Unit_Enchantment, "m_Unit_Enchantment"), "");
    ptree->appendChild("m_Road_Building_left_to_complete", new TreeItem<int8_t>(&rhs->m_Road_Building_left_to_complete));
    TreeItemBase* ptreem_Road_Building_parms = ptree;
    if (3 > 3)
    {
        ptreem_Road_Building_parms = new TreeItemBase("m_Road_Building_parms");
        ptree->appendTree(ptreem_Road_Building_parms, "");
    }
    for (int i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Road_Building_parms[" << i << "]";
          ptreem_Road_Building_parms->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_Road_Building_parms[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(Unit_Data_Hero_Types* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->Dwarf, "Dwarf"), "");
    ptree->appendTree(constructTreeItem(&rhs->Barbarian, "Barbarian"), "");
    ptree->appendTree(constructTreeItem(&rhs->Sage, "Sage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Dervish, "Dervish"), "");
    ptree->appendTree(constructTreeItem(&rhs->Beastmaster, "Beastmaster"), "");
    ptree->appendTree(constructTreeItem(&rhs->Bard, "Bard"), "");
    ptree->appendTree(constructTreeItem(&rhs->Orc_Warrior, "Orc_Warrior"), "");
    ptree->appendTree(constructTreeItem(&rhs->Healer, "Healer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Huntress, "Huntress"), "");
    ptree->appendTree(constructTreeItem(&rhs->Thief, "Thief"), "");
    ptree->appendTree(constructTreeItem(&rhs->Druid, "Druid"), "");
    ptree->appendTree(constructTreeItem(&rhs->War_Monk, "War_Monk"), "");
    ptree->appendTree(constructTreeItem(&rhs->Warrior_Mage, "Warrior_Mage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Magician, "Magician"), "");
    ptree->appendTree(constructTreeItem(&rhs->Assassin, "Assassin"), "");
    ptree->appendTree(constructTreeItem(&rhs->Wind_Mage, "Wind_Mage"), "");
    ptree->appendTree(constructTreeItem(&rhs->Ranger, "Ranger"), "");
    ptree->appendTree(constructTreeItem(&rhs->Draconian, "Draconian"), "");
    ptree->appendTree(constructTreeItem(&rhs->Witch, "Witch"), "");
    ptree->appendTree(constructTreeItem(&rhs->Golden_One, "Golden_One"), "");
    ptree->appendTree(constructTreeItem(&rhs->Ninja, "Ninja"), "");
    ptree->appendTree(constructTreeItem(&rhs->Rogue, "Rogue"), "");
    ptree->appendTree(constructTreeItem(&rhs->Amazon, "Amazon"), "");
    ptree->appendTree(constructTreeItem(&rhs->Warlock, "Warlock"), "");
    ptree->appendTree(constructTreeItem(&rhs->Unknown, "Unknown"), "");
    ptree->appendTree(constructTreeItem(&rhs->Illusionist, "Illusionist"), "");
    ptree->appendTree(constructTreeItem(&rhs->Swordsman, "Swordsman"), "");
    ptree->appendTree(constructTreeItem(&rhs->Priestess, "Priestess"), "");
    ptree->appendTree(constructTreeItem(&rhs->Paladin, "Paladin"), "");
    ptree->appendTree(constructTreeItem(&rhs->Black_Knight, "Black_Knight"), "");
    ptree->appendTree(constructTreeItem(&rhs->Elven_Archer, "Elven_Archer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Knight, "Knight"), "");
    ptree->appendTree(constructTreeItem(&rhs->Necromancer, "Necromancer"), "");
    ptree->appendTree(constructTreeItem(&rhs->Chaos_Warrior, "Chaos_Warrior"), "");
    ptree->appendTree(constructTreeItem(&rhs->Chosen, "Chosen"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(Unit_Enchantment* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Unit_Enchantment maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 0xFF;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Unit_Enchantment maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 0xFF;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Unit_Enchantment maskBerserk;
    memset(&maskBerserk, '\0', sizeof(maskBerserk));
    maskBerserk.Berserk = 0xFF;
    if (1 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBerserk));
    else if (2 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBerserk));
    else
        ptree->appendChild("Berserk", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBerserk));
    Unit_Enchantment maskCloak_of_Fear;
    memset(&maskCloak_of_Fear, '\0', sizeof(maskCloak_of_Fear));
    maskCloak_of_Fear.Cloak_of_Fear = 0xFF;
    if (1 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_of_Fear));
    else if (2 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_of_Fear));
    else
        ptree->appendChild("Cloak_of_Fear", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_of_Fear));
    Unit_Enchantment maskBlack_Channels;
    memset(&maskBlack_Channels, '\0', sizeof(maskBlack_Channels));
    maskBlack_Channels.Black_Channels = 0xFF;
    if (1 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Channels));
    else if (2 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Channels));
    else
        ptree->appendChild("Black_Channels", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Channels));
    Unit_Enchantment maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 0xFF;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Unit_Enchantment maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 0xFF;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Unit_Enchantment maskPath_Finding;
    memset(&maskPath_Finding, '\0', sizeof(maskPath_Finding));
    maskPath_Finding.Path_Finding = 0xFF;
    if (1 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPath_Finding));
    else if (2 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPath_Finding));
    else
        ptree->appendChild("Path_Finding", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPath_Finding));
    Unit_Enchantment maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 0xFF;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Unit_Enchantment maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 0xFF;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Unit_Enchantment maskElemental_Armor;
    memset(&maskElemental_Armor, '\0', sizeof(maskElemental_Armor));
    maskElemental_Armor.Elemental_Armor = 0xFF;
    if (1 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armor));
    else if (2 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armor));
    else
        ptree->appendChild("Elemental_Armor", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armor));
    Unit_Enchantment maskStone_Skin;
    memset(&maskStone_Skin, '\0', sizeof(maskStone_Skin));
    maskStone_Skin.Stone_Skin = 0xFF;
    if (1 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStone_Skin));
    else if (2 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStone_Skin));
    else
        ptree->appendChild("Stone_Skin", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStone_Skin));
    Unit_Enchantment maskIron_Skin;
    memset(&maskIron_Skin, '\0', sizeof(maskIron_Skin));
    maskIron_Skin.Iron_Skin = 0xFF;
    if (1 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIron_Skin));
    else if (2 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIron_Skin));
    else
        ptree->appendChild("Iron_Skin", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIron_Skin));
    Unit_Enchantment maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 0xFF;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Unit_Enchantment maskSpell_Lock;
    memset(&maskSpell_Lock, '\0', sizeof(maskSpell_Lock));
    maskSpell_Lock.Spell_Lock = 0xFF;
    if (1 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSpell_Lock));
    else if (2 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSpell_Lock));
    else
        ptree->appendChild("Spell_Lock", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSpell_Lock));
    Unit_Enchantment maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 0xFF;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Unit_Enchantment maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 0xFF;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Unit_Enchantment maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 0xFF;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Unit_Enchantment maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 0xFF;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Unit_Enchantment maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 0xFF;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Unit_Enchantment maskFlame_Blade;
    memset(&maskFlame_Blade, '\0', sizeof(maskFlame_Blade));
    maskFlame_Blade.Flame_Blade = 0xFF;
    if (1 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlame_Blade));
    else if (2 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlame_Blade));
    else
        ptree->appendChild("Flame_Blade", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlame_Blade));
    Unit_Enchantment maskEldritch_Weapon;
    memset(&maskEldritch_Weapon, '\0', sizeof(maskEldritch_Weapon));
    maskEldritch_Weapon.Eldritch_Weapon = 0xFF;
    if (1 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon));
    else if (2 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon));
    else
        ptree->appendChild("Eldritch_Weapon", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon));
    Unit_Enchantment maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 0xFF;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Unit_Enchantment maskHoly_Weapon;
    memset(&maskHoly_Weapon, '\0', sizeof(maskHoly_Weapon));
    maskHoly_Weapon.Holy_Weapon = 0xFF;
    if (1 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Weapon));
    else if (2 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Weapon));
    else
        ptree->appendChild("Holy_Weapon", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Weapon));
    Unit_Enchantment maskHeroism;
    memset(&maskHeroism, '\0', sizeof(maskHeroism));
    maskHeroism.Heroism = 0xFF;
    if (1 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHeroism));
    else if (2 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHeroism));
    else
        ptree->appendChild("Heroism", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHeroism));
    Unit_Enchantment maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 0xFF;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Unit_Enchantment maskLionheart;
    memset(&maskLionheart, '\0', sizeof(maskLionheart));
    maskLionheart.Lionheart = 0xFF;
    if (1 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLionheart));
    else if (2 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLionheart));
    else
        ptree->appendChild("Lionheart", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLionheart));
    Unit_Enchantment maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 0xFF;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Unit_Enchantment maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 0xFF;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Unit_Enchantment maskHoly_Armor;
    memset(&maskHoly_Armor, '\0', sizeof(maskHoly_Armor));
    maskHoly_Armor.Holy_Armor = 0xFF;
    if (1 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Armor));
    else if (2 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Armor));
    else
        ptree->appendChild("Holy_Armor", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Armor));
    Unit_Enchantment maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 0xFF;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Unit_Enchantment maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 0xFF;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

TreeItemBase* constructTreeItem(Unit_Type_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new TreeItem<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Melee", new TreeItem<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new TreeItem<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new TreeItem<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new TreeItem<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new TreeItem<uint8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new TreeItem<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new TreeItem<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new TreeItem<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new TreeItem<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new TreeItem<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new TreeItem<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Building_Required1", new TreeItem<uint8_t>(&rhs->m_Building_Required1));
    ptree->appendChild("m_Hero_TypeCode_or_Building2", new TreeItem<eHero_TypeCode>(&rhs->m_Hero_TypeCode_or_Building2));
    ptree->appendChild("m_TypeCode", new TreeItem<uint8_t>(&rhs->m_TypeCode));
    ptree->appendChild("m_UNK01", new TreeItem<uint8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Hitpoints", new TreeItem<uint8_t>(&rhs->m_Hitpoints));
    ptree->appendChild("m_Scouting_Range", new TreeItem<uint8_t>(&rhs->m_Scouting_Range));
    ptree->appendChild("m_Transport_Capacity", new TreeItem<uint8_t>(&rhs->m_Transport_Capacity));
    ptree->appendChild("m_Nr_Figures", new TreeItem<uint8_t>(&rhs->m_Nr_Figures));
    ptree->appendChild("m_Construction_Capacity", new TreeItem<uint8_t>(&rhs->m_Construction_Capacity));
    ptree->appendChild("m_Gaze_Modifier", new TreeItem<int8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero02", new TreeItem<uint8_t>(&rhs->m_Zero02));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero03", new TreeItem<uint8_t>(&rhs->m_Zero03));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_UNK02", new TreeItem<uint8_t>(&rhs->m_UNK02));
    ptree->appendChild("m_Zero04", new TreeItem<uint8_t>(&rhs->m_Zero04));
    return ptree;
}

TreeItemBase* constructTreeItem(Unit_Weapon_Mutation* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    Unit_Weapon_Mutation maskWeapon_Type;
    memset(&maskWeapon_Type, '\0', sizeof(maskWeapon_Type));
    maskWeapon_Type.Weapon_Type = 0xFF;
    if (1 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Type));
    else if (2 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Type));
    else
        ptree->appendChild("Weapon_Type", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Type));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Skin;
    memset(&maskChaos_Channels_Demon_Skin, '\0', sizeof(maskChaos_Channels_Demon_Skin));
    maskChaos_Channels_Demon_Skin.Chaos_Channels_Demon_Skin = 0xFF;
    if (1 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Skin));
    else if (2 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Skin));
    else
        ptree->appendChild("Chaos_Channels_Demon_Skin", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Skin));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Wings;
    memset(&maskChaos_Channels_Demon_Wings, '\0', sizeof(maskChaos_Channels_Demon_Wings));
    maskChaos_Channels_Demon_Wings.Chaos_Channels_Demon_Wings = 0xFF;
    if (1 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Wings));
    else if (2 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Wings));
    else
        ptree->appendChild("Chaos_Channels_Demon_Wings", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Wings));
    Unit_Weapon_Mutation maskChaos_Channels_Fiery_Breath;
    memset(&maskChaos_Channels_Fiery_Breath, '\0', sizeof(maskChaos_Channels_Fiery_Breath));
    maskChaos_Channels_Fiery_Breath.Chaos_Channels_Fiery_Breath = 0xFF;
    if (1 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Fiery_Breath));
    else if (2 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Fiery_Breath));
    else
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Fiery_Breath));
    Unit_Weapon_Mutation maskUndead;
    memset(&maskUndead, '\0', sizeof(maskUndead));
    maskUndead.Undead = 0xFF;
    if (1 == sizeof(maskUndead))
        ptree->appendChild("Undead", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskUndead));
    else if (2 == sizeof(maskUndead))
        ptree->appendChild("Undead", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskUndead));
    else
        ptree->appendChild("Undead", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskUndead));
    Unit_Weapon_Mutation maskStasis_initial;
    memset(&maskStasis_initial, '\0', sizeof(maskStasis_initial));
    maskStasis_initial.Stasis_initial = 0xFF;
    if (1 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_initial));
    else if (2 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_initial));
    else
        ptree->appendChild("Stasis_initial", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_initial));
    Unit_Weapon_Mutation maskStasis_lingering;
    memset(&maskStasis_lingering, '\0', sizeof(maskStasis_lingering));
    maskStasis_lingering.Stasis_lingering = 0xFF;
    if (1 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new TreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_lingering));
    else if (2 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new TreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_lingering));
    else
        ptree->appendChild("Stasis_lingering", new TreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_lingering));
    return ptree;
}

TreeItemBase* constructTreeItem(Upkeep_Enchantments* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Immolation", new TreeItem<uint16_t>(&rhs->Immolation));
    ptree->appendChild("Guardian_Wind", new TreeItem<uint16_t>(&rhs->Guardian_Wind));
    ptree->appendChild("Berserk", new TreeItem<uint16_t>(&rhs->Berserk));
    ptree->appendChild("Cloak_of_Fear", new TreeItem<uint16_t>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Channels", new TreeItem<uint16_t>(&rhs->Black_Channels));
    ptree->appendChild("Wraith_Form", new TreeItem<uint16_t>(&rhs->Wraith_Form));
    ptree->appendChild("Regeneration", new TreeItem<uint16_t>(&rhs->Regeneration));
    ptree->appendChild("Path_Finding", new TreeItem<uint16_t>(&rhs->Path_Finding));
    ptree->appendChild("Water_Walking", new TreeItem<uint16_t>(&rhs->Water_Walking));
    ptree->appendChild("Resist_Elements", new TreeItem<uint16_t>(&rhs->Resist_Elements));
    ptree->appendChild("Elemental_Armor", new TreeItem<uint16_t>(&rhs->Elemental_Armor));
    ptree->appendChild("Stone_Skin", new TreeItem<uint16_t>(&rhs->Stone_Skin));
    ptree->appendChild("Iron_Skin", new TreeItem<uint16_t>(&rhs->Iron_Skin));
    ptree->appendChild("Endurance", new TreeItem<uint16_t>(&rhs->Endurance));
    ptree->appendChild("Spell_Lock", new TreeItem<uint16_t>(&rhs->Spell_Lock));
    ptree->appendChild("Invisibility", new TreeItem<uint16_t>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new TreeItem<uint16_t>(&rhs->Wind_Walking));
    ptree->appendChild("Flight", new TreeItem<uint16_t>(&rhs->Flight));
    ptree->appendChild("Resist_Magic", new TreeItem<uint16_t>(&rhs->Resist_Magic));
    ptree->appendChild("Magic_Immunity", new TreeItem<uint16_t>(&rhs->Magic_Immunity));
    ptree->appendChild("Flame_Blade", new TreeItem<uint16_t>(&rhs->Flame_Blade));
    ptree->appendChild("Eldritch_Weapon", new TreeItem<uint16_t>(&rhs->Eldritch_Weapon));
    ptree->appendChild("True_Sight", new TreeItem<uint16_t>(&rhs->True_Sight));
    ptree->appendChild("Holy_Weapon", new TreeItem<uint16_t>(&rhs->Holy_Weapon));
    ptree->appendChild("Heroism", new TreeItem<uint16_t>(&rhs->Heroism));
    ptree->appendChild("Bless", new TreeItem<uint16_t>(&rhs->Bless));
    ptree->appendChild("Lionheart", new TreeItem<uint16_t>(&rhs->Lionheart));
    ptree->appendChild("Giant_Strength", new TreeItem<uint16_t>(&rhs->Giant_Strength));
    ptree->appendChild("Planar_Travel", new TreeItem<uint16_t>(&rhs->Planar_Travel));
    ptree->appendChild("Holy_Armor", new TreeItem<uint16_t>(&rhs->Holy_Armor));
    ptree->appendChild("Righteousness", new TreeItem<uint16_t>(&rhs->Righteousness));
    ptree->appendChild("Invulnerability", new TreeItem<uint16_t>(&rhs->Invulnerability));
    ptree->appendChild("Wall_of_Fire", new TreeItem<uint16_t>(&rhs->Wall_of_Fire));
    ptree->appendChild("Chaos_Rift", new TreeItem<uint16_t>(&rhs->Chaos_Rift));
    ptree->appendChild("Dark_Rituals", new TreeItem<uint16_t>(&rhs->Dark_Rituals));
    ptree->appendChild("Evil_Presence", new TreeItem<uint16_t>(&rhs->Evil_Presence));
    ptree->appendChild("Cursed_Lands", new TreeItem<uint16_t>(&rhs->Cursed_Lands));
    ptree->appendChild("Pestilence", new TreeItem<uint16_t>(&rhs->Pestilence));
    ptree->appendChild("Cloud_of_Shadow", new TreeItem<uint16_t>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Famine", new TreeItem<uint16_t>(&rhs->Famine));
    ptree->appendChild("Flying_Fortress", new TreeItem<uint16_t>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new TreeItem<uint16_t>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new TreeItem<uint16_t>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new TreeItem<uint16_t>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new TreeItem<uint16_t>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new TreeItem<uint16_t>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new TreeItem<uint16_t>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new TreeItem<uint16_t>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new TreeItem<uint16_t>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new TreeItem<uint16_t>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new TreeItem<uint16_t>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new TreeItem<uint16_t>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new TreeItem<uint16_t>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new TreeItem<uint16_t>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new TreeItem<uint16_t>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new TreeItem<uint16_t>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new TreeItem<uint16_t>(&rhs->Altar_of_Battle));
    ptree->appendChild("Nightshade", new TreeItem<uint16_t>(&rhs->Nightshade));
    ptree->appendChild("Eternal_Night", new TreeItem<uint16_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new TreeItem<uint16_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new TreeItem<uint16_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new TreeItem<uint16_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new TreeItem<uint16_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new TreeItem<uint16_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new TreeItem<uint16_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new TreeItem<uint16_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new TreeItem<uint16_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new TreeItem<uint16_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new TreeItem<uint16_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new TreeItem<uint16_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new TreeItem<uint16_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new TreeItem<uint16_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new TreeItem<uint16_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new TreeItem<uint16_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new TreeItem<uint16_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new TreeItem<uint16_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new TreeItem<uint16_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new TreeItem<uint16_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new TreeItem<uint16_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new TreeItem<uint16_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new TreeItem<uint16_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new TreeItem<uint16_t>(&rhs->Awareness));
    return ptree;
}

TreeItemBase* constructTreeItem(Wizard* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Portrait", new TreeItem<ePortrait>(&rhs->m_Portrait));
    ptree->appendChild("m_Name", new TreeItem<char[20]>(rhs->m_Name));
    ptree->appendChild("m_Home_Race", new TreeItem<eRace>(&rhs->m_Home_Race));
    ptree->appendChild("m_BannerColor", new TreeItem<eBannerColor>(&rhs->m_BannerColor));
    ptree->appendChild("m_Personality", new TreeItem<ePersonality>(&rhs->m_Personality));
    ptree->appendChild("m_Objective", new TreeItem<eObjective>(&rhs->m_Objective));
    TreeItemBase* ptreem_UNK01 = ptree;
    if (8 > 3)
    {
        ptreem_UNK01 = new TreeItemBase("m_UNK01");
        ptree->appendTree(ptreem_UNK01, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01[" << i << "]";
          ptreem_UNK01->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK01[i]));
    }
    ptree->appendChild("m_Fame", new TreeItem<uint16_t>(&rhs->m_Fame));
    ptree->appendChild("m_Power_Base", new TreeItem<uint16_t>(&rhs->m_Power_Base));
    TreeItemBase* ptreem_UNK02a = ptree;
    if (2 > 3)
    {
        ptreem_UNK02a = new TreeItemBase("m_UNK02a");
        ptree->appendTree(ptreem_UNK02a, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK02a[" << i << "]";
          ptreem_UNK02a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK02a[i]));
    }
    ptree->appendChild("m_Research_Percentage", new TreeItem<uint8_t>(&rhs->m_Research_Percentage));
    ptree->appendChild("m_Mana_Percentage", new TreeItem<uint8_t>(&rhs->m_Mana_Percentage));
    ptree->appendChild("m_Skill_Percentage", new TreeItem<uint8_t>(&rhs->m_Skill_Percentage));
    ptree->appendChild("m_UNK02b", new TreeItem<uint8_t>(&rhs->m_UNK02b));
    ptree->appendChild("m_X_Coordinate_of_Summoning_Circle", new TreeItem<int16_t>(&rhs->m_X_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Y_Coordinate_of_Summoning_Circle", new TreeItem<int16_t>(&rhs->m_Y_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Plane_of_Summoning_Circle", new TreeItem<ePlane>(&rhs->m_Plane_of_Summoning_Circle));
    ptree->appendChild("m_Zero01", new TreeItem<uint8_t>(&rhs->m_Zero01));
    TreeItemBase* ptreem_Research_Spell_candidates = ptree;
    if (8 > 3)
    {
        ptreem_Research_Spell_candidates = new TreeItemBase("m_Research_Spell_candidates");
        ptree->appendTree(ptreem_Research_Spell_candidates, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Research_Spell_candidates[" << i << "]";
          ptreem_Research_Spell_candidates->appendChild(oss.str().c_str(), new TreeItem<eSpell16>(&rhs->m_Research_Spell_candidates[i]));
    }
    TreeItemBase* ptreem_UNK03a = ptree;
    if (4 > 3)
    {
        ptreem_UNK03a = new TreeItemBase("m_UNK03a");
        ptree->appendTree(ptreem_UNK03a, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03a[" << i << "]";
          ptreem_UNK03a->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK03a[i]));
    }
    ptree->appendChild("m_UNK_048", new TreeItem<uint16_t>(&rhs->m_UNK_048));
    TreeItemBase* ptreem_UNK03b = ptree;
    if (4 > 3)
    {
        ptreem_UNK03b = new TreeItemBase("m_UNK03b");
        ptree->appendTree(ptreem_UNK03b, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03b[" << i << "]";
          ptreem_UNK03b->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK03b[i]));
    }
    ptree->appendChild("m_Cost_Left_of_Spell_being_cast", new TreeItem<uint16_t>(&rhs->m_Cost_Left_of_Spell_being_cast));
    ptree->appendChild("m_Initial_Cost_of_Spell_being_cast", new TreeItem<uint16_t>(&rhs->m_Initial_Cost_of_Spell_being_cast));
    ptree->appendChild("m_Spell_being_cast", new TreeItem<eSpell>(&rhs->m_Spell_being_cast));
    ptree->appendChild("m_Zero02", new TreeItem<uint8_t>(&rhs->m_Zero02));
    ptree->appendChild("m_Unused_Casting_Skill_available_this_turn", new TreeItem<int16_t>(&rhs->m_Unused_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Nominal_Casting_Skill_available_this_turn", new TreeItem<int16_t>(&rhs->m_Nominal_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Tax_Rate", new TreeItem<eTax_Rate>(&rhs->m_Tax_Rate));
    ptree->appendChild("m_Number_of_Spellbooks_Nature", new TreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Nature));
    ptree->appendChild("m_Number_of_Spellbooks_Sorcery", new TreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Sorcery));
    ptree->appendChild("m_Number_of_Spellbooks_Chaos", new TreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Chaos));
    ptree->appendChild("m_Number_of_Spellbooks_Life", new TreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Life));
    ptree->appendChild("m_Number_of_Spellbooks_Death", new TreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Death));
    ptree->appendTree(constructTreeItem(&rhs->m_Skills, "m_Skills"), "");
    TreeItemBase* ptreem_Heroes_hired_by_wizard = ptree;
    if (gMAX_HIRED_HEROES > 3)
    {
        ptreem_Heroes_hired_by_wizard = new TreeItemBase("m_Heroes_hired_by_wizard");
        ptree->appendTree(ptreem_Heroes_hired_by_wizard, "");
    }
    for (int i = 0; i < gMAX_HIRED_HEROES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Heroes_hired_by_wizard[" << i << "]";
          ptreem_Heroes_hired_by_wizard->appendTree(constructTreeItem(&rhs->m_Heroes_hired_by_wizard[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreem_UNK06 = ptree;
    if (2 > 3)
    {
        ptreem_UNK06 = new TreeItemBase("m_UNK06");
        ptree->appendTree(ptreem_UNK06, "");
    }
    for (int i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06[" << i << "]";
          ptreem_UNK06->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK06[i]));
    }
    TreeItemBase* ptreem_Items_in_Slots = ptree;
    if (4 > 3)
    {
        ptreem_Items_in_Slots = new TreeItemBase("m_Items_in_Slots");
        ptree->appendTree(ptreem_Items_in_Slots, "");
    }
    for (int i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_in_Slots[" << i << "]";
          ptreem_Items_in_Slots->appendChild(oss.str().c_str(), new TreeItem<int16_t>(&rhs->m_Items_in_Slots[i]));
    }
    TreeItemBase* ptreem_Contacted = ptree;
    if (6 > 3)
    {
        ptreem_Contacted = new TreeItemBase("m_Contacted");
        ptree->appendTree(ptreem_Contacted, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Contacted[" << i << "]";
          ptreem_Contacted->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_Contacted[i]));
    }
    TreeItemBase* ptreem_UNK07a_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK07a_Relation = new TreeItemBase("m_UNK07a_Relation");
        ptree->appendTree(ptreem_UNK07a_Relation, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07a_Relation[" << i << "]";
          ptreem_UNK07a_Relation->appendChild(oss.str().c_str(), new TreeItem<int16_t>(&rhs->m_UNK07a_Relation[i]));
    }
    TreeItemBase* ptreem_UNK07b_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK07b_Relation = new TreeItemBase("m_UNK07b_Relation");
        ptree->appendTree(ptreem_UNK07b_Relation, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07b_Relation[" << i << "]";
          ptreem_UNK07b_Relation->appendChild(oss.str().c_str(), new TreeItem<int16_t>(&rhs->m_UNK07b_Relation[i]));
    }
    TreeItemBase* ptreem_UNK07c_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK07c_Relation = new TreeItemBase("m_UNK07c_Relation");
        ptree->appendTree(ptreem_UNK07c_Relation, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07c_Relation[" << i << "]";
          ptreem_UNK07c_Relation->appendChild(oss.str().c_str(), new TreeItem<int16_t>(&rhs->m_UNK07c_Relation[i]));
    }
    TreeItemBase* ptreem_Current_Wizard_Relations = ptree;
    if (6 > 3)
    {
        ptreem_Current_Wizard_Relations = new TreeItemBase("m_Current_Wizard_Relations");
        ptree->appendTree(ptreem_Current_Wizard_Relations, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Current_Wizard_Relations[" << i << "]";
          ptreem_Current_Wizard_Relations->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_Current_Wizard_Relations[i]));
    }
    TreeItemBase* ptreem_War_Status = ptree;
    if (6 > 3)
    {
        ptreem_War_Status = new TreeItemBase("m_War_Status");
        ptree->appendTree(ptreem_War_Status, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_War_Status[" << i << "]";
          ptreem_War_Status->appendChild(oss.str().c_str(), new TreeItem<eWar_Status>(&rhs->m_War_Status[i]));
    }
    TreeItemBase* ptreem_UNK07d = ptree;
    if (0x24 > 3)
    {
        ptreem_UNK07d = new TreeItemBase("m_UNK07d");
        ptree->appendTree(ptreem_UNK07d, "");
    }
    for (int i = 0; i < 0x24; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07d[" << i << "]";
          ptreem_UNK07d->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_UNK07d[i]));
    }
    TreeItemBase* ptreem_UNK07e_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK07e_Relation = new TreeItemBase("m_UNK07e_Relation");
        ptree->appendTree(ptreem_UNK07e_Relation, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07e_Relation[" << i << "]";
          ptreem_UNK07e_Relation->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_UNK07e_Relation[i]));
    }
    TreeItemBase* ptreem_UNK07f_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK07f_Relation = new TreeItemBase("m_UNK07f_Relation");
        ptree->appendTree(ptreem_UNK07f_Relation, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07f_Relation[" << i << "]";
          ptreem_UNK07f_Relation->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_UNK07f_Relation[i]));
    }
    TreeItemBase* ptreem_UNK07g = ptree;
    if (0xCC > 3)
    {
        ptreem_UNK07g = new TreeItemBase("m_UNK07g");
        ptree->appendTree(ptreem_UNK07g, "");
    }
    for (int i = 0; i < 0xCC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07g[" << i << "]";
          ptreem_UNK07g->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_UNK07g[i]));
    }
    ptree->appendChild("m_Researching_Left", new TreeItem<int16_t>(&rhs->m_Researching_Left));
    ptree->appendChild("m_Mana_Crystals", new TreeItem<int16_t>(&rhs->m_Mana_Crystals));
    ptree->appendChild("m_Wizard_Casting_Skill", new TreeItem<int32_t>(&rhs->m_Wizard_Casting_Skill));
    ptree->appendChild("m_Researching_Spell", new TreeItem<eSpell>(&rhs->m_Researching_Spell));
    ptree->appendTree(constructTreeItem(&rhs->m_Spells_Known, "m_Spells_Known"), "");
    TreeItemBase* ptreem_UNK09a = ptree;
    if (26 > 3)
    {
        ptreem_UNK09a = new TreeItemBase("m_UNK09a");
        ptree->appendTree(ptreem_UNK09a, "");
    }
    for (int i = 0; i < 26; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK09a[" << i << "]";
          ptreem_UNK09a->appendChild(oss.str().c_str(), new TreeItem<int8_t>(&rhs->m_UNK09a[i]));
    }
    ptree->appendChild("m_UNK_354", new TreeItem<int8_t>(&rhs->m_UNK_354));
    ptree->appendChild("m_UNK_355", new TreeItem<int8_t>(&rhs->m_UNK_355));
    ptree->appendChild("m_Gold_Coins", new TreeItem<int16_t>(&rhs->m_Gold_Coins));
    ptree->appendChild("m_UNK09b", new TreeItem<int16_t>(&rhs->m_UNK09b));
    ptree->appendChild("m_Astrologer_Magic_Power", new TreeItem<uint16_t>(&rhs->m_Astrologer_Magic_Power));
    ptree->appendChild("m_Astrologer_Spell_Research", new TreeItem<uint16_t>(&rhs->m_Astrologer_Spell_Research));
    ptree->appendChild("m_Astrologer_Army_Strength", new TreeItem<uint16_t>(&rhs->m_Astrologer_Army_Strength));
    ptree->appendChild("m_Astrologer_Power_GUESS", new TreeItem<uint16_t>(&rhs->m_Astrologer_Power_GUESS));
    TreeItemBase* ptreem_Historian = ptree;
    if (288 > 3)
    {
        ptreem_Historian = new TreeItemBase("m_Historian");
        ptree->appendTree(ptreem_Historian, "");
    }
    for (int i = 0; i < 288; ++i)
    {
          std::ostringstream oss;
          oss << "m_Historian[" << i << "]";
          ptreem_Historian->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_Historian[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Global_Enchantments, "m_Global_Enchantments"), "");
    TreeItemBase* ptreem_UNK11 = ptree;
    if (42 > 3)
    {
        ptreem_UNK11 = new TreeItemBase("m_UNK11");
        ptree->appendTree(ptreem_UNK11, "");
    }
    for (int i = 0; i < 42; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK11[" << i << "]";
          ptreem_UNK11->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->m_UNK11[i]));
    }
    ptree->appendChild("m_Books_Color", new TreeItem<eRealm_Type>(&rhs->m_Books_Color));
    ptree->appendChild("m_Zero04", new TreeItem<uint8_t>(&rhs->m_Zero04));
    ptree->appendChild("m_UNK12", new TreeItem<uint16_t>(&rhs->m_UNK12));
    return ptree;
}

TreeItemBase* constructTreeItem(Wizard_Type_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Wizard_Name", new TreeItem<char[10]>(rhs->m_Wizard_Name));
    ptree->appendChild("m_Life_books", new TreeItem<uint16_t>(&rhs->m_Life_books));
    ptree->appendChild("m_Sorcery_books", new TreeItem<uint16_t>(&rhs->m_Sorcery_books));
    ptree->appendChild("m_Nature_books", new TreeItem<uint16_t>(&rhs->m_Nature_books));
    ptree->appendChild("m_Death_books", new TreeItem<uint16_t>(&rhs->m_Death_books));
    ptree->appendChild("m_Chaos_books", new TreeItem<uint16_t>(&rhs->m_Chaos_books));
    ptree->appendChild("m_Skill", new TreeItem<eSkill16>(&rhs->m_Skill));
    return ptree;
}

TreeItemBase* constructTreeItem(WizardsExe_Game_Data* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_UnitNr_Active", new TreeItem<uint16_t>(&rhs->m_UnitNr_Active));
    ptree->appendChild("m_Current_Turn", new TreeItem<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_Number_of_Units", new TreeItem<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Number_of_Cities", new TreeItem<uint16_t>(&rhs->m_Number_of_Cities));
    ptree->appendChild("m_Difficulty", new TreeItem<eDifficulty>(&rhs->m_Difficulty));
    ptree->appendChild("m_Magic_Powerful_setting", new TreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    ptree->appendChild("m_Land_Size_setting", new TreeItem<eLand_Size>(&rhs->m_Land_Size_setting));
    ptree->appendChild("m_Number_of_Wizards", new TreeItem<uint16_t>(&rhs->m_Number_of_Wizards));
    return ptree;
}

TreeItemBase* constructTreeItem(WizardsExe_Pointers* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->addr_Spell_Data, "addr_Spell_Data"), "");
    ptree->appendChild("word_3FBD0", new TreeItem<uint16_t>(&rhs->word_3FBD0));
    ptree->appendChild("w_sound_x", new TreeItem<uint16_t>(&rhs->w_sound_x));
    ptree->appendChild("word_3FBD4", new TreeItem<uint16_t>(&rhs->word_3FBD4));
    ptree->appendTree(constructTreeItem(&rhs->addr_Items, "addr_Items"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_item_in_game_GUESS, "addr_item_in_game_GUESS"), "");
    TreeItemBase* ptreeunk__913E = ptree;
    if (26 > 3)
    {
        ptreeunk__913E = new TreeItemBase("unk__913E");
        ptree->appendTree(ptreeunk__913E, "");
    }
    for (int i = 0; i < 26; ++i)
    {
          std::ostringstream oss;
          oss << "unk__913E[" << i << "]";
          ptreeunk__913E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->unk__913E[i]));
    }
    TreeItemBase* ptreeunk_3FBF8 = ptree;
    if (23 > 3)
    {
        ptreeunk_3FBF8 = new TreeItemBase("unk_3FBF8");
        ptree->appendTree(ptreeunk_3FBF8, "");
    }
    for (int i = 0; i < 23; ++i)
    {
          std::ostringstream oss;
          oss << "unk_3FBF8[" << i << "]";
          ptreeunk_3FBF8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->unk_3FBF8[i]));
    }
    TreeItemBase* ptreeunk_3FC0F = ptree;
    if (183 > 3)
    {
        ptreeunk_3FC0F = new TreeItemBase("unk_3FC0F");
        ptree->appendTree(ptreeunk_3FC0F, "");
    }
    for (int i = 0; i < 183; ++i)
    {
          std::ostringstream oss;
          oss << "unk_3FC0F[" << i << "]";
          ptreeunk_3FC0F->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->unk_3FC0F[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->addr_Battle_Unit_View, "addr_Battle_Unit_View"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Battle_Unit, "addr_Battle_Unit"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Spells_Cast_in_Battle, "addr_Spells_Cast_in_Battle"), "");
    TreeItemBase* ptreeaddr_Hero_stat = ptree;
    if (6 > 3)
    {
        ptreeaddr_Hero_stat = new TreeItemBase("addr_Hero_stat");
        ptree->appendTree(ptreeaddr_Hero_stat, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "addr_Hero_stat[" << i << "]";
          ptreeaddr_Hero_stat->appendTree(constructTreeItem(&rhs->addr_Hero_stat[i], oss.str().c_str()), "");
    }
    TreeItemBase* ptreew_AI_flees = ptree;
    if (20 > 3)
    {
        ptreew_AI_flees = new TreeItemBase("w_AI_flees");
        ptree->appendTree(ptreew_AI_flees, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "w_AI_flees[" << i << "]";
          ptreew_AI_flees->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->w_AI_flees[i]));
    }
    TreeItemBase* ptreeword_3FCFE = ptree;
    if (10 > 3)
    {
        ptreeword_3FCFE = new TreeItemBase("word_3FCFE");
        ptree->appendTree(ptreeword_3FCFE, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FCFE[" << i << "]";
          ptreeword_3FCFE->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FCFE[i]));
    }
    ptree->appendChild("word_3FD08", new TreeItem<uint16_t>(&rhs->word_3FD08));
    ptree->appendChild("word_3FD0A", new TreeItem<uint16_t>(&rhs->word_3FD0A));
    ptree->appendChild("word_3FD0C", new TreeItem<uint16_t>(&rhs->word_3FD0C));
    ptree->appendChild("word_3FD0E", new TreeItem<uint16_t>(&rhs->word_3FD0E));
    ptree->appendChild("word_3FD10", new TreeItem<uint16_t>(&rhs->word_3FD10));
    ptree->appendChild("word_3FD12", new TreeItem<uint16_t>(&rhs->word_3FD12));
    ptree->appendTree(constructTreeItem(&rhs->addr_Battlefield, "addr_Battlefield"), "");
    ptree->appendChild("word_3FD18", new TreeItem<uint16_t>(&rhs->word_3FD18));
    ptree->appendChild("word_3FD1A", new TreeItem<uint16_t>(&rhs->word_3FD1A));
    ptree->appendChild("w_AI_on_the_move_GUESS", new TreeItem<uint16_t>(&rhs->w_AI_on_the_move_GUESS));
    ptree->appendChild("w_coo_X_Y_clicked", new TreeItem<uint16_t>(&rhs->w_coo_X_Y_clicked));
    ptree->appendChild("w_coo_Y_X_clicked", new TreeItem<uint16_t>(&rhs->w_coo_Y_X_clicked));
    ptree->appendChild("word_3FD22", new TreeItem<uint16_t>(&rhs->word_3FD22));
    ptree->appendChild("w_clash_place_type", new TreeItem<uint16_t>(&rhs->w_clash_place_type));
    TreeItemBase* ptreew_clash_place_ID = ptree;
    if (14 > 3)
    {
        ptreew_clash_place_ID = new TreeItemBase("w_clash_place_ID");
        ptree->appendTree(ptreew_clash_place_ID, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "w_clash_place_ID[" << i << "]";
          ptreew_clash_place_ID->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->w_clash_place_ID[i]));
    }
    ptree->appendChild("w_kyrub_dseg_9294", new TreeItem<int16_t>(&rhs->w_kyrub_dseg_9294));
    ptree->appendChild("w_kyrub_dseg_9296", new TreeItem<int16_t>(&rhs->w_kyrub_dseg_9296));
    TreeItemBase* ptreeword_3FD38 = ptree;
    if (20 > 3)
    {
        ptreeword_3FD38 = new TreeItemBase("word_3FD38");
        ptree->appendTree(ptreeword_3FD38, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD38[" << i << "]";
          ptreeword_3FD38->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FD38[i]));
    }
    ptree->appendChild("w_negat_encha_x17_flag_def", new TreeItem<uint16_t>(&rhs->w_negat_encha_x17_flag_def));
    ptree->appendChild("w_aggre_spell_color_flag_att", new TreeItem<uint16_t>(&rhs->w_aggre_spell_color_flag_att));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FD50, "dword_3FD50"), "");
    ptree->appendChild("word_3FD54", new TreeItem<uint16_t>(&rhs->word_3FD54));
    TreeItemBase* ptreeword_3FD56 = ptree;
    if (64 > 3)
    {
        ptreeword_3FD56 = new TreeItemBase("word_3FD56");
        ptree->appendTree(ptreeword_3FD56, "");
    }
    for (int i = 0; i < 64; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD56[" << i << "]";
          ptreeword_3FD56->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FD56[i]));
    }
    TreeItemBase* ptreeword_3FD96 = ptree;
    if (8 > 3)
    {
        ptreeword_3FD96 = new TreeItemBase("word_3FD96");
        ptree->appendTree(ptreeword_3FD96, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD96[" << i << "]";
          ptreeword_3FD96->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FD96[i]));
    }
    ptree->appendChild("word_3FD9E", new TreeItem<uint16_t>(&rhs->word_3FD9E));
    ptree->appendChild("word_3FDA0", new TreeItem<uint16_t>(&rhs->word_3FDA0));
    ptree->appendChild("word_3FDA2", new TreeItem<uint16_t>(&rhs->word_3FDA2));
    ptree->appendChild("word_3FDA4", new TreeItem<uint16_t>(&rhs->word_3FDA4));
    ptree->appendChild("word_3FDA6", new TreeItem<uint16_t>(&rhs->word_3FDA6));
    ptree->appendChild("word_3FDA8", new TreeItem<uint16_t>(&rhs->word_3FDA8));
    ptree->appendChild("word_3FDAA", new TreeItem<uint16_t>(&rhs->word_3FDAA));
    ptree->appendChild("word_3FDAC", new TreeItem<uint16_t>(&rhs->word_3FDAC));
    ptree->appendChild("word_3FDAE", new TreeItem<uint16_t>(&rhs->word_3FDAE));
    ptree->appendChild("word_3FDB0", new TreeItem<uint16_t>(&rhs->word_3FDB0));
    ptree->appendChild("word_3FDB2", new TreeItem<uint16_t>(&rhs->word_3FDB2));
    ptree->appendChild("word_3FDB4", new TreeItem<uint16_t>(&rhs->word_3FDB4));
    ptree->appendChild("word_3FDB6", new TreeItem<uint16_t>(&rhs->word_3FDB6));
    TreeItemBase* ptreeword_3FDB8 = ptree;
    if (44 > 3)
    {
        ptreeword_3FDB8 = new TreeItemBase("word_3FDB8");
        ptree->appendTree(ptreeword_3FDB8, "");
    }
    for (int i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FDB8[" << i << "]";
          ptreeword_3FDB8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FDB8[i]));
    }
    ptree->appendChild("word_3FDE4", new TreeItem<uint16_t>(&rhs->word_3FDE4));
    ptree->appendTree(constructTreeItem(&rhs->addr_3FDE6, "addr_3FDE6"), "");
    ptree->appendChild("word_3FDEA", new TreeItem<uint16_t>(&rhs->word_3FDEA));
    ptree->appendChild("word_3FDEC", new TreeItem<uint16_t>(&rhs->word_3FDEC));
    ptree->appendChild("word_3FDEE", new TreeItem<uint16_t>(&rhs->word_3FDEE));
    ptree->appendChild("word_3FDF0", new TreeItem<uint16_t>(&rhs->word_3FDF0));
    ptree->appendChild("word_3FDF2", new TreeItem<uint16_t>(&rhs->word_3FDF2));
    ptree->appendChild("word_3FDF4", new TreeItem<uint16_t>(&rhs->word_3FDF4));
    ptree->appendChild("word_3FDF6", new TreeItem<uint16_t>(&rhs->word_3FDF6));
    ptree->appendChild("word_3FDF8", new TreeItem<uint16_t>(&rhs->word_3FDF8));
    ptree->appendChild("word_3FDFA", new TreeItem<uint16_t>(&rhs->word_3FDFA));
    ptree->appendChild("word_3FDFC", new TreeItem<uint16_t>(&rhs->word_3FDFC));
    ptree->appendChild("word_3FDFE", new TreeItem<uint16_t>(&rhs->word_3FDFE));
    ptree->appendChild("word_3FE00", new TreeItem<uint16_t>(&rhs->word_3FE00));
    ptree->appendChild("word_3FE02", new TreeItem<uint16_t>(&rhs->word_3FE02));
    ptree->appendChild("word_3FE04", new TreeItem<uint16_t>(&rhs->word_3FE04));
    ptree->appendChild("word_3FE06", new TreeItem<uint16_t>(&rhs->word_3FE06));
    ptree->appendChild("word_3FE08", new TreeItem<uint16_t>(&rhs->word_3FE08));
    ptree->appendChild("word_3FE0A", new TreeItem<uint16_t>(&rhs->word_3FE0A));
    ptree->appendChild("word_3FE0C", new TreeItem<uint16_t>(&rhs->word_3FE0C));
    ptree->appendChild("word_3FE0E", new TreeItem<uint16_t>(&rhs->word_3FE0E));
    ptree->appendChild("word_3FE10", new TreeItem<uint16_t>(&rhs->word_3FE10));
    ptree->appendChild("word_3FE12", new TreeItem<uint16_t>(&rhs->word_3FE12));
    ptree->appendChild("word_3FE14", new TreeItem<uint16_t>(&rhs->word_3FE14));
    ptree->appendChild("word_3FE16", new TreeItem<uint16_t>(&rhs->word_3FE16));
    ptree->appendChild("word_3FE18", new TreeItem<uint16_t>(&rhs->word_3FE18));
    ptree->appendChild("word_3FE1A", new TreeItem<uint16_t>(&rhs->word_3FE1A));
    ptree->appendChild("word_3FE1C", new TreeItem<uint16_t>(&rhs->word_3FE1C));
    ptree->appendChild("word_3FE1E", new TreeItem<uint16_t>(&rhs->word_3FE1E));
    ptree->appendChild("word_3FE20", new TreeItem<uint16_t>(&rhs->word_3FE20));
    ptree->appendChild("word_3FE22", new TreeItem<uint16_t>(&rhs->word_3FE22));
    ptree->appendChild("word_3FE24", new TreeItem<uint16_t>(&rhs->word_3FE24));
    ptree->appendChild("word_3FE26", new TreeItem<uint16_t>(&rhs->word_3FE26));
    ptree->appendChild("word_3FE28", new TreeItem<uint16_t>(&rhs->word_3FE28));
    ptree->appendChild("word_3FE2A", new TreeItem<uint16_t>(&rhs->word_3FE2A));
    ptree->appendTree(constructTreeItem(&rhs->addr_Building_Data, "addr_Building_Data"), "");
    ptree->appendChild("word_3FE30", new TreeItem<uint16_t>(&rhs->word_3FE30));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FE32, "dword_3FE32"), "");
    TreeItemBase* ptreedword_3FE36 = ptree;
    if (126 > 3)
    {
        ptreedword_3FE36 = new TreeItemBase("dword_3FE36");
        ptree->appendTree(ptreedword_3FE36, "");
    }
    for (int i = 0; i < 126; ++i)
    {
          std::ostringstream oss;
          oss << "dword_3FE36[" << i << "]";
          ptreedword_3FE36->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->dword_3FE36[i]));
    }
    TreeItemBase* ptreeword_3FEB4 = ptree;
    if (6 > 3)
    {
        ptreeword_3FEB4 = new TreeItemBase("word_3FEB4");
        ptree->appendTree(ptreeword_3FEB4, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEB4[" << i << "]";
          ptreeword_3FEB4->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FEB4[i]));
    }
    TreeItemBase* ptreeword_3FEBA = ptree;
    if (18 > 3)
    {
        ptreeword_3FEBA = new TreeItemBase("word_3FEBA");
        ptree->appendTree(ptreeword_3FEBA, "");
    }
    for (int i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEBA[" << i << "]";
          ptreeword_3FEBA->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FEBA[i]));
    }
    TreeItemBase* ptreeword_3FECC = ptree;
    if (22 > 3)
    {
        ptreeword_3FECC = new TreeItemBase("word_3FECC");
        ptree->appendTree(ptreeword_3FECC, "");
    }
    for (int i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FECC[" << i << "]";
          ptreeword_3FECC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FECC[i]));
    }
    ptree->appendChild("word_3FEE2", new TreeItem<uint16_t>(&rhs->word_3FEE2));
    ptree->appendChild("w_all_units_moved_GUESS", new TreeItem<uint16_t>(&rhs->w_all_units_moved_GUESS));
    ptree->appendChild("word_3FEE6", new TreeItem<uint16_t>(&rhs->word_3FEE6));
    ptree->appendChild("word_3FEE8", new TreeItem<uint16_t>(&rhs->word_3FEE8));
    ptree->appendChild("word_3FEEA", new TreeItem<uint16_t>(&rhs->word_3FEEA));
    TreeItemBase* ptreeword_3FEEC = ptree;
    if (6 > 3)
    {
        ptreeword_3FEEC = new TreeItemBase("word_3FEEC");
        ptree->appendTree(ptreeword_3FEEC, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEEC[" << i << "]";
          ptreeword_3FEEC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FEEC[i]));
    }
    TreeItemBase* ptreeword_3FEF2 = ptree;
    if (14 > 3)
    {
        ptreeword_3FEF2 = new TreeItemBase("word_3FEF2");
        ptree->appendTree(ptreeword_3FEF2, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEF2[" << i << "]";
          ptreeword_3FEF2->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FEF2[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->word_3FF00, "word_3FF00"), "");
    ptree->appendChild("word_3FF04", new TreeItem<uint16_t>(&rhs->word_3FF04));
    ptree->appendChild("word_3FF06", new TreeItem<uint16_t>(&rhs->word_3FF06));
    ptree->appendChild("word_3FF08", new TreeItem<uint16_t>(&rhs->word_3FF08));
    ptree->appendChild("word_3FF0A", new TreeItem<uint16_t>(&rhs->word_3FF0A));
    ptree->appendChild("word_3FF0C", new TreeItem<uint16_t>(&rhs->word_3FF0C));
    ptree->appendChild("word_3FF0E", new TreeItem<uint16_t>(&rhs->word_3FF0E));
    TreeItemBase* ptreeword_3FF10 = ptree;
    if (14 > 3)
    {
        ptreeword_3FF10 = new TreeItemBase("word_3FF10");
        ptree->appendTree(ptreeword_3FF10, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF10[" << i << "]";
          ptreeword_3FF10->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FF10[i]));
    }
    ptree->appendChild("word_3FF1E", new TreeItem<uint16_t>(&rhs->word_3FF1E));
    ptree->appendChild("word_3FF20", new TreeItem<uint16_t>(&rhs->word_3FF20));
    ptree->appendChild("word_3FF22", new TreeItem<uint16_t>(&rhs->word_3FF22));
    ptree->appendChild("word_3FF24", new TreeItem<uint16_t>(&rhs->word_3FF24));
    ptree->appendChild("word_3FF26", new TreeItem<uint16_t>(&rhs->word_3FF26));
    ptree->appendChild("word_3FF28", new TreeItem<uint16_t>(&rhs->word_3FF28));
    ptree->appendChild("word_3FF2A", new TreeItem<uint16_t>(&rhs->word_3FF2A));
    ptree->appendChild("word_3FF2C", new TreeItem<uint16_t>(&rhs->word_3FF2C));
    TreeItemBase* ptreeword_3FF2E = ptree;
    if (6 > 3)
    {
        ptreeword_3FF2E = new TreeItemBase("word_3FF2E");
        ptree->appendTree(ptreeword_3FF2E, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF2E[" << i << "]";
          ptreeword_3FF2E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FF2E[i]));
    }
    ptree->appendChild("word_3FF34", new TreeItem<uint16_t>(&rhs->word_3FF34));
    ptree->appendChild("word_3FF36", new TreeItem<uint16_t>(&rhs->word_3FF36));
    ptree->appendChild("word_3FF38", new TreeItem<uint16_t>(&rhs->word_3FF38));
    ptree->appendChild("word_3FF3A", new TreeItem<uint16_t>(&rhs->word_3FF3A));
    ptree->appendChild("word_3FF3C", new TreeItem<uint16_t>(&rhs->word_3FF3C));
    ptree->appendChild("word_3FF3E", new TreeItem<uint16_t>(&rhs->word_3FF3E));
    ptree->appendChild("word_3FF40", new TreeItem<uint16_t>(&rhs->word_3FF40));
    ptree->appendChild("word_3FF42", new TreeItem<uint16_t>(&rhs->word_3FF42));
    ptree->appendChild("word_3FF44", new TreeItem<uint16_t>(&rhs->word_3FF44));
    ptree->appendChild("word_3FF46", new TreeItem<uint16_t>(&rhs->word_3FF46));
    ptree->appendChild("word_3FF48", new TreeItem<uint16_t>(&rhs->word_3FF48));
    ptree->appendChild("word_3FF4A", new TreeItem<uint16_t>(&rhs->word_3FF4A));
    TreeItemBase* ptreeword_3FF4C = ptree;
    if (58 > 3)
    {
        ptreeword_3FF4C = new TreeItemBase("word_3FF4C");
        ptree->appendTree(ptreeword_3FF4C, "");
    }
    for (int i = 0; i < 58; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF4C[" << i << "]";
          ptreeword_3FF4C->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FF4C[i]));
    }
    ptree->appendChild("word_3FF86", new TreeItem<uint16_t>(&rhs->word_3FF86));
    ptree->appendChild("word_3FF88", new TreeItem<uint16_t>(&rhs->word_3FF88));
    ptree->appendChild("word_3FF8A", new TreeItem<uint16_t>(&rhs->word_3FF8A));
    ptree->appendChild("word_3FF8C", new TreeItem<uint16_t>(&rhs->word_3FF8C));
    ptree->appendChild("word_3FF8E", new TreeItem<uint16_t>(&rhs->word_3FF8E));
    TreeItemBase* ptreeword_3FF90 = ptree;
    if (30 > 3)
    {
        ptreeword_3FF90 = new TreeItemBase("word_3FF90");
        ptree->appendTree(ptreeword_3FF90, "");
    }
    for (int i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF90[" << i << "]";
          ptreeword_3FF90->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FF90[i]));
    }
    ptree->appendChild("word_3FFAE", new TreeItem<uint16_t>(&rhs->word_3FFAE));
    ptree->appendChild("word_3FFB0", new TreeItem<uint16_t>(&rhs->word_3FFB0));
    ptree->appendChild("word_3FFB2", new TreeItem<uint16_t>(&rhs->word_3FFB2));
    ptree->appendChild("word_3FFB4", new TreeItem<uint16_t>(&rhs->word_3FFB4));
    ptree->appendChild("word_3FFB6", new TreeItem<uint16_t>(&rhs->word_3FFB6));
    ptree->appendChild("word_3FFB8", new TreeItem<uint16_t>(&rhs->word_3FFB8));
    ptree->appendChild("word_3FFBA", new TreeItem<uint16_t>(&rhs->word_3FFBA));
    ptree->appendChild("word_3FFBC", new TreeItem<uint16_t>(&rhs->word_3FFBC));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFBE, "word_3FFBE"), "");
    ptree->appendChild("word_3FFC2", new TreeItem<uint16_t>(&rhs->word_3FFC2));
    ptree->appendChild("word_3FFC4", new TreeItem<uint16_t>(&rhs->word_3FFC4));
    ptree->appendChild("word_3FFC6", new TreeItem<uint16_t>(&rhs->word_3FFC6));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFC8, "word_3FFC8"), "");
    ptree->appendChild("word_3FFCC", new TreeItem<uint16_t>(&rhs->word_3FFCC));
    TreeItemBase* ptreeword_3FFCE = ptree;
    if (14 > 3)
    {
        ptreeword_3FFCE = new TreeItemBase("word_3FFCE");
        ptree->appendTree(ptreeword_3FFCE, "");
    }
    for (int i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFCE[" << i << "]";
          ptreeword_3FFCE->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FFCE[i]));
    }
    ptree->appendChild("word_3FFDC", new TreeItem<uint16_t>(&rhs->word_3FFDC));
    ptree->appendChild("word_3FFDE", new TreeItem<uint16_t>(&rhs->word_3FFDE));
    TreeItemBase* ptreeword_3FFE0 = ptree;
    if (8 > 3)
    {
        ptreeword_3FFE0 = new TreeItemBase("word_3FFE0");
        ptree->appendTree(ptreeword_3FFE0, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE0[" << i << "]";
          ptreeword_3FFE0->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FFE0[i]));
    }
    TreeItemBase* ptreeword_3FFE8 = ptree;
    if (38 > 3)
    {
        ptreeword_3FFE8 = new TreeItemBase("word_3FFE8");
        ptree->appendTree(ptreeword_3FFE8, "");
    }
    for (int i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE8[" << i << "]";
          ptreeword_3FFE8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_3FFE8[i]));
    }
    ptree->appendChild("word_4000E", new TreeItem<uint16_t>(&rhs->word_4000E));
    ptree->appendChild("word_40010", new TreeItem<uint16_t>(&rhs->word_40010));
    ptree->appendChild("word_40012", new TreeItem<uint16_t>(&rhs->word_40012));
    ptree->appendChild("word_40014", new TreeItem<uint16_t>(&rhs->word_40014));
    ptree->appendChild("word_40016", new TreeItem<uint16_t>(&rhs->word_40016));
    ptree->appendChild("word_40018", new TreeItem<uint16_t>(&rhs->word_40018));
    ptree->appendChild("word_4001A", new TreeItem<uint16_t>(&rhs->word_4001A));
    ptree->appendChild("word_4001C", new TreeItem<uint16_t>(&rhs->word_4001C));
    ptree->appendChild("word_4001E", new TreeItem<uint16_t>(&rhs->word_4001E));
    ptree->appendChild("word_40020", new TreeItem<uint16_t>(&rhs->word_40020));
    ptree->appendChild("word_40022", new TreeItem<uint16_t>(&rhs->word_40022));
    ptree->appendChild("word_40024", new TreeItem<uint16_t>(&rhs->word_40024));
    ptree->appendChild("word_40026", new TreeItem<uint16_t>(&rhs->word_40026));
    ptree->appendChild("word_40028", new TreeItem<uint16_t>(&rhs->word_40028));
    ptree->appendChild("word_4002A", new TreeItem<uint16_t>(&rhs->word_4002A));
    ptree->appendChild("word_4002C", new TreeItem<uint16_t>(&rhs->word_4002C));
    TreeItemBase* ptreeword_4002E = ptree;
    if (28 > 3)
    {
        ptreeword_4002E = new TreeItemBase("word_4002E");
        ptree->appendTree(ptreeword_4002E, "");
    }
    for (int i = 0; i < 28; ++i)
    {
          std::ostringstream oss;
          oss << "word_4002E[" << i << "]";
          ptreeword_4002E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4002E[i]));
    }
    ptree->appendChild("word_4004A", new TreeItem<uint16_t>(&rhs->word_4004A));
    ptree->appendChild("word_4004C", new TreeItem<uint16_t>(&rhs->word_4004C));
    ptree->appendChild("word_4004E", new TreeItem<uint16_t>(&rhs->word_4004E));
    ptree->appendChild("word_40050", new TreeItem<uint16_t>(&rhs->word_40050));
    ptree->appendChild("word_40052", new TreeItem<uint16_t>(&rhs->word_40052));
    ptree->appendChild("word_40054", new TreeItem<uint16_t>(&rhs->word_40054));
    ptree->appendChild("word_40056", new TreeItem<uint16_t>(&rhs->word_40056));
    ptree->appendChild("word_40058", new TreeItem<uint16_t>(&rhs->word_40058));
    ptree->appendChild("word_4005A", new TreeItem<uint16_t>(&rhs->word_4005A));
    ptree->appendChild("word_4005C", new TreeItem<uint16_t>(&rhs->word_4005C));
    ptree->appendChild("word_4005E", new TreeItem<uint16_t>(&rhs->word_4005E));
    ptree->appendChild("word_40060", new TreeItem<uint16_t>(&rhs->word_40060));
    TreeItemBase* ptreeword_40062 = ptree;
    if (12 > 3)
    {
        ptreeword_40062 = new TreeItemBase("word_40062");
        ptree->appendTree(ptreeword_40062, "");
    }
    for (int i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "word_40062[" << i << "]";
          ptreeword_40062->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40062[i]));
    }
    TreeItemBase* ptreeword_4006E = ptree;
    if (34 > 3)
    {
        ptreeword_4006E = new TreeItemBase("word_4006E");
        ptree->appendTree(ptreeword_4006E, "");
    }
    for (int i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4006E[" << i << "]";
          ptreeword_4006E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4006E[i]));
    }
    ptree->appendChild("word_40090", new TreeItem<uint16_t>(&rhs->word_40090));
    TreeItemBase* ptreeword_40092 = ptree;
    if (82 > 3)
    {
        ptreeword_40092 = new TreeItemBase("word_40092");
        ptree->appendTree(ptreeword_40092, "");
    }
    for (int i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "word_40092[" << i << "]";
          ptreeword_40092->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40092[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->addr_city_detailed_GUESS, "addr_city_detailed_GUESS"), "");
    TreeItemBase* ptreeword_400E8 = ptree;
    if (244 > 3)
    {
        ptreeword_400E8 = new TreeItemBase("word_400E8");
        ptree->appendTree(ptreeword_400E8, "");
    }
    for (int i = 0; i < 244; ++i)
    {
          std::ostringstream oss;
          oss << "word_400E8[" << i << "]";
          ptreeword_400E8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_400E8[i]));
    }
    ptree->appendChild("word_401DC", new TreeItem<uint16_t>(&rhs->word_401DC));
    ptree->appendChild("word_401DE", new TreeItem<uint16_t>(&rhs->word_401DE));
    ptree->appendChild("word_401E0", new TreeItem<uint16_t>(&rhs->word_401E0));
    ptree->appendChild("word_401E2", new TreeItem<uint16_t>(&rhs->word_401E2));
    ptree->appendChild("word_401E4", new TreeItem<uint16_t>(&rhs->word_401E4));
    ptree->appendChild("word_401E6", new TreeItem<uint16_t>(&rhs->word_401E6));
    ptree->appendChild("word_401E8", new TreeItem<uint16_t>(&rhs->word_401E8));
    ptree->appendChild("word_401EA", new TreeItem<uint16_t>(&rhs->word_401EA));
    ptree->appendChild("word_401EC", new TreeItem<uint16_t>(&rhs->word_401EC));
    ptree->appendChild("word_401EE", new TreeItem<uint16_t>(&rhs->word_401EE));
    ptree->appendChild("word_401F0", new TreeItem<uint16_t>(&rhs->word_401F0));
    ptree->appendChild("word_401F2", new TreeItem<uint16_t>(&rhs->word_401F2));
    ptree->appendChild("word_401F4", new TreeItem<uint16_t>(&rhs->word_401F4));
    ptree->appendChild("word_401F6", new TreeItem<uint16_t>(&rhs->word_401F6));
    ptree->appendChild("word_401F8", new TreeItem<uint16_t>(&rhs->word_401F8));
    ptree->appendChild("word_401FA", new TreeItem<uint16_t>(&rhs->word_401FA));
    ptree->appendChild("word_401FC", new TreeItem<uint16_t>(&rhs->word_401FC));
    ptree->appendChild("word_401FE", new TreeItem<uint16_t>(&rhs->word_401FE));
    ptree->appendChild("word_40200", new TreeItem<uint16_t>(&rhs->word_40200));
    ptree->appendChild("word_40202", new TreeItem<uint16_t>(&rhs->word_40202));
    ptree->appendChild("word_40204", new TreeItem<uint16_t>(&rhs->word_40204));
    ptree->appendChild("word_40206", new TreeItem<uint16_t>(&rhs->word_40206));
    ptree->appendChild("word_40208", new TreeItem<uint16_t>(&rhs->word_40208));
    ptree->appendChild("word_4020A", new TreeItem<uint16_t>(&rhs->word_4020A));
    TreeItemBase* ptreeword_4020C = ptree;
    if (38 > 3)
    {
        ptreeword_4020C = new TreeItemBase("word_4020C");
        ptree->appendTree(ptreeword_4020C, "");
    }
    for (int i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_4020C[" << i << "]";
          ptreeword_4020C->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4020C[i]));
    }
    ptree->appendChild("word_40232", new TreeItem<uint16_t>(&rhs->word_40232));
    ptree->appendChild("word_40234", new TreeItem<uint16_t>(&rhs->word_40234));
    ptree->appendChild("word_40236", new TreeItem<uint16_t>(&rhs->word_40236));
    ptree->appendChild("word_40238", new TreeItem<uint16_t>(&rhs->word_40238));
    ptree->appendChild("word_4023A", new TreeItem<uint16_t>(&rhs->word_4023A));
    ptree->appendChild("word_4023C", new TreeItem<uint16_t>(&rhs->word_4023C));
    ptree->appendChild("word_4023E", new TreeItem<uint16_t>(&rhs->word_4023E));
    ptree->appendChild("word_40240", new TreeItem<uint16_t>(&rhs->word_40240));
    TreeItemBase* ptreeword_40242 = ptree;
    if (18 > 3)
    {
        ptreeword_40242 = new TreeItemBase("word_40242");
        ptree->appendTree(ptreeword_40242, "");
    }
    for (int i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_40242[" << i << "]";
          ptreeword_40242->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40242[i]));
    }
    ptree->appendChild("word_40254", new TreeItem<uint16_t>(&rhs->word_40254));
    ptree->appendChild("word_40256", new TreeItem<uint16_t>(&rhs->word_40256));
    ptree->appendChild("word_40258", new TreeItem<uint16_t>(&rhs->word_40258));
    TreeItemBase* ptreeword_4025A = ptree;
    if (50 > 3)
    {
        ptreeword_4025A = new TreeItemBase("word_4025A");
        ptree->appendTree(ptreeword_4025A, "");
    }
    for (int i = 0; i < 50; ++i)
    {
          std::ostringstream oss;
          oss << "word_4025A[" << i << "]";
          ptreeword_4025A->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4025A[i]));
    }
    ptree->appendChild("word_4028C", new TreeItem<uint16_t>(&rhs->word_4028C));
    TreeItemBase* ptreeword_4028E = ptree;
    if (10 > 3)
    {
        ptreeword_4028E = new TreeItemBase("word_4028E");
        ptree->appendTree(ptreeword_4028E, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4028E[" << i << "]";
          ptreeword_4028E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4028E[i]));
    }
    ptree->appendChild("word_40298", new TreeItem<uint16_t>(&rhs->word_40298));
    ptree->appendChild("word_4029A", new TreeItem<uint16_t>(&rhs->word_4029A));
    ptree->appendChild("word_4029C", new TreeItem<uint16_t>(&rhs->word_4029C));
    TreeItemBase* ptreeword_4029E = ptree;
    if (34 > 3)
    {
        ptreeword_4029E = new TreeItemBase("word_4029E");
        ptree->appendTree(ptreeword_4029E, "");
    }
    for (int i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4029E[" << i << "]";
          ptreeword_4029E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4029E[i]));
    }
    TreeItemBase* ptreeword_402C0 = ptree;
    if (32 > 3)
    {
        ptreeword_402C0 = new TreeItemBase("word_402C0");
        ptree->appendTree(ptreeword_402C0, "");
    }
    for (int i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "word_402C0[" << i << "]";
          ptreeword_402C0->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_402C0[i]));
    }
    ptree->appendChild("word_402E0", new TreeItem<uint16_t>(&rhs->word_402E0));
    TreeItemBase* ptreeword_402E2 = ptree;
    if (36 > 3)
    {
        ptreeword_402E2 = new TreeItemBase("word_402E2");
        ptree->appendTree(ptreeword_402E2, "");
    }
    for (int i = 0; i < 36; ++i)
    {
          std::ostringstream oss;
          oss << "word_402E2[" << i << "]";
          ptreeword_402E2->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_402E2[i]));
    }
    TreeItemBase* ptreeword_40306 = ptree;
    if (120 > 3)
    {
        ptreeword_40306 = new TreeItemBase("word_40306");
        ptree->appendTree(ptreeword_40306, "");
    }
    for (int i = 0; i < 120; ++i)
    {
          std::ostringstream oss;
          oss << "word_40306[" << i << "]";
          ptreeword_40306->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40306[i]));
    }
    TreeItemBase* ptreeword_4037E = ptree;
    if (10 > 3)
    {
        ptreeword_4037E = new TreeItemBase("word_4037E");
        ptree->appendTree(ptreeword_4037E, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4037E[" << i << "]";
          ptreeword_4037E->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_4037E[i]));
    }
    TreeItemBase* ptreeword_40388 = ptree;
    if (10 > 3)
    {
        ptreeword_40388 = new TreeItemBase("word_40388");
        ptree->appendTree(ptreeword_40388, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_40388[" << i << "]";
          ptreeword_40388->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40388[i]));
    }
    ptree->appendChild("word_40392", new TreeItem<uint16_t>(&rhs->word_40392));
    TreeItemBase* ptreeword_40394 = ptree;
    if (20 > 3)
    {
        ptreeword_40394 = new TreeItemBase("word_40394");
        ptree->appendTree(ptreeword_40394, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_40394[" << i << "]";
          ptreeword_40394->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_40394[i]));
    }
    TreeItemBase* ptreeword_403A8 = ptree;
    if (6 > 3)
    {
        ptreeword_403A8 = new TreeItemBase("word_403A8");
        ptree->appendTree(ptreeword_403A8, "");
    }
    for (int i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_403A8[" << i << "]";
          ptreeword_403A8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_403A8[i]));
    }
    TreeItemBase* ptreeword_403AE = ptree;
    if (10 > 3)
    {
        ptreeword_403AE = new TreeItemBase("word_403AE");
        ptree->appendTree(ptreeword_403AE, "");
    }
    for (int i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_403AE[" << i << "]";
          ptreeword_403AE->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_403AE[i]));
    }
    ptree->appendChild("word_403B8", new TreeItem<uint16_t>(&rhs->word_403B8));
    ptree->appendChild("word_403BA", new TreeItem<uint16_t>(&rhs->word_403BA));
    ptree->appendChild("word_403BC", new TreeItem<uint16_t>(&rhs->word_403BC));
    ptree->appendChild("word_403BE", new TreeItem<uint16_t>(&rhs->word_403BE));
    ptree->appendChild("word_403C0", new TreeItem<uint16_t>(&rhs->word_403C0));
    TreeItemBase* ptreeword_403C2 = ptree;
    if (20 > 3)
    {
        ptreeword_403C2 = new TreeItemBase("word_403C2");
        ptree->appendTree(ptreeword_403C2, "");
    }
    for (int i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_403C2[" << i << "]";
          ptreeword_403C2->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->word_403C2[i]));
    }
    ptree->appendChild("word_403D6", new TreeItem<uint16_t>(&rhs->word_403D6));
    ptree->appendChild("word_403D8", new TreeItem<uint16_t>(&rhs->word_403D8));
    ptree->appendChild("word_403DA", new TreeItem<uint16_t>(&rhs->word_403DA));
    ptree->appendChild("word_403DC", new TreeItem<uint16_t>(&rhs->word_403DC));
    ptree->appendChild("word_403DE", new TreeItem<uint16_t>(&rhs->word_403DE));
    ptree->appendChild("word_403E0", new TreeItem<uint16_t>(&rhs->word_403E0));
    ptree->appendChild("word_403E2", new TreeItem<uint16_t>(&rhs->word_403E2));
    ptree->appendChild("word_403E4", new TreeItem<uint16_t>(&rhs->word_403E4));
    ptree->appendChild("word_403E6", new TreeItem<uint16_t>(&rhs->word_403E6));
    ptree->appendChild("word_403E8", new TreeItem<uint16_t>(&rhs->word_403E8));
    ptree->appendChild("word_403EA", new TreeItem<uint16_t>(&rhs->word_403EA));
    ptree->appendChild("word_403EC", new TreeItem<uint16_t>(&rhs->word_403EC));
    ptree->appendChild("word_403EE", new TreeItem<uint16_t>(&rhs->word_403EE));
    ptree->appendChild("word_403F0", new TreeItem<uint16_t>(&rhs->word_403F0));
    ptree->appendChild("word_403F2", new TreeItem<uint16_t>(&rhs->word_403F2));
    ptree->appendChild("word_403F4", new TreeItem<uint16_t>(&rhs->word_403F4));
    ptree->appendChild("word_403F6", new TreeItem<uint16_t>(&rhs->word_403F6));
    ptree->appendChild("word_403F8", new TreeItem<uint16_t>(&rhs->word_403F8));
    ptree->appendChild("word_403FA", new TreeItem<uint16_t>(&rhs->word_403FA));
    ptree->appendChild("word_403FC", new TreeItem<uint16_t>(&rhs->word_403FC));
    ptree->appendTree(constructTreeItem(&rhs->word_403FE, "word_403FE"), "");
    ptree->appendChild("word_40402", new TreeItem<uint16_t>(&rhs->word_40402));
    ptree->appendChild("word_40404", new TreeItem<uint16_t>(&rhs->word_40404));
    ptree->appendChild("word_40406", new TreeItem<uint16_t>(&rhs->word_40406));
    ptree->appendChild("word_40408", new TreeItem<uint16_t>(&rhs->word_40408));
    ptree->appendChild("word_4040A", new TreeItem<uint16_t>(&rhs->word_4040A));
    ptree->appendChild("word_4040C", new TreeItem<uint16_t>(&rhs->word_4040C));
    ptree->appendChild("word_4040E", new TreeItem<uint16_t>(&rhs->word_4040E));
    ptree->appendChild("word_40410", new TreeItem<uint16_t>(&rhs->word_40410));
    ptree->appendChild("word_40412", new TreeItem<uint16_t>(&rhs->word_40412));
    ptree->appendChild("word_40414", new TreeItem<uint16_t>(&rhs->word_40414));
    ptree->appendChild("word_40416", new TreeItem<uint16_t>(&rhs->word_40416));
    ptree->appendChild("word_40418", new TreeItem<uint16_t>(&rhs->word_40418));
    ptree->appendChild("word_4041A", new TreeItem<uint16_t>(&rhs->word_4041A));
    ptree->appendChild("word_4041C", new TreeItem<uint16_t>(&rhs->word_4041C));
    ptree->appendChild("word_4041E", new TreeItem<uint16_t>(&rhs->word_4041E));
    ptree->appendChild("word_40420", new TreeItem<uint16_t>(&rhs->word_40420));
    ptree->appendChild("word_40422", new TreeItem<uint16_t>(&rhs->word_40422));
    ptree->appendChild("word_40424", new TreeItem<uint16_t>(&rhs->word_40424));
    ptree->appendChild("word_40426", new TreeItem<uint16_t>(&rhs->word_40426));
    ptree->appendTree(constructTreeItem(&rhs->word_40428, "word_40428"), "");
    ptree->appendChild("word_4042C", new TreeItem<uint16_t>(&rhs->word_4042C));
    ptree->appendChild("w_constant_GUESS", new TreeItem<uint16_t>(&rhs->w_constant_GUESS));
    ptree->appendChild("w_Game_flow", new TreeItem<eGameState>(&rhs->w_Game_flow));
    ptree->appendChild("word_40432", new TreeItem<uint16_t>(&rhs->word_40432));
    ptree->appendChild("word_40434", new TreeItem<uint16_t>(&rhs->word_40434));
    ptree->appendChild("word_40436", new TreeItem<uint16_t>(&rhs->word_40436));
    ptree->appendTree(constructTreeItem(&rhs->addr_events, "addr_events"), "");
    ptree->appendChild("w_uts_in_stack_ovrland_GUESS", new TreeItem<uint16_t>(&rhs->w_uts_in_stack_ovrland_GUESS));
    TreeItemBase* ptreew_Stack_active_GUESS = ptree;
    if (36 > 3)
    {
        ptreew_Stack_active_GUESS = new TreeItemBase("w_Stack_active_GUESS");
        ptree->appendTree(ptreew_Stack_active_GUESS, "");
    }
    for (int i = 0; i < 36; ++i)
    {
          std::ostringstream oss;
          oss << "w_Stack_active_GUESS[" << i << "]";
          ptreew_Stack_active_GUESS->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->w_Stack_active_GUESS[i]));
    }
    TreeItemBase* ptreebyte_40462 = ptree;
    if (281 > 3)
    {
        ptreebyte_40462 = new TreeItemBase("byte_40462");
        ptree->appendTree(ptreebyte_40462, "");
    }
    for (int i = 0; i < 281; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40462[" << i << "]";
          ptreebyte_40462->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_40462[i]));
    }
    TreeItemBase* ptreebyte_4057B = ptree;
    if (21 > 3)
    {
        ptreebyte_4057B = new TreeItemBase("byte_4057B");
        ptree->appendTree(ptreebyte_4057B, "");
    }
    for (int i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_4057B[" << i << "]";
          ptreebyte_4057B->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_4057B[i]));
    }
    TreeItemBase* ptreeb_mess_number = ptree;
    if (82 > 3)
    {
        ptreeb_mess_number = new TreeItemBase("b_mess_number");
        ptree->appendTree(ptreeb_mess_number, "");
    }
    for (int i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "b_mess_number[" << i << "]";
          ptreeb_mess_number->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->b_mess_number[i]));
    }
    TreeItemBase* ptreebyte_405E2 = ptree;
    if (82 > 3)
    {
        ptreebyte_405E2 = new TreeItemBase("byte_405E2");
        ptree->appendTree(ptreebyte_405E2, "");
    }
    for (int i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_405E2[" << i << "]";
          ptreebyte_405E2->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_405E2[i]));
    }
    TreeItemBase* ptreebyte_40634 = ptree;
    if (82 > 3)
    {
        ptreebyte_40634 = new TreeItemBase("byte_40634");
        ptree->appendTree(ptreebyte_40634, "");
    }
    for (int i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40634[" << i << "]";
          ptreebyte_40634->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_40634[i]));
    }
    TreeItemBase* ptreebyte_40686 = ptree;
    if (82 > 3)
    {
        ptreebyte_40686 = new TreeItemBase("byte_40686");
        ptree->appendTree(ptreebyte_40686, "");
    }
    for (int i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40686[" << i << "]";
          ptreebyte_40686->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_40686[i]));
    }
    TreeItemBase* ptreebyte_406D8 = ptree;
    if (21 > 3)
    {
        ptreebyte_406D8 = new TreeItemBase("byte_406D8");
        ptree->appendTree(ptreebyte_406D8, "");
    }
    for (int i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406D8[" << i << "]";
          ptreebyte_406D8->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_406D8[i]));
    }
    TreeItemBase* ptreebyte_406ED = ptree;
    if (21 > 3)
    {
        ptreebyte_406ED = new TreeItemBase("byte_406ED");
        ptree->appendTree(ptreebyte_406ED, "");
    }
    for (int i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406ED[" << i << "]";
          ptreebyte_406ED->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_406ED[i]));
    }
    TreeItemBase* ptreebyte_40702 = ptree;
    if (21 > 3)
    {
        ptreebyte_40702 = new TreeItemBase("byte_40702");
        ptree->appendTree(ptreebyte_40702, "");
    }
    for (int i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40702[" << i << "]";
          ptreebyte_40702->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_40702[i]));
    }
    TreeItemBase* ptreebyte_40717 = ptree;
    if (21 > 3)
    {
        ptreebyte_40717 = new TreeItemBase("byte_40717");
        ptree->appendTree(ptreebyte_40717, "");
    }
    for (int i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40717[" << i << "]";
          ptreebyte_40717->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->byte_40717[i]));
    }
    ptree->appendChild("byte_4072C", new TreeItem<uint16_t>(&rhs->byte_4072C));
    ptree->appendChild("w_video_style_CL_BUG_GUESS", new TreeItem<uint16_t>(&rhs->w_video_style_CL_BUG_GUESS));
    ptree->appendTree(constructTreeItem(&rhs->dword_40730, "dword_40730"), "");
    ptree->appendChild("word_40734", new TreeItem<uint16_t>(&rhs->word_40734));
    ptree->appendChild("word_40736", new TreeItem<uint16_t>(&rhs->word_40736));
    ptree->appendChild("word_40738", new TreeItem<uint16_t>(&rhs->word_40738));
    ptree->appendChild("word_4073A", new TreeItem<uint16_t>(&rhs->word_4073A));
    ptree->appendTree(constructTreeItem(&rhs->dword_4073C, "dword_4073C"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_40740, "dword_40740"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_terrain_cost_GUESS, "addr_terrain_cost_GUESS"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_40748, "dword_40748"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_4074C, "dword_4074C"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_terrain_scouted_loc, "addr_terrain_scouted_loc"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_changed_terrain_loc, "addr_changed_terrain_loc"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_special_terrain_loc_, "addr_special_terrain_loc_"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Cities, "addr_Cities"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Lairs_data, "addr_Lairs_data"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_tower_attr, "addr_tower_attr"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_fortress_data, "addr_fortress_data"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Nodes_Attr, "addr_Nodes_Attr"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_Continent_, "addr_Continent_"), "");
    ptree->appendChild("word_40774", new TreeItem<uint16_t>(&rhs->word_40774));
    ptree->appendChild("word_40776", new TreeItem<uint16_t>(&rhs->word_40776));
    ptree->appendChild("word_40778", new TreeItem<uint16_t>(&rhs->word_40778));
    ptree->appendChild("word_4077A", new TreeItem<uint16_t>(&rhs->word_4077A));
    ptree->appendTree(constructTreeItem(&rhs->addr_TerrainTypes, "addr_TerrainTypes"), "");
    TreeItemBase* ptreeaddr_Unrest_Table = ptree;
    if (gMAX_RACES > 3)
    {
        ptreeaddr_Unrest_Table = new TreeItemBase("addr_Unrest_Table");
        ptree->appendTree(ptreeaddr_Unrest_Table, "");
    }
    for (int i = 0; i < gMAX_RACES; ++i)
    {
          std::ostringstream oss;
          oss << "addr_Unrest_Table[" << i << "]";
          ptreeaddr_Unrest_Table->appendTree(constructTreeItem(&rhs->addr_Unrest_Table[i], oss.str().c_str()), "");
    }
    ptree->appendChild("word_407B8", new TreeItem<uint16_t>(&rhs->word_407B8));
    ptree->appendChild("word_407BA", new TreeItem<uint16_t>(&rhs->word_407BA));
    ptree->appendChild("word_407BC", new TreeItem<uint16_t>(&rhs->word_407BC));
    ptree->appendChild("word_407BE", new TreeItem<uint16_t>(&rhs->word_407BE));
    ptree->appendChild("word_407C0", new TreeItem<uint16_t>(&rhs->word_407C0));
    TreeItemBase* ptreew_Vizier_allowed_GUESS = ptree;
    if (8 > 3)
    {
        ptreew_Vizier_allowed_GUESS = new TreeItemBase("w_Vizier_allowed_GUESS");
        ptree->appendTree(ptreew_Vizier_allowed_GUESS, "");
    }
    for (int i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "w_Vizier_allowed_GUESS[" << i << "]";
          ptreew_Vizier_allowed_GUESS->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->w_Vizier_allowed_GUESS[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->dword_407CA, "dword_407CA"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_407CE, "dword_407CE"), "");
    ptree->appendChild("word_407D2", new TreeItem<uint16_t>(&rhs->word_407D2));
    ptree->appendChild("word_407D4", new TreeItem<uint16_t>(&rhs->word_407D4));
    ptree->appendChild("word_407D6", new TreeItem<uint16_t>(&rhs->word_407D6));
    ptree->appendChild("word_407D8", new TreeItem<uint16_t>(&rhs->word_407D8));
    ptree->appendChild("word_407DA", new TreeItem<uint16_t>(&rhs->word_407DA));
    ptree->appendChild("word_407DC", new TreeItem<uint16_t>(&rhs->word_407DC));
    ptree->appendChild("word_407DE", new TreeItem<uint16_t>(&rhs->word_407DE));
    ptree->appendChild("word_407E0", new TreeItem<uint16_t>(&rhs->word_407E0));
    ptree->appendChild("word_407E2", new TreeItem<uint16_t>(&rhs->word_407E2));
    ptree->appendChild("word_407E4", new TreeItem<uint16_t>(&rhs->word_407E4));
    ptree->appendChild("word_407E6", new TreeItem<uint16_t>(&rhs->word_407E6));
    ptree->appendChild("word_407E8", new TreeItem<uint16_t>(&rhs->word_407E8));
    ptree->appendChild("w_AI_stack_nr", new TreeItem<uint16_t>(&rhs->w_AI_stack_nr));
    TreeItemBase* ptreeunk_407EC = ptree;
    if (320 > 3)
    {
        ptreeunk_407EC = new TreeItemBase("unk_407EC");
        ptree->appendTree(ptreeunk_407EC, "");
    }
    for (int i = 0; i < 320; ++i)
    {
          std::ostringstream oss;
          oss << "unk_407EC[" << i << "]";
          ptreeunk_407EC->appendChild(oss.str().c_str(), new TreeItem<uint8_t>(&rhs->unk_407EC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->dw_Nr_in_stack, "dw_Nr_in_stack"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_stack_place, "dw_stack_place"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_pla_stacks_loc, "dw_pla_stacks_loc"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_Y_stacks_loc, "dw_Y_stacks_loc"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_X_stacks_loc, "dw_X_stacks_loc"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_bx_6160, "dw_bx_6160"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_bx_615C, "dw_bx_615C"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_bx_6176, "dw_bx_6176"), "");
    ptree->appendTree(constructTreeItem(&rhs->dw_bx_6154, "dw_bx_6154"), "");
    ptree->appendChild("word_40950", new TreeItem<uint16_t>(&rhs->word_40950));
    ptree->appendChild("word_40952", new TreeItem<uint16_t>(&rhs->word_40952));
    ptree->appendChild("word_40954", new TreeItem<uint16_t>(&rhs->word_40954));
    ptree->appendChild("word_40956", new TreeItem<uint16_t>(&rhs->word_40956));
    ptree->appendChild("word_40958", new TreeItem<uint16_t>(&rhs->word_40958));
    ptree->appendChild("word_4095A", new TreeItem<uint16_t>(&rhs->word_4095A));
    ptree->appendChild("word_4095C", new TreeItem<uint16_t>(&rhs->word_4095C));
    ptree->appendChild("word_4095E", new TreeItem<uint16_t>(&rhs->word_4095E));
    ptree->appendChild("word_40960", new TreeItem<uint16_t>(&rhs->word_40960));
    ptree->appendTree(constructTreeItem(&rhs->addr_Units, "addr_Units"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_40966, "dword_40966"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(WizardsExe_Save_Name* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new TreeItem<char[20]>(rhs->m_Name));
    return ptree;
}

TreeItemBase* constructTreeItem(unionAbility_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionAttack_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionAttribute_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionBuilding_Status* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreea = ptree;
    if (eBuilding_MAX > 3)
    {
        ptreea = new TreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (int i = 0; i < eBuilding_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new TreeItem<eBuildingStatus>(&rhs->a[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(unionHero_Abilities* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionImmunity_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionItem_Powers* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionList_Hero_stats* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    TreeItemBase* ptreea = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreea = new TreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (int i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendTree(constructTreeItem(&rhs->a[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    return ptree;
}

TreeItemBase* constructTreeItem(unionMovement_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionSkills* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    TreeItemBase* ptreea = ptree;
    if (eSkill_MAX > 3)
    {
        ptreea = new TreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (int i = 0; i < eSkill_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new TreeItem<eYesNo8>(&rhs->a[i]));
    }
    return ptree;
}

TreeItemBase* constructTreeItem(unionTower_Node_Lair_Flags* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionUnit_Enchantment* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

TreeItemBase* constructTreeItem(unionUnit_Weapon_Mutation* rhs, const QString& context)
{
    TreeItemBase* ptree = new TreeItemBase(context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new TreeItem<uint8_t>(&rhs->bits));
    return ptree;
}


} // namespace
