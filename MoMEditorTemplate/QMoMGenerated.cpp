// File: QMoMGenerated.cpp
// Generated from: MoMTemplate.h

#include <ctype.h>
#include <iomanip>
#include <sstream>

#include <MoMGenerated.h>

#include "QMoMGenerated.h"

namespace MoM {

QMoMTreeItemBase* constructTreeItem(Ability_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Ability_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Ability_Flags maskSummoned_Unit;
    memset(&maskSummoned_Unit, '\0', sizeof(maskSummoned_Unit));
    maskSummoned_Unit.Summoned_Unit = 1;
    if (1 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummoned_Unit));
    else if (2 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummoned_Unit));
    else
        ptree->appendChild("Summoned_Unit", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummoned_Unit));
    Ability_Flags maskLarge_Shield;
    memset(&maskLarge_Shield, '\0', sizeof(maskLarge_Shield));
    maskLarge_Shield.Large_Shield = 1;
    if (1 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLarge_Shield));
    else if (2 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLarge_Shield));
    else
        ptree->appendChild("Large_Shield", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLarge_Shield));
    Ability_Flags maskPlane_Shift;
    memset(&maskPlane_Shift, '\0', sizeof(maskPlane_Shift));
    maskPlane_Shift.Plane_Shift = 1;
    if (1 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlane_Shift));
    else if (2 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlane_Shift));
    else
        ptree->appendChild("Plane_Shift", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlane_Shift));
    Ability_Flags maskWall_Crusher;
    memset(&maskWall_Crusher, '\0', sizeof(maskWall_Crusher));
    maskWall_Crusher.Wall_Crusher = 1;
    if (1 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWall_Crusher));
    else if (2 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWall_Crusher));
    else
        ptree->appendChild("Wall_Crusher", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWall_Crusher));
    Ability_Flags maskHealer;
    memset(&maskHealer, '\0', sizeof(maskHealer));
    maskHealer.Healer = 1;
    if (1 == sizeof(maskHealer))
        ptree->appendChild("Healer", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealer));
    else if (2 == sizeof(maskHealer))
        ptree->appendChild("Healer", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealer));
    else
        ptree->appendChild("Healer", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealer));
    Ability_Flags maskCreate_Outpost;
    memset(&maskCreate_Outpost, '\0', sizeof(maskCreate_Outpost));
    maskCreate_Outpost.Create_Outpost = 1;
    if (1 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Outpost));
    else if (2 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Outpost));
    else
        ptree->appendChild("Create_Outpost", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Outpost));
    Ability_Flags maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Ability_Flags maskCreate_Undead;
    memset(&maskCreate_Undead, '\0', sizeof(maskCreate_Undead));
    maskCreate_Undead.Create_Undead = 1;
    if (1 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Undead));
    else if (2 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Undead));
    else
        ptree->appendChild("Create_Undead", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Undead));
    Ability_Flags maskLong_Range;
    memset(&maskLong_Range, '\0', sizeof(maskLong_Range));
    maskLong_Range.Long_Range = 1;
    if (1 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLong_Range));
    else if (2 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLong_Range));
    else
        ptree->appendChild("Long_Range", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLong_Range));
    Ability_Flags maskLand_Corruption;
    memset(&maskLand_Corruption, '\0', sizeof(maskLand_Corruption));
    maskLand_Corruption.Land_Corruption = 1;
    if (1 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLand_Corruption));
    else if (2 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLand_Corruption));
    else
        ptree->appendChild("Land_Corruption", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLand_Corruption));
    Ability_Flags maskMeld_With_Node;
    memset(&maskMeld_With_Node, '\0', sizeof(maskMeld_With_Node));
    maskMeld_With_Node.Meld_With_Node = 1;
    if (1 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMeld_With_Node));
    else if (2 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMeld_With_Node));
    else
        ptree->appendChild("Meld_With_Node", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMeld_With_Node));
    Ability_Flags maskNon_Corporeal;
    memset(&maskNon_Corporeal, '\0', sizeof(maskNon_Corporeal));
    maskNon_Corporeal.Non_Corporeal = 1;
    if (1 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNon_Corporeal));
    else if (2 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNon_Corporeal));
    else
        ptree->appendChild("Non_Corporeal", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNon_Corporeal));
    Ability_Flags maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 1;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Ability_Flags maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Ability_Flags maskPurify;
    memset(&maskPurify, '\0', sizeof(maskPurify));
    maskPurify.Purify = 1;
    if (1 == sizeof(maskPurify))
        ptree->appendChild("Purify", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPurify));
    else if (2 == sizeof(maskPurify))
        ptree->appendChild("Purify", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPurify));
    else
        ptree->appendChild("Purify", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPurify));
    Ability_Flags maskNegate_First_Strike;
    memset(&maskNegate_First_Strike, '\0', sizeof(maskNegate_First_Strike));
    maskNegate_First_Strike.Negate_First_Strike = 1;
    if (1 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNegate_First_Strike));
    else if (2 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNegate_First_Strike));
    else
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNegate_First_Strike));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Attack_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Attack_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Attack_Flags maskArmor_Piercing;
    memset(&maskArmor_Piercing, '\0', sizeof(maskArmor_Piercing));
    maskArmor_Piercing.Armor_Piercing = 1;
    if (1 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmor_Piercing));
    else if (2 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmor_Piercing));
    else
        ptree->appendChild("Armor_Piercing", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmor_Piercing));
    Attack_Flags maskFirst_Strike;
    memset(&maskFirst_Strike, '\0', sizeof(maskFirst_Strike));
    maskFirst_Strike.First_Strike = 1;
    if (1 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFirst_Strike));
    else if (2 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFirst_Strike));
    else
        ptree->appendChild("First_Strike", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFirst_Strike));
    Attack_Flags maskPoison_attack;
    memset(&maskPoison_attack, '\0', sizeof(maskPoison_attack));
    maskPoison_attack.Poison_attack = 1;
    if (1 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_attack));
    else if (2 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_attack));
    else
        ptree->appendChild("Poison_attack", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_attack));
    Attack_Flags maskLife_Stealing;
    memset(&maskLife_Stealing, '\0', sizeof(maskLife_Stealing));
    maskLife_Stealing.Life_Stealing = 1;
    if (1 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLife_Stealing));
    else if (2 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLife_Stealing));
    else
        ptree->appendChild("Life_Stealing", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLife_Stealing));
    Attack_Flags maskAutomatic_Damage;
    memset(&maskAutomatic_Damage, '\0', sizeof(maskAutomatic_Damage));
    maskAutomatic_Damage.Automatic_Damage = 1;
    if (1 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAutomatic_Damage));
    else if (2 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAutomatic_Damage));
    else
        ptree->appendChild("Automatic_Damage", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAutomatic_Damage));
    Attack_Flags maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 1;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Attack_Flags maskIllusionary_attack;
    memset(&maskIllusionary_attack, '\0', sizeof(maskIllusionary_attack));
    maskIllusionary_attack.Illusionary_attack = 1;
    if (1 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusionary_attack));
    else if (2 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusionary_attack));
    else
        ptree->appendChild("Illusionary_attack", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusionary_attack));
    Attack_Flags maskStoning_Touch;
    memset(&maskStoning_Touch, '\0', sizeof(maskStoning_Touch));
    maskStoning_Touch.Stoning_Touch = 1;
    if (1 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Touch));
    else if (2 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Touch));
    else
        ptree->appendChild("Stoning_Touch", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Touch));
    Attack_Flags maskNo_effect01;
    memset(&maskNo_effect01, '\0', sizeof(maskNo_effect01));
    maskNo_effect01.No_effect01 = 1;
    if (1 == sizeof(maskNo_effect01))
        ptree->appendChild("No_effect01", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect01));
    else if (2 == sizeof(maskNo_effect01))
        ptree->appendChild("No_effect01", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect01));
    else
        ptree->appendChild("No_effect01", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect01));
    Attack_Flags maskDeath_Touch;
    memset(&maskDeath_Touch, '\0', sizeof(maskDeath_Touch));
    maskDeath_Touch.Death_Touch = 1;
    if (1 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Touch));
    else if (2 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Touch));
    else
        ptree->appendChild("Death_Touch", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Touch));
    Attack_Flags maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 1;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Attack_Flags maskDispel_Evil;
    memset(&maskDispel_Evil, '\0', sizeof(maskDispel_Evil));
    maskDispel_Evil.Dispel_Evil = 1;
    if (1 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDispel_Evil));
    else if (2 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDispel_Evil));
    else
        ptree->appendChild("Dispel_Evil", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDispel_Evil));
    Attack_Flags maskBall_COMBAT;
    memset(&maskBall_COMBAT, '\0', sizeof(maskBall_COMBAT));
    maskBall_COMBAT.Ball_COMBAT = 1;
    if (1 == sizeof(maskBall_COMBAT))
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBall_COMBAT));
    else if (2 == sizeof(maskBall_COMBAT))
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBall_COMBAT));
    else
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBall_COMBAT));
    Attack_Flags maskNo_effect20_COMBAT;
    memset(&maskNo_effect20_COMBAT, '\0', sizeof(maskNo_effect20_COMBAT));
    maskNo_effect20_COMBAT.No_effect20_COMBAT = 1;
    if (1 == sizeof(maskNo_effect20_COMBAT))
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect20_COMBAT));
    else if (2 == sizeof(maskNo_effect20_COMBAT))
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect20_COMBAT));
    else
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect20_COMBAT));
    Attack_Flags maskEldritch_Weapon_COMBAT;
    memset(&maskEldritch_Weapon_COMBAT, '\0', sizeof(maskEldritch_Weapon_COMBAT));
    maskEldritch_Weapon_COMBAT.Eldritch_Weapon_COMBAT = 1;
    if (1 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon_COMBAT));
    else if (2 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon_COMBAT));
    else
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon_COMBAT));
    Attack_Flags maskWarp_Lightning_COMBAT;
    memset(&maskWarp_Lightning_COMBAT, '\0', sizeof(maskWarp_Lightning_COMBAT));
    maskWarp_Lightning_COMBAT.Warp_Lightning_COMBAT = 1;
    if (1 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Lightning_COMBAT));
    else if (2 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Lightning_COMBAT));
    else
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Lightning_COMBAT));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Attribute_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Attribute_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Attribute_Flags maskWeapon_Immunity;
    memset(&maskWeapon_Immunity, '\0', sizeof(maskWeapon_Immunity));
    maskWeapon_Immunity.Weapon_Immunity = 1;
    if (1 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Immunity));
    else if (2 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Immunity));
    else
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Immunity));
    Attribute_Flags maskFlyer;
    memset(&maskFlyer, '\0', sizeof(maskFlyer));
    maskFlyer.Flyer = 1;
    if (1 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlyer));
    else if (2 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlyer));
    else
        ptree->appendChild("Flyer", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlyer));
    Attribute_Flags maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 1;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Attribute_Flags maskSummon_Demons_1;
    memset(&maskSummon_Demons_1, '\0', sizeof(maskSummon_Demons_1));
    maskSummon_Demons_1.Summon_Demons_1 = 1;
    if (1 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_1));
    else if (2 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_1));
    else
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_1));
    Attribute_Flags maskSummon_Demons_2;
    memset(&maskSummon_Demons_2, '\0', sizeof(maskSummon_Demons_2));
    maskSummon_Demons_2.Summon_Demons_2 = 1;
    if (1 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_2));
    else if (2 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_2));
    else
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_2));
    Attribute_Flags maskCaster_20_MP;
    memset(&maskCaster_20_MP, '\0', sizeof(maskCaster_20_MP));
    maskCaster_20_MP.Caster_20_MP = 1;
    if (1 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_20_MP));
    else if (2 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_20_MP));
    else
        ptree->appendChild("Caster_20_MP", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_20_MP));
    Attribute_Flags maskCaster_40_MP;
    memset(&maskCaster_40_MP, '\0', sizeof(maskCaster_40_MP));
    maskCaster_40_MP.Caster_40_MP = 1;
    if (1 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_40_MP));
    else if (2 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_40_MP));
    else
        ptree->appendChild("Caster_40_MP", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_40_MP));
    Attribute_Flags maskStandard;
    memset(&maskStandard, '\0', sizeof(maskStandard));
    maskStandard.Standard = 1;
    if (1 == sizeof(maskStandard))
        ptree->appendChild("Standard", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStandard));
    else if (2 == sizeof(maskStandard))
        ptree->appendChild("Standard", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStandard));
    else
        ptree->appendChild("Standard", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStandard));
    Attribute_Flags maskHealing_Spell;
    memset(&maskHealing_Spell, '\0', sizeof(maskHealing_Spell));
    maskHealing_Spell.Healing_Spell = 1;
    if (1 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealing_Spell));
    else if (2 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealing_Spell));
    else
        ptree->appendChild("Healing_Spell", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealing_Spell));
    Attribute_Flags maskFire_Ball_Spell;
    memset(&maskFire_Ball_Spell, '\0', sizeof(maskFire_Ball_Spell));
    maskFire_Ball_Spell.Fire_Ball_Spell = 1;
    if (1 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Ball_Spell));
    else if (2 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Ball_Spell));
    else
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Ball_Spell));
    Attribute_Flags maskDoombolt_Spell;
    memset(&maskDoombolt_Spell, '\0', sizeof(maskDoombolt_Spell));
    maskDoombolt_Spell.Doombolt_Spell = 1;
    if (1 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoombolt_Spell));
    else if (2 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoombolt_Spell));
    else
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoombolt_Spell));
    Attribute_Flags maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 1;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Attribute_Flags maskWeb_Spell;
    memset(&maskWeb_Spell, '\0', sizeof(maskWeb_Spell));
    maskWeb_Spell.Web_Spell = 1;
    if (1 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb_Spell));
    else if (2 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb_Spell));
    else
        ptree->appendChild("Web_Spell", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb_Spell));
    Attribute_Flags maskCause_Fear_Spell;
    memset(&maskCause_Fear_Spell, '\0', sizeof(maskCause_Fear_Spell));
    maskCause_Fear_Spell.Cause_Fear_Spell = 1;
    if (1 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCause_Fear_Spell));
    else if (2 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCause_Fear_Spell));
    else
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCause_Fear_Spell));
    Attribute_Flags maskResistance_to_All;
    memset(&maskResistance_to_All, '\0', sizeof(maskResistance_to_All));
    maskResistance_to_All.Resistance_to_All = 1;
    if (1 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResistance_to_All));
    else if (2 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResistance_to_All));
    else
        ptree->appendChild("Resistance_to_All", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResistance_to_All));
    Attribute_Flags maskHoly_Bonus;
    memset(&maskHoly_Bonus, '\0', sizeof(maskHoly_Bonus));
    maskHoly_Bonus.Holy_Bonus = 1;
    if (1 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Bonus));
    else if (2 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Bonus));
    else
        ptree->appendChild("Holy_Bonus", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Bonus));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Available_spell_page* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Available_spell_page>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Page_Name", new QMoMTreeItem<char[0x10]>(rhs->m_Page_Name));
    QMoMTreeItemBase* ptreem_Spells_on_page = ptree;
    if (6 > 3)
    {
        ptreem_Spells_on_page = new QMoMTreeItemBase("m_Spells_on_page");
        ptree->appendTree(ptreem_Spells_on_page, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_on_page[" << i << "]";
          ptreem_Spells_on_page->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell16>(&rhs->m_Spells_on_page[i]));
    }
    ptree->appendChild("m_Nr_spells_on_page", new QMoMTreeItem<uint8_t>(&rhs->m_Nr_spells_on_page));
    ptree->appendChild("m_Zero", new QMoMTreeItem<uint8_t>(&rhs->m_Zero));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Battle_Figure* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Battle_Figure>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_xpel", new QMoMTreeItem<uint16_t>(&rhs->m_xpel));
    ptree->appendChild("m_ypel", new QMoMTreeItem<uint16_t>(&rhs->m_ypel));
    ptree->appendChild("m_Pic", new QMoMTreeItem<uint16_t>(&rhs->m_Pic));
    ptree->appendChild("m_Unk_6_sound", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_6_sound));
    ptree->appendChild("m_Unk_8", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_8));
    ptree->appendChild("m_Unk_A", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_A));
    ptree->appendChild("m_Unk_C", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_C));
    ptree->appendChild("m_Owner", new QMoMTreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Unk_10", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_10));
    ptree->appendChild("m_Color_enchantment", new QMoMTreeItem<uint16_t>(&rhs->m_Color_enchantment));
    ptree->appendChild("m_Unk_14_sound", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_14_sound));
    ptree->appendChild("m_Unk_16", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_16));
    ptree->appendChild("m_Unk_18_battleunit_field_58", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_18_battleunit_field_58));
    ptree->appendChild("m_ZDepth", new QMoMTreeItem<uint32_t>(&rhs->m_ZDepth));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Battle_Unit* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Battle_Unit>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Melee", new QMoMTreeItem<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new QMoMTreeItem<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new QMoMTreeItem<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new QMoMTreeItem<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new QMoMTreeItem<uint8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new QMoMTreeItem<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new QMoMTreeItem<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new QMoMTreeItem<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new QMoMTreeItem<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new QMoMTreeItem<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new QMoMTreeItem<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Buildings_Required1_UNK", new QMoMTreeItem<uint8_t>(&rhs->m_Buildings_Required1_UNK));
    ptree->appendChild("m_Current_Figures", new QMoMTreeItem<uint8_t>(&rhs->m_Current_Figures));
    ptree->appendChild("m_BattleUnitNr", new QMoMTreeItem<uint8_t>(&rhs->m_BattleUnitNr));
    ptree->appendChild("m_UNK0F", new QMoMTreeItem<uint8_t>(&rhs->m_UNK0F));
    ptree->appendChild("m_Hitpoints_per_Figure", new QMoMTreeItem<uint8_t>(&rhs->m_Hitpoints_per_Figure));
    ptree->appendChild("m_Scouting", new QMoMTreeItem<uint8_t>(&rhs->m_Scouting));
    ptree->appendChild("m_Transport_Capacity_GUESS", new QMoMTreeItem<uint8_t>(&rhs->m_Transport_Capacity_GUESS));
    ptree->appendChild("m_Total_Figures", new QMoMTreeItem<uint8_t>(&rhs->m_Total_Figures));
    ptree->appendChild("m_Construction", new QMoMTreeItem<uint8_t>(&rhs->m_Construction));
    ptree->appendChild("m_Gaze_Modifier", new QMoMTreeItem<uint8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero01", new QMoMTreeItem<uint8_t>(&rhs->m_Zero01));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero02", new QMoMTreeItem<uint8_t>(&rhs->m_Zero02));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_Zero03", new QMoMTreeItem<uint16_t>(&rhs->m_Zero03));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags_Combat_Enchantment, "m_Flags_Combat_Enchantment"), "");
    ptree->appendChild("m_Extra_ToHit_Melee", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_ToHit_Melee));
    ptree->appendChild("m_Extra_ToHit_Ranged", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_ToHit_Ranged));
    ptree->appendChild("m_Extra_ToDefend", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_ToDefend));
    ptree->appendChild("m_Weapon_Type_Plus_1", new QMoMTreeItem<uint8_t>(&rhs->m_Weapon_Type_Plus_1));
    ptree->appendTree(constructTreeItem(&rhs->m_Cur_Attack_Flags, "m_Cur_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Item_Attack_Flags, "m_Item_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Flags2_UnitEnchantment, "m_Flags2_UnitEnchantment"), "");
    ptree->appendChild("m_unitNr", new QMoMTreeItem<int16_t>(&rhs->m_unitNr));
    ptree->appendChild("m_additional_life_per_figure", new QMoMTreeItem<uint8_t>(&rhs->m_additional_life_per_figure));
    ptree->appendChild("m_web_", new QMoMTreeItem<uint8_t>(&rhs->m_web_));
    ptree->appendChild("m_Active", new QMoMTreeItem<eBattleUnitActive>(&rhs->m_Active));
    ptree->appendChild("m_Owner", new QMoMTreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_cur_total_damage_GUESS", new QMoMTreeItem<uint8_t>(&rhs->m_cur_total_damage_GUESS));
    ptree->appendChild("m_lifesteal_damage", new QMoMTreeItem<int8_t>(&rhs->m_lifesteal_damage));
    ptree->appendChild("m_instant_damage_like_stoning", new QMoMTreeItem<int8_t>(&rhs->m_instant_damage_like_stoning));
    ptree->appendChild("m_cur_figure_damage_GUESS", new QMoMTreeItem<int8_t>(&rhs->m_cur_figure_damage_GUESS));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags1_UnitEnchantment, "m_Flags1_UnitEnchantment"), "");
    ptree->appendChild("m_Suppression", new QMoMTreeItem<int8_t>(&rhs->m_Suppression));
    ptree->appendChild("m_Mana_points", new QMoMTreeItem<int8_t>(&rhs->m_Mana_points));
    ptree->appendChild("m_Current_mana_", new QMoMTreeItem<int8_t>(&rhs->m_Current_mana_));
    ptree->appendChild("m_Item_nr_charges_", new QMoMTreeItem<int8_t>(&rhs->m_Item_nr_charges_));
    ptree->appendChild("m_Poison_strength_", new QMoMTreeItem<int8_t>(&rhs->m_Poison_strength_));
    ptree->appendChild("m_Target_BattleUnitID", new QMoMTreeItem<int8_t>(&rhs->m_Target_BattleUnitID));
    ptree->appendChild("m_xPos", new QMoMTreeItem<int16_t>(&rhs->m_xPos));
    ptree->appendChild("m_yPos", new QMoMTreeItem<int16_t>(&rhs->m_yPos));
    ptree->appendChild("m_xPosHeaded", new QMoMTreeItem<int16_t>(&rhs->m_xPosHeaded));
    ptree->appendChild("m_yPosHeaded", new QMoMTreeItem<int16_t>(&rhs->m_yPosHeaded));
    ptree->appendChild("m_UNK4C_display_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_UNK4C_display_GUESS));
    ptree->appendChild("m_UNK4E", new QMoMTreeItem<uint16_t>(&rhs->m_UNK4E));
    ptree->appendChild("m_UNK50", new QMoMTreeItem<uint16_t>(&rhs->m_UNK50));
    ptree->appendChild("m_UNK52_sound_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_UNK52_sound_GUESS));
    ptree->appendChild("m_Tactic", new QMoMTreeItem<eBattleUnitTactic>(&rhs->m_Tactic));
    ptree->appendChild("m_Confused_State", new QMoMTreeItem<int8_t>(&rhs->m_Confused_State));
    ptree->appendChild("m_UNK57", new QMoMTreeItem<uint8_t>(&rhs->m_UNK57));
    QMoMTreeItemBase* ptreem_UNK58 = ptree;
    if (6 > 3)
    {
        ptreem_UNK58 = new QMoMTreeItemBase("m_UNK58");
        ptree->appendTree(ptreem_UNK58, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK58[" << i << "]";
          ptreem_UNK58->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_UNK58[i]));
    }
    ptree->appendChild("m_Extra_Melee", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_Melee));
    ptree->appendChild("m_Extra_Ranged", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_Ranged));
    ptree->appendChild("m_Extra_Defense", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_Defense));
    ptree->appendChild("m_Extra_Resistance", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_Resistance));
    ptree->appendChild("m_Extra_Hitpoints", new QMoMTreeItem<uint8_t>(&rhs->m_Extra_Hitpoints));
    ptree->appendChild("m_Lost_Melee", new QMoMTreeItem<uint8_t>(&rhs->m_Lost_Melee));
    ptree->appendChild("m_Lost_Ranged", new QMoMTreeItem<uint8_t>(&rhs->m_Lost_Ranged));
    ptree->appendChild("m_Lost_Defense", new QMoMTreeItem<uint8_t>(&rhs->m_Lost_Defense));
    ptree->appendChild("m_Lost_Resistance", new QMoMTreeItem<uint8_t>(&rhs->m_Lost_Resistance));
    ptree->appendChild("m_UNUSED6D", new QMoMTreeItem<uint8_t>(&rhs->m_UNUSED6D));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Battlefield* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Battlefield>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Terrain = ptree;
    if (462 > 3)
    {
        ptreem_Terrain = new QMoMTreeItemBase("m_Terrain");
        ptree->appendTree(ptreem_Terrain, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Terrain[" << i << "]";
          ptreem_Terrain->appendChild(oss.str().c_str(), new QMoMTreeItem<eTerrainBattle>(&rhs->m_Terrain[i]));
    }
    QMoMTreeItemBase* ptreem_TerrainGroupType = ptree;
    if (462 > 3)
    {
        ptreem_TerrainGroupType = new QMoMTreeItemBase("m_TerrainGroupType");
        ptree->appendTree(ptreem_TerrainGroupType, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_TerrainGroupType[" << i << "]";
          ptreem_TerrainGroupType->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_TerrainGroupType[i]));
    }
    QMoMTreeItemBase* ptreem_Road = ptree;
    if (462 > 3)
    {
        ptreem_Road = new QMoMTreeItemBase("m_Road");
        ptree->appendTree(ptreem_Road, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Road[" << i << "]";
          ptreem_Road->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Road[i]));
    }
    QMoMTreeItemBase* ptreem_Movement_walking = ptree;
    if (462 > 3)
    {
        ptreem_Movement_walking = new QMoMTreeItemBase("m_Movement_walking");
        ptree->appendTree(ptreem_Movement_walking, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_walking[" << i << "]";
          ptreem_Movement_walking->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Movement_walking[i]));
    }
    QMoMTreeItemBase* ptreem_Movement_merging_teleporting_fly = ptree;
    if (462 > 3)
    {
        ptreem_Movement_merging_teleporting_fly = new QMoMTreeItemBase("m_Movement_merging_teleporting_fly");
        ptree->appendTree(ptreem_Movement_merging_teleporting_fly, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_merging_teleporting_fly[" << i << "]";
          ptreem_Movement_merging_teleporting_fly->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Movement_merging_teleporting_fly[i]));
    }
    QMoMTreeItemBase* ptreem_Movement_similar_to_walking = ptree;
    if (462 > 3)
    {
        ptreem_Movement_similar_to_walking = new QMoMTreeItemBase("m_Movement_similar_to_walking");
        ptree->appendTree(ptreem_Movement_similar_to_walking, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_similar_to_walking[" << i << "]";
          ptreem_Movement_similar_to_walking->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Movement_similar_to_walking[i]));
    }
    QMoMTreeItemBase* ptreem_Movement_sailing = ptree;
    if (462 > 3)
    {
        ptreem_Movement_sailing = new QMoMTreeItemBase("m_Movement_sailing");
        ptree->appendTree(ptreem_Movement_sailing, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_sailing[" << i << "]";
          ptreem_Movement_sailing->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Movement_sailing[i]));
    }
    ptree->appendChild("m_Nr_tree_pics", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_tree_pics));
    QMoMTreeItemBase* ptreem_xpel_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_xpel_tree_pics = new QMoMTreeItemBase("m_xpel_tree_pics");
        ptree->appendTree(ptreem_xpel_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_xpel_tree_pics[" << i << "]";
          ptreem_xpel_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_xpel_tree_pics[i]));
    }
    QMoMTreeItemBase* ptreem_ypel_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_ypel_tree_pics = new QMoMTreeItemBase("m_ypel_tree_pics");
        ptree->appendTree(ptreem_ypel_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_ypel_tree_pics[" << i << "]";
          ptreem_ypel_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_ypel_tree_pics[i]));
    }
    QMoMTreeItemBase* ptreem_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_tree_pics = new QMoMTreeItemBase("m_tree_pics");
        ptree->appendTree(ptreem_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_tree_pics[" << i << "]";
          ptreem_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_tree_pics[i]));
    }
    ptree->appendChild("m_Nr_rock_pics", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_rock_pics));
    QMoMTreeItemBase* ptreem_xpel_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_xpel_rock_pics = new QMoMTreeItemBase("m_xpel_rock_pics");
        ptree->appendTree(ptreem_xpel_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_xpel_rock_pics[" << i << "]";
          ptreem_xpel_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_xpel_rock_pics[i]));
    }
    QMoMTreeItemBase* ptreem_ypel_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_ypel_rock_pics = new QMoMTreeItemBase("m_ypel_rock_pics");
        ptree->appendTree(ptreem_ypel_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_ypel_rock_pics[" << i << "]";
          ptreem_ypel_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_ypel_rock_pics[i]));
    }
    QMoMTreeItemBase* ptreem_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_rock_pics = new QMoMTreeItemBase("m_rock_pics");
        ptree->appendTree(ptreem_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_rock_pics[" << i << "]";
          ptreem_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_rock_pics[i]));
    }
    QMoMTreeItemBase* ptreefield_11F8 = ptree;
    if (462 > 3)
    {
        ptreefield_11F8 = new QMoMTreeItemBase("field_11F8");
        ptree->appendTree(ptreefield_11F8, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "field_11F8[" << i << "]";
          ptreefield_11F8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->field_11F8[i]));
    }
    ptree->appendChild("m_Central_structure", new QMoMTreeItem<eCentralStructure>(&rhs->m_Central_structure));
    ptree->appendChild("field_14F4", new QMoMTreeItem<uint16_t>(&rhs->field_14F4));
    ptree->appendChild("field_14F6", new QMoMTreeItem<uint16_t>(&rhs->field_14F6));
    QMoMTreeItemBase* ptreefield_14F8 = ptree;
    if (30 > 3)
    {
        ptreefield_14F8 = new QMoMTreeItemBase("field_14F8");
        ptree->appendTree(ptreefield_14F8, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_14F8[" << i << "]";
          ptreefield_14F8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->field_14F8[i]));
    }
    ptree->appendChild("field_1516", new QMoMTreeItem<uint16_t>(&rhs->field_1516));
    QMoMTreeItemBase* ptreefield_1518 = ptree;
    if (30 > 3)
    {
        ptreefield_1518 = new QMoMTreeItemBase("field_1518");
        ptree->appendTree(ptreefield_1518, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_1518[" << i << "]";
          ptreefield_1518->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->field_1518[i]));
    }
    ptree->appendChild("field_1536", new QMoMTreeItem<uint16_t>(&rhs->field_1536));
    QMoMTreeItemBase* ptreefield_1538 = ptree;
    if (30 > 3)
    {
        ptreefield_1538 = new QMoMTreeItemBase("field_1538");
        ptree->appendTree(ptreefield_1538, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "field_1538[" << i << "]";
          ptreefield_1538->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->field_1538[i]));
    }
    ptree->appendChild("m_City_Walls", new QMoMTreeItem<eYesNo16>(&rhs->m_City_Walls));
    QMoMTreeItemBase* ptreem_Wall_present_4x4 = ptree;
    if (16 > 3)
    {
        ptreem_Wall_present_4x4 = new QMoMTreeItemBase("m_Wall_present_4x4");
        ptree->appendTree(ptreem_Wall_present_4x4, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wall_present_4x4[" << i << "]";
          ptreem_Wall_present_4x4->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Wall_present_4x4[i]));
    }
    ptree->appendChild("m_Wall_of_Fire", new QMoMTreeItem<eYesNo16>(&rhs->m_Wall_of_Fire));
    ptree->appendChild("m_Wall_of_Darkness", new QMoMTreeItem<eYesNo16>(&rhs->m_Wall_of_Darkness));
    ptree->appendChild("m_Plane", new QMoMTreeItem<int16_t>(&rhs->m_Plane));
    ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(BorlandSegmentEntry* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<BorlandSegmentEntry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("base", new QMoMTreeItem<uint16_t>(&rhs->base));
    ptree->appendChild("size", new QMoMTreeItem<uint16_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItem<uint16_t>(&rhs->type));
    ptree->appendChild("offset", new QMoMTreeItem<uint16_t>(&rhs->offset));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(BorlandStub* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<BorlandStub>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreeint_code = ptree;
    if (2 > 3)
    {
        ptreeint_code = new QMoMTreeItemBase("int_code");
        ptree->appendTree(ptreeint_code, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "int_code[" << i << "]";
          ptreeint_code->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->int_code[i]));
    }
    ptree->appendChild("memswap", new QMoMTreeItem<uint16_t>(&rhs->memswap));
    ptree->appendChild("fileoff", new QMoMTreeItem<uint32_t>(&rhs->fileoff));
    ptree->appendChild("codesize", new QMoMTreeItem<uint16_t>(&rhs->codesize));
    ptree->appendChild("relsize", new QMoMTreeItem<uint16_t>(&rhs->relsize));
    ptree->appendChild("nentries", new QMoMTreeItem<uint16_t>(&rhs->nentries));
    ptree->appendChild("prevstub", new QMoMTreeItem<uint16_t>(&rhs->prevstub));
    QMoMTreeItemBase* ptreeworkarea = ptree;
    if (0x10 > 3)
    {
        ptreeworkarea = new QMoMTreeItemBase("workarea");
        ptree->appendTree(ptreeworkarea, "");
    }
    for (unsigned i = 0; i < 0x10; ++i)
    {
          std::ostringstream oss;
          oss << "workarea[" << i << "]";
          ptreeworkarea->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->workarea[i]));
    }
    QMoMTreeItemBase* ptreeentries = ptree;
    if (1 > 3)
    {
        ptreeentries = new QMoMTreeItemBase("entries");
        ptree->appendTree(ptreeentries, "");
    }
    for (unsigned i = 0; i < 1; ++i)
    {
          std::ostringstream oss;
          oss << "entries[" << i << "]";
          ptreeentries->appendTree(constructTreeItem(&rhs->entries[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(BorlandStubJmpEntry* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<BorlandStubJmpEntry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("jmpfar_code", new QMoMTreeItem<uint8_t>(&rhs->jmpfar_code));
    ptree->appendChild("offset", new QMoMTreeItem<uint16_t>(&rhs->offset));
    ptree->appendChild("base_addr", new QMoMTreeItem<uint16_t>(&rhs->base_addr));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Building_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Building_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_BuildingName", new QMoMTreeItem<char[20]>(rhs->m_BuildingName));
    ptree->appendChild("m_Prerequisite1", new QMoMTreeItem<eBuilding>(&rhs->m_Prerequisite1));
    ptree->appendChild("m_Prerequisite2", new QMoMTreeItem<eBuilding>(&rhs->m_Prerequisite2));
    ptree->appendChild("m_Replaces_building", new QMoMTreeItem<eBuilding>(&rhs->m_Replaces_building));
    ptree->appendChild("m_Produces_Regulars", new QMoMTreeItem<eYesNo16>(&rhs->m_Produces_Regulars));
    ptree->appendChild("m_Produces_Veterans", new QMoMTreeItem<eYesNo16>(&rhs->m_Produces_Veterans));
    ptree->appendChild("m_Produces_Magic_Weapons", new QMoMTreeItem<eYesNo16>(&rhs->m_Produces_Magic_Weapons));
    ptree->appendChild("m_Upkeep_yield", new QMoMTreeItem<int16_t>(&rhs->m_Upkeep_yield));
    ptree->appendChild("m_Food_and_pop_related", new QMoMTreeItem<uint16_t>(&rhs->m_Food_and_pop_related));
    ptree->appendChild("m_Zero_24", new QMoMTreeItem<uint16_t>(&rhs->m_Zero_24));
    ptree->appendChild("m_Unk_26", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_26));
    ptree->appendChild("m_Temple_related", new QMoMTreeItem<uint16_t>(&rhs->m_Temple_related));
    ptree->appendChild("m_Research_related", new QMoMTreeItem<uint16_t>(&rhs->m_Research_related));
    ptree->appendChild("m_Building_cost", new QMoMTreeItem<uint16_t>(&rhs->m_Building_cost));
    ptree->appendChild("m_Zero_2E", new QMoMTreeItem<uint16_t>(&rhs->m_Zero_2E));
    ptree->appendChild("m_Animation_related", new QMoMTreeItem<uint16_t>(&rhs->m_Animation_related));
    ptree->appendChild("m_Unk_32", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_32));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Building_Status* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Building_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("No_building", new QMoMTreeItem<eBuildingStatus>(&rhs->No_building));
    ptree->appendChild("Trade_Goods", new QMoMTreeItem<eBuildingStatus>(&rhs->Trade_Goods));
    ptree->appendChild("Housing", new QMoMTreeItem<eBuildingStatus>(&rhs->Housing));
    ptree->appendChild("Barracks", new QMoMTreeItem<eBuildingStatus>(&rhs->Barracks));
    ptree->appendChild("Armory", new QMoMTreeItem<eBuildingStatus>(&rhs->Armory));
    ptree->appendChild("Fighters_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Fighters_Guild));
    ptree->appendChild("Armorers_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Armorers_Guild));
    ptree->appendChild("War_College", new QMoMTreeItem<eBuildingStatus>(&rhs->War_College));
    ptree->appendChild("Smithy", new QMoMTreeItem<eBuildingStatus>(&rhs->Smithy));
    ptree->appendChild("Stable", new QMoMTreeItem<eBuildingStatus>(&rhs->Stable));
    ptree->appendChild("Animists_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Animists_Guild));
    ptree->appendChild("Fantastic_Stable", new QMoMTreeItem<eBuildingStatus>(&rhs->Fantastic_Stable));
    ptree->appendChild("Shipwright_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Shipwright_Guild));
    ptree->appendChild("Ship_Yard", new QMoMTreeItem<eBuildingStatus>(&rhs->Ship_Yard));
    ptree->appendChild("Maritime_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Maritime_Guild));
    ptree->appendChild("Sawmill", new QMoMTreeItem<eBuildingStatus>(&rhs->Sawmill));
    ptree->appendChild("Library", new QMoMTreeItem<eBuildingStatus>(&rhs->Library));
    ptree->appendChild("Sages_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Sages_Guild));
    ptree->appendChild("Oracle", new QMoMTreeItem<eBuildingStatus>(&rhs->Oracle));
    ptree->appendChild("Alchemist_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Alchemist_Guild));
    ptree->appendChild("University", new QMoMTreeItem<eBuildingStatus>(&rhs->University));
    ptree->appendChild("Wizards_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Wizards_Guild));
    ptree->appendChild("Shrine", new QMoMTreeItem<eBuildingStatus>(&rhs->Shrine));
    ptree->appendChild("Temple", new QMoMTreeItem<eBuildingStatus>(&rhs->Temple));
    ptree->appendChild("Parthenon", new QMoMTreeItem<eBuildingStatus>(&rhs->Parthenon));
    ptree->appendChild("Cathedral", new QMoMTreeItem<eBuildingStatus>(&rhs->Cathedral));
    ptree->appendChild("Marketplace", new QMoMTreeItem<eBuildingStatus>(&rhs->Marketplace));
    ptree->appendChild("Bank", new QMoMTreeItem<eBuildingStatus>(&rhs->Bank));
    ptree->appendChild("Merchants_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Merchants_Guild));
    ptree->appendChild("Granary", new QMoMTreeItem<eBuildingStatus>(&rhs->Granary));
    ptree->appendChild("Farmers_Market", new QMoMTreeItem<eBuildingStatus>(&rhs->Farmers_Market));
    ptree->appendChild("Foresters_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Foresters_Guild));
    ptree->appendChild("Builders_Hall", new QMoMTreeItem<eBuildingStatus>(&rhs->Builders_Hall));
    ptree->appendChild("Mechanicians_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Mechanicians_Guild));
    ptree->appendChild("Miners_Guild", new QMoMTreeItem<eBuildingStatus>(&rhs->Miners_Guild));
    ptree->appendChild("City_Walls", new QMoMTreeItem<eBuildingStatus>(&rhs->City_Walls));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(City* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<City>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Name", new QMoMTreeItem<char[14]>(rhs->m_City_Name));
    ptree->appendChild("m_Race", new QMoMTreeItem<eRace>(&rhs->m_Race));
    ptree->appendChild("m_XPos", new QMoMTreeItem<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Size", new QMoMTreeItem<eCity_Size>(&rhs->m_Size));
    ptree->appendChild("m_Population", new QMoMTreeItem<uint8_t>(&rhs->m_Population));
    ptree->appendChild("m_Number_of_farmers_allocated", new QMoMTreeItem<uint8_t>(&rhs->m_Number_of_farmers_allocated));
    QMoMTreeItemBase* ptreem_UNK01a = ptree;
    if (2 > 3)
    {
        ptreem_UNK01a = new QMoMTreeItemBase("m_UNK01a");
        ptree->appendTree(ptreem_UNK01a, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01a[" << i << "]";
          ptreem_UNK01a->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK01a[i]));
    }
    ptree->appendChild("m_PopulationDekaPop", new QMoMTreeItem<uint8_t>(&rhs->m_PopulationDekaPop));
    ptree->appendChild("m_UNK01b", new QMoMTreeItem<uint8_t>(&rhs->m_UNK01b));
    ptree->appendChild("m_Player_as_bitmask_GUESS", new QMoMTreeItem<uint8_t>(&rhs->m_Player_as_bitmask_GUESS));
    ptree->appendChild("m_UNK01c", new QMoMTreeItem<uint8_t>(&rhs->m_UNK01c));
    ptree->appendChild("m_Producing", new QMoMTreeItem<eProducing>(&rhs->m_Producing));
    ptree->appendChild("m_UNK02", new QMoMTreeItem<uint8_t>(&rhs->m_UNK02));
    ptree->appendTree(constructTreeItem(&rhs->m_Building_Status, "m_Building_Status"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
    ptree->appendChild("m_Nightshade", new QMoMTreeItem<eYesNo8>(&rhs->m_Nightshade));
    ptree->appendChild("m_Hammers", new QMoMTreeItem<uint8_t>(&rhs->m_Hammers));
    ptree->appendChild("m_HammersAccumulated", new QMoMTreeItem<uint16_t>(&rhs->m_HammersAccumulated));
    ptree->appendChild("m_Coins", new QMoMTreeItem<uint8_t>(&rhs->m_Coins));
    ptree->appendChild("m_Maintenance", new QMoMTreeItem<uint8_t>(&rhs->m_Maintenance));
    ptree->appendChild("m_Mana_cr", new QMoMTreeItem<uint8_t>(&rhs->m_Mana_cr));
    ptree->appendChild("m_Research", new QMoMTreeItem<uint8_t>(&rhs->m_Research));
    ptree->appendChild("m_Food_Produced", new QMoMTreeItem<uint8_t>(&rhs->m_Food_Produced));
    ptree->appendChild("m_Road_Connection_GUESS", new QMoMTreeItem<int8_t>(&rhs->m_Road_Connection_GUESS));
    QMoMTreeItemBase* ptreem_UNK03 = ptree;
    if (12 > 3)
    {
        ptreem_UNK03 = new QMoMTreeItemBase("m_UNK03");
        ptree->appendTree(ptreem_UNK03, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03[" << i << "]";
          ptreem_UNK03->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK03[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(City_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<City_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Wall_of_Fire", new QMoMTreeItem<eOwner>(&rhs->Wall_of_Fire));
    ptree->appendChild("_Chaos_Rift_", new QMoMTreeItem<eOwner>(&rhs->_Chaos_Rift_));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItem<eOwner>(&rhs->Dark_Rituals));
    ptree->appendChild("_Evil_Presence_", new QMoMTreeItem<eOwner>(&rhs->_Evil_Presence_));
    ptree->appendChild("_Cursed_Lands_", new QMoMTreeItem<eOwner>(&rhs->_Cursed_Lands_));
    ptree->appendChild("_Pestilence_", new QMoMTreeItem<eOwner>(&rhs->_Pestilence_));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItem<eOwner>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("_Famine_", new QMoMTreeItem<eOwner>(&rhs->_Famine_));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItem<eOwner>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new QMoMTreeItem<eOwner>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new QMoMTreeItem<eOwner>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new QMoMTreeItem<eOwner>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new QMoMTreeItem<eOwner>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new QMoMTreeItem<eOwner>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new QMoMTreeItem<eOwner>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new QMoMTreeItem<eOwner>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItem<eOwner>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItem<eOwner>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new QMoMTreeItem<eOwner>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new QMoMTreeItem<eOwner>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new QMoMTreeItem<eOwner>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItem<eOwner>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new QMoMTreeItem<eOwner>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItem<eOwner>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItem<eOwner>(&rhs->Altar_of_Battle));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Combat_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Combat_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    Combat_Enchantment maskVertigo;
    memset(&maskVertigo, '\0', sizeof(maskVertigo));
    maskVertigo.Vertigo = 1;
    if (1 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVertigo));
    else if (2 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVertigo));
    else
        ptree->appendChild("Vertigo", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVertigo));
    Combat_Enchantment maskConfusion;
    memset(&maskConfusion, '\0', sizeof(maskConfusion));
    maskConfusion.Confusion = 1;
    if (1 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConfusion));
    else if (2 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConfusion));
    else
        ptree->appendChild("Confusion", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConfusion));
    Combat_Enchantment maskWhirlwind;
    memset(&maskWhirlwind, '\0', sizeof(maskWhirlwind));
    maskWhirlwind.Whirlwind = 1;
    if (1 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWhirlwind));
    else if (2 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWhirlwind));
    else
        ptree->appendChild("Whirlwind", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWhirlwind));
    Combat_Enchantment maskMind_Storm;
    memset(&maskMind_Storm, '\0', sizeof(maskMind_Storm));
    maskMind_Storm.Mind_Storm = 1;
    if (1 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Storm));
    else if (2 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Storm));
    else
        ptree->appendChild("Mind_Storm", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Storm));
    Combat_Enchantment maskShatter;
    memset(&maskShatter, '\0', sizeof(maskShatter));
    maskShatter.Shatter = 1;
    if (1 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskShatter));
    else if (2 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskShatter));
    else
        ptree->appendChild("Shatter", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskShatter));
    Combat_Enchantment maskWeakness;
    memset(&maskWeakness, '\0', sizeof(maskWeakness));
    maskWeakness.Weakness = 1;
    if (1 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeakness));
    else if (2 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeakness));
    else
        ptree->appendChild("Weakness", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeakness));
    Combat_Enchantment maskBlack_Sleep;
    memset(&maskBlack_Sleep, '\0', sizeof(maskBlack_Sleep));
    maskBlack_Sleep.Black_Sleep = 1;
    if (1 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Sleep));
    else if (2 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Sleep));
    else
        ptree->appendChild("Black_Sleep", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Sleep));
    Combat_Enchantment maskWarp_Creature_Attack;
    memset(&maskWarp_Creature_Attack, '\0', sizeof(maskWarp_Creature_Attack));
    maskWarp_Creature_Attack.Warp_Creature_Attack = 1;
    if (1 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Attack));
    else if (2 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Attack));
    else
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Attack));
    Combat_Enchantment maskWarp_Creature_Defense;
    memset(&maskWarp_Creature_Defense, '\0', sizeof(maskWarp_Creature_Defense));
    maskWarp_Creature_Defense.Warp_Creature_Defense = 1;
    if (1 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Defense));
    else if (2 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Defense));
    else
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Defense));
    Combat_Enchantment maskWarp_Creature_Resistance;
    memset(&maskWarp_Creature_Resistance, '\0', sizeof(maskWarp_Creature_Resistance));
    maskWarp_Creature_Resistance.Warp_Creature_Resistance = 1;
    if (1 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Resistance));
    else if (2 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Resistance));
    else
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Resistance));
    Combat_Enchantment maskMind_Twist;
    memset(&maskMind_Twist, '\0', sizeof(maskMind_Twist));
    maskMind_Twist.Mind_Twist = 1;
    if (1 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Twist));
    else if (2 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Twist));
    else
        ptree->appendChild("Mind_Twist", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Twist));
    Combat_Enchantment maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 1;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Combat_Enchantment maskWeb;
    memset(&maskWeb, '\0', sizeof(maskWeb));
    maskWeb.Web = 1;
    if (1 == sizeof(maskWeb))
        ptree->appendChild("Web", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb));
    else if (2 == sizeof(maskWeb))
        ptree->appendChild("Web", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb));
    else
        ptree->appendChild("Web", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb));
    Combat_Enchantment maskCreature_Binding;
    memset(&maskCreature_Binding, '\0', sizeof(maskCreature_Binding));
    maskCreature_Binding.Creature_Binding = 1;
    if (1 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreature_Binding));
    else if (2 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreature_Binding));
    else
        ptree->appendChild("Creature_Binding", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreature_Binding));
    Combat_Enchantment maskPossession;
    memset(&maskPossession, '\0', sizeof(maskPossession));
    maskPossession.Possession = 1;
    if (1 == sizeof(maskPossession))
        ptree->appendChild("Possession", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPossession));
    else if (2 == sizeof(maskPossession))
        ptree->appendChild("Possession", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPossession));
    else
        ptree->appendChild("Possession", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPossession));
    Combat_Enchantment maskNo_Effect80;
    memset(&maskNo_Effect80, '\0', sizeof(maskNo_Effect80));
    maskNo_Effect80.No_Effect80 = 1;
    if (1 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_Effect80));
    else if (2 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_Effect80));
    else
        ptree->appendChild("No_Effect80", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_Effect80));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Difficulty_Table* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Difficulty_Table>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Growth_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Growth_multiplier));
    ptree->appendChild("m_Outpost_Growth_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_Outpost_Growth_multiplier));
    ptree->appendChild("m_City_Production_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Production_multiplier));
    ptree->appendChild("m_City_Coin_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Coin_multiplier));
    ptree->appendChild("m_City_Mana_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Mana_multiplier));
    ptree->appendChild("m_City_Research_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Research_multiplier));
    ptree->appendChild("m_City_Food_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Food_multiplier));
    ptree->appendChild("m_City_Maintenance_multiplier", new QMoMTreeItem<int16_t>(&rhs->m_City_Maintenance_multiplier));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(EXE_Header* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<EXE_Header>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("signature", new QMoMTreeItem<uint16_t>(&rhs->signature));
    ptree->appendChild("bytes_in_last_block", new QMoMTreeItem<uint16_t>(&rhs->bytes_in_last_block));
    ptree->appendChild("blocks_in_file", new QMoMTreeItem<uint16_t>(&rhs->blocks_in_file));
    ptree->appendChild("nr_relocation_items", new QMoMTreeItem<uint16_t>(&rhs->nr_relocation_items));
    ptree->appendChild("load_module_offset_paragraphs", new QMoMTreeItem<uint16_t>(&rhs->load_module_offset_paragraphs));
    ptree->appendChild("min_needed_paragraphs", new QMoMTreeItem<uint16_t>(&rhs->min_needed_paragraphs));
    ptree->appendChild("max_needed_paragraphs", new QMoMTreeItem<uint16_t>(&rhs->max_needed_paragraphs));
    ptree->appendChild("ss_offset_in_load_module_paragraphs", new QMoMTreeItem<uint16_t>(&rhs->ss_offset_in_load_module_paragraphs));
    ptree->appendChild("sp_initial", new QMoMTreeItem<uint16_t>(&rhs->sp_initial));
    ptree->appendChild("checksum", new QMoMTreeItem<uint16_t>(&rhs->checksum));
    ptree->appendChild("ip_program_entry_point", new QMoMTreeItem<uint16_t>(&rhs->ip_program_entry_point));
    ptree->appendChild("cs_offset_in_load_module_paragraphs", new QMoMTreeItem<uint16_t>(&rhs->cs_offset_in_load_module_paragraphs));
    ptree->appendChild("relocation_table_offset_bytes", new QMoMTreeItem<uint16_t>(&rhs->relocation_table_offset_bytes));
    ptree->appendChild("overlay_number", new QMoMTreeItem<uint16_t>(&rhs->overlay_number));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(EXE_Reloc* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<EXE_Reloc>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("offset", new QMoMTreeItem<uint16_t>(&rhs->offset));
    ptree->appendChild("segment", new QMoMTreeItem<uint16_t>(&rhs->segment));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Events_Status* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Events_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Turn_Event_triggered_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_Turn_Event_triggered_GUESS));
    ptree->appendChild("m_Meteor_active", new QMoMTreeItem<uint16_t>(&rhs->m_Meteor_active));
    ptree->appendChild("m_Meteor_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Meteor_playerNr));
    ptree->appendChild("m_Meteor_cityNr", new QMoMTreeItem<uint16_t>(&rhs->m_Meteor_cityNr));
    ptree->appendChild("m_Gift_of_the_Gods_active", new QMoMTreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_active));
    ptree->appendChild("m_Gift_of_the_Gods_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_playerNr));
    ptree->appendChild("m_Gift_of_the_Gods_itemNr_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_Gift_of_the_Gods_itemNr_GUESS));
    ptree->appendChild("m_Disjunction_active", new QMoMTreeItem<uint16_t>(&rhs->m_Disjunction_active));
    ptree->appendChild("m_Diplomatic_Marriage_active", new QMoMTreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_active));
    ptree->appendChild("m_Diplomatic_Marriage_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_playerNr));
    ptree->appendChild("m_Diplomatic_Marriage_newCityNr_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_newCityNr_GUESS));
    ptree->appendChild("m_Diplomatic_Marriage_cityNr_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_Diplomatic_Marriage_cityNr_GUESS));
    ptree->appendChild("m_Earthquake_active", new QMoMTreeItem<uint16_t>(&rhs->m_Earthquake_active));
    ptree->appendChild("m_Earthquake_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Earthquake_playerNr));
    ptree->appendChild("m_Earthquake_cityNr", new QMoMTreeItem<uint16_t>(&rhs->m_Earthquake_cityNr));
    ptree->appendChild("m_Pirates_active", new QMoMTreeItem<uint16_t>(&rhs->m_Pirates_active));
    ptree->appendChild("m_Pirates_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Pirates_playerNr));
    ptree->appendChild("m_Pirates_gold_stolen", new QMoMTreeItem<uint16_t>(&rhs->m_Pirates_gold_stolen));
    ptree->appendChild("m_Plague_active", new QMoMTreeItem<uint16_t>(&rhs->m_Plague_active));
    ptree->appendChild("m_Plague_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Plague_playerNr));
    ptree->appendChild("m_Plague_cityNr", new QMoMTreeItem<uint16_t>(&rhs->m_Plague_cityNr));
    ptree->appendChild("m_UNUSED01", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED01));
    ptree->appendChild("m_Rebellion_active", new QMoMTreeItem<uint16_t>(&rhs->m_Rebellion_active));
    ptree->appendChild("m_Rebellion_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Rebellion_playerNr));
    ptree->appendChild("m_Rebellion_cityNr", new QMoMTreeItem<uint16_t>(&rhs->m_Rebellion_cityNr));
    ptree->appendChild("m_Donation_active", new QMoMTreeItem<uint16_t>(&rhs->m_Donation_active));
    ptree->appendChild("m_Donation_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Donation_playerNr));
    ptree->appendChild("m_Donation_gold_donated", new QMoMTreeItem<uint16_t>(&rhs->m_Donation_gold_donated));
    ptree->appendChild("m_Depletion_active", new QMoMTreeItem<uint16_t>(&rhs->m_Depletion_active));
    ptree->appendChild("m_Depletion_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Depletion_playerNr));
    ptree->appendChild("m_UNUSED02", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED02));
    ptree->appendChild("m_Mine_found_active", new QMoMTreeItem<uint16_t>(&rhs->m_Mine_found_active));
    ptree->appendChild("m_Mine_found_playerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Mine_found_playerNr));
    ptree->appendChild("m_UNUSED03", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED03));
    ptree->appendChild("m_Population_Boom_active", new QMoMTreeItem<uint16_t>(&rhs->m_Population_Boom_active));
    ptree->appendChild("m_Population_Boom_CityNr", new QMoMTreeItem<uint16_t>(&rhs->m_Population_Boom_CityNr));
    ptree->appendChild("m_Population_Boom_PlayerNr", new QMoMTreeItem<uint16_t>(&rhs->m_Population_Boom_PlayerNr));
    ptree->appendChild("m_UNUSED04", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED04));
    ptree->appendChild("m_Good_Moon_active", new QMoMTreeItem<uint16_t>(&rhs->m_Good_Moon_active));
    ptree->appendChild("m_UNUSED05", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED05));
    ptree->appendChild("m_Bad_Moon_active", new QMoMTreeItem<uint16_t>(&rhs->m_Bad_Moon_active));
    ptree->appendChild("m_UNUSED06", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED06));
    ptree->appendChild("m_Conjunction_Sorcery_active", new QMoMTreeItem<uint16_t>(&rhs->m_Conjunction_Sorcery_active));
    ptree->appendChild("m_UNUSED07", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED07));
    ptree->appendChild("m_Conjunction_Nature_active", new QMoMTreeItem<uint16_t>(&rhs->m_Conjunction_Nature_active));
    ptree->appendChild("m_UNUSED08", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED08));
    ptree->appendChild("m_Conjunction_Chaos_active", new QMoMTreeItem<uint16_t>(&rhs->m_Conjunction_Chaos_active));
    ptree->appendChild("m_UNUSED09", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED09));
    ptree->appendChild("m_Mana_Short_active", new QMoMTreeItem<uint16_t>(&rhs->m_Mana_Short_active));
    ptree->appendChild("m_UNUSED10", new QMoMTreeItem<uint16_t>(&rhs->m_UNUSED10));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Fortress* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Fortress>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Active", new QMoMTreeItem<uint8_t>(&rhs->m_Active));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Game_Data_Save* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Game_Data_Save>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Number_of_Wizards", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Wizards));
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItem<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size_setting));
    }
    else
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItem<eLand_Size>(&rhs->m_Land_Size_setting));
    }
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItem<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful_setting));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    }
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty>(&rhs->m_Difficulty));
    }
    ptree->appendChild("m_Number_of_Cities", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Cities));
    ptree->appendChild("m_Number_of_Units", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Current_Turn", new QMoMTreeItem<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_UnitNr_Active", new QMoMTreeItem<uint16_t>(&rhs->m_UnitNr_Active));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Game_Settings* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Game_Settings>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Sound_Effects", new QMoMTreeItem<eYesNo16>(&rhs->m_Sound_Effects));
    ptree->appendChild("m_Background_Music", new QMoMTreeItem<eYesNo16>(&rhs->m_Background_Music));
    ptree->appendChild("m_Event_Music", new QMoMTreeItem<eYesNo16>(&rhs->m_Event_Music));
    ptree->appendChild("m_City_Spell_Events", new QMoMTreeItem<eYesNo16>(&rhs->m_City_Spell_Events));
    ptree->appendChild("m_Overland_Spell_Events", new QMoMTreeItem<eYesNo16>(&rhs->m_Overland_Spell_Events));
    ptree->appendChild("m_Summoning_Events", new QMoMTreeItem<eYesNo16>(&rhs->m_Summoning_Events));
    ptree->appendChild("m_End_of_Turn_Summary", new QMoMTreeItem<eYesNo16>(&rhs->m_End_of_Turn_Summary));
    ptree->appendChild("m_Raze_City", new QMoMTreeItem<eYesNo16>(&rhs->m_Raze_City));
    ptree->appendChild("m_Random_Events", new QMoMTreeItem<eYesNo16>(&rhs->m_Random_Events));
    ptree->appendChild("m_End_of_Turn_Wait", new QMoMTreeItem<eYesNo16>(&rhs->m_End_of_Turn_Wait));
    ptree->appendChild("m_Stratic_Combat_Only", new QMoMTreeItem<eYesNo16>(&rhs->m_Stratic_Combat_Only));
    ptree->appendChild("m_Auto_Unit_Information", new QMoMTreeItem<eYesNo16>(&rhs->m_Auto_Unit_Information));
    ptree->appendChild("m_Enemy_Moves", new QMoMTreeItem<eYesNo16>(&rhs->m_Enemy_Moves));
    ptree->appendChild("m_Enemy_Spells", new QMoMTreeItem<eYesNo16>(&rhs->m_Enemy_Spells));
    ptree->appendChild("m_Spell_Book_Ordering", new QMoMTreeItem<eYesNo16>(&rhs->m_Spell_Book_Ordering));
    ptree->appendChild("m_Spell_Animations", new QMoMTreeItem<eYesNo16>(&rhs->m_Spell_Animations));
    ptree->appendChild("m_Show_Node_Owners", new QMoMTreeItem<eYesNo16>(&rhs->m_Show_Node_Owners));
    ptree->appendChild("m_Expanding_Help", new QMoMTreeItem<eYesNo16>(&rhs->m_Expanding_Help));
    ptree->appendChild("m_UNK01", new QMoMTreeItem<uint16_t>(&rhs->m_UNK01));
    ptree->appendChild("m_UNK02", new QMoMTreeItem<uint16_t>(&rhs->m_UNK02));
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty>(&rhs->m_Difficulty));
    }
    ptree->appendChild("m_Nr_Opponents", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_Opponents));
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size", new QMoMTreeItem<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size));
    }
    else
    {
        ptree->appendChild("m_Land_Size", new QMoMTreeItem<eLand_Size>(&rhs->m_Land_Size));
    }
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful", new QMoMTreeItem<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful", new QMoMTreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful));
    }
    QMoMTreeItemBase* ptreem_Slots_Saved = ptree;
    if (8 > 3)
    {
        ptreem_Slots_Saved = new QMoMTreeItemBase("m_Slots_Saved");
        ptree->appendTree(ptreem_Slots_Saved, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slots_Saved[" << i << "]";
          ptreem_Slots_Saved->appendChild(oss.str().c_str(), new QMoMTreeItem<eYesNo16>(&rhs->m_Slots_Saved[i]));
    }
    QMoMTreeItemBase* ptreem_Save_Names = ptree;
    if (8 > 3)
    {
        ptreem_Save_Names = new QMoMTreeItemBase("m_Save_Names");
        ptree->appendTree(ptreem_Save_Names, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Names[" << i << "]";
          ptreem_Save_Names->appendTree(constructTreeItem(&rhs->m_Save_Names[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Movement_Animations", new QMoMTreeItem<eYesNo16>(&rhs->m_Movement_Animations));
    QMoMTreeItemBase* ptreem_Save_Wizard_Names = ptree;
    if (10 > 3)
    {
        ptreem_Save_Wizard_Names = new QMoMTreeItemBase("m_Save_Wizard_Names");
        ptree->appendTree(ptreem_Save_Wizard_Names, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Wizard_Names[" << i << "]";
          ptreem_Save_Wizard_Names->appendTree(constructTreeItem(&rhs->m_Save_Wizard_Names[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UNK03 = ptree;
    if (20 > 3)
    {
        ptreem_UNK03 = new QMoMTreeItemBase("m_UNK03");
        ptree->appendTree(ptreem_UNK03, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK03[" << i << "]";
          ptreem_UNK03->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_UNK03[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Global_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Global_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Eternal_Night", new QMoMTreeItem<uint8_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItem<uint8_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItem<uint8_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItem<uint8_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItem<uint8_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItem<uint8_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItem<uint8_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItem<uint8_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItem<uint8_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItem<uint8_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItem<uint8_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItem<uint8_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new QMoMTreeItem<uint8_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItem<uint8_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new QMoMTreeItem<uint8_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new QMoMTreeItem<uint8_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new QMoMTreeItem<uint8_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new QMoMTreeItem<uint8_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new QMoMTreeItem<uint8_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new QMoMTreeItem<uint8_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new QMoMTreeItem<uint8_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItem<uint8_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new QMoMTreeItem<uint8_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new QMoMTreeItem<uint8_t>(&rhs->Awareness));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(HelpLBXentry* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<HelpLBXentry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("title", new QMoMTreeItem<char[30]>(rhs->title));
    ptree->appendChild("lbxFile", new QMoMTreeItem<char[14]>(rhs->lbxFile));
    ptree->appendChild("lbxIndex", new QMoMTreeItem<uint16_t>(&rhs->lbxIndex));
    ptree->appendChild("zero", new QMoMTreeItem<uint16_t>(&rhs->zero));
    ptree->appendChild("description", new QMoMTreeItem<char[1000]>(rhs->description));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Hero_Ability* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Hero_Ability>(rhs, context);
    if (0 == rhs)
        return ptree;

    Hero_Ability maskLeadership;
    memset(&maskLeadership, '\0', sizeof(maskLeadership));
    maskLeadership.Leadership = 1;
    if (1 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership));
    else if (2 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership));
    else
        ptree->appendChild("Leadership", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership));
    Hero_Ability maskLeadership_X;
    memset(&maskLeadership_X, '\0', sizeof(maskLeadership_X));
    maskLeadership_X.Leadership_X = 1;
    if (1 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership_X));
    else if (2 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership_X));
    else
        ptree->appendChild("Leadership_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership_X));
    Hero_Ability masku1;
    memset(&masku1, '\0', sizeof(masku1));
    masku1.u1 = 1;
    if (1 == sizeof(masku1))
        ptree->appendChild("u1", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku1));
    else if (2 == sizeof(masku1))
        ptree->appendChild("u1", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku1));
    else
        ptree->appendChild("u1", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku1));
    Hero_Ability maskLegendary;
    memset(&maskLegendary, '\0', sizeof(maskLegendary));
    maskLegendary.Legendary = 1;
    if (1 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary));
    else if (2 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary));
    else
        ptree->appendChild("Legendary", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary));
    Hero_Ability maskLegendary_X;
    memset(&maskLegendary_X, '\0', sizeof(maskLegendary_X));
    maskLegendary_X.Legendary_X = 1;
    if (1 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary_X));
    else if (2 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary_X));
    else
        ptree->appendChild("Legendary_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary_X));
    Hero_Ability masku0;
    memset(&masku0, '\0', sizeof(masku0));
    masku0.u0 = 1;
    if (1 == sizeof(masku0))
        ptree->appendChild("u0", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku0));
    else if (2 == sizeof(masku0))
        ptree->appendChild("u0", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku0));
    else
        ptree->appendChild("u0", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku0));
    Hero_Ability maskBlademaster;
    memset(&maskBlademaster, '\0', sizeof(maskBlademaster));
    maskBlademaster.Blademaster = 1;
    if (1 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster));
    else if (2 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster));
    else
        ptree->appendChild("Blademaster", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster));
    Hero_Ability maskBlademaster_X;
    memset(&maskBlademaster_X, '\0', sizeof(maskBlademaster_X));
    maskBlademaster_X.Blademaster_X = 1;
    if (1 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster_X));
    else if (2 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster_X));
    else
        ptree->appendChild("Blademaster_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster_X));
    Hero_Ability masku4;
    memset(&masku4, '\0', sizeof(masku4));
    masku4.u4 = 1;
    if (1 == sizeof(masku4))
        ptree->appendChild("u4", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku4));
    else if (2 == sizeof(masku4))
        ptree->appendChild("u4", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku4));
    else
        ptree->appendChild("u4", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku4));
    Hero_Ability maskArmsmaster;
    memset(&maskArmsmaster, '\0', sizeof(maskArmsmaster));
    maskArmsmaster.Armsmaster = 1;
    if (1 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster));
    else if (2 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster));
    else
        ptree->appendChild("Armsmaster", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster));
    Hero_Ability maskArmsmaster_X;
    memset(&maskArmsmaster_X, '\0', sizeof(maskArmsmaster_X));
    maskArmsmaster_X.Armsmaster_X = 1;
    if (1 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster_X));
    else if (2 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster_X));
    else
        ptree->appendChild("Armsmaster_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster_X));
    Hero_Ability masku3;
    memset(&masku3, '\0', sizeof(masku3));
    masku3.u3 = 1;
    if (1 == sizeof(masku3))
        ptree->appendChild("u3", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku3));
    else if (2 == sizeof(masku3))
        ptree->appendChild("u3", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku3));
    else
        ptree->appendChild("u3", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku3));
    Hero_Ability maskConstitution;
    memset(&maskConstitution, '\0', sizeof(maskConstitution));
    maskConstitution.Constitution = 1;
    if (1 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution));
    else if (2 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution));
    else
        ptree->appendChild("Constitution", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution));
    Hero_Ability maskConstitution_X;
    memset(&maskConstitution_X, '\0', sizeof(maskConstitution_X));
    maskConstitution_X.Constitution_X = 1;
    if (1 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution_X));
    else if (2 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution_X));
    else
        ptree->appendChild("Constitution_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution_X));
    Hero_Ability masku2;
    memset(&masku2, '\0', sizeof(masku2));
    masku2.u2 = 1;
    if (1 == sizeof(masku2))
        ptree->appendChild("u2", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku2));
    else if (2 == sizeof(masku2))
        ptree->appendChild("u2", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku2));
    else
        ptree->appendChild("u2", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku2));
    Hero_Ability maskMight;
    memset(&maskMight, '\0', sizeof(maskMight));
    maskMight.Might = 1;
    if (1 == sizeof(maskMight))
        ptree->appendChild("Might", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight));
    else if (2 == sizeof(maskMight))
        ptree->appendChild("Might", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight));
    else
        ptree->appendChild("Might", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight));
    Hero_Ability maskMight_X;
    memset(&maskMight_X, '\0', sizeof(maskMight_X));
    maskMight_X.Might_X = 1;
    if (1 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight_X));
    else if (2 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight_X));
    else
        ptree->appendChild("Might_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight_X));
    Hero_Ability masku7;
    memset(&masku7, '\0', sizeof(masku7));
    masku7.u7 = 1;
    if (1 == sizeof(masku7))
        ptree->appendChild("u7", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku7));
    else if (2 == sizeof(masku7))
        ptree->appendChild("u7", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku7));
    else
        ptree->appendChild("u7", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku7));
    Hero_Ability maskArcane_Power;
    memset(&maskArcane_Power, '\0', sizeof(maskArcane_Power));
    maskArcane_Power.Arcane_Power = 1;
    if (1 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power));
    else if (2 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power));
    else
        ptree->appendChild("Arcane_Power", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power));
    Hero_Ability maskArcane_Power_X;
    memset(&maskArcane_Power_X, '\0', sizeof(maskArcane_Power_X));
    maskArcane_Power_X.Arcane_Power_X = 1;
    if (1 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power_X));
    else if (2 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power_X));
    else
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power_X));
    Hero_Ability masku6;
    memset(&masku6, '\0', sizeof(masku6));
    masku6.u6 = 1;
    if (1 == sizeof(masku6))
        ptree->appendChild("u6", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku6));
    else if (2 == sizeof(masku6))
        ptree->appendChild("u6", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku6));
    else
        ptree->appendChild("u6", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku6));
    Hero_Ability maskSage;
    memset(&maskSage, '\0', sizeof(maskSage));
    maskSage.Sage = 1;
    if (1 == sizeof(maskSage))
        ptree->appendChild("Sage", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage));
    else if (2 == sizeof(maskSage))
        ptree->appendChild("Sage", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage));
    else
        ptree->appendChild("Sage", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage));
    Hero_Ability maskSage_X;
    memset(&maskSage_X, '\0', sizeof(maskSage_X));
    maskSage_X.Sage_X = 1;
    if (1 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage_X));
    else if (2 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage_X));
    else
        ptree->appendChild("Sage_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage_X));
    Hero_Ability masku5;
    memset(&masku5, '\0', sizeof(masku5));
    masku5.u5 = 1;
    if (1 == sizeof(masku5))
        ptree->appendChild("u5", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku5));
    else if (2 == sizeof(masku5))
        ptree->appendChild("u5", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku5));
    else
        ptree->appendChild("u5", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku5));
    Hero_Ability maskPrayermaster;
    memset(&maskPrayermaster, '\0', sizeof(maskPrayermaster));
    maskPrayermaster.Prayermaster = 1;
    if (1 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster));
    else if (2 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster));
    else
        ptree->appendChild("Prayermaster", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster));
    Hero_Ability maskPrayermaster_X;
    memset(&maskPrayermaster_X, '\0', sizeof(maskPrayermaster_X));
    maskPrayermaster_X.Prayermaster_X = 1;
    if (1 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster_X));
    else if (2 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster_X));
    else
        ptree->appendChild("Prayermaster_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster_X));
    Hero_Ability maskAgility_X;
    memset(&maskAgility_X, '\0', sizeof(maskAgility_X));
    maskAgility_X.Agility_X = 1;
    if (1 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility_X));
    else if (2 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility_X));
    else
        ptree->appendChild("Agility_X", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility_X));
    Hero_Ability maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 1;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Hero_Ability maskCharmed;
    memset(&maskCharmed, '\0', sizeof(maskCharmed));
    maskCharmed.Charmed = 1;
    if (1 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCharmed));
    else if (2 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCharmed));
    else
        ptree->appendChild("Charmed", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCharmed));
    Hero_Ability maskNoble;
    memset(&maskNoble, '\0', sizeof(maskNoble));
    maskNoble.Noble = 1;
    if (1 == sizeof(maskNoble))
        ptree->appendChild("Noble", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNoble));
    else if (2 == sizeof(maskNoble))
        ptree->appendChild("Noble", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNoble));
    else
        ptree->appendChild("Noble", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNoble));
    Hero_Ability masku8;
    memset(&masku8, '\0', sizeof(masku8));
    masku8.u8 = 1;
    if (1 == sizeof(masku8))
        ptree->appendChild("u8", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku8));
    else if (2 == sizeof(masku8))
        ptree->appendChild("u8", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku8));
    else
        ptree->appendChild("u8", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku8));
    Hero_Ability maskAgility;
    memset(&maskAgility, '\0', sizeof(maskAgility));
    maskAgility.Agility = 1;
    if (1 == sizeof(maskAgility))
        ptree->appendChild("Agility", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility));
    else if (2 == sizeof(maskAgility))
        ptree->appendChild("Agility", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility));
    else
        ptree->appendChild("Agility", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Hero_Choice* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Hero_Choice>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new QMoMTreeItem<char[14]>(rhs->m_Name));
    QMoMTreeItemBase* ptreem_UNK = ptree;
    if (2 > 3)
    {
        ptreem_UNK = new QMoMTreeItemBase("m_UNK");
        ptree->appendTree(ptreem_UNK, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK[" << i << "]";
          ptreem_UNK->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Hero_Stats_Initializer* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Hero_Stats_Initializer>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Nr_Random_picks", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_Random_picks));
    ptree->appendChild("m_Random_pick_type", new QMoMTreeItem<eRandomPickType>(&rhs->m_Random_pick_type));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new QMoMTreeItem<uint16_t>(&rhs->m_Hero_Casting_Skill));
    QMoMTreeItemBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new QMoMTreeItemBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell16>(&rhs->m_Spell[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Hero_stats>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Level_Status", new QMoMTreeItem<eHero_Level_Status>(&rhs->m_Level_Status));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new QMoMTreeItem<uint8_t>(&rhs->m_Hero_Casting_Skill));
    QMoMTreeItemBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new QMoMTreeItemBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell>(&rhs->m_Spell[i]));
    }
    ptree->appendChild("m_Garbage", new QMoMTreeItem<uint8_t>(&rhs->m_Garbage));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Hired_Hero* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Hired_Hero>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Unit_Nr", new QMoMTreeItem<int16_t>(&rhs->m_Unit_Nr));
    ptree->appendChild("m_Hero_name", new QMoMTreeItem<char[14]>(rhs->m_Hero_name));
    QMoMTreeItemBase* ptreem_Items_In_Slot = ptree;
    if (3 > 3)
    {
        ptreem_Items_In_Slot = new QMoMTreeItemBase("m_Items_In_Slot");
        ptree->appendTree(ptreem_Items_In_Slot, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_In_Slot[" << i << "]";
          ptreem_Items_In_Slot->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_Items_In_Slot[i]));
    }
    QMoMTreeItemBase* ptreem_Slot_Types = ptree;
    if (3 > 3)
    {
        ptreem_Slot_Types = new QMoMTreeItemBase("m_Slot_Types");
        ptree->appendTree(ptreem_Slot_Types, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slot_Types[" << i << "]";
          ptreem_Slot_Types->appendChild(oss.str().c_str(), new QMoMTreeItem<eSlot_Type16>(&rhs->m_Slot_Types[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Immunity_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Immunity_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Immunity_Flags maskFire_Immunity;
    memset(&maskFire_Immunity, '\0', sizeof(maskFire_Immunity));
    maskFire_Immunity.Fire_Immunity = 1;
    if (1 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Immunity));
    else if (2 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Immunity));
    else
        ptree->appendChild("Fire_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Immunity));
    Immunity_Flags maskStoning_Immunity;
    memset(&maskStoning_Immunity, '\0', sizeof(maskStoning_Immunity));
    maskStoning_Immunity.Stoning_Immunity = 1;
    if (1 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Immunity));
    else if (2 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Immunity));
    else
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Immunity));
    Immunity_Flags maskMissiles_Immunity;
    memset(&maskMissiles_Immunity, '\0', sizeof(maskMissiles_Immunity));
    maskMissiles_Immunity.Missiles_Immunity = 1;
    if (1 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMissiles_Immunity));
    else if (2 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMissiles_Immunity));
    else
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMissiles_Immunity));
    Immunity_Flags maskIllusions_Immunity;
    memset(&maskIllusions_Immunity, '\0', sizeof(maskIllusions_Immunity));
    maskIllusions_Immunity.Illusions_Immunity = 1;
    if (1 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusions_Immunity));
    else if (2 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusions_Immunity));
    else
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusions_Immunity));
    Immunity_Flags maskCold_Immunity;
    memset(&maskCold_Immunity, '\0', sizeof(maskCold_Immunity));
    maskCold_Immunity.Cold_Immunity = 1;
    if (1 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCold_Immunity));
    else if (2 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCold_Immunity));
    else
        ptree->appendChild("Cold_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCold_Immunity));
    Immunity_Flags maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Immunity_Flags maskDeath_Immunity;
    memset(&maskDeath_Immunity, '\0', sizeof(maskDeath_Immunity));
    maskDeath_Immunity.Death_Immunity = 1;
    if (1 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Immunity));
    else if (2 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Immunity));
    else
        ptree->appendChild("Death_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Immunity));
    Immunity_Flags maskPoison_Immunity;
    memset(&maskPoison_Immunity, '\0', sizeof(maskPoison_Immunity));
    maskPoison_Immunity.Poison_Immunity = 1;
    if (1 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_Immunity));
    else if (2 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_Immunity));
    else
        ptree->appendChild("Poison_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_Immunity));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Item* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Item>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Item_Name", new QMoMTreeItem<char[30]>(rhs->m_Item_Name));
    ptree->appendChild("m_Icon", new QMoMTreeItem<eItem_Icon>(&rhs->m_Icon));
    ptree->appendChild("m_Slot_Required", new QMoMTreeItem<eSlot_Type8>(&rhs->m_Slot_Required));
    ptree->appendChild("m_Item_Type", new QMoMTreeItem<eItem_Type>(&rhs->m_Item_Type));
    ptree->appendChild("m_Cost", new QMoMTreeItem<int16_t>(&rhs->m_Cost));
    ptree->appendTree(constructTreeItem(&rhs->m_Bonuses, "m_Bonuses"), "");
    ptree->appendChild("m_Spell_Number_Charged", new QMoMTreeItem<eSpell>(&rhs->m_Spell_Number_Charged));
    ptree->appendChild("m_Number_Of_Charges", new QMoMTreeItem<int16_t>(&rhs->m_Number_Of_Charges));
    ptree->appendTree(constructTreeItem(&rhs->m_Bitmask_Powers, "m_Bitmask_Powers"), "");
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(ItemLBX* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<ItemLBX>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Code = ptree;
    if (4 > 3)
    {
        ptreem_Code = new QMoMTreeItemBase("m_Code");
        ptree->appendTree(ptreem_Code, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Code[" << i << "]";
          ptreem_Code->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Code[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Item, "m_Item"), "");
    QMoMTreeItemBase* ptreem_UNK01 = ptree;
    if (2 > 3)
    {
        ptreem_UNK01 = new QMoMTreeItemBase("m_UNK01");
        ptree->appendTree(ptreem_UNK01, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01[" << i << "]";
          ptreem_UNK01->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK01[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Item_Bonuses* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Item_Bonuses>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Attack", new QMoMTreeItem<int8_t>(&rhs->Attack));
    ptree->appendChild("To_Hit", new QMoMTreeItem<int8_t>(&rhs->To_Hit));
    ptree->appendChild("Defense", new QMoMTreeItem<int8_t>(&rhs->Defense));
    ptree->appendChild("Movement_in_halves", new QMoMTreeItem<int8_t>(&rhs->Movement_in_halves));
    ptree->appendChild("Resistance", new QMoMTreeItem<int8_t>(&rhs->Resistance));
    ptree->appendChild("Spell_Points", new QMoMTreeItem<int8_t>(&rhs->Spell_Points));
    ptree->appendChild("Spell_Save", new QMoMTreeItem<int8_t>(&rhs->Spell_Save));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Item_Powers* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Item_Powers>(rhs, context);
    if (0 == rhs)
        return ptree;

    Item_Powers maskVampiric;
    memset(&maskVampiric, '\0', sizeof(maskVampiric));
    maskVampiric.Vampiric = 1;
    if (1 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVampiric));
    else if (2 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVampiric));
    else
        ptree->appendChild("Vampiric", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVampiric));
    Item_Powers maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 1;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Item_Powers maskLightning;
    memset(&maskLightning, '\0', sizeof(maskLightning));
    maskLightning.Lightning = 1;
    if (1 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLightning));
    else if (2 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLightning));
    else
        ptree->appendChild("Lightning", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLightning));
    Item_Powers maskCloak_Of_Fear;
    memset(&maskCloak_Of_Fear, '\0', sizeof(maskCloak_Of_Fear));
    maskCloak_Of_Fear.Cloak_Of_Fear = 1;
    if (1 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_Of_Fear));
    else if (2 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_Of_Fear));
    else
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_Of_Fear));
    Item_Powers maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 1;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Item_Powers maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 1;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Item_Powers maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Item_Powers maskPathfinding;
    memset(&maskPathfinding, '\0', sizeof(maskPathfinding));
    maskPathfinding.Pathfinding = 1;
    if (1 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPathfinding));
    else if (2 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPathfinding));
    else
        ptree->appendChild("Pathfinding", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPathfinding));
    Item_Powers maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 1;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Item_Powers maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 1;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Item_Powers maskElemental_Armour;
    memset(&maskElemental_Armour, '\0', sizeof(maskElemental_Armour));
    maskElemental_Armour.Elemental_Armour = 1;
    if (1 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armour));
    else if (2 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armour));
    else
        ptree->appendChild("Elemental_Armour", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armour));
    Item_Powers maskDoom_equals_Chaos;
    memset(&maskDoom_equals_Chaos, '\0', sizeof(maskDoom_equals_Chaos));
    maskDoom_equals_Chaos.Doom_equals_Chaos = 1;
    if (1 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoom_equals_Chaos));
    else if (2 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoom_equals_Chaos));
    else
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoom_equals_Chaos));
    Item_Powers maskStoning;
    memset(&maskStoning, '\0', sizeof(maskStoning));
    maskStoning.Stoning = 1;
    if (1 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning));
    else if (2 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning));
    else
        ptree->appendChild("Stoning", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning));
    Item_Powers maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 1;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Item_Powers maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 1;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Item_Powers maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Item_Powers maskDeath;
    memset(&maskDeath, '\0', sizeof(maskDeath));
    maskDeath.Death = 1;
    if (1 == sizeof(maskDeath))
        ptree->appendChild("Death", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath));
    else if (2 == sizeof(maskDeath))
        ptree->appendChild("Death", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath));
    else
        ptree->appendChild("Death", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath));
    Item_Powers maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 1;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Item_Powers maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 1;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Item_Powers maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Item_Powers maskFlaming;
    memset(&maskFlaming, '\0', sizeof(maskFlaming));
    maskFlaming.Flaming = 1;
    if (1 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlaming));
    else if (2 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlaming));
    else
        ptree->appendChild("Flaming", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlaming));
    Item_Powers maskHoly_Avenger;
    memset(&maskHoly_Avenger, '\0', sizeof(maskHoly_Avenger));
    maskHoly_Avenger.Holy_Avenger = 1;
    if (1 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Avenger));
    else if (2 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Avenger));
    else
        ptree->appendChild("Holy_Avenger", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Avenger));
    Item_Powers maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 1;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Item_Powers maskPhantasmal;
    memset(&maskPhantasmal, '\0', sizeof(maskPhantasmal));
    maskPhantasmal.Phantasmal = 1;
    if (1 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPhantasmal));
    else if (2 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPhantasmal));
    else
        ptree->appendChild("Phantasmal", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPhantasmal));
    Item_Powers maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 1;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Item_Powers maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 1;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Item_Powers maskLion_Heart;
    memset(&maskLion_Heart, '\0', sizeof(maskLion_Heart));
    maskLion_Heart.Lion_Heart = 1;
    if (1 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLion_Heart));
    else if (2 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLion_Heart));
    else
        ptree->appendChild("Lion_Heart", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLion_Heart));
    Item_Powers maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 1;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Item_Powers maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 1;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Item_Powers maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 1;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    Item_Powers maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 1;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Item_Powers maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 1;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(LBXHEADER* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<LBXHEADER>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("n", new QMoMTreeItem<uint16_t>(&rhs->n));
    ptree->appendChild("magic_number", new QMoMTreeItem<uint32_t>(&rhs->magic_number));
    ptree->appendChild("reserved", new QMoMTreeItem<uint16_t>(&rhs->reserved));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Lair_Inhabitant* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Lair_Inhabitant>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Inhabitant", new QMoMTreeItem<eUnit_Type>(&rhs->m_Inhabitant));
    Lair_Inhabitant maskm_Remaining_Nr_of_Inhabitant;
    memset(&maskm_Remaining_Nr_of_Inhabitant, '\0', sizeof(maskm_Remaining_Nr_of_Inhabitant));
    maskm_Remaining_Nr_of_Inhabitant.m_Remaining_Nr_of_Inhabitant = 15;
    if (1 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Remaining_Nr_of_Inhabitant));
    Lair_Inhabitant maskm_Initial_Nr_of_Inhabitant;
    memset(&maskm_Initial_Nr_of_Inhabitant, '\0', sizeof(maskm_Initial_Nr_of_Inhabitant));
    maskm_Initial_Nr_of_Inhabitant.m_Initial_Nr_of_Inhabitant = 15;
    if (1 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Initial_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Initial_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Initial_Nr_of_Inhabitant));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Lbx_EMS_info* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Lbx_EMS_info>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_buffer", new QMoMTreeItem<char[8]>(rhs->m_buffer));
    ptree->appendChild("m_Unk_08", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_08));
    ptree->appendChild("m_Unk_0A", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_0A));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(List_Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<List_Hero_stats>(rhs, context);
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

QMoMTreeItemBase* constructTreeItem(MapRow_Bonus* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_Bonus>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Bonus_Deposit = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Bonus_Deposit[" << i << "]";
          ptreem_Bonus_Deposit->appendChild(oss.str().c_str(), new QMoMTreeItem<eTerrainBonusDeposit>(&rhs->m_Bonus_Deposit[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MapRow_Exploration* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_Exploration>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Explored = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Explored[" << i << "]";
          ptreem_Explored->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Explored[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MapRow_LandMassID* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_LandMassID>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_LandMassID = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_LandMassID[" << i << "]";
          ptreem_LandMassID->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_LandMassID[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MapRow_Movement* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_Movement>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Moves = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Moves[" << i << "]";
          ptreem_Moves->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Moves[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MapRow_Terrain* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_Terrain>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Tile = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tile[" << i << "]";
          ptreem_Tile->appendChild(oss.str().c_str(), new QMoMTreeItem<eTerrainType>(&rhs->m_Tile[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MapRow_Terrain_Changes* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MapRow_Terrain_Changes>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Terrain_Changes = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Terrain_Changes[" << i << "]";
          ptreem_Terrain_Changes->appendTree(constructTreeItem(&rhs->m_Terrain_Changes[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Map_Attr* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Map_Attr>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Arcanus_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Bonus_Row = new QMoMTreeItemBase("m_Arcanus_Bonus_Row");
        ptree->appendTree(ptreem_Arcanus_Bonus_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Bonus_Row[" << i << "]";
          ptreem_Arcanus_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Bonus_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Bonus_Row = new QMoMTreeItemBase("m_Myrror_Bonus_Row");
        ptree->appendTree(ptreem_Myrror_Bonus_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Bonus_Row[" << i << "]";
          ptreem_Myrror_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Bonus_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Arcanus_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Exploration_Row = new QMoMTreeItemBase("m_Arcanus_Exploration_Row");
        ptree->appendTree(ptreem_Arcanus_Exploration_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Exploration_Row[" << i << "]";
          ptreem_Arcanus_Exploration_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Exploration_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Exploration_Row = new QMoMTreeItemBase("m_Myrror_Exploration_Row");
        ptree->appendTree(ptreem_Myrror_Exploration_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Exploration_Row[" << i << "]";
          ptreem_Myrror_Exploration_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Exploration_Row[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Arcanus_Movement, "m_Arcanus_Movement"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Myrror_Movement, "m_Myrror_Movement"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Events_Status, "m_Events_Status"), "");
    QMoMTreeItemBase* ptreem_Arcanus_Terrain_Changes_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Terrain_Changes_Row = new QMoMTreeItemBase("m_Arcanus_Terrain_Changes_Row");
        ptree->appendTree(ptreem_Arcanus_Terrain_Changes_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Terrain_Changes_Row[" << i << "]";
          ptreem_Arcanus_Terrain_Changes_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Terrain_Changes_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Terrain_Changes_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Terrain_Changes_Row = new QMoMTreeItemBase("m_Myrror_Terrain_Changes_Row");
        ptree->appendTree(ptreem_Myrror_Terrain_Changes_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Terrain_Changes_Row[" << i << "]";
          ptreem_Myrror_Terrain_Changes_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Terrain_Changes_Row[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Map_Movement* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Map_Movement>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Unused_Row = ptree;
    if (40 > 3)
    {
        ptreem_Unused_Row = new QMoMTreeItemBase("m_Unused_Row");
        ptree->appendTree(ptreem_Unused_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unused_Row[" << i << "]";
          ptreem_Unused_Row->appendTree(constructTreeItem(&rhs->m_Unused_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Walking_Row = ptree;
    if (40 > 3)
    {
        ptreem_Walking_Row = new QMoMTreeItemBase("m_Walking_Row");
        ptree->appendTree(ptreem_Walking_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Walking_Row[" << i << "]";
          ptreem_Walking_Row->appendTree(constructTreeItem(&rhs->m_Walking_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Forester_Row = ptree;
    if (40 > 3)
    {
        ptreem_Forester_Row = new QMoMTreeItemBase("m_Forester_Row");
        ptree->appendTree(ptreem_Forester_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Forester_Row[" << i << "]";
          ptreem_Forester_Row->appendTree(constructTreeItem(&rhs->m_Forester_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Mountaineer_Row = ptree;
    if (40 > 3)
    {
        ptreem_Mountaineer_Row = new QMoMTreeItemBase("m_Mountaineer_Row");
        ptree->appendTree(ptreem_Mountaineer_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Mountaineer_Row[" << i << "]";
          ptreem_Mountaineer_Row->appendTree(constructTreeItem(&rhs->m_Mountaineer_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Swimming_Row = ptree;
    if (40 > 3)
    {
        ptreem_Swimming_Row = new QMoMTreeItemBase("m_Swimming_Row");
        ptree->appendTree(ptreem_Swimming_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Swimming_Row[" << i << "]";
          ptreem_Swimming_Row->appendTree(constructTreeItem(&rhs->m_Swimming_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Sailing_Row = ptree;
    if (40 > 3)
    {
        ptreem_Sailing_Row = new QMoMTreeItemBase("m_Sailing_Row");
        ptree->appendTree(ptreem_Sailing_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Sailing_Row[" << i << "]";
          ptreem_Sailing_Row->appendTree(constructTreeItem(&rhs->m_Sailing_Row[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Map_Tiles* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Map_Tiles>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_Arcanus_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Map_Row = new QMoMTreeItemBase("m_Arcanus_Map_Row");
        ptree->appendTree(ptreem_Arcanus_Map_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Map_Row[" << i << "]";
          ptreem_Arcanus_Map_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Map_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Map_Row = new QMoMTreeItemBase("m_Myrror_Map_Row");
        ptree->appendTree(ptreem_Myrror_Map_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Map_Row[" << i << "]";
          ptreem_Myrror_Map_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Map_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Arcanus_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Arcanus_UNK01 = new QMoMTreeItemBase("m_Arcanus_UNK01");
        ptree->appendTree(ptreem_Arcanus_UNK01, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_UNK01[" << i << "]";
          ptreem_Arcanus_UNK01->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Arcanus_UNK01[i]));
    }
    QMoMTreeItemBase* ptreem_Myrror_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Myrror_UNK01 = new QMoMTreeItemBase("m_Myrror_UNK01");
        ptree->appendTree(ptreem_Myrror_UNK01, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_UNK01[" << i << "]";
          ptreem_Myrror_UNK01->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Myrror_UNK01[i]));
    }
    QMoMTreeItemBase* ptreem_Arcanus_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_LandMassID_Row = new QMoMTreeItemBase("m_Arcanus_LandMassID_Row");
        ptree->appendTree(ptreem_Arcanus_LandMassID_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_LandMassID_Row[" << i << "]";
          ptreem_Arcanus_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_LandMassID_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_LandMassID_Row = new QMoMTreeItemBase("m_Myrror_LandMassID_Row");
        ptree->appendTree(ptreem_Myrror_LandMassID_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_LandMassID_Row[" << i << "]";
          ptreem_Myrror_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Myrror_LandMassID_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Arcanus_Node_Attr = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Node_Attr = new QMoMTreeItemBase("m_Arcanus_Node_Attr");
        ptree->appendTree(ptreem_Arcanus_Node_Attr, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Node_Attr[" << i << "]";
          ptreem_Arcanus_Node_Attr->appendTree(constructTreeItem(&rhs->m_Arcanus_Node_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Attr = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Attr = new QMoMTreeItemBase("m_Myrror_Attr");
        ptree->appendTree(ptreem_Myrror_Attr, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Attr[" << i << "]";
          ptreem_Myrror_Attr->appendTree(constructTreeItem(&rhs->m_Myrror_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Fortresses = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Fortresses = new QMoMTreeItemBase("m_Fortresses");
        ptree->appendTree(ptreem_Fortresses, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Fortresses[" << i << "]";
          ptreem_Fortresses->appendTree(constructTreeItem(&rhs->m_Fortresses[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Tower_Attr = ptree;
    if (6 > 3)
    {
        ptreem_Tower_Attr = new QMoMTreeItemBase("m_Tower_Attr");
        ptree->appendTree(ptreem_Tower_Attr, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tower_Attr[" << i << "]";
          ptreem_Tower_Attr->appendTree(constructTreeItem(&rhs->m_Tower_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Arcanus_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Arcanus_Towers = new QMoMTreeItemBase("m_Arcanus_Towers");
        ptree->appendTree(ptreem_Arcanus_Towers, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Towers[" << i << "]";
          ptreem_Arcanus_Towers->appendTree(constructTreeItem(&rhs->m_Arcanus_Towers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Myrror_Towers = new QMoMTreeItemBase("m_Myrror_Towers");
        ptree->appendTree(ptreem_Myrror_Towers, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Towers[" << i << "]";
          ptreem_Myrror_Towers->appendTree(constructTreeItem(&rhs->m_Myrror_Towers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Arcanus_Nodes = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Nodes = new QMoMTreeItemBase("m_Arcanus_Nodes");
        ptree->appendTree(ptreem_Arcanus_Nodes, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Nodes[" << i << "]";
          ptreem_Arcanus_Nodes->appendTree(constructTreeItem(&rhs->m_Arcanus_Nodes[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Myrror_Nodes = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Nodes = new QMoMTreeItemBase("m_Myrror_Nodes");
        ptree->appendTree(ptreem_Myrror_Nodes, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Nodes[" << i << "]";
          ptreem_Myrror_Nodes->appendTree(constructTreeItem(&rhs->m_Myrror_Nodes[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Normal_Lairs = ptree;
    if (25 > 3)
    {
        ptreem_Normal_Lairs = new QMoMTreeItemBase("m_Normal_Lairs");
        ptree->appendTree(ptreem_Normal_Lairs, "");
    }
    for (unsigned i = 0; i < 25; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Lairs[" << i << "]";
          ptreem_Normal_Lairs->appendTree(constructTreeItem(&rhs->m_Normal_Lairs[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Weak_Lairs = ptree;
    if (32 > 3)
    {
        ptreem_Weak_Lairs = new QMoMTreeItemBase("m_Weak_Lairs");
        ptree->appendTree(ptreem_Weak_Lairs, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_Weak_Lairs[" << i << "]";
          ptreem_Weak_Lairs->appendTree(constructTreeItem(&rhs->m_Weak_Lairs[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_ExtraLairs_GUESS = ptree;
    if (3 > 3)
    {
        ptreem_ExtraLairs_GUESS = new QMoMTreeItemBase("m_ExtraLairs_GUESS");
        ptree->appendTree(ptreem_ExtraLairs_GUESS, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_ExtraLairs_GUESS[" << i << "]";
          ptreem_ExtraLairs_GUESS->appendTree(constructTreeItem(&rhs->m_ExtraLairs_GUESS[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MoMDataSegment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MoMDataSegment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new QMoMTreeItem<char[0x0130]>(rhs->m_DataSegmentStart));
    QMoMTreeItemBase* ptreem_Offsets_SkillNames = ptree;
    if (eSkill_MAX > 3)
    {
        ptreem_Offsets_SkillNames = new QMoMTreeItemBase("m_Offsets_SkillNames");
        ptree->appendTree(ptreem_Offsets_SkillNames, "");
    }
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_SkillNames[" << i << "]";
          ptreem_Offsets_SkillNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_SkillNames[i]));
    }
    ptree->appendChild("m_unk0154", new QMoMTreeItem<uint16_t>(&rhs->m_unk0154));
    QMoMTreeItemBase* ptreem_Offsets_CitySizeNames = ptree;
    if (eCity_Size_MAX > 3)
    {
        ptreem_Offsets_CitySizeNames = new QMoMTreeItemBase("m_Offsets_CitySizeNames");
        ptree->appendTree(ptreem_Offsets_CitySizeNames, "");
    }
    for (unsigned i = 0; i < eCity_Size_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CitySizeNames[" << i << "]";
          ptreem_Offsets_CitySizeNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_CitySizeNames[i]));
    }
    QMoMTreeItemBase* ptreem_Offsets_CitySpecialNames = ptree;
    if (7 > 3)
    {
        ptreem_Offsets_CitySpecialNames = new QMoMTreeItemBase("m_Offsets_CitySpecialNames");
        ptree->appendTree(ptreem_Offsets_CitySpecialNames, "");
    }
    for (unsigned i = 0; i < 7; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CitySpecialNames[" << i << "]";
          ptreem_Offsets_CitySpecialNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_CitySpecialNames[i]));
    }
    QMoMTreeItemBase* ptreem_Unk0170 = ptree;
    if (22 > 3)
    {
        ptreem_Unk0170 = new QMoMTreeItemBase("m_Unk0170");
        ptree->appendTree(ptreem_Unk0170, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk0170[" << i << "]";
          ptreem_Unk0170->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Unk0170[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Types, "m_Hero_Types"), "");
    QMoMTreeItemBase* ptreem_Normal_Units = ptree;
    if (4 + 115 > 3)
    {
        ptreem_Normal_Units = new QMoMTreeItemBase("m_Normal_Units");
        ptree->appendTree(ptreem_Normal_Units, "");
    }
    for (unsigned i = 0; i < 4 + 115; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Units[" << i << "]";
          ptreem_Normal_Units->appendTree(constructTreeItem(&rhs->m_Normal_Units[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Summoned_Units = ptree;
    if (44 > 3)
    {
        ptreem_Summoned_Units = new QMoMTreeItemBase("m_Summoned_Units");
        ptree->appendTree(ptreem_Summoned_Units, "");
    }
    for (unsigned i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "m_Summoned_Units[" << i << "]";
          ptreem_Summoned_Units->appendTree(constructTreeItem(&rhs->m_Summoned_Units[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_XP_Level_Table = ptree;
    if (9 > 3)
    {
        ptreem_XP_Level_Table = new QMoMTreeItemBase("m_XP_Level_Table");
        ptree->appendTree(ptreem_XP_Level_Table, "");
    }
    for (unsigned i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_XP_Level_Table[" << i << "]";
          ptreem_XP_Level_Table->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_XP_Level_Table[i]));
    }
    QMoMTreeItemBase* ptreem_Race_Data = ptree;
    if (14 > 3)
    {
        ptreem_Race_Data = new QMoMTreeItemBase("m_Race_Data");
        ptree->appendTree(ptreem_Race_Data, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Race_Data[" << i << "]";
          ptreem_Race_Data->appendTree(constructTreeItem(&rhs->m_Race_Data[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Unk1ED6", new QMoMTreeItem<uint16_t>(&rhs->m_Unk1ED6));
    ptree->appendChild("m_Offset_Arcane", new QMoMTreeItem<uint16_t>(&rhs->m_Offset_Arcane));
    QMoMTreeItemBase* ptreem_Offsets_RealmNames_5 = ptree;
    if (5 > 3)
    {
        ptreem_Offsets_RealmNames_5 = new QMoMTreeItemBase("m_Offsets_RealmNames_5");
        ptree->appendTree(ptreem_Offsets_RealmNames_5, "");
    }
    for (unsigned i = 0; i < 5; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_RealmNames_5[" << i << "]";
          ptreem_Offsets_RealmNames_5->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_RealmNames_5[i]));
    }
    QMoMTreeItemBase* ptreem_Offsets_CityEnchantmentNames = ptree;
    if (eCityEnchantments_MAX > 3)
    {
        ptreem_Offsets_CityEnchantmentNames = new QMoMTreeItemBase("m_Offsets_CityEnchantmentNames");
        ptree->appendTree(ptreem_Offsets_CityEnchantmentNames, "");
    }
    for (unsigned i = 0; i < eCityEnchantments_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CityEnchantmentNames[" << i << "]";
          ptreem_Offsets_CityEnchantmentNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_CityEnchantmentNames[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Upkeep_Enchantments, "m_Upkeep_Enchantments"), "");
    QMoMTreeItemBase* ptreem_Offsets_PersonalityNames = ptree;
    if (ePersonality_MAX > 3)
    {
        ptreem_Offsets_PersonalityNames = new QMoMTreeItemBase("m_Offsets_PersonalityNames");
        ptree->appendTree(ptreem_Offsets_PersonalityNames, "");
    }
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_PersonalityNames[" << i << "]";
          ptreem_Offsets_PersonalityNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_PersonalityNames[i]));
    }
    QMoMTreeItemBase* ptreem_Values_Personalities_GUESS = ptree;
    if (ePersonality_MAX > 3)
    {
        ptreem_Values_Personalities_GUESS = new QMoMTreeItemBase("m_Values_Personalities_GUESS");
        ptree->appendTree(ptreem_Values_Personalities_GUESS, "");
    }
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Values_Personalities_GUESS[" << i << "]";
          ptreem_Values_Personalities_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_Values_Personalities_GUESS[i]));
    }
    QMoMTreeItemBase* ptreem_Offsets_ObjectiveNames = ptree;
    if (eObjective_MAX > 3)
    {
        ptreem_Offsets_ObjectiveNames = new QMoMTreeItemBase("m_Offsets_ObjectiveNames");
        ptree->appendTree(ptreem_Offsets_ObjectiveNames, "");
    }
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_ObjectiveNames[" << i << "]";
          ptreem_Offsets_ObjectiveNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_ObjectiveNames[i]));
    }
    ptree->appendChild("m_Unk1FDE", new QMoMTreeItem<uint16_t>(&rhs->m_Unk1FDE));
    QMoMTreeItemBase* ptreem_Values_Objectives_GUESS = ptree;
    if (eObjective_MAX > 3)
    {
        ptreem_Values_Objectives_GUESS = new QMoMTreeItemBase("m_Values_Objectives_GUESS");
        ptree->appendTree(ptreem_Values_Objectives_GUESS, "");
    }
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Values_Objectives_GUESS[" << i << "]";
          ptreem_Values_Objectives_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_Values_Objectives_GUESS[i]));
    }
    QMoMTreeItemBase* ptreem_DifficultyTable = ptree;
    if (eDifficulty_MAX > 3)
    {
        ptreem_DifficultyTable = new QMoMTreeItemBase("m_DifficultyTable");
        ptree->appendTree(ptreem_DifficultyTable, "");
    }
    for (unsigned i = 0; i < eDifficulty_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_DifficultyTable[" << i << "]";
          ptreem_DifficultyTable->appendTree(constructTreeItem(&rhs->m_DifficultyTable[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UNK06a = ptree;
    if (72 > 3)
    {
        ptreem_UNK06a = new QMoMTreeItemBase("m_UNK06a");
        ptree->appendTree(ptreem_UNK06a, "");
    }
    for (unsigned i = 0; i < 72; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06a[" << i << "]";
          ptreem_UNK06a->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK06a[i]));
    }
    ptree->appendChild("m_NameBuffer_2082", new QMoMTreeItem<char[0x3A50 - 0x2082]>(rhs->m_NameBuffer_2082));
    QMoMTreeItemBase* ptreem_UnitView_HeroAbility_data = ptree;
    if (23 > 3)
    {
        ptreem_UnitView_HeroAbility_data = new QMoMTreeItemBase("m_UnitView_HeroAbility_data");
        ptree->appendTree(ptreem_UnitView_HeroAbility_data, "");
    }
    for (unsigned i = 0; i < 23; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_HeroAbility_data[" << i << "]";
          ptreem_UnitView_HeroAbility_data->appendTree(constructTreeItem(&rhs->m_UnitView_HeroAbility_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitView_UnitAbility_data = ptree;
    if (17 > 3)
    {
        ptreem_UnitView_UnitAbility_data = new QMoMTreeItemBase("m_UnitView_UnitAbility_data");
        ptree->appendTree(ptreem_UnitView_UnitAbility_data, "");
    }
    for (unsigned i = 0; i < 17; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitAbility_data[" << i << "]";
          ptreem_UnitView_UnitAbility_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitAbility_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitView_UnitImmunity_data = ptree;
    if (8 > 3)
    {
        ptreem_UnitView_UnitImmunity_data = new QMoMTreeItemBase("m_UnitView_UnitImmunity_data");
        ptree->appendTree(ptreem_UnitView_UnitImmunity_data, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitImmunity_data[" << i << "]";
          ptreem_UnitView_UnitImmunity_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitImmunity_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitView_UnitSpell_data = ptree;
    if (8 > 3)
    {
        ptreem_UnitView_UnitSpell_data = new QMoMTreeItemBase("m_UnitView_UnitSpell_data");
        ptree->appendTree(ptreem_UnitView_UnitSpell_data, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitSpell_data[" << i << "]";
          ptreem_UnitView_UnitSpell_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitSpell_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitView_UnitAttack_data = ptree;
    if (11 > 3)
    {
        ptreem_UnitView_UnitAttack_data = new QMoMTreeItemBase("m_UnitView_UnitAttack_data");
        ptree->appendTree(ptreem_UnitView_UnitAttack_data, "");
    }
    for (unsigned i = 0; i < 11; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitAttack_data[" << i << "]";
          ptreem_UnitView_UnitAttack_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitAttack_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitMutation_data = ptree;
    if (3 > 3)
    {
        ptreem_UnitMutation_data = new QMoMTreeItemBase("m_UnitMutation_data");
        ptree->appendTree(ptreem_UnitMutation_data, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitMutation_data[" << i << "]";
          ptreem_UnitMutation_data->appendTree(constructTreeItem(&rhs->m_UnitMutation_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitRanged_data = ptree;
    if (6 > 3)
    {
        ptreem_UnitRanged_data = new QMoMTreeItemBase("m_UnitRanged_data");
        ptree->appendTree(ptreem_UnitRanged_data, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitRanged_data[" << i << "]";
          ptreem_UnitRanged_data->appendTree(constructTreeItem(&rhs->m_UnitRanged_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UnitEnchantment_data = ptree;
    if (32 > 3)
    {
        ptreem_UnitEnchantment_data = new QMoMTreeItemBase("m_UnitEnchantment_data");
        ptree->appendTree(ptreem_UnitEnchantment_data, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitEnchantment_data[" << i << "]";
          ptreem_UnitEnchantment_data->appendTree(constructTreeItem(&rhs->m_UnitEnchantment_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_CombatEnchantment_data = ptree;
    if (15 > 3)
    {
        ptreem_CombatEnchantment_data = new QMoMTreeItemBase("m_CombatEnchantment_data");
        ptree->appendTree(ptreem_CombatEnchantment_data, "");
    }
    for (unsigned i = 0; i < 15; ++i)
    {
          std::ostringstream oss;
          oss << "m_CombatEnchantment_data[" << i << "]";
          ptreem_CombatEnchantment_data->appendTree(constructTreeItem(&rhs->m_CombatEnchantment_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_ItemPower_data = ptree;
    if (21 > 3)
    {
        ptreem_ItemPower_data = new QMoMTreeItemBase("m_ItemPower_data");
        ptree->appendTree(ptreem_ItemPower_data, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "m_ItemPower_data[" << i << "]";
          ptreem_ItemPower_data->appendTree(constructTreeItem(&rhs->m_ItemPower_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Offsets_UnitLevelNames = ptree;
    if (6 > 3)
    {
        ptreem_Offsets_UnitLevelNames = new QMoMTreeItemBase("m_Offsets_UnitLevelNames");
        ptree->appendTree(ptreem_Offsets_UnitLevelNames, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_UnitLevelNames[" << i << "]";
          ptreem_Offsets_UnitLevelNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_UnitLevelNames[i]));
    }
    QMoMTreeItemBase* ptreem_Offsets_HeroLevelNames = ptree;
    if (9 > 3)
    {
        ptreem_Offsets_HeroLevelNames = new QMoMTreeItemBase("m_Offsets_HeroLevelNames");
        ptree->appendTree(ptreem_Offsets_HeroLevelNames, "");
    }
    for (unsigned i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_HeroLevelNames[" << i << "]";
          ptreem_Offsets_HeroLevelNames->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_HeroLevelNames[i]));
    }
    QMoMTreeItemBase* ptreem_ItemPower_text = ptree;
    if (32 > 3)
    {
        ptreem_ItemPower_text = new QMoMTreeItemBase("m_ItemPower_text");
        ptree->appendTree(ptreem_ItemPower_text, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_ItemPower_text[" << i << "]";
          ptreem_ItemPower_text->appendTree(constructTreeItem(&rhs->m_ItemPower_text[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_NameBuffer_4064", new QMoMTreeItem<char[0x5E92 - 0x4064]>(rhs->m_NameBuffer_4064));
    ptree->appendChild("m_Next_Turn_seed_storage_lo", new QMoMTreeItem<uint16_t>(&rhs->m_Next_Turn_seed_storage_lo));
    ptree->appendChild("m_Next_Turn_seed_storage_hi", new QMoMTreeItem<uint16_t>(&rhs->m_Next_Turn_seed_storage_hi));
    QMoMTreeItemBase* ptreem_UNK_5E96 = ptree;
    if (0x6E9E - 0x5E96 > 3)
    {
        ptreem_UNK_5E96 = new QMoMTreeItemBase("m_UNK_5E96");
        ptree->appendTree(ptreem_UNK_5E96, "");
    }
    for (unsigned i = 0; i < 0x6E9E - 0x5E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_5E96[" << i << "]";
          ptreem_UNK_5E96->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_5E96[i]));
    }
    QMoMTreeItemBase* ptreem_Tax_Unrest_Table = ptree;
    if (eTax_Rate_MAX > 3)
    {
        ptreem_Tax_Unrest_Table = new QMoMTreeItemBase("m_Tax_Unrest_Table");
        ptree->appendTree(ptreem_Tax_Unrest_Table, "");
    }
    for (unsigned i = 0; i < eTax_Rate_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tax_Unrest_Table[" << i << "]";
          ptreem_Tax_Unrest_Table->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Tax_Unrest_Table[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_6EAC = ptree;
    if (0x7151 - 0x6EAC > 3)
    {
        ptreem_UNK_6EAC = new QMoMTreeItemBase("m_UNK_6EAC");
        ptree->appendTree(ptreem_UNK_6EAC, "");
    }
    for (unsigned i = 0; i < 0x7151 - 0x6EAC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_6EAC[" << i << "]";
          ptreem_UNK_6EAC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_6EAC[i]));
    }
    ptree->appendChild("m_Copyright_and_Version", new QMoMTreeItem<char[41]>(rhs->m_Copyright_and_Version));
    QMoMTreeItemBase* ptreem_UNK_717A = ptree;
    if (0x71E0 - 0x717A > 3)
    {
        ptreem_UNK_717A = new QMoMTreeItemBase("m_UNK_717A");
        ptree->appendTree(ptreem_UNK_717A, "");
    }
    for (unsigned i = 0; i < 0x71E0 - 0x717A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_717A[" << i << "]";
          ptreem_UNK_717A->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_717A[i]));
    }
    ptree->appendChild("m_BIOS_clock_snapshot", new QMoMTreeItem<uint32_t>(&rhs->m_BIOS_clock_snapshot));
    QMoMTreeItemBase* ptreem_UNK_71E4 = ptree;
    if (0x7846 - 0x71E4 > 3)
    {
        ptreem_UNK_71E4 = new QMoMTreeItemBase("m_UNK_71E4");
        ptree->appendTree(ptreem_UNK_71E4, "");
    }
    for (unsigned i = 0; i < 0x7846 - 0x71E4; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_71E4[" << i << "]";
          ptreem_UNK_71E4->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_71E4[i]));
    }
    ptree->appendChild("m_RNG_seed_lo", new QMoMTreeItem<uint16_t>(&rhs->m_RNG_seed_lo));
    ptree->appendChild("m_RNG_seed_hi", new QMoMTreeItem<uint16_t>(&rhs->m_RNG_seed_hi));
    QMoMTreeItemBase* ptreem_UNK06c = ptree;
    if (0x7876 - 0x784A > 3)
    {
        ptreem_UNK06c = new QMoMTreeItemBase("m_UNK06c");
        ptree->appendTree(ptreem_UNK06c, "");
    }
    for (unsigned i = 0; i < 0x7876 - 0x784A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06c[" << i << "]";
          ptreem_UNK06c->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK06c[i]));
    }
    ptree->appendChild("m_DEBUG_Off", new QMoMTreeItem<uint16_t>(&rhs->m_DEBUG_Off));
    QMoMTreeItemBase* ptreem_UNK06d = ptree;
    if (0x912C - 0x7878 > 3)
    {
        ptreem_UNK06d = new QMoMTreeItemBase("m_UNK06d");
        ptree->appendTree(ptreem_UNK06d, "");
    }
    for (unsigned i = 0; i < 0x912C - 0x7878; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK06d[" << i << "]";
          ptreem_UNK06d->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK06d[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Spell_Data, "m_addr_Spell_Data"), "");
    ptree->appendChild("word_3FBD0", new QMoMTreeItem<uint16_t>(&rhs->word_3FBD0));
    ptree->appendChild("w_sound_x", new QMoMTreeItem<uint16_t>(&rhs->w_sound_x));
    ptree->appendChild("word_3FBD4", new QMoMTreeItem<uint16_t>(&rhs->word_3FBD4));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Items, "m_addr_Items"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_item_in_game_GUESS, "addr_item_in_game_GUESS"), "");
    QMoMTreeItemBase* ptreem_item_pics_116 = ptree;
    if (116 > 3)
    {
        ptreem_item_pics_116 = new QMoMTreeItemBase("m_item_pics_116");
        ptree->appendTree(ptreem_item_pics_116, "");
    }
    for (unsigned i = 0; i < 116; ++i)
    {
          std::ostringstream oss;
          oss << "m_item_pics_116[" << i << "]";
          ptreem_item_pics_116->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_item_pics_116[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_Unit_View, "m_addr_Battle_Unit_View"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_Unit, "m_addr_Battle_Unit"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Spells_Cast_in_Battle, "m_addr_Spells_Cast_in_Battle"), "");
    QMoMTreeItemBase* ptreem_addr_Hero_stat = ptree;
    if (6 > 3)
    {
        ptreem_addr_Hero_stat = new QMoMTreeItemBase("m_addr_Hero_stat");
        ptree->appendTree(ptreem_addr_Hero_stat, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_addr_Hero_stat[" << i << "]";
          ptreem_addr_Hero_stat->appendTree(constructTreeItem(&rhs->m_addr_Hero_stat[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreew_AI_flees = ptree;
    if (20 > 3)
    {
        ptreew_AI_flees = new QMoMTreeItemBase("w_AI_flees");
        ptree->appendTree(ptreew_AI_flees, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "w_AI_flees[" << i << "]";
          ptreew_AI_flees->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->w_AI_flees[i]));
    }
    QMoMTreeItemBase* ptreeword_3FCFE = ptree;
    if (10 > 3)
    {
        ptreeword_3FCFE = new QMoMTreeItemBase("word_3FCFE");
        ptree->appendTree(ptreeword_3FCFE, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FCFE[" << i << "]";
          ptreeword_3FCFE->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FCFE[i]));
    }
    ptree->appendChild("word_3FD08", new QMoMTreeItem<uint16_t>(&rhs->word_3FD08));
    ptree->appendChild("word_3FD0A", new QMoMTreeItem<uint16_t>(&rhs->word_3FD0A));
    ptree->appendChild("word_3FD0C", new QMoMTreeItem<uint16_t>(&rhs->word_3FD0C));
    ptree->appendChild("word_3FD0E", new QMoMTreeItem<uint16_t>(&rhs->word_3FD0E));
    ptree->appendChild("word_3FD10", new QMoMTreeItem<uint16_t>(&rhs->word_3FD10));
    ptree->appendChild("word_3FD12", new QMoMTreeItem<uint16_t>(&rhs->word_3FD12));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battlefield, "m_addr_Battlefield"), "");
    ptree->appendChild("word_3FD18", new QMoMTreeItem<uint16_t>(&rhs->word_3FD18));
    ptree->appendChild("word_3FD1A", new QMoMTreeItem<uint16_t>(&rhs->word_3FD1A));
    ptree->appendChild("w_AI_on_the_move_GUESS", new QMoMTreeItem<uint16_t>(&rhs->w_AI_on_the_move_GUESS));
    ptree->appendChild("w_coo_X_Y_clicked", new QMoMTreeItem<uint16_t>(&rhs->w_coo_X_Y_clicked));
    ptree->appendChild("w_coo_Y_X_clicked", new QMoMTreeItem<uint16_t>(&rhs->w_coo_Y_X_clicked));
    ptree->appendChild("word_3FD22", new QMoMTreeItem<uint16_t>(&rhs->word_3FD22));
    ptree->appendChild("m_clash_place_type", new QMoMTreeItem<int16_t>(&rhs->m_clash_place_type));
    ptree->appendChild("m_clash_cityNr_or_lairNr", new QMoMTreeItem<int16_t>(&rhs->m_clash_cityNr_or_lairNr));
    QMoMTreeItemBase* ptreeword_3FD28 = ptree;
    if (12 > 3)
    {
        ptreeword_3FD28 = new QMoMTreeItemBase("word_3FD28");
        ptree->appendTree(ptreeword_3FD28, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD28[" << i << "]";
          ptreeword_3FD28->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FD28[i]));
    }
    ptree->appendChild("m_kyrub_dseg_9294", new QMoMTreeItem<int16_t>(&rhs->m_kyrub_dseg_9294));
    ptree->appendChild("m_kyrub_dseg_9296", new QMoMTreeItem<int16_t>(&rhs->m_kyrub_dseg_9296));
    QMoMTreeItemBase* ptreeword_3FD38 = ptree;
    if (20 > 3)
    {
        ptreeword_3FD38 = new QMoMTreeItemBase("word_3FD38");
        ptree->appendTree(ptreeword_3FD38, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD38[" << i << "]";
          ptreeword_3FD38->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FD38[i]));
    }
    ptree->appendChild("w_negat_encha_x17_flag_def", new QMoMTreeItem<uint16_t>(&rhs->w_negat_encha_x17_flag_def));
    ptree->appendChild("w_aggre_spell_color_flag_att", new QMoMTreeItem<uint16_t>(&rhs->w_aggre_spell_color_flag_att));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FD50, "dword_3FD50"), "");
    ptree->appendChild("word_3FD54", new QMoMTreeItem<uint16_t>(&rhs->word_3FD54));
    QMoMTreeItemBase* ptreeword_3FD56 = ptree;
    if (64 > 3)
    {
        ptreeword_3FD56 = new QMoMTreeItemBase("word_3FD56");
        ptree->appendTree(ptreeword_3FD56, "");
    }
    for (unsigned i = 0; i < 64; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD56[" << i << "]";
          ptreeword_3FD56->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FD56[i]));
    }
    QMoMTreeItemBase* ptreeword_3FD96 = ptree;
    if (8 > 3)
    {
        ptreeword_3FD96 = new QMoMTreeItemBase("word_3FD96");
        ptree->appendTree(ptreeword_3FD96, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD96[" << i << "]";
          ptreeword_3FD96->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FD96[i]));
    }
    ptree->appendChild("word_3FD9E", new QMoMTreeItem<uint16_t>(&rhs->word_3FD9E));
    ptree->appendChild("word_3FDA0", new QMoMTreeItem<uint16_t>(&rhs->word_3FDA0));
    ptree->appendChild("word_3FDA2", new QMoMTreeItem<uint16_t>(&rhs->word_3FDA2));
    ptree->appendChild("word_3FDA4", new QMoMTreeItem<uint16_t>(&rhs->word_3FDA4));
    ptree->appendChild("word_3FDA6", new QMoMTreeItem<uint16_t>(&rhs->word_3FDA6));
    ptree->appendChild("word_3FDA8", new QMoMTreeItem<uint16_t>(&rhs->word_3FDA8));
    ptree->appendChild("word_3FDAA", new QMoMTreeItem<uint16_t>(&rhs->word_3FDAA));
    ptree->appendChild("word_3FDAC", new QMoMTreeItem<uint16_t>(&rhs->word_3FDAC));
    ptree->appendChild("word_3FDAE", new QMoMTreeItem<uint16_t>(&rhs->word_3FDAE));
    ptree->appendChild("word_3FDB0", new QMoMTreeItem<uint16_t>(&rhs->word_3FDB0));
    ptree->appendChild("word_3FDB2", new QMoMTreeItem<uint16_t>(&rhs->word_3FDB2));
    ptree->appendChild("word_3FDB4", new QMoMTreeItem<uint16_t>(&rhs->word_3FDB4));
    ptree->appendChild("word_3FDB6", new QMoMTreeItem<uint16_t>(&rhs->word_3FDB6));
    QMoMTreeItemBase* ptreeword_3FDB8 = ptree;
    if (44 > 3)
    {
        ptreeword_3FDB8 = new QMoMTreeItemBase("word_3FDB8");
        ptree->appendTree(ptreeword_3FDB8, "");
    }
    for (unsigned i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FDB8[" << i << "]";
          ptreeword_3FDB8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FDB8[i]));
    }
    ptree->appendChild("word_3FDE4", new QMoMTreeItem<uint16_t>(&rhs->word_3FDE4));
    ptree->appendTree(constructTreeItem(&rhs->addr_3FDE6, "addr_3FDE6"), "");
    ptree->appendChild("word_3FDEA", new QMoMTreeItem<uint16_t>(&rhs->word_3FDEA));
    ptree->appendChild("word_3FDEC", new QMoMTreeItem<uint16_t>(&rhs->word_3FDEC));
    ptree->appendChild("word_3FDEE", new QMoMTreeItem<uint16_t>(&rhs->word_3FDEE));
    ptree->appendChild("word_3FDF0", new QMoMTreeItem<uint16_t>(&rhs->word_3FDF0));
    ptree->appendChild("word_3FDF2", new QMoMTreeItem<uint16_t>(&rhs->word_3FDF2));
    ptree->appendChild("word_3FDF4", new QMoMTreeItem<uint16_t>(&rhs->word_3FDF4));
    ptree->appendChild("word_3FDF6", new QMoMTreeItem<uint16_t>(&rhs->word_3FDF6));
    ptree->appendChild("word_3FDF8", new QMoMTreeItem<uint16_t>(&rhs->word_3FDF8));
    ptree->appendChild("word_3FDFA", new QMoMTreeItem<uint16_t>(&rhs->word_3FDFA));
    ptree->appendChild("word_3FDFC", new QMoMTreeItem<uint16_t>(&rhs->word_3FDFC));
    ptree->appendChild("word_3FDFE", new QMoMTreeItem<uint16_t>(&rhs->word_3FDFE));
    ptree->appendChild("word_3FE00", new QMoMTreeItem<uint16_t>(&rhs->word_3FE00));
    ptree->appendChild("word_3FE02", new QMoMTreeItem<uint16_t>(&rhs->word_3FE02));
    ptree->appendChild("word_3FE04", new QMoMTreeItem<uint16_t>(&rhs->word_3FE04));
    ptree->appendChild("word_3FE06", new QMoMTreeItem<uint16_t>(&rhs->word_3FE06));
    ptree->appendChild("word_3FE08", new QMoMTreeItem<uint16_t>(&rhs->word_3FE08));
    ptree->appendChild("word_3FE0A", new QMoMTreeItem<uint16_t>(&rhs->word_3FE0A));
    ptree->appendChild("word_3FE0C", new QMoMTreeItem<uint16_t>(&rhs->word_3FE0C));
    ptree->appendChild("word_3FE0E", new QMoMTreeItem<uint16_t>(&rhs->word_3FE0E));
    ptree->appendChild("word_3FE10", new QMoMTreeItem<uint16_t>(&rhs->word_3FE10));
    ptree->appendChild("word_3FE12", new QMoMTreeItem<uint16_t>(&rhs->word_3FE12));
    ptree->appendChild("word_3FE14", new QMoMTreeItem<uint16_t>(&rhs->word_3FE14));
    ptree->appendChild("word_3FE16", new QMoMTreeItem<uint16_t>(&rhs->word_3FE16));
    ptree->appendChild("word_3FE18", new QMoMTreeItem<uint16_t>(&rhs->word_3FE18));
    ptree->appendChild("word_3FE1A", new QMoMTreeItem<uint16_t>(&rhs->word_3FE1A));
    ptree->appendChild("word_3FE1C", new QMoMTreeItem<uint16_t>(&rhs->word_3FE1C));
    ptree->appendChild("word_3FE1E", new QMoMTreeItem<uint16_t>(&rhs->word_3FE1E));
    ptree->appendChild("word_3FE20", new QMoMTreeItem<uint16_t>(&rhs->word_3FE20));
    ptree->appendChild("word_3FE22", new QMoMTreeItem<uint16_t>(&rhs->word_3FE22));
    ptree->appendChild("word_3FE24", new QMoMTreeItem<uint16_t>(&rhs->word_3FE24));
    ptree->appendChild("word_3FE26", new QMoMTreeItem<uint16_t>(&rhs->word_3FE26));
    ptree->appendChild("word_3FE28", new QMoMTreeItem<uint16_t>(&rhs->word_3FE28));
    ptree->appendChild("word_3FE2A", new QMoMTreeItem<uint16_t>(&rhs->word_3FE2A));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Building_Data, "m_addr_Building_Data"), "");
    ptree->appendChild("word_3FE30", new QMoMTreeItem<uint16_t>(&rhs->word_3FE30));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FE32, "dword_3FE32"), "");
    QMoMTreeItemBase* ptreedword_3FE36 = ptree;
    if (126 > 3)
    {
        ptreedword_3FE36 = new QMoMTreeItemBase("dword_3FE36");
        ptree->appendTree(ptreedword_3FE36, "");
    }
    for (unsigned i = 0; i < 126; ++i)
    {
          std::ostringstream oss;
          oss << "dword_3FE36[" << i << "]";
          ptreedword_3FE36->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->dword_3FE36[i]));
    }
    QMoMTreeItemBase* ptreeword_3FEB4 = ptree;
    if (6 > 3)
    {
        ptreeword_3FEB4 = new QMoMTreeItemBase("word_3FEB4");
        ptree->appendTree(ptreeword_3FEB4, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEB4[" << i << "]";
          ptreeword_3FEB4->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FEB4[i]));
    }
    QMoMTreeItemBase* ptreeword_3FEBA = ptree;
    if (18 > 3)
    {
        ptreeword_3FEBA = new QMoMTreeItemBase("word_3FEBA");
        ptree->appendTree(ptreeword_3FEBA, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEBA[" << i << "]";
          ptreeword_3FEBA->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FEBA[i]));
    }
    QMoMTreeItemBase* ptreeword_3FECC = ptree;
    if (22 > 3)
    {
        ptreeword_3FECC = new QMoMTreeItemBase("word_3FECC");
        ptree->appendTree(ptreeword_3FECC, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FECC[" << i << "]";
          ptreeword_3FECC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FECC[i]));
    }
    ptree->appendChild("word_3FEE2", new QMoMTreeItem<uint16_t>(&rhs->word_3FEE2));
    ptree->appendChild("w_all_units_moved_GUESS", new QMoMTreeItem<uint16_t>(&rhs->w_all_units_moved_GUESS));
    ptree->appendChild("word_3FEE6", new QMoMTreeItem<uint16_t>(&rhs->word_3FEE6));
    ptree->appendChild("word_3FEE8", new QMoMTreeItem<uint16_t>(&rhs->word_3FEE8));
    ptree->appendChild("word_3FEEA", new QMoMTreeItem<uint16_t>(&rhs->word_3FEEA));
    QMoMTreeItemBase* ptreeword_3FEEC = ptree;
    if (6 > 3)
    {
        ptreeword_3FEEC = new QMoMTreeItemBase("word_3FEEC");
        ptree->appendTree(ptreeword_3FEEC, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEEC[" << i << "]";
          ptreeword_3FEEC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FEEC[i]));
    }
    QMoMTreeItemBase* ptreeword_3FEF2 = ptree;
    if (14 > 3)
    {
        ptreeword_3FEF2 = new QMoMTreeItemBase("word_3FEF2");
        ptree->appendTree(ptreeword_3FEF2, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEF2[" << i << "]";
          ptreeword_3FEF2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FEF2[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->word_3FF00, "word_3FF00"), "");
    ptree->appendChild("word_3FF04", new QMoMTreeItem<uint16_t>(&rhs->word_3FF04));
    ptree->appendChild("word_3FF06", new QMoMTreeItem<uint16_t>(&rhs->word_3FF06));
    ptree->appendChild("word_3FF08", new QMoMTreeItem<uint16_t>(&rhs->word_3FF08));
    ptree->appendChild("word_3FF0A", new QMoMTreeItem<uint16_t>(&rhs->word_3FF0A));
    ptree->appendChild("word_3FF0C", new QMoMTreeItem<uint16_t>(&rhs->word_3FF0C));
    ptree->appendChild("word_3FF0E", new QMoMTreeItem<uint16_t>(&rhs->word_3FF0E));
    QMoMTreeItemBase* ptreeword_3FF10 = ptree;
    if (14 > 3)
    {
        ptreeword_3FF10 = new QMoMTreeItemBase("word_3FF10");
        ptree->appendTree(ptreeword_3FF10, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF10[" << i << "]";
          ptreeword_3FF10->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FF10[i]));
    }
    ptree->appendChild("word_3FF1E", new QMoMTreeItem<uint16_t>(&rhs->word_3FF1E));
    ptree->appendChild("word_3FF20", new QMoMTreeItem<uint16_t>(&rhs->word_3FF20));
    ptree->appendChild("word_3FF22", new QMoMTreeItem<uint16_t>(&rhs->word_3FF22));
    ptree->appendChild("word_3FF24", new QMoMTreeItem<uint16_t>(&rhs->word_3FF24));
    ptree->appendChild("word_3FF26", new QMoMTreeItem<uint16_t>(&rhs->word_3FF26));
    ptree->appendChild("word_3FF28", new QMoMTreeItem<uint16_t>(&rhs->word_3FF28));
    ptree->appendChild("word_3FF2A", new QMoMTreeItem<uint16_t>(&rhs->word_3FF2A));
    ptree->appendChild("word_3FF2C", new QMoMTreeItem<uint16_t>(&rhs->word_3FF2C));
    QMoMTreeItemBase* ptreeword_3FF2E = ptree;
    if (6 > 3)
    {
        ptreeword_3FF2E = new QMoMTreeItemBase("word_3FF2E");
        ptree->appendTree(ptreeword_3FF2E, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF2E[" << i << "]";
          ptreeword_3FF2E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FF2E[i]));
    }
    ptree->appendChild("word_3FF34", new QMoMTreeItem<uint16_t>(&rhs->word_3FF34));
    ptree->appendChild("word_3FF36", new QMoMTreeItem<uint16_t>(&rhs->word_3FF36));
    ptree->appendChild("word_3FF38", new QMoMTreeItem<uint16_t>(&rhs->word_3FF38));
    ptree->appendChild("word_3FF3A", new QMoMTreeItem<uint16_t>(&rhs->word_3FF3A));
    ptree->appendChild("word_3FF3C", new QMoMTreeItem<uint16_t>(&rhs->word_3FF3C));
    ptree->appendChild("word_3FF3E", new QMoMTreeItem<uint16_t>(&rhs->word_3FF3E));
    ptree->appendChild("word_3FF40", new QMoMTreeItem<uint16_t>(&rhs->word_3FF40));
    ptree->appendChild("word_3FF42", new QMoMTreeItem<uint16_t>(&rhs->word_3FF42));
    ptree->appendChild("word_3FF44", new QMoMTreeItem<uint16_t>(&rhs->word_3FF44));
    ptree->appendChild("word_3FF46", new QMoMTreeItem<uint16_t>(&rhs->word_3FF46));
    ptree->appendChild("word_3FF48", new QMoMTreeItem<uint16_t>(&rhs->word_3FF48));
    ptree->appendChild("word_3FF4A", new QMoMTreeItem<uint16_t>(&rhs->word_3FF4A));
    QMoMTreeItemBase* ptreeword_3FF4C = ptree;
    if (58 > 3)
    {
        ptreeword_3FF4C = new QMoMTreeItemBase("word_3FF4C");
        ptree->appendTree(ptreeword_3FF4C, "");
    }
    for (unsigned i = 0; i < 58; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF4C[" << i << "]";
          ptreeword_3FF4C->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FF4C[i]));
    }
    ptree->appendChild("word_3FF86", new QMoMTreeItem<uint16_t>(&rhs->word_3FF86));
    ptree->appendChild("word_3FF88", new QMoMTreeItem<uint16_t>(&rhs->word_3FF88));
    ptree->appendChild("word_3FF8A", new QMoMTreeItem<uint16_t>(&rhs->word_3FF8A));
    ptree->appendChild("word_3FF8C", new QMoMTreeItem<uint16_t>(&rhs->word_3FF8C));
    ptree->appendChild("word_3FF8E", new QMoMTreeItem<uint16_t>(&rhs->word_3FF8E));
    QMoMTreeItemBase* ptreeword_3FF90 = ptree;
    if (30 > 3)
    {
        ptreeword_3FF90 = new QMoMTreeItemBase("word_3FF90");
        ptree->appendTree(ptreeword_3FF90, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF90[" << i << "]";
          ptreeword_3FF90->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FF90[i]));
    }
    ptree->appendChild("word_3FFAE", new QMoMTreeItem<uint16_t>(&rhs->word_3FFAE));
    ptree->appendChild("word_3FFB0", new QMoMTreeItem<uint16_t>(&rhs->word_3FFB0));
    ptree->appendChild("word_3FFB2", new QMoMTreeItem<uint16_t>(&rhs->word_3FFB2));
    ptree->appendChild("word_3FFB4", new QMoMTreeItem<uint16_t>(&rhs->word_3FFB4));
    ptree->appendChild("word_3FFB6", new QMoMTreeItem<uint16_t>(&rhs->word_3FFB6));
    ptree->appendChild("word_3FFB8", new QMoMTreeItem<uint16_t>(&rhs->word_3FFB8));
    ptree->appendChild("word_3FFBA", new QMoMTreeItem<uint16_t>(&rhs->word_3FFBA));
    ptree->appendChild("word_3FFBC", new QMoMTreeItem<uint16_t>(&rhs->word_3FFBC));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFBE, "word_3FFBE"), "");
    ptree->appendChild("word_3FFC2", new QMoMTreeItem<uint16_t>(&rhs->word_3FFC2));
    ptree->appendChild("word_3FFC4", new QMoMTreeItem<uint16_t>(&rhs->word_3FFC4));
    ptree->appendChild("word_3FFC6", new QMoMTreeItem<uint16_t>(&rhs->word_3FFC6));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFC8, "word_3FFC8"), "");
    ptree->appendChild("word_3FFCC", new QMoMTreeItem<uint16_t>(&rhs->word_3FFCC));
    QMoMTreeItemBase* ptreeword_3FFCE = ptree;
    if (14 > 3)
    {
        ptreeword_3FFCE = new QMoMTreeItemBase("word_3FFCE");
        ptree->appendTree(ptreeword_3FFCE, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFCE[" << i << "]";
          ptreeword_3FFCE->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FFCE[i]));
    }
    ptree->appendChild("word_3FFDC", new QMoMTreeItem<uint16_t>(&rhs->word_3FFDC));
    ptree->appendChild("word_3FFDE", new QMoMTreeItem<uint16_t>(&rhs->word_3FFDE));
    QMoMTreeItemBase* ptreeword_3FFE0 = ptree;
    if (8 > 3)
    {
        ptreeword_3FFE0 = new QMoMTreeItemBase("word_3FFE0");
        ptree->appendTree(ptreeword_3FFE0, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE0[" << i << "]";
          ptreeword_3FFE0->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FFE0[i]));
    }
    QMoMTreeItemBase* ptreeword_3FFE8 = ptree;
    if (38 > 3)
    {
        ptreeword_3FFE8 = new QMoMTreeItemBase("word_3FFE8");
        ptree->appendTree(ptreeword_3FFE8, "");
    }
    for (unsigned i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE8[" << i << "]";
          ptreeword_3FFE8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_3FFE8[i]));
    }
    ptree->appendChild("word_4000E", new QMoMTreeItem<uint16_t>(&rhs->word_4000E));
    ptree->appendChild("word_40010", new QMoMTreeItem<uint16_t>(&rhs->word_40010));
    ptree->appendChild("word_40012", new QMoMTreeItem<uint16_t>(&rhs->word_40012));
    ptree->appendChild("word_40014", new QMoMTreeItem<uint16_t>(&rhs->word_40014));
    ptree->appendChild("word_40016", new QMoMTreeItem<uint16_t>(&rhs->word_40016));
    ptree->appendChild("word_40018", new QMoMTreeItem<uint16_t>(&rhs->word_40018));
    ptree->appendChild("word_4001A", new QMoMTreeItem<uint16_t>(&rhs->word_4001A));
    ptree->appendChild("word_4001C", new QMoMTreeItem<uint16_t>(&rhs->word_4001C));
    ptree->appendChild("word_4001E", new QMoMTreeItem<uint16_t>(&rhs->word_4001E));
    ptree->appendChild("word_40020", new QMoMTreeItem<uint16_t>(&rhs->word_40020));
    ptree->appendChild("word_40022", new QMoMTreeItem<uint16_t>(&rhs->word_40022));
    ptree->appendChild("word_40024", new QMoMTreeItem<uint16_t>(&rhs->word_40024));
    ptree->appendChild("word_40026", new QMoMTreeItem<uint16_t>(&rhs->word_40026));
    ptree->appendChild("word_40028", new QMoMTreeItem<uint16_t>(&rhs->word_40028));
    ptree->appendChild("word_4002A", new QMoMTreeItem<uint16_t>(&rhs->word_4002A));
    ptree->appendChild("word_4002C", new QMoMTreeItem<uint16_t>(&rhs->word_4002C));
    QMoMTreeItemBase* ptreeword_4002E = ptree;
    if (28 > 3)
    {
        ptreeword_4002E = new QMoMTreeItemBase("word_4002E");
        ptree->appendTree(ptreeword_4002E, "");
    }
    for (unsigned i = 0; i < 28; ++i)
    {
          std::ostringstream oss;
          oss << "word_4002E[" << i << "]";
          ptreeword_4002E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4002E[i]));
    }
    ptree->appendChild("word_4004A", new QMoMTreeItem<uint16_t>(&rhs->word_4004A));
    ptree->appendChild("word_4004C", new QMoMTreeItem<uint16_t>(&rhs->word_4004C));
    ptree->appendChild("word_4004E", new QMoMTreeItem<uint16_t>(&rhs->word_4004E));
    ptree->appendChild("word_40050", new QMoMTreeItem<uint16_t>(&rhs->word_40050));
    ptree->appendChild("word_40052", new QMoMTreeItem<uint16_t>(&rhs->word_40052));
    ptree->appendChild("word_40054", new QMoMTreeItem<uint16_t>(&rhs->word_40054));
    ptree->appendChild("word_40056", new QMoMTreeItem<uint16_t>(&rhs->word_40056));
    ptree->appendChild("word_40058", new QMoMTreeItem<uint16_t>(&rhs->word_40058));
    ptree->appendChild("word_4005A", new QMoMTreeItem<uint16_t>(&rhs->word_4005A));
    ptree->appendChild("word_4005C", new QMoMTreeItem<uint16_t>(&rhs->word_4005C));
    ptree->appendChild("word_4005E", new QMoMTreeItem<uint16_t>(&rhs->word_4005E));
    ptree->appendChild("word_40060", new QMoMTreeItem<uint16_t>(&rhs->word_40060));
    QMoMTreeItemBase* ptreeword_40062 = ptree;
    if (12 > 3)
    {
        ptreeword_40062 = new QMoMTreeItemBase("word_40062");
        ptree->appendTree(ptreeword_40062, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "word_40062[" << i << "]";
          ptreeword_40062->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40062[i]));
    }
    QMoMTreeItemBase* ptreeword_4006E = ptree;
    if (34 > 3)
    {
        ptreeword_4006E = new QMoMTreeItemBase("word_4006E");
        ptree->appendTree(ptreeword_4006E, "");
    }
    for (unsigned i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4006E[" << i << "]";
          ptreeword_4006E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4006E[i]));
    }
    ptree->appendChild("word_40090", new QMoMTreeItem<uint16_t>(&rhs->word_40090));
    QMoMTreeItemBase* ptreeword_40092 = ptree;
    if (82 > 3)
    {
        ptreeword_40092 = new QMoMTreeItemBase("word_40092");
        ptree->appendTree(ptreeword_40092, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "word_40092[" << i << "]";
          ptreeword_40092->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40092[i]));
    }
    ptree->appendChild("m_cityNr_detailed", new QMoMTreeItem<int16_t>(&rhs->m_cityNr_detailed));
    QMoMTreeItemBase* ptreeword_400E8 = ptree;
    if (246 > 3)
    {
        ptreeword_400E8 = new QMoMTreeItemBase("word_400E8");
        ptree->appendTree(ptreeword_400E8, "");
    }
    for (unsigned i = 0; i < 246; ++i)
    {
          std::ostringstream oss;
          oss << "word_400E8[" << i << "]";
          ptreeword_400E8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_400E8[i]));
    }
    ptree->appendChild("word_401DC", new QMoMTreeItem<uint16_t>(&rhs->word_401DC));
    ptree->appendChild("word_401DE", new QMoMTreeItem<uint16_t>(&rhs->word_401DE));
    ptree->appendChild("word_401E0", new QMoMTreeItem<uint16_t>(&rhs->word_401E0));
    ptree->appendChild("word_401E2", new QMoMTreeItem<uint16_t>(&rhs->word_401E2));
    ptree->appendChild("word_401E4", new QMoMTreeItem<uint16_t>(&rhs->word_401E4));
    ptree->appendChild("word_401E6", new QMoMTreeItem<uint16_t>(&rhs->word_401E6));
    ptree->appendChild("word_401E8", new QMoMTreeItem<uint16_t>(&rhs->word_401E8));
    ptree->appendChild("word_401EA", new QMoMTreeItem<uint16_t>(&rhs->word_401EA));
    ptree->appendChild("word_401EC", new QMoMTreeItem<uint16_t>(&rhs->word_401EC));
    ptree->appendChild("word_401EE", new QMoMTreeItem<uint16_t>(&rhs->word_401EE));
    ptree->appendChild("word_401F0", new QMoMTreeItem<uint16_t>(&rhs->word_401F0));
    ptree->appendChild("word_401F2", new QMoMTreeItem<uint16_t>(&rhs->word_401F2));
    ptree->appendChild("word_401F4", new QMoMTreeItem<uint16_t>(&rhs->word_401F4));
    ptree->appendChild("word_401F6", new QMoMTreeItem<uint16_t>(&rhs->word_401F6));
    ptree->appendChild("word_401F8", new QMoMTreeItem<uint16_t>(&rhs->word_401F8));
    ptree->appendChild("word_401FA", new QMoMTreeItem<uint16_t>(&rhs->word_401FA));
    ptree->appendChild("word_401FC", new QMoMTreeItem<uint16_t>(&rhs->word_401FC));
    ptree->appendChild("word_401FE", new QMoMTreeItem<uint16_t>(&rhs->word_401FE));
    ptree->appendChild("word_40200", new QMoMTreeItem<uint16_t>(&rhs->word_40200));
    ptree->appendChild("word_40202", new QMoMTreeItem<uint16_t>(&rhs->word_40202));
    ptree->appendChild("word_40204", new QMoMTreeItem<uint16_t>(&rhs->word_40204));
    ptree->appendChild("word_40206", new QMoMTreeItem<uint16_t>(&rhs->word_40206));
    ptree->appendChild("word_40208", new QMoMTreeItem<uint16_t>(&rhs->word_40208));
    ptree->appendChild("word_4020A", new QMoMTreeItem<uint16_t>(&rhs->word_4020A));
    QMoMTreeItemBase* ptreeword_4020C = ptree;
    if (38 > 3)
    {
        ptreeword_4020C = new QMoMTreeItemBase("word_4020C");
        ptree->appendTree(ptreeword_4020C, "");
    }
    for (unsigned i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_4020C[" << i << "]";
          ptreeword_4020C->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4020C[i]));
    }
    ptree->appendChild("word_40232", new QMoMTreeItem<uint16_t>(&rhs->word_40232));
    ptree->appendChild("word_40234", new QMoMTreeItem<uint16_t>(&rhs->word_40234));
    ptree->appendChild("word_40236", new QMoMTreeItem<uint16_t>(&rhs->word_40236));
    ptree->appendChild("word_40238", new QMoMTreeItem<uint16_t>(&rhs->word_40238));
    ptree->appendChild("word_4023A", new QMoMTreeItem<uint16_t>(&rhs->word_4023A));
    ptree->appendChild("word_4023C", new QMoMTreeItem<uint16_t>(&rhs->word_4023C));
    ptree->appendChild("word_4023E", new QMoMTreeItem<uint16_t>(&rhs->word_4023E));
    ptree->appendChild("word_40240", new QMoMTreeItem<uint16_t>(&rhs->word_40240));
    QMoMTreeItemBase* ptreeword_40242 = ptree;
    if (18 > 3)
    {
        ptreeword_40242 = new QMoMTreeItemBase("word_40242");
        ptree->appendTree(ptreeword_40242, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_40242[" << i << "]";
          ptreeword_40242->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40242[i]));
    }
    ptree->appendChild("word_40254", new QMoMTreeItem<uint16_t>(&rhs->word_40254));
    ptree->appendChild("word_40256", new QMoMTreeItem<uint16_t>(&rhs->word_40256));
    ptree->appendChild("word_40258", new QMoMTreeItem<uint16_t>(&rhs->word_40258));
    QMoMTreeItemBase* ptreeword_4025A = ptree;
    if (50 > 3)
    {
        ptreeword_4025A = new QMoMTreeItemBase("word_4025A");
        ptree->appendTree(ptreeword_4025A, "");
    }
    for (unsigned i = 0; i < 50; ++i)
    {
          std::ostringstream oss;
          oss << "word_4025A[" << i << "]";
          ptreeword_4025A->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4025A[i]));
    }
    ptree->appendChild("word_4028C", new QMoMTreeItem<uint16_t>(&rhs->word_4028C));
    QMoMTreeItemBase* ptreeword_4028E = ptree;
    if (10 > 3)
    {
        ptreeword_4028E = new QMoMTreeItemBase("word_4028E");
        ptree->appendTree(ptreeword_4028E, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4028E[" << i << "]";
          ptreeword_4028E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4028E[i]));
    }
    ptree->appendChild("word_40298", new QMoMTreeItem<uint16_t>(&rhs->word_40298));
    ptree->appendChild("word_4029A", new QMoMTreeItem<uint16_t>(&rhs->word_4029A));
    ptree->appendChild("word_4029C", new QMoMTreeItem<uint16_t>(&rhs->word_4029C));
    QMoMTreeItemBase* ptreeword_4029E = ptree;
    if (34 > 3)
    {
        ptreeword_4029E = new QMoMTreeItemBase("word_4029E");
        ptree->appendTree(ptreeword_4029E, "");
    }
    for (unsigned i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4029E[" << i << "]";
          ptreeword_4029E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4029E[i]));
    }
    QMoMTreeItemBase* ptreeword_402C0 = ptree;
    if (32 > 3)
    {
        ptreeword_402C0 = new QMoMTreeItemBase("word_402C0");
        ptree->appendTree(ptreeword_402C0, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "word_402C0[" << i << "]";
          ptreeword_402C0->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_402C0[i]));
    }
    ptree->appendChild("word_402E0", new QMoMTreeItem<uint16_t>(&rhs->word_402E0));
    QMoMTreeItemBase* ptreeword_402E2 = ptree;
    if (36 > 3)
    {
        ptreeword_402E2 = new QMoMTreeItemBase("word_402E2");
        ptree->appendTree(ptreeword_402E2, "");
    }
    for (unsigned i = 0; i < 36; ++i)
    {
          std::ostringstream oss;
          oss << "word_402E2[" << i << "]";
          ptreeword_402E2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_402E2[i]));
    }
    QMoMTreeItemBase* ptreeword_40306 = ptree;
    if (120 > 3)
    {
        ptreeword_40306 = new QMoMTreeItemBase("word_40306");
        ptree->appendTree(ptreeword_40306, "");
    }
    for (unsigned i = 0; i < 120; ++i)
    {
          std::ostringstream oss;
          oss << "word_40306[" << i << "]";
          ptreeword_40306->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40306[i]));
    }
    QMoMTreeItemBase* ptreeword_4037E = ptree;
    if (10 > 3)
    {
        ptreeword_4037E = new QMoMTreeItemBase("word_4037E");
        ptree->appendTree(ptreeword_4037E, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4037E[" << i << "]";
          ptreeword_4037E->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_4037E[i]));
    }
    QMoMTreeItemBase* ptreeword_40388 = ptree;
    if (10 > 3)
    {
        ptreeword_40388 = new QMoMTreeItemBase("word_40388");
        ptree->appendTree(ptreeword_40388, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_40388[" << i << "]";
          ptreeword_40388->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40388[i]));
    }
    ptree->appendChild("word_40392", new QMoMTreeItem<uint16_t>(&rhs->word_40392));
    QMoMTreeItemBase* ptreeword_40394 = ptree;
    if (20 > 3)
    {
        ptreeword_40394 = new QMoMTreeItemBase("word_40394");
        ptree->appendTree(ptreeword_40394, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_40394[" << i << "]";
          ptreeword_40394->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_40394[i]));
    }
    QMoMTreeItemBase* ptreeword_403A8 = ptree;
    if (6 > 3)
    {
        ptreeword_403A8 = new QMoMTreeItemBase("word_403A8");
        ptree->appendTree(ptreeword_403A8, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_403A8[" << i << "]";
          ptreeword_403A8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_403A8[i]));
    }
    QMoMTreeItemBase* ptreeword_403AE = ptree;
    if (10 > 3)
    {
        ptreeword_403AE = new QMoMTreeItemBase("word_403AE");
        ptree->appendTree(ptreeword_403AE, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_403AE[" << i << "]";
          ptreeword_403AE->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_403AE[i]));
    }
    ptree->appendChild("word_403B8", new QMoMTreeItem<uint16_t>(&rhs->word_403B8));
    ptree->appendChild("word_403BA", new QMoMTreeItem<uint16_t>(&rhs->word_403BA));
    ptree->appendChild("word_403BC", new QMoMTreeItem<uint16_t>(&rhs->word_403BC));
    ptree->appendChild("word_403BE", new QMoMTreeItem<uint16_t>(&rhs->word_403BE));
    ptree->appendChild("word_403C0", new QMoMTreeItem<uint16_t>(&rhs->word_403C0));
    QMoMTreeItemBase* ptreeword_403C2 = ptree;
    if (20 > 3)
    {
        ptreeword_403C2 = new QMoMTreeItemBase("word_403C2");
        ptree->appendTree(ptreeword_403C2, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_403C2[" << i << "]";
          ptreeword_403C2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_403C2[i]));
    }
    ptree->appendChild("word_403D6", new QMoMTreeItem<uint16_t>(&rhs->word_403D6));
    ptree->appendChild("word_403D8", new QMoMTreeItem<uint16_t>(&rhs->word_403D8));
    ptree->appendChild("word_403DA", new QMoMTreeItem<uint16_t>(&rhs->word_403DA));
    ptree->appendChild("word_403DC", new QMoMTreeItem<uint16_t>(&rhs->word_403DC));
    ptree->appendChild("word_403DE", new QMoMTreeItem<uint16_t>(&rhs->word_403DE));
    ptree->appendChild("word_403E0", new QMoMTreeItem<uint16_t>(&rhs->word_403E0));
    ptree->appendChild("word_403E2", new QMoMTreeItem<uint16_t>(&rhs->word_403E2));
    ptree->appendChild("word_403E4", new QMoMTreeItem<uint16_t>(&rhs->word_403E4));
    ptree->appendChild("word_403E6", new QMoMTreeItem<uint16_t>(&rhs->word_403E6));
    ptree->appendChild("word_403E8", new QMoMTreeItem<uint16_t>(&rhs->word_403E8));
    ptree->appendChild("word_403EA", new QMoMTreeItem<uint16_t>(&rhs->word_403EA));
    ptree->appendChild("word_403EC", new QMoMTreeItem<uint16_t>(&rhs->word_403EC));
    ptree->appendChild("word_403EE", new QMoMTreeItem<uint16_t>(&rhs->word_403EE));
    ptree->appendChild("word_403F0", new QMoMTreeItem<uint16_t>(&rhs->word_403F0));
    ptree->appendChild("word_403F2", new QMoMTreeItem<uint16_t>(&rhs->word_403F2));
    ptree->appendChild("word_403F4", new QMoMTreeItem<uint16_t>(&rhs->word_403F4));
    ptree->appendChild("word_403F6", new QMoMTreeItem<uint16_t>(&rhs->word_403F6));
    ptree->appendChild("word_403F8", new QMoMTreeItem<uint16_t>(&rhs->word_403F8));
    ptree->appendChild("word_403FA", new QMoMTreeItem<uint16_t>(&rhs->word_403FA));
    ptree->appendChild("word_403FC", new QMoMTreeItem<uint16_t>(&rhs->word_403FC));
    ptree->appendTree(constructTreeItem(&rhs->word_403FE, "word_403FE"), "");
    ptree->appendChild("word_40402", new QMoMTreeItem<uint16_t>(&rhs->word_40402));
    ptree->appendChild("word_40404", new QMoMTreeItem<uint16_t>(&rhs->word_40404));
    ptree->appendChild("word_40406", new QMoMTreeItem<uint16_t>(&rhs->word_40406));
    ptree->appendChild("word_40408", new QMoMTreeItem<uint16_t>(&rhs->word_40408));
    ptree->appendChild("word_4040A", new QMoMTreeItem<uint16_t>(&rhs->word_4040A));
    ptree->appendChild("word_4040C", new QMoMTreeItem<uint16_t>(&rhs->word_4040C));
    ptree->appendChild("word_4040E", new QMoMTreeItem<uint16_t>(&rhs->word_4040E));
    ptree->appendChild("word_40410", new QMoMTreeItem<uint16_t>(&rhs->word_40410));
    ptree->appendChild("word_40412", new QMoMTreeItem<uint16_t>(&rhs->word_40412));
    ptree->appendChild("word_40414", new QMoMTreeItem<uint16_t>(&rhs->word_40414));
    ptree->appendChild("word_40416", new QMoMTreeItem<uint16_t>(&rhs->word_40416));
    ptree->appendChild("word_40418", new QMoMTreeItem<uint16_t>(&rhs->word_40418));
    ptree->appendChild("word_4041A", new QMoMTreeItem<uint16_t>(&rhs->word_4041A));
    ptree->appendChild("word_4041C", new QMoMTreeItem<uint16_t>(&rhs->word_4041C));
    ptree->appendChild("word_4041E", new QMoMTreeItem<uint16_t>(&rhs->word_4041E));
    ptree->appendChild("word_40420", new QMoMTreeItem<uint16_t>(&rhs->word_40420));
    ptree->appendChild("word_40422", new QMoMTreeItem<uint16_t>(&rhs->word_40422));
    ptree->appendChild("word_40424", new QMoMTreeItem<uint16_t>(&rhs->word_40424));
    ptree->appendChild("word_40426", new QMoMTreeItem<uint16_t>(&rhs->word_40426));
    ptree->appendTree(constructTreeItem(&rhs->word_40428, "word_40428"), "");
    ptree->appendChild("word_4042C", new QMoMTreeItem<uint16_t>(&rhs->word_4042C));
    ptree->appendChild("w_constant_GUESS", new QMoMTreeItem<uint16_t>(&rhs->w_constant_GUESS));
    ptree->appendChild("m_Game_flow", new QMoMTreeItem<eGameState>(&rhs->m_Game_flow));
    ptree->appendChild("word_40432", new QMoMTreeItem<uint16_t>(&rhs->word_40432));
    ptree->appendChild("word_40434", new QMoMTreeItem<uint16_t>(&rhs->word_40434));
    ptree->appendChild("word_40436", new QMoMTreeItem<uint16_t>(&rhs->word_40436));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_events, "m_addr_events"), "");
    ptree->appendChild("w_uts_in_stack_ovrland_GUESS", new QMoMTreeItem<uint16_t>(&rhs->w_uts_in_stack_ovrland_GUESS));
    QMoMTreeItemBase* ptreew_Stack_active_GUESS = ptree;
    if (36 > 3)
    {
        ptreew_Stack_active_GUESS = new QMoMTreeItemBase("w_Stack_active_GUESS");
        ptree->appendTree(ptreew_Stack_active_GUESS, "");
    }
    for (unsigned i = 0; i < 36; ++i)
    {
          std::ostringstream oss;
          oss << "w_Stack_active_GUESS[" << i << "]";
          ptreew_Stack_active_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->w_Stack_active_GUESS[i]));
    }
    QMoMTreeItemBase* ptreebyte_40462 = ptree;
    if (281 > 3)
    {
        ptreebyte_40462 = new QMoMTreeItemBase("byte_40462");
        ptree->appendTree(ptreebyte_40462, "");
    }
    for (unsigned i = 0; i < 281; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40462[" << i << "]";
          ptreebyte_40462->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_40462[i]));
    }
    QMoMTreeItemBase* ptreebyte_4057B = ptree;
    if (21 > 3)
    {
        ptreebyte_4057B = new QMoMTreeItemBase("byte_4057B");
        ptree->appendTree(ptreebyte_4057B, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_4057B[" << i << "]";
          ptreebyte_4057B->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_4057B[i]));
    }
    QMoMTreeItemBase* ptreeb_mess_number = ptree;
    if (82 > 3)
    {
        ptreeb_mess_number = new QMoMTreeItemBase("b_mess_number");
        ptree->appendTree(ptreeb_mess_number, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "b_mess_number[" << i << "]";
          ptreeb_mess_number->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->b_mess_number[i]));
    }
    QMoMTreeItemBase* ptreebyte_405E2 = ptree;
    if (82 > 3)
    {
        ptreebyte_405E2 = new QMoMTreeItemBase("byte_405E2");
        ptree->appendTree(ptreebyte_405E2, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_405E2[" << i << "]";
          ptreebyte_405E2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_405E2[i]));
    }
    QMoMTreeItemBase* ptreebyte_40634 = ptree;
    if (82 > 3)
    {
        ptreebyte_40634 = new QMoMTreeItemBase("byte_40634");
        ptree->appendTree(ptreebyte_40634, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40634[" << i << "]";
          ptreebyte_40634->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_40634[i]));
    }
    QMoMTreeItemBase* ptreebyte_40686 = ptree;
    if (82 > 3)
    {
        ptreebyte_40686 = new QMoMTreeItemBase("byte_40686");
        ptree->appendTree(ptreebyte_40686, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40686[" << i << "]";
          ptreebyte_40686->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_40686[i]));
    }
    QMoMTreeItemBase* ptreebyte_406D8 = ptree;
    if (21 > 3)
    {
        ptreebyte_406D8 = new QMoMTreeItemBase("byte_406D8");
        ptree->appendTree(ptreebyte_406D8, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406D8[" << i << "]";
          ptreebyte_406D8->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_406D8[i]));
    }
    QMoMTreeItemBase* ptreebyte_406ED = ptree;
    if (21 > 3)
    {
        ptreebyte_406ED = new QMoMTreeItemBase("byte_406ED");
        ptree->appendTree(ptreebyte_406ED, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406ED[" << i << "]";
          ptreebyte_406ED->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_406ED[i]));
    }
    QMoMTreeItemBase* ptreebyte_40702 = ptree;
    if (21 > 3)
    {
        ptreebyte_40702 = new QMoMTreeItemBase("byte_40702");
        ptree->appendTree(ptreebyte_40702, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40702[" << i << "]";
          ptreebyte_40702->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_40702[i]));
    }
    QMoMTreeItemBase* ptreebyte_40717 = ptree;
    if (21 > 3)
    {
        ptreebyte_40717 = new QMoMTreeItemBase("byte_40717");
        ptree->appendTree(ptreebyte_40717, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40717[" << i << "]";
          ptreebyte_40717->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->byte_40717[i]));
    }
    ptree->appendChild("byte_4072C", new QMoMTreeItem<uint16_t>(&rhs->byte_4072C));
    ptree->appendChild("w_video_style_CL_BUG_GUESS", new QMoMTreeItem<uint16_t>(&rhs->w_video_style_CL_BUG_GUESS));
    ptree->appendTree(constructTreeItem(&rhs->dword_40730, "dword_40730"), "");
    ptree->appendChild("word_40734", new QMoMTreeItem<uint16_t>(&rhs->word_40734));
    ptree->appendChild("word_40736", new QMoMTreeItem<uint16_t>(&rhs->word_40736));
    ptree->appendChild("word_40738", new QMoMTreeItem<uint16_t>(&rhs->word_40738));
    ptree->appendChild("word_4073A", new QMoMTreeItem<uint16_t>(&rhs->word_4073A));
    ptree->appendTree(constructTreeItem(&rhs->dword_4073C, "dword_4073C"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_40740, "dword_40740"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_terrain_Movement_copy, "m_addr_terrain_Movement_copy"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_40748, "dword_40748"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_Movement, "m_addr_Terrain_Movement"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_Explored, "m_addr_Terrain_Explored"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_Changes, "m_addr_Terrain_Changes"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_Bonuses, "m_addr_Terrain_Bonuses"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Cities, "m_addr_Cities"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Lairs_data, "m_addr_Lairs_data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_tower_attr, "m_addr_tower_attr"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_fortress_data, "m_addr_fortress_data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Nodes_Attr, "m_addr_Nodes_Attr"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_LandMassID, "m_addr_Terrain_LandMassID"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_40774_Terrain, "addr_40774_Terrain"), "");
    ptree->appendTree(constructTreeItem(&rhs->addr_40778_Terrain, "addr_40778_Terrain"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Terrain_Types, "m_addr_Terrain_Types"), "");
    QMoMTreeItemBase* ptreem_addr_Unrest_Table = ptree;
    if (gMAX_RACES > 3)
    {
        ptreem_addr_Unrest_Table = new QMoMTreeItemBase("m_addr_Unrest_Table");
        ptree->appendTree(ptreem_addr_Unrest_Table, "");
    }
    for (unsigned i = 0; i < gMAX_RACES; ++i)
    {
          std::ostringstream oss;
          oss << "m_addr_Unrest_Table[" << i << "]";
          ptreem_addr_Unrest_Table->appendTree(constructTreeItem(&rhs->m_addr_Unrest_Table[i], oss.str().c_str()), "");
    }
    ptree->appendChild("word_407B8", new QMoMTreeItem<uint16_t>(&rhs->word_407B8));
    ptree->appendChild("word_407BA", new QMoMTreeItem<uint16_t>(&rhs->word_407BA));
    ptree->appendChild("word_407BC", new QMoMTreeItem<uint16_t>(&rhs->word_407BC));
    ptree->appendChild("word_407BE", new QMoMTreeItem<uint16_t>(&rhs->word_407BE));
    ptree->appendChild("word_407C0", new QMoMTreeItem<uint16_t>(&rhs->word_407C0));
    ptree->appendChild("m_Vizier_active", new QMoMTreeItem<uint16_t>(&rhs->m_Vizier_active));
    QMoMTreeItemBase* ptreeword_407C4 = ptree;
    if (6 > 3)
    {
        ptreeword_407C4 = new QMoMTreeItemBase("word_407C4");
        ptree->appendTree(ptreeword_407C4, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_407C4[" << i << "]";
          ptreeword_407C4->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->word_407C4[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->dword_407CA, "dword_407CA"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_407CE, "dword_407CE"), "");
    ptree->appendChild("word_407D2", new QMoMTreeItem<uint16_t>(&rhs->word_407D2));
    ptree->appendChild("word_407D4", new QMoMTreeItem<uint16_t>(&rhs->word_407D4));
    ptree->appendChild("word_407D6", new QMoMTreeItem<uint16_t>(&rhs->word_407D6));
    ptree->appendChild("word_407D8", new QMoMTreeItem<uint16_t>(&rhs->word_407D8));
    ptree->appendChild("word_407DA", new QMoMTreeItem<uint16_t>(&rhs->word_407DA));
    ptree->appendChild("word_407DC", new QMoMTreeItem<uint16_t>(&rhs->word_407DC));
    ptree->appendChild("word_407DE", new QMoMTreeItem<uint16_t>(&rhs->word_407DE));
    ptree->appendChild("word_407E0", new QMoMTreeItem<uint16_t>(&rhs->word_407E0));
    ptree->appendChild("word_407E2", new QMoMTreeItem<uint16_t>(&rhs->word_407E2));
    ptree->appendChild("word_407E4", new QMoMTreeItem<uint16_t>(&rhs->word_407E4));
    ptree->appendChild("word_407E6", new QMoMTreeItem<uint16_t>(&rhs->word_407E6));
    ptree->appendChild("word_407E8", new QMoMTreeItem<uint16_t>(&rhs->word_407E8));
    ptree->appendChild("w_AI_stack_nr", new QMoMTreeItem<uint16_t>(&rhs->w_AI_stack_nr));
    QMoMTreeItemBase* ptreeunk_407EC = ptree;
    if (320 > 3)
    {
        ptreeunk_407EC = new QMoMTreeItemBase("unk_407EC");
        ptree->appendTree(ptreeunk_407EC, "");
    }
    for (unsigned i = 0; i < 320; ++i)
    {
          std::ostringstream oss;
          oss << "unk_407EC[" << i << "]";
          ptreeunk_407EC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->unk_407EC[i]));
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
    ptree->appendChild("word_40950", new QMoMTreeItem<uint16_t>(&rhs->word_40950));
    ptree->appendChild("word_40952", new QMoMTreeItem<uint16_t>(&rhs->word_40952));
    ptree->appendChild("word_40954", new QMoMTreeItem<uint16_t>(&rhs->word_40954));
    ptree->appendChild("word_40956", new QMoMTreeItem<uint16_t>(&rhs->word_40956));
    ptree->appendChild("word_40958", new QMoMTreeItem<uint16_t>(&rhs->word_40958));
    ptree->appendChild("word_4095A", new QMoMTreeItem<uint16_t>(&rhs->word_4095A));
    ptree->appendChild("word_4095C", new QMoMTreeItem<uint16_t>(&rhs->word_4095C));
    ptree->appendChild("word_4095E", new QMoMTreeItem<uint16_t>(&rhs->word_4095E));
    ptree->appendChild("word_40960", new QMoMTreeItem<uint16_t>(&rhs->word_40960));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Units, "m_addr_Units"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Chosen_Hero_Names, "m_addr_Chosen_Hero_Names"), "");
    QMoMTreeItemBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new QMoMTreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UNK07 = ptree;
    if (0xBD8E - 0xBB7A > 3)
    {
        ptreem_UNK07 = new QMoMTreeItemBase("m_UNK07");
        ptree->appendTree(ptreem_UNK07, "");
    }
    for (unsigned i = 0; i < 0xBD8E - 0xBB7A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK07[" << i << "]";
          ptreem_UNK07->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK07[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    QMoMTreeItemBase* ptreem_Unk_BF70 = ptree;
    if (0xC190 - 0xBF70 > 3)
    {
        ptreem_Unk_BF70 = new QMoMTreeItemBase("m_Unk_BF70");
        ptree->appendTree(ptreem_Unk_BF70, "");
    }
    for (unsigned i = 0; i < 0xC190 - 0xBF70; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_BF70[" << i << "]";
          ptreem_Unk_BF70->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_BF70[i]));
    }
    ptree->appendChild("m_UnitView_nrLines", new QMoMTreeItem<uint16_t>(&rhs->m_UnitView_nrLines));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_UnitView_Lines, "m_addr_UnitView_Lines"), "");
    QMoMTreeItemBase* ptreem_Unk_C196 = ptree;
    if (0xC51C - 0xC196 > 3)
    {
        ptreem_Unk_C196 = new QMoMTreeItemBase("m_Unk_C196");
        ptree->appendTree(ptreem_Unk_C196, "");
    }
    for (unsigned i = 0; i < 0xC51C - 0xC196; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C196[" << i << "]";
          ptreem_Unk_C196->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C196[i]));
    }
    ptree->appendChild("m_Combat_turn", new QMoMTreeItem<int16_t>(&rhs->m_Combat_turn));
    ptree->appendChild("m_Unk_C51E", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_C51E));
    ptree->appendChild("m_External_battle_condition", new QMoMTreeItem<eBattleCondition>(&rhs->m_External_battle_condition));
    ptree->appendChild("m_Unk_C522", new QMoMTreeItem<uint16_t>(&rhs->m_Unk_C522));
    QMoMTreeItemBase* ptreem_Offsets_Battlefield_battleUnitIDs = ptree;
    if (22 > 3)
    {
        ptreem_Offsets_Battlefield_battleUnitIDs = new QMoMTreeItemBase("m_Offsets_Battlefield_battleUnitIDs");
        ptree->appendTree(ptreem_Offsets_Battlefield_battleUnitIDs, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_Battlefield_battleUnitIDs[" << i << "]";
          ptreem_Offsets_Battlefield_battleUnitIDs->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Offsets_Battlefield_battleUnitIDs[i]));
    }
    QMoMTreeItemBase* ptreem_Unk_C550 = ptree;
    if (0xC582 - 0xC550 > 3)
    {
        ptreem_Unk_C550 = new QMoMTreeItemBase("m_Unk_C550");
        ptree->appendTree(ptreem_Unk_C550, "");
    }
    for (unsigned i = 0; i < 0xC582 - 0xC550; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C550[" << i << "]";
          ptreem_Unk_C550->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C550[i]));
    }
    ptree->appendChild("m_BattleUnit_on_move", new QMoMTreeItem<int16_t>(&rhs->m_BattleUnit_on_move));
    ptree->appendChild("m_Defending_wizard", new QMoMTreeItem<int16_t>(&rhs->m_Defending_wizard));
    ptree->appendChild("m_Attacking_wizard", new QMoMTreeItem<int16_t>(&rhs->m_Attacking_wizard));
    ptree->appendChild("m_Nr_Battle_Units", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_Battle_Units));
    ptree->appendChild("m_BattleUnit_pointed_at", new QMoMTreeItem<int16_t>(&rhs->m_BattleUnit_pointed_at));
    QMoMTreeItemBase* ptreem_Unk_C58A = ptree;
    if (0xC5C2 - 0xC58C > 3)
    {
        ptreem_Unk_C58A = new QMoMTreeItemBase("m_Unk_C58A");
        ptree->appendTree(ptreem_Unk_C58A, "");
    }
    for (unsigned i = 0; i < 0xC5C2 - 0xC58C; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C58A[" << i << "]";
          ptreem_Unk_C58A->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C58A[i]));
    }
    ptree->appendChild("m_Battle_winner", new QMoMTreeItem<int16_t>(&rhs->m_Battle_winner));
    ptree->appendChild("m_Battle_loser", new QMoMTreeItem<int16_t>(&rhs->m_Battle_loser));
    QMoMTreeItemBase* ptreem_Unk_C5C6 = ptree;
    if (0xC5DE - 0xC5C6 > 3)
    {
        ptreem_Unk_C5C6 = new QMoMTreeItemBase("m_Unk_C5C6");
        ptree->appendTree(ptreem_Unk_C5C6, "");
    }
    for (unsigned i = 0; i < 0xC5DE - 0xC5C6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C5C6[" << i << "]";
          ptreem_Unk_C5C6->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C5C6[i]));
    }
    ptree->appendChild("m_YPos_clash", new QMoMTreeItem<int16_t>(&rhs->m_YPos_clash));
    ptree->appendChild("m_XPos_clash", new QMoMTreeItem<int16_t>(&rhs->m_XPos_clash));
    QMoMTreeItemBase* ptreem_Unk_C5E2 = ptree;
    if (0xC8B4 - 0xC5E2 > 3)
    {
        ptreem_Unk_C5E2 = new QMoMTreeItemBase("m_Unk_C5E2");
        ptree->appendTree(ptreem_Unk_C5E2, "");
    }
    for (unsigned i = 0; i < 0xC8B4 - 0xC5E2; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C5E2[" << i << "]";
          ptreem_Unk_C5E2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C5E2[i]));
    }
    ptree->appendChild("m_Battlefield_flags", new QMoMTreeItem<uint16_t>(&rhs->m_Battlefield_flags));
    QMoMTreeItemBase* ptreem_Unk_C8B6 = ptree;
    if (0xC8FA - 0xC8B6 > 3)
    {
        ptreem_Unk_C8B6 = new QMoMTreeItemBase("m_Unk_C8B6");
        ptree->appendTree(ptreem_Unk_C8B6, "");
    }
    for (unsigned i = 0; i < 0xC8FA - 0xC8B6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C8B6[" << i << "]";
          ptreem_Unk_C8B6->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C8B6[i]));
    }
    ptree->appendChild("m_offset_Available_spell_pages", new QMoMTreeItem<uint16_t>(&rhs->m_offset_Available_spell_pages));
    QMoMTreeItemBase* ptreem_Unk_C8FC = ptree;
    if (0xC910 - 0xC8FC > 3)
    {
        ptreem_Unk_C8FC = new QMoMTreeItemBase("m_Unk_C8FC");
        ptree->appendTree(ptreem_Unk_C8FC, "");
    }
    for (unsigned i = 0; i < 0xC910 - 0xC8FC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C8FC[" << i << "]";
          ptreem_Unk_C8FC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C8FC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Hero_Spells, "m_addr_Hero_Spells"), "");
    ptree->appendChild("m_Nr_available_spell_pages", new QMoMTreeItem<uint16_t>(&rhs->m_Nr_available_spell_pages));
    QMoMTreeItemBase* ptreem_Unk_C916 = ptree;
    if (0xC924 - 0xC916 > 3)
    {
        ptreem_Unk_C916 = new QMoMTreeItemBase("m_Unk_C916");
        ptree->appendTree(ptreem_Unk_C916, "");
    }
    for (unsigned i = 0; i < 0xC924 - 0xC916; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C916[" << i << "]";
          ptreem_Unk_C916->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C916[i]));
    }
    ptree->appendChild("m_First_visible_available_spell_page", new QMoMTreeItem<uint16_t>(&rhs->m_First_visible_available_spell_page));
    QMoMTreeItemBase* ptreem_Unk_C926 = ptree;
    if (0xD15A - 0xC926 > 3)
    {
        ptreem_Unk_C926 = new QMoMTreeItemBase("m_Unk_C926");
        ptree->appendTree(ptreem_Unk_C926, "");
    }
    for (unsigned i = 0; i < 0xD15A - 0xC926; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C926[" << i << "]";
          ptreem_Unk_C926->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_C926[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_figures_256, "m_addr_Battle_figures_256"), "");
    ptree->appendChild("m_Nr_figures_on_battlefield", new QMoMTreeItem<int16_t>(&rhs->m_Nr_figures_on_battlefield));
    QMoMTreeItemBase* ptreem_Unk_D160 = ptree;
    if (0xD188 - 0xD160 > 3)
    {
        ptreem_Unk_D160 = new QMoMTreeItemBase("m_Unk_D160");
        ptree->appendTree(ptreem_Unk_D160, "");
    }
    for (unsigned i = 0; i < 0xD188 - 0xD160; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_D160[" << i << "]";
          ptreem_Unk_D160->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_D160[i]));
    }
    ptree->appendChild("m_Battle_activetile_anim", new QMoMTreeItem<uint16_t>(&rhs->m_Battle_activetile_anim));
    ptree->appendChild("m_Battle_tileselection_anim", new QMoMTreeItem<uint16_t>(&rhs->m_Battle_tileselection_anim));
    QMoMTreeItemBase* ptreem_Unk_D18C = ptree;
    if (0xD49A - 0xD18C > 3)
    {
        ptreem_Unk_D18C = new QMoMTreeItemBase("m_Unk_D18C");
        ptree->appendTree(ptreem_Unk_D18C, "");
    }
    for (unsigned i = 0; i < 0xD49A - 0xD18C; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_D18C[" << i << "]";
          ptreem_Unk_D18C->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_D18C[i]));
    }
    QMoMTreeItemBase* ptreem_NEAR_HEAP = ptree;
    if (0x1130 > 3)
    {
        ptreem_NEAR_HEAP = new QMoMTreeItemBase("m_NEAR_HEAP");
        ptree->appendTree(ptreem_NEAR_HEAP, "");
    }
    for (unsigned i = 0; i < 0x1130; ++i)
    {
          std::ostringstream oss;
          oss << "m_NEAR_HEAP[" << i << "]";
          ptreem_NEAR_HEAP->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_NEAR_HEAP[i]));
    }
    QMoMTreeItemBase* ptreem_Unk_E5CA = ptree;
    if (0xE5FC - 0xE5CA > 3)
    {
        ptreem_Unk_E5CA = new QMoMTreeItemBase("m_Unk_E5CA");
        ptree->appendTree(ptreem_Unk_E5CA, "");
    }
    for (unsigned i = 0; i < 0xE5FC - 0xE5CA; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E5CA[" << i << "]";
          ptreem_Unk_E5CA->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_E5CA[i]));
    }
    QMoMTreeItemBase* ptreem_lbx_filenames_x_0C = ptree;
    if (0x10 > 3)
    {
        ptreem_lbx_filenames_x_0C = new QMoMTreeItemBase("m_lbx_filenames_x_0C");
        ptree->appendTree(ptreem_lbx_filenames_x_0C, "");
    }
    for (unsigned i = 0; i < 0x10; ++i)
    {
          std::ostringstream oss;
          oss << "m_lbx_filenames_x_0C[" << i << "]";
          ptreem_lbx_filenames_x_0C->appendTree(constructTreeItem(&rhs->m_lbx_filenames_x_0C[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Unk_E6BC = ptree;
    if (0xEA54 - 0xE6BC > 3)
    {
        ptreem_Unk_E6BC = new QMoMTreeItemBase("m_Unk_E6BC");
        ptree->appendTree(ptreem_Unk_E6BC, "");
    }
    for (unsigned i = 0; i < 0xEA54 - 0xE6BC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E6BC[" << i << "]";
          ptreem_Unk_E6BC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Unk_E6BC[i]));
    }
    QMoMTreeItemBase* ptreem_PARALIGN09 = ptree;
    if (0x0C > 3)
    {
        ptreem_PARALIGN09 = new QMoMTreeItemBase("m_PARALIGN09");
        ptree->appendTree(ptreem_PARALIGN09, "");
    }
    for (unsigned i = 0; i < 0x0C; ++i)
    {
          std::ostringstream oss;
          oss << "m_PARALIGN09[" << i << "]";
          ptreem_PARALIGN09->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_PARALIGN09[i]));
    }
    QMoMTreeItemBase* ptreem_StackSegment = ptree;
    if (0x40 > 3)
    {
        ptreem_StackSegment = new QMoMTreeItemBase("m_StackSegment");
        ptree->appendTree(ptreem_StackSegment, "");
    }
    for (unsigned i = 0; i < 0x40; ++i)
    {
          std::ostringstream oss;
          oss << "m_StackSegment[" << i << "]";
          ptreem_StackSegment->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_StackSegment[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(MoMMagicDataSegment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<MoMMagicDataSegment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new QMoMTreeItem<char[47]>(rhs->m_DataSegmentStart));
    QMoMTreeItemBase* ptreem_UNK_2F = ptree;
    if (0x2AD0 - 47 > 3)
    {
        ptreem_UNK_2F = new QMoMTreeItemBase("m_UNK_2F");
        ptree->appendTree(ptreem_UNK_2F, "");
    }
    for (unsigned i = 0; i < 0x2AD0 - 47; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2F[" << i << "]";
          ptreem_UNK_2F->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_2F[i]));
    }
    QMoMTreeItemBase* ptreem_Wizard_Types = ptree;
    if (ePortrait_MAX > 3)
    {
        ptreem_Wizard_Types = new QMoMTreeItemBase("m_Wizard_Types");
        ptree->appendTree(ptreem_Wizard_Types, "");
    }
    for (unsigned i = 0; i < ePortrait_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizard_Types[" << i << "]";
          ptreem_Wizard_Types->appendTree(constructTreeItem(&rhs->m_Wizard_Types[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UNK_2C1A = ptree;
    if (10 > 3)
    {
        ptreem_UNK_2C1A = new QMoMTreeItemBase("m_UNK_2C1A");
        ptree->appendTree(ptreem_UNK_2C1A, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2C1A[" << i << "]";
          ptreem_UNK_2C1A->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_UNK_2C1A[i]));
    }
    QMoMTreeItemBase* ptreem_Nr_spell_choices = ptree;
    if (10 > 3)
    {
        ptreem_Nr_spell_choices = new QMoMTreeItemBase("m_Nr_spell_choices");
        ptree->appendTree(ptreem_Nr_spell_choices, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Nr_spell_choices[" << i << "]";
          ptreem_Nr_spell_choices->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_Nr_spell_choices[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_2C40 = ptree;
    if (0x2C6A - 0x2C42 > 3)
    {
        ptreem_UNK_2C40 = new QMoMTreeItemBase("m_UNK_2C40");
        ptree->appendTree(ptreem_UNK_2C40, "");
    }
    for (unsigned i = 0; i < 0x2C6A - 0x2C42; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2C40[" << i << "]";
          ptreem_UNK_2C40->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_2C40[i]));
    }
    QMoMTreeItemBase* ptreem_Preselected_spell_choices = ptree;
    if (65 > 3)
    {
        ptreem_Preselected_spell_choices = new QMoMTreeItemBase("m_Preselected_spell_choices");
        ptree->appendTree(ptreem_Preselected_spell_choices, "");
    }
    for (unsigned i = 0; i < 65; ++i)
    {
          std::ostringstream oss;
          oss << "m_Preselected_spell_choices[" << i << "]";
          ptreem_Preselected_spell_choices->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell16>(&rhs->m_Preselected_spell_choices[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_2CEC = ptree;
    if (0x3067 - 0x2CEC > 3)
    {
        ptreem_UNK_2CEC = new QMoMTreeItemBase("m_UNK_2CEC");
        ptree->appendTree(ptreem_UNK_2CEC, "");
    }
    for (unsigned i = 0; i < 0x3067 - 0x2CEC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_2CEC[" << i << "]";
          ptreem_UNK_2CEC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_2CEC[i]));
    }
    ptree->appendChild("m_Copyright1_and_Version", new QMoMTreeItem<char[41]>(rhs->m_Copyright1_and_Version));
    QMoMTreeItemBase* ptreem_UNK_3090 = ptree;
    if (0x35D0 - 0x3090 > 3)
    {
        ptreem_UNK_3090 = new QMoMTreeItemBase("m_UNK_3090");
        ptree->appendTree(ptreem_UNK_3090, "");
    }
    for (unsigned i = 0; i < 0x35D0 - 0x3090; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_3090[" << i << "]";
          ptreem_UNK_3090->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_3090[i]));
    }
    QMoMTreeItemBase* ptreem_Hero_Stats_Initializers = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Hero_Stats_Initializers = new QMoMTreeItemBase("m_Hero_Stats_Initializers");
        ptree->appendTree(ptreem_Hero_Stats_Initializers, "");
    }
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Hero_Stats_Initializers[" << i << "]";
          ptreem_Hero_Stats_Initializers->appendTree(constructTreeItem(&rhs->m_Hero_Stats_Initializers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_UNK_3846 = ptree;
    if (0x389A - 0x3846 > 3)
    {
        ptreem_UNK_3846 = new QMoMTreeItemBase("m_UNK_3846");
        ptree->appendTree(ptreem_UNK_3846, "");
    }
    for (unsigned i = 0; i < 0x389A - 0x3846; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_3846[" << i << "]";
          ptreem_UNK_3846->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_3846[i]));
    }
    ptree->appendChild("m_Copyright2_and_Version", new QMoMTreeItem<char[41]>(rhs->m_Copyright2_and_Version));
    QMoMTreeItemBase* ptreem_UNK_38C3 = ptree;
    if (0x6900 - 0x38C3 > 3)
    {
        ptreem_UNK_38C3 = new QMoMTreeItemBase("m_UNK_38C3");
        ptree->appendTree(ptreem_UNK_38C3, "");
    }
    for (unsigned i = 0; i < 0x6900 - 0x38C3; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_38C3[" << i << "]";
          ptreem_UNK_38C3->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_38C3[i]));
    }
    QMoMTreeItemBase* ptreem_Wizards = ptree;
    if (6 > 3)
    {
        ptreem_Wizards = new QMoMTreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Spells_selected_of_Realm = ptree;
    if (150 > 3)
    {
        ptreem_Spells_selected_of_Realm = new QMoMTreeItemBase("m_Spells_selected_of_Realm");
        ptree->appendTree(ptreem_Spells_selected_of_Realm, "");
    }
    for (unsigned i = 0; i < 150; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_selected_of_Realm[" << i << "]";
          ptreem_Spells_selected_of_Realm->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell16>(&rhs->m_Spells_selected_of_Realm[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_86DC = ptree;
    if (0x87C4 - 0x86DC > 3)
    {
        ptreem_UNK_86DC = new QMoMTreeItemBase("m_UNK_86DC");
        ptree->appendTree(ptreem_UNK_86DC, "");
    }
    for (unsigned i = 0; i < 0x87C4 - 0x86DC; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_86DC[" << i << "]";
          ptreem_UNK_86DC->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_86DC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    QMoMTreeItemBase* ptreem_UNK_89A6 = ptree;
    if (0x8A14 - 0x89A6 > 3)
    {
        ptreem_UNK_89A6 = new QMoMTreeItemBase("m_UNK_89A6");
        ptree->appendTree(ptreem_UNK_89A6, "");
    }
    for (unsigned i = 0; i < 0x8A14 - 0x89A6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_89A6[" << i << "]";
          ptreem_UNK_89A6->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_89A6[i]));
    }
    QMoMTreeItemBase* ptreem_Spell_Selected = ptree;
    if (eSpell_MAX > 3)
    {
        ptreem_Spell_Selected = new QMoMTreeItemBase("m_Spell_Selected");
        ptree->appendTree(ptreem_Spell_Selected, "");
    }
    for (unsigned i = 0; i < eSpell_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell_Selected[" << i << "]";
          ptreem_Spell_Selected->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell>(&rhs->m_Spell_Selected[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_8AEB = ptree;
    if (0x8D52 - 0x8AEB > 3)
    {
        ptreem_UNK_8AEB = new QMoMTreeItemBase("m_UNK_8AEB");
        ptree->appendTree(ptreem_UNK_8AEB, "");
    }
    for (unsigned i = 0; i < 0x8D52 - 0x8AEB; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8AEB[" << i << "]";
          ptreem_UNK_8AEB->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_8AEB[i]));
    }
    QMoMTreeItemBase* ptreem_Spells_Known_Realm = ptree;
    if (66 > 3)
    {
        ptreem_Spells_Known_Realm = new QMoMTreeItemBase("m_Spells_Known_Realm");
        ptree->appendTree(ptreem_Spells_Known_Realm, "");
    }
    for (unsigned i = 0; i < 66; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm[" << i << "]";
          ptreem_Spells_Known_Realm->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Spells_Known_Realm[i]));
    }
    ptree->appendChild("m_UNK_8DD6", new QMoMTreeItem<uint16_t>(&rhs->m_UNK_8DD6));
    ptree->appendChild("m_Sorcery_Picks_Divider", new QMoMTreeItem<uint16_t>(&rhs->m_Sorcery_Picks_Divider));
    ptree->appendChild("m_Nature_Picks_Divider", new QMoMTreeItem<uint16_t>(&rhs->m_Nature_Picks_Divider));
    ptree->appendChild("m_Chaos_Picks_Divider", new QMoMTreeItem<uint16_t>(&rhs->m_Chaos_Picks_Divider));
    ptree->appendChild("m_Death_Picks_Divider", new QMoMTreeItem<uint16_t>(&rhs->m_Death_Picks_Divider));
    ptree->appendChild("m_Life_Picks_Divider", new QMoMTreeItem<uint16_t>(&rhs->m_Life_Picks_Divider));
    QMoMTreeItemBase* ptreem_UNK_8DE2 = ptree;
    if (2 > 3)
    {
        ptreem_UNK_8DE2 = new QMoMTreeItemBase("m_UNK_8DE2");
        ptree->appendTree(ptreem_UNK_8DE2, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8DE2[" << i << "]";
          ptreem_UNK_8DE2->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_UNK_8DE2[i]));
    }
    QMoMTreeItemBase* ptreem_Spells_Known_Realm_Indexed = ptree;
    if (15 > 3)
    {
        ptreem_Spells_Known_Realm_Indexed = new QMoMTreeItemBase("m_Spells_Known_Realm_Indexed");
        ptree->appendTree(ptreem_Spells_Known_Realm_Indexed, "");
    }
    for (unsigned i = 0; i < 15; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm_Indexed[" << i << "]";
          ptreem_Spells_Known_Realm_Indexed->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Spells_Known_Realm_Indexed[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_8E04 = ptree;
    if (0x8E48 - 0x8E04 > 3)
    {
        ptreem_UNK_8E04 = new QMoMTreeItemBase("m_UNK_8E04");
        ptree->appendTree(ptreem_UNK_8E04, "");
    }
    for (unsigned i = 0; i < 0x8E48 - 0x8E04; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E04[" << i << "]";
          ptreem_UNK_8E04->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_8E04[i]));
    }
    ptree->appendChild("m_Select_Wizard_Shown", new QMoMTreeItem<ePortrait>(&rhs->m_Select_Wizard_Shown));
    QMoMTreeItemBase* ptreem_UNK_8E49 = ptree;
    if (0x8E94 - 0x8E49 > 3)
    {
        ptreem_UNK_8E49 = new QMoMTreeItemBase("m_UNK_8E49");
        ptree->appendTree(ptreem_UNK_8E49, "");
    }
    for (unsigned i = 0; i < 0x8E94 - 0x8E49; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E49[" << i << "]";
          ptreem_UNK_8E49->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_8E49[i]));
    }
    ptree->appendChild("m_Total_Picks_Left", new QMoMTreeItem<uint16_t>(&rhs->m_Total_Picks_Left));
    QMoMTreeItemBase* ptreem_UNK_8E96 = ptree;
    if (0xAA4A - 0x8E96 > 3)
    {
        ptreem_UNK_8E96 = new QMoMTreeItemBase("m_UNK_8E96");
        ptree->appendTree(ptreem_UNK_8E96, "");
    }
    for (unsigned i = 0; i < 0xAA4A - 0x8E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_8E96[" << i << "]";
          ptreem_UNK_8E96->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_8E96[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_AA4A = ptree;
    if (0xFE68 - 0xAA4A > 3)
    {
        ptreem_UNK_AA4A = new QMoMTreeItemBase("m_UNK_AA4A");
        ptree->appendTree(ptreem_UNK_AA4A, "");
    }
    for (unsigned i = 0; i < 0xFE68 - 0xAA4A; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_AA4A[" << i << "]";
          ptreem_UNK_AA4A->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_AA4A[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_1", new QMoMTreeItem<char[11]>(rhs->m_Wizards_Name_Shown_1));
    QMoMTreeItemBase* ptreem_UNK_FE73 = ptree;
    if (0xFEC2 - 0xFE73 > 3)
    {
        ptreem_UNK_FE73 = new QMoMTreeItemBase("m_UNK_FE73");
        ptree->appendTree(ptreem_UNK_FE73, "");
    }
    for (unsigned i = 0; i < 0xFEC2 - 0xFE73; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_FE73[" << i << "]";
          ptreem_UNK_FE73->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK_FE73[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_2", new QMoMTreeItem<char[11]>(rhs->m_Wizards_Name_Shown_2));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Movement_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Movement_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Movement_Flags maskCavalry;
    memset(&maskCavalry, '\0', sizeof(maskCavalry));
    maskCavalry.Cavalry = 1;
    if (1 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCavalry));
    else if (2 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCavalry));
    else
        ptree->appendChild("Cavalry", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCavalry));
    Movement_Flags maskSailing;
    memset(&maskSailing, '\0', sizeof(maskSailing));
    maskSailing.Sailing = 1;
    if (1 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSailing));
    else if (2 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSailing));
    else
        ptree->appendChild("Sailing", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSailing));
    Movement_Flags maskSwimming;
    memset(&maskSwimming, '\0', sizeof(maskSwimming));
    maskSwimming.Swimming = 1;
    if (1 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSwimming));
    else if (2 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSwimming));
    else
        ptree->appendChild("Swimming", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSwimming));
    Movement_Flags maskFlying;
    memset(&maskFlying, '\0', sizeof(maskFlying));
    maskFlying.Flying = 1;
    if (1 == sizeof(maskFlying))
        ptree->appendChild("Flying", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlying));
    else if (2 == sizeof(maskFlying))
        ptree->appendChild("Flying", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlying));
    else
        ptree->appendChild("Flying", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlying));
    Movement_Flags maskTeleporting;
    memset(&maskTeleporting, '\0', sizeof(maskTeleporting));
    maskTeleporting.Teleporting = 1;
    if (1 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTeleporting));
    else if (2 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTeleporting));
    else
        ptree->appendChild("Teleporting", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTeleporting));
    Movement_Flags maskForester;
    memset(&maskForester, '\0', sizeof(maskForester));
    maskForester.Forester = 1;
    if (1 == sizeof(maskForester))
        ptree->appendChild("Forester", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskForester));
    else if (2 == sizeof(maskForester))
        ptree->appendChild("Forester", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskForester));
    else
        ptree->appendChild("Forester", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskForester));
    Movement_Flags maskMountaineer;
    memset(&maskMountaineer, '\0', sizeof(maskMountaineer));
    maskMountaineer.Mountaineer = 1;
    if (1 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMountaineer));
    else if (2 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMountaineer));
    else
        ptree->appendChild("Mountaineer", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMountaineer));
    Movement_Flags maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 1;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Node_Attr* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Node_Attr>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Power_Node", new QMoMTreeItem<uint8_t>(&rhs->m_Power_Node));
    QMoMTreeItemBase* ptreem_XPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_XPos_Mana = new QMoMTreeItemBase("m_XPos_Mana");
        ptree->appendTree(ptreem_XPos_Mana, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_XPos_Mana[" << i << "]";
          ptreem_XPos_Mana->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_XPos_Mana[i]));
    }
    QMoMTreeItemBase* ptreem_YPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_YPos_Mana = new QMoMTreeItemBase("m_YPos_Mana");
        ptree->appendTree(ptreem_YPos_Mana, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_YPos_Mana[" << i << "]";
          ptreem_YPos_Mana->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_YPos_Mana[i]));
    }
    ptree->appendChild("m_Node_Type", new QMoMTreeItem<eNode_Type>(&rhs->m_Node_Type));
    ptree->appendChild("m_Status", new QMoMTreeItem<uint8_t>(&rhs->m_Status));
    ptree->appendChild("m_Unk_2F", new QMoMTreeItem<uint8_t>(&rhs->m_Unk_2F));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Race_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Race_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new QMoMTreeItem<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Number_of_prohibited_buildings", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_prohibited_buildings));
    QMoMTreeItemBase* ptreem_Prohibited_buildings = ptree;
    if (7 > 3)
    {
        ptreem_Prohibited_buildings = new QMoMTreeItemBase("m_Prohibited_buildings");
        ptree->appendTree(ptreem_Prohibited_buildings, "");
    }
    for (unsigned i = 0; i < 7; ++i)
    {
          std::ostringstream oss;
          oss << "m_Prohibited_buildings[" << i << "]";
          ptreem_Prohibited_buildings->appendChild(oss.str().c_str(), new QMoMTreeItem<eBuilding>(&rhs->m_Prohibited_buildings[i]));
    }
    ptree->appendChild("m_Outpost_growth_probability", new QMoMTreeItem<uint16_t>(&rhs->m_Outpost_growth_probability));
    ptree->appendChild("m_City_population_growth_modifier", new QMoMTreeItem<int16_t>(&rhs->m_City_population_growth_modifier));
    ptree->appendChild("m_Housing_picture", new QMoMTreeItem<uint16_t>(&rhs->m_Housing_picture));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(SaveGame* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<SaveGame>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_List_Hero_stats = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_List_Hero_stats = new QMoMTreeItemBase("m_List_Hero_stats");
        ptree->appendTree(ptreem_List_Hero_stats, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_List_Hero_stats[" << i << "]";
          ptreem_List_Hero_stats->appendTree(constructTreeItem(&rhs->m_List_Hero_stats[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    QMoMTreeItemBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new QMoMTreeItemBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Map_Tiles, "m_Map_Tiles"), "");
    QMoMTreeItemBase* ptreem_Items = ptree;
    if (128 > 3)
    {
        ptreem_Items = new QMoMTreeItemBase("m_Items");
        ptree->appendTree(ptreem_Items, "");
    }
    for (unsigned i = 0; i < 128; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items[" << i << "]";
          ptreem_Items->appendTree(constructTreeItem(&rhs->m_Items[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Item_Trashcan = ptree;
    if (10 > 3)
    {
        ptreem_Item_Trashcan = new QMoMTreeItemBase("m_Item_Trashcan");
        ptree->appendTree(ptreem_Item_Trashcan, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Trashcan[" << i << "]";
          ptreem_Item_Trashcan->appendTree(constructTreeItem(&rhs->m_Item_Trashcan[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Cities = ptree;
    if (gMAX_CITIES > 3)
    {
        ptreem_Cities = new QMoMTreeItemBase("m_Cities");
        ptree->appendTree(ptreem_Cities, "");
    }
    for (unsigned i = 0; i < gMAX_CITIES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Cities[" << i << "]";
          ptreem_Cities->appendTree(constructTreeItem(&rhs->m_Cities[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Unit = ptree;
    if (1000 > 3)
    {
        ptreem_Unit = new QMoMTreeItemBase("m_Unit");
        ptree->appendTree(ptreem_Unit, "");
    }
    for (unsigned i = 0; i < 1000; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unit[" << i << "]";
          ptreem_Unit->appendTree(constructTreeItem(&rhs->m_Unit[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_Units_Trashcan_GUESS = ptree;
    if (9 > 3)
    {
        ptreem_Units_Trashcan_GUESS = new QMoMTreeItemBase("m_Units_Trashcan_GUESS");
        ptree->appendTree(ptreem_Units_Trashcan_GUESS, "");
    }
    for (unsigned i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_Units_Trashcan_GUESS[" << i << "]";
          ptreem_Units_Trashcan_GUESS->appendTree(constructTreeItem(&rhs->m_Units_Trashcan_GUESS[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Map_Attr, "m_Map_Attr"), "");
    ptree->appendChild("m_Grand_Vizier", new QMoMTreeItem<eGrand_Vizier>(&rhs->m_Grand_Vizier));
    QMoMTreeItemBase* ptreem_Items_in_Game = ptree;
    if (250 > 3)
    {
        ptreem_Items_in_Game = new QMoMTreeItemBase("m_Items_in_Game");
        ptree->appendTree(ptreem_Items_in_Game, "");
    }
    for (unsigned i = 0; i < 250; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_in_Game[" << i << "]";
          ptreem_Items_in_Game->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Items_in_Game[i]));
    }
    QMoMTreeItemBase* ptreem_Hero_Choices = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Hero_Choices = new QMoMTreeItemBase("m_Hero_Choices");
        ptree->appendTree(ptreem_Hero_Choices, "");
    }
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Hero_Choices[" << i << "]";
          ptreem_Hero_Choices->appendTree(constructTreeItem(&rhs->m_Hero_Choices[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Skills* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Skills>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Alchemy", new QMoMTreeItem<eYesNo8>(&rhs->Alchemy));
    ptree->appendChild("Warlord", new QMoMTreeItem<eYesNo8>(&rhs->Warlord));
    ptree->appendChild("Chaos_Master", new QMoMTreeItem<eYesNo8>(&rhs->Chaos_Master));
    ptree->appendChild("Nature_Master", new QMoMTreeItem<eYesNo8>(&rhs->Nature_Master));
    ptree->appendChild("Sorcery_Master", new QMoMTreeItem<eYesNo8>(&rhs->Sorcery_Master));
    ptree->appendChild("Infernal_Power", new QMoMTreeItem<eYesNo8>(&rhs->Infernal_Power));
    ptree->appendChild("Divine_Power", new QMoMTreeItem<eYesNo8>(&rhs->Divine_Power));
    ptree->appendChild("Sage_Master", new QMoMTreeItem<eYesNo8>(&rhs->Sage_Master));
    ptree->appendChild("Channeller", new QMoMTreeItem<eYesNo8>(&rhs->Channeller));
    ptree->appendChild("Myrran", new QMoMTreeItem<eYesNo8>(&rhs->Myrran));
    ptree->appendChild("Archmage", new QMoMTreeItem<eYesNo8>(&rhs->Archmage));
    ptree->appendChild("Mana_Focusing", new QMoMTreeItem<eYesNo8>(&rhs->Mana_Focusing));
    ptree->appendChild("Node_Mastery", new QMoMTreeItem<eYesNo8>(&rhs->Node_Mastery));
    ptree->appendChild("Famous", new QMoMTreeItem<eYesNo8>(&rhs->Famous));
    ptree->appendChild("Runemaster", new QMoMTreeItem<eYesNo8>(&rhs->Runemaster));
    ptree->appendChild("Conjurer", new QMoMTreeItem<eYesNo8>(&rhs->Conjurer));
    ptree->appendChild("Charismatic", new QMoMTreeItem<eYesNo8>(&rhs->Charismatic));
    ptree->appendChild("Artificer", new QMoMTreeItem<eYesNo8>(&rhs->Artificer));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Spell_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Spell_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_SpellName", new QMoMTreeItem<char[19]>(rhs->m_SpellName));
    ptree->appendChild("m_Spell_desirability", new QMoMTreeItem<int16_t>(&rhs->m_Spell_desirability));
    ptree->appendChild("m_Spell_Category", new QMoMTreeItem<eSpellCategory>(&rhs->m_Spell_Category));
    ptree->appendChild("m_Section_in_spell_book", new QMoMTreeItem<eSpell_Type>(&rhs->m_Section_in_spell_book));
    ptree->appendChild("m_Magic_Realm", new QMoMTreeItem<eRealm_Type>(&rhs->m_Magic_Realm));
    ptree->appendChild("m_Casting_eligibility", new QMoMTreeItem<int8_t>(&rhs->m_Casting_eligibility));
    ptree->appendChild("m_UNK01", new QMoMTreeItem<int8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Casting_cost", new QMoMTreeItem<uint16_t>(&rhs->m_Casting_cost));
    ptree->appendChild("m_Research_cost", new QMoMTreeItem<uint16_t>(&rhs->m_Research_cost));
    ptree->appendChild("m_Sound_effect_when_casting_spell", new QMoMTreeItem<int16_t>(&rhs->m_Sound_effect_when_casting_spell));
    QMoMTreeItemBase* ptreem_Parameters = ptree;
    if (4 > 3)
    {
        ptreem_Parameters = new QMoMTreeItemBase("m_Parameters");
        ptree->appendTree(ptreem_Parameters, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Parameters[" << i << "]";
          ptreem_Parameters->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Parameters[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Spells_Cast_in_Battle* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Spells_Cast_in_Battle>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreeTrue_Light = ptree;
    if (2 > 3)
    {
        ptreeTrue_Light = new QMoMTreeItemBase("True_Light");
        ptree->appendTree(ptreeTrue_Light, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "True_Light[" << i << "]";
          ptreeTrue_Light->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->True_Light[i]));
    }
    QMoMTreeItemBase* ptreeDarkness = ptree;
    if (2 > 3)
    {
        ptreeDarkness = new QMoMTreeItemBase("Darkness");
        ptree->appendTree(ptreeDarkness, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Darkness[" << i << "]";
          ptreeDarkness->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Darkness[i]));
    }
    QMoMTreeItemBase* ptreeWarp_Reality = ptree;
    if (2 > 3)
    {
        ptreeWarp_Reality = new QMoMTreeItemBase("Warp_Reality");
        ptree->appendTree(ptreeWarp_Reality, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Warp_Reality[" << i << "]";
          ptreeWarp_Reality->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Warp_Reality[i]));
    }
    QMoMTreeItemBase* ptreeBlack_Prayer = ptree;
    if (2 > 3)
    {
        ptreeBlack_Prayer = new QMoMTreeItemBase("Black_Prayer");
        ptree->appendTree(ptreeBlack_Prayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Black_Prayer[" << i << "]";
          ptreeBlack_Prayer->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Black_Prayer[i]));
    }
    QMoMTreeItemBase* ptreeWrack = ptree;
    if (2 > 3)
    {
        ptreeWrack = new QMoMTreeItemBase("Wrack");
        ptree->appendTree(ptreeWrack, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Wrack[" << i << "]";
          ptreeWrack->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Wrack[i]));
    }
    QMoMTreeItemBase* ptreeMetal_Fires = ptree;
    if (2 > 3)
    {
        ptreeMetal_Fires = new QMoMTreeItemBase("Metal_Fires");
        ptree->appendTree(ptreeMetal_Fires, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Metal_Fires[" << i << "]";
          ptreeMetal_Fires->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Metal_Fires[i]));
    }
    QMoMTreeItemBase* ptreePrayer = ptree;
    if (2 > 3)
    {
        ptreePrayer = new QMoMTreeItemBase("Prayer");
        ptree->appendTree(ptreePrayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Prayer[" << i << "]";
          ptreePrayer->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Prayer[i]));
    }
    QMoMTreeItemBase* ptreeHigh_Prayer = ptree;
    if (2 > 3)
    {
        ptreeHigh_Prayer = new QMoMTreeItemBase("High_Prayer");
        ptree->appendTree(ptreeHigh_Prayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "High_Prayer[" << i << "]";
          ptreeHigh_Prayer->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->High_Prayer[i]));
    }
    QMoMTreeItemBase* ptreeTerror = ptree;
    if (2 > 3)
    {
        ptreeTerror = new QMoMTreeItemBase("Terror");
        ptree->appendTree(ptreeTerror, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Terror[" << i << "]";
          ptreeTerror->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Terror[i]));
    }
    QMoMTreeItemBase* ptreeCall_Lightning = ptree;
    if (2 > 3)
    {
        ptreeCall_Lightning = new QMoMTreeItemBase("Call_Lightning");
        ptree->appendTree(ptreeCall_Lightning, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Call_Lightning[" << i << "]";
          ptreeCall_Lightning->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Call_Lightning[i]));
    }
    QMoMTreeItemBase* ptreeCounter_Magic = ptree;
    if (2 > 3)
    {
        ptreeCounter_Magic = new QMoMTreeItemBase("Counter_Magic");
        ptree->appendTree(ptreeCounter_Magic, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Counter_Magic[" << i << "]";
          ptreeCounter_Magic->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Counter_Magic[i]));
    }
    QMoMTreeItemBase* ptreeMass_Invisibility = ptree;
    if (2 > 3)
    {
        ptreeMass_Invisibility = new QMoMTreeItemBase("Mass_Invisibility");
        ptree->appendTree(ptreeMass_Invisibility, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mass_Invisibility[" << i << "]";
          ptreeMass_Invisibility->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Mass_Invisibility[i]));
    }
    QMoMTreeItemBase* ptreeEntangle = ptree;
    if (2 > 3)
    {
        ptreeEntangle = new QMoMTreeItemBase("Entangle");
        ptree->appendTree(ptreeEntangle, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Entangle[" << i << "]";
          ptreeEntangle->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Entangle[i]));
    }
    QMoMTreeItemBase* ptreeMana_Leak = ptree;
    if (2 > 3)
    {
        ptreeMana_Leak = new QMoMTreeItemBase("Mana_Leak");
        ptree->appendTree(ptreeMana_Leak, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mana_Leak[" << i << "]";
          ptreeMana_Leak->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Mana_Leak[i]));
    }
    QMoMTreeItemBase* ptreeBlur = ptree;
    if (2 > 3)
    {
        ptreeBlur = new QMoMTreeItemBase("Blur");
        ptree->appendTree(ptreeBlur, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Blur[" << i << "]";
          ptreeBlur->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->Blur[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Spells_Known* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Spells_Known>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("No_spell", new QMoMTreeItem<eSpellKnown>(&rhs->No_spell));
    ptree->appendChild("Earth_to_Mud", new QMoMTreeItem<eSpellKnown>(&rhs->Earth_to_Mud));
    ptree->appendChild("Resist_Elements", new QMoMTreeItem<eSpellKnown>(&rhs->Resist_Elements));
    ptree->appendChild("Wall_of_Stone", new QMoMTreeItem<eSpellKnown>(&rhs->Wall_of_Stone));
    ptree->appendChild("Giant_Strength", new QMoMTreeItem<eSpellKnown>(&rhs->Giant_Strength));
    ptree->appendChild("Web", new QMoMTreeItem<eSpellKnown>(&rhs->Web));
    ptree->appendChild("War_Bears", new QMoMTreeItem<eSpellKnown>(&rhs->War_Bears));
    ptree->appendChild("Stone_Skin", new QMoMTreeItem<eSpellKnown>(&rhs->Stone_Skin));
    ptree->appendChild("Water_Walking", new QMoMTreeItem<eSpellKnown>(&rhs->Water_Walking));
    ptree->appendChild("Sprites", new QMoMTreeItem<eSpellKnown>(&rhs->Sprites));
    ptree->appendChild("Earth_Lore", new QMoMTreeItem<eSpellKnown>(&rhs->Earth_Lore));
    ptree->appendChild("Cracks_Call", new QMoMTreeItem<eSpellKnown>(&rhs->Cracks_Call));
    ptree->appendChild("Natures_eye", new QMoMTreeItem<eSpellKnown>(&rhs->Natures_eye));
    ptree->appendChild("Ice_Bolt", new QMoMTreeItem<eSpellKnown>(&rhs->Ice_Bolt));
    ptree->appendChild("Giant_Spiders", new QMoMTreeItem<eSpellKnown>(&rhs->Giant_Spiders));
    ptree->appendChild("Change_Terrain", new QMoMTreeItem<eSpellKnown>(&rhs->Change_Terrain));
    ptree->appendChild("Path_Finding", new QMoMTreeItem<eSpellKnown>(&rhs->Path_Finding));
    ptree->appendChild("Cockatrices", new QMoMTreeItem<eSpellKnown>(&rhs->Cockatrices));
    ptree->appendChild("Transmute", new QMoMTreeItem<eSpellKnown>(&rhs->Transmute));
    ptree->appendChild("Natures_Cures", new QMoMTreeItem<eSpellKnown>(&rhs->Natures_Cures));
    ptree->appendChild("Basilisk", new QMoMTreeItem<eSpellKnown>(&rhs->Basilisk));
    ptree->appendChild("Elemental_Armor", new QMoMTreeItem<eSpellKnown>(&rhs->Elemental_Armor));
    ptree->appendChild("Petrify", new QMoMTreeItem<eSpellKnown>(&rhs->Petrify));
    ptree->appendChild("Stone_Giant", new QMoMTreeItem<eSpellKnown>(&rhs->Stone_Giant));
    ptree->appendChild("Iron_Skin", new QMoMTreeItem<eSpellKnown>(&rhs->Iron_Skin));
    ptree->appendChild("Ice_Storm", new QMoMTreeItem<eSpellKnown>(&rhs->Ice_Storm));
    ptree->appendChild("Earthquake", new QMoMTreeItem<eSpellKnown>(&rhs->Earthquake));
    ptree->appendChild("Gorgons", new QMoMTreeItem<eSpellKnown>(&rhs->Gorgons));
    ptree->appendChild("Move_Fortress", new QMoMTreeItem<eSpellKnown>(&rhs->Move_Fortress));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItem<eSpellKnown>(&rhs->Gaias_Blessing));
    ptree->appendChild("Earth_Elemental", new QMoMTreeItem<eSpellKnown>(&rhs->Earth_Elemental));
    ptree->appendChild("Regeneration", new QMoMTreeItem<eSpellKnown>(&rhs->Regeneration));
    ptree->appendChild("Behemoth", new QMoMTreeItem<eSpellKnown>(&rhs->Behemoth));
    ptree->appendChild("Entangle", new QMoMTreeItem<eSpellKnown>(&rhs->Entangle));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItem<eSpellKnown>(&rhs->Nature_Awareness));
    ptree->appendChild("Call_Lightning", new QMoMTreeItem<eSpellKnown>(&rhs->Call_Lightning));
    ptree->appendChild("Colossus", new QMoMTreeItem<eSpellKnown>(&rhs->Colossus));
    ptree->appendChild("Earth_Gate", new QMoMTreeItem<eSpellKnown>(&rhs->Earth_Gate));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItem<eSpellKnown>(&rhs->Herb_Mastery));
    ptree->appendChild("Great_Wyrm", new QMoMTreeItem<eSpellKnown>(&rhs->Great_Wyrm));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItem<eSpellKnown>(&rhs->Natures_Wrath));
    ptree->appendChild("Resist_Magic", new QMoMTreeItem<eSpellKnown>(&rhs->Resist_Magic));
    ptree->appendChild("Dispel_Magic_True", new QMoMTreeItem<eSpellKnown>(&rhs->Dispel_Magic_True));
    ptree->appendChild("Floating_Island", new QMoMTreeItem<eSpellKnown>(&rhs->Floating_Island));
    ptree->appendChild("Guardian_Wind", new QMoMTreeItem<eSpellKnown>(&rhs->Guardian_Wind));
    ptree->appendChild("Phantom_Warriors", new QMoMTreeItem<eSpellKnown>(&rhs->Phantom_Warriors));
    ptree->appendChild("Confusion", new QMoMTreeItem<eSpellKnown>(&rhs->Confusion));
    ptree->appendChild("Word_of_Recall", new QMoMTreeItem<eSpellKnown>(&rhs->Word_of_Recall));
    ptree->appendChild("Counter_Magic", new QMoMTreeItem<eSpellKnown>(&rhs->Counter_Magic));
    ptree->appendChild("Nagas", new QMoMTreeItem<eSpellKnown>(&rhs->Nagas));
    ptree->appendChild("Psionic_Blast", new QMoMTreeItem<eSpellKnown>(&rhs->Psionic_Blast));
    ptree->appendChild("Blur", new QMoMTreeItem<eSpellKnown>(&rhs->Blur));
    ptree->appendChild("Disenchant_True", new QMoMTreeItem<eSpellKnown>(&rhs->Disenchant_True));
    ptree->appendChild("Vertigo", new QMoMTreeItem<eSpellKnown>(&rhs->Vertigo));
    ptree->appendChild("Spell_Lock", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Lock));
    ptree->appendChild("Enchant_Road", new QMoMTreeItem<eSpellKnown>(&rhs->Enchant_Road));
    ptree->appendChild("Flight", new QMoMTreeItem<eSpellKnown>(&rhs->Flight));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItem<eSpellKnown>(&rhs->Wind_Mastery));
    ptree->appendChild("Spell_Blast", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Blast));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItem<eSpellKnown>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Phantom_Beast", new QMoMTreeItem<eSpellKnown>(&rhs->Phantom_Beast));
    ptree->appendChild("Disjunction_True", new QMoMTreeItem<eSpellKnown>(&rhs->Disjunction_True));
    ptree->appendChild("Invisibility", new QMoMTreeItem<eSpellKnown>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new QMoMTreeItem<eSpellKnown>(&rhs->Wind_Walking));
    ptree->appendChild("Banish", new QMoMTreeItem<eSpellKnown>(&rhs->Banish));
    ptree->appendChild("Storm_Giant", new QMoMTreeItem<eSpellKnown>(&rhs->Storm_Giant));
    ptree->appendChild("Air_Elemental", new QMoMTreeItem<eSpellKnown>(&rhs->Air_Elemental));
    ptree->appendChild("Mind_Storm", new QMoMTreeItem<eSpellKnown>(&rhs->Mind_Storm));
    ptree->appendChild("Stasis", new QMoMTreeItem<eSpellKnown>(&rhs->Stasis));
    ptree->appendChild("Magic_Immunity", new QMoMTreeItem<eSpellKnown>(&rhs->Magic_Immunity));
    ptree->appendChild("Haste", new QMoMTreeItem<eSpellKnown>(&rhs->Haste));
    ptree->appendChild("Djinn", new QMoMTreeItem<eSpellKnown>(&rhs->Djinn));
    ptree->appendChild("Spell_Ward", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Ward));
    ptree->appendChild("Creature_Binding", new QMoMTreeItem<eSpellKnown>(&rhs->Creature_Binding));
    ptree->appendChild("Mass_Invisibility", new QMoMTreeItem<eSpellKnown>(&rhs->Mass_Invisibility));
    ptree->appendChild("Great_Unsummoning", new QMoMTreeItem<eSpellKnown>(&rhs->Great_Unsummoning));
    ptree->appendChild("Spell_Binding", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Binding));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItem<eSpellKnown>(&rhs->Flying_Fortress));
    ptree->appendChild("Sky_Drake", new QMoMTreeItem<eSpellKnown>(&rhs->Sky_Drake));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItem<eSpellKnown>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItem<eSpellKnown>(&rhs->Time_Stop));
    ptree->appendChild("Warp_Wood", new QMoMTreeItem<eSpellKnown>(&rhs->Warp_Wood));
    ptree->appendChild("Disrupt", new QMoMTreeItem<eSpellKnown>(&rhs->Disrupt));
    ptree->appendChild("Fire_Bolt", new QMoMTreeItem<eSpellKnown>(&rhs->Fire_Bolt));
    ptree->appendChild("Hell_Hounds", new QMoMTreeItem<eSpellKnown>(&rhs->Hell_Hounds));
    ptree->appendChild("Corruption", new QMoMTreeItem<eSpellKnown>(&rhs->Corruption));
    ptree->appendChild("Eldritch_Weapon", new QMoMTreeItem<eSpellKnown>(&rhs->Eldritch_Weapon));
    ptree->appendChild("Wall_of_Fire", new QMoMTreeItem<eSpellKnown>(&rhs->Wall_of_Fire));
    ptree->appendChild("Shatter", new QMoMTreeItem<eSpellKnown>(&rhs->Shatter));
    ptree->appendChild("Warp_Creature", new QMoMTreeItem<eSpellKnown>(&rhs->Warp_Creature));
    ptree->appendChild("Fire_Elemental", new QMoMTreeItem<eSpellKnown>(&rhs->Fire_Elemental));
    ptree->appendChild("Lightning_Bolt", new QMoMTreeItem<eSpellKnown>(&rhs->Lightning_Bolt));
    ptree->appendChild("Fire_Giant", new QMoMTreeItem<eSpellKnown>(&rhs->Fire_Giant));
    ptree->appendChild("Chaos_Channels", new QMoMTreeItem<eSpellKnown>(&rhs->Chaos_Channels));
    ptree->appendChild("Flame_Blade", new QMoMTreeItem<eSpellKnown>(&rhs->Flame_Blade));
    ptree->appendChild("Gargoyles", new QMoMTreeItem<eSpellKnown>(&rhs->Gargoyles));
    ptree->appendChild("Fireball", new QMoMTreeItem<eSpellKnown>(&rhs->Fireball));
    ptree->appendChild("Doombat", new QMoMTreeItem<eSpellKnown>(&rhs->Doombat));
    ptree->appendChild("Raise_Volcano", new QMoMTreeItem<eSpellKnown>(&rhs->Raise_Volcano));
    ptree->appendChild("Immolation", new QMoMTreeItem<eSpellKnown>(&rhs->Immolation));
    ptree->appendChild("Chimeras", new QMoMTreeItem<eSpellKnown>(&rhs->Chimeras));
    ptree->appendChild("Warp_Lightning", new QMoMTreeItem<eSpellKnown>(&rhs->Warp_Lightning));
    ptree->appendChild("Metal_Fires", new QMoMTreeItem<eSpellKnown>(&rhs->Metal_Fires));
    ptree->appendChild("Chaos_Spawn", new QMoMTreeItem<eSpellKnown>(&rhs->Chaos_Spawn));
    ptree->appendChild("Doom_Bolt", new QMoMTreeItem<eSpellKnown>(&rhs->Doom_Bolt));
    ptree->appendChild("Magic_Vortex", new QMoMTreeItem<eSpellKnown>(&rhs->Magic_Vortex));
    ptree->appendChild("Efreet", new QMoMTreeItem<eSpellKnown>(&rhs->Efreet));
    ptree->appendChild("Fire_Storm", new QMoMTreeItem<eSpellKnown>(&rhs->Fire_Storm));
    ptree->appendChild("Warp_Reality", new QMoMTreeItem<eSpellKnown>(&rhs->Warp_Reality));
    ptree->appendChild("Flame_Strike", new QMoMTreeItem<eSpellKnown>(&rhs->Flame_Strike));
    ptree->appendChild("Chaos_Rift", new QMoMTreeItem<eSpellKnown>(&rhs->Chaos_Rift));
    ptree->appendChild("Hydra", new QMoMTreeItem<eSpellKnown>(&rhs->Hydra));
    ptree->appendChild("Disintegrate", new QMoMTreeItem<eSpellKnown>(&rhs->Disintegrate));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItem<eSpellKnown>(&rhs->Meteor_Storm));
    ptree->appendChild("Great_Wasting", new QMoMTreeItem<eSpellKnown>(&rhs->Great_Wasting));
    ptree->appendChild("Call_Chaos", new QMoMTreeItem<eSpellKnown>(&rhs->Call_Chaos));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItem<eSpellKnown>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItem<eSpellKnown>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Drake", new QMoMTreeItem<eSpellKnown>(&rhs->Great_Drake));
    ptree->appendChild("Call_The_Void", new QMoMTreeItem<eSpellKnown>(&rhs->Call_The_Void));
    ptree->appendChild("Armageddon", new QMoMTreeItem<eSpellKnown>(&rhs->Armageddon));
    ptree->appendChild("Bless", new QMoMTreeItem<eSpellKnown>(&rhs->Bless));
    ptree->appendChild("Star_Fires", new QMoMTreeItem<eSpellKnown>(&rhs->Star_Fires));
    ptree->appendChild("Endurance", new QMoMTreeItem<eSpellKnown>(&rhs->Endurance));
    ptree->appendChild("Holy_Weapon", new QMoMTreeItem<eSpellKnown>(&rhs->Holy_Weapon));
    ptree->appendChild("Healing", new QMoMTreeItem<eSpellKnown>(&rhs->Healing));
    ptree->appendChild("Holy_Armor", new QMoMTreeItem<eSpellKnown>(&rhs->Holy_Armor));
    ptree->appendChild("Just_Cause", new QMoMTreeItem<eSpellKnown>(&rhs->Just_Cause));
    ptree->appendChild("True_Light", new QMoMTreeItem<eSpellKnown>(&rhs->True_Light));
    ptree->appendChild("Guardian_Spirit", new QMoMTreeItem<eSpellKnown>(&rhs->Guardian_Spirit));
    ptree->appendChild("Heroism", new QMoMTreeItem<eSpellKnown>(&rhs->Heroism));
    ptree->appendChild("True_Sight", new QMoMTreeItem<eSpellKnown>(&rhs->True_Sight));
    ptree->appendChild("Plane_Shift", new QMoMTreeItem<eSpellKnown>(&rhs->Plane_Shift));
    ptree->appendChild("Resurrection", new QMoMTreeItem<eSpellKnown>(&rhs->Resurrection));
    ptree->appendChild("Dispel_Evil", new QMoMTreeItem<eSpellKnown>(&rhs->Dispel_Evil));
    ptree->appendChild("Planar_Seal", new QMoMTreeItem<eSpellKnown>(&rhs->Planar_Seal));
    ptree->appendChild("Unicorns", new QMoMTreeItem<eSpellKnown>(&rhs->Unicorns));
    ptree->appendChild("Raise_Dead", new QMoMTreeItem<eSpellKnown>(&rhs->Raise_Dead));
    ptree->appendChild("Planar_Travel", new QMoMTreeItem<eSpellKnown>(&rhs->Planar_Travel));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItem<eSpellKnown>(&rhs->Heavenly_Light));
    ptree->appendChild("Prayer", new QMoMTreeItem<eSpellKnown>(&rhs->Prayer));
    ptree->appendChild("Lionheart", new QMoMTreeItem<eSpellKnown>(&rhs->Lionheart));
    ptree->appendChild("Incarnation", new QMoMTreeItem<eSpellKnown>(&rhs->Incarnation));
    ptree->appendChild("Invulnerability", new QMoMTreeItem<eSpellKnown>(&rhs->Invulnerability));
    ptree->appendChild("Righteousness", new QMoMTreeItem<eSpellKnown>(&rhs->Righteousness));
    ptree->appendChild("Prosperity", new QMoMTreeItem<eSpellKnown>(&rhs->Prosperity));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItem<eSpellKnown>(&rhs->Altar_of_Battle));
    ptree->appendChild("Angel", new QMoMTreeItem<eSpellKnown>(&rhs->Angel));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItem<eSpellKnown>(&rhs->Stream_of_Life));
    ptree->appendChild("Mass_Healing", new QMoMTreeItem<eSpellKnown>(&rhs->Mass_Healing));
    ptree->appendChild("Holy_Word", new QMoMTreeItem<eSpellKnown>(&rhs->Holy_Word));
    ptree->appendChild("High_Prayer", new QMoMTreeItem<eSpellKnown>(&rhs->High_Prayer));
    ptree->appendChild("Inspirations", new QMoMTreeItem<eSpellKnown>(&rhs->Inspirations));
    ptree->appendChild("Astral_Gate", new QMoMTreeItem<eSpellKnown>(&rhs->Astral_Gate));
    ptree->appendChild("Holy_Arms", new QMoMTreeItem<eSpellKnown>(&rhs->Holy_Arms));
    ptree->appendChild("Consecration", new QMoMTreeItem<eSpellKnown>(&rhs->Consecration));
    ptree->appendChild("Life_Force", new QMoMTreeItem<eSpellKnown>(&rhs->Life_Force));
    ptree->appendChild("Tranquility", new QMoMTreeItem<eSpellKnown>(&rhs->Tranquility));
    ptree->appendChild("Crusade", new QMoMTreeItem<eSpellKnown>(&rhs->Crusade));
    ptree->appendChild("Arch_Angel", new QMoMTreeItem<eSpellKnown>(&rhs->Arch_Angel));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItem<eSpellKnown>(&rhs->Charm_of_Life));
    ptree->appendChild("Skeletons", new QMoMTreeItem<eSpellKnown>(&rhs->Skeletons));
    ptree->appendChild("Weakness", new QMoMTreeItem<eSpellKnown>(&rhs->Weakness));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItem<eSpellKnown>(&rhs->Dark_Rituals));
    ptree->appendChild("Cloak_of_Fear", new QMoMTreeItem<eSpellKnown>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Sleep", new QMoMTreeItem<eSpellKnown>(&rhs->Black_Sleep));
    ptree->appendChild("Ghouls", new QMoMTreeItem<eSpellKnown>(&rhs->Ghouls));
    ptree->appendChild("Life_Drain", new QMoMTreeItem<eSpellKnown>(&rhs->Life_Drain));
    ptree->appendChild("Terror", new QMoMTreeItem<eSpellKnown>(&rhs->Terror));
    ptree->appendChild("Darkness", new QMoMTreeItem<eSpellKnown>(&rhs->Darkness));
    ptree->appendChild("Mana_Leak", new QMoMTreeItem<eSpellKnown>(&rhs->Mana_Leak));
    ptree->appendChild("Drain_Power", new QMoMTreeItem<eSpellKnown>(&rhs->Drain_Power));
    ptree->appendChild("Possession", new QMoMTreeItem<eSpellKnown>(&rhs->Possession));
    ptree->appendChild("Lycantrophy", new QMoMTreeItem<eSpellKnown>(&rhs->Lycantrophy));
    ptree->appendChild("Black_Prayer", new QMoMTreeItem<eSpellKnown>(&rhs->Black_Prayer));
    ptree->appendChild("Black_Channels", new QMoMTreeItem<eSpellKnown>(&rhs->Black_Channels));
    ptree->appendChild("Night_Stalker", new QMoMTreeItem<eSpellKnown>(&rhs->Night_Stalker));
    ptree->appendChild("Subversion", new QMoMTreeItem<eSpellKnown>(&rhs->Subversion));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItem<eSpellKnown>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Berserk", new QMoMTreeItem<eSpellKnown>(&rhs->Berserk));
    ptree->appendChild("Shadow_Demons", new QMoMTreeItem<eSpellKnown>(&rhs->Shadow_Demons));
    ptree->appendChild("Wraith_Form", new QMoMTreeItem<eSpellKnown>(&rhs->Wraith_Form));
    ptree->appendChild("Wrack", new QMoMTreeItem<eSpellKnown>(&rhs->Wrack));
    ptree->appendChild("Evil_Presence", new QMoMTreeItem<eSpellKnown>(&rhs->Evil_Presence));
    ptree->appendChild("Wraiths", new QMoMTreeItem<eSpellKnown>(&rhs->Wraiths));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItem<eSpellKnown>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Warp_Node", new QMoMTreeItem<eSpellKnown>(&rhs->Warp_Node));
    ptree->appendChild("Black_Wind", new QMoMTreeItem<eSpellKnown>(&rhs->Black_Wind));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItem<eSpellKnown>(&rhs->Zombie_Mastery));
    ptree->appendChild("Famine", new QMoMTreeItem<eSpellKnown>(&rhs->Famine));
    ptree->appendChild("Cursed_Lands", new QMoMTreeItem<eSpellKnown>(&rhs->Cursed_Lands));
    ptree->appendChild("Cruel_Unminding", new QMoMTreeItem<eSpellKnown>(&rhs->Cruel_Unminding));
    ptree->appendChild("Word_of_Death", new QMoMTreeItem<eSpellKnown>(&rhs->Word_of_Death));
    ptree->appendChild("Death_Knights", new QMoMTreeItem<eSpellKnown>(&rhs->Death_Knights));
    ptree->appendChild("Death_Spell", new QMoMTreeItem<eSpellKnown>(&rhs->Death_Spell));
    ptree->appendChild("Animate_dead", new QMoMTreeItem<eSpellKnown>(&rhs->Animate_dead));
    ptree->appendChild("Pestilence", new QMoMTreeItem<eSpellKnown>(&rhs->Pestilence));
    ptree->appendChild("Eternal_Night", new QMoMTreeItem<eSpellKnown>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItem<eSpellKnown>(&rhs->Evil_Omens));
    ptree->appendChild("Death_Wish", new QMoMTreeItem<eSpellKnown>(&rhs->Death_Wish));
    ptree->appendChild("Demon_Lord", new QMoMTreeItem<eSpellKnown>(&rhs->Demon_Lord));
    ptree->appendChild("Magic_Spirit", new QMoMTreeItem<eSpellKnown>(&rhs->Magic_Spirit));
    ptree->appendChild("Dispel_Magic", new QMoMTreeItem<eSpellKnown>(&rhs->Dispel_Magic));
    ptree->appendChild("Summoning_Circle", new QMoMTreeItem<eSpellKnown>(&rhs->Summoning_Circle));
    ptree->appendChild("Disenchant_Area", new QMoMTreeItem<eSpellKnown>(&rhs->Disenchant_Area));
    ptree->appendChild("Recall_Hero", new QMoMTreeItem<eSpellKnown>(&rhs->Recall_Hero));
    ptree->appendChild("Detect_Magic", new QMoMTreeItem<eSpellKnown>(&rhs->Detect_Magic));
    ptree->appendChild("Enchant_Item", new QMoMTreeItem<eSpellKnown>(&rhs->Enchant_Item));
    ptree->appendChild("Summon_Hero", new QMoMTreeItem<eSpellKnown>(&rhs->Summon_Hero));
    ptree->appendChild("Awareness", new QMoMTreeItem<eSpellKnown>(&rhs->Awareness));
    ptree->appendChild("Disjunction", new QMoMTreeItem<eSpellKnown>(&rhs->Disjunction));
    ptree->appendChild("Create_Artifact", new QMoMTreeItem<eSpellKnown>(&rhs->Create_Artifact));
    ptree->appendChild("Summon_Champion", new QMoMTreeItem<eSpellKnown>(&rhs->Summon_Champion));
    ptree->appendChild("Spell_Of_Mastery", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Of_Mastery));
    ptree->appendChild("Spell_Of_Return", new QMoMTreeItem<eSpellKnown>(&rhs->Spell_Of_Return));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Terrain_Changes* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Terrain_Changes>(rhs, context);
    if (0 == rhs)
        return ptree;

    Terrain_Changes maskVolcano_producing_for_Owner;
    memset(&maskVolcano_producing_for_Owner, '\0', sizeof(maskVolcano_producing_for_Owner));
    maskVolcano_producing_for_Owner.Volcano_producing_for_Owner = 7;
    if (1 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVolcano_producing_for_Owner));
    else if (2 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVolcano_producing_for_Owner));
    else
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVolcano_producing_for_Owner));
    Terrain_Changes maskroad;
    memset(&maskroad, '\0', sizeof(maskroad));
    maskroad.road = 1;
    if (1 == sizeof(maskroad))
        ptree->appendChild("road", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskroad));
    else if (2 == sizeof(maskroad))
        ptree->appendChild("road", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskroad));
    else
        ptree->appendChild("road", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskroad));
    Terrain_Changes maskenchanted_road;
    memset(&maskenchanted_road, '\0', sizeof(maskenchanted_road));
    maskenchanted_road.enchanted_road = 1;
    if (1 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskenchanted_road));
    else if (2 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskenchanted_road));
    else
        ptree->appendChild("enchanted_road", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskenchanted_road));
    Terrain_Changes maskcorruption;
    memset(&maskcorruption, '\0', sizeof(maskcorruption));
    maskcorruption.corruption = 1;
    if (1 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskcorruption));
    else if (2 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskcorruption));
    else
        ptree->appendChild("corruption", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskcorruption));
    Terrain_Changes maskunknown40;
    memset(&maskunknown40, '\0', sizeof(maskunknown40));
    maskunknown40.unknown40 = 1;
    if (1 == sizeof(maskunknown40))
        ptree->appendChild("unknown40", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskunknown40));
    else if (2 == sizeof(maskunknown40))
        ptree->appendChild("unknown40", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskunknown40));
    else
        ptree->appendChild("unknown40", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskunknown40));
    Terrain_Changes maskno_road80;
    memset(&maskno_road80, '\0', sizeof(maskno_road80));
    maskno_road80.no_road80 = 1;
    if (1 == sizeof(maskno_road80))
        ptree->appendChild("no_road80", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskno_road80));
    else if (2 == sizeof(maskno_road80))
        ptree->appendChild("no_road80", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskno_road80));
    else
        ptree->appendChild("no_road80", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskno_road80));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Tower_Attr* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Tower_Attr>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Closed", new QMoMTreeItem<uint8_t>(&rhs->m_Closed));
    ptree->appendChild("m_UNK", new QMoMTreeItem<uint8_t>(&rhs->m_UNK));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Tower_Node_Lair* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Tower_Node_Lair>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItem<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Status", new QMoMTreeItem<eTower_Node_Lair_Status>(&rhs->m_Status));
    ptree->appendChild("m_Type", new QMoMTreeItem<eTower_Node_Lair_Type>(&rhs->m_Type));
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant1, "m_Inhabitant1"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant2, "m_Inhabitant2"), "");
    ptree->appendChild("m_UNK01", new QMoMTreeItem<uint8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Reward_Gold", new QMoMTreeItem<uint16_t>(&rhs->m_Reward_Gold));
    ptree->appendChild("m_Reward_Mana", new QMoMTreeItem<uint16_t>(&rhs->m_Reward_Mana));
    ptree->appendChild("m_Reward_Specials", new QMoMTreeItem<eReward_Specials>(&rhs->m_Reward_Specials));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags, "m_Flags"), "");
    ptree->appendChild("m_Item_Rewards", new QMoMTreeItem<uint16_t>(&rhs->m_Item_Rewards));
    QMoMTreeItemBase* ptreem_Item_Value = ptree;
    if (3 > 3)
    {
        ptreem_Item_Value = new QMoMTreeItemBase("m_Item_Value");
        ptree->appendTree(ptreem_Item_Value, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Value[" << i << "]";
          ptreem_Item_Value->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_Item_Value[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Tower_Node_Lair_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Tower_Node_Lair_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Tower_Node_Lair_Flags maskm_Prisoner;
    memset(&maskm_Prisoner, '\0', sizeof(maskm_Prisoner));
    maskm_Prisoner.m_Prisoner = 1;
    if (1 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Prisoner));
    else if (2 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Prisoner));
    else
        ptree->appendChild("m_Prisoner", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Prisoner));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant1;
    memset(&maskm_YOU_aware_Inhabitant1, '\0', sizeof(maskm_YOU_aware_Inhabitant1));
    maskm_YOU_aware_Inhabitant1.m_YOU_aware_Inhabitant1 = 1;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant1));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant1));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant1));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant2;
    memset(&maskm_YOU_aware_Inhabitant2, '\0', sizeof(maskm_YOU_aware_Inhabitant2));
    maskm_YOU_aware_Inhabitant2.m_YOU_aware_Inhabitant2 = 1;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant2));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant2));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant2));
    Tower_Node_Lair_Flags maskm_Zero;
    memset(&maskm_Zero, '\0', sizeof(maskm_Zero));
    maskm_Zero.m_Zero = 31;
    if (1 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Zero));
    else if (2 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Zero));
    else
        ptree->appendChild("m_Zero", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Zero));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Unit* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Unit>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItem<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItem<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItem<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItem<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Moves_Total", new QMoMTreeItem<int8_t>(&rhs->m_Moves_Total));
    ptree->appendChild("m_Unit_Type", new QMoMTreeItem<eUnit_Type>(&rhs->m_Unit_Type));
    ptree->appendChild("m_Hero_Slot_Number", new QMoMTreeItem<int8_t>(&rhs->m_Hero_Slot_Number));
    ptree->appendChild("m_Active", new QMoMTreeItem<eUnit_Active>(&rhs->m_Active));
    ptree->appendChild("m_Moves_Left", new QMoMTreeItem<int8_t>(&rhs->m_Moves_Left));
    ptree->appendChild("m_XPos_of_destination", new QMoMTreeItem<int8_t>(&rhs->m_XPos_of_destination));
    ptree->appendChild("m_YPos_of_destination", new QMoMTreeItem<int8_t>(&rhs->m_YPos_of_destination));
    ptree->appendChild("m_Status", new QMoMTreeItem<eUnit_Status8>(&rhs->m_Status));
    ptree->appendChild("m_Level", new QMoMTreeItem<eLevel>(&rhs->m_Level));
    ptree->appendChild("m_UNK01", new QMoMTreeItem<int8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Experience", new QMoMTreeItem<int16_t>(&rhs->m_Experience));
    ptree->appendChild("m_Guess_Lifedrain_Damage", new QMoMTreeItem<int8_t>(&rhs->m_Guess_Lifedrain_Damage));
    ptree->appendChild("m_Damage", new QMoMTreeItem<int8_t>(&rhs->m_Damage));
    ptree->appendChild("m_Grouping", new QMoMTreeItem<uint8_t>(&rhs->m_Grouping));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag1", new QMoMTreeItem<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag1));
    ptree->appendChild("m_In_Tower_without_Seal", new QMoMTreeItem<int8_t>(&rhs->m_In_Tower_without_Seal));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag3", new QMoMTreeItem<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag3));
    ptree->appendChild("m_Scouting", new QMoMTreeItem<uint8_t>(&rhs->m_Scouting));
    ptree->appendTree(constructTreeItem(&rhs->m_Weapon_Mutation, "m_Weapon_Mutation"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Unit_Enchantment, "m_Unit_Enchantment"), "");
    ptree->appendChild("m_Road_Building_left_to_complete", new QMoMTreeItem<int8_t>(&rhs->m_Road_Building_left_to_complete));
    ptree->appendChild("m_XPos_Road_Building_from", new QMoMTreeItem<int8_t>(&rhs->m_XPos_Road_Building_from));
    ptree->appendChild("m_YPos_Road_Building_from", new QMoMTreeItem<int8_t>(&rhs->m_YPos_Road_Building_from));
    ptree->appendChild("m_UNK02", new QMoMTreeItem<int8_t>(&rhs->m_UNK02));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_HeroAbility* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_HeroAbility>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_bitmask", new QMoMTreeItem<uint32_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItem<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItem<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_ItemText* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_ItemText>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItem<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_offset_helpText", new QMoMTreeItem<uint16_t>(&rhs->m_offset_helpText));
    ptree->appendChild("m_bitmask", new QMoMTreeItem<uint32_t>(&rhs->m_bitmask));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_Line* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_Line>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Line", new QMoMTreeItem<char[30]>(rhs->m_Line));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_Lines* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_Lines>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreem_lines = ptree;
    if (40 > 3)
    {
        ptreem_lines = new QMoMTreeItemBase("m_lines");
        ptree->appendTree(ptreem_lines, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_lines[" << i << "]";
          ptreem_lines->appendTree(constructTreeItem(&rhs->m_lines[i], oss.str().c_str()), "");
    }
    QMoMTreeItemBase* ptreem_4B0_line_related = ptree;
    if (4 > 3)
    {
        ptreem_4B0_line_related = new QMoMTreeItemBase("m_4B0_line_related");
        ptree->appendTree(ptreem_4B0_line_related, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_4B0_line_related[" << i << "]";
          ptreem_4B0_line_related->appendChild(oss.str().c_str(), new QMoMTreeItem<uint32_t>(&rhs->m_4B0_line_related[i]));
    }
    QMoMTreeItemBase* ptreem_550_line_icon = ptree;
    if (40 > 3)
    {
        ptreem_550_line_icon = new QMoMTreeItemBase("m_550_line_icon");
        ptree->appendTree(ptreem_550_line_icon, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_550_line_icon[" << i << "]";
          ptreem_550_line_icon->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_550_line_icon[i]));
    }
    QMoMTreeItemBase* ptreem_5A0_line_related_itemNr = ptree;
    if (40 > 3)
    {
        ptreem_5A0_line_related_itemNr = new QMoMTreeItemBase("m_5A0_line_related_itemNr");
        ptree->appendTree(ptreem_5A0_line_related_itemNr, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_5A0_line_related_itemNr[" << i << "]";
          ptreem_5A0_line_related_itemNr->appendChild(oss.str().c_str(), new QMoMTreeItem<uint16_t>(&rhs->m_5A0_line_related_itemNr[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_Mutation* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItem<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItem<uint8_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItem<int8_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItem<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_Ranged* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_Ranged>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItem<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_rangedType", new QMoMTreeItem<eRanged_Type>(&rhs->m_rangedType));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItem<int8_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItem<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_SpellData* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_SpellData>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItem<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItem<uint32_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItem<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItem<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(UnitView_UnitData* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<UnitView_UnitData>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItem<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItem<uint16_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItem<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItem<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Unit_Data_Hero_Types* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Unit_Data_Hero_Types>(rhs, context);
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

QMoMTreeItemBase* constructTreeItem(Unit_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Unit_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    Unit_Enchantment maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 1;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Unit_Enchantment maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 1;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Unit_Enchantment maskBerserk;
    memset(&maskBerserk, '\0', sizeof(maskBerserk));
    maskBerserk.Berserk = 1;
    if (1 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBerserk));
    else if (2 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBerserk));
    else
        ptree->appendChild("Berserk", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBerserk));
    Unit_Enchantment maskCloak_of_Fear;
    memset(&maskCloak_of_Fear, '\0', sizeof(maskCloak_of_Fear));
    maskCloak_of_Fear.Cloak_of_Fear = 1;
    if (1 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_of_Fear));
    else if (2 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_of_Fear));
    else
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_of_Fear));
    Unit_Enchantment maskBlack_Channels;
    memset(&maskBlack_Channels, '\0', sizeof(maskBlack_Channels));
    maskBlack_Channels.Black_Channels = 1;
    if (1 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Channels));
    else if (2 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Channels));
    else
        ptree->appendChild("Black_Channels", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Channels));
    Unit_Enchantment maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 1;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Unit_Enchantment maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Unit_Enchantment maskPath_Finding;
    memset(&maskPath_Finding, '\0', sizeof(maskPath_Finding));
    maskPath_Finding.Path_Finding = 1;
    if (1 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPath_Finding));
    else if (2 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPath_Finding));
    else
        ptree->appendChild("Path_Finding", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPath_Finding));
    Unit_Enchantment maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 1;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Unit_Enchantment maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 1;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Unit_Enchantment maskElemental_Armor;
    memset(&maskElemental_Armor, '\0', sizeof(maskElemental_Armor));
    maskElemental_Armor.Elemental_Armor = 1;
    if (1 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armor));
    else if (2 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armor));
    else
        ptree->appendChild("Elemental_Armor", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armor));
    Unit_Enchantment maskStone_Skin;
    memset(&maskStone_Skin, '\0', sizeof(maskStone_Skin));
    maskStone_Skin.Stone_Skin = 1;
    if (1 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStone_Skin));
    else if (2 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStone_Skin));
    else
        ptree->appendChild("Stone_Skin", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStone_Skin));
    Unit_Enchantment maskIron_Skin;
    memset(&maskIron_Skin, '\0', sizeof(maskIron_Skin));
    maskIron_Skin.Iron_Skin = 1;
    if (1 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIron_Skin));
    else if (2 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIron_Skin));
    else
        ptree->appendChild("Iron_Skin", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIron_Skin));
    Unit_Enchantment maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 1;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Unit_Enchantment maskSpell_Lock;
    memset(&maskSpell_Lock, '\0', sizeof(maskSpell_Lock));
    maskSpell_Lock.Spell_Lock = 1;
    if (1 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSpell_Lock));
    else if (2 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSpell_Lock));
    else
        ptree->appendChild("Spell_Lock", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSpell_Lock));
    Unit_Enchantment maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Unit_Enchantment maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 1;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Unit_Enchantment maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 1;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Unit_Enchantment maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 1;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Unit_Enchantment maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Unit_Enchantment maskFlame_Blade;
    memset(&maskFlame_Blade, '\0', sizeof(maskFlame_Blade));
    maskFlame_Blade.Flame_Blade = 1;
    if (1 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlame_Blade));
    else if (2 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlame_Blade));
    else
        ptree->appendChild("Flame_Blade", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlame_Blade));
    Unit_Enchantment maskEldritch_Weapon;
    memset(&maskEldritch_Weapon, '\0', sizeof(maskEldritch_Weapon));
    maskEldritch_Weapon.Eldritch_Weapon = 1;
    if (1 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon));
    else if (2 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon));
    else
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon));
    Unit_Enchantment maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 1;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Unit_Enchantment maskHoly_Weapon;
    memset(&maskHoly_Weapon, '\0', sizeof(maskHoly_Weapon));
    maskHoly_Weapon.Holy_Weapon = 1;
    if (1 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Weapon));
    else if (2 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Weapon));
    else
        ptree->appendChild("Holy_Weapon", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Weapon));
    Unit_Enchantment maskHeroism;
    memset(&maskHeroism, '\0', sizeof(maskHeroism));
    maskHeroism.Heroism = 1;
    if (1 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHeroism));
    else if (2 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHeroism));
    else
        ptree->appendChild("Heroism", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHeroism));
    Unit_Enchantment maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 1;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Unit_Enchantment maskLionheart;
    memset(&maskLionheart, '\0', sizeof(maskLionheart));
    maskLionheart.Lionheart = 1;
    if (1 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLionheart));
    else if (2 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLionheart));
    else
        ptree->appendChild("Lionheart", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLionheart));
    Unit_Enchantment maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 1;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Unit_Enchantment maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 1;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Unit_Enchantment maskHoly_Armor;
    memset(&maskHoly_Armor, '\0', sizeof(maskHoly_Armor));
    maskHoly_Armor.Holy_Armor = 1;
    if (1 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Armor));
    else if (2 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Armor));
    else
        ptree->appendChild("Holy_Armor", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Armor));
    Unit_Enchantment maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 1;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Unit_Enchantment maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 1;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Unit_Type_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Unit_Type_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new QMoMTreeItem<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Melee", new QMoMTreeItem<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new QMoMTreeItem<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new QMoMTreeItem<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new QMoMTreeItem<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new QMoMTreeItem<int8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new QMoMTreeItem<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new QMoMTreeItem<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new QMoMTreeItem<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new QMoMTreeItem<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new QMoMTreeItem<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new QMoMTreeItem<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Building_Required1", new QMoMTreeItem<uint8_t>(&rhs->m_Building_Required1));
    ptree->appendChild("m_Hero_TypeCode_or_Building2", new QMoMTreeItem<eHero_TypeCode>(&rhs->m_Hero_TypeCode_or_Building2));
    ptree->appendChild("m_Unit_picture", new QMoMTreeItem<uint8_t>(&rhs->m_Unit_picture));
    ptree->appendChild("m_UNK01", new QMoMTreeItem<uint8_t>(&rhs->m_UNK01));
    ptree->appendChild("m_Hitpoints", new QMoMTreeItem<uint8_t>(&rhs->m_Hitpoints));
    ptree->appendChild("m_Scouting", new QMoMTreeItem<uint8_t>(&rhs->m_Scouting));
    ptree->appendChild("m_Transport_Capacity", new QMoMTreeItem<uint8_t>(&rhs->m_Transport_Capacity));
    ptree->appendChild("m_Nr_Figures", new QMoMTreeItem<uint8_t>(&rhs->m_Nr_Figures));
    ptree->appendChild("m_Construction", new QMoMTreeItem<uint8_t>(&rhs->m_Construction));
    ptree->appendChild("m_Gaze_Modifier", new QMoMTreeItem<int8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero02", new QMoMTreeItem<uint8_t>(&rhs->m_Zero02));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero03", new QMoMTreeItem<uint8_t>(&rhs->m_Zero03));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_UNK02", new QMoMTreeItem<uint8_t>(&rhs->m_UNK02));
    ptree->appendChild("m_Zero04", new QMoMTreeItem<uint8_t>(&rhs->m_Zero04));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Unit_Weapon_Mutation* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Unit_Weapon_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    Unit_Weapon_Mutation maskWeapon_Type;
    memset(&maskWeapon_Type, '\0', sizeof(maskWeapon_Type));
    maskWeapon_Type.Weapon_Type = 3;
    if (1 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Type));
    else if (2 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Type));
    else
        ptree->appendChild("Weapon_Type", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Type));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Skin;
    memset(&maskChaos_Channels_Demon_Skin, '\0', sizeof(maskChaos_Channels_Demon_Skin));
    maskChaos_Channels_Demon_Skin.Chaos_Channels_Demon_Skin = 1;
    if (1 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Skin));
    else if (2 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Skin));
    else
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Skin));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Wings;
    memset(&maskChaos_Channels_Demon_Wings, '\0', sizeof(maskChaos_Channels_Demon_Wings));
    maskChaos_Channels_Demon_Wings.Chaos_Channels_Demon_Wings = 1;
    if (1 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Wings));
    else if (2 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Wings));
    else
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Wings));
    Unit_Weapon_Mutation maskChaos_Channels_Fiery_Breath;
    memset(&maskChaos_Channels_Fiery_Breath, '\0', sizeof(maskChaos_Channels_Fiery_Breath));
    maskChaos_Channels_Fiery_Breath.Chaos_Channels_Fiery_Breath = 1;
    if (1 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Fiery_Breath));
    else if (2 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Fiery_Breath));
    else
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Fiery_Breath));
    Unit_Weapon_Mutation maskUndead;
    memset(&maskUndead, '\0', sizeof(maskUndead));
    maskUndead.Undead = 1;
    if (1 == sizeof(maskUndead))
        ptree->appendChild("Undead", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskUndead));
    else if (2 == sizeof(maskUndead))
        ptree->appendChild("Undead", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskUndead));
    else
        ptree->appendChild("Undead", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskUndead));
    Unit_Weapon_Mutation maskStasis_initial;
    memset(&maskStasis_initial, '\0', sizeof(maskStasis_initial));
    maskStasis_initial.Stasis_initial = 1;
    if (1 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_initial));
    else if (2 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_initial));
    else
        ptree->appendChild("Stasis_initial", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_initial));
    Unit_Weapon_Mutation maskStasis_lingering;
    memset(&maskStasis_lingering, '\0', sizeof(maskStasis_lingering));
    maskStasis_lingering.Stasis_lingering = 1;
    if (1 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new QMoMTreeItem<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_lingering));
    else if (2 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new QMoMTreeItem<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_lingering));
    else
        ptree->appendChild("Stasis_lingering", new QMoMTreeItem<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_lingering));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Upkeep_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Upkeep_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Immolation", new QMoMTreeItem<uint16_t>(&rhs->Immolation));
    ptree->appendChild("Guardian_Wind", new QMoMTreeItem<uint16_t>(&rhs->Guardian_Wind));
    ptree->appendChild("Berserk", new QMoMTreeItem<uint16_t>(&rhs->Berserk));
    ptree->appendChild("Cloak_of_Fear", new QMoMTreeItem<uint16_t>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Channels", new QMoMTreeItem<uint16_t>(&rhs->Black_Channels));
    ptree->appendChild("Wraith_Form", new QMoMTreeItem<uint16_t>(&rhs->Wraith_Form));
    ptree->appendChild("Regeneration", new QMoMTreeItem<uint16_t>(&rhs->Regeneration));
    ptree->appendChild("Path_Finding", new QMoMTreeItem<uint16_t>(&rhs->Path_Finding));
    ptree->appendChild("Water_Walking", new QMoMTreeItem<uint16_t>(&rhs->Water_Walking));
    ptree->appendChild("Resist_Elements", new QMoMTreeItem<uint16_t>(&rhs->Resist_Elements));
    ptree->appendChild("Elemental_Armor", new QMoMTreeItem<uint16_t>(&rhs->Elemental_Armor));
    ptree->appendChild("Stone_Skin", new QMoMTreeItem<uint16_t>(&rhs->Stone_Skin));
    ptree->appendChild("Iron_Skin", new QMoMTreeItem<uint16_t>(&rhs->Iron_Skin));
    ptree->appendChild("Endurance", new QMoMTreeItem<uint16_t>(&rhs->Endurance));
    ptree->appendChild("Spell_Lock", new QMoMTreeItem<uint16_t>(&rhs->Spell_Lock));
    ptree->appendChild("Invisibility", new QMoMTreeItem<uint16_t>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new QMoMTreeItem<uint16_t>(&rhs->Wind_Walking));
    ptree->appendChild("Flight", new QMoMTreeItem<uint16_t>(&rhs->Flight));
    ptree->appendChild("Resist_Magic", new QMoMTreeItem<uint16_t>(&rhs->Resist_Magic));
    ptree->appendChild("Magic_Immunity", new QMoMTreeItem<uint16_t>(&rhs->Magic_Immunity));
    ptree->appendChild("Flame_Blade", new QMoMTreeItem<uint16_t>(&rhs->Flame_Blade));
    ptree->appendChild("Eldritch_Weapon", new QMoMTreeItem<uint16_t>(&rhs->Eldritch_Weapon));
    ptree->appendChild("True_Sight", new QMoMTreeItem<uint16_t>(&rhs->True_Sight));
    ptree->appendChild("Holy_Weapon", new QMoMTreeItem<uint16_t>(&rhs->Holy_Weapon));
    ptree->appendChild("Heroism", new QMoMTreeItem<uint16_t>(&rhs->Heroism));
    ptree->appendChild("Bless", new QMoMTreeItem<uint16_t>(&rhs->Bless));
    ptree->appendChild("Lionheart", new QMoMTreeItem<uint16_t>(&rhs->Lionheart));
    ptree->appendChild("Giant_Strength", new QMoMTreeItem<uint16_t>(&rhs->Giant_Strength));
    ptree->appendChild("Planar_Travel", new QMoMTreeItem<uint16_t>(&rhs->Planar_Travel));
    ptree->appendChild("Holy_Armor", new QMoMTreeItem<uint16_t>(&rhs->Holy_Armor));
    ptree->appendChild("Righteousness", new QMoMTreeItem<uint16_t>(&rhs->Righteousness));
    ptree->appendChild("Invulnerability", new QMoMTreeItem<uint16_t>(&rhs->Invulnerability));
    ptree->appendChild("Wall_of_Fire", new QMoMTreeItem<uint16_t>(&rhs->Wall_of_Fire));
    ptree->appendChild("Chaos_Rift", new QMoMTreeItem<uint16_t>(&rhs->Chaos_Rift));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItem<uint16_t>(&rhs->Dark_Rituals));
    ptree->appendChild("Evil_Presence", new QMoMTreeItem<uint16_t>(&rhs->Evil_Presence));
    ptree->appendChild("Cursed_Lands", new QMoMTreeItem<uint16_t>(&rhs->Cursed_Lands));
    ptree->appendChild("Pestilence", new QMoMTreeItem<uint16_t>(&rhs->Pestilence));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItem<uint16_t>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Famine", new QMoMTreeItem<uint16_t>(&rhs->Famine));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItem<uint16_t>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new QMoMTreeItem<uint16_t>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new QMoMTreeItem<uint16_t>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new QMoMTreeItem<uint16_t>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new QMoMTreeItem<uint16_t>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new QMoMTreeItem<uint16_t>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new QMoMTreeItem<uint16_t>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new QMoMTreeItem<uint16_t>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItem<uint16_t>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItem<uint16_t>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new QMoMTreeItem<uint16_t>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new QMoMTreeItem<uint16_t>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new QMoMTreeItem<uint16_t>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItem<uint16_t>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new QMoMTreeItem<uint16_t>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItem<uint16_t>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItem<uint16_t>(&rhs->Altar_of_Battle));
    ptree->appendChild("Nightshade", new QMoMTreeItem<uint16_t>(&rhs->Nightshade));
    ptree->appendChild("Eternal_Night", new QMoMTreeItem<uint16_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItem<uint16_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItem<uint16_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItem<uint16_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItem<uint16_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItem<uint16_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItem<uint16_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItem<uint16_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItem<uint16_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItem<uint16_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItem<uint16_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItem<uint16_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new QMoMTreeItem<uint16_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItem<uint16_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new QMoMTreeItem<uint16_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new QMoMTreeItem<uint16_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new QMoMTreeItem<uint16_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new QMoMTreeItem<uint16_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new QMoMTreeItem<uint16_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new QMoMTreeItem<uint16_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new QMoMTreeItem<uint16_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItem<uint16_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new QMoMTreeItem<uint16_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new QMoMTreeItem<uint16_t>(&rhs->Awareness));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Wizard* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Wizard>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Portrait", new QMoMTreeItem<ePortrait>(&rhs->m_Portrait));
    ptree->appendChild("m_Name", new QMoMTreeItem<char[20]>(rhs->m_Name));
    ptree->appendChild("m_Home_Race", new QMoMTreeItem<eRace>(&rhs->m_Home_Race));
    ptree->appendChild("m_BannerColor", new QMoMTreeItem<eBannerColor>(&rhs->m_BannerColor));
    ptree->appendChild("m_Personality", new QMoMTreeItem<ePersonality>(&rhs->m_Personality));
    ptree->appendChild("m_Objective", new QMoMTreeItem<eObjective>(&rhs->m_Objective));
    QMoMTreeItemBase* ptreem_UNK01C = ptree;
    if (8 > 3)
    {
        ptreem_UNK01C = new QMoMTreeItemBase("m_UNK01C");
        ptree->appendTree(ptreem_UNK01C, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK01C[" << i << "]";
          ptreem_UNK01C->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK01C[i]));
    }
    ptree->appendChild("m_Fame", new QMoMTreeItem<uint16_t>(&rhs->m_Fame));
    ptree->appendChild("m_Power_Base", new QMoMTreeItem<uint16_t>(&rhs->m_Power_Base));
    ptree->appendChild("m_UNK028", new QMoMTreeItem<uint16_t>(&rhs->m_UNK028));
    ptree->appendChild("m_Research_Percentage", new QMoMTreeItem<uint8_t>(&rhs->m_Research_Percentage));
    ptree->appendChild("m_Mana_Percentage", new QMoMTreeItem<uint8_t>(&rhs->m_Mana_Percentage));
    ptree->appendChild("m_Skill_Percentage", new QMoMTreeItem<uint8_t>(&rhs->m_Skill_Percentage));
    ptree->appendChild("m_Mana_generated_by_volcanoes", new QMoMTreeItem<uint8_t>(&rhs->m_Mana_generated_by_volcanoes));
    ptree->appendChild("m_X_Coordinate_of_Summoning_Circle", new QMoMTreeItem<int16_t>(&rhs->m_X_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Y_Coordinate_of_Summoning_Circle", new QMoMTreeItem<int16_t>(&rhs->m_Y_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Plane_of_Summoning_Circle", new QMoMTreeItem<ePlane>(&rhs->m_Plane_of_Summoning_Circle));
    ptree->appendChild("m_Zero01", new QMoMTreeItem<uint8_t>(&rhs->m_Zero01));
    QMoMTreeItemBase* ptreem_Research_Spell_candidates = ptree;
    if (8 > 3)
    {
        ptreem_Research_Spell_candidates = new QMoMTreeItemBase("m_Research_Spell_candidates");
        ptree->appendTree(ptreem_Research_Spell_candidates, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Research_Spell_candidates[" << i << "]";
          ptreem_Research_Spell_candidates->appendChild(oss.str().c_str(), new QMoMTreeItem<eSpell16>(&rhs->m_Research_Spell_candidates[i]));
    }
    QMoMTreeItemBase* ptreem_UNK044 = ptree;
    if (4 > 3)
    {
        ptreem_UNK044 = new QMoMTreeItemBase("m_UNK044");
        ptree->appendTree(ptreem_UNK044, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK044[" << i << "]";
          ptreem_UNK044->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK044[i]));
    }
    ptree->appendChild("m_UNK048", new QMoMTreeItem<uint16_t>(&rhs->m_UNK048));
    ptree->appendChild("m_UNK04A", new QMoMTreeItem<uint16_t>(&rhs->m_UNK04A));
    ptree->appendChild("m_Skill_Left_in_combat", new QMoMTreeItem<uint16_t>(&rhs->m_Skill_Left_in_combat));
    ptree->appendChild("m_Cost_Left_of_Spell_being_cast", new QMoMTreeItem<uint16_t>(&rhs->m_Cost_Left_of_Spell_being_cast));
    ptree->appendChild("m_Initial_Cost_of_Spell_being_cast", new QMoMTreeItem<uint16_t>(&rhs->m_Initial_Cost_of_Spell_being_cast));
    ptree->appendChild("m_Spell_being_cast", new QMoMTreeItem<eSpell16>(&rhs->m_Spell_being_cast));
    ptree->appendChild("m_Unused_Casting_Skill_available_this_turn", new QMoMTreeItem<int16_t>(&rhs->m_Unused_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Nominal_Casting_Skill_available_this_turn", new QMoMTreeItem<int16_t>(&rhs->m_Nominal_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Tax_Rate", new QMoMTreeItem<eTax_Rate>(&rhs->m_Tax_Rate));
    ptree->appendChild("m_Number_of_Spellbooks_Nature", new QMoMTreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Nature));
    ptree->appendChild("m_Number_of_Spellbooks_Sorcery", new QMoMTreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Sorcery));
    ptree->appendChild("m_Number_of_Spellbooks_Chaos", new QMoMTreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Chaos));
    ptree->appendChild("m_Number_of_Spellbooks_Life", new QMoMTreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Life));
    ptree->appendChild("m_Number_of_Spellbooks_Death", new QMoMTreeItem<int16_t>(&rhs->m_Number_of_Spellbooks_Death));
    ptree->appendTree(constructTreeItem(&rhs->m_Skills, "m_Skills"), "");
    QMoMTreeItemBase* ptreem_Heroes_hired_by_wizard = ptree;
    if (gMAX_HIRED_HEROES > 3)
    {
        ptreem_Heroes_hired_by_wizard = new QMoMTreeItemBase("m_Heroes_hired_by_wizard");
        ptree->appendTree(ptreem_Heroes_hired_by_wizard, "");
    }
    for (unsigned i = 0; i < gMAX_HIRED_HEROES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Heroes_hired_by_wizard[" << i << "]";
          ptreem_Heroes_hired_by_wizard->appendTree(constructTreeItem(&rhs->m_Heroes_hired_by_wizard[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_UNK11E", new QMoMTreeItem<uint16_t>(&rhs->m_UNK11E));
    QMoMTreeItemBase* ptreem_Items_in_Slots = ptree;
    if (4 > 3)
    {
        ptreem_Items_in_Slots = new QMoMTreeItemBase("m_Items_in_Slots");
        ptree->appendTree(ptreem_Items_in_Slots, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_in_Slots[" << i << "]";
          ptreem_Items_in_Slots->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_Items_in_Slots[i]));
    }
    QMoMTreeItemBase* ptreem_Contacted = ptree;
    if (6 > 3)
    {
        ptreem_Contacted = new QMoMTreeItemBase("m_Contacted");
        ptree->appendTree(ptreem_Contacted, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Contacted[" << i << "]";
          ptreem_Contacted->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Contacted[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_12E_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK_12E_Relation = new QMoMTreeItemBase("m_UNK_12E_Relation");
        ptree->appendTree(ptreem_UNK_12E_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_12E_Relation[" << i << "]";
          ptreem_UNK_12E_Relation->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_UNK_12E_Relation[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_13A_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK_13A_Relation = new QMoMTreeItemBase("m_UNK_13A_Relation");
        ptree->appendTree(ptreem_UNK_13A_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_13A_Relation[" << i << "]";
          ptreem_UNK_13A_Relation->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_UNK_13A_Relation[i]));
    }
    QMoMTreeItemBase* ptreem_UNK_146_Relation = ptree;
    if (6 > 3)
    {
        ptreem_UNK_146_Relation = new QMoMTreeItemBase("m_UNK_146_Relation");
        ptree->appendTree(ptreem_UNK_146_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK_146_Relation[" << i << "]";
          ptreem_UNK_146_Relation->appendChild(oss.str().c_str(), new QMoMTreeItem<int16_t>(&rhs->m_UNK_146_Relation[i]));
    }
    QMoMTreeItemBase* ptreem_Current_Wizard_Relations = ptree;
    if (6 > 3)
    {
        ptreem_Current_Wizard_Relations = new QMoMTreeItemBase("m_Current_Wizard_Relations");
        ptree->appendTree(ptreem_Current_Wizard_Relations, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Current_Wizard_Relations[" << i << "]";
          ptreem_Current_Wizard_Relations->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Current_Wizard_Relations[i]));
    }
    QMoMTreeItemBase* ptreem_War_Status = ptree;
    if (6 > 3)
    {
        ptreem_War_Status = new QMoMTreeItemBase("m_War_Status");
        ptree->appendTree(ptreem_War_Status, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_War_Status[" << i << "]";
          ptreem_War_Status->appendChild(oss.str().c_str(), new QMoMTreeItem<eWar_Status>(&rhs->m_War_Status[i]));
    }
    QMoMTreeItemBase* ptreem_Unk15E = ptree;
    if (0x24 > 3)
    {
        ptreem_Unk15E = new QMoMTreeItemBase("m_Unk15E");
        ptree->appendTree(ptreem_Unk15E, "");
    }
    for (unsigned i = 0; i < 0x24; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk15E[" << i << "]";
          ptreem_Unk15E->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Unk15E[i]));
    }
    QMoMTreeItemBase* ptreem_Unk182_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk182_Relation = new QMoMTreeItemBase("m_Unk182_Relation");
        ptree->appendTree(ptreem_Unk182_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk182_Relation[" << i << "]";
          ptreem_Unk182_Relation->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Unk182_Relation[i]));
    }
    QMoMTreeItemBase* ptreem_Unk188_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk188_Relation = new QMoMTreeItemBase("m_Unk188_Relation");
        ptree->appendTree(ptreem_Unk188_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk188_Relation[" << i << "]";
          ptreem_Unk188_Relation->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Unk188_Relation[i]));
    }
    QMoMTreeItemBase* ptreem_Unk18E = ptree;
    if (18 > 3)
    {
        ptreem_Unk18E = new QMoMTreeItemBase("m_Unk18E");
        ptree->appendTree(ptreem_Unk18E, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk18E[" << i << "]";
          ptreem_Unk18E->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Unk18E[i]));
    }
    QMoMTreeItemBase* ptreem_Diplomacy_penalty_GUESS = ptree;
    if (6 > 3)
    {
        ptreem_Diplomacy_penalty_GUESS = new QMoMTreeItemBase("m_Diplomacy_penalty_GUESS");
        ptree->appendTree(ptreem_Diplomacy_penalty_GUESS, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Diplomacy_penalty_GUESS[" << i << "]";
          ptreem_Diplomacy_penalty_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Diplomacy_penalty_GUESS[i]));
    }
    QMoMTreeItemBase* ptreem_Unk1A6 = ptree;
    if (0xB4 > 3)
    {
        ptreem_Unk1A6 = new QMoMTreeItemBase("m_Unk1A6");
        ptree->appendTree(ptreem_Unk1A6, "");
    }
    for (unsigned i = 0; i < 0xB4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk1A6[" << i << "]";
          ptreem_Unk1A6->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_Unk1A6[i]));
    }
    ptree->appendChild("m_Researching_Left", new QMoMTreeItem<int16_t>(&rhs->m_Researching_Left));
    ptree->appendChild("m_Mana_Crystals", new QMoMTreeItem<int16_t>(&rhs->m_Mana_Crystals));
    ptree->appendChild("m_Wizard_Casting_Skill", new QMoMTreeItem<int32_t>(&rhs->m_Wizard_Casting_Skill));
    ptree->appendChild("m_Researching_Spell", new QMoMTreeItem<eSpell>(&rhs->m_Researching_Spell));
    ptree->appendTree(constructTreeItem(&rhs->m_Spells_Known, "m_Spells_Known"), "");
    QMoMTreeItemBase* ptreem_UNK33A = ptree;
    if (26 > 3)
    {
        ptreem_UNK33A = new QMoMTreeItemBase("m_UNK33A");
        ptree->appendTree(ptreem_UNK33A, "");
    }
    for (unsigned i = 0; i < 26; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK33A[" << i << "]";
          ptreem_UNK33A->appendChild(oss.str().c_str(), new QMoMTreeItem<int8_t>(&rhs->m_UNK33A[i]));
    }
    ptree->appendChild("m_UNK354", new QMoMTreeItem<int8_t>(&rhs->m_UNK354));
    ptree->appendChild("m_UNK355", new QMoMTreeItem<int8_t>(&rhs->m_UNK355));
    ptree->appendChild("m_Gold_Coins", new QMoMTreeItem<int16_t>(&rhs->m_Gold_Coins));
    ptree->appendChild("m_UNK358", new QMoMTreeItem<int16_t>(&rhs->m_UNK358));
    ptree->appendChild("m_Astrologer_Magic_Power", new QMoMTreeItem<uint16_t>(&rhs->m_Astrologer_Magic_Power));
    ptree->appendChild("m_Astrologer_Spell_Research", new QMoMTreeItem<uint16_t>(&rhs->m_Astrologer_Spell_Research));
    ptree->appendChild("m_Astrologer_Army_Strength", new QMoMTreeItem<uint16_t>(&rhs->m_Astrologer_Army_Strength));
    ptree->appendChild("m_Astrologer_Power_GUESS", new QMoMTreeItem<uint16_t>(&rhs->m_Astrologer_Power_GUESS));
    QMoMTreeItemBase* ptreem_Historian = ptree;
    if (288 > 3)
    {
        ptreem_Historian = new QMoMTreeItemBase("m_Historian");
        ptree->appendTree(ptreem_Historian, "");
    }
    for (unsigned i = 0; i < 288; ++i)
    {
          std::ostringstream oss;
          oss << "m_Historian[" << i << "]";
          ptreem_Historian->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_Historian[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Global_Enchantments, "m_Global_Enchantments"), "");
    QMoMTreeItemBase* ptreem_UNK49A = ptree;
    if (42 > 3)
    {
        ptreem_UNK49A = new QMoMTreeItemBase("m_UNK49A");
        ptree->appendTree(ptreem_UNK49A, "");
    }
    for (unsigned i = 0; i < 42; ++i)
    {
          std::ostringstream oss;
          oss << "m_UNK49A[" << i << "]";
          ptreem_UNK49A->appendChild(oss.str().c_str(), new QMoMTreeItem<uint8_t>(&rhs->m_UNK49A[i]));
    }
    ptree->appendChild("m_Books_Color", new QMoMTreeItem<eRealm_Type>(&rhs->m_Books_Color));
    ptree->appendChild("m_Zero4C5", new QMoMTreeItem<uint8_t>(&rhs->m_Zero4C5));
    ptree->appendChild("m_UNK4C6", new QMoMTreeItem<uint16_t>(&rhs->m_UNK4C6));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(Wizard_Type_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<Wizard_Type_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Wizard_Name", new QMoMTreeItem<char[10]>(rhs->m_Wizard_Name));
    ptree->appendChild("m_Life_books", new QMoMTreeItem<uint16_t>(&rhs->m_Life_books));
    ptree->appendChild("m_Sorcery_books", new QMoMTreeItem<uint16_t>(&rhs->m_Sorcery_books));
    ptree->appendChild("m_Nature_books", new QMoMTreeItem<uint16_t>(&rhs->m_Nature_books));
    ptree->appendChild("m_Death_books", new QMoMTreeItem<uint16_t>(&rhs->m_Death_books));
    ptree->appendChild("m_Chaos_books", new QMoMTreeItem<uint16_t>(&rhs->m_Chaos_books));
    ptree->appendChild("m_Skill", new QMoMTreeItem<eSkill16>(&rhs->m_Skill));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(WizardsExe_Game_Data* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<WizardsExe_Game_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_UnitNr_Active", new QMoMTreeItem<uint16_t>(&rhs->m_UnitNr_Active));
    ptree->appendChild("m_Current_Turn", new QMoMTreeItem<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_Number_of_Units", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Number_of_Cities", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Cities));
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItem<eDifficulty>(&rhs->m_Difficulty));
    }
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItem<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful_setting));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItem<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    }
    if (QMoMTreeItemBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItem<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size_setting));
    }
    else
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItem<eLand_Size>(&rhs->m_Land_Size_setting));
    }
    ptree->appendChild("m_Number_of_Wizards", new QMoMTreeItem<uint16_t>(&rhs->m_Number_of_Wizards));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(WizardsExe_Save_Name* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<WizardsExe_Save_Name>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new QMoMTreeItem<char[20]>(rhs->m_Name));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionAbility_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionAbility_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionAttack_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionAttack_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionAttribute_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionAttribute_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionBuilding_Status* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionBuilding_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreea = ptree;
    if (eBuilding_MAX > 3)
    {
        ptreea = new QMoMTreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (unsigned i = 0; i < eBuilding_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new QMoMTreeItem<eBuildingStatus>(&rhs->a[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionCombat_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionCombat_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionHero_Abilities* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionHero_Abilities>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionImmunity_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionImmunity_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionItem_Powers* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionItem_Powers>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionList_Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionList_Hero_stats>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemBase* ptreea = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreea = new QMoMTreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendTree(constructTreeItem(&rhs->a[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionMovement_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionMovement_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionSkills* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionSkills>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    QMoMTreeItemBase* ptreea = ptree;
    if (eSkill_MAX > 3)
    {
        ptreea = new QMoMTreeItemBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new QMoMTreeItem<eYesNo8>(&rhs->a[i]));
    }
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionTower_Node_Lair_Flags* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionTower_Node_Lair_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionUnit_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionUnit_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemBase* constructTreeItem(unionUnit_Weapon_Mutation* rhs, const QString& context)
{
    QMoMTreeItemBase* ptree = new QMoMTreeItemSubtree<unionUnit_Weapon_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItem<uint8_t>(&rhs->bits));
    return ptree;
}


} // namespace
