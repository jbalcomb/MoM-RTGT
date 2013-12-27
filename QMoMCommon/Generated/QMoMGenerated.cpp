// File: QMoMCommon/Generated/QMoMGenerated.cpp
// Generated from: MoMTemplate.h

#include <ctype.h>
#include <iomanip>
#include <sstream>

#include <MoMGenerated.h>

#include "QMoMGenerated.h"

namespace MoM {

QMoMTreeItemModelBase* constructTreeItem(Ability_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Ability_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Ability_Flags maskSummoned_Unit;
    memset(&maskSummoned_Unit, '\0', sizeof(maskSummoned_Unit));
    maskSummoned_Unit.Summoned_Unit = 1;
    if (1 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummoned_Unit));
    else if (2 == sizeof(maskSummoned_Unit))
        ptree->appendChild("Summoned_Unit", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummoned_Unit));
    else
        ptree->appendChild("Summoned_Unit", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummoned_Unit));
    Ability_Flags maskLarge_Shield;
    memset(&maskLarge_Shield, '\0', sizeof(maskLarge_Shield));
    maskLarge_Shield.Large_Shield = 1;
    if (1 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLarge_Shield));
    else if (2 == sizeof(maskLarge_Shield))
        ptree->appendChild("Large_Shield", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLarge_Shield));
    else
        ptree->appendChild("Large_Shield", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLarge_Shield));
    Ability_Flags maskPlane_Shift;
    memset(&maskPlane_Shift, '\0', sizeof(maskPlane_Shift));
    maskPlane_Shift.Plane_Shift = 1;
    if (1 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlane_Shift));
    else if (2 == sizeof(maskPlane_Shift))
        ptree->appendChild("Plane_Shift", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlane_Shift));
    else
        ptree->appendChild("Plane_Shift", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlane_Shift));
    Ability_Flags maskWall_Crusher;
    memset(&maskWall_Crusher, '\0', sizeof(maskWall_Crusher));
    maskWall_Crusher.Wall_Crusher = 1;
    if (1 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWall_Crusher));
    else if (2 == sizeof(maskWall_Crusher))
        ptree->appendChild("Wall_Crusher", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWall_Crusher));
    else
        ptree->appendChild("Wall_Crusher", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWall_Crusher));
    Ability_Flags maskHealer;
    memset(&maskHealer, '\0', sizeof(maskHealer));
    maskHealer.Healer = 1;
    if (1 == sizeof(maskHealer))
        ptree->appendChild("Healer", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealer));
    else if (2 == sizeof(maskHealer))
        ptree->appendChild("Healer", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealer));
    else
        ptree->appendChild("Healer", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealer));
    Ability_Flags maskCreate_Outpost;
    memset(&maskCreate_Outpost, '\0', sizeof(maskCreate_Outpost));
    maskCreate_Outpost.Create_Outpost = 1;
    if (1 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Outpost));
    else if (2 == sizeof(maskCreate_Outpost))
        ptree->appendChild("Create_Outpost", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Outpost));
    else
        ptree->appendChild("Create_Outpost", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Outpost));
    Ability_Flags maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Ability_Flags maskCreate_Undead;
    memset(&maskCreate_Undead, '\0', sizeof(maskCreate_Undead));
    maskCreate_Undead.Create_Undead = 1;
    if (1 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreate_Undead));
    else if (2 == sizeof(maskCreate_Undead))
        ptree->appendChild("Create_Undead", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreate_Undead));
    else
        ptree->appendChild("Create_Undead", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreate_Undead));
    Ability_Flags maskLong_Range;
    memset(&maskLong_Range, '\0', sizeof(maskLong_Range));
    maskLong_Range.Long_Range = 1;
    if (1 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLong_Range));
    else if (2 == sizeof(maskLong_Range))
        ptree->appendChild("Long_Range", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLong_Range));
    else
        ptree->appendChild("Long_Range", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLong_Range));
    Ability_Flags maskLand_Corruption;
    memset(&maskLand_Corruption, '\0', sizeof(maskLand_Corruption));
    maskLand_Corruption.Land_Corruption = 1;
    if (1 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLand_Corruption));
    else if (2 == sizeof(maskLand_Corruption))
        ptree->appendChild("Land_Corruption", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLand_Corruption));
    else
        ptree->appendChild("Land_Corruption", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLand_Corruption));
    Ability_Flags maskMeld_With_Node;
    memset(&maskMeld_With_Node, '\0', sizeof(maskMeld_With_Node));
    maskMeld_With_Node.Meld_With_Node = 1;
    if (1 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMeld_With_Node));
    else if (2 == sizeof(maskMeld_With_Node))
        ptree->appendChild("Meld_With_Node", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMeld_With_Node));
    else
        ptree->appendChild("Meld_With_Node", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMeld_With_Node));
    Ability_Flags maskNon_Corporeal;
    memset(&maskNon_Corporeal, '\0', sizeof(maskNon_Corporeal));
    maskNon_Corporeal.Non_Corporeal = 1;
    if (1 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNon_Corporeal));
    else if (2 == sizeof(maskNon_Corporeal))
        ptree->appendChild("Non_Corporeal", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNon_Corporeal));
    else
        ptree->appendChild("Non_Corporeal", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNon_Corporeal));
    Ability_Flags maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 1;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Ability_Flags maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Ability_Flags maskPurify;
    memset(&maskPurify, '\0', sizeof(maskPurify));
    maskPurify.Purify = 1;
    if (1 == sizeof(maskPurify))
        ptree->appendChild("Purify", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPurify));
    else if (2 == sizeof(maskPurify))
        ptree->appendChild("Purify", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPurify));
    else
        ptree->appendChild("Purify", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPurify));
    Ability_Flags maskNegate_First_Strike;
    memset(&maskNegate_First_Strike, '\0', sizeof(maskNegate_First_Strike));
    maskNegate_First_Strike.Negate_First_Strike = 1;
    if (1 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNegate_First_Strike));
    else if (2 == sizeof(maskNegate_First_Strike))
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNegate_First_Strike));
    else
        ptree->appendChild("Negate_First_Strike", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNegate_First_Strike));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Attack_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Attack_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Attack_Flags maskArmor_Piercing;
    memset(&maskArmor_Piercing, '\0', sizeof(maskArmor_Piercing));
    maskArmor_Piercing.Armor_Piercing = 1;
    if (1 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmor_Piercing));
    else if (2 == sizeof(maskArmor_Piercing))
        ptree->appendChild("Armor_Piercing", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmor_Piercing));
    else
        ptree->appendChild("Armor_Piercing", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmor_Piercing));
    Attack_Flags maskFirst_Strike;
    memset(&maskFirst_Strike, '\0', sizeof(maskFirst_Strike));
    maskFirst_Strike.First_Strike = 1;
    if (1 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFirst_Strike));
    else if (2 == sizeof(maskFirst_Strike))
        ptree->appendChild("First_Strike", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFirst_Strike));
    else
        ptree->appendChild("First_Strike", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFirst_Strike));
    Attack_Flags maskPoison_attack;
    memset(&maskPoison_attack, '\0', sizeof(maskPoison_attack));
    maskPoison_attack.Poison_attack = 1;
    if (1 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_attack));
    else if (2 == sizeof(maskPoison_attack))
        ptree->appendChild("Poison_attack", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_attack));
    else
        ptree->appendChild("Poison_attack", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_attack));
    Attack_Flags maskLife_Stealing;
    memset(&maskLife_Stealing, '\0', sizeof(maskLife_Stealing));
    maskLife_Stealing.Life_Stealing = 1;
    if (1 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLife_Stealing));
    else if (2 == sizeof(maskLife_Stealing))
        ptree->appendChild("Life_Stealing", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLife_Stealing));
    else
        ptree->appendChild("Life_Stealing", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLife_Stealing));
    Attack_Flags maskAutomatic_Damage;
    memset(&maskAutomatic_Damage, '\0', sizeof(maskAutomatic_Damage));
    maskAutomatic_Damage.Automatic_Damage = 1;
    if (1 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAutomatic_Damage));
    else if (2 == sizeof(maskAutomatic_Damage))
        ptree->appendChild("Automatic_Damage", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAutomatic_Damage));
    else
        ptree->appendChild("Automatic_Damage", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAutomatic_Damage));
    Attack_Flags maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 1;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Attack_Flags maskIllusionary_attack;
    memset(&maskIllusionary_attack, '\0', sizeof(maskIllusionary_attack));
    maskIllusionary_attack.Illusionary_attack = 1;
    if (1 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusionary_attack));
    else if (2 == sizeof(maskIllusionary_attack))
        ptree->appendChild("Illusionary_attack", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusionary_attack));
    else
        ptree->appendChild("Illusionary_attack", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusionary_attack));
    Attack_Flags maskStoning_Touch;
    memset(&maskStoning_Touch, '\0', sizeof(maskStoning_Touch));
    maskStoning_Touch.Stoning_Touch = 1;
    if (1 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Touch));
    else if (2 == sizeof(maskStoning_Touch))
        ptree->appendChild("Stoning_Touch", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Touch));
    else
        ptree->appendChild("Stoning_Touch", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Touch));
    Attack_Flags maskNo_effect01;
    memset(&maskNo_effect01, '\0', sizeof(maskNo_effect01));
    maskNo_effect01.No_effect01 = 1;
    if (1 == sizeof(maskNo_effect01))
        ptree->appendChild("No_effect01", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect01));
    else if (2 == sizeof(maskNo_effect01))
        ptree->appendChild("No_effect01", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect01));
    else
        ptree->appendChild("No_effect01", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect01));
    Attack_Flags maskDeath_Touch;
    memset(&maskDeath_Touch, '\0', sizeof(maskDeath_Touch));
    maskDeath_Touch.Death_Touch = 1;
    if (1 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Touch));
    else if (2 == sizeof(maskDeath_Touch))
        ptree->appendChild("Death_Touch", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Touch));
    else
        ptree->appendChild("Death_Touch", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Touch));
    Attack_Flags maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 1;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Attack_Flags maskDispel_Evil;
    memset(&maskDispel_Evil, '\0', sizeof(maskDispel_Evil));
    maskDispel_Evil.Dispel_Evil = 1;
    if (1 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDispel_Evil));
    else if (2 == sizeof(maskDispel_Evil))
        ptree->appendChild("Dispel_Evil", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDispel_Evil));
    else
        ptree->appendChild("Dispel_Evil", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDispel_Evil));
    Attack_Flags maskBall_COMBAT;
    memset(&maskBall_COMBAT, '\0', sizeof(maskBall_COMBAT));
    maskBall_COMBAT.Ball_COMBAT = 1;
    if (1 == sizeof(maskBall_COMBAT))
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBall_COMBAT));
    else if (2 == sizeof(maskBall_COMBAT))
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBall_COMBAT));
    else
        ptree->appendChild("Ball_COMBAT", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBall_COMBAT));
    Attack_Flags maskNo_effect20_COMBAT;
    memset(&maskNo_effect20_COMBAT, '\0', sizeof(maskNo_effect20_COMBAT));
    maskNo_effect20_COMBAT.No_effect20_COMBAT = 1;
    if (1 == sizeof(maskNo_effect20_COMBAT))
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_effect20_COMBAT));
    else if (2 == sizeof(maskNo_effect20_COMBAT))
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_effect20_COMBAT));
    else
        ptree->appendChild("No_effect20_COMBAT", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_effect20_COMBAT));
    Attack_Flags maskEldritch_Weapon_COMBAT;
    memset(&maskEldritch_Weapon_COMBAT, '\0', sizeof(maskEldritch_Weapon_COMBAT));
    maskEldritch_Weapon_COMBAT.Eldritch_Weapon_COMBAT = 1;
    if (1 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon_COMBAT));
    else if (2 == sizeof(maskEldritch_Weapon_COMBAT))
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon_COMBAT));
    else
        ptree->appendChild("Eldritch_Weapon_COMBAT", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon_COMBAT));
    Attack_Flags maskWarp_Lightning_COMBAT;
    memset(&maskWarp_Lightning_COMBAT, '\0', sizeof(maskWarp_Lightning_COMBAT));
    maskWarp_Lightning_COMBAT.Warp_Lightning_COMBAT = 1;
    if (1 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Lightning_COMBAT));
    else if (2 == sizeof(maskWarp_Lightning_COMBAT))
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Lightning_COMBAT));
    else
        ptree->appendChild("Warp_Lightning_COMBAT", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Lightning_COMBAT));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Attribute_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Attribute_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Attribute_Flags maskWeapon_Immunity;
    memset(&maskWeapon_Immunity, '\0', sizeof(maskWeapon_Immunity));
    maskWeapon_Immunity.Weapon_Immunity = 1;
    if (1 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Immunity));
    else if (2 == sizeof(maskWeapon_Immunity))
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Immunity));
    else
        ptree->appendChild("Weapon_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Immunity));
    Attribute_Flags maskFlyer;
    memset(&maskFlyer, '\0', sizeof(maskFlyer));
    maskFlyer.Flyer = 1;
    if (1 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlyer));
    else if (2 == sizeof(maskFlyer))
        ptree->appendChild("Flyer", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlyer));
    else
        ptree->appendChild("Flyer", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlyer));
    Attribute_Flags maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 1;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Attribute_Flags maskSummon_Demons_1;
    memset(&maskSummon_Demons_1, '\0', sizeof(maskSummon_Demons_1));
    maskSummon_Demons_1.Summon_Demons_1 = 1;
    if (1 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_1));
    else if (2 == sizeof(maskSummon_Demons_1))
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_1));
    else
        ptree->appendChild("Summon_Demons_1", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_1));
    Attribute_Flags maskSummon_Demons_2;
    memset(&maskSummon_Demons_2, '\0', sizeof(maskSummon_Demons_2));
    maskSummon_Demons_2.Summon_Demons_2 = 1;
    if (1 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSummon_Demons_2));
    else if (2 == sizeof(maskSummon_Demons_2))
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSummon_Demons_2));
    else
        ptree->appendChild("Summon_Demons_2", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSummon_Demons_2));
    Attribute_Flags maskCaster_20_MP;
    memset(&maskCaster_20_MP, '\0', sizeof(maskCaster_20_MP));
    maskCaster_20_MP.Caster_20_MP = 1;
    if (1 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_20_MP));
    else if (2 == sizeof(maskCaster_20_MP))
        ptree->appendChild("Caster_20_MP", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_20_MP));
    else
        ptree->appendChild("Caster_20_MP", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_20_MP));
    Attribute_Flags maskCaster_40_MP;
    memset(&maskCaster_40_MP, '\0', sizeof(maskCaster_40_MP));
    maskCaster_40_MP.Caster_40_MP = 1;
    if (1 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCaster_40_MP));
    else if (2 == sizeof(maskCaster_40_MP))
        ptree->appendChild("Caster_40_MP", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCaster_40_MP));
    else
        ptree->appendChild("Caster_40_MP", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCaster_40_MP));
    Attribute_Flags maskStandard;
    memset(&maskStandard, '\0', sizeof(maskStandard));
    maskStandard.Standard = 1;
    if (1 == sizeof(maskStandard))
        ptree->appendChild("Standard", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStandard));
    else if (2 == sizeof(maskStandard))
        ptree->appendChild("Standard", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStandard));
    else
        ptree->appendChild("Standard", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStandard));
    Attribute_Flags maskHealing_Spell;
    memset(&maskHealing_Spell, '\0', sizeof(maskHealing_Spell));
    maskHealing_Spell.Healing_Spell = 1;
    if (1 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHealing_Spell));
    else if (2 == sizeof(maskHealing_Spell))
        ptree->appendChild("Healing_Spell", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHealing_Spell));
    else
        ptree->appendChild("Healing_Spell", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHealing_Spell));
    Attribute_Flags maskFire_Ball_Spell;
    memset(&maskFire_Ball_Spell, '\0', sizeof(maskFire_Ball_Spell));
    maskFire_Ball_Spell.Fire_Ball_Spell = 1;
    if (1 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Ball_Spell));
    else if (2 == sizeof(maskFire_Ball_Spell))
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Ball_Spell));
    else
        ptree->appendChild("Fire_Ball_Spell", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Ball_Spell));
    Attribute_Flags maskDoombolt_Spell;
    memset(&maskDoombolt_Spell, '\0', sizeof(maskDoombolt_Spell));
    maskDoombolt_Spell.Doombolt_Spell = 1;
    if (1 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoombolt_Spell));
    else if (2 == sizeof(maskDoombolt_Spell))
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoombolt_Spell));
    else
        ptree->appendChild("Doombolt_Spell", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoombolt_Spell));
    Attribute_Flags maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 1;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Attribute_Flags maskWeb_Spell;
    memset(&maskWeb_Spell, '\0', sizeof(maskWeb_Spell));
    maskWeb_Spell.Web_Spell = 1;
    if (1 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb_Spell));
    else if (2 == sizeof(maskWeb_Spell))
        ptree->appendChild("Web_Spell", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb_Spell));
    else
        ptree->appendChild("Web_Spell", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb_Spell));
    Attribute_Flags maskCause_Fear_Spell;
    memset(&maskCause_Fear_Spell, '\0', sizeof(maskCause_Fear_Spell));
    maskCause_Fear_Spell.Cause_Fear_Spell = 1;
    if (1 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCause_Fear_Spell));
    else if (2 == sizeof(maskCause_Fear_Spell))
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCause_Fear_Spell));
    else
        ptree->appendChild("Cause_Fear_Spell", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCause_Fear_Spell));
    Attribute_Flags maskResistance_to_All;
    memset(&maskResistance_to_All, '\0', sizeof(maskResistance_to_All));
    maskResistance_to_All.Resistance_to_All = 1;
    if (1 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResistance_to_All));
    else if (2 == sizeof(maskResistance_to_All))
        ptree->appendChild("Resistance_to_All", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResistance_to_All));
    else
        ptree->appendChild("Resistance_to_All", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResistance_to_All));
    Attribute_Flags maskHoly_Bonus;
    memset(&maskHoly_Bonus, '\0', sizeof(maskHoly_Bonus));
    maskHoly_Bonus.Holy_Bonus = 1;
    if (1 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Bonus));
    else if (2 == sizeof(maskHoly_Bonus))
        ptree->appendChild("Holy_Bonus", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Bonus));
    else
        ptree->appendChild("Holy_Bonus", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Bonus));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Available_spell_page* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Available_spell_page>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Page_Name", new QMoMTreeItemModel<char[0x10]>(rhs->m_Page_Name));
    QMoMTreeItemModelBase* ptreem_Spells_on_page = ptree;
    if (6 > 3)
    {
        ptreem_Spells_on_page = new QMoMTreeItemModelBase("m_Spells_on_page");
        ptree->appendTree(ptreem_Spells_on_page, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_on_page[" << i << "]";
          ptreem_Spells_on_page->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell16>(&rhs->m_Spells_on_page[i]));
    }
    ptree->appendChild("m_Nr_spells_on_page", new QMoMTreeItemModel<uint8_t>(&rhs->m_Nr_spells_on_page));
    ptree->appendChild("m_Zero_1D", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_1D));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Battle_Figure* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Battle_Figure>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_xpel", new QMoMTreeItemModel<int16_t>(&rhs->m_xpel));
    ptree->appendChild("m_ypel", new QMoMTreeItemModel<int16_t>(&rhs->m_ypel));
    ptree->appendChild("m_Pic", new QMoMTreeItemModel<int16_t>(&rhs->m_Pic));
    ptree->appendChild("m_Unk_6_sound", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_6_sound));
    ptree->appendChild("m_Unk_8", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_8));
    ptree->appendChild("m_Unk_A", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_A));
    ptree->appendChild("m_Unk_C", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_C));
    ptree->appendChild("m_Owner", new QMoMTreeItemModel<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Unk_10", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_10));
    ptree->appendChild("m_Color_enchantment", new QMoMTreeItemModel<uint16_t>(&rhs->m_Color_enchantment));
    ptree->appendChild("m_Unk_14_sound", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_14_sound));
    ptree->appendChild("m_Unk_16", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_16));
    ptree->appendChild("m_Unk_18_battleunit_field_58", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_18_battleunit_field_58));
    ptree->appendChild("m_ZDepth", new QMoMTreeItemModel<uint32_t>(&rhs->m_ZDepth));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Battle_Unit* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Battle_Unit>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Melee", new QMoMTreeItemModel<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new QMoMTreeItemModel<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new QMoMTreeItemModel<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new QMoMTreeItemModel<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new QMoMTreeItemModel<uint8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new QMoMTreeItemModel<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new QMoMTreeItemModel<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new QMoMTreeItemModel<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new QMoMTreeItemModel<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new QMoMTreeItemModel<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new QMoMTreeItemModel<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Building1Required_or_PortraitLbxIndex", new QMoMTreeItemModel<uint8_t>(&rhs->m_Building1Required_or_PortraitLbxIndex));
    ptree->appendChild("m_Current_figures", new QMoMTreeItemModel<uint8_t>(&rhs->m_Current_figures));
    ptree->appendChild("m_BattleUnitNr", new QMoMTreeItemModel<int8_t>(&rhs->m_BattleUnitNr));
    ptree->appendChild("m_Unk_0F", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_0F));
    ptree->appendChild("m_Hitpoints_per_Figure", new QMoMTreeItemModel<uint8_t>(&rhs->m_Hitpoints_per_Figure));
    ptree->appendChild("m_Scouting", new QMoMTreeItemModel<uint8_t>(&rhs->m_Scouting));
    ptree->appendChild("m_Transport_Capacity_GUESS", new QMoMTreeItemModel<uint8_t>(&rhs->m_Transport_Capacity_GUESS));
    ptree->appendChild("m_Max_figures", new QMoMTreeItemModel<uint8_t>(&rhs->m_Max_figures));
    ptree->appendChild("m_Construction", new QMoMTreeItemModel<uint8_t>(&rhs->m_Construction));
    ptree->appendChild("m_Gaze_Modifier", new QMoMTreeItemModel<int8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero_17", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_17));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero_1B", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_1B));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_Zero_20", new QMoMTreeItemModel<uint16_t>(&rhs->m_Zero_20));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags_Combat_Enchantment, "m_Flags_Combat_Enchantment"), "");
    ptree->appendChild("m_Extra_ToHit_Melee", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_ToHit_Melee));
    ptree->appendChild("m_Extra_ToHit_Ranged", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_ToHit_Ranged));
    ptree->appendChild("m_Extra_ToDefend", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_ToDefend));
    ptree->appendChild("m_Weapon_Type_Plus_1", new QMoMTreeItemModel<uint8_t>(&rhs->m_Weapon_Type_Plus_1));
    ptree->appendTree(constructTreeItem(&rhs->m_Cur_Attack_Flags, "m_Cur_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Item_Attack_Flags, "m_Item_Attack_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Item_UnitEnchantment, "m_Item_UnitEnchantment"), "");
    ptree->appendChild("m_unitNr", new QMoMTreeItemModel<int16_t>(&rhs->m_unitNr));
    ptree->appendChild("m_additional_life_per_figure", new QMoMTreeItemModel<int8_t>(&rhs->m_additional_life_per_figure));
    ptree->appendChild("m_web_strength", new QMoMTreeItemModel<int8_t>(&rhs->m_web_strength));
    ptree->appendChild("m_Active", new QMoMTreeItemModel<eBattleUnitActive>(&rhs->m_Active));
    ptree->appendChild("m_Owner", new QMoMTreeItemModel<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_tracks_regular_damage", new QMoMTreeItemModel<int8_t>(&rhs->m_tracks_regular_damage));
    ptree->appendChild("m_tracks_lifesteal_damage", new QMoMTreeItemModel<int8_t>(&rhs->m_tracks_lifesteal_damage));
    ptree->appendChild("m_tracks_instant_damage_like_stoning", new QMoMTreeItemModel<int8_t>(&rhs->m_tracks_instant_damage_like_stoning));
    ptree->appendChild("m_top_figure_damage", new QMoMTreeItemModel<int8_t>(&rhs->m_top_figure_damage));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags1_UnitEnchantment, "m_Flags1_UnitEnchantment"), "");
    ptree->appendChild("m_Suppression", new QMoMTreeItemModel<int8_t>(&rhs->m_Suppression));
    ptree->appendChild("m_Mana_points", new QMoMTreeItemModel<int8_t>(&rhs->m_Mana_points));
    ptree->appendChild("m_Current_mana", new QMoMTreeItemModel<int8_t>(&rhs->m_Current_mana));
    ptree->appendChild("m_Item_nr_charges", new QMoMTreeItemModel<int8_t>(&rhs->m_Item_nr_charges));
    ptree->appendChild("m_Poison_strength", new QMoMTreeItemModel<int8_t>(&rhs->m_Poison_strength));
    ptree->appendChild("m_Target_BattleUnitID", new QMoMTreeItemModel<int8_t>(&rhs->m_Target_BattleUnitID));
    ptree->appendChild("m_xPos", new QMoMTreeItemModel<int16_t>(&rhs->m_xPos));
    ptree->appendChild("m_yPos", new QMoMTreeItemModel<int16_t>(&rhs->m_yPos));
    ptree->appendChild("m_xPosHeaded", new QMoMTreeItemModel<int16_t>(&rhs->m_xPosHeaded));
    ptree->appendChild("m_yPosHeaded", new QMoMTreeItemModel<int16_t>(&rhs->m_yPosHeaded));
    ptree->appendChild("m_Unk_4C_display", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_4C_display));
    ptree->appendChild("m_Unk_4E", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_4E));
    ptree->appendChild("m_Unk_50", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_50));
    ptree->appendChild("m_Unk_52_sound", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_52_sound));
    ptree->appendChild("m_Tactic", new QMoMTreeItemModel<eBattleUnitTactic>(&rhs->m_Tactic));
    ptree->appendChild("m_Confused_State", new QMoMTreeItemModel<int8_t>(&rhs->m_Confused_State));
    ptree->appendChild("m_Unk_57", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_57));
    QMoMTreeItemModelBase* ptreem_Unk_58 = ptree;
    if (6 > 3)
    {
        ptreem_Unk_58 = new QMoMTreeItemModelBase("m_Unk_58");
        ptree->appendTree(ptreem_Unk_58, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_58[" << i << "]";
          ptreem_Unk_58->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_58[i]));
    }
    ptree->appendChild("m_Extra_Melee", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_Melee));
    ptree->appendChild("m_Extra_Ranged", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_Ranged));
    ptree->appendChild("m_Extra_Defense", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_Defense));
    ptree->appendChild("m_Extra_Resistance", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_Resistance));
    ptree->appendChild("m_Extra_Hitpoints", new QMoMTreeItemModel<uint8_t>(&rhs->m_Extra_Hitpoints));
    ptree->appendChild("m_Lost_Melee", new QMoMTreeItemModel<uint8_t>(&rhs->m_Lost_Melee));
    ptree->appendChild("m_Lost_Ranged", new QMoMTreeItemModel<uint8_t>(&rhs->m_Lost_Ranged));
    ptree->appendChild("m_Lost_Defense", new QMoMTreeItemModel<uint8_t>(&rhs->m_Lost_Defense));
    ptree->appendChild("m_Lost_Resistance", new QMoMTreeItemModel<uint8_t>(&rhs->m_Lost_Resistance));
    ptree->appendChild("m_Unused6D", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unused6D));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Battlefield* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Battlefield>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Terrain = ptree;
    if (462 > 3)
    {
        ptreem_Terrain = new QMoMTreeItemModelBase("m_Terrain");
        ptree->appendTree(ptreem_Terrain, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Terrain[" << i << "]";
          ptreem_Terrain->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eTerrainBattle>(&rhs->m_Terrain[i]));
    }
    QMoMTreeItemModelBase* ptreem_TerrainGroupType = ptree;
    if (462 > 3)
    {
        ptreem_TerrainGroupType = new QMoMTreeItemModelBase("m_TerrainGroupType");
        ptree->appendTree(ptreem_TerrainGroupType, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_TerrainGroupType[" << i << "]";
          ptreem_TerrainGroupType->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_TerrainGroupType[i]));
    }
    QMoMTreeItemModelBase* ptreem_Road = ptree;
    if (462 > 3)
    {
        ptreem_Road = new QMoMTreeItemModelBase("m_Road");
        ptree->appendTree(ptreem_Road, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Road[" << i << "]";
          ptreem_Road->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Road[i]));
    }
    QMoMTreeItemModelBase* ptreem_Movement_walking = ptree;
    if (462 > 3)
    {
        ptreem_Movement_walking = new QMoMTreeItemModelBase("m_Movement_walking");
        ptree->appendTree(ptreem_Movement_walking, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_walking[" << i << "]";
          ptreem_Movement_walking->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Movement_walking[i]));
    }
    QMoMTreeItemModelBase* ptreem_Movement_merging_teleporting_fly = ptree;
    if (462 > 3)
    {
        ptreem_Movement_merging_teleporting_fly = new QMoMTreeItemModelBase("m_Movement_merging_teleporting_fly");
        ptree->appendTree(ptreem_Movement_merging_teleporting_fly, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_merging_teleporting_fly[" << i << "]";
          ptreem_Movement_merging_teleporting_fly->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Movement_merging_teleporting_fly[i]));
    }
    QMoMTreeItemModelBase* ptreem_Movement_similar_to_walking = ptree;
    if (462 > 3)
    {
        ptreem_Movement_similar_to_walking = new QMoMTreeItemModelBase("m_Movement_similar_to_walking");
        ptree->appendTree(ptreem_Movement_similar_to_walking, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_similar_to_walking[" << i << "]";
          ptreem_Movement_similar_to_walking->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Movement_similar_to_walking[i]));
    }
    QMoMTreeItemModelBase* ptreem_Movement_sailing = ptree;
    if (462 > 3)
    {
        ptreem_Movement_sailing = new QMoMTreeItemModelBase("m_Movement_sailing");
        ptree->appendTree(ptreem_Movement_sailing, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Movement_sailing[" << i << "]";
          ptreem_Movement_sailing->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Movement_sailing[i]));
    }
    ptree->appendChild("m_Nr_tree_pics", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_tree_pics));
    QMoMTreeItemModelBase* ptreem_xpel_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_xpel_tree_pics = new QMoMTreeItemModelBase("m_xpel_tree_pics");
        ptree->appendTree(ptreem_xpel_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_xpel_tree_pics[" << i << "]";
          ptreem_xpel_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_xpel_tree_pics[i]));
    }
    QMoMTreeItemModelBase* ptreem_ypel_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_ypel_tree_pics = new QMoMTreeItemModelBase("m_ypel_tree_pics");
        ptree->appendTree(ptreem_ypel_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_ypel_tree_pics[" << i << "]";
          ptreem_ypel_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_ypel_tree_pics[i]));
    }
    QMoMTreeItemModelBase* ptreem_tree_pics = ptree;
    if (100 > 3)
    {
        ptreem_tree_pics = new QMoMTreeItemModelBase("m_tree_pics");
        ptree->appendTree(ptreem_tree_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_tree_pics[" << i << "]";
          ptreem_tree_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_tree_pics[i]));
    }
    ptree->appendChild("m_Nr_rock_pics", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_rock_pics));
    QMoMTreeItemModelBase* ptreem_xpel_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_xpel_rock_pics = new QMoMTreeItemModelBase("m_xpel_rock_pics");
        ptree->appendTree(ptreem_xpel_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_xpel_rock_pics[" << i << "]";
          ptreem_xpel_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_xpel_rock_pics[i]));
    }
    QMoMTreeItemModelBase* ptreem_ypel_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_ypel_rock_pics = new QMoMTreeItemModelBase("m_ypel_rock_pics");
        ptree->appendTree(ptreem_ypel_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_ypel_rock_pics[" << i << "]";
          ptreem_ypel_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_ypel_rock_pics[i]));
    }
    QMoMTreeItemModelBase* ptreem_rock_pics = ptree;
    if (100 > 3)
    {
        ptreem_rock_pics = new QMoMTreeItemModelBase("m_rock_pics");
        ptree->appendTree(ptreem_rock_pics, "");
    }
    for (unsigned i = 0; i < 100; ++i)
    {
          std::ostringstream oss;
          oss << "m_rock_pics[" << i << "]";
          ptreem_rock_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_rock_pics[i]));
    }
    QMoMTreeItemModelBase* ptreem_Mud = ptree;
    if (462 > 3)
    {
        ptreem_Mud = new QMoMTreeItemModelBase("m_Mud");
        ptree->appendTree(ptreem_Mud, "");
    }
    for (unsigned i = 0; i < 462; ++i)
    {
          std::ostringstream oss;
          oss << "m_Mud[" << i << "]";
          ptreem_Mud->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Mud[i]));
    }
    ptree->appendChild("m_Central_structure", new QMoMTreeItemModel<eCentralStructure>(&rhs->m_Central_structure));
    ptree->appendChild("m_Nr_houses", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_houses));
    QMoMTreeItemModelBase* ptreem_xpos_houses = ptree;
    if (16 > 3)
    {
        ptreem_xpos_houses = new QMoMTreeItemModelBase("m_xpos_houses");
        ptree->appendTree(ptreem_xpos_houses, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_xpos_houses[" << i << "]";
          ptreem_xpos_houses->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_xpos_houses[i]));
    }
    QMoMTreeItemModelBase* ptreem_ypos_houses = ptree;
    if (16 > 3)
    {
        ptreem_ypos_houses = new QMoMTreeItemModelBase("m_ypos_houses");
        ptree->appendTree(ptreem_ypos_houses, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_ypos_houses[" << i << "]";
          ptreem_ypos_houses->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_ypos_houses[i]));
    }
    QMoMTreeItemModelBase* ptreem_house_pics = ptree;
    if (16 > 3)
    {
        ptreem_house_pics = new QMoMTreeItemModelBase("m_house_pics");
        ptree->appendTree(ptreem_house_pics, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_house_pics[" << i << "]";
          ptreem_house_pics->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_house_pics[i]));
    }
    ptree->appendChild("m_City_Walls", new QMoMTreeItemModel<eYesNo16>(&rhs->m_City_Walls));
    QMoMTreeItemModelBase* ptreem_Wall_present_4x4 = ptree;
    if (16 > 3)
    {
        ptreem_Wall_present_4x4 = new QMoMTreeItemModelBase("m_Wall_present_4x4");
        ptree->appendTree(ptreem_Wall_present_4x4, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wall_present_4x4[" << i << "]";
          ptreem_Wall_present_4x4->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Wall_present_4x4[i]));
    }
    ptree->appendChild("m_Wall_of_Fire", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Wall_of_Fire));
    ptree->appendChild("m_Wall_of_Darkness", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Wall_of_Darkness));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<int16_t>(&rhs->m_Plane));
    ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(BorlandSegmentEntry* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<BorlandSegmentEntry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("base", new QMoMTreeItemModel<uint16_t>(&rhs->base));
    ptree->appendChild("size", new QMoMTreeItemModel<uint16_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItemModel<uint16_t>(&rhs->type));
    ptree->appendChild("offset", new QMoMTreeItemModel<uint16_t>(&rhs->offset));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(BorlandStub* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<BorlandStub>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreeint_code = ptree;
    if (2 > 3)
    {
        ptreeint_code = new QMoMTreeItemModelBase("int_code");
        ptree->appendTree(ptreeint_code, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "int_code[" << i << "]";
          ptreeint_code->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->int_code[i]));
    }
    ptree->appendChild("memswap", new QMoMTreeItemModel<uint16_t>(&rhs->memswap));
    ptree->appendChild("fileoff", new QMoMTreeItemModel<uint32_t>(&rhs->fileoff));
    ptree->appendChild("codesize", new QMoMTreeItemModel<uint16_t>(&rhs->codesize));
    ptree->appendChild("relsize", new QMoMTreeItemModel<uint16_t>(&rhs->relsize));
    ptree->appendChild("nentries", new QMoMTreeItemModel<uint16_t>(&rhs->nentries));
    ptree->appendChild("prevstub", new QMoMTreeItemModel<uint16_t>(&rhs->prevstub));
    QMoMTreeItemModelBase* ptreeworkarea = ptree;
    if (0x10 > 3)
    {
        ptreeworkarea = new QMoMTreeItemModelBase("workarea");
        ptree->appendTree(ptreeworkarea, "");
    }
    for (unsigned i = 0; i < 0x10; ++i)
    {
          std::ostringstream oss;
          oss << "workarea[" << i << "]";
          ptreeworkarea->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->workarea[i]));
    }
    QMoMTreeItemModelBase* ptreeentries = ptree;
    if (1 > 3)
    {
        ptreeentries = new QMoMTreeItemModelBase("entries");
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

QMoMTreeItemModelBase* constructTreeItem(BorlandStubJmpEntry* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<BorlandStubJmpEntry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("jmpfar_code", new QMoMTreeItemModel<uint8_t>(&rhs->jmpfar_code));
    ptree->appendChild("offset", new QMoMTreeItemModel<uint16_t>(&rhs->offset));
    ptree->appendChild("base_addr", new QMoMTreeItemModel<uint16_t>(&rhs->base_addr));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Building_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Building_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_BuildingName", new QMoMTreeItemModel<char[20]>(rhs->m_BuildingName));
    ptree->appendChild("m_Prerequisite1", new QMoMTreeItemModel<eBuilding>(&rhs->m_Prerequisite1));
    ptree->appendChild("m_Prerequisite2", new QMoMTreeItemModel<eBuilding>(&rhs->m_Prerequisite2));
    ptree->appendChild("m_Replaces_building", new QMoMTreeItemModel<eBuilding>(&rhs->m_Replaces_building));
    ptree->appendChild("m_Produces_Regulars", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Produces_Regulars));
    ptree->appendChild("m_Produces_Veterans", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Produces_Veterans));
    ptree->appendChild("m_Produces_Magic_Weapons", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Produces_Magic_Weapons));
    ptree->appendChild("m_Upkeep_yield", new QMoMTreeItemModel<int16_t>(&rhs->m_Upkeep_yield));
    ptree->appendChild("m_AI_trade_goods_housing", new QMoMTreeItemModel<int16_t>(&rhs->m_AI_trade_goods_housing));
    ptree->appendChild("m_Zero_24", new QMoMTreeItemModel<int16_t>(&rhs->m_Zero_24));
    ptree->appendChild("m_Zero_26", new QMoMTreeItemModel<int16_t>(&rhs->m_Zero_26));
    ptree->appendChild("m_AI_Religious", new QMoMTreeItemModel<int16_t>(&rhs->m_AI_Religious));
    ptree->appendChild("m_AI_Research", new QMoMTreeItemModel<int16_t>(&rhs->m_AI_Research));
    ptree->appendChild("m_Building_cost", new QMoMTreeItemModel<int16_t>(&rhs->m_Building_cost));
    ptree->appendChild("m_Zero_2E", new QMoMTreeItemModel<int16_t>(&rhs->m_Zero_2E));
    ptree->appendChild("m_Animation_related", new QMoMTreeItemModel<int16_t>(&rhs->m_Animation_related));
    ptree->appendChild("m_Building_category", new QMoMTreeItemModel<eBuildingCategory>(&rhs->m_Building_category));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Building_Status* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Building_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("No_building", new QMoMTreeItemModel<eBuildingStatus>(&rhs->No_building));
    ptree->appendChild("Trade_Goods", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Trade_Goods));
    ptree->appendChild("Housing", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Housing));
    ptree->appendChild("Barracks", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Barracks));
    ptree->appendChild("Armory", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Armory));
    ptree->appendChild("Fighters_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Fighters_Guild));
    ptree->appendChild("Armorers_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Armorers_Guild));
    ptree->appendChild("War_College", new QMoMTreeItemModel<eBuildingStatus>(&rhs->War_College));
    ptree->appendChild("Smithy", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Smithy));
    ptree->appendChild("Stable", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Stable));
    ptree->appendChild("Animists_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Animists_Guild));
    ptree->appendChild("Fantastic_Stable", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Fantastic_Stable));
    ptree->appendChild("Shipwright_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Shipwright_Guild));
    ptree->appendChild("Ship_Yard", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Ship_Yard));
    ptree->appendChild("Maritime_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Maritime_Guild));
    ptree->appendChild("Sawmill", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Sawmill));
    ptree->appendChild("Library", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Library));
    ptree->appendChild("Sages_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Sages_Guild));
    ptree->appendChild("Oracle", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Oracle));
    ptree->appendChild("Alchemist_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Alchemist_Guild));
    ptree->appendChild("University", new QMoMTreeItemModel<eBuildingStatus>(&rhs->University));
    ptree->appendChild("Wizards_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Wizards_Guild));
    ptree->appendChild("Shrine", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Shrine));
    ptree->appendChild("Temple", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Temple));
    ptree->appendChild("Parthenon", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Parthenon));
    ptree->appendChild("Cathedral", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Cathedral));
    ptree->appendChild("Marketplace", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Marketplace));
    ptree->appendChild("Bank", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Bank));
    ptree->appendChild("Merchants_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Merchants_Guild));
    ptree->appendChild("Granary", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Granary));
    ptree->appendChild("Farmers_Market", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Farmers_Market));
    ptree->appendChild("Foresters_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Foresters_Guild));
    ptree->appendChild("Builders_Hall", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Builders_Hall));
    ptree->appendChild("Mechanicians_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Mechanicians_Guild));
    ptree->appendChild("Miners_Guild", new QMoMTreeItemModel<eBuildingStatus>(&rhs->Miners_Guild));
    ptree->appendChild("City_Walls", new QMoMTreeItemModel<eBuildingStatus>(&rhs->City_Walls));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(City* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<City>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Name", new QMoMTreeItemModel<char[14]>(rhs->m_City_Name));
    ptree->appendChild("m_Race", new QMoMTreeItemModel<eRace>(&rhs->m_Race));
    ptree->appendChild("m_XPos", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItemModel<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Size", new QMoMTreeItemModel<eCity_Size>(&rhs->m_Size));
    ptree->appendChild("m_Population", new QMoMTreeItemModel<int8_t>(&rhs->m_Population));
    ptree->appendChild("m_Number_of_farmers_allocated", new QMoMTreeItemModel<int8_t>(&rhs->m_Number_of_farmers_allocated));
    ptree->appendChild("m_Building_sold", new QMoMTreeItemModel<eYesNo8>(&rhs->m_Building_sold));
    ptree->appendChild("m_Unk_17", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_17));
    ptree->appendChild("m_PopulationDekaPop", new QMoMTreeItemModel<int16_t>(&rhs->m_PopulationDekaPop));
    ptree->appendChild("m_Player_as_bitmask_GUESS", new QMoMTreeItemModel<uint8_t>(&rhs->m_Player_as_bitmask_GUESS));
    ptree->appendChild("m_Unk_1B", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_1B));
    ptree->appendChild("m_Producing", new QMoMTreeItemModel<eProducing>(&rhs->m_Producing));
    ptree->appendChild("m_Nr_buildings", new QMoMTreeItemModel<uint8_t>(&rhs->m_Nr_buildings));
    ptree->appendTree(constructTreeItem(&rhs->m_Building_Status, "m_Building_Status"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_City_Enchantments, "m_City_Enchantments"), "");
    ptree->appendChild("m_Nightshade", new QMoMTreeItemModel<eYesNo8>(&rhs->m_Nightshade));
    ptree->appendChild("m_Hammers", new QMoMTreeItemModel<int8_t>(&rhs->m_Hammers));
    ptree->appendChild("m_HammersAccumulated", new QMoMTreeItemModel<int16_t>(&rhs->m_HammersAccumulated));
    ptree->appendChild("m_Coins", new QMoMTreeItemModel<int8_t>(&rhs->m_Coins));
    ptree->appendChild("m_Maintenance", new QMoMTreeItemModel<int8_t>(&rhs->m_Maintenance));
    ptree->appendChild("m_Mana_cr", new QMoMTreeItemModel<int8_t>(&rhs->m_Mana_cr));
    ptree->appendChild("m_Research", new QMoMTreeItemModel<int8_t>(&rhs->m_Research));
    ptree->appendChild("m_Food_Produced", new QMoMTreeItemModel<int8_t>(&rhs->m_Food_Produced));
    ptree->appendChild("m_Road_Connection_GUESS", new QMoMTreeItemModel<int8_t>(&rhs->m_Road_Connection_GUESS));
    QMoMTreeItemModelBase* ptreem_Unk_66 = ptree;
    if (12 > 3)
    {
        ptreem_Unk_66 = new QMoMTreeItemModelBase("m_Unk_66");
        ptree->appendTree(ptreem_Unk_66, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_66[" << i << "]";
          ptreem_Unk_66->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_66[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(CityQueueElement* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<CityQueueElement>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_CityNr", new QMoMTreeItemModel<int8_t>(&rhs->m_CityNr));
    ptree->appendChild("m_Unused_01", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unused_01));
    ptree->appendChild("m_Producing", new QMoMTreeItemModel<eProducing>(&rhs->m_Producing));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(City_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<City_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Wall_of_Fire", new QMoMTreeItemModel<eOwner>(&rhs->Wall_of_Fire));
    ptree->appendChild("_Chaos_Rift_", new QMoMTreeItemModel<eOwner>(&rhs->_Chaos_Rift_));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItemModel<eOwner>(&rhs->Dark_Rituals));
    ptree->appendChild("_Evil_Presence_", new QMoMTreeItemModel<eOwner>(&rhs->_Evil_Presence_));
    ptree->appendChild("_Cursed_Lands_", new QMoMTreeItemModel<eOwner>(&rhs->_Cursed_Lands_));
    ptree->appendChild("_Pestilence_", new QMoMTreeItemModel<eOwner>(&rhs->_Pestilence_));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItemModel<eOwner>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("_Famine_", new QMoMTreeItemModel<eOwner>(&rhs->_Famine_));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItemModel<eOwner>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new QMoMTreeItemModel<eOwner>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new QMoMTreeItemModel<eOwner>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new QMoMTreeItemModel<eOwner>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new QMoMTreeItemModel<eOwner>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new QMoMTreeItemModel<eOwner>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new QMoMTreeItemModel<eOwner>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new QMoMTreeItemModel<eOwner>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItemModel<eOwner>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItemModel<eOwner>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new QMoMTreeItemModel<eOwner>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new QMoMTreeItemModel<eOwner>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new QMoMTreeItemModel<eOwner>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItemModel<eOwner>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new QMoMTreeItemModel<eOwner>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItemModel<eOwner>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItemModel<eOwner>(&rhs->Altar_of_Battle));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Combat_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Combat_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    Combat_Enchantment maskVertigo;
    memset(&maskVertigo, '\0', sizeof(maskVertigo));
    maskVertigo.Vertigo = 1;
    if (1 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVertigo));
    else if (2 == sizeof(maskVertigo))
        ptree->appendChild("Vertigo", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVertigo));
    else
        ptree->appendChild("Vertigo", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVertigo));
    Combat_Enchantment maskConfusion;
    memset(&maskConfusion, '\0', sizeof(maskConfusion));
    maskConfusion.Confusion = 1;
    if (1 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConfusion));
    else if (2 == sizeof(maskConfusion))
        ptree->appendChild("Confusion", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConfusion));
    else
        ptree->appendChild("Confusion", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConfusion));
    Combat_Enchantment maskWhirlwind;
    memset(&maskWhirlwind, '\0', sizeof(maskWhirlwind));
    maskWhirlwind.Whirlwind = 1;
    if (1 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWhirlwind));
    else if (2 == sizeof(maskWhirlwind))
        ptree->appendChild("Whirlwind", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWhirlwind));
    else
        ptree->appendChild("Whirlwind", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWhirlwind));
    Combat_Enchantment maskMind_Storm;
    memset(&maskMind_Storm, '\0', sizeof(maskMind_Storm));
    maskMind_Storm.Mind_Storm = 1;
    if (1 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Storm));
    else if (2 == sizeof(maskMind_Storm))
        ptree->appendChild("Mind_Storm", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Storm));
    else
        ptree->appendChild("Mind_Storm", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Storm));
    Combat_Enchantment maskShatter;
    memset(&maskShatter, '\0', sizeof(maskShatter));
    maskShatter.Shatter = 1;
    if (1 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskShatter));
    else if (2 == sizeof(maskShatter))
        ptree->appendChild("Shatter", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskShatter));
    else
        ptree->appendChild("Shatter", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskShatter));
    Combat_Enchantment maskWeakness;
    memset(&maskWeakness, '\0', sizeof(maskWeakness));
    maskWeakness.Weakness = 1;
    if (1 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeakness));
    else if (2 == sizeof(maskWeakness))
        ptree->appendChild("Weakness", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeakness));
    else
        ptree->appendChild("Weakness", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeakness));
    Combat_Enchantment maskBlack_Sleep;
    memset(&maskBlack_Sleep, '\0', sizeof(maskBlack_Sleep));
    maskBlack_Sleep.Black_Sleep = 1;
    if (1 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Sleep));
    else if (2 == sizeof(maskBlack_Sleep))
        ptree->appendChild("Black_Sleep", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Sleep));
    else
        ptree->appendChild("Black_Sleep", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Sleep));
    Combat_Enchantment maskWarp_Creature_Attack;
    memset(&maskWarp_Creature_Attack, '\0', sizeof(maskWarp_Creature_Attack));
    maskWarp_Creature_Attack.Warp_Creature_Attack = 1;
    if (1 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Attack));
    else if (2 == sizeof(maskWarp_Creature_Attack))
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Attack));
    else
        ptree->appendChild("Warp_Creature_Attack", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Attack));
    Combat_Enchantment maskWarp_Creature_Defense;
    memset(&maskWarp_Creature_Defense, '\0', sizeof(maskWarp_Creature_Defense));
    maskWarp_Creature_Defense.Warp_Creature_Defense = 1;
    if (1 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Defense));
    else if (2 == sizeof(maskWarp_Creature_Defense))
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Defense));
    else
        ptree->appendChild("Warp_Creature_Defense", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Defense));
    Combat_Enchantment maskWarp_Creature_Resistance;
    memset(&maskWarp_Creature_Resistance, '\0', sizeof(maskWarp_Creature_Resistance));
    maskWarp_Creature_Resistance.Warp_Creature_Resistance = 1;
    if (1 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWarp_Creature_Resistance));
    else if (2 == sizeof(maskWarp_Creature_Resistance))
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWarp_Creature_Resistance));
    else
        ptree->appendChild("Warp_Creature_Resistance", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWarp_Creature_Resistance));
    Combat_Enchantment maskMind_Twist;
    memset(&maskMind_Twist, '\0', sizeof(maskMind_Twist));
    maskMind_Twist.Mind_Twist = 1;
    if (1 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMind_Twist));
    else if (2 == sizeof(maskMind_Twist))
        ptree->appendChild("Mind_Twist", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMind_Twist));
    else
        ptree->appendChild("Mind_Twist", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMind_Twist));
    Combat_Enchantment maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 1;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Combat_Enchantment maskWeb;
    memset(&maskWeb, '\0', sizeof(maskWeb));
    maskWeb.Web = 1;
    if (1 == sizeof(maskWeb))
        ptree->appendChild("Web", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeb));
    else if (2 == sizeof(maskWeb))
        ptree->appendChild("Web", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeb));
    else
        ptree->appendChild("Web", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeb));
    Combat_Enchantment maskCreature_Binding;
    memset(&maskCreature_Binding, '\0', sizeof(maskCreature_Binding));
    maskCreature_Binding.Creature_Binding = 1;
    if (1 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCreature_Binding));
    else if (2 == sizeof(maskCreature_Binding))
        ptree->appendChild("Creature_Binding", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCreature_Binding));
    else
        ptree->appendChild("Creature_Binding", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCreature_Binding));
    Combat_Enchantment maskPossession;
    memset(&maskPossession, '\0', sizeof(maskPossession));
    maskPossession.Possession = 1;
    if (1 == sizeof(maskPossession))
        ptree->appendChild("Possession", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPossession));
    else if (2 == sizeof(maskPossession))
        ptree->appendChild("Possession", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPossession));
    else
        ptree->appendChild("Possession", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPossession));
    Combat_Enchantment maskNo_Effect80;
    memset(&maskNo_Effect80, '\0', sizeof(maskNo_Effect80));
    maskNo_Effect80.No_Effect80 = 1;
    if (1 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNo_Effect80));
    else if (2 == sizeof(maskNo_Effect80))
        ptree->appendChild("No_Effect80", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNo_Effect80));
    else
        ptree->appendChild("No_Effect80", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNo_Effect80));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Difficulty_Table* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Difficulty_Table>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_City_Growth_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Growth_multiplier));
    ptree->appendChild("m_Outpost_Growth_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_Outpost_Growth_multiplier));
    ptree->appendChild("m_City_Production_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Production_multiplier));
    ptree->appendChild("m_City_Coin_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Coin_multiplier));
    ptree->appendChild("m_City_Mana_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Mana_multiplier));
    ptree->appendChild("m_City_Research_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Research_multiplier));
    ptree->appendChild("m_City_Food_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_Food_multiplier));
    ptree->appendChild("m_Maintenance_multiplier", new QMoMTreeItemModel<int16_t>(&rhs->m_Maintenance_multiplier));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(EMS_descriptor* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<EMS_descriptor>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_name", new QMoMTreeItemModel<char[9]>(rhs->m_name));
    ptree->appendChild("m_Unk_09", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_09));
    ptree->appendChild("m_Unk_0A", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_0A));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(EXE_Header* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<EXE_Header>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("signature", new QMoMTreeItemModel<uint16_t>(&rhs->signature));
    ptree->appendChild("bytes_in_last_block", new QMoMTreeItemModel<uint16_t>(&rhs->bytes_in_last_block));
    ptree->appendChild("blocks_in_file", new QMoMTreeItemModel<uint16_t>(&rhs->blocks_in_file));
    ptree->appendChild("nr_relocation_items", new QMoMTreeItemModel<uint16_t>(&rhs->nr_relocation_items));
    ptree->appendChild("load_module_offset_paragraphs", new QMoMTreeItemModel<uint16_t>(&rhs->load_module_offset_paragraphs));
    ptree->appendChild("min_needed_paragraphs", new QMoMTreeItemModel<uint16_t>(&rhs->min_needed_paragraphs));
    ptree->appendChild("max_needed_paragraphs", new QMoMTreeItemModel<uint16_t>(&rhs->max_needed_paragraphs));
    ptree->appendChild("ss_offset_in_load_module_paragraphs", new QMoMTreeItemModel<uint16_t>(&rhs->ss_offset_in_load_module_paragraphs));
    ptree->appendChild("sp_initial", new QMoMTreeItemModel<uint16_t>(&rhs->sp_initial));
    ptree->appendChild("checksum", new QMoMTreeItemModel<uint16_t>(&rhs->checksum));
    ptree->appendChild("ip_program_entry_point", new QMoMTreeItemModel<uint16_t>(&rhs->ip_program_entry_point));
    ptree->appendChild("cs_offset_in_load_module_paragraphs", new QMoMTreeItemModel<uint16_t>(&rhs->cs_offset_in_load_module_paragraphs));
    ptree->appendChild("relocation_table_offset_bytes", new QMoMTreeItemModel<uint16_t>(&rhs->relocation_table_offset_bytes));
    ptree->appendChild("overlay_number", new QMoMTreeItemModel<uint16_t>(&rhs->overlay_number));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(EXE_Reloc* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<EXE_Reloc>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("offset", new QMoMTreeItemModel<uint16_t>(&rhs->offset));
    ptree->appendChild("segment", new QMoMTreeItemModel<uint16_t>(&rhs->segment));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Events_Status* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Events_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Turn_Event_triggered_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Turn_Event_triggered_GUESS));
    ptree->appendChild("m_Meteor_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Meteor_active));
    ptree->appendChild("m_Meteor_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Meteor_playerNr));
    ptree->appendChild("m_Meteor_cityNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Meteor_cityNr));
    ptree->appendChild("m_Gift_of_the_Gods_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Gift_of_the_Gods_active));
    ptree->appendChild("m_Gift_of_the_Gods_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Gift_of_the_Gods_playerNr));
    ptree->appendChild("m_Gift_of_the_Gods_itemNr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Gift_of_the_Gods_itemNr_GUESS));
    ptree->appendChild("m_Disjunction_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Disjunction_active));
    ptree->appendChild("m_Diplomatic_Marriage_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Diplomatic_Marriage_active));
    ptree->appendChild("m_Diplomatic_Marriage_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Diplomatic_Marriage_playerNr));
    ptree->appendChild("m_Diplomatic_Marriage_newCityNr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Diplomatic_Marriage_newCityNr_GUESS));
    ptree->appendChild("m_Diplomatic_Marriage_cityNr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Diplomatic_Marriage_cityNr_GUESS));
    ptree->appendChild("m_Earthquake_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Earthquake_active));
    ptree->appendChild("m_Earthquake_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Earthquake_playerNr));
    ptree->appendChild("m_Earthquake_cityNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Earthquake_cityNr));
    ptree->appendChild("m_Pirates_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Pirates_active));
    ptree->appendChild("m_Pirates_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Pirates_playerNr));
    ptree->appendChild("m_Pirates_gold_stolen", new QMoMTreeItemModel<uint16_t>(&rhs->m_Pirates_gold_stolen));
    ptree->appendChild("m_Plague_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Plague_active));
    ptree->appendChild("m_Plague_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Plague_playerNr));
    ptree->appendChild("m_Plague_cityNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Plague_cityNr));
    ptree->appendChild("m_UNUSED01", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED01));
    ptree->appendChild("m_Rebellion_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Rebellion_active));
    ptree->appendChild("m_Rebellion_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Rebellion_playerNr));
    ptree->appendChild("m_Rebellion_cityNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Rebellion_cityNr));
    ptree->appendChild("m_Donation_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Donation_active));
    ptree->appendChild("m_Donation_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Donation_playerNr));
    ptree->appendChild("m_Donation_gold_donated", new QMoMTreeItemModel<uint16_t>(&rhs->m_Donation_gold_donated));
    ptree->appendChild("m_Depletion_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Depletion_active));
    ptree->appendChild("m_Depletion_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Depletion_playerNr));
    ptree->appendChild("m_UNUSED02", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED02));
    ptree->appendChild("m_Mine_found_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Mine_found_active));
    ptree->appendChild("m_Mine_found_playerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Mine_found_playerNr));
    ptree->appendChild("m_UNUSED03", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED03));
    ptree->appendChild("m_Population_Boom_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Population_Boom_active));
    ptree->appendChild("m_Population_Boom_CityNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Population_Boom_CityNr));
    ptree->appendChild("m_Population_Boom_PlayerNr", new QMoMTreeItemModel<uint16_t>(&rhs->m_Population_Boom_PlayerNr));
    ptree->appendChild("m_UNUSED04", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED04));
    ptree->appendChild("m_Good_Moon_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Good_Moon_active));
    ptree->appendChild("m_UNUSED05", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED05));
    ptree->appendChild("m_Bad_Moon_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Bad_Moon_active));
    ptree->appendChild("m_UNUSED06", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED06));
    ptree->appendChild("m_Conjunction_Sorcery_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Sorcery_active));
    ptree->appendChild("m_Conjunction_Sorcery_Nr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Sorcery_Nr_GUESS));
    ptree->appendChild("m_Conjunction_Nature_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Nature_active));
    ptree->appendChild("m_Conjunction_Nature_Nr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Nature_Nr_GUESS));
    ptree->appendChild("m_Conjunction_Chaos_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Chaos_active));
    ptree->appendChild("m_Conjunction_Chaos_Nr_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_Conjunction_Chaos_Nr_GUESS));
    ptree->appendChild("m_Mana_Short_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Mana_Short_active));
    ptree->appendChild("m_UNUSED10", new QMoMTreeItemModel<uint16_t>(&rhs->m_UNUSED10));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(FLIC_COLOR_64* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<FLIC_COLOR_64>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("size", new QMoMTreeItemModel<uint32_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItemModel<uint16_t>(&rhs->type));
    ptree->appendChild("chunks", new QMoMTreeItemModel<uint16_t>(&rhs->chunks));
    ptree->appendChild("skip", new QMoMTreeItemModel<uint16_t>(&rhs->skip));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(FLIC_FLI_COPY* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<FLIC_FLI_COPY>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("size", new QMoMTreeItemModel<uint32_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItemModel<uint16_t>(&rhs->type));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(FLIC_FRAME_TYPE* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<FLIC_FRAME_TYPE>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("size", new QMoMTreeItemModel<uint32_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItemModel<uint16_t>(&rhs->type));
    ptree->appendChild("chunks", new QMoMTreeItemModel<uint16_t>(&rhs->chunks));
    ptree->appendChild("delay", new QMoMTreeItemModel<uint16_t>(&rhs->delay));
    ptree->appendChild("reserved", new QMoMTreeItemModel<int16_t>(&rhs->reserved));
    ptree->appendChild("width", new QMoMTreeItemModel<uint16_t>(&rhs->width));
    ptree->appendChild("height", new QMoMTreeItemModel<uint16_t>(&rhs->height));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(FLIC_HEADER* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<FLIC_HEADER>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("size", new QMoMTreeItemModel<uint32_t>(&rhs->size));
    ptree->appendChild("type", new QMoMTreeItemModel<uint16_t>(&rhs->type));
    ptree->appendChild("frames", new QMoMTreeItemModel<uint16_t>(&rhs->frames));
    ptree->appendChild("width", new QMoMTreeItemModel<uint16_t>(&rhs->width));
    ptree->appendChild("height", new QMoMTreeItemModel<uint16_t>(&rhs->height));
    ptree->appendChild("depth", new QMoMTreeItemModel<uint16_t>(&rhs->depth));
    ptree->appendChild("flags", new QMoMTreeItemModel<uint16_t>(&rhs->flags));
    ptree->appendChild("speed", new QMoMTreeItemModel<uint32_t>(&rhs->speed));
    ptree->appendChild("reserved1", new QMoMTreeItemModel<uint16_t>(&rhs->reserved1));
    ptree->appendChild("created", new QMoMTreeItemModel<uint32_t>(&rhs->created));
    ptree->appendChild("creator", new QMoMTreeItemModel<uint32_t>(&rhs->creator));
    ptree->appendChild("updated", new QMoMTreeItemModel<uint32_t>(&rhs->updated));
    ptree->appendChild("updater", new QMoMTreeItemModel<uint32_t>(&rhs->updater));
    ptree->appendChild("aspect_dx", new QMoMTreeItemModel<uint16_t>(&rhs->aspect_dx));
    ptree->appendChild("aspect_dy", new QMoMTreeItemModel<uint16_t>(&rhs->aspect_dy));
    ptree->appendChild("ext_flags", new QMoMTreeItemModel<uint16_t>(&rhs->ext_flags));
    ptree->appendChild("keyframes", new QMoMTreeItemModel<uint16_t>(&rhs->keyframes));
    ptree->appendChild("totalframes", new QMoMTreeItemModel<uint16_t>(&rhs->totalframes));
    ptree->appendChild("req_memory", new QMoMTreeItemModel<uint32_t>(&rhs->req_memory));
    ptree->appendChild("max_regions", new QMoMTreeItemModel<uint16_t>(&rhs->max_regions));
    ptree->appendChild("transp_num", new QMoMTreeItemModel<uint16_t>(&rhs->transp_num));
    QMoMTreeItemModelBase* ptreereserved2 = ptree;
    if (24 > 3)
    {
        ptreereserved2 = new QMoMTreeItemModelBase("reserved2");
        ptree->appendTree(ptreereserved2, "");
    }
    for (unsigned i = 0; i < 24; ++i)
    {
          std::ostringstream oss;
          oss << "reserved2[" << i << "]";
          ptreereserved2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->reserved2[i]));
    }
    ptree->appendChild("oframe1", new QMoMTreeItemModel<uint32_t>(&rhs->oframe1));
    ptree->appendChild("oframe2", new QMoMTreeItemModel<uint32_t>(&rhs->oframe2));
    QMoMTreeItemModelBase* ptreereserved3 = ptree;
    if (40 > 3)
    {
        ptreereserved3 = new QMoMTreeItemModelBase("reserved3");
        ptree->appendTree(ptreereserved3, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "reserved3[" << i << "]";
          ptreereserved3->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->reserved3[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Fortress* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Fortress>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Active", new QMoMTreeItemModel<int8_t>(&rhs->m_Active));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Game_Data_Save* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Game_Data_Save>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Number_of_Wizards", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Wizards));
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItemModel<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size_setting));
    }
    else
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItemModel<eLand_Size>(&rhs->m_Land_Size_setting));
    }
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItemModel<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful_setting));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItemModel<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    }
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty>(&rhs->m_Difficulty));
    }
    ptree->appendChild("m_Number_of_Cities", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Cities));
    ptree->appendChild("m_Number_of_Units", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Current_Turn", new QMoMTreeItemModel<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_UnitNr_Active", new QMoMTreeItemModel<uint16_t>(&rhs->m_UnitNr_Active));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Game_Settings* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Game_Settings>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Sound_Effects", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Sound_Effects));
    ptree->appendChild("m_Background_Music", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Background_Music));
    ptree->appendChild("m_Event_Music", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Event_Music));
    ptree->appendChild("m_City_Spell_Events", new QMoMTreeItemModel<eYesNo16>(&rhs->m_City_Spell_Events));
    ptree->appendChild("m_Overland_Spell_Events", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Overland_Spell_Events));
    ptree->appendChild("m_Summoning_Events", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Summoning_Events));
    ptree->appendChild("m_End_of_Turn_Summary", new QMoMTreeItemModel<eYesNo16>(&rhs->m_End_of_Turn_Summary));
    ptree->appendChild("m_Raze_City", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Raze_City));
    ptree->appendChild("m_Random_Events", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Random_Events));
    ptree->appendChild("m_End_of_Turn_Wait", new QMoMTreeItemModel<eYesNo16>(&rhs->m_End_of_Turn_Wait));
    ptree->appendChild("m_Stratic_Combat_Only", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Stratic_Combat_Only));
    ptree->appendChild("m_Auto_Unit_Information", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Auto_Unit_Information));
    ptree->appendChild("m_Enemy_Moves", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Enemy_Moves));
    ptree->appendChild("m_Enemy_Spells", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Enemy_Spells));
    ptree->appendChild("m_Spell_Book_Ordering", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Spell_Book_Ordering));
    ptree->appendChild("m_Spell_Animations", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Spell_Animations));
    ptree->appendChild("m_Show_Node_Owners", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Show_Node_Owners));
    ptree->appendChild("m_Expanding_Help", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Expanding_Help));
    ptree->appendChild("m_Unk_024", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_024));
    ptree->appendChild("m_Unk_026", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_026));
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty>(&rhs->m_Difficulty));
    }
    ptree->appendChild("m_Nr_Opponents", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_Opponents));
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size", new QMoMTreeItemModel<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size));
    }
    else
    {
        ptree->appendChild("m_Land_Size", new QMoMTreeItemModel<eLand_Size>(&rhs->m_Land_Size));
    }
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful", new QMoMTreeItemModel<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful", new QMoMTreeItemModel<eMagic_Powerful>(&rhs->m_Magic_Powerful));
    }
    QMoMTreeItemModelBase* ptreem_Slots_Saved = ptree;
    if (8 > 3)
    {
        ptreem_Slots_Saved = new QMoMTreeItemModelBase("m_Slots_Saved");
        ptree->appendTree(ptreem_Slots_Saved, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slots_Saved[" << i << "]";
          ptreem_Slots_Saved->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eYesNo16>(&rhs->m_Slots_Saved[i]));
    }
    QMoMTreeItemModelBase* ptreem_Save_Names = ptree;
    if (8 > 3)
    {
        ptreem_Save_Names = new QMoMTreeItemModelBase("m_Save_Names");
        ptree->appendTree(ptreem_Save_Names, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Names[" << i << "]";
          ptreem_Save_Names->appendTree(constructTreeItem(&rhs->m_Save_Names[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Movement_Animations", new QMoMTreeItemModel<eYesNo16>(&rhs->m_Movement_Animations));
    QMoMTreeItemModelBase* ptreem_Save_Wizard_Names = ptree;
    if (10 > 3)
    {
        ptreem_Save_Wizard_Names = new QMoMTreeItemModelBase("m_Save_Wizard_Names");
        ptree->appendTree(ptreem_Save_Wizard_Names, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Save_Wizard_Names[" << i << "]";
          ptreem_Save_Wizard_Names->appendTree(constructTreeItem(&rhs->m_Save_Wizard_Names[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unk_1AA = ptree;
    if (20 > 3)
    {
        ptreem_Unk_1AA = new QMoMTreeItemModelBase("m_Unk_1AA");
        ptree->appendTree(ptreem_Unk_1AA, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_1AA[" << i << "]";
          ptreem_Unk_1AA->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_1AA[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Global_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Global_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Eternal_Night", new QMoMTreeItemModel<uint8_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItemModel<uint8_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItemModel<uint8_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItemModel<uint8_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItemModel<uint8_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItemModel<uint8_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItemModel<uint8_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItemModel<uint8_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItemModel<uint8_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItemModel<uint8_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItemModel<uint8_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItemModel<uint8_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new QMoMTreeItemModel<uint8_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItemModel<uint8_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new QMoMTreeItemModel<uint8_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new QMoMTreeItemModel<uint8_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new QMoMTreeItemModel<uint8_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new QMoMTreeItemModel<uint8_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new QMoMTreeItemModel<uint8_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new QMoMTreeItemModel<uint8_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new QMoMTreeItemModel<uint8_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItemModel<uint8_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new QMoMTreeItemModel<uint8_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new QMoMTreeItemModel<uint8_t>(&rhs->Awareness));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(HelpLBXentry* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<HelpLBXentry>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("title", new QMoMTreeItemModel<char[30]>(rhs->title));
    ptree->appendChild("lbxFile", new QMoMTreeItemModel<char[14]>(rhs->lbxFile));
    ptree->appendChild("lbxIndex", new QMoMTreeItemModel<uint16_t>(&rhs->lbxIndex));
    ptree->appendChild("zero_2E", new QMoMTreeItemModel<uint16_t>(&rhs->zero_2E));
    ptree->appendChild("description", new QMoMTreeItemModel<char[1000]>(rhs->description));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Hero_Ability* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Hero_Ability>(rhs, context);
    if (0 == rhs)
        return ptree;

    Hero_Ability maskLeadership;
    memset(&maskLeadership, '\0', sizeof(maskLeadership));
    maskLeadership.Leadership = 1;
    if (1 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership));
    else if (2 == sizeof(maskLeadership))
        ptree->appendChild("Leadership", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership));
    else
        ptree->appendChild("Leadership", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership));
    Hero_Ability maskLeadership_X;
    memset(&maskLeadership_X, '\0', sizeof(maskLeadership_X));
    maskLeadership_X.Leadership_X = 1;
    if (1 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLeadership_X));
    else if (2 == sizeof(maskLeadership_X))
        ptree->appendChild("Leadership_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLeadership_X));
    else
        ptree->appendChild("Leadership_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLeadership_X));
    Hero_Ability masku1;
    memset(&masku1, '\0', sizeof(masku1));
    masku1.u1 = 1;
    if (1 == sizeof(masku1))
        ptree->appendChild("u1", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku1));
    else if (2 == sizeof(masku1))
        ptree->appendChild("u1", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku1));
    else
        ptree->appendChild("u1", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku1));
    Hero_Ability maskLegendary;
    memset(&maskLegendary, '\0', sizeof(maskLegendary));
    maskLegendary.Legendary = 1;
    if (1 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary));
    else if (2 == sizeof(maskLegendary))
        ptree->appendChild("Legendary", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary));
    else
        ptree->appendChild("Legendary", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary));
    Hero_Ability maskLegendary_X;
    memset(&maskLegendary_X, '\0', sizeof(maskLegendary_X));
    maskLegendary_X.Legendary_X = 1;
    if (1 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLegendary_X));
    else if (2 == sizeof(maskLegendary_X))
        ptree->appendChild("Legendary_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLegendary_X));
    else
        ptree->appendChild("Legendary_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLegendary_X));
    Hero_Ability masku0;
    memset(&masku0, '\0', sizeof(masku0));
    masku0.u0 = 1;
    if (1 == sizeof(masku0))
        ptree->appendChild("u0", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku0));
    else if (2 == sizeof(masku0))
        ptree->appendChild("u0", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku0));
    else
        ptree->appendChild("u0", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku0));
    Hero_Ability maskBlademaster;
    memset(&maskBlademaster, '\0', sizeof(maskBlademaster));
    maskBlademaster.Blademaster = 1;
    if (1 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster));
    else if (2 == sizeof(maskBlademaster))
        ptree->appendChild("Blademaster", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster));
    else
        ptree->appendChild("Blademaster", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster));
    Hero_Ability maskBlademaster_X;
    memset(&maskBlademaster_X, '\0', sizeof(maskBlademaster_X));
    maskBlademaster_X.Blademaster_X = 1;
    if (1 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlademaster_X));
    else if (2 == sizeof(maskBlademaster_X))
        ptree->appendChild("Blademaster_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlademaster_X));
    else
        ptree->appendChild("Blademaster_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlademaster_X));
    Hero_Ability masku4;
    memset(&masku4, '\0', sizeof(masku4));
    masku4.u4 = 1;
    if (1 == sizeof(masku4))
        ptree->appendChild("u4", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku4));
    else if (2 == sizeof(masku4))
        ptree->appendChild("u4", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku4));
    else
        ptree->appendChild("u4", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku4));
    Hero_Ability maskArmsmaster;
    memset(&maskArmsmaster, '\0', sizeof(maskArmsmaster));
    maskArmsmaster.Armsmaster = 1;
    if (1 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster));
    else if (2 == sizeof(maskArmsmaster))
        ptree->appendChild("Armsmaster", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster));
    else
        ptree->appendChild("Armsmaster", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster));
    Hero_Ability maskArmsmaster_X;
    memset(&maskArmsmaster_X, '\0', sizeof(maskArmsmaster_X));
    maskArmsmaster_X.Armsmaster_X = 1;
    if (1 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArmsmaster_X));
    else if (2 == sizeof(maskArmsmaster_X))
        ptree->appendChild("Armsmaster_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArmsmaster_X));
    else
        ptree->appendChild("Armsmaster_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArmsmaster_X));
    Hero_Ability masku3;
    memset(&masku3, '\0', sizeof(masku3));
    masku3.u3 = 1;
    if (1 == sizeof(masku3))
        ptree->appendChild("u3", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku3));
    else if (2 == sizeof(masku3))
        ptree->appendChild("u3", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku3));
    else
        ptree->appendChild("u3", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku3));
    Hero_Ability maskConstitution;
    memset(&maskConstitution, '\0', sizeof(maskConstitution));
    maskConstitution.Constitution = 1;
    if (1 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution));
    else if (2 == sizeof(maskConstitution))
        ptree->appendChild("Constitution", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution));
    else
        ptree->appendChild("Constitution", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution));
    Hero_Ability maskConstitution_X;
    memset(&maskConstitution_X, '\0', sizeof(maskConstitution_X));
    maskConstitution_X.Constitution_X = 1;
    if (1 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskConstitution_X));
    else if (2 == sizeof(maskConstitution_X))
        ptree->appendChild("Constitution_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskConstitution_X));
    else
        ptree->appendChild("Constitution_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskConstitution_X));
    Hero_Ability masku2;
    memset(&masku2, '\0', sizeof(masku2));
    masku2.u2 = 1;
    if (1 == sizeof(masku2))
        ptree->appendChild("u2", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku2));
    else if (2 == sizeof(masku2))
        ptree->appendChild("u2", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku2));
    else
        ptree->appendChild("u2", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku2));
    Hero_Ability maskMight;
    memset(&maskMight, '\0', sizeof(maskMight));
    maskMight.Might = 1;
    if (1 == sizeof(maskMight))
        ptree->appendChild("Might", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight));
    else if (2 == sizeof(maskMight))
        ptree->appendChild("Might", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight));
    else
        ptree->appendChild("Might", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight));
    Hero_Ability maskMight_X;
    memset(&maskMight_X, '\0', sizeof(maskMight_X));
    maskMight_X.Might_X = 1;
    if (1 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMight_X));
    else if (2 == sizeof(maskMight_X))
        ptree->appendChild("Might_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMight_X));
    else
        ptree->appendChild("Might_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMight_X));
    Hero_Ability masku7;
    memset(&masku7, '\0', sizeof(masku7));
    masku7.u7 = 1;
    if (1 == sizeof(masku7))
        ptree->appendChild("u7", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku7));
    else if (2 == sizeof(masku7))
        ptree->appendChild("u7", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku7));
    else
        ptree->appendChild("u7", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku7));
    Hero_Ability maskArcane_Power;
    memset(&maskArcane_Power, '\0', sizeof(maskArcane_Power));
    maskArcane_Power.Arcane_Power = 1;
    if (1 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power));
    else if (2 == sizeof(maskArcane_Power))
        ptree->appendChild("Arcane_Power", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power));
    else
        ptree->appendChild("Arcane_Power", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power));
    Hero_Ability maskArcane_Power_X;
    memset(&maskArcane_Power_X, '\0', sizeof(maskArcane_Power_X));
    maskArcane_Power_X.Arcane_Power_X = 1;
    if (1 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskArcane_Power_X));
    else if (2 == sizeof(maskArcane_Power_X))
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskArcane_Power_X));
    else
        ptree->appendChild("Arcane_Power_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskArcane_Power_X));
    Hero_Ability masku6;
    memset(&masku6, '\0', sizeof(masku6));
    masku6.u6 = 1;
    if (1 == sizeof(masku6))
        ptree->appendChild("u6", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku6));
    else if (2 == sizeof(masku6))
        ptree->appendChild("u6", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku6));
    else
        ptree->appendChild("u6", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku6));
    Hero_Ability maskSage;
    memset(&maskSage, '\0', sizeof(maskSage));
    maskSage.Sage = 1;
    if (1 == sizeof(maskSage))
        ptree->appendChild("Sage", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage));
    else if (2 == sizeof(maskSage))
        ptree->appendChild("Sage", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage));
    else
        ptree->appendChild("Sage", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage));
    Hero_Ability maskSage_X;
    memset(&maskSage_X, '\0', sizeof(maskSage_X));
    maskSage_X.Sage_X = 1;
    if (1 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSage_X));
    else if (2 == sizeof(maskSage_X))
        ptree->appendChild("Sage_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSage_X));
    else
        ptree->appendChild("Sage_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSage_X));
    Hero_Ability masku5;
    memset(&masku5, '\0', sizeof(masku5));
    masku5.u5 = 1;
    if (1 == sizeof(masku5))
        ptree->appendChild("u5", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku5));
    else if (2 == sizeof(masku5))
        ptree->appendChild("u5", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku5));
    else
        ptree->appendChild("u5", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku5));
    Hero_Ability maskPrayermaster;
    memset(&maskPrayermaster, '\0', sizeof(maskPrayermaster));
    maskPrayermaster.Prayermaster = 1;
    if (1 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster));
    else if (2 == sizeof(maskPrayermaster))
        ptree->appendChild("Prayermaster", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster));
    else
        ptree->appendChild("Prayermaster", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster));
    Hero_Ability maskPrayermaster_X;
    memset(&maskPrayermaster_X, '\0', sizeof(maskPrayermaster_X));
    maskPrayermaster_X.Prayermaster_X = 1;
    if (1 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPrayermaster_X));
    else if (2 == sizeof(maskPrayermaster_X))
        ptree->appendChild("Prayermaster_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPrayermaster_X));
    else
        ptree->appendChild("Prayermaster_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPrayermaster_X));
    Hero_Ability maskAgility_X;
    memset(&maskAgility_X, '\0', sizeof(maskAgility_X));
    maskAgility_X.Agility_X = 1;
    if (1 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility_X));
    else if (2 == sizeof(maskAgility_X))
        ptree->appendChild("Agility_X", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility_X));
    else
        ptree->appendChild("Agility_X", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility_X));
    Hero_Ability maskLucky;
    memset(&maskLucky, '\0', sizeof(maskLucky));
    maskLucky.Lucky = 1;
    if (1 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLucky));
    else if (2 == sizeof(maskLucky))
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLucky));
    else
        ptree->appendChild("Lucky", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLucky));
    Hero_Ability maskCharmed;
    memset(&maskCharmed, '\0', sizeof(maskCharmed));
    maskCharmed.Charmed = 1;
    if (1 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCharmed));
    else if (2 == sizeof(maskCharmed))
        ptree->appendChild("Charmed", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCharmed));
    else
        ptree->appendChild("Charmed", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCharmed));
    Hero_Ability maskNoble;
    memset(&maskNoble, '\0', sizeof(maskNoble));
    maskNoble.Noble = 1;
    if (1 == sizeof(maskNoble))
        ptree->appendChild("Noble", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskNoble));
    else if (2 == sizeof(maskNoble))
        ptree->appendChild("Noble", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskNoble));
    else
        ptree->appendChild("Noble", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskNoble));
    Hero_Ability masku8;
    memset(&masku8, '\0', sizeof(masku8));
    masku8.u8 = 1;
    if (1 == sizeof(masku8))
        ptree->appendChild("u8", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&masku8));
    else if (2 == sizeof(masku8))
        ptree->appendChild("u8", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&masku8));
    else
        ptree->appendChild("u8", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&masku8));
    Hero_Ability maskAgility;
    memset(&maskAgility, '\0', sizeof(maskAgility));
    maskAgility.Agility = 1;
    if (1 == sizeof(maskAgility))
        ptree->appendChild("Agility", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskAgility));
    else if (2 == sizeof(maskAgility))
        ptree->appendChild("Agility", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskAgility));
    else
        ptree->appendChild("Agility", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskAgility));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Hero_Choice* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Hero_Choice>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new QMoMTreeItemModel<char[14]>(rhs->m_Name));
    ptree->appendChild("m_Experience", new QMoMTreeItemModel<int16_t>(&rhs->m_Experience));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Hero_Stats_Initializer* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Hero_Stats_Initializer>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Nr_Random_picks", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_Random_picks));
    ptree->appendChild("m_Random_pick_type", new QMoMTreeItemModel<eRandomPickType>(&rhs->m_Random_pick_type));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new QMoMTreeItemModel<uint16_t>(&rhs->m_Hero_Casting_Skill));
    QMoMTreeItemModelBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new QMoMTreeItemModelBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell16>(&rhs->m_Spell[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Hero_stats>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Level_Status", new QMoMTreeItemModel<eHero_Level_Status>(&rhs->m_Level_Status));
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Abilities, "m_Hero_Abilities"), "");
    ptree->appendChild("m_Hero_Casting_Skill", new QMoMTreeItemModel<uint8_t>(&rhs->m_Hero_Casting_Skill));
    QMoMTreeItemModelBase* ptreem_Spell = ptree;
    if (4 > 3)
    {
        ptreem_Spell = new QMoMTreeItemModelBase("m_Spell");
        ptree->appendTree(ptreem_Spell, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell[" << i << "]";
          ptreem_Spell->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell>(&rhs->m_Spell[i]));
    }
    ptree->appendChild("m_Garbage", new QMoMTreeItemModel<uint8_t>(&rhs->m_Garbage));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Hired_Hero* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Hired_Hero>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Unit_Nr", new QMoMTreeItemModel<int16_t>(&rhs->m_Unit_Nr));
    ptree->appendChild("m_Hero_name", new QMoMTreeItemModel<char[14]>(rhs->m_Hero_name));
    QMoMTreeItemModelBase* ptreem_Items_In_Slot = ptree;
    if (3 > 3)
    {
        ptreem_Items_In_Slot = new QMoMTreeItemModelBase("m_Items_In_Slot");
        ptree->appendTree(ptreem_Items_In_Slot, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_In_Slot[" << i << "]";
          ptreem_Items_In_Slot->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Items_In_Slot[i]));
    }
    QMoMTreeItemModelBase* ptreem_Slot_Types = ptree;
    if (3 > 3)
    {
        ptreem_Slot_Types = new QMoMTreeItemModelBase("m_Slot_Types");
        ptree->appendTree(ptreem_Slot_Types, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Slot_Types[" << i << "]";
          ptreem_Slot_Types->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSlot_Type16>(&rhs->m_Slot_Types[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(HlpEntryLbx* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<HlpEntryLbx>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("lbxIndex", new QMoMTreeItemModel<uint16_t>(&rhs->lbxIndex));
    ptree->appendChild("left", new QMoMTreeItemModel<int16_t>(&rhs->left));
    ptree->appendChild("top", new QMoMTreeItemModel<int16_t>(&rhs->top));
    ptree->appendChild("right", new QMoMTreeItemModel<int16_t>(&rhs->right));
    ptree->appendChild("bottom", new QMoMTreeItemModel<int16_t>(&rhs->bottom));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Immunity_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Immunity_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Immunity_Flags maskFire_Immunity;
    memset(&maskFire_Immunity, '\0', sizeof(maskFire_Immunity));
    maskFire_Immunity.Fire_Immunity = 1;
    if (1 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFire_Immunity));
    else if (2 == sizeof(maskFire_Immunity))
        ptree->appendChild("Fire_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFire_Immunity));
    else
        ptree->appendChild("Fire_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFire_Immunity));
    Immunity_Flags maskStoning_Immunity;
    memset(&maskStoning_Immunity, '\0', sizeof(maskStoning_Immunity));
    maskStoning_Immunity.Stoning_Immunity = 1;
    if (1 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning_Immunity));
    else if (2 == sizeof(maskStoning_Immunity))
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning_Immunity));
    else
        ptree->appendChild("Stoning_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning_Immunity));
    Immunity_Flags maskMissiles_Immunity;
    memset(&maskMissiles_Immunity, '\0', sizeof(maskMissiles_Immunity));
    maskMissiles_Immunity.Missiles_Immunity = 1;
    if (1 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMissiles_Immunity));
    else if (2 == sizeof(maskMissiles_Immunity))
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMissiles_Immunity));
    else
        ptree->appendChild("Missiles_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMissiles_Immunity));
    Immunity_Flags maskIllusions_Immunity;
    memset(&maskIllusions_Immunity, '\0', sizeof(maskIllusions_Immunity));
    maskIllusions_Immunity.Illusions_Immunity = 1;
    if (1 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIllusions_Immunity));
    else if (2 == sizeof(maskIllusions_Immunity))
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIllusions_Immunity));
    else
        ptree->appendChild("Illusions_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIllusions_Immunity));
    Immunity_Flags maskCold_Immunity;
    memset(&maskCold_Immunity, '\0', sizeof(maskCold_Immunity));
    maskCold_Immunity.Cold_Immunity = 1;
    if (1 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCold_Immunity));
    else if (2 == sizeof(maskCold_Immunity))
        ptree->appendChild("Cold_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCold_Immunity));
    else
        ptree->appendChild("Cold_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCold_Immunity));
    Immunity_Flags maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Immunity_Flags maskDeath_Immunity;
    memset(&maskDeath_Immunity, '\0', sizeof(maskDeath_Immunity));
    maskDeath_Immunity.Death_Immunity = 1;
    if (1 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath_Immunity));
    else if (2 == sizeof(maskDeath_Immunity))
        ptree->appendChild("Death_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath_Immunity));
    else
        ptree->appendChild("Death_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath_Immunity));
    Immunity_Flags maskPoison_Immunity;
    memset(&maskPoison_Immunity, '\0', sizeof(maskPoison_Immunity));
    maskPoison_Immunity.Poison_Immunity = 1;
    if (1 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPoison_Immunity));
    else if (2 == sizeof(maskPoison_Immunity))
        ptree->appendChild("Poison_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPoison_Immunity));
    else
        ptree->appendChild("Poison_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPoison_Immunity));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Item* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Item>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Item_Name", new QMoMTreeItemModel<char[30]>(rhs->m_Item_Name));
    ptree->appendChild("m_Icon", new QMoMTreeItemModel<eItem_Icon>(&rhs->m_Icon));
    ptree->appendChild("m_Slot_Required", new QMoMTreeItemModel<eSlot_Type8>(&rhs->m_Slot_Required));
    ptree->appendChild("m_Item_Type", new QMoMTreeItemModel<eItem_Type>(&rhs->m_Item_Type));
    ptree->appendChild("m_Cost", new QMoMTreeItemModel<int16_t>(&rhs->m_Cost));
    ptree->appendTree(constructTreeItem(&rhs->m_Bonuses, "m_Bonuses"), "");
    ptree->appendChild("m_Spell_Number_Charged", new QMoMTreeItemModel<eSpell>(&rhs->m_Spell_Number_Charged));
    ptree->appendChild("m_Number_Of_Charges", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_Of_Charges));
    ptree->appendTree(constructTreeItem(&rhs->m_Bitmask_Powers, "m_Bitmask_Powers"), "");
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(ItemDataLbx* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<ItemDataLbx>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->m_Item, "m_Item"), "");
    QMoMTreeItemModelBase* ptreem_Required_Spellbooks = ptree;
    if (5 > 3)
    {
        ptreem_Required_Spellbooks = new QMoMTreeItemModelBase("m_Required_Spellbooks");
        ptree->appendTree(ptreem_Required_Spellbooks, "");
    }
    for (unsigned i = 0; i < 5; ++i)
    {
          std::ostringstream oss;
          oss << "m_Required_Spellbooks[" << i << "]";
          ptreem_Required_Spellbooks->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Required_Spellbooks[i]));
    }
    ptree->appendChild("m_Special_Item", new QMoMTreeItemModel<uint8_t>(&rhs->m_Special_Item));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(ItemPowLbx* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<ItemPowLbx>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new QMoMTreeItemModel<char[18]>(rhs->m_Name));
    ptree->appendChild("m_EnchantibleItems", new QMoMTreeItemModel<uint16_t>(&rhs->m_EnchantibleItems));
    ptree->appendChild("m_Mana_cost_to_enchant", new QMoMTreeItemModel<int16_t>(&rhs->m_Mana_cost_to_enchant));
    ptree->appendChild("m_PowerType", new QMoMTreeItemModel<eItemPowerType>(&rhs->m_PowerType));
    ptree->appendChild("m_Color", new QMoMTreeItemModel<eRealm_Type>(&rhs->m_Color));
    ptree->appendChild("m_Required_Nr_Spell_Books", new QMoMTreeItemModel<int16_t>(&rhs->m_Required_Nr_Spell_Books));
    ptree->appendTree(constructTreeItem(&rhs->m_Bitmask_Powers, "m_Bitmask_Powers"), "");
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Item_Bonuses* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Item_Bonuses>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Attack", new QMoMTreeItemModel<int8_t>(&rhs->Attack));
    ptree->appendChild("To_Hit", new QMoMTreeItemModel<int8_t>(&rhs->To_Hit));
    ptree->appendChild("Defense", new QMoMTreeItemModel<int8_t>(&rhs->Defense));
    ptree->appendChild("Movement_in_halves", new QMoMTreeItemModel<int8_t>(&rhs->Movement_in_halves));
    ptree->appendChild("Resistance", new QMoMTreeItemModel<int8_t>(&rhs->Resistance));
    ptree->appendChild("Spell_Points", new QMoMTreeItemModel<int8_t>(&rhs->Spell_Points));
    ptree->appendChild("Spell_Save", new QMoMTreeItemModel<int8_t>(&rhs->Spell_Save));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Item_Powers* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Item_Powers>(rhs, context);
    if (0 == rhs)
        return ptree;

    Item_Powers maskVampiric;
    memset(&maskVampiric, '\0', sizeof(maskVampiric));
    maskVampiric.Vampiric = 1;
    if (1 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVampiric));
    else if (2 == sizeof(maskVampiric))
        ptree->appendChild("Vampiric", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVampiric));
    else
        ptree->appendChild("Vampiric", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVampiric));
    Item_Powers maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 1;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Item_Powers maskLightning;
    memset(&maskLightning, '\0', sizeof(maskLightning));
    maskLightning.Lightning = 1;
    if (1 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLightning));
    else if (2 == sizeof(maskLightning))
        ptree->appendChild("Lightning", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLightning));
    else
        ptree->appendChild("Lightning", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLightning));
    Item_Powers maskCloak_Of_Fear;
    memset(&maskCloak_Of_Fear, '\0', sizeof(maskCloak_Of_Fear));
    maskCloak_Of_Fear.Cloak_Of_Fear = 1;
    if (1 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_Of_Fear));
    else if (2 == sizeof(maskCloak_Of_Fear))
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_Of_Fear));
    else
        ptree->appendChild("Cloak_Of_Fear", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_Of_Fear));
    Item_Powers maskDestruction;
    memset(&maskDestruction, '\0', sizeof(maskDestruction));
    maskDestruction.Destruction = 1;
    if (1 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDestruction));
    else if (2 == sizeof(maskDestruction))
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDestruction));
    else
        ptree->appendChild("Destruction", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDestruction));
    Item_Powers maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 1;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Item_Powers maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Item_Powers maskPathfinding;
    memset(&maskPathfinding, '\0', sizeof(maskPathfinding));
    maskPathfinding.Pathfinding = 1;
    if (1 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPathfinding));
    else if (2 == sizeof(maskPathfinding))
        ptree->appendChild("Pathfinding", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPathfinding));
    else
        ptree->appendChild("Pathfinding", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPathfinding));
    Item_Powers maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 1;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Item_Powers maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 1;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Item_Powers maskElemental_Armour;
    memset(&maskElemental_Armour, '\0', sizeof(maskElemental_Armour));
    maskElemental_Armour.Elemental_Armour = 1;
    if (1 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armour));
    else if (2 == sizeof(maskElemental_Armour))
        ptree->appendChild("Elemental_Armour", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armour));
    else
        ptree->appendChild("Elemental_Armour", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armour));
    Item_Powers maskDoom_equals_Chaos;
    memset(&maskDoom_equals_Chaos, '\0', sizeof(maskDoom_equals_Chaos));
    maskDoom_equals_Chaos.Doom_equals_Chaos = 1;
    if (1 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDoom_equals_Chaos));
    else if (2 == sizeof(maskDoom_equals_Chaos))
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDoom_equals_Chaos));
    else
        ptree->appendChild("Doom_equals_Chaos", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDoom_equals_Chaos));
    Item_Powers maskStoning;
    memset(&maskStoning, '\0', sizeof(maskStoning));
    maskStoning.Stoning = 1;
    if (1 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStoning));
    else if (2 == sizeof(maskStoning))
        ptree->appendChild("Stoning", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStoning));
    else
        ptree->appendChild("Stoning", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStoning));
    Item_Powers maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 1;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Item_Powers maskHaste;
    memset(&maskHaste, '\0', sizeof(maskHaste));
    maskHaste.Haste = 1;
    if (1 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHaste));
    else if (2 == sizeof(maskHaste))
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHaste));
    else
        ptree->appendChild("Haste", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHaste));
    Item_Powers maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Item_Powers maskDeath;
    memset(&maskDeath, '\0', sizeof(maskDeath));
    maskDeath.Death = 1;
    if (1 == sizeof(maskDeath))
        ptree->appendChild("Death", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskDeath));
    else if (2 == sizeof(maskDeath))
        ptree->appendChild("Death", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskDeath));
    else
        ptree->appendChild("Death", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskDeath));
    Item_Powers maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 1;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Item_Powers maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 1;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Item_Powers maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Item_Powers maskFlaming;
    memset(&maskFlaming, '\0', sizeof(maskFlaming));
    maskFlaming.Flaming = 1;
    if (1 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlaming));
    else if (2 == sizeof(maskFlaming))
        ptree->appendChild("Flaming", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlaming));
    else
        ptree->appendChild("Flaming", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlaming));
    Item_Powers maskHoly_Avenger;
    memset(&maskHoly_Avenger, '\0', sizeof(maskHoly_Avenger));
    maskHoly_Avenger.Holy_Avenger = 1;
    if (1 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Avenger));
    else if (2 == sizeof(maskHoly_Avenger))
        ptree->appendChild("Holy_Avenger", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Avenger));
    else
        ptree->appendChild("Holy_Avenger", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Avenger));
    Item_Powers maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 1;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Item_Powers maskPhantasmal;
    memset(&maskPhantasmal, '\0', sizeof(maskPhantasmal));
    maskPhantasmal.Phantasmal = 1;
    if (1 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPhantasmal));
    else if (2 == sizeof(maskPhantasmal))
        ptree->appendChild("Phantasmal", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPhantasmal));
    else
        ptree->appendChild("Phantasmal", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPhantasmal));
    Item_Powers maskPower_Drain;
    memset(&maskPower_Drain, '\0', sizeof(maskPower_Drain));
    maskPower_Drain.Power_Drain = 1;
    if (1 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPower_Drain));
    else if (2 == sizeof(maskPower_Drain))
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPower_Drain));
    else
        ptree->appendChild("Power_Drain", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPower_Drain));
    Item_Powers maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 1;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Item_Powers maskLion_Heart;
    memset(&maskLion_Heart, '\0', sizeof(maskLion_Heart));
    maskLion_Heart.Lion_Heart = 1;
    if (1 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLion_Heart));
    else if (2 == sizeof(maskLion_Heart))
        ptree->appendChild("Lion_Heart", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLion_Heart));
    else
        ptree->appendChild("Lion_Heart", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLion_Heart));
    Item_Powers maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 1;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Item_Powers maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 1;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Item_Powers maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 1;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    Item_Powers maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 1;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Item_Powers maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 1;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(LBXHEADER* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<LBXHEADER>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("n", new QMoMTreeItemModel<uint16_t>(&rhs->n));
    ptree->appendChild("magic_number", new QMoMTreeItemModel<uint32_t>(&rhs->magic_number));
    ptree->appendChild("reserved", new QMoMTreeItemModel<uint16_t>(&rhs->reserved));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Lair_Inhabitant* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Lair_Inhabitant>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Inhabitant", new QMoMTreeItemModel<eUnit_Type>(&rhs->m_Inhabitant));
    Lair_Inhabitant maskm_Remaining_Nr_of_Inhabitant;
    memset(&maskm_Remaining_Nr_of_Inhabitant, '\0', sizeof(maskm_Remaining_Nr_of_Inhabitant));
    maskm_Remaining_Nr_of_Inhabitant.m_Remaining_Nr_of_Inhabitant = 15;
    if (1 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Remaining_Nr_of_Inhabitant))
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Remaining_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Remaining_Nr_of_Inhabitant", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Remaining_Nr_of_Inhabitant));
    Lair_Inhabitant maskm_Initial_Nr_of_Inhabitant;
    memset(&maskm_Initial_Nr_of_Inhabitant, '\0', sizeof(maskm_Initial_Nr_of_Inhabitant));
    maskm_Initial_Nr_of_Inhabitant.m_Initial_Nr_of_Inhabitant = 15;
    if (1 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Initial_Nr_of_Inhabitant));
    else if (2 == sizeof(maskm_Initial_Nr_of_Inhabitant))
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Initial_Nr_of_Inhabitant));
    else
        ptree->appendChild("m_Initial_Nr_of_Inhabitant", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Initial_Nr_of_Inhabitant));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(List_Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<List_Hero_stats>(rhs, context);
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

QMoMTreeItemModelBase* constructTreeItem(MapRow_Bonus* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_Bonus>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Bonus_Deposit = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Bonus_Deposit[" << i << "]";
          ptreem_Bonus_Deposit->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eTerrainBonusDeposit>(&rhs->m_Bonus_Deposit[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MapRow_Exploration* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_Exploration>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Explored = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Explored[" << i << "]";
          ptreem_Explored->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Explored[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MapRow_LandMassID* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_LandMassID>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_LandMassID = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_LandMassID[" << i << "]";
          ptreem_LandMassID->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_LandMassID[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MapRow_Movement* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_Movement>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Moves = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Moves[" << i << "]";
          ptreem_Moves->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Moves[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MapRow_Terrain* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_Terrain>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Tile = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tile[" << i << "]";
          ptreem_Tile->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eTerrainType>(&rhs->m_Tile[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MapRow_Terrain_Changes* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MapRow_Terrain_Changes>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Terrain_Changes = ptree;
    for (unsigned i = 0; i < 60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Terrain_Changes[" << i << "]";
          ptreem_Terrain_Changes->appendTree(constructTreeItem(&rhs->m_Terrain_Changes[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Map_Movement* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Map_Movement>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Unused_Row = ptree;
    if (40 > 3)
    {
        ptreem_Unused_Row = new QMoMTreeItemModelBase("m_Unused_Row");
        ptree->appendTree(ptreem_Unused_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unused_Row[" << i << "]";
          ptreem_Unused_Row->appendTree(constructTreeItem(&rhs->m_Unused_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Walking_Row = ptree;
    if (40 > 3)
    {
        ptreem_Walking_Row = new QMoMTreeItemModelBase("m_Walking_Row");
        ptree->appendTree(ptreem_Walking_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Walking_Row[" << i << "]";
          ptreem_Walking_Row->appendTree(constructTreeItem(&rhs->m_Walking_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Forester_Row = ptree;
    if (40 > 3)
    {
        ptreem_Forester_Row = new QMoMTreeItemModelBase("m_Forester_Row");
        ptree->appendTree(ptreem_Forester_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Forester_Row[" << i << "]";
          ptreem_Forester_Row->appendTree(constructTreeItem(&rhs->m_Forester_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Mountaineer_Row = ptree;
    if (40 > 3)
    {
        ptreem_Mountaineer_Row = new QMoMTreeItemModelBase("m_Mountaineer_Row");
        ptree->appendTree(ptreem_Mountaineer_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Mountaineer_Row[" << i << "]";
          ptreem_Mountaineer_Row->appendTree(constructTreeItem(&rhs->m_Mountaineer_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Swimming_Row = ptree;
    if (40 > 3)
    {
        ptreem_Swimming_Row = new QMoMTreeItemModelBase("m_Swimming_Row");
        ptree->appendTree(ptreem_Swimming_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Swimming_Row[" << i << "]";
          ptreem_Swimming_Row->appendTree(constructTreeItem(&rhs->m_Swimming_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Sailing_Row = ptree;
    if (40 > 3)
    {
        ptreem_Sailing_Row = new QMoMTreeItemModelBase("m_Sailing_Row");
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

QMoMTreeItemModelBase* constructTreeItem(MoMDataSegment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMDataSegment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new QMoMTreeItemModel<char[0x0130]>(rhs->m_DataSegmentStart));
    QMoMTreeItemModelBase* ptreem_Offsets_SkillNames = ptree;
    if (eSkill_MAX > 3)
    {
        ptreem_Offsets_SkillNames = new QMoMTreeItemModelBase("m_Offsets_SkillNames");
        ptree->appendTree(ptreem_Offsets_SkillNames, "");
    }
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_SkillNames[" << i << "]";
          ptreem_Offsets_SkillNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_SkillNames[i]));
    }
    ptree->appendChild("m_Unk_0154", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_0154));
    QMoMTreeItemModelBase* ptreem_Offsets_CitySizeNames = ptree;
    if (eCity_Size_MAX > 3)
    {
        ptreem_Offsets_CitySizeNames = new QMoMTreeItemModelBase("m_Offsets_CitySizeNames");
        ptree->appendTree(ptreem_Offsets_CitySizeNames, "");
    }
    for (unsigned i = 0; i < eCity_Size_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CitySizeNames[" << i << "]";
          ptreem_Offsets_CitySizeNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_CitySizeNames[i]));
    }
    QMoMTreeItemModelBase* ptreem_Offsets_CitySpecialNames = ptree;
    if (7 > 3)
    {
        ptreem_Offsets_CitySpecialNames = new QMoMTreeItemModelBase("m_Offsets_CitySpecialNames");
        ptree->appendTree(ptreem_Offsets_CitySpecialNames, "");
    }
    for (unsigned i = 0; i < 7; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CitySpecialNames[" << i << "]";
          ptreem_Offsets_CitySpecialNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_CitySpecialNames[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_0170 = ptree;
    if (22 > 3)
    {
        ptreem_Unk_0170 = new QMoMTreeItemModelBase("m_Unk_0170");
        ptree->appendTree(ptreem_Unk_0170, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_0170[" << i << "]";
          ptreem_Unk_0170->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_0170[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Hero_Types, "m_Hero_Types"), "");
    QMoMTreeItemModelBase* ptreem_Normal_Units = ptree;
    if (4 + 115 > 3)
    {
        ptreem_Normal_Units = new QMoMTreeItemModelBase("m_Normal_Units");
        ptree->appendTree(ptreem_Normal_Units, "");
    }
    for (unsigned i = 0; i < 4 + 115; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Units[" << i << "]";
          ptreem_Normal_Units->appendTree(constructTreeItem(&rhs->m_Normal_Units[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Summoned_Units = ptree;
    if (44 > 3)
    {
        ptreem_Summoned_Units = new QMoMTreeItemModelBase("m_Summoned_Units");
        ptree->appendTree(ptreem_Summoned_Units, "");
    }
    for (unsigned i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "m_Summoned_Units[" << i << "]";
          ptreem_Summoned_Units->appendTree(constructTreeItem(&rhs->m_Summoned_Units[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_XP_Level_Table = ptree;
    if (gMAX_LEVELS_HERO > 3)
    {
        ptreem_XP_Level_Table = new QMoMTreeItemModelBase("m_XP_Level_Table");
        ptree->appendTree(ptreem_XP_Level_Table, "");
    }
    for (unsigned i = 0; i < gMAX_LEVELS_HERO; ++i)
    {
          std::ostringstream oss;
          oss << "m_XP_Level_Table[" << i << "]";
          ptreem_XP_Level_Table->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_XP_Level_Table[i]));
    }
    QMoMTreeItemModelBase* ptreem_Race_Data = ptree;
    if (14 > 3)
    {
        ptreem_Race_Data = new QMoMTreeItemModelBase("m_Race_Data");
        ptree->appendTree(ptreem_Race_Data, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Race_Data[" << i << "]";
          ptreem_Race_Data->appendTree(constructTreeItem(&rhs->m_Race_Data[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Unk_1ED6", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_1ED6));
    ptree->appendChild("m_Offset_Arcane", new QMoMTreeItemModel<uint16_t>(&rhs->m_Offset_Arcane));
    QMoMTreeItemModelBase* ptreem_Offsets_RealmNames_5 = ptree;
    if (5 > 3)
    {
        ptreem_Offsets_RealmNames_5 = new QMoMTreeItemModelBase("m_Offsets_RealmNames_5");
        ptree->appendTree(ptreem_Offsets_RealmNames_5, "");
    }
    for (unsigned i = 0; i < 5; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_RealmNames_5[" << i << "]";
          ptreem_Offsets_RealmNames_5->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_RealmNames_5[i]));
    }
    QMoMTreeItemModelBase* ptreem_Offsets_CityEnchantmentNames = ptree;
    if (eCityEnchantments_MAX > 3)
    {
        ptreem_Offsets_CityEnchantmentNames = new QMoMTreeItemModelBase("m_Offsets_CityEnchantmentNames");
        ptree->appendTree(ptreem_Offsets_CityEnchantmentNames, "");
    }
    for (unsigned i = 0; i < eCityEnchantments_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_CityEnchantmentNames[" << i << "]";
          ptreem_Offsets_CityEnchantmentNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_CityEnchantmentNames[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Upkeep_Enchantments, "m_Upkeep_Enchantments"), "");
    QMoMTreeItemModelBase* ptreem_Offsets_PersonalityNames = ptree;
    if (ePersonality_MAX > 3)
    {
        ptreem_Offsets_PersonalityNames = new QMoMTreeItemModelBase("m_Offsets_PersonalityNames");
        ptree->appendTree(ptreem_Offsets_PersonalityNames, "");
    }
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_PersonalityNames[" << i << "]";
          ptreem_Offsets_PersonalityNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_PersonalityNames[i]));
    }
    QMoMTreeItemModelBase* ptreem_Values_Personalities_GUESS = ptree;
    if (ePersonality_MAX > 3)
    {
        ptreem_Values_Personalities_GUESS = new QMoMTreeItemModelBase("m_Values_Personalities_GUESS");
        ptree->appendTree(ptreem_Values_Personalities_GUESS, "");
    }
    for (unsigned i = 0; i < ePersonality_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Values_Personalities_GUESS[" << i << "]";
          ptreem_Values_Personalities_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Values_Personalities_GUESS[i]));
    }
    QMoMTreeItemModelBase* ptreem_Offsets_ObjectiveNames = ptree;
    if (eObjective_MAX > 3)
    {
        ptreem_Offsets_ObjectiveNames = new QMoMTreeItemModelBase("m_Offsets_ObjectiveNames");
        ptree->appendTree(ptreem_Offsets_ObjectiveNames, "");
    }
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_ObjectiveNames[" << i << "]";
          ptreem_Offsets_ObjectiveNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_ObjectiveNames[i]));
    }
    ptree->appendChild("m_Unk_1FDE", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_1FDE));
    QMoMTreeItemModelBase* ptreem_Values_Objectives_GUESS = ptree;
    if (eObjective_MAX > 3)
    {
        ptreem_Values_Objectives_GUESS = new QMoMTreeItemModelBase("m_Values_Objectives_GUESS");
        ptree->appendTree(ptreem_Values_Objectives_GUESS, "");
    }
    for (unsigned i = 0; i < eObjective_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Values_Objectives_GUESS[" << i << "]";
          ptreem_Values_Objectives_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Values_Objectives_GUESS[i]));
    }
    QMoMTreeItemModelBase* ptreem_DifficultyTable = ptree;
    if (eDifficulty_MAX > 3)
    {
        ptreem_DifficultyTable = new QMoMTreeItemModelBase("m_DifficultyTable");
        ptree->appendTree(ptreem_DifficultyTable, "");
    }
    for (unsigned i = 0; i < eDifficulty_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_DifficultyTable[" << i << "]";
          ptreem_DifficultyTable->appendTree(constructTreeItem(&rhs->m_DifficultyTable[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unk_203A = ptree;
    if (72 > 3)
    {
        ptreem_Unk_203A = new QMoMTreeItemModelBase("m_Unk_203A");
        ptree->appendTree(ptreem_Unk_203A, "");
    }
    for (unsigned i = 0; i < 72; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_203A[" << i << "]";
          ptreem_Unk_203A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_203A[i]));
    }
    ptree->appendChild("m_NameBuffer_2082", new QMoMTreeItemModel<char[0x3A50 - 0x2082]>(rhs->m_NameBuffer_2082));
    QMoMTreeItemModelBase* ptreem_UnitView_HeroAbility_data = ptree;
    if (23 > 3)
    {
        ptreem_UnitView_HeroAbility_data = new QMoMTreeItemModelBase("m_UnitView_HeroAbility_data");
        ptree->appendTree(ptreem_UnitView_HeroAbility_data, "");
    }
    for (unsigned i = 0; i < 23; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_HeroAbility_data[" << i << "]";
          ptreem_UnitView_HeroAbility_data->appendTree(constructTreeItem(&rhs->m_UnitView_HeroAbility_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitView_UnitAbility_data = ptree;
    if (17 > 3)
    {
        ptreem_UnitView_UnitAbility_data = new QMoMTreeItemModelBase("m_UnitView_UnitAbility_data");
        ptree->appendTree(ptreem_UnitView_UnitAbility_data, "");
    }
    for (unsigned i = 0; i < 17; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitAbility_data[" << i << "]";
          ptreem_UnitView_UnitAbility_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitAbility_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitView_UnitImmunity_data = ptree;
    if (8 > 3)
    {
        ptreem_UnitView_UnitImmunity_data = new QMoMTreeItemModelBase("m_UnitView_UnitImmunity_data");
        ptree->appendTree(ptreem_UnitView_UnitImmunity_data, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitImmunity_data[" << i << "]";
          ptreem_UnitView_UnitImmunity_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitImmunity_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitView_UnitSpell_data = ptree;
    if (8 > 3)
    {
        ptreem_UnitView_UnitSpell_data = new QMoMTreeItemModelBase("m_UnitView_UnitSpell_data");
        ptree->appendTree(ptreem_UnitView_UnitSpell_data, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitSpell_data[" << i << "]";
          ptreem_UnitView_UnitSpell_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitSpell_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitView_UnitAttack_data = ptree;
    if (11 > 3)
    {
        ptreem_UnitView_UnitAttack_data = new QMoMTreeItemModelBase("m_UnitView_UnitAttack_data");
        ptree->appendTree(ptreem_UnitView_UnitAttack_data, "");
    }
    for (unsigned i = 0; i < 11; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitView_UnitAttack_data[" << i << "]";
          ptreem_UnitView_UnitAttack_data->appendTree(constructTreeItem(&rhs->m_UnitView_UnitAttack_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitMutation_data = ptree;
    if (3 > 3)
    {
        ptreem_UnitMutation_data = new QMoMTreeItemModelBase("m_UnitMutation_data");
        ptree->appendTree(ptreem_UnitMutation_data, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitMutation_data[" << i << "]";
          ptreem_UnitMutation_data->appendTree(constructTreeItem(&rhs->m_UnitMutation_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitRanged_data = ptree;
    if (6 > 3)
    {
        ptreem_UnitRanged_data = new QMoMTreeItemModelBase("m_UnitRanged_data");
        ptree->appendTree(ptreem_UnitRanged_data, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitRanged_data[" << i << "]";
          ptreem_UnitRanged_data->appendTree(constructTreeItem(&rhs->m_UnitRanged_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_UnitEnchantment_data = ptree;
    if (32 > 3)
    {
        ptreem_UnitEnchantment_data = new QMoMTreeItemModelBase("m_UnitEnchantment_data");
        ptree->appendTree(ptreem_UnitEnchantment_data, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_UnitEnchantment_data[" << i << "]";
          ptreem_UnitEnchantment_data->appendTree(constructTreeItem(&rhs->m_UnitEnchantment_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_CombatEnchantment_data = ptree;
    if (15 > 3)
    {
        ptreem_CombatEnchantment_data = new QMoMTreeItemModelBase("m_CombatEnchantment_data");
        ptree->appendTree(ptreem_CombatEnchantment_data, "");
    }
    for (unsigned i = 0; i < 15; ++i)
    {
          std::ostringstream oss;
          oss << "m_CombatEnchantment_data[" << i << "]";
          ptreem_CombatEnchantment_data->appendTree(constructTreeItem(&rhs->m_CombatEnchantment_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_ItemPower_data = ptree;
    if (21 > 3)
    {
        ptreem_ItemPower_data = new QMoMTreeItemModelBase("m_ItemPower_data");
        ptree->appendTree(ptreem_ItemPower_data, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "m_ItemPower_data[" << i << "]";
          ptreem_ItemPower_data->appendTree(constructTreeItem(&rhs->m_ItemPower_data[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Offsets_UnitLevelNames = ptree;
    if (gMAX_LEVELS_UNIT > 3)
    {
        ptreem_Offsets_UnitLevelNames = new QMoMTreeItemModelBase("m_Offsets_UnitLevelNames");
        ptree->appendTree(ptreem_Offsets_UnitLevelNames, "");
    }
    for (unsigned i = 0; i < gMAX_LEVELS_UNIT; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_UnitLevelNames[" << i << "]";
          ptreem_Offsets_UnitLevelNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_UnitLevelNames[i]));
    }
    QMoMTreeItemModelBase* ptreem_Offsets_HeroLevelNames = ptree;
    if (gMAX_LEVELS_HERO > 3)
    {
        ptreem_Offsets_HeroLevelNames = new QMoMTreeItemModelBase("m_Offsets_HeroLevelNames");
        ptree->appendTree(ptreem_Offsets_HeroLevelNames, "");
    }
    for (unsigned i = 0; i < gMAX_LEVELS_HERO; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_HeroLevelNames[" << i << "]";
          ptreem_Offsets_HeroLevelNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_HeroLevelNames[i]));
    }
    QMoMTreeItemModelBase* ptreem_ItemPower_text = ptree;
    if (32 > 3)
    {
        ptreem_ItemPower_text = new QMoMTreeItemModelBase("m_ItemPower_text");
        ptree->appendTree(ptreem_ItemPower_text, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_ItemPower_text[" << i << "]";
          ptreem_ItemPower_text->appendTree(constructTreeItem(&rhs->m_ItemPower_text[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_NameBuffer_4064", new QMoMTreeItemModel<char[0x5bd8 - 0x4064]>(rhs->m_NameBuffer_4064));
    QMoMTreeItemModelBase* ptreem_BaseItemPowerCosts = ptree;
    if (eItemPowerType_MAX > 3)
    {
        ptreem_BaseItemPowerCosts = new QMoMTreeItemModelBase("m_BaseItemPowerCosts");
        ptree->appendTree(ptreem_BaseItemPowerCosts, "");
    }
    for (unsigned i = 0; i < eItemPowerType_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_BaseItemPowerCosts[" << i << "]";
          ptreem_BaseItemPowerCosts->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_BaseItemPowerCosts[i]));
    }
    ptree->appendChild("m_NameBuffer_5BEC", new QMoMTreeItemModel<char[0x5E92 - 0x5BEC]>(rhs->m_NameBuffer_5BEC));
    ptree->appendChild("m_Next_Turn_seed_storage_lo", new QMoMTreeItemModel<uint16_t>(&rhs->m_Next_Turn_seed_storage_lo));
    ptree->appendChild("m_Next_Turn_seed_storage_hi", new QMoMTreeItemModel<uint16_t>(&rhs->m_Next_Turn_seed_storage_hi));
    QMoMTreeItemModelBase* ptreem_Unk_5E96 = ptree;
    if (0x6E9E - 0x5E96 > 3)
    {
        ptreem_Unk_5E96 = new QMoMTreeItemModelBase("m_Unk_5E96");
        ptree->appendTree(ptreem_Unk_5E96, "");
    }
    for (unsigned i = 0; i < 0x6E9E - 0x5E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_5E96[" << i << "]";
          ptreem_Unk_5E96->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_5E96[i]));
    }
    QMoMTreeItemModelBase* ptreem_Tax_Unrest_Table = ptree;
    if (eTax_Rate_MAX > 3)
    {
        ptreem_Tax_Unrest_Table = new QMoMTreeItemModelBase("m_Tax_Unrest_Table");
        ptree->appendTree(ptreem_Tax_Unrest_Table, "");
    }
    for (unsigned i = 0; i < eTax_Rate_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tax_Unrest_Table[" << i << "]";
          ptreem_Tax_Unrest_Table->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Tax_Unrest_Table[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_6EAC = ptree;
    if (0x7151 - 0x6EAC > 3)
    {
        ptreem_Unk_6EAC = new QMoMTreeItemModelBase("m_Unk_6EAC");
        ptree->appendTree(ptreem_Unk_6EAC, "");
    }
    for (unsigned i = 0; i < 0x7151 - 0x6EAC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_6EAC[" << i << "]";
          ptreem_Unk_6EAC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_6EAC[i]));
    }
    ptree->appendChild("m_Copyright_and_Version", new QMoMTreeItemModel<char[41]>(rhs->m_Copyright_and_Version));
    QMoMTreeItemModelBase* ptreem_Unk_717A = ptree;
    if (0x71E0 - 0x717A > 3)
    {
        ptreem_Unk_717A = new QMoMTreeItemModelBase("m_Unk_717A");
        ptree->appendTree(ptreem_Unk_717A, "");
    }
    for (unsigned i = 0; i < 0x71E0 - 0x717A; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_717A[" << i << "]";
          ptreem_Unk_717A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_717A[i]));
    }
    ptree->appendChild("m_BIOS_clock_snapshot", new QMoMTreeItemModel<uint32_t>(&rhs->m_BIOS_clock_snapshot));
    QMoMTreeItemModelBase* ptreem_Unk_71E4 = ptree;
    if (0x760C - 0x71E4 > 3)
    {
        ptreem_Unk_71E4 = new QMoMTreeItemModelBase("m_Unk_71E4");
        ptree->appendTree(ptreem_Unk_71E4, "");
    }
    for (unsigned i = 0; i < 0x760C - 0x71E4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_71E4[" << i << "]";
          ptreem_Unk_71E4->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_71E4[i]));
    }
    ptree->appendChild("m_EMS_data_reference_point", new QMoMTreeItemModel<uint16_t>(&rhs->m_EMS_data_reference_point));
    QMoMTreeItemModelBase* ptreem_Unk_760E = ptree;
    if (0x7846 - 0x760E > 3)
    {
        ptreem_Unk_760E = new QMoMTreeItemModelBase("m_Unk_760E");
        ptree->appendTree(ptreem_Unk_760E, "");
    }
    for (unsigned i = 0; i < 0x7846 - 0x760E; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_760E[" << i << "]";
          ptreem_Unk_760E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_760E[i]));
    }
    ptree->appendChild("m_RNG_seed_lo", new QMoMTreeItemModel<uint16_t>(&rhs->m_RNG_seed_lo));
    ptree->appendChild("m_RNG_seed_hi", new QMoMTreeItemModel<uint16_t>(&rhs->m_RNG_seed_hi));
    QMoMTreeItemModelBase* ptreem_Unk_784A = ptree;
    if (0x7876 - 0x784A > 3)
    {
        ptreem_Unk_784A = new QMoMTreeItemModelBase("m_Unk_784A");
        ptree->appendTree(ptreem_Unk_784A, "");
    }
    for (unsigned i = 0; i < 0x7876 - 0x784A; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_784A[" << i << "]";
          ptreem_Unk_784A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_784A[i]));
    }
    ptree->appendChild("m_DEBUG_Off", new QMoMTreeItemModel<uint16_t>(&rhs->m_DEBUG_Off));
    QMoMTreeItemModelBase* ptreem_Unk_7878 = ptree;
    if (0x912C - 0x7878 > 3)
    {
        ptreem_Unk_7878 = new QMoMTreeItemModelBase("m_Unk_7878");
        ptree->appendTree(ptreem_Unk_7878, "");
    }
    for (unsigned i = 0; i < 0x912C - 0x7878; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_7878[" << i << "]";
          ptreem_Unk_7878->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_7878[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Spell_Data, "m_addr_Spell_Data"), "");
    ptree->appendChild("word_3FBD0", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FBD0));
    ptree->appendChild("w_sound_x", new QMoMTreeItemModel<uint16_t>(&rhs->w_sound_x));
    ptree->appendChild("word_3FBD4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FBD4));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Items, "m_addr_Items"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Artifacts_in_Game, "m_addr_Artifacts_in_Game"), "");
    QMoMTreeItemModelBase* ptreem_item_pics_116 = ptree;
    if (116 > 3)
    {
        ptreem_item_pics_116 = new QMoMTreeItemModelBase("m_item_pics_116");
        ptree->appendTree(ptreem_item_pics_116, "");
    }
    for (unsigned i = 0; i < 116; ++i)
    {
          std::ostringstream oss;
          oss << "m_item_pics_116[" << i << "]";
          ptreem_item_pics_116->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_item_pics_116[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_Unit_View, "m_addr_Battle_Unit_View"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_Unit, "m_addr_Battle_Unit"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Spells_Cast_in_Battle, "m_addr_Spells_Cast_in_Battle"), "");
    QMoMTreeItemModelBase* ptreem_addr_Hero_stat = ptree;
    if (6 > 3)
    {
        ptreem_addr_Hero_stat = new QMoMTreeItemModelBase("m_addr_Hero_stat");
        ptree->appendTree(ptreem_addr_Hero_stat, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_addr_Hero_stat[" << i << "]";
          ptreem_addr_Hero_stat->appendTree(constructTreeItem(&rhs->m_addr_Hero_stat[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreew_AI_flees = ptree;
    if (20 > 3)
    {
        ptreew_AI_flees = new QMoMTreeItemModelBase("w_AI_flees");
        ptree->appendTree(ptreew_AI_flees, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "w_AI_flees[" << i << "]";
          ptreew_AI_flees->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->w_AI_flees[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FCFE = ptree;
    if (10 > 3)
    {
        ptreeword_3FCFE = new QMoMTreeItemModelBase("word_3FCFE");
        ptree->appendTree(ptreeword_3FCFE, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FCFE[" << i << "]";
          ptreeword_3FCFE->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FCFE[i]));
    }
    ptree->appendChild("word_3FD08", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD08));
    ptree->appendChild("word_3FD0A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD0A));
    ptree->appendChild("word_3FD0C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD0C));
    ptree->appendChild("word_3FD0E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD0E));
    ptree->appendChild("word_3FD10", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD10));
    ptree->appendChild("word_3FD12", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD12));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battlefield, "m_addr_Battlefield"), "");
    ptree->appendChild("word_3FD18", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD18));
    ptree->appendChild("word_3FD1A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD1A));
    ptree->appendChild("w_AI_on_the_move_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->w_AI_on_the_move_GUESS));
    ptree->appendChild("w_coo_X_Y_clicked", new QMoMTreeItemModel<uint16_t>(&rhs->w_coo_X_Y_clicked));
    ptree->appendChild("w_coo_Y_X_clicked", new QMoMTreeItemModel<uint16_t>(&rhs->w_coo_Y_X_clicked));
    ptree->appendChild("word_3FD22", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD22));
    ptree->appendChild("m_clash_place_type", new QMoMTreeItemModel<int16_t>(&rhs->m_clash_place_type));
    ptree->appendChild("m_clash_cityNr_or_lairNr", new QMoMTreeItemModel<int16_t>(&rhs->m_clash_cityNr_or_lairNr));
    QMoMTreeItemModelBase* ptreeword_3FD28 = ptree;
    if (12 > 3)
    {
        ptreeword_3FD28 = new QMoMTreeItemModelBase("word_3FD28");
        ptree->appendTree(ptreeword_3FD28, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD28[" << i << "]";
          ptreeword_3FD28->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FD28[i]));
    }
    ptree->appendChild("m_kyrub_dseg_9294", new QMoMTreeItemModel<int16_t>(&rhs->m_kyrub_dseg_9294));
    ptree->appendChild("m_kyrub_dseg_9296", new QMoMTreeItemModel<int16_t>(&rhs->m_kyrub_dseg_9296));
    QMoMTreeItemModelBase* ptreeword_3FD38 = ptree;
    if (20 > 3)
    {
        ptreeword_3FD38 = new QMoMTreeItemModelBase("word_3FD38");
        ptree->appendTree(ptreeword_3FD38, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD38[" << i << "]";
          ptreeword_3FD38->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FD38[i]));
    }
    ptree->appendChild("w_negat_encha_x17_flag_def", new QMoMTreeItemModel<uint16_t>(&rhs->w_negat_encha_x17_flag_def));
    ptree->appendChild("w_aggre_spell_color_flag_att", new QMoMTreeItemModel<uint16_t>(&rhs->w_aggre_spell_color_flag_att));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FD50, "dword_3FD50"), "");
    ptree->appendChild("word_3FD54", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD54));
    QMoMTreeItemModelBase* ptreeword_3FD56 = ptree;
    if (64 > 3)
    {
        ptreeword_3FD56 = new QMoMTreeItemModelBase("word_3FD56");
        ptree->appendTree(ptreeword_3FD56, "");
    }
    for (unsigned i = 0; i < 64; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD56[" << i << "]";
          ptreeword_3FD56->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FD56[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FD96 = ptree;
    if (8 > 3)
    {
        ptreeword_3FD96 = new QMoMTreeItemModelBase("word_3FD96");
        ptree->appendTree(ptreeword_3FD96, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FD96[" << i << "]";
          ptreeword_3FD96->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FD96[i]));
    }
    ptree->appendChild("word_3FD9E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FD9E));
    ptree->appendChild("word_3FDA0", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDA0));
    ptree->appendChild("word_3FDA2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDA2));
    ptree->appendChild("word_3FDA4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDA4));
    ptree->appendChild("word_3FDA6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDA6));
    ptree->appendChild("word_3FDA8", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDA8));
    ptree->appendChild("word_3FDAA", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDAA));
    ptree->appendChild("word_3FDAC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDAC));
    ptree->appendChild("word_3FDAE", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDAE));
    ptree->appendChild("word_3FDB0", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDB0));
    ptree->appendChild("word_3FDB2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDB2));
    ptree->appendChild("word_3FDB4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDB4));
    ptree->appendChild("word_3FDB6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDB6));
    QMoMTreeItemModelBase* ptreeword_3FDB8 = ptree;
    if (44 > 3)
    {
        ptreeword_3FDB8 = new QMoMTreeItemModelBase("word_3FDB8");
        ptree->appendTree(ptreeword_3FDB8, "");
    }
    for (unsigned i = 0; i < 44; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FDB8[" << i << "]";
          ptreeword_3FDB8->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FDB8[i]));
    }
    ptree->appendChild("word_3FDE4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDE4));
    ptree->appendTree(constructTreeItem(&rhs->addr_3FDE6, "addr_3FDE6"), "");
    ptree->appendChild("word_3FDEA", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDEA));
    ptree->appendChild("word_3FDEC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDEC));
    ptree->appendChild("word_3FDEE", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDEE));
    ptree->appendChild("word_3FDF0", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDF0));
    ptree->appendChild("word_3FDF2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDF2));
    ptree->appendChild("word_3FDF4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDF4));
    ptree->appendChild("word_3FDF6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDF6));
    ptree->appendChild("word_3FDF8", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDF8));
    ptree->appendChild("word_3FDFA", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDFA));
    ptree->appendChild("word_3FDFC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDFC));
    ptree->appendChild("word_3FDFE", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FDFE));
    ptree->appendChild("word_3FE00", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE00));
    ptree->appendChild("word_3FE02", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE02));
    ptree->appendChild("word_3FE04", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE04));
    ptree->appendChild("word_3FE06", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE06));
    ptree->appendChild("word_3FE08", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE08));
    ptree->appendChild("word_3FE0A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE0A));
    ptree->appendChild("word_3FE0C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE0C));
    ptree->appendChild("word_3FE0E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE0E));
    ptree->appendChild("word_3FE10", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE10));
    ptree->appendChild("word_3FE12", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE12));
    ptree->appendChild("word_3FE14", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE14));
    ptree->appendChild("word_3FE16", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE16));
    ptree->appendChild("word_3FE18", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE18));
    ptree->appendChild("word_3FE1A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE1A));
    ptree->appendChild("word_3FE1C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE1C));
    ptree->appendChild("word_3FE1E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE1E));
    ptree->appendChild("word_3FE20", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE20));
    ptree->appendChild("word_3FE22", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE22));
    ptree->appendChild("word_3FE24", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE24));
    ptree->appendChild("word_3FE26", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE26));
    ptree->appendChild("word_3FE28", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE28));
    ptree->appendChild("word_3FE2A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE2A));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Building_Data, "m_addr_Building_Data"), "");
    ptree->appendChild("word_3FE30", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FE30));
    ptree->appendTree(constructTreeItem(&rhs->dword_3FE32, "dword_3FE32"), "");
    QMoMTreeItemModelBase* ptreedword_3FE36 = ptree;
    if (126 > 3)
    {
        ptreedword_3FE36 = new QMoMTreeItemModelBase("dword_3FE36");
        ptree->appendTree(ptreedword_3FE36, "");
    }
    for (unsigned i = 0; i < 126; ++i)
    {
          std::ostringstream oss;
          oss << "dword_3FE36[" << i << "]";
          ptreedword_3FE36->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->dword_3FE36[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FEB4 = ptree;
    if (6 > 3)
    {
        ptreeword_3FEB4 = new QMoMTreeItemModelBase("word_3FEB4");
        ptree->appendTree(ptreeword_3FEB4, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEB4[" << i << "]";
          ptreeword_3FEB4->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FEB4[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FEBA = ptree;
    if (18 > 3)
    {
        ptreeword_3FEBA = new QMoMTreeItemModelBase("word_3FEBA");
        ptree->appendTree(ptreeword_3FEBA, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEBA[" << i << "]";
          ptreeword_3FEBA->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FEBA[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FECC = ptree;
    if (22 > 3)
    {
        ptreeword_3FECC = new QMoMTreeItemModelBase("word_3FECC");
        ptree->appendTree(ptreeword_3FECC, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FECC[" << i << "]";
          ptreeword_3FECC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FECC[i]));
    }
    ptree->appendChild("word_3FEE2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FEE2));
    ptree->appendChild("w_all_units_moved_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->w_all_units_moved_GUESS));
    ptree->appendChild("word_3FEE6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FEE6));
    ptree->appendChild("word_3FEE8", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FEE8));
    ptree->appendChild("word_3FEEA", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FEEA));
    QMoMTreeItemModelBase* ptreeword_3FEEC = ptree;
    if (6 > 3)
    {
        ptreeword_3FEEC = new QMoMTreeItemModelBase("word_3FEEC");
        ptree->appendTree(ptreeword_3FEEC, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEEC[" << i << "]";
          ptreeword_3FEEC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FEEC[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FEF2 = ptree;
    if (14 > 3)
    {
        ptreeword_3FEF2 = new QMoMTreeItemModelBase("word_3FEF2");
        ptree->appendTree(ptreeword_3FEF2, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FEF2[" << i << "]";
          ptreeword_3FEF2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FEF2[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->word_3FF00, "word_3FF00"), "");
    ptree->appendChild("word_3FF04", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF04));
    ptree->appendChild("word_3FF06", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF06));
    ptree->appendChild("word_3FF08", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF08));
    ptree->appendChild("word_3FF0A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF0A));
    ptree->appendChild("word_3FF0C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF0C));
    ptree->appendChild("word_3FF0E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF0E));
    QMoMTreeItemModelBase* ptreeword_3FF10 = ptree;
    if (14 > 3)
    {
        ptreeword_3FF10 = new QMoMTreeItemModelBase("word_3FF10");
        ptree->appendTree(ptreeword_3FF10, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF10[" << i << "]";
          ptreeword_3FF10->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FF10[i]));
    }
    ptree->appendChild("word_3FF1E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF1E));
    ptree->appendChild("word_3FF20", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF20));
    ptree->appendChild("word_3FF22", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF22));
    ptree->appendChild("word_3FF24", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF24));
    ptree->appendChild("word_3FF26", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF26));
    ptree->appendChild("word_3FF28", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF28));
    ptree->appendChild("word_3FF2A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF2A));
    ptree->appendChild("word_3FF2C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF2C));
    QMoMTreeItemModelBase* ptreeword_3FF2E = ptree;
    if (6 > 3)
    {
        ptreeword_3FF2E = new QMoMTreeItemModelBase("word_3FF2E");
        ptree->appendTree(ptreeword_3FF2E, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF2E[" << i << "]";
          ptreeword_3FF2E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FF2E[i]));
    }
    ptree->appendChild("word_3FF34", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF34));
    ptree->appendChild("word_3FF36", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF36));
    ptree->appendChild("word_3FF38", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF38));
    ptree->appendChild("word_3FF3A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF3A));
    ptree->appendChild("word_3FF3C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF3C));
    ptree->appendChild("word_3FF3E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF3E));
    ptree->appendChild("word_3FF40", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF40));
    ptree->appendChild("word_3FF42", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF42));
    ptree->appendChild("word_3FF44", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF44));
    ptree->appendChild("word_3FF46", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF46));
    ptree->appendChild("word_3FF48", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF48));
    ptree->appendChild("word_3FF4A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF4A));
    QMoMTreeItemModelBase* ptreeword_3FF4C = ptree;
    if (58 > 3)
    {
        ptreeword_3FF4C = new QMoMTreeItemModelBase("word_3FF4C");
        ptree->appendTree(ptreeword_3FF4C, "");
    }
    for (unsigned i = 0; i < 58; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF4C[" << i << "]";
          ptreeword_3FF4C->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FF4C[i]));
    }
    ptree->appendChild("word_3FF86", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF86));
    ptree->appendChild("word_3FF88", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF88));
    ptree->appendChild("word_3FF8A", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF8A));
    ptree->appendChild("word_3FF8C", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF8C));
    ptree->appendChild("word_3FF8E", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FF8E));
    QMoMTreeItemModelBase* ptreeword_3FF90 = ptree;
    if (30 > 3)
    {
        ptreeword_3FF90 = new QMoMTreeItemModelBase("word_3FF90");
        ptree->appendTree(ptreeword_3FF90, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FF90[" << i << "]";
          ptreeword_3FF90->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FF90[i]));
    }
    ptree->appendChild("word_3FFAE", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFAE));
    ptree->appendChild("word_3FFB0", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFB0));
    ptree->appendChild("word_3FFB2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFB2));
    ptree->appendChild("word_3FFB4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFB4));
    ptree->appendChild("word_3FFB6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFB6));
    ptree->appendChild("word_3FFB8", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFB8));
    ptree->appendChild("word_3FFBA", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFBA));
    ptree->appendChild("word_3FFBC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFBC));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFBE, "word_3FFBE"), "");
    ptree->appendChild("word_3FFC2", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFC2));
    ptree->appendChild("word_3FFC4", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFC4));
    ptree->appendChild("word_3FFC6", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFC6));
    ptree->appendTree(constructTreeItem(&rhs->word_3FFC8, "word_3FFC8"), "");
    ptree->appendChild("word_3FFCC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFCC));
    QMoMTreeItemModelBase* ptreeword_3FFCE = ptree;
    if (14 > 3)
    {
        ptreeword_3FFCE = new QMoMTreeItemModelBase("word_3FFCE");
        ptree->appendTree(ptreeword_3FFCE, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFCE[" << i << "]";
          ptreeword_3FFCE->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FFCE[i]));
    }
    ptree->appendChild("word_3FFDC", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFDC));
    ptree->appendChild("word_3FFDE", new QMoMTreeItemModel<uint16_t>(&rhs->word_3FFDE));
    QMoMTreeItemModelBase* ptreeword_3FFE0 = ptree;
    if (8 > 3)
    {
        ptreeword_3FFE0 = new QMoMTreeItemModelBase("word_3FFE0");
        ptree->appendTree(ptreeword_3FFE0, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE0[" << i << "]";
          ptreeword_3FFE0->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FFE0[i]));
    }
    QMoMTreeItemModelBase* ptreeword_3FFE8 = ptree;
    if (38 > 3)
    {
        ptreeword_3FFE8 = new QMoMTreeItemModelBase("word_3FFE8");
        ptree->appendTree(ptreeword_3FFE8, "");
    }
    for (unsigned i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_3FFE8[" << i << "]";
          ptreeword_3FFE8->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_3FFE8[i]));
    }
    ptree->appendChild("word_4000E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4000E));
    ptree->appendChild("word_40010", new QMoMTreeItemModel<uint16_t>(&rhs->word_40010));
    ptree->appendChild("word_40012", new QMoMTreeItemModel<uint16_t>(&rhs->word_40012));
    ptree->appendChild("word_40014", new QMoMTreeItemModel<uint16_t>(&rhs->word_40014));
    ptree->appendChild("word_40016", new QMoMTreeItemModel<uint16_t>(&rhs->word_40016));
    ptree->appendChild("word_40018", new QMoMTreeItemModel<uint16_t>(&rhs->word_40018));
    ptree->appendChild("word_4001A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4001A));
    ptree->appendChild("word_4001C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4001C));
    ptree->appendChild("word_4001E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4001E));
    ptree->appendChild("word_40020", new QMoMTreeItemModel<uint16_t>(&rhs->word_40020));
    ptree->appendChild("word_40022", new QMoMTreeItemModel<uint16_t>(&rhs->word_40022));
    ptree->appendChild("word_40024", new QMoMTreeItemModel<uint16_t>(&rhs->word_40024));
    ptree->appendChild("word_40026", new QMoMTreeItemModel<uint16_t>(&rhs->word_40026));
    ptree->appendChild("word_40028", new QMoMTreeItemModel<uint16_t>(&rhs->word_40028));
    ptree->appendChild("word_4002A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4002A));
    ptree->appendChild("word_4002C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4002C));
    QMoMTreeItemModelBase* ptreeword_4002E = ptree;
    if (28 > 3)
    {
        ptreeword_4002E = new QMoMTreeItemModelBase("word_4002E");
        ptree->appendTree(ptreeword_4002E, "");
    }
    for (unsigned i = 0; i < 28; ++i)
    {
          std::ostringstream oss;
          oss << "word_4002E[" << i << "]";
          ptreeword_4002E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4002E[i]));
    }
    ptree->appendChild("word_4004A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4004A));
    ptree->appendChild("word_4004C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4004C));
    ptree->appendChild("word_4004E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4004E));
    ptree->appendChild("word_40050", new QMoMTreeItemModel<uint16_t>(&rhs->word_40050));
    ptree->appendChild("word_40052", new QMoMTreeItemModel<uint16_t>(&rhs->word_40052));
    ptree->appendChild("word_40054", new QMoMTreeItemModel<uint16_t>(&rhs->word_40054));
    ptree->appendChild("word_40056", new QMoMTreeItemModel<uint16_t>(&rhs->word_40056));
    ptree->appendChild("word_40058", new QMoMTreeItemModel<uint16_t>(&rhs->word_40058));
    ptree->appendChild("word_4005A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4005A));
    ptree->appendChild("word_4005C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4005C));
    ptree->appendChild("word_4005E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4005E));
    ptree->appendChild("word_40060", new QMoMTreeItemModel<uint16_t>(&rhs->word_40060));
    QMoMTreeItemModelBase* ptreeword_40062 = ptree;
    if (12 > 3)
    {
        ptreeword_40062 = new QMoMTreeItemModelBase("word_40062");
        ptree->appendTree(ptreeword_40062, "");
    }
    for (unsigned i = 0; i < 12; ++i)
    {
          std::ostringstream oss;
          oss << "word_40062[" << i << "]";
          ptreeword_40062->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40062[i]));
    }
    QMoMTreeItemModelBase* ptreeword_4006E = ptree;
    if (34 > 3)
    {
        ptreeword_4006E = new QMoMTreeItemModelBase("word_4006E");
        ptree->appendTree(ptreeword_4006E, "");
    }
    for (unsigned i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4006E[" << i << "]";
          ptreeword_4006E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4006E[i]));
    }
    ptree->appendChild("word_40090", new QMoMTreeItemModel<uint16_t>(&rhs->word_40090));
    QMoMTreeItemModelBase* ptreeword_40092 = ptree;
    if (82 > 3)
    {
        ptreeword_40092 = new QMoMTreeItemModelBase("word_40092");
        ptree->appendTree(ptreeword_40092, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "word_40092[" << i << "]";
          ptreeword_40092->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40092[i]));
    }
    ptree->appendChild("m_cityNr_detailed", new QMoMTreeItemModel<int16_t>(&rhs->m_cityNr_detailed));
    QMoMTreeItemModelBase* ptreeword_400E8 = ptree;
    if (246 > 3)
    {
        ptreeword_400E8 = new QMoMTreeItemModelBase("word_400E8");
        ptree->appendTree(ptreeword_400E8, "");
    }
    for (unsigned i = 0; i < 246; ++i)
    {
          std::ostringstream oss;
          oss << "word_400E8[" << i << "]";
          ptreeword_400E8->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_400E8[i]));
    }
    ptree->appendChild("word_401DC", new QMoMTreeItemModel<uint16_t>(&rhs->word_401DC));
    ptree->appendChild("word_401DE", new QMoMTreeItemModel<uint16_t>(&rhs->word_401DE));
    ptree->appendChild("word_401E0", new QMoMTreeItemModel<uint16_t>(&rhs->word_401E0));
    ptree->appendChild("word_401E2", new QMoMTreeItemModel<uint16_t>(&rhs->word_401E2));
    ptree->appendChild("word_401E4", new QMoMTreeItemModel<uint16_t>(&rhs->word_401E4));
    ptree->appendChild("word_401E6", new QMoMTreeItemModel<uint16_t>(&rhs->word_401E6));
    ptree->appendChild("word_401E8", new QMoMTreeItemModel<uint16_t>(&rhs->word_401E8));
    ptree->appendChild("word_401EA", new QMoMTreeItemModel<uint16_t>(&rhs->word_401EA));
    ptree->appendChild("word_401EC", new QMoMTreeItemModel<uint16_t>(&rhs->word_401EC));
    ptree->appendChild("word_401EE", new QMoMTreeItemModel<uint16_t>(&rhs->word_401EE));
    ptree->appendChild("word_401F0", new QMoMTreeItemModel<uint16_t>(&rhs->word_401F0));
    ptree->appendChild("word_401F2", new QMoMTreeItemModel<uint16_t>(&rhs->word_401F2));
    ptree->appendChild("word_401F4", new QMoMTreeItemModel<uint16_t>(&rhs->word_401F4));
    ptree->appendChild("word_401F6", new QMoMTreeItemModel<uint16_t>(&rhs->word_401F6));
    ptree->appendChild("word_401F8", new QMoMTreeItemModel<uint16_t>(&rhs->word_401F8));
    ptree->appendChild("word_401FA", new QMoMTreeItemModel<uint16_t>(&rhs->word_401FA));
    ptree->appendChild("word_401FC", new QMoMTreeItemModel<uint16_t>(&rhs->word_401FC));
    ptree->appendChild("word_401FE", new QMoMTreeItemModel<uint16_t>(&rhs->word_401FE));
    ptree->appendChild("word_40200", new QMoMTreeItemModel<uint16_t>(&rhs->word_40200));
    ptree->appendChild("word_40202", new QMoMTreeItemModel<uint16_t>(&rhs->word_40202));
    ptree->appendChild("word_40204", new QMoMTreeItemModel<uint16_t>(&rhs->word_40204));
    ptree->appendChild("word_40206", new QMoMTreeItemModel<uint16_t>(&rhs->word_40206));
    ptree->appendChild("word_40208", new QMoMTreeItemModel<uint16_t>(&rhs->word_40208));
    ptree->appendChild("word_4020A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4020A));
    QMoMTreeItemModelBase* ptreeword_4020C = ptree;
    if (38 > 3)
    {
        ptreeword_4020C = new QMoMTreeItemModelBase("word_4020C");
        ptree->appendTree(ptreeword_4020C, "");
    }
    for (unsigned i = 0; i < 38; ++i)
    {
          std::ostringstream oss;
          oss << "word_4020C[" << i << "]";
          ptreeword_4020C->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4020C[i]));
    }
    ptree->appendChild("word_40232", new QMoMTreeItemModel<uint16_t>(&rhs->word_40232));
    ptree->appendChild("word_40234", new QMoMTreeItemModel<uint16_t>(&rhs->word_40234));
    ptree->appendChild("word_40236", new QMoMTreeItemModel<uint16_t>(&rhs->word_40236));
    ptree->appendChild("word_40238", new QMoMTreeItemModel<uint16_t>(&rhs->word_40238));
    ptree->appendChild("word_4023A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4023A));
    ptree->appendChild("word_4023C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4023C));
    ptree->appendChild("word_4023E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4023E));
    ptree->appendChild("word_40240", new QMoMTreeItemModel<uint16_t>(&rhs->word_40240));
    QMoMTreeItemModelBase* ptreeword_40242 = ptree;
    if (18 > 3)
    {
        ptreeword_40242 = new QMoMTreeItemModelBase("word_40242");
        ptree->appendTree(ptreeword_40242, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "word_40242[" << i << "]";
          ptreeword_40242->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40242[i]));
    }
    ptree->appendChild("word_40254", new QMoMTreeItemModel<uint16_t>(&rhs->word_40254));
    ptree->appendChild("word_40256", new QMoMTreeItemModel<uint16_t>(&rhs->word_40256));
    ptree->appendChild("word_40258", new QMoMTreeItemModel<uint16_t>(&rhs->word_40258));
    QMoMTreeItemModelBase* ptreeword_4025A = ptree;
    if (50 > 3)
    {
        ptreeword_4025A = new QMoMTreeItemModelBase("word_4025A");
        ptree->appendTree(ptreeword_4025A, "");
    }
    for (unsigned i = 0; i < 50; ++i)
    {
          std::ostringstream oss;
          oss << "word_4025A[" << i << "]";
          ptreeword_4025A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4025A[i]));
    }
    ptree->appendChild("word_4028C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4028C));
    QMoMTreeItemModelBase* ptreeword_4028E = ptree;
    if (10 > 3)
    {
        ptreeword_4028E = new QMoMTreeItemModelBase("word_4028E");
        ptree->appendTree(ptreeword_4028E, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4028E[" << i << "]";
          ptreeword_4028E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4028E[i]));
    }
    ptree->appendChild("word_40298", new QMoMTreeItemModel<uint16_t>(&rhs->word_40298));
    ptree->appendChild("word_4029A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4029A));
    ptree->appendChild("word_4029C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4029C));
    QMoMTreeItemModelBase* ptreeword_4029E = ptree;
    if (34 > 3)
    {
        ptreeword_4029E = new QMoMTreeItemModelBase("word_4029E");
        ptree->appendTree(ptreeword_4029E, "");
    }
    for (unsigned i = 0; i < 34; ++i)
    {
          std::ostringstream oss;
          oss << "word_4029E[" << i << "]";
          ptreeword_4029E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4029E[i]));
    }
    QMoMTreeItemModelBase* ptreeword_402C0 = ptree;
    if (32 > 3)
    {
        ptreeword_402C0 = new QMoMTreeItemModelBase("word_402C0");
        ptree->appendTree(ptreeword_402C0, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "word_402C0[" << i << "]";
          ptreeword_402C0->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_402C0[i]));
    }
    ptree->appendChild("word_402E0", new QMoMTreeItemModel<uint16_t>(&rhs->word_402E0));
    QMoMTreeItemModelBase* ptreeword_402E2 = ptree;
    if (36 > 3)
    {
        ptreeword_402E2 = new QMoMTreeItemModelBase("word_402E2");
        ptree->appendTree(ptreeword_402E2, "");
    }
    for (unsigned i = 0; i < 36; ++i)
    {
          std::ostringstream oss;
          oss << "word_402E2[" << i << "]";
          ptreeword_402E2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_402E2[i]));
    }
    QMoMTreeItemModelBase* ptreeword_40306 = ptree;
    if (120 > 3)
    {
        ptreeword_40306 = new QMoMTreeItemModelBase("word_40306");
        ptree->appendTree(ptreeword_40306, "");
    }
    for (unsigned i = 0; i < 120; ++i)
    {
          std::ostringstream oss;
          oss << "word_40306[" << i << "]";
          ptreeword_40306->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40306[i]));
    }
    QMoMTreeItemModelBase* ptreeword_4037E = ptree;
    if (10 > 3)
    {
        ptreeword_4037E = new QMoMTreeItemModelBase("word_4037E");
        ptree->appendTree(ptreeword_4037E, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_4037E[" << i << "]";
          ptreeword_4037E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_4037E[i]));
    }
    QMoMTreeItemModelBase* ptreeword_40388 = ptree;
    if (10 > 3)
    {
        ptreeword_40388 = new QMoMTreeItemModelBase("word_40388");
        ptree->appendTree(ptreeword_40388, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_40388[" << i << "]";
          ptreeword_40388->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40388[i]));
    }
    ptree->appendChild("word_40392", new QMoMTreeItemModel<uint16_t>(&rhs->word_40392));
    QMoMTreeItemModelBase* ptreeword_40394 = ptree;
    if (20 > 3)
    {
        ptreeword_40394 = new QMoMTreeItemModelBase("word_40394");
        ptree->appendTree(ptreeword_40394, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_40394[" << i << "]";
          ptreeword_40394->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_40394[i]));
    }
    QMoMTreeItemModelBase* ptreeword_403A8 = ptree;
    if (6 > 3)
    {
        ptreeword_403A8 = new QMoMTreeItemModelBase("word_403A8");
        ptree->appendTree(ptreeword_403A8, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_403A8[" << i << "]";
          ptreeword_403A8->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_403A8[i]));
    }
    QMoMTreeItemModelBase* ptreeword_403AE = ptree;
    if (10 > 3)
    {
        ptreeword_403AE = new QMoMTreeItemModelBase("word_403AE");
        ptree->appendTree(ptreeword_403AE, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "word_403AE[" << i << "]";
          ptreeword_403AE->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_403AE[i]));
    }
    ptree->appendChild("word_403B8", new QMoMTreeItemModel<uint16_t>(&rhs->word_403B8));
    ptree->appendChild("word_403BA", new QMoMTreeItemModel<uint16_t>(&rhs->word_403BA));
    ptree->appendChild("word_403BC", new QMoMTreeItemModel<uint16_t>(&rhs->word_403BC));
    ptree->appendChild("word_403BE", new QMoMTreeItemModel<uint16_t>(&rhs->word_403BE));
    ptree->appendChild("word_403C0", new QMoMTreeItemModel<uint16_t>(&rhs->word_403C0));
    QMoMTreeItemModelBase* ptreeword_403C2 = ptree;
    if (20 > 3)
    {
        ptreeword_403C2 = new QMoMTreeItemModelBase("word_403C2");
        ptree->appendTree(ptreeword_403C2, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "word_403C2[" << i << "]";
          ptreeword_403C2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_403C2[i]));
    }
    ptree->appendChild("word_403D6", new QMoMTreeItemModel<uint16_t>(&rhs->word_403D6));
    ptree->appendChild("word_403D8", new QMoMTreeItemModel<uint16_t>(&rhs->word_403D8));
    ptree->appendChild("word_403DA", new QMoMTreeItemModel<uint16_t>(&rhs->word_403DA));
    ptree->appendChild("word_403DC", new QMoMTreeItemModel<uint16_t>(&rhs->word_403DC));
    ptree->appendChild("word_403DE", new QMoMTreeItemModel<uint16_t>(&rhs->word_403DE));
    ptree->appendChild("word_403E0", new QMoMTreeItemModel<uint16_t>(&rhs->word_403E0));
    ptree->appendChild("word_403E2", new QMoMTreeItemModel<uint16_t>(&rhs->word_403E2));
    ptree->appendChild("word_403E4", new QMoMTreeItemModel<uint16_t>(&rhs->word_403E4));
    ptree->appendChild("word_403E6", new QMoMTreeItemModel<uint16_t>(&rhs->word_403E6));
    ptree->appendChild("word_403E8", new QMoMTreeItemModel<uint16_t>(&rhs->word_403E8));
    ptree->appendChild("word_403EA", new QMoMTreeItemModel<uint16_t>(&rhs->word_403EA));
    ptree->appendChild("word_403EC", new QMoMTreeItemModel<uint16_t>(&rhs->word_403EC));
    ptree->appendChild("word_403EE", new QMoMTreeItemModel<uint16_t>(&rhs->word_403EE));
    ptree->appendChild("word_403F0", new QMoMTreeItemModel<uint16_t>(&rhs->word_403F0));
    ptree->appendChild("word_403F2", new QMoMTreeItemModel<uint16_t>(&rhs->word_403F2));
    ptree->appendChild("word_403F4", new QMoMTreeItemModel<uint16_t>(&rhs->word_403F4));
    ptree->appendChild("word_403F6", new QMoMTreeItemModel<uint16_t>(&rhs->word_403F6));
    ptree->appendChild("word_403F8", new QMoMTreeItemModel<uint16_t>(&rhs->word_403F8));
    ptree->appendChild("word_403FA", new QMoMTreeItemModel<uint16_t>(&rhs->word_403FA));
    ptree->appendChild("word_403FC", new QMoMTreeItemModel<uint16_t>(&rhs->word_403FC));
    ptree->appendTree(constructTreeItem(&rhs->word_403FE, "word_403FE"), "");
    ptree->appendChild("word_40402", new QMoMTreeItemModel<uint16_t>(&rhs->word_40402));
    ptree->appendChild("word_40404", new QMoMTreeItemModel<uint16_t>(&rhs->word_40404));
    ptree->appendChild("word_40406", new QMoMTreeItemModel<uint16_t>(&rhs->word_40406));
    ptree->appendChild("word_40408", new QMoMTreeItemModel<uint16_t>(&rhs->word_40408));
    ptree->appendChild("word_4040A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4040A));
    ptree->appendChild("word_4040C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4040C));
    ptree->appendChild("word_4040E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4040E));
    ptree->appendChild("word_40410", new QMoMTreeItemModel<uint16_t>(&rhs->word_40410));
    ptree->appendChild("word_40412", new QMoMTreeItemModel<uint16_t>(&rhs->word_40412));
    ptree->appendChild("word_40414", new QMoMTreeItemModel<uint16_t>(&rhs->word_40414));
    ptree->appendChild("word_40416", new QMoMTreeItemModel<uint16_t>(&rhs->word_40416));
    ptree->appendChild("word_40418", new QMoMTreeItemModel<uint16_t>(&rhs->word_40418));
    ptree->appendChild("word_4041A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4041A));
    ptree->appendChild("word_4041C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4041C));
    ptree->appendChild("word_4041E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4041E));
    ptree->appendChild("word_40420", new QMoMTreeItemModel<uint16_t>(&rhs->word_40420));
    ptree->appendChild("word_40422", new QMoMTreeItemModel<uint16_t>(&rhs->word_40422));
    ptree->appendChild("word_40424", new QMoMTreeItemModel<uint16_t>(&rhs->word_40424));
    ptree->appendChild("word_40426", new QMoMTreeItemModel<uint16_t>(&rhs->word_40426));
    ptree->appendTree(constructTreeItem(&rhs->word_40428, "word_40428"), "");
    ptree->appendChild("word_4042C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4042C));
    ptree->appendChild("w_constant_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->w_constant_GUESS));
    ptree->appendChild("m_Game_flow", new QMoMTreeItemModel<eGameState>(&rhs->m_Game_flow));
    ptree->appendChild("word_40432", new QMoMTreeItemModel<uint16_t>(&rhs->word_40432));
    ptree->appendChild("word_40434", new QMoMTreeItemModel<uint16_t>(&rhs->word_40434));
    ptree->appendChild("word_40436", new QMoMTreeItemModel<uint16_t>(&rhs->word_40436));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_events, "m_addr_events"), "");
    ptree->appendChild("m_nr_units_in_overland_stack", new QMoMTreeItemModel<int16_t>(&rhs->m_nr_units_in_overland_stack));
    QMoMTreeItemModelBase* ptreem_units_in_overland_stack = ptree;
    if (gMAX_UNITS_IN_LOCATION > 3)
    {
        ptreem_units_in_overland_stack = new QMoMTreeItemModelBase("m_units_in_overland_stack");
        ptree->appendTree(ptreem_units_in_overland_stack, "");
    }
    for (unsigned i = 0; i < gMAX_UNITS_IN_LOCATION; ++i)
    {
          std::ostringstream oss;
          oss << "m_units_in_overland_stack[" << i << "]";
          ptreem_units_in_overland_stack->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint32_t>(&rhs->m_units_in_overland_stack[i]));
    }
    ptree->appendChild("m_nr_message_cityNames", new QMoMTreeItemModel<int8_t>(&rhs->m_nr_message_cityNames));
    QMoMTreeItemModelBase* ptreem_arr20_message_cityNames = ptree;
    if (20 * 14 > 3)
    {
        ptreem_arr20_message_cityNames = new QMoMTreeItemModelBase("m_arr20_message_cityNames");
        ptree->appendTree(ptreem_arr20_message_cityNames, "");
    }
    for (unsigned i = 0; i < 20 * 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_arr20_message_cityNames[" << i << "]";
          ptreem_arr20_message_cityNames->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_arr20_message_cityNames[i]));
    }
    ptree->appendChild("m_nr_message_cityNrs", new QMoMTreeItemModel<int8_t>(&rhs->m_nr_message_cityNrs));
    QMoMTreeItemModelBase* ptreem_arr20_message_cityNrs = ptree;
    if (20 > 3)
    {
        ptreem_arr20_message_cityNrs = new QMoMTreeItemModelBase("m_arr20_message_cityNrs");
        ptree->appendTree(ptreem_arr20_message_cityNrs, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_arr20_message_cityNrs[" << i << "]";
          ptreem_arr20_message_cityNrs->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_arr20_message_cityNrs[i]));
    }
    ptree->appendChild("m_nr_city_queue", new QMoMTreeItemModel<int8_t>(&rhs->m_nr_city_queue));
    ptree->appendChild("m_Unused_9AF1", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unused_9AF1));
    QMoMTreeItemModelBase* ptreem_arr20_city_queue = ptree;
    if (20 > 3)
    {
        ptreem_arr20_city_queue = new QMoMTreeItemModelBase("m_arr20_city_queue");
        ptree->appendTree(ptreem_arr20_city_queue, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_arr20_city_queue[" << i << "]";
          ptreem_arr20_city_queue->appendTree(constructTreeItem(&rhs->m_arr20_city_queue[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreebyte_405E2 = ptree;
    if (82 > 3)
    {
        ptreebyte_405E2 = new QMoMTreeItemModelBase("byte_405E2");
        ptree->appendTree(ptreebyte_405E2, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_405E2[" << i << "]";
          ptreebyte_405E2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_405E2[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_40634 = ptree;
    if (82 > 3)
    {
        ptreebyte_40634 = new QMoMTreeItemModelBase("byte_40634");
        ptree->appendTree(ptreebyte_40634, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40634[" << i << "]";
          ptreebyte_40634->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_40634[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_40686 = ptree;
    if (82 > 3)
    {
        ptreebyte_40686 = new QMoMTreeItemModelBase("byte_40686");
        ptree->appendTree(ptreebyte_40686, "");
    }
    for (unsigned i = 0; i < 82; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40686[" << i << "]";
          ptreebyte_40686->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_40686[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_406D8 = ptree;
    if (21 > 3)
    {
        ptreebyte_406D8 = new QMoMTreeItemModelBase("byte_406D8");
        ptree->appendTree(ptreebyte_406D8, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406D8[" << i << "]";
          ptreebyte_406D8->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_406D8[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_406ED = ptree;
    if (21 > 3)
    {
        ptreebyte_406ED = new QMoMTreeItemModelBase("byte_406ED");
        ptree->appendTree(ptreebyte_406ED, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_406ED[" << i << "]";
          ptreebyte_406ED->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_406ED[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_40702 = ptree;
    if (21 > 3)
    {
        ptreebyte_40702 = new QMoMTreeItemModelBase("byte_40702");
        ptree->appendTree(ptreebyte_40702, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40702[" << i << "]";
          ptreebyte_40702->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_40702[i]));
    }
    QMoMTreeItemModelBase* ptreebyte_40717 = ptree;
    if (21 > 3)
    {
        ptreebyte_40717 = new QMoMTreeItemModelBase("byte_40717");
        ptree->appendTree(ptreebyte_40717, "");
    }
    for (unsigned i = 0; i < 21; ++i)
    {
          std::ostringstream oss;
          oss << "byte_40717[" << i << "]";
          ptreebyte_40717->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->byte_40717[i]));
    }
    ptree->appendChild("byte_4072C", new QMoMTreeItemModel<uint16_t>(&rhs->byte_4072C));
    ptree->appendChild("w_video_style_CL_BUG_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->w_video_style_CL_BUG_GUESS));
    ptree->appendTree(constructTreeItem(&rhs->dword_40730, "dword_40730"), "");
    ptree->appendChild("word_40734", new QMoMTreeItemModel<uint16_t>(&rhs->word_40734));
    ptree->appendChild("word_40736", new QMoMTreeItemModel<uint16_t>(&rhs->word_40736));
    ptree->appendChild("word_40738", new QMoMTreeItemModel<uint16_t>(&rhs->word_40738));
    ptree->appendChild("word_4073A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4073A));
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
    QMoMTreeItemModelBase* ptreem_addr_Unrest_Table = ptree;
    if (gMAX_RACES > 3)
    {
        ptreem_addr_Unrest_Table = new QMoMTreeItemModelBase("m_addr_Unrest_Table");
        ptree->appendTree(ptreem_addr_Unrest_Table, "");
    }
    for (unsigned i = 0; i < gMAX_RACES; ++i)
    {
          std::ostringstream oss;
          oss << "m_addr_Unrest_Table[" << i << "]";
          ptreem_addr_Unrest_Table->appendTree(constructTreeItem(&rhs->m_addr_Unrest_Table[i], oss.str().c_str()), "");
    }
    ptree->appendChild("word_407B8", new QMoMTreeItemModel<uint16_t>(&rhs->word_407B8));
    ptree->appendChild("word_407BA", new QMoMTreeItemModel<uint16_t>(&rhs->word_407BA));
    ptree->appendChild("word_407BC", new QMoMTreeItemModel<uint16_t>(&rhs->word_407BC));
    ptree->appendChild("word_407BE", new QMoMTreeItemModel<uint16_t>(&rhs->word_407BE));
    ptree->appendChild("word_407C0", new QMoMTreeItemModel<uint16_t>(&rhs->word_407C0));
    ptree->appendChild("m_Vizier_active", new QMoMTreeItemModel<uint16_t>(&rhs->m_Vizier_active));
    QMoMTreeItemModelBase* ptreeword_407C4 = ptree;
    if (6 > 3)
    {
        ptreeword_407C4 = new QMoMTreeItemModelBase("word_407C4");
        ptree->appendTree(ptreeword_407C4, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "word_407C4[" << i << "]";
          ptreeword_407C4->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->word_407C4[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->dword_407CA, "dword_407CA"), "");
    ptree->appendTree(constructTreeItem(&rhs->dword_407CE, "dword_407CE"), "");
    ptree->appendChild("word_407D2", new QMoMTreeItemModel<uint16_t>(&rhs->word_407D2));
    ptree->appendChild("word_407D4", new QMoMTreeItemModel<uint16_t>(&rhs->word_407D4));
    ptree->appendChild("word_407D6", new QMoMTreeItemModel<uint16_t>(&rhs->word_407D6));
    ptree->appendChild("word_407D8", new QMoMTreeItemModel<uint16_t>(&rhs->word_407D8));
    ptree->appendChild("word_407DA", new QMoMTreeItemModel<uint16_t>(&rhs->word_407DA));
    ptree->appendChild("word_407DC", new QMoMTreeItemModel<uint16_t>(&rhs->word_407DC));
    ptree->appendChild("word_407DE", new QMoMTreeItemModel<uint16_t>(&rhs->word_407DE));
    ptree->appendChild("word_407E0", new QMoMTreeItemModel<uint16_t>(&rhs->word_407E0));
    ptree->appendChild("word_407E2", new QMoMTreeItemModel<uint16_t>(&rhs->word_407E2));
    ptree->appendChild("word_407E4", new QMoMTreeItemModel<uint16_t>(&rhs->word_407E4));
    ptree->appendChild("word_407E6", new QMoMTreeItemModel<uint16_t>(&rhs->word_407E6));
    ptree->appendChild("word_407E8", new QMoMTreeItemModel<uint16_t>(&rhs->word_407E8));
    ptree->appendChild("w_AI_stack_nr", new QMoMTreeItemModel<uint16_t>(&rhs->w_AI_stack_nr));
    QMoMTreeItemModelBase* ptreeunk_407EC = ptree;
    if (320 > 3)
    {
        ptreeunk_407EC = new QMoMTreeItemModelBase("unk_407EC");
        ptree->appendTree(ptreeunk_407EC, "");
    }
    for (unsigned i = 0; i < 320; ++i)
    {
          std::ostringstream oss;
          oss << "unk_407EC[" << i << "]";
          ptreeunk_407EC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->unk_407EC[i]));
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
    ptree->appendChild("word_40950", new QMoMTreeItemModel<uint16_t>(&rhs->word_40950));
    ptree->appendChild("word_40952", new QMoMTreeItemModel<uint16_t>(&rhs->word_40952));
    ptree->appendChild("word_40954", new QMoMTreeItemModel<uint16_t>(&rhs->word_40954));
    ptree->appendChild("word_40956", new QMoMTreeItemModel<uint16_t>(&rhs->word_40956));
    ptree->appendChild("word_40958", new QMoMTreeItemModel<uint16_t>(&rhs->word_40958));
    ptree->appendChild("word_4095A", new QMoMTreeItemModel<uint16_t>(&rhs->word_4095A));
    ptree->appendChild("word_4095C", new QMoMTreeItemModel<uint16_t>(&rhs->word_4095C));
    ptree->appendChild("word_4095E", new QMoMTreeItemModel<uint16_t>(&rhs->word_4095E));
    ptree->appendChild("word_40960", new QMoMTreeItemModel<uint16_t>(&rhs->word_40960));
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Units, "m_addr_Units"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Chosen_Hero_Names, "m_addr_Chosen_Hero_Names"), "");
    QMoMTreeItemModelBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new QMoMTreeItemModelBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unk_BB7A = ptree;
    if (0xBD8E - 0xBB7A > 3)
    {
        ptreem_Unk_BB7A = new QMoMTreeItemModelBase("m_Unk_BB7A");
        ptree->appendTree(ptreem_Unk_BB7A, "");
    }
    for (unsigned i = 0; i < 0xBD8E - 0xBB7A; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_BB7A[" << i << "]";
          ptreem_Unk_BB7A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_BB7A[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    QMoMTreeItemModelBase* ptreem_Unk_BF70 = ptree;
    if (0xC190 - 0xBF70 > 3)
    {
        ptreem_Unk_BF70 = new QMoMTreeItemModelBase("m_Unk_BF70");
        ptree->appendTree(ptreem_Unk_BF70, "");
    }
    for (unsigned i = 0; i < 0xC190 - 0xBF70; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_BF70[" << i << "]";
          ptreem_Unk_BF70->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_BF70[i]));
    }
    ptree->appendChild("m_UnitView_nrLines", new QMoMTreeItemModel<uint16_t>(&rhs->m_UnitView_nrLines));
    ptree->appendChild("m_Offset_UnitView_Lines", new QMoMTreeItemModel<uint16_t>(&rhs->m_Offset_UnitView_Lines));
    ptree->appendTree(constructTreeItem(&rhs->m_UnitView_UnitEnchantment, "m_UnitView_UnitEnchantment"), "");
    QMoMTreeItemModelBase* ptreem_Unk_C196 = ptree;
    if (0xC292 - 0xC198 > 3)
    {
        ptreem_Unk_C196 = new QMoMTreeItemModelBase("m_Unk_C196");
        ptree->appendTree(ptreem_Unk_C196, "");
    }
    for (unsigned i = 0; i < 0xC292 - 0xC198; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C196[" << i << "]";
          ptreem_Unk_C196->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C196[i]));
    }
    ptree->appendChild("m_Location_Item", new QMoMTreeItemModel<int16_t>(&rhs->m_Location_Item));
    ptree->appendChild("m_Selected_Item", new QMoMTreeItemModel<int16_t>(&rhs->m_Selected_Item));
    QMoMTreeItemModelBase* ptreem_Unk_C296 = ptree;
    if (0xC300 - 0xC296 > 3)
    {
        ptreem_Unk_C296 = new QMoMTreeItemModelBase("m_Unk_C296");
        ptree->appendTree(ptreem_Unk_C296, "");
    }
    for (unsigned i = 0; i < 0xC300 - 0xC296; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C296[" << i << "]";
          ptreem_Unk_C296->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C296[i]));
    }
    ptree->appendChild("m_Plane_Item", new QMoMTreeItemModel<ePlane16>(&rhs->m_Plane_Item));
    ptree->appendChild("m_YPos_Item", new QMoMTreeItemModel<int16_t>(&rhs->m_YPos_Item));
    ptree->appendChild("m_XPos_Item", new QMoMTreeItemModel<int16_t>(&rhs->m_XPos_Item));
    QMoMTreeItemModelBase* ptreem_Unk_C306 = ptree;
    if (0xC51C - 0xC306 > 3)
    {
        ptreem_Unk_C306 = new QMoMTreeItemModelBase("m_Unk_C306");
        ptree->appendTree(ptreem_Unk_C306, "");
    }
    for (unsigned i = 0; i < 0xC51C - 0xC306; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C306[" << i << "]";
          ptreem_Unk_C306->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C306[i]));
    }
    ptree->appendChild("m_Combat_turn", new QMoMTreeItemModel<int16_t>(&rhs->m_Combat_turn));
    ptree->appendChild("m_Unk_C51E", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_C51E));
    ptree->appendChild("m_External_battle_condition", new QMoMTreeItemModel<eBattleCondition>(&rhs->m_External_battle_condition));
    ptree->appendChild("m_Unk_C522", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_C522));
    QMoMTreeItemModelBase* ptreem_Offsets_Battlefield_battleUnitIDs = ptree;
    if (22 > 3)
    {
        ptreem_Offsets_Battlefield_battleUnitIDs = new QMoMTreeItemModelBase("m_Offsets_Battlefield_battleUnitIDs");
        ptree->appendTree(ptreem_Offsets_Battlefield_battleUnitIDs, "");
    }
    for (unsigned i = 0; i < 22; ++i)
    {
          std::ostringstream oss;
          oss << "m_Offsets_Battlefield_battleUnitIDs[" << i << "]";
          ptreem_Offsets_Battlefield_battleUnitIDs->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Offsets_Battlefield_battleUnitIDs[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_C550 = ptree;
    if (0xC582 - 0xC550 > 3)
    {
        ptreem_Unk_C550 = new QMoMTreeItemModelBase("m_Unk_C550");
        ptree->appendTree(ptreem_Unk_C550, "");
    }
    for (unsigned i = 0; i < 0xC582 - 0xC550; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C550[" << i << "]";
          ptreem_Unk_C550->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C550[i]));
    }
    ptree->appendChild("m_BattleUnit_on_move", new QMoMTreeItemModel<int16_t>(&rhs->m_BattleUnit_on_move));
    ptree->appendChild("m_Defending_wizard", new QMoMTreeItemModel<int16_t>(&rhs->m_Defending_wizard));
    ptree->appendChild("m_Attacking_wizard", new QMoMTreeItemModel<int16_t>(&rhs->m_Attacking_wizard));
    ptree->appendChild("m_Nr_Battle_Units", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_Battle_Units));
    ptree->appendChild("m_BattleUnit_pointed_at", new QMoMTreeItemModel<int16_t>(&rhs->m_BattleUnit_pointed_at));
    QMoMTreeItemModelBase* ptreem_Unk_C58A = ptree;
    if (0xC5C2 - 0xC58C > 3)
    {
        ptreem_Unk_C58A = new QMoMTreeItemModelBase("m_Unk_C58A");
        ptree->appendTree(ptreem_Unk_C58A, "");
    }
    for (unsigned i = 0; i < 0xC5C2 - 0xC58C; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C58A[" << i << "]";
          ptreem_Unk_C58A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C58A[i]));
    }
    ptree->appendChild("m_Battle_winner", new QMoMTreeItemModel<int16_t>(&rhs->m_Battle_winner));
    ptree->appendChild("m_Battle_loser", new QMoMTreeItemModel<int16_t>(&rhs->m_Battle_loser));
    QMoMTreeItemModelBase* ptreem_Unk_C5C6 = ptree;
    if (0xC5DE - 0xC5C6 > 3)
    {
        ptreem_Unk_C5C6 = new QMoMTreeItemModelBase("m_Unk_C5C6");
        ptree->appendTree(ptreem_Unk_C5C6, "");
    }
    for (unsigned i = 0; i < 0xC5DE - 0xC5C6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C5C6[" << i << "]";
          ptreem_Unk_C5C6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C5C6[i]));
    }
    ptree->appendChild("m_YPos_clash", new QMoMTreeItemModel<int16_t>(&rhs->m_YPos_clash));
    ptree->appendChild("m_XPos_clash", new QMoMTreeItemModel<int16_t>(&rhs->m_XPos_clash));
    QMoMTreeItemModelBase* ptreem_Unk_C5E2 = ptree;
    if (0xC8B4 - 0xC5E2 > 3)
    {
        ptreem_Unk_C5E2 = new QMoMTreeItemModelBase("m_Unk_C5E2");
        ptree->appendTree(ptreem_Unk_C5E2, "");
    }
    for (unsigned i = 0; i < 0xC8B4 - 0xC5E2; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C5E2[" << i << "]";
          ptreem_Unk_C5E2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C5E2[i]));
    }
    ptree->appendChild("m_Battlefield_flags", new QMoMTreeItemModel<uint16_t>(&rhs->m_Battlefield_flags));
    QMoMTreeItemModelBase* ptreem_Unk_C8B6 = ptree;
    if (0xC8FA - 0xC8B6 > 3)
    {
        ptreem_Unk_C8B6 = new QMoMTreeItemModelBase("m_Unk_C8B6");
        ptree->appendTree(ptreem_Unk_C8B6, "");
    }
    for (unsigned i = 0; i < 0xC8FA - 0xC8B6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C8B6[" << i << "]";
          ptreem_Unk_C8B6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C8B6[i]));
    }
    ptree->appendChild("m_offset_Available_spell_pages", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_Available_spell_pages));
    QMoMTreeItemModelBase* ptreem_Unk_C8FC = ptree;
    if (0xC910 - 0xC8FC > 3)
    {
        ptreem_Unk_C8FC = new QMoMTreeItemModelBase("m_Unk_C8FC");
        ptree->appendTree(ptreem_Unk_C8FC, "");
    }
    for (unsigned i = 0; i < 0xC910 - 0xC8FC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C8FC[" << i << "]";
          ptreem_Unk_C8FC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C8FC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Hero_Spells, "m_addr_Hero_Spells"), "");
    ptree->appendChild("m_Nr_available_spell_pages", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nr_available_spell_pages));
    QMoMTreeItemModelBase* ptreem_Unk_C916 = ptree;
    if (0xC924 - 0xC916 > 3)
    {
        ptreem_Unk_C916 = new QMoMTreeItemModelBase("m_Unk_C916");
        ptree->appendTree(ptreem_Unk_C916, "");
    }
    for (unsigned i = 0; i < 0xC924 - 0xC916; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C916[" << i << "]";
          ptreem_Unk_C916->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C916[i]));
    }
    ptree->appendChild("m_First_visible_available_spell_page", new QMoMTreeItemModel<uint16_t>(&rhs->m_First_visible_available_spell_page));
    QMoMTreeItemModelBase* ptreem_Unk_C926 = ptree;
    if (0xD15A - 0xC926 > 3)
    {
        ptreem_Unk_C926 = new QMoMTreeItemModelBase("m_Unk_C926");
        ptree->appendTree(ptreem_Unk_C926, "");
    }
    for (unsigned i = 0; i < 0xD15A - 0xC926; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_C926[" << i << "]";
          ptreem_Unk_C926->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_C926[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_Battle_figures_256, "m_addr_Battle_figures_256"), "");
    ptree->appendChild("m_Nr_figures_on_battlefield", new QMoMTreeItemModel<int16_t>(&rhs->m_Nr_figures_on_battlefield));
    QMoMTreeItemModelBase* ptreem_Unk_D160 = ptree;
    if (0xD188 - 0xD160 > 3)
    {
        ptreem_Unk_D160 = new QMoMTreeItemModelBase("m_Unk_D160");
        ptree->appendTree(ptreem_Unk_D160, "");
    }
    for (unsigned i = 0; i < 0xD188 - 0xD160; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_D160[" << i << "]";
          ptreem_Unk_D160->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_D160[i]));
    }
    ptree->appendChild("m_Battle_activetile_anim", new QMoMTreeItemModel<uint16_t>(&rhs->m_Battle_activetile_anim));
    ptree->appendChild("m_Battle_tileselection_anim", new QMoMTreeItemModel<uint16_t>(&rhs->m_Battle_tileselection_anim));
    QMoMTreeItemModelBase* ptreem_Unk_D18C = ptree;
    if (0xD49A - 0xD18C > 3)
    {
        ptreem_Unk_D18C = new QMoMTreeItemModelBase("m_Unk_D18C");
        ptree->appendTree(ptreem_Unk_D18C, "");
    }
    for (unsigned i = 0; i < 0xD49A - 0xD18C; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_D18C[" << i << "]";
          ptreem_Unk_D18C->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_D18C[i]));
    }
    QMoMTreeItemModelBase* ptreem_NEAR_HEAP = ptree;
    if (0x1130 > 3)
    {
        ptreem_NEAR_HEAP = new QMoMTreeItemModelBase("m_NEAR_HEAP");
        ptree->appendTree(ptreem_NEAR_HEAP, "");
    }
    for (unsigned i = 0; i < 0x1130; ++i)
    {
          std::ostringstream oss;
          oss << "m_NEAR_HEAP[" << i << "]";
          ptreem_NEAR_HEAP->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_NEAR_HEAP[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_E5CA = ptree;
    if (0xE5FC - 0xE5CA > 3)
    {
        ptreem_Unk_E5CA = new QMoMTreeItemModelBase("m_Unk_E5CA");
        ptree->appendTree(ptreem_Unk_E5CA, "");
    }
    for (unsigned i = 0; i < 0xE5FC - 0xE5CA; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E5CA[" << i << "]";
          ptreem_Unk_E5CA->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E5CA[i]));
    }
    QMoMTreeItemModelBase* ptreem_EMS_lbx_descriptors_0C = ptree;
    if (40 > 3)
    {
        ptreem_EMS_lbx_descriptors_0C = new QMoMTreeItemModelBase("m_EMS_lbx_descriptors_0C");
        ptree->appendTree(ptreem_EMS_lbx_descriptors_0C, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_EMS_lbx_descriptors_0C[" << i << "]";
          ptreem_EMS_lbx_descriptors_0C->appendTree(constructTreeItem(&rhs->m_EMS_lbx_descriptors_0C[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_required_EMS_memory", new QMoMTreeItemModel<uint16_t>(&rhs->m_required_EMS_memory));
    QMoMTreeItemModelBase* ptreem_Unk_E7DE = ptree;
    if (0xE800 - 0xE7DE > 3)
    {
        ptreem_Unk_E7DE = new QMoMTreeItemModelBase("m_Unk_E7DE");
        ptree->appendTree(ptreem_Unk_E7DE, "");
    }
    for (unsigned i = 0; i < 0xE800 - 0xE7DE; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E7DE[" << i << "]";
          ptreem_Unk_E7DE->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E7DE[i]));
    }
    QMoMTreeItemModelBase* ptreem_arr16_font_palette = ptree;
    if (16 > 3)
    {
        ptreem_arr16_font_palette = new QMoMTreeItemModelBase("m_arr16_font_palette");
        ptree->appendTree(ptreem_arr16_font_palette, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_arr16_font_palette[" << i << "]";
          ptreem_arr16_font_palette->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_arr16_font_palette[i]));
    }
    ptree->appendChild("m_byte_00h_from_fonts_style_data", new QMoMTreeItemModel<uint8_t>(&rhs->m_byte_00h_from_fonts_style_data));
    ptree->appendChild("m_byte_14h_from_fonts_style_data", new QMoMTreeItemModel<uint8_t>(&rhs->m_byte_14h_from_fonts_style_data));
    ptree->appendChild("m_byte_24h_from_fonts_style_data", new QMoMTreeItemModel<uint8_t>(&rhs->m_byte_24h_from_fonts_style_data));
    ptree->appendChild("m_byte_34h_from_fonts_style_data", new QMoMTreeItemModel<uint8_t>(&rhs->m_byte_34h_from_fonts_style_data));
    ptree->appendChild("m_Unk_E814", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_E814));
    ptree->appendChild("m_Unk_E816", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_E816));
    ptree->appendChild("m_font_palette_section_index", new QMoMTreeItemModel<int16_t>(&rhs->m_font_palette_section_index));
    ptree->appendChild("m_cur_font_nr", new QMoMTreeItemModel<int16_t>(&rhs->m_cur_font_nr));
    ptree->appendChild("m_display_text_xpel", new QMoMTreeItemModel<int16_t>(&rhs->m_display_text_xpel));
    ptree->appendChild("m_display_text_ypel", new QMoMTreeItemModel<int16_t>(&rhs->m_display_text_ypel));
    ptree->appendChild("m_seg_fonts_style_data", new QMoMTreeItemModel<uint16_t>(&rhs->m_seg_fonts_style_data));
    ptree->appendChild("m_seg_fonts_border_style_data", new QMoMTreeItemModel<uint16_t>(&rhs->m_seg_fonts_border_style_data));
    QMoMTreeItemModelBase* ptreem_Unk_E824 = ptree;
    if (0xE860 - 0xE824 > 3)
    {
        ptreem_Unk_E824 = new QMoMTreeItemModelBase("m_Unk_E824");
        ptree->appendTree(ptreem_Unk_E824, "");
    }
    for (unsigned i = 0; i < 0xE860 - 0xE824; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E824[" << i << "]";
          ptreem_Unk_E824->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E824[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_EMS_lbx_descriptor, "m_EMS_lbx_descriptor"), "");
    QMoMTreeItemModelBase* ptreem_Unk_E86C = ptree;
    if (0xE8A2 - 0xE86C > 3)
    {
        ptreem_Unk_E86C = new QMoMTreeItemModelBase("m_Unk_E86C");
        ptree->appendTree(ptreem_Unk_E86C, "");
    }
    for (unsigned i = 0; i < 0xE8A2 - 0xE86C; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E86C[" << i << "]";
          ptreem_Unk_E86C->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E86C[i]));
    }
    ptree->appendChild("m_clickable_area_nr", new QMoMTreeItemModel<int16_t>(&rhs->m_clickable_area_nr));
    QMoMTreeItemModelBase* ptreem_Unk_E8A4 = ptree;
    if (0xE8AC - 0xE8A4 > 3)
    {
        ptreem_Unk_E8A4 = new QMoMTreeItemModelBase("m_Unk_E8A4");
        ptree->appendTree(ptreem_Unk_E8A4, "");
    }
    for (unsigned i = 0; i < 0xE8AC - 0xE8A4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E8A4[" << i << "]";
          ptreem_Unk_E8A4->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E8A4[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_ClickableArea, "m_addr_ClickableArea"), "");
    QMoMTreeItemModelBase* ptreem_Unk_E8B0 = ptree;
    if (0xEA54 - 0xE8B0 > 3)
    {
        ptreem_Unk_E8B0 = new QMoMTreeItemModelBase("m_Unk_E8B0");
        ptree->appendTree(ptreem_Unk_E8B0, "");
    }
    for (unsigned i = 0; i < 0xEA54 - 0xE8B0; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_E8B0[" << i << "]";
          ptreem_Unk_E8B0->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_E8B0[i]));
    }
    QMoMTreeItemModelBase* ptreem_PARALIGN09 = ptree;
    if (0x0C > 3)
    {
        ptreem_PARALIGN09 = new QMoMTreeItemModelBase("m_PARALIGN09");
        ptree->appendTree(ptreem_PARALIGN09, "");
    }
    for (unsigned i = 0; i < 0x0C; ++i)
    {
          std::ostringstream oss;
          oss << "m_PARALIGN09[" << i << "]";
          ptreem_PARALIGN09->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_PARALIGN09[i]));
    }
    QMoMTreeItemModelBase* ptreem_StackSegment = ptree;
    if (0x40 > 3)
    {
        ptreem_StackSegment = new QMoMTreeItemModelBase("m_StackSegment");
        ptree->appendTree(ptreem_StackSegment, "");
    }
    for (unsigned i = 0; i < 0x40; ++i)
    {
          std::ostringstream oss;
          oss << "m_StackSegment[" << i << "]";
          ptreem_StackSegment->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_StackSegment[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMFontsCharacterWidths* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMFontsCharacterWidths>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_characterWidths = ptree;
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_characterWidths[" << i << "]";
          ptreem_characterWidths->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_characterWidths[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMFontsGlyphOffsets* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMFontsGlyphOffsets>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_glyphOffsets = ptree;
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_glyphOffsets[" << i << "]";
          ptreem_glyphOffsets->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_glyphOffsets[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMFontsStyleData* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMFontsStyleData>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Unk_0000 = ptree;
    if (0x0010 > 3)
    {
        ptreem_Unk_0000 = new QMoMTreeItemModelBase("m_Unk_0000");
        ptree->appendTree(ptreem_Unk_0000, "");
    }
    for (unsigned i = 0; i < 0x0010; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_0000[" << i << "]";
          ptreem_Unk_0000->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_0000[i]));
    }
    ptree->appendChild("m_curFontHeight", new QMoMTreeItemModel<int16_t>(&rhs->m_curFontHeight));
    QMoMTreeItemModelBase* ptreem_Unk_0012 = ptree;
    if (0x0036 > 3)
    {
        ptreem_Unk_0012 = new QMoMTreeItemModelBase("m_Unk_0012");
        ptree->appendTree(ptreem_Unk_0012, "");
    }
    for (unsigned i = 0; i < 0x0036; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_0012[" << i << "]";
          ptreem_Unk_0012->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_0012[i]));
    }
    ptree->appendChild("m_curHorizontalSpacing", new QMoMTreeItemModel<int16_t>(&rhs->m_curHorizontalSpacing));
    QMoMTreeItemModelBase* ptreem_curCharacterWidths = ptree;
    if (0x60 > 3)
    {
        ptreem_curCharacterWidths = new QMoMTreeItemModelBase("m_curCharacterWidths");
        ptree->appendTree(ptreem_curCharacterWidths, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_curCharacterWidths[" << i << "]";
          ptreem_curCharacterWidths->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_curCharacterWidths[i]));
    }
    QMoMTreeItemModelBase* ptreem_curGlyphOffsets = ptree;
    if (0x60 > 3)
    {
        ptreem_curGlyphOffsets = new QMoMTreeItemModelBase("m_curGlyphOffsets");
        ptree->appendTree(ptreem_curGlyphOffsets, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_curGlyphOffsets[" << i << "]";
          ptreem_curGlyphOffsets->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_curGlyphOffsets[i]));
    }
    QMoMTreeItemModelBase* ptreem_allFontHeights = ptree;
    if (8 > 3)
    {
        ptreem_allFontHeights = new QMoMTreeItemModelBase("m_allFontHeights");
        ptree->appendTree(ptreem_allFontHeights, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_allFontHeights[" << i << "]";
          ptreem_allFontHeights->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_allFontHeights[i]));
    }
    QMoMTreeItemModelBase* ptreem_allHorizontalSpacings = ptree;
    if (8 > 3)
    {
        ptreem_allHorizontalSpacings = new QMoMTreeItemModelBase("m_allHorizontalSpacings");
        ptree->appendTree(ptreem_allHorizontalSpacings, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_allHorizontalSpacings[" << i << "]";
          ptreem_allHorizontalSpacings->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_allHorizontalSpacings[i]));
    }
    QMoMTreeItemModelBase* ptreem_allLineSpacings = ptree;
    if (8 > 3)
    {
        ptreem_allLineSpacings = new QMoMTreeItemModelBase("m_allLineSpacings");
        ptree->appendTree(ptreem_allLineSpacings, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_allLineSpacings[" << i << "]";
          ptreem_allLineSpacings->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_allLineSpacings[i]));
    }
    QMoMTreeItemModelBase* ptreem_allCharacterWidths = ptree;
    if (8 > 3)
    {
        ptreem_allCharacterWidths = new QMoMTreeItemModelBase("m_allCharacterWidths");
        ptree->appendTree(ptreem_allCharacterWidths, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_allCharacterWidths[" << i << "]";
          ptreem_allCharacterWidths->appendTree(constructTreeItem(&rhs->m_allCharacterWidths[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_allGlyphOffsets = ptree;
    if (8 > 3)
    {
        ptreem_allGlyphOffsets = new QMoMTreeItemModelBase("m_allGlyphOffsets");
        ptree->appendTree(ptreem_allGlyphOffsets, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_allGlyphOffsets[" << i << "]";
          ptreem_allGlyphOffsets->appendTree(constructTreeItem(&rhs->m_allGlyphOffsets[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_glyphData = ptree;
    if (1 > 3)
    {
        ptreem_glyphData = new QMoMTreeItemModelBase("m_glyphData");
        ptree->appendTree(ptreem_glyphData, "");
    }
    for (unsigned i = 0; i < 1; ++i)
    {
          std::ostringstream oss;
          oss << "m_glyphData[" << i << "]";
          ptreem_glyphData->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_glyphData[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMImageHeaderLbx* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMImageHeaderLbx>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("width", new QMoMTreeItemModel<uint16_t>(&rhs->width));
    ptree->appendChild("height", new QMoMTreeItemModel<uint16_t>(&rhs->height));
    ptree->appendChild("compression", new QMoMTreeItemModel<uint16_t>(&rhs->compression));
    ptree->appendChild("nframes", new QMoMTreeItemModel<uint16_t>(&rhs->nframes));
    ptree->appendChild("frameDelay", new QMoMTreeItemModel<uint16_t>(&rhs->frameDelay));
    ptree->appendChild("flags", new QMoMTreeItemModel<uint16_t>(&rhs->flags));
    ptree->appendChild("reserved_0C", new QMoMTreeItemModel<uint16_t>(&rhs->reserved_0C));
    ptree->appendChild("paletteInfoOffset", new QMoMTreeItemModel<uint32_t>(&rhs->paletteInfoOffset));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMMagicDataSegment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMMagicDataSegment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_DataSegmentStart", new QMoMTreeItemModel<char[47]>(rhs->m_DataSegmentStart));
    QMoMTreeItemModelBase* ptreem_Unk_002F = ptree;
    if (0x2AD0 - 47 > 3)
    {
        ptreem_Unk_002F = new QMoMTreeItemModelBase("m_Unk_002F");
        ptree->appendTree(ptreem_Unk_002F, "");
    }
    for (unsigned i = 0; i < 0x2AD0 - 47; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_002F[" << i << "]";
          ptreem_Unk_002F->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_002F[i]));
    }
    QMoMTreeItemModelBase* ptreem_Wizard_Types = ptree;
    if (ePortrait_MAX > 3)
    {
        ptreem_Wizard_Types = new QMoMTreeItemModelBase("m_Wizard_Types");
        ptree->appendTree(ptreem_Wizard_Types, "");
    }
    for (unsigned i = 0; i < ePortrait_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizard_Types[" << i << "]";
          ptreem_Wizard_Types->appendTree(constructTreeItem(&rhs->m_Wizard_Types[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unk_2C1A = ptree;
    if (10 > 3)
    {
        ptreem_Unk_2C1A = new QMoMTreeItemModelBase("m_Unk_2C1A");
        ptree->appendTree(ptreem_Unk_2C1A, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_2C1A[" << i << "]";
          ptreem_Unk_2C1A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Unk_2C1A[i]));
    }
    QMoMTreeItemModelBase* ptreem_Nr_spell_choices = ptree;
    if (10 > 3)
    {
        ptreem_Nr_spell_choices = new QMoMTreeItemModelBase("m_Nr_spell_choices");
        ptree->appendTree(ptreem_Nr_spell_choices, "");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
          std::ostringstream oss;
          oss << "m_Nr_spell_choices[" << i << "]";
          ptreem_Nr_spell_choices->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Nr_spell_choices[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_2C40 = ptree;
    if (0x2C6A - 0x2C42 > 3)
    {
        ptreem_Unk_2C40 = new QMoMTreeItemModelBase("m_Unk_2C40");
        ptree->appendTree(ptreem_Unk_2C40, "");
    }
    for (unsigned i = 0; i < 0x2C6A - 0x2C42; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_2C40[" << i << "]";
          ptreem_Unk_2C40->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_2C40[i]));
    }
    QMoMTreeItemModelBase* ptreem_Preselected_spell_choices = ptree;
    if (65 > 3)
    {
        ptreem_Preselected_spell_choices = new QMoMTreeItemModelBase("m_Preselected_spell_choices");
        ptree->appendTree(ptreem_Preselected_spell_choices, "");
    }
    for (unsigned i = 0; i < 65; ++i)
    {
          std::ostringstream oss;
          oss << "m_Preselected_spell_choices[" << i << "]";
          ptreem_Preselected_spell_choices->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell16>(&rhs->m_Preselected_spell_choices[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_2CEC = ptree;
    if (0x3067 - 0x2CEC > 3)
    {
        ptreem_Unk_2CEC = new QMoMTreeItemModelBase("m_Unk_2CEC");
        ptree->appendTree(ptreem_Unk_2CEC, "");
    }
    for (unsigned i = 0; i < 0x3067 - 0x2CEC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_2CEC[" << i << "]";
          ptreem_Unk_2CEC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_2CEC[i]));
    }
    ptree->appendChild("m_Copyright1_and_Version", new QMoMTreeItemModel<char[41]>(rhs->m_Copyright1_and_Version));
    QMoMTreeItemModelBase* ptreem_Unk_3090 = ptree;
    if (0x35D0 - 0x3090 > 3)
    {
        ptreem_Unk_3090 = new QMoMTreeItemModelBase("m_Unk_3090");
        ptree->appendTree(ptreem_Unk_3090, "");
    }
    for (unsigned i = 0; i < 0x35D0 - 0x3090; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_3090[" << i << "]";
          ptreem_Unk_3090->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_3090[i]));
    }
    QMoMTreeItemModelBase* ptreem_Hero_Stats_Initializers = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Hero_Stats_Initializers = new QMoMTreeItemModelBase("m_Hero_Stats_Initializers");
        ptree->appendTree(ptreem_Hero_Stats_Initializers, "");
    }
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Hero_Stats_Initializers[" << i << "]";
          ptreem_Hero_Stats_Initializers->appendTree(constructTreeItem(&rhs->m_Hero_Stats_Initializers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unk_3846 = ptree;
    if (0x389A - 0x3846 > 3)
    {
        ptreem_Unk_3846 = new QMoMTreeItemModelBase("m_Unk_3846");
        ptree->appendTree(ptreem_Unk_3846, "");
    }
    for (unsigned i = 0; i < 0x389A - 0x3846; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_3846[" << i << "]";
          ptreem_Unk_3846->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_3846[i]));
    }
    ptree->appendChild("m_Copyright2_and_Version", new QMoMTreeItemModel<char[41]>(rhs->m_Copyright2_and_Version));
    QMoMTreeItemModelBase* ptreem_Unk_38C3 = ptree;
    if (0x3CB8 - 0x38C3 > 3)
    {
        ptreem_Unk_38C3 = new QMoMTreeItemModelBase("m_Unk_38C3");
        ptree->appendTree(ptreem_Unk_38C3, "");
    }
    for (unsigned i = 0; i < 0x3CB8 - 0x38C3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_38C3[" << i << "]";
          ptreem_Unk_38C3->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_38C3[i]));
    }
    ptree->appendChild("m_BIOS_clock_snapshot", new QMoMTreeItemModel<uint32_t>(&rhs->m_BIOS_clock_snapshot));
    QMoMTreeItemModelBase* ptreem_Unk_3CBC = ptree;
    if (0x40E4 - 0x3CBC > 3)
    {
        ptreem_Unk_3CBC = new QMoMTreeItemModelBase("m_Unk_3CBC");
        ptree->appendTree(ptreem_Unk_3CBC, "");
    }
    for (unsigned i = 0; i < 0x40E4 - 0x3CBC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_3CBC[" << i << "]";
          ptreem_Unk_3CBC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_3CBC[i]));
    }
    ptree->appendChild("m_EMS_data_reference_point", new QMoMTreeItemModel<uint16_t>(&rhs->m_EMS_data_reference_point));
    QMoMTreeItemModelBase* ptreem_Unk_40E6 = ptree;
    if (0x431E - 0x40E6 > 3)
    {
        ptreem_Unk_40E6 = new QMoMTreeItemModelBase("m_Unk_40E6");
        ptree->appendTree(ptreem_Unk_40E6, "");
    }
    for (unsigned i = 0; i < 0x431E - 0x40E6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_40E6[" << i << "]";
          ptreem_Unk_40E6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_40E6[i]));
    }
    ptree->appendChild("m_RNG_seed_lo", new QMoMTreeItemModel<uint16_t>(&rhs->m_RNG_seed_lo));
    ptree->appendChild("m_RNG_seed_hi", new QMoMTreeItemModel<uint16_t>(&rhs->m_RNG_seed_hi));
    QMoMTreeItemModelBase* ptreem_Unk_4322 = ptree;
    if (0x434E - 0x4322 > 3)
    {
        ptreem_Unk_4322 = new QMoMTreeItemModelBase("m_Unk_4322");
        ptree->appendTree(ptreem_Unk_4322, "");
    }
    for (unsigned i = 0; i < 0x434E - 0x4322; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_4322[" << i << "]";
          ptreem_Unk_4322->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_4322[i]));
    }
    ptree->appendChild("m_DEBUG_Off", new QMoMTreeItemModel<uint16_t>(&rhs->m_DEBUG_Off));
    QMoMTreeItemModelBase* ptreem_Unk_4350 = ptree;
    if (0x4D44 - 0x4350 > 3)
    {
        ptreem_Unk_4350 = new QMoMTreeItemModelBase("m_Unk_4350");
        ptree->appendTree(ptreem_Unk_4350, "");
    }
    for (unsigned i = 0; i < 0x4D44 - 0x4350; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_4350[" << i << "]";
          ptreem_Unk_4350->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_4350[i]));
    }
    ptree->appendChild("m_Want_input_GUESS", new QMoMTreeItemModel<int16_t>(&rhs->m_Want_input_GUESS));
    QMoMTreeItemModelBase* ptreem_Unk_4D46 = ptree;
    if (0x52EA - 0x4D46 > 3)
    {
        ptreem_Unk_4D46 = new QMoMTreeItemModelBase("m_Unk_4D46");
        ptree->appendTree(ptreem_Unk_4D46, "");
    }
    for (unsigned i = 0; i < 0x52EA - 0x4D46; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_4D46[" << i << "]";
          ptreem_Unk_4D46->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_4D46[i]));
    }
    ptree->appendChild("m_Button_New_game_ID", new QMoMTreeItemModel<int16_t>(&rhs->m_Button_New_game_ID));
    QMoMTreeItemModelBase* ptreem_Unk_52EC = ptree;
    if (0x6900 - 0x52EC > 3)
    {
        ptreem_Unk_52EC = new QMoMTreeItemModelBase("m_Unk_52EC");
        ptree->appendTree(ptreem_Unk_52EC, "");
    }
    for (unsigned i = 0; i < 0x6900 - 0x52EC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_52EC[" << i << "]";
          ptreem_Unk_52EC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_52EC[i]));
    }
    QMoMTreeItemModelBase* ptreem_Wizards = ptree;
    if (6 > 3)
    {
        ptreem_Wizards = new QMoMTreeItemModelBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Spells_selected_of_Realm = ptree;
    if (150 > 3)
    {
        ptreem_Spells_selected_of_Realm = new QMoMTreeItemModelBase("m_Spells_selected_of_Realm");
        ptree->appendTree(ptreem_Spells_selected_of_Realm, "");
    }
    for (unsigned i = 0; i < 150; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_selected_of_Realm[" << i << "]";
          ptreem_Spells_selected_of_Realm->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell16>(&rhs->m_Spells_selected_of_Realm[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_86DC = ptree;
    if (0x87C4 - 0x86DC > 3)
    {
        ptreem_Unk_86DC = new QMoMTreeItemModelBase("m_Unk_86DC");
        ptree->appendTree(ptreem_Unk_86DC, "");
    }
    for (unsigned i = 0; i < 0x87C4 - 0x86DC; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_86DC[" << i << "]";
          ptreem_Unk_86DC->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_86DC[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Settings, "m_Game_Settings"), "");
    QMoMTreeItemModelBase* ptreem_Unk_89A6 = ptree;
    if (0x8A14 - 0x89A6 > 3)
    {
        ptreem_Unk_89A6 = new QMoMTreeItemModelBase("m_Unk_89A6");
        ptree->appendTree(ptreem_Unk_89A6, "");
    }
    for (unsigned i = 0; i < 0x8A14 - 0x89A6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_89A6[" << i << "]";
          ptreem_Unk_89A6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_89A6[i]));
    }
    QMoMTreeItemModelBase* ptreem_Spell_Selected = ptree;
    if (eSpell_MAX > 3)
    {
        ptreem_Spell_Selected = new QMoMTreeItemModelBase("m_Spell_Selected");
        ptree->appendTree(ptreem_Spell_Selected, "");
    }
    for (unsigned i = 0; i < eSpell_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spell_Selected[" << i << "]";
          ptreem_Spell_Selected->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell>(&rhs->m_Spell_Selected[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_8AEB = ptree;
    if (0x8D52 - 0x8AEB > 3)
    {
        ptreem_Unk_8AEB = new QMoMTreeItemModelBase("m_Unk_8AEB");
        ptree->appendTree(ptreem_Unk_8AEB, "");
    }
    for (unsigned i = 0; i < 0x8D52 - 0x8AEB; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_8AEB[" << i << "]";
          ptreem_Unk_8AEB->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_8AEB[i]));
    }
    QMoMTreeItemModelBase* ptreem_Spells_Known_Realm = ptree;
    if (66 > 3)
    {
        ptreem_Spells_Known_Realm = new QMoMTreeItemModelBase("m_Spells_Known_Realm");
        ptree->appendTree(ptreem_Spells_Known_Realm, "");
    }
    for (unsigned i = 0; i < 66; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm[" << i << "]";
          ptreem_Spells_Known_Realm->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Spells_Known_Realm[i]));
    }
    ptree->appendChild("m_Unk_8DD6", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_8DD6));
    ptree->appendChild("m_Sorcery_Picks_Divider", new QMoMTreeItemModel<uint16_t>(&rhs->m_Sorcery_Picks_Divider));
    ptree->appendChild("m_Nature_Picks_Divider", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nature_Picks_Divider));
    ptree->appendChild("m_Chaos_Picks_Divider", new QMoMTreeItemModel<uint16_t>(&rhs->m_Chaos_Picks_Divider));
    ptree->appendChild("m_Death_Picks_Divider", new QMoMTreeItemModel<uint16_t>(&rhs->m_Death_Picks_Divider));
    ptree->appendChild("m_Life_Picks_Divider", new QMoMTreeItemModel<uint16_t>(&rhs->m_Life_Picks_Divider));
    QMoMTreeItemModelBase* ptreem_Unk_8DE2 = ptree;
    if (2 > 3)
    {
        ptreem_Unk_8DE2 = new QMoMTreeItemModelBase("m_Unk_8DE2");
        ptree->appendTree(ptreem_Unk_8DE2, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_8DE2[" << i << "]";
          ptreem_Unk_8DE2->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_8DE2[i]));
    }
    QMoMTreeItemModelBase* ptreem_Spells_Known_Realm_Indexed = ptree;
    if (15 > 3)
    {
        ptreem_Spells_Known_Realm_Indexed = new QMoMTreeItemModelBase("m_Spells_Known_Realm_Indexed");
        ptree->appendTree(ptreem_Spells_Known_Realm_Indexed, "");
    }
    for (unsigned i = 0; i < 15; ++i)
    {
          std::ostringstream oss;
          oss << "m_Spells_Known_Realm_Indexed[" << i << "]";
          ptreem_Spells_Known_Realm_Indexed->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Spells_Known_Realm_Indexed[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_8E04 = ptree;
    if (0x8E0C - 0x8E04 > 3)
    {
        ptreem_Unk_8E04 = new QMoMTreeItemModelBase("m_Unk_8E04");
        ptree->appendTree(ptreem_Unk_8E04, "");
    }
    for (unsigned i = 0; i < 0x8E0C - 0x8E04; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_8E04[" << i << "]";
          ptreem_Unk_8E04->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_8E04[i]));
    }
    QMoMTreeItemModelBase* ptreem_Button_IDs = ptree;
    if (30 > 3)
    {
        ptreem_Button_IDs = new QMoMTreeItemModelBase("m_Button_IDs");
        ptree->appendTree(ptreem_Button_IDs, "");
    }
    for (unsigned i = 0; i < 30; ++i)
    {
          std::ostringstream oss;
          oss << "m_Button_IDs[" << i << "]";
          ptreem_Button_IDs->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Button_IDs[i]));
    }
    ptree->appendChild("m_Wizard_portrait_shown", new QMoMTreeItemModel<ePortrait>(&rhs->m_Wizard_portrait_shown));
    QMoMTreeItemModelBase* ptreem_Unk_8E49 = ptree;
    if (0x8E92 - 0x8E49 > 3)
    {
        ptreem_Unk_8E49 = new QMoMTreeItemModelBase("m_Unk_8E49");
        ptree->appendTree(ptreem_Unk_8E49, "");
    }
    for (unsigned i = 0; i < 0x8E92 - 0x8E49; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_8E49[" << i << "]";
          ptreem_Unk_8E49->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_8E49[i]));
    }
    ptree->appendChild("m_Button_OK_ID", new QMoMTreeItemModel<int16_t>(&rhs->m_Button_OK_ID));
    ptree->appendChild("m_Total_Picks_Left", new QMoMTreeItemModel<uint16_t>(&rhs->m_Total_Picks_Left));
    QMoMTreeItemModelBase* ptreem_Unk_8E96 = ptree;
    if (0xA8A2 - 0x8E96 > 3)
    {
        ptreem_Unk_8E96 = new QMoMTreeItemModelBase("m_Unk_8E96");
        ptree->appendTree(ptreem_Unk_8E96, "");
    }
    for (unsigned i = 0; i < 0xA8A2 - 0x8E96; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_8E96[" << i << "]";
          ptreem_Unk_8E96->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_8E96[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_addr_ClickableArea, "m_addr_ClickableArea"), "");
    QMoMTreeItemModelBase* ptreem_Unk_A8A6 = ptree;
    if (0xAA4A - 0xA8A6 > 3)
    {
        ptreem_Unk_A8A6 = new QMoMTreeItemModelBase("m_Unk_A8A6");
        ptree->appendTree(ptreem_Unk_A8A6, "");
    }
    for (unsigned i = 0; i < 0xAA4A - 0xA8A6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_A8A6[" << i << "]";
          ptreem_Unk_A8A6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_A8A6[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_AA4A = ptree;
    if (0xFE68 - 0xAA4A > 3)
    {
        ptreem_Unk_AA4A = new QMoMTreeItemModelBase("m_Unk_AA4A");
        ptree->appendTree(ptreem_Unk_AA4A, "");
    }
    for (unsigned i = 0; i < 0xFE68 - 0xAA4A; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_AA4A[" << i << "]";
          ptreem_Unk_AA4A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_AA4A[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_1", new QMoMTreeItemModel<char[11]>(rhs->m_Wizards_Name_Shown_1));
    QMoMTreeItemModelBase* ptreem_Unk_FE73 = ptree;
    if (0xFEC2 - 0xFE73 > 3)
    {
        ptreem_Unk_FE73 = new QMoMTreeItemModelBase("m_Unk_FE73");
        ptree->appendTree(ptreem_Unk_FE73, "");
    }
    for (unsigned i = 0; i < 0xFEC2 - 0xFE73; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_FE73[" << i << "]";
          ptreem_Unk_FE73->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_FE73[i]));
    }
    ptree->appendChild("m_Wizards_Name_Shown_2", new QMoMTreeItemModel<char[11]>(rhs->m_Wizards_Name_Shown_2));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(MoMPaletteInfoLbx* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<MoMPaletteInfoLbx>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("paletteOffset", new QMoMTreeItemModel<uint16_t>(&rhs->paletteOffset));
    ptree->appendChild("firstPaletteColorIndex", new QMoMTreeItemModel<uint16_t>(&rhs->firstPaletteColorIndex));
    ptree->appendChild("paletteColorCount", new QMoMTreeItemModel<uint16_t>(&rhs->paletteColorCount));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Movement_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Movement_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Movement_Flags maskCavalry;
    memset(&maskCavalry, '\0', sizeof(maskCavalry));
    maskCavalry.Cavalry = 1;
    if (1 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCavalry));
    else if (2 == sizeof(maskCavalry))
        ptree->appendChild("Cavalry", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCavalry));
    else
        ptree->appendChild("Cavalry", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCavalry));
    Movement_Flags maskSailing;
    memset(&maskSailing, '\0', sizeof(maskSailing));
    maskSailing.Sailing = 1;
    if (1 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSailing));
    else if (2 == sizeof(maskSailing))
        ptree->appendChild("Sailing", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSailing));
    else
        ptree->appendChild("Sailing", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSailing));
    Movement_Flags maskSwimming;
    memset(&maskSwimming, '\0', sizeof(maskSwimming));
    maskSwimming.Swimming = 1;
    if (1 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSwimming));
    else if (2 == sizeof(maskSwimming))
        ptree->appendChild("Swimming", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSwimming));
    else
        ptree->appendChild("Swimming", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSwimming));
    Movement_Flags maskFlying;
    memset(&maskFlying, '\0', sizeof(maskFlying));
    maskFlying.Flying = 1;
    if (1 == sizeof(maskFlying))
        ptree->appendChild("Flying", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlying));
    else if (2 == sizeof(maskFlying))
        ptree->appendChild("Flying", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlying));
    else
        ptree->appendChild("Flying", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlying));
    Movement_Flags maskTeleporting;
    memset(&maskTeleporting, '\0', sizeof(maskTeleporting));
    maskTeleporting.Teleporting = 1;
    if (1 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTeleporting));
    else if (2 == sizeof(maskTeleporting))
        ptree->appendChild("Teleporting", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTeleporting));
    else
        ptree->appendChild("Teleporting", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTeleporting));
    Movement_Flags maskForester;
    memset(&maskForester, '\0', sizeof(maskForester));
    maskForester.Forester = 1;
    if (1 == sizeof(maskForester))
        ptree->appendChild("Forester", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskForester));
    else if (2 == sizeof(maskForester))
        ptree->appendChild("Forester", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskForester));
    else
        ptree->appendChild("Forester", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskForester));
    Movement_Flags maskMountaineer;
    memset(&maskMountaineer, '\0', sizeof(maskMountaineer));
    maskMountaineer.Mountaineer = 1;
    if (1 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMountaineer));
    else if (2 == sizeof(maskMountaineer))
        ptree->appendChild("Mountaineer", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMountaineer));
    else
        ptree->appendChild("Mountaineer", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMountaineer));
    Movement_Flags maskMerging;
    memset(&maskMerging, '\0', sizeof(maskMerging));
    maskMerging.Merging = 1;
    if (1 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMerging));
    else if (2 == sizeof(maskMerging))
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMerging));
    else
        ptree->appendChild("Merging", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMerging));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Node_Attr* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Node_Attr>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItemModel<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Power_Node", new QMoMTreeItemModel<int8_t>(&rhs->m_Power_Node));
    QMoMTreeItemModelBase* ptreem_XPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_XPos_Mana = new QMoMTreeItemModelBase("m_XPos_Mana");
        ptree->appendTree(ptreem_XPos_Mana, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_XPos_Mana[" << i << "]";
          ptreem_XPos_Mana->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_XPos_Mana[i]));
    }
    QMoMTreeItemModelBase* ptreem_YPos_Mana = ptree;
    if (20 > 3)
    {
        ptreem_YPos_Mana = new QMoMTreeItemModelBase("m_YPos_Mana");
        ptree->appendTree(ptreem_YPos_Mana, "");
    }
    for (unsigned i = 0; i < 20; ++i)
    {
          std::ostringstream oss;
          oss << "m_YPos_Mana[" << i << "]";
          ptreem_YPos_Mana->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_YPos_Mana[i]));
    }
    ptree->appendChild("m_Node_Type", new QMoMTreeItemModel<eNode_Type>(&rhs->m_Node_Type));
    ptree->appendChild("m_Status", new QMoMTreeItemModel<uint8_t>(&rhs->m_Status));
    ptree->appendChild("m_Unk_2F", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_2F));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Race_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Race_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new QMoMTreeItemModel<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Number_of_prohibited_buildings", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_prohibited_buildings));
    QMoMTreeItemModelBase* ptreem_Prohibited_buildings = ptree;
    if (7 > 3)
    {
        ptreem_Prohibited_buildings = new QMoMTreeItemModelBase("m_Prohibited_buildings");
        ptree->appendTree(ptreem_Prohibited_buildings, "");
    }
    for (unsigned i = 0; i < 7; ++i)
    {
          std::ostringstream oss;
          oss << "m_Prohibited_buildings[" << i << "]";
          ptreem_Prohibited_buildings->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eBuilding>(&rhs->m_Prohibited_buildings[i]));
    }
    ptree->appendChild("m_Outpost_growth_probability", new QMoMTreeItemModel<uint16_t>(&rhs->m_Outpost_growth_probability));
    ptree->appendChild("m_City_population_growth_modifier", new QMoMTreeItemModel<int16_t>(&rhs->m_City_population_growth_modifier));
    ptree->appendChild("m_Housing_picture", new QMoMTreeItemModel<eHousing>(&rhs->m_Housing_picture));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(SaveGame* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<SaveGame>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_List_Hero_stats = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_List_Hero_stats = new QMoMTreeItemModelBase("m_List_Hero_stats");
        ptree->appendTree(ptreem_List_Hero_stats, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_List_Hero_stats[" << i << "]";
          ptreem_List_Hero_stats->appendTree(constructTreeItem(&rhs->m_List_Hero_stats[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Game_Data, "m_Game_Data"), "");
    QMoMTreeItemModelBase* ptreem_Wizards = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Wizards = new QMoMTreeItemModelBase("m_Wizards");
        ptree->appendTree(ptreem_Wizards, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Wizards[" << i << "]";
          ptreem_Wizards->appendTree(constructTreeItem(&rhs->m_Wizards[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Map_Row = new QMoMTreeItemModelBase("m_Arcanus_Map_Row");
        ptree->appendTree(ptreem_Arcanus_Map_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Map_Row[" << i << "]";
          ptreem_Arcanus_Map_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Map_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Map_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Map_Row = new QMoMTreeItemModelBase("m_Myrror_Map_Row");
        ptree->appendTree(ptreem_Myrror_Map_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Map_Row[" << i << "]";
          ptreem_Myrror_Map_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Map_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Arcanus_UNK01 = new QMoMTreeItemModelBase("m_Arcanus_UNK01");
        ptree->appendTree(ptreem_Arcanus_UNK01, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_UNK01[" << i << "]";
          ptreem_Arcanus_UNK01->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Arcanus_UNK01[i]));
    }
    QMoMTreeItemModelBase* ptreem_Myrror_UNK01 = ptree;
    if (0x60 > 3)
    {
        ptreem_Myrror_UNK01 = new QMoMTreeItemModelBase("m_Myrror_UNK01");
        ptree->appendTree(ptreem_Myrror_UNK01, "");
    }
    for (unsigned i = 0; i < 0x60; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_UNK01[" << i << "]";
          ptreem_Myrror_UNK01->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Myrror_UNK01[i]));
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_LandMassID_Row = new QMoMTreeItemModelBase("m_Arcanus_LandMassID_Row");
        ptree->appendTree(ptreem_Arcanus_LandMassID_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_LandMassID_Row[" << i << "]";
          ptreem_Arcanus_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_LandMassID_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_LandMassID_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_LandMassID_Row = new QMoMTreeItemModelBase("m_Myrror_LandMassID_Row");
        ptree->appendTree(ptreem_Myrror_LandMassID_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_LandMassID_Row[" << i << "]";
          ptreem_Myrror_LandMassID_Row->appendTree(constructTreeItem(&rhs->m_Myrror_LandMassID_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Node_Attr = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Node_Attr = new QMoMTreeItemModelBase("m_Arcanus_Node_Attr");
        ptree->appendTree(ptreem_Arcanus_Node_Attr, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Node_Attr[" << i << "]";
          ptreem_Arcanus_Node_Attr->appendTree(constructTreeItem(&rhs->m_Arcanus_Node_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Node_Attr = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Node_Attr = new QMoMTreeItemModelBase("m_Myrror_Node_Attr");
        ptree->appendTree(ptreem_Myrror_Node_Attr, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Node_Attr[" << i << "]";
          ptreem_Myrror_Node_Attr->appendTree(constructTreeItem(&rhs->m_Myrror_Node_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Fortresses = ptree;
    if (gMAX_WIZARD_RECORDS > 3)
    {
        ptreem_Fortresses = new QMoMTreeItemModelBase("m_Fortresses");
        ptree->appendTree(ptreem_Fortresses, "");
    }
    for (unsigned i = 0; i < gMAX_WIZARD_RECORDS; ++i)
    {
          std::ostringstream oss;
          oss << "m_Fortresses[" << i << "]";
          ptreem_Fortresses->appendTree(constructTreeItem(&rhs->m_Fortresses[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Tower_Attr = ptree;
    if (6 > 3)
    {
        ptreem_Tower_Attr = new QMoMTreeItemModelBase("m_Tower_Attr");
        ptree->appendTree(ptreem_Tower_Attr, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Tower_Attr[" << i << "]";
          ptreem_Tower_Attr->appendTree(constructTreeItem(&rhs->m_Tower_Attr[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Arcanus_Towers = new QMoMTreeItemModelBase("m_Arcanus_Towers");
        ptree->appendTree(ptreem_Arcanus_Towers, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Towers[" << i << "]";
          ptreem_Arcanus_Towers->appendTree(constructTreeItem(&rhs->m_Arcanus_Towers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Towers = ptree;
    if (6 > 3)
    {
        ptreem_Myrror_Towers = new QMoMTreeItemModelBase("m_Myrror_Towers");
        ptree->appendTree(ptreem_Myrror_Towers, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Towers[" << i << "]";
          ptreem_Myrror_Towers->appendTree(constructTreeItem(&rhs->m_Myrror_Towers[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Nodes = ptree;
    if (16 > 3)
    {
        ptreem_Arcanus_Nodes = new QMoMTreeItemModelBase("m_Arcanus_Nodes");
        ptree->appendTree(ptreem_Arcanus_Nodes, "");
    }
    for (unsigned i = 0; i < 16; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Nodes[" << i << "]";
          ptreem_Arcanus_Nodes->appendTree(constructTreeItem(&rhs->m_Arcanus_Nodes[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Nodes = ptree;
    if (14 > 3)
    {
        ptreem_Myrror_Nodes = new QMoMTreeItemModelBase("m_Myrror_Nodes");
        ptree->appendTree(ptreem_Myrror_Nodes, "");
    }
    for (unsigned i = 0; i < 14; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Nodes[" << i << "]";
          ptreem_Myrror_Nodes->appendTree(constructTreeItem(&rhs->m_Myrror_Nodes[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Normal_Lairs = ptree;
    if (25 > 3)
    {
        ptreem_Normal_Lairs = new QMoMTreeItemModelBase("m_Normal_Lairs");
        ptree->appendTree(ptreem_Normal_Lairs, "");
    }
    for (unsigned i = 0; i < 25; ++i)
    {
          std::ostringstream oss;
          oss << "m_Normal_Lairs[" << i << "]";
          ptreem_Normal_Lairs->appendTree(constructTreeItem(&rhs->m_Normal_Lairs[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Weak_Lairs = ptree;
    if (32 > 3)
    {
        ptreem_Weak_Lairs = new QMoMTreeItemModelBase("m_Weak_Lairs");
        ptree->appendTree(ptreem_Weak_Lairs, "");
    }
    for (unsigned i = 0; i < 32; ++i)
    {
          std::ostringstream oss;
          oss << "m_Weak_Lairs[" << i << "]";
          ptreem_Weak_Lairs->appendTree(constructTreeItem(&rhs->m_Weak_Lairs[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_ExtraLairs_GUESS = ptree;
    if (3 > 3)
    {
        ptreem_ExtraLairs_GUESS = new QMoMTreeItemModelBase("m_ExtraLairs_GUESS");
        ptree->appendTree(ptreem_ExtraLairs_GUESS, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_ExtraLairs_GUESS[" << i << "]";
          ptreem_ExtraLairs_GUESS->appendTree(constructTreeItem(&rhs->m_ExtraLairs_GUESS[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Items = ptree;
    if (128 > 3)
    {
        ptreem_Items = new QMoMTreeItemModelBase("m_Items");
        ptree->appendTree(ptreem_Items, "");
    }
    for (unsigned i = 0; i < 128; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items[" << i << "]";
          ptreem_Items->appendTree(constructTreeItem(&rhs->m_Items[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Item_Trashcan_GUESS = ptree;
    if (8 > 3)
    {
        ptreem_Item_Trashcan_GUESS = new QMoMTreeItemModelBase("m_Item_Trashcan_GUESS");
        ptree->appendTree(ptreem_Item_Trashcan_GUESS, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Trashcan_GUESS[" << i << "]";
          ptreem_Item_Trashcan_GUESS->appendTree(constructTreeItem(&rhs->m_Item_Trashcan_GUESS[i], oss.str().c_str()), "");
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Item_Found, "m_Item_Found"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Item_Created, "m_Item_Created"), "");
    QMoMTreeItemModelBase* ptreem_Cities = ptree;
    if (gMAX_CITIES > 3)
    {
        ptreem_Cities = new QMoMTreeItemModelBase("m_Cities");
        ptree->appendTree(ptreem_Cities, "");
    }
    for (unsigned i = 0; i < gMAX_CITIES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Cities[" << i << "]";
          ptreem_Cities->appendTree(constructTreeItem(&rhs->m_Cities[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Unit = ptree;
    if (1000 > 3)
    {
        ptreem_Unit = new QMoMTreeItemModelBase("m_Unit");
        ptree->appendTree(ptreem_Unit, "");
    }
    for (unsigned i = 0; i < 1000; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unit[" << i << "]";
          ptreem_Unit->appendTree(constructTreeItem(&rhs->m_Unit[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Units_Trashcan_GUESS = ptree;
    if (9 > 3)
    {
        ptreem_Units_Trashcan_GUESS = new QMoMTreeItemModelBase("m_Units_Trashcan_GUESS");
        ptree->appendTree(ptreem_Units_Trashcan_GUESS, "");
    }
    for (unsigned i = 0; i < 9; ++i)
    {
          std::ostringstream oss;
          oss << "m_Units_Trashcan_GUESS[" << i << "]";
          ptreem_Units_Trashcan_GUESS->appendTree(constructTreeItem(&rhs->m_Units_Trashcan_GUESS[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Bonus_Row = new QMoMTreeItemModelBase("m_Arcanus_Bonus_Row");
        ptree->appendTree(ptreem_Arcanus_Bonus_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Bonus_Row[" << i << "]";
          ptreem_Arcanus_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Bonus_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Bonus_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Bonus_Row = new QMoMTreeItemModelBase("m_Myrror_Bonus_Row");
        ptree->appendTree(ptreem_Myrror_Bonus_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Bonus_Row[" << i << "]";
          ptreem_Myrror_Bonus_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Bonus_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Arcanus_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Exploration_Row = new QMoMTreeItemModelBase("m_Arcanus_Exploration_Row");
        ptree->appendTree(ptreem_Arcanus_Exploration_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Exploration_Row[" << i << "]";
          ptreem_Arcanus_Exploration_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Exploration_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Exploration_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Exploration_Row = new QMoMTreeItemModelBase("m_Myrror_Exploration_Row");
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
    QMoMTreeItemModelBase* ptreem_Arcanus_Terrain_Changes_Row = ptree;
    if (40 > 3)
    {
        ptreem_Arcanus_Terrain_Changes_Row = new QMoMTreeItemModelBase("m_Arcanus_Terrain_Changes_Row");
        ptree->appendTree(ptreem_Arcanus_Terrain_Changes_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Arcanus_Terrain_Changes_Row[" << i << "]";
          ptreem_Arcanus_Terrain_Changes_Row->appendTree(constructTreeItem(&rhs->m_Arcanus_Terrain_Changes_Row[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_Myrror_Terrain_Changes_Row = ptree;
    if (40 > 3)
    {
        ptreem_Myrror_Terrain_Changes_Row = new QMoMTreeItemModelBase("m_Myrror_Terrain_Changes_Row");
        ptree->appendTree(ptreem_Myrror_Terrain_Changes_Row, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_Myrror_Terrain_Changes_Row[" << i << "]";
          ptreem_Myrror_Terrain_Changes_Row->appendTree(constructTreeItem(&rhs->m_Myrror_Terrain_Changes_Row[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Grand_Vizier", new QMoMTreeItemModel<eGrand_Vizier>(&rhs->m_Grand_Vizier));
    QMoMTreeItemModelBase* ptreem_Artifacts_in_Game = ptree;
    if (gMAX_ARTIFACTS_IN_GAME > 3)
    {
        ptreem_Artifacts_in_Game = new QMoMTreeItemModelBase("m_Artifacts_in_Game");
        ptree->appendTree(ptreem_Artifacts_in_Game, "");
    }
    for (unsigned i = 0; i < gMAX_ARTIFACTS_IN_GAME; ++i)
    {
          std::ostringstream oss;
          oss << "m_Artifacts_in_Game[" << i << "]";
          ptreem_Artifacts_in_Game->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Artifacts_in_Game[i]));
    }
    QMoMTreeItemModelBase* ptreem_Chosen_Hero_Names = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreem_Chosen_Hero_Names = new QMoMTreeItemModelBase("m_Chosen_Hero_Names");
        ptree->appendTree(ptreem_Chosen_Hero_Names, "");
    }
    for (unsigned i = 0; i < gMAX_HERO_TYPES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Chosen_Hero_Names[" << i << "]";
          ptreem_Chosen_Hero_Names->appendTree(constructTreeItem(&rhs->m_Chosen_Hero_Names[i], oss.str().c_str()), "");
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Skills* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Skills>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Alchemy", new QMoMTreeItemModel<eYesNo8>(&rhs->Alchemy));
    ptree->appendChild("Warlord", new QMoMTreeItemModel<eYesNo8>(&rhs->Warlord));
    ptree->appendChild("Chaos_Master", new QMoMTreeItemModel<eYesNo8>(&rhs->Chaos_Master));
    ptree->appendChild("Nature_Master", new QMoMTreeItemModel<eYesNo8>(&rhs->Nature_Master));
    ptree->appendChild("Sorcery_Master", new QMoMTreeItemModel<eYesNo8>(&rhs->Sorcery_Master));
    ptree->appendChild("Infernal_Power", new QMoMTreeItemModel<eYesNo8>(&rhs->Infernal_Power));
    ptree->appendChild("Divine_Power", new QMoMTreeItemModel<eYesNo8>(&rhs->Divine_Power));
    ptree->appendChild("Sage_Master", new QMoMTreeItemModel<eYesNo8>(&rhs->Sage_Master));
    ptree->appendChild("Channeller", new QMoMTreeItemModel<eYesNo8>(&rhs->Channeller));
    ptree->appendChild("Myrran", new QMoMTreeItemModel<eYesNo8>(&rhs->Myrran));
    ptree->appendChild("Archmage", new QMoMTreeItemModel<eYesNo8>(&rhs->Archmage));
    ptree->appendChild("Mana_Focusing", new QMoMTreeItemModel<eYesNo8>(&rhs->Mana_Focusing));
    ptree->appendChild("Node_Mastery", new QMoMTreeItemModel<eYesNo8>(&rhs->Node_Mastery));
    ptree->appendChild("Famous", new QMoMTreeItemModel<eYesNo8>(&rhs->Famous));
    ptree->appendChild("Runemaster", new QMoMTreeItemModel<eYesNo8>(&rhs->Runemaster));
    ptree->appendChild("Conjurer", new QMoMTreeItemModel<eYesNo8>(&rhs->Conjurer));
    ptree->appendChild("Charismatic", new QMoMTreeItemModel<eYesNo8>(&rhs->Charismatic));
    ptree->appendChild("Artificer", new QMoMTreeItemModel<eYesNo8>(&rhs->Artificer));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Spell_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Spell_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_SpellName", new QMoMTreeItemModel<char[19]>(rhs->m_SpellName));
    ptree->appendChild("m_Spell_desirability", new QMoMTreeItemModel<int16_t>(&rhs->m_Spell_desirability));
    ptree->appendChild("m_Spell_Category", new QMoMTreeItemModel<eSpellCategory>(&rhs->m_Spell_Category));
    ptree->appendChild("m_Section_in_spell_book", new QMoMTreeItemModel<eSpell_Type>(&rhs->m_Section_in_spell_book));
    ptree->appendChild("m_Magic_Realm", new QMoMTreeItemModel<eRealm_Type>(&rhs->m_Magic_Realm));
    ptree->appendChild("m_Casting_eligibility", new QMoMTreeItemModel<int8_t>(&rhs->m_Casting_eligibility));
    ptree->appendChild("m_Unk_19", new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_19));
    ptree->appendChild("m_Casting_cost", new QMoMTreeItemModel<int16_t>(&rhs->m_Casting_cost));
    ptree->appendChild("m_Research_cost", new QMoMTreeItemModel<int16_t>(&rhs->m_Research_cost));
    ptree->appendChild("m_Sound_effect_when_casting_spell", new QMoMTreeItemModel<int16_t>(&rhs->m_Sound_effect_when_casting_spell));
    QMoMTreeItemModelBase* ptreem_Parameters = ptree;
    if (4 > 3)
    {
        ptreem_Parameters = new QMoMTreeItemModelBase("m_Parameters");
        ptree->appendTree(ptreem_Parameters, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Parameters[" << i << "]";
          ptreem_Parameters->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Parameters[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Spells_Cast_in_Battle* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Spells_Cast_in_Battle>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreeTrue_Light = ptree;
    if (2 > 3)
    {
        ptreeTrue_Light = new QMoMTreeItemModelBase("True_Light");
        ptree->appendTree(ptreeTrue_Light, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "True_Light[" << i << "]";
          ptreeTrue_Light->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->True_Light[i]));
    }
    QMoMTreeItemModelBase* ptreeDarkness = ptree;
    if (2 > 3)
    {
        ptreeDarkness = new QMoMTreeItemModelBase("Darkness");
        ptree->appendTree(ptreeDarkness, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Darkness[" << i << "]";
          ptreeDarkness->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Darkness[i]));
    }
    QMoMTreeItemModelBase* ptreeWarp_Reality = ptree;
    if (2 > 3)
    {
        ptreeWarp_Reality = new QMoMTreeItemModelBase("Warp_Reality");
        ptree->appendTree(ptreeWarp_Reality, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Warp_Reality[" << i << "]";
          ptreeWarp_Reality->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Warp_Reality[i]));
    }
    QMoMTreeItemModelBase* ptreeBlack_Prayer = ptree;
    if (2 > 3)
    {
        ptreeBlack_Prayer = new QMoMTreeItemModelBase("Black_Prayer");
        ptree->appendTree(ptreeBlack_Prayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Black_Prayer[" << i << "]";
          ptreeBlack_Prayer->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Black_Prayer[i]));
    }
    QMoMTreeItemModelBase* ptreeWrack = ptree;
    if (2 > 3)
    {
        ptreeWrack = new QMoMTreeItemModelBase("Wrack");
        ptree->appendTree(ptreeWrack, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Wrack[" << i << "]";
          ptreeWrack->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Wrack[i]));
    }
    QMoMTreeItemModelBase* ptreeMetal_Fires = ptree;
    if (2 > 3)
    {
        ptreeMetal_Fires = new QMoMTreeItemModelBase("Metal_Fires");
        ptree->appendTree(ptreeMetal_Fires, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Metal_Fires[" << i << "]";
          ptreeMetal_Fires->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Metal_Fires[i]));
    }
    QMoMTreeItemModelBase* ptreePrayer = ptree;
    if (2 > 3)
    {
        ptreePrayer = new QMoMTreeItemModelBase("Prayer");
        ptree->appendTree(ptreePrayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Prayer[" << i << "]";
          ptreePrayer->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Prayer[i]));
    }
    QMoMTreeItemModelBase* ptreeHigh_Prayer = ptree;
    if (2 > 3)
    {
        ptreeHigh_Prayer = new QMoMTreeItemModelBase("High_Prayer");
        ptree->appendTree(ptreeHigh_Prayer, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "High_Prayer[" << i << "]";
          ptreeHigh_Prayer->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->High_Prayer[i]));
    }
    QMoMTreeItemModelBase* ptreeTerror = ptree;
    if (2 > 3)
    {
        ptreeTerror = new QMoMTreeItemModelBase("Terror");
        ptree->appendTree(ptreeTerror, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Terror[" << i << "]";
          ptreeTerror->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Terror[i]));
    }
    QMoMTreeItemModelBase* ptreeCall_Lightning = ptree;
    if (2 > 3)
    {
        ptreeCall_Lightning = new QMoMTreeItemModelBase("Call_Lightning");
        ptree->appendTree(ptreeCall_Lightning, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Call_Lightning[" << i << "]";
          ptreeCall_Lightning->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Call_Lightning[i]));
    }
    QMoMTreeItemModelBase* ptreeCounter_Magic = ptree;
    if (2 > 3)
    {
        ptreeCounter_Magic = new QMoMTreeItemModelBase("Counter_Magic");
        ptree->appendTree(ptreeCounter_Magic, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Counter_Magic[" << i << "]";
          ptreeCounter_Magic->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Counter_Magic[i]));
    }
    QMoMTreeItemModelBase* ptreeMass_Invisibility = ptree;
    if (2 > 3)
    {
        ptreeMass_Invisibility = new QMoMTreeItemModelBase("Mass_Invisibility");
        ptree->appendTree(ptreeMass_Invisibility, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mass_Invisibility[" << i << "]";
          ptreeMass_Invisibility->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Mass_Invisibility[i]));
    }
    QMoMTreeItemModelBase* ptreeEntangle = ptree;
    if (2 > 3)
    {
        ptreeEntangle = new QMoMTreeItemModelBase("Entangle");
        ptree->appendTree(ptreeEntangle, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Entangle[" << i << "]";
          ptreeEntangle->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Entangle[i]));
    }
    QMoMTreeItemModelBase* ptreeMana_Leak = ptree;
    if (2 > 3)
    {
        ptreeMana_Leak = new QMoMTreeItemModelBase("Mana_Leak");
        ptree->appendTree(ptreeMana_Leak, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Mana_Leak[" << i << "]";
          ptreeMana_Leak->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Mana_Leak[i]));
    }
    QMoMTreeItemModelBase* ptreeBlur = ptree;
    if (2 > 3)
    {
        ptreeBlur = new QMoMTreeItemModelBase("Blur");
        ptree->appendTree(ptreeBlur, "");
    }
    for (unsigned i = 0; i < 2; ++i)
    {
          std::ostringstream oss;
          oss << "Blur[" << i << "]";
          ptreeBlur->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->Blur[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Spells_Known* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Spells_Known>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("No_spell", new QMoMTreeItemModel<eSpellKnown>(&rhs->No_spell));
    ptree->appendChild("Earth_to_Mud", new QMoMTreeItemModel<eSpellKnown>(&rhs->Earth_to_Mud));
    ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<eSpellKnown>(&rhs->Resist_Elements));
    ptree->appendChild("Wall_of_Stone", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wall_of_Stone));
    ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<eSpellKnown>(&rhs->Giant_Strength));
    ptree->appendChild("Web", new QMoMTreeItemModel<eSpellKnown>(&rhs->Web));
    ptree->appendChild("War_Bears", new QMoMTreeItemModel<eSpellKnown>(&rhs->War_Bears));
    ptree->appendChild("Stone_Skin", new QMoMTreeItemModel<eSpellKnown>(&rhs->Stone_Skin));
    ptree->appendChild("Water_Walking", new QMoMTreeItemModel<eSpellKnown>(&rhs->Water_Walking));
    ptree->appendChild("Sprites", new QMoMTreeItemModel<eSpellKnown>(&rhs->Sprites));
    ptree->appendChild("Earth_Lore", new QMoMTreeItemModel<eSpellKnown>(&rhs->Earth_Lore));
    ptree->appendChild("Cracks_Call", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cracks_Call));
    ptree->appendChild("Natures_eye", new QMoMTreeItemModel<eSpellKnown>(&rhs->Natures_eye));
    ptree->appendChild("Ice_Bolt", new QMoMTreeItemModel<eSpellKnown>(&rhs->Ice_Bolt));
    ptree->appendChild("Giant_Spiders", new QMoMTreeItemModel<eSpellKnown>(&rhs->Giant_Spiders));
    ptree->appendChild("Change_Terrain", new QMoMTreeItemModel<eSpellKnown>(&rhs->Change_Terrain));
    ptree->appendChild("Path_Finding", new QMoMTreeItemModel<eSpellKnown>(&rhs->Path_Finding));
    ptree->appendChild("Cockatrices", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cockatrices));
    ptree->appendChild("Transmute", new QMoMTreeItemModel<eSpellKnown>(&rhs->Transmute));
    ptree->appendChild("Natures_Cures", new QMoMTreeItemModel<eSpellKnown>(&rhs->Natures_Cures));
    ptree->appendChild("Basilisk", new QMoMTreeItemModel<eSpellKnown>(&rhs->Basilisk));
    ptree->appendChild("Elemental_Armor", new QMoMTreeItemModel<eSpellKnown>(&rhs->Elemental_Armor));
    ptree->appendChild("Petrify", new QMoMTreeItemModel<eSpellKnown>(&rhs->Petrify));
    ptree->appendChild("Stone_Giant", new QMoMTreeItemModel<eSpellKnown>(&rhs->Stone_Giant));
    ptree->appendChild("Iron_Skin", new QMoMTreeItemModel<eSpellKnown>(&rhs->Iron_Skin));
    ptree->appendChild("Ice_Storm", new QMoMTreeItemModel<eSpellKnown>(&rhs->Ice_Storm));
    ptree->appendChild("Earthquake", new QMoMTreeItemModel<eSpellKnown>(&rhs->Earthquake));
    ptree->appendChild("Gorgons", new QMoMTreeItemModel<eSpellKnown>(&rhs->Gorgons));
    ptree->appendChild("Move_Fortress", new QMoMTreeItemModel<eSpellKnown>(&rhs->Move_Fortress));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItemModel<eSpellKnown>(&rhs->Gaias_Blessing));
    ptree->appendChild("Earth_Elemental", new QMoMTreeItemModel<eSpellKnown>(&rhs->Earth_Elemental));
    ptree->appendChild("Regeneration", new QMoMTreeItemModel<eSpellKnown>(&rhs->Regeneration));
    ptree->appendChild("Behemoth", new QMoMTreeItemModel<eSpellKnown>(&rhs->Behemoth));
    ptree->appendChild("Entangle", new QMoMTreeItemModel<eSpellKnown>(&rhs->Entangle));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Nature_Awareness));
    ptree->appendChild("Call_Lightning", new QMoMTreeItemModel<eSpellKnown>(&rhs->Call_Lightning));
    ptree->appendChild("Colossus", new QMoMTreeItemModel<eSpellKnown>(&rhs->Colossus));
    ptree->appendChild("Earth_Gate", new QMoMTreeItemModel<eSpellKnown>(&rhs->Earth_Gate));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItemModel<eSpellKnown>(&rhs->Herb_Mastery));
    ptree->appendChild("Great_Wyrm", new QMoMTreeItemModel<eSpellKnown>(&rhs->Great_Wyrm));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItemModel<eSpellKnown>(&rhs->Natures_Wrath));
    ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<eSpellKnown>(&rhs->Resist_Magic));
    ptree->appendChild("Dispel_Magic_True", new QMoMTreeItemModel<eSpellKnown>(&rhs->Dispel_Magic_True));
    ptree->appendChild("Floating_Island", new QMoMTreeItemModel<eSpellKnown>(&rhs->Floating_Island));
    ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<eSpellKnown>(&rhs->Guardian_Wind));
    ptree->appendChild("Phantom_Warriors", new QMoMTreeItemModel<eSpellKnown>(&rhs->Phantom_Warriors));
    ptree->appendChild("Confusion", new QMoMTreeItemModel<eSpellKnown>(&rhs->Confusion));
    ptree->appendChild("Word_of_Recall", new QMoMTreeItemModel<eSpellKnown>(&rhs->Word_of_Recall));
    ptree->appendChild("Counter_Magic", new QMoMTreeItemModel<eSpellKnown>(&rhs->Counter_Magic));
    ptree->appendChild("Nagas", new QMoMTreeItemModel<eSpellKnown>(&rhs->Nagas));
    ptree->appendChild("Psionic_Blast", new QMoMTreeItemModel<eSpellKnown>(&rhs->Psionic_Blast));
    ptree->appendChild("Blur", new QMoMTreeItemModel<eSpellKnown>(&rhs->Blur));
    ptree->appendChild("Disenchant_True", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disenchant_True));
    ptree->appendChild("Vertigo", new QMoMTreeItemModel<eSpellKnown>(&rhs->Vertigo));
    ptree->appendChild("Spell_Lock", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Lock));
    ptree->appendChild("Enchant_Road", new QMoMTreeItemModel<eSpellKnown>(&rhs->Enchant_Road));
    ptree->appendChild("Flight", new QMoMTreeItemModel<eSpellKnown>(&rhs->Flight));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wind_Mastery));
    ptree->appendChild("Spell_Blast", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Blast));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItemModel<eSpellKnown>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Phantom_Beast", new QMoMTreeItemModel<eSpellKnown>(&rhs->Phantom_Beast));
    ptree->appendChild("Disjunction_True", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disjunction_True));
    ptree->appendChild("Invisibility", new QMoMTreeItemModel<eSpellKnown>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wind_Walking));
    ptree->appendChild("Banish", new QMoMTreeItemModel<eSpellKnown>(&rhs->Banish));
    ptree->appendChild("Storm_Giant", new QMoMTreeItemModel<eSpellKnown>(&rhs->Storm_Giant));
    ptree->appendChild("Air_Elemental", new QMoMTreeItemModel<eSpellKnown>(&rhs->Air_Elemental));
    ptree->appendChild("Mind_Storm", new QMoMTreeItemModel<eSpellKnown>(&rhs->Mind_Storm));
    ptree->appendChild("Stasis", new QMoMTreeItemModel<eSpellKnown>(&rhs->Stasis));
    ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<eSpellKnown>(&rhs->Magic_Immunity));
    ptree->appendChild("Haste", new QMoMTreeItemModel<eSpellKnown>(&rhs->Haste));
    ptree->appendChild("Djinn", new QMoMTreeItemModel<eSpellKnown>(&rhs->Djinn));
    ptree->appendChild("Spell_Ward", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Ward));
    ptree->appendChild("Creature_Binding", new QMoMTreeItemModel<eSpellKnown>(&rhs->Creature_Binding));
    ptree->appendChild("Mass_Invisibility", new QMoMTreeItemModel<eSpellKnown>(&rhs->Mass_Invisibility));
    ptree->appendChild("Great_Unsummoning", new QMoMTreeItemModel<eSpellKnown>(&rhs->Great_Unsummoning));
    ptree->appendChild("Spell_Binding", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Binding));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItemModel<eSpellKnown>(&rhs->Flying_Fortress));
    ptree->appendChild("Sky_Drake", new QMoMTreeItemModel<eSpellKnown>(&rhs->Sky_Drake));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItemModel<eSpellKnown>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItemModel<eSpellKnown>(&rhs->Time_Stop));
    ptree->appendChild("Warp_Wood", new QMoMTreeItemModel<eSpellKnown>(&rhs->Warp_Wood));
    ptree->appendChild("Disrupt", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disrupt));
    ptree->appendChild("Fire_Bolt", new QMoMTreeItemModel<eSpellKnown>(&rhs->Fire_Bolt));
    ptree->appendChild("Hell_Hounds", new QMoMTreeItemModel<eSpellKnown>(&rhs->Hell_Hounds));
    ptree->appendChild("Corruption", new QMoMTreeItemModel<eSpellKnown>(&rhs->Corruption));
    ptree->appendChild("Eldritch_Weapon", new QMoMTreeItemModel<eSpellKnown>(&rhs->Eldritch_Weapon));
    ptree->appendChild("Wall_of_Fire", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wall_of_Fire));
    ptree->appendChild("Shatter", new QMoMTreeItemModel<eSpellKnown>(&rhs->Shatter));
    ptree->appendChild("Warp_Creature", new QMoMTreeItemModel<eSpellKnown>(&rhs->Warp_Creature));
    ptree->appendChild("Fire_Elemental", new QMoMTreeItemModel<eSpellKnown>(&rhs->Fire_Elemental));
    ptree->appendChild("Lightning_Bolt", new QMoMTreeItemModel<eSpellKnown>(&rhs->Lightning_Bolt));
    ptree->appendChild("Fire_Giant", new QMoMTreeItemModel<eSpellKnown>(&rhs->Fire_Giant));
    ptree->appendChild("Chaos_Channels", new QMoMTreeItemModel<eSpellKnown>(&rhs->Chaos_Channels));
    ptree->appendChild("Flame_Blade", new QMoMTreeItemModel<eSpellKnown>(&rhs->Flame_Blade));
    ptree->appendChild("Gargoyles", new QMoMTreeItemModel<eSpellKnown>(&rhs->Gargoyles));
    ptree->appendChild("Fireball", new QMoMTreeItemModel<eSpellKnown>(&rhs->Fireball));
    ptree->appendChild("Doombat", new QMoMTreeItemModel<eSpellKnown>(&rhs->Doombat));
    ptree->appendChild("Raise_Volcano", new QMoMTreeItemModel<eSpellKnown>(&rhs->Raise_Volcano));
    ptree->appendChild("Immolation", new QMoMTreeItemModel<eSpellKnown>(&rhs->Immolation));
    ptree->appendChild("Chimeras", new QMoMTreeItemModel<eSpellKnown>(&rhs->Chimeras));
    ptree->appendChild("Warp_Lightning", new QMoMTreeItemModel<eSpellKnown>(&rhs->Warp_Lightning));
    ptree->appendChild("Metal_Fires", new QMoMTreeItemModel<eSpellKnown>(&rhs->Metal_Fires));
    ptree->appendChild("Chaos_Spawn", new QMoMTreeItemModel<eSpellKnown>(&rhs->Chaos_Spawn));
    ptree->appendChild("Doom_Bolt", new QMoMTreeItemModel<eSpellKnown>(&rhs->Doom_Bolt));
    ptree->appendChild("Magic_Vortex", new QMoMTreeItemModel<eSpellKnown>(&rhs->Magic_Vortex));
    ptree->appendChild("Efreet", new QMoMTreeItemModel<eSpellKnown>(&rhs->Efreet));
    ptree->appendChild("Fire_Storm", new QMoMTreeItemModel<eSpellKnown>(&rhs->Fire_Storm));
    ptree->appendChild("Warp_Reality", new QMoMTreeItemModel<eSpellKnown>(&rhs->Warp_Reality));
    ptree->appendChild("Flame_Strike", new QMoMTreeItemModel<eSpellKnown>(&rhs->Flame_Strike));
    ptree->appendChild("Chaos_Rift", new QMoMTreeItemModel<eSpellKnown>(&rhs->Chaos_Rift));
    ptree->appendChild("Hydra", new QMoMTreeItemModel<eSpellKnown>(&rhs->Hydra));
    ptree->appendChild("Disintegrate", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disintegrate));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItemModel<eSpellKnown>(&rhs->Meteor_Storm));
    ptree->appendChild("Great_Wasting", new QMoMTreeItemModel<eSpellKnown>(&rhs->Great_Wasting));
    ptree->appendChild("Call_Chaos", new QMoMTreeItemModel<eSpellKnown>(&rhs->Call_Chaos));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItemModel<eSpellKnown>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItemModel<eSpellKnown>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Drake", new QMoMTreeItemModel<eSpellKnown>(&rhs->Great_Drake));
    ptree->appendChild("Call_The_Void", new QMoMTreeItemModel<eSpellKnown>(&rhs->Call_The_Void));
    ptree->appendChild("Armageddon", new QMoMTreeItemModel<eSpellKnown>(&rhs->Armageddon));
    ptree->appendChild("Bless", new QMoMTreeItemModel<eSpellKnown>(&rhs->Bless));
    ptree->appendChild("Star_Fires", new QMoMTreeItemModel<eSpellKnown>(&rhs->Star_Fires));
    ptree->appendChild("Endurance", new QMoMTreeItemModel<eSpellKnown>(&rhs->Endurance));
    ptree->appendChild("Holy_Weapon", new QMoMTreeItemModel<eSpellKnown>(&rhs->Holy_Weapon));
    ptree->appendChild("Healing", new QMoMTreeItemModel<eSpellKnown>(&rhs->Healing));
    ptree->appendChild("Holy_Armor", new QMoMTreeItemModel<eSpellKnown>(&rhs->Holy_Armor));
    ptree->appendChild("Just_Cause", new QMoMTreeItemModel<eSpellKnown>(&rhs->Just_Cause));
    ptree->appendChild("True_Light", new QMoMTreeItemModel<eSpellKnown>(&rhs->True_Light));
    ptree->appendChild("Guardian_Spirit", new QMoMTreeItemModel<eSpellKnown>(&rhs->Guardian_Spirit));
    ptree->appendChild("Heroism", new QMoMTreeItemModel<eSpellKnown>(&rhs->Heroism));
    ptree->appendChild("True_Sight", new QMoMTreeItemModel<eSpellKnown>(&rhs->True_Sight));
    ptree->appendChild("Plane_Shift", new QMoMTreeItemModel<eSpellKnown>(&rhs->Plane_Shift));
    ptree->appendChild("Resurrection", new QMoMTreeItemModel<eSpellKnown>(&rhs->Resurrection));
    ptree->appendChild("Dispel_Evil", new QMoMTreeItemModel<eSpellKnown>(&rhs->Dispel_Evil));
    ptree->appendChild("Planar_Seal", new QMoMTreeItemModel<eSpellKnown>(&rhs->Planar_Seal));
    ptree->appendChild("Unicorns", new QMoMTreeItemModel<eSpellKnown>(&rhs->Unicorns));
    ptree->appendChild("Raise_Dead", new QMoMTreeItemModel<eSpellKnown>(&rhs->Raise_Dead));
    ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<eSpellKnown>(&rhs->Planar_Travel));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItemModel<eSpellKnown>(&rhs->Heavenly_Light));
    ptree->appendChild("Prayer", new QMoMTreeItemModel<eSpellKnown>(&rhs->Prayer));
    ptree->appendChild("Lionheart", new QMoMTreeItemModel<eSpellKnown>(&rhs->Lionheart));
    ptree->appendChild("Incarnation", new QMoMTreeItemModel<eSpellKnown>(&rhs->Incarnation));
    ptree->appendChild("Invulnerability", new QMoMTreeItemModel<eSpellKnown>(&rhs->Invulnerability));
    ptree->appendChild("Righteousness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Righteousness));
    ptree->appendChild("Prosperity", new QMoMTreeItemModel<eSpellKnown>(&rhs->Prosperity));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItemModel<eSpellKnown>(&rhs->Altar_of_Battle));
    ptree->appendChild("Angel", new QMoMTreeItemModel<eSpellKnown>(&rhs->Angel));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItemModel<eSpellKnown>(&rhs->Stream_of_Life));
    ptree->appendChild("Mass_Healing", new QMoMTreeItemModel<eSpellKnown>(&rhs->Mass_Healing));
    ptree->appendChild("Holy_Word", new QMoMTreeItemModel<eSpellKnown>(&rhs->Holy_Word));
    ptree->appendChild("High_Prayer", new QMoMTreeItemModel<eSpellKnown>(&rhs->High_Prayer));
    ptree->appendChild("Inspirations", new QMoMTreeItemModel<eSpellKnown>(&rhs->Inspirations));
    ptree->appendChild("Astral_Gate", new QMoMTreeItemModel<eSpellKnown>(&rhs->Astral_Gate));
    ptree->appendChild("Holy_Arms", new QMoMTreeItemModel<eSpellKnown>(&rhs->Holy_Arms));
    ptree->appendChild("Consecration", new QMoMTreeItemModel<eSpellKnown>(&rhs->Consecration));
    ptree->appendChild("Life_Force", new QMoMTreeItemModel<eSpellKnown>(&rhs->Life_Force));
    ptree->appendChild("Tranquility", new QMoMTreeItemModel<eSpellKnown>(&rhs->Tranquility));
    ptree->appendChild("Crusade", new QMoMTreeItemModel<eSpellKnown>(&rhs->Crusade));
    ptree->appendChild("Arch_Angel", new QMoMTreeItemModel<eSpellKnown>(&rhs->Arch_Angel));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItemModel<eSpellKnown>(&rhs->Charm_of_Life));
    ptree->appendChild("Skeletons", new QMoMTreeItemModel<eSpellKnown>(&rhs->Skeletons));
    ptree->appendChild("Weakness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Weakness));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItemModel<eSpellKnown>(&rhs->Dark_Rituals));
    ptree->appendChild("Cloak_of_Fear", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Sleep", new QMoMTreeItemModel<eSpellKnown>(&rhs->Black_Sleep));
    ptree->appendChild("Ghouls", new QMoMTreeItemModel<eSpellKnown>(&rhs->Ghouls));
    ptree->appendChild("Life_Drain", new QMoMTreeItemModel<eSpellKnown>(&rhs->Life_Drain));
    ptree->appendChild("Terror", new QMoMTreeItemModel<eSpellKnown>(&rhs->Terror));
    ptree->appendChild("Darkness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Darkness));
    ptree->appendChild("Mana_Leak", new QMoMTreeItemModel<eSpellKnown>(&rhs->Mana_Leak));
    ptree->appendChild("Drain_Power", new QMoMTreeItemModel<eSpellKnown>(&rhs->Drain_Power));
    ptree->appendChild("Possession", new QMoMTreeItemModel<eSpellKnown>(&rhs->Possession));
    ptree->appendChild("Lycantrophy", new QMoMTreeItemModel<eSpellKnown>(&rhs->Lycantrophy));
    ptree->appendChild("Black_Prayer", new QMoMTreeItemModel<eSpellKnown>(&rhs->Black_Prayer));
    ptree->appendChild("Black_Channels", new QMoMTreeItemModel<eSpellKnown>(&rhs->Black_Channels));
    ptree->appendChild("Night_Stalker", new QMoMTreeItemModel<eSpellKnown>(&rhs->Night_Stalker));
    ptree->appendChild("Subversion", new QMoMTreeItemModel<eSpellKnown>(&rhs->Subversion));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Berserk", new QMoMTreeItemModel<eSpellKnown>(&rhs->Berserk));
    ptree->appendChild("Shadow_Demons", new QMoMTreeItemModel<eSpellKnown>(&rhs->Shadow_Demons));
    ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wraith_Form));
    ptree->appendChild("Wrack", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wrack));
    ptree->appendChild("Evil_Presence", new QMoMTreeItemModel<eSpellKnown>(&rhs->Evil_Presence));
    ptree->appendChild("Wraiths", new QMoMTreeItemModel<eSpellKnown>(&rhs->Wraiths));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Warp_Node", new QMoMTreeItemModel<eSpellKnown>(&rhs->Warp_Node));
    ptree->appendChild("Black_Wind", new QMoMTreeItemModel<eSpellKnown>(&rhs->Black_Wind));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItemModel<eSpellKnown>(&rhs->Zombie_Mastery));
    ptree->appendChild("Famine", new QMoMTreeItemModel<eSpellKnown>(&rhs->Famine));
    ptree->appendChild("Cursed_Lands", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cursed_Lands));
    ptree->appendChild("Cruel_Unminding", new QMoMTreeItemModel<eSpellKnown>(&rhs->Cruel_Unminding));
    ptree->appendChild("Word_of_Death", new QMoMTreeItemModel<eSpellKnown>(&rhs->Word_of_Death));
    ptree->appendChild("Death_Knights", new QMoMTreeItemModel<eSpellKnown>(&rhs->Death_Knights));
    ptree->appendChild("Death_Spell", new QMoMTreeItemModel<eSpellKnown>(&rhs->Death_Spell));
    ptree->appendChild("Animate_dead", new QMoMTreeItemModel<eSpellKnown>(&rhs->Animate_dead));
    ptree->appendChild("Pestilence", new QMoMTreeItemModel<eSpellKnown>(&rhs->Pestilence));
    ptree->appendChild("Eternal_Night", new QMoMTreeItemModel<eSpellKnown>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItemModel<eSpellKnown>(&rhs->Evil_Omens));
    ptree->appendChild("Death_Wish", new QMoMTreeItemModel<eSpellKnown>(&rhs->Death_Wish));
    ptree->appendChild("Demon_Lord", new QMoMTreeItemModel<eSpellKnown>(&rhs->Demon_Lord));
    ptree->appendChild("Magic_Spirit", new QMoMTreeItemModel<eSpellKnown>(&rhs->Magic_Spirit));
    ptree->appendChild("Dispel_Magic", new QMoMTreeItemModel<eSpellKnown>(&rhs->Dispel_Magic));
    ptree->appendChild("Summoning_Circle", new QMoMTreeItemModel<eSpellKnown>(&rhs->Summoning_Circle));
    ptree->appendChild("Disenchant_Area", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disenchant_Area));
    ptree->appendChild("Recall_Hero", new QMoMTreeItemModel<eSpellKnown>(&rhs->Recall_Hero));
    ptree->appendChild("Detect_Magic", new QMoMTreeItemModel<eSpellKnown>(&rhs->Detect_Magic));
    ptree->appendChild("Enchant_Item", new QMoMTreeItemModel<eSpellKnown>(&rhs->Enchant_Item));
    ptree->appendChild("Summon_Hero", new QMoMTreeItemModel<eSpellKnown>(&rhs->Summon_Hero));
    ptree->appendChild("Awareness", new QMoMTreeItemModel<eSpellKnown>(&rhs->Awareness));
    ptree->appendChild("Disjunction", new QMoMTreeItemModel<eSpellKnown>(&rhs->Disjunction));
    ptree->appendChild("Create_Artifact", new QMoMTreeItemModel<eSpellKnown>(&rhs->Create_Artifact));
    ptree->appendChild("Summon_Champion", new QMoMTreeItemModel<eSpellKnown>(&rhs->Summon_Champion));
    ptree->appendChild("Spell_Of_Mastery", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Of_Mastery));
    ptree->appendChild("Spell_Of_Return", new QMoMTreeItemModel<eSpellKnown>(&rhs->Spell_Of_Return));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Terrain_Changes* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Terrain_Changes>(rhs, context);
    if (0 == rhs)
        return ptree;

    Terrain_Changes maskVolcano_producing_for_Owner;
    memset(&maskVolcano_producing_for_Owner, '\0', sizeof(maskVolcano_producing_for_Owner));
    maskVolcano_producing_for_Owner.Volcano_producing_for_Owner = 7;
    if (1 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskVolcano_producing_for_Owner));
    else if (2 == sizeof(maskVolcano_producing_for_Owner))
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskVolcano_producing_for_Owner));
    else
        ptree->appendChild("Volcano_producing_for_Owner", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskVolcano_producing_for_Owner));
    Terrain_Changes maskroad;
    memset(&maskroad, '\0', sizeof(maskroad));
    maskroad.road = 1;
    if (1 == sizeof(maskroad))
        ptree->appendChild("road", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskroad));
    else if (2 == sizeof(maskroad))
        ptree->appendChild("road", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskroad));
    else
        ptree->appendChild("road", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskroad));
    Terrain_Changes maskenchanted_road;
    memset(&maskenchanted_road, '\0', sizeof(maskenchanted_road));
    maskenchanted_road.enchanted_road = 1;
    if (1 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskenchanted_road));
    else if (2 == sizeof(maskenchanted_road))
        ptree->appendChild("enchanted_road", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskenchanted_road));
    else
        ptree->appendChild("enchanted_road", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskenchanted_road));
    Terrain_Changes maskcorruption;
    memset(&maskcorruption, '\0', sizeof(maskcorruption));
    maskcorruption.corruption = 1;
    if (1 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskcorruption));
    else if (2 == sizeof(maskcorruption))
        ptree->appendChild("corruption", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskcorruption));
    else
        ptree->appendChild("corruption", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskcorruption));
    Terrain_Changes maskunknown40;
    memset(&maskunknown40, '\0', sizeof(maskunknown40));
    maskunknown40.unknown40 = 1;
    if (1 == sizeof(maskunknown40))
        ptree->appendChild("unknown40", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskunknown40));
    else if (2 == sizeof(maskunknown40))
        ptree->appendChild("unknown40", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskunknown40));
    else
        ptree->appendChild("unknown40", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskunknown40));
    Terrain_Changes maskno_road80;
    memset(&maskno_road80, '\0', sizeof(maskno_road80));
    maskno_road80.no_road80 = 1;
    if (1 == sizeof(maskno_road80))
        ptree->appendChild("no_road80", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskno_road80));
    else if (2 == sizeof(maskno_road80))
        ptree->appendChild("no_road80", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskno_road80));
    else
        ptree->appendChild("no_road80", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskno_road80));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Tower_Attr* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Tower_Attr>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Closed", new QMoMTreeItemModel<uint8_t>(&rhs->m_Closed));
    ptree->appendChild("m_Unk_03", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_03));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Tower_Node_Lair* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Tower_Node_Lair>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItemModel<uint8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<uint8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Status", new QMoMTreeItemModel<eTower_Node_Lair_Status>(&rhs->m_Status));
    ptree->appendChild("m_Type", new QMoMTreeItemModel<eTower_Node_Lair_Type>(&rhs->m_Type));
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant1, "m_Inhabitant1"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Inhabitant2, "m_Inhabitant2"), "");
    ptree->appendChild("m_Unk_09", new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_09));
    ptree->appendChild("m_Reward_Gold", new QMoMTreeItemModel<uint16_t>(&rhs->m_Reward_Gold));
    ptree->appendChild("m_Reward_Mana", new QMoMTreeItemModel<uint16_t>(&rhs->m_Reward_Mana));
    ptree->appendChild("m_Reward_Specials", new QMoMTreeItemModel<eReward_Specials>(&rhs->m_Reward_Specials));
    ptree->appendTree(constructTreeItem(&rhs->m_Flags, "m_Flags"), "");
    ptree->appendChild("m_Item_Rewards", new QMoMTreeItemModel<uint16_t>(&rhs->m_Item_Rewards));
    QMoMTreeItemModelBase* ptreem_Item_Value = ptree;
    if (3 > 3)
    {
        ptreem_Item_Value = new QMoMTreeItemModelBase("m_Item_Value");
        ptree->appendTree(ptreem_Item_Value, "");
    }
    for (unsigned i = 0; i < 3; ++i)
    {
          std::ostringstream oss;
          oss << "m_Item_Value[" << i << "]";
          ptreem_Item_Value->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_Item_Value[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Tower_Node_Lair_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Tower_Node_Lair_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    Tower_Node_Lair_Flags maskm_Prisoner;
    memset(&maskm_Prisoner, '\0', sizeof(maskm_Prisoner));
    maskm_Prisoner.m_Prisoner = 1;
    if (1 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Prisoner));
    else if (2 == sizeof(maskm_Prisoner))
        ptree->appendChild("m_Prisoner", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Prisoner));
    else
        ptree->appendChild("m_Prisoner", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Prisoner));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant1;
    memset(&maskm_YOU_aware_Inhabitant1, '\0', sizeof(maskm_YOU_aware_Inhabitant1));
    maskm_YOU_aware_Inhabitant1.m_YOU_aware_Inhabitant1 = 1;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant1));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant1))
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant1));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant1", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant1));
    Tower_Node_Lair_Flags maskm_YOU_aware_Inhabitant2;
    memset(&maskm_YOU_aware_Inhabitant2, '\0', sizeof(maskm_YOU_aware_Inhabitant2));
    maskm_YOU_aware_Inhabitant2.m_YOU_aware_Inhabitant2 = 1;
    if (1 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_YOU_aware_Inhabitant2));
    else if (2 == sizeof(maskm_YOU_aware_Inhabitant2))
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_YOU_aware_Inhabitant2));
    else
        ptree->appendChild("m_YOU_aware_Inhabitant2", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_YOU_aware_Inhabitant2));
    Tower_Node_Lair_Flags maskm_Zero;
    memset(&maskm_Zero, '\0', sizeof(maskm_Zero));
    maskm_Zero.m_Zero = 31;
    if (1 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskm_Zero));
    else if (2 == sizeof(maskm_Zero))
        ptree->appendChild("m_Zero", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskm_Zero));
    else
        ptree->appendChild("m_Zero", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskm_Zero));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Unit* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Unit>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_XPos", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos));
    ptree->appendChild("m_YPos", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos));
    ptree->appendChild("m_Plane", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane));
    ptree->appendChild("m_Owner", new QMoMTreeItemModel<ePlayer>(&rhs->m_Owner));
    ptree->appendChild("m_Moves_Total", new QMoMTreeItemModel<int8_t>(&rhs->m_Moves_Total));
    ptree->appendChild("m_Unit_Type", new QMoMTreeItemModel<eUnit_Type>(&rhs->m_Unit_Type));
    ptree->appendChild("m_Hero_Slot_Number", new QMoMTreeItemModel<int8_t>(&rhs->m_Hero_Slot_Number));
    ptree->appendChild("m_Active", new QMoMTreeItemModel<eUnit_Active>(&rhs->m_Active));
    ptree->appendChild("m_Moves_Left", new QMoMTreeItemModel<int8_t>(&rhs->m_Moves_Left));
    ptree->appendChild("m_XPos_of_destination", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos_of_destination));
    ptree->appendChild("m_YPos_of_destination", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos_of_destination));
    ptree->appendChild("m_Status", new QMoMTreeItemModel<eUnit_Status8>(&rhs->m_Status));
    ptree->appendChild("m_Level", new QMoMTreeItemModel<eLevel>(&rhs->m_Level));
    ptree->appendChild("m_Unk_0D", new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_0D));
    ptree->appendChild("m_Experience", new QMoMTreeItemModel<int16_t>(&rhs->m_Experience));
    ptree->appendChild("m_Unk_10", new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_10));
    ptree->appendChild("m_Damage", new QMoMTreeItemModel<int8_t>(&rhs->m_Damage));
    ptree->appendChild("m_Grouping", new QMoMTreeItemModel<int8_t>(&rhs->m_Grouping));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag1", new QMoMTreeItemModel<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag1));
    ptree->appendChild("m_In_Tower_without_Seal", new QMoMTreeItemModel<int8_t>(&rhs->m_In_Tower_without_Seal));
    ptree->appendChild("m_Guess_Combat_Enchantment_Flag3", new QMoMTreeItemModel<int8_t>(&rhs->m_Guess_Combat_Enchantment_Flag3));
    ptree->appendChild("m_Scouting", new QMoMTreeItemModel<int8_t>(&rhs->m_Scouting));
    ptree->appendTree(constructTreeItem(&rhs->m_Weapon_Mutation, "m_Weapon_Mutation"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Unit_Enchantment, "m_Unit_Enchantment"), "");
    ptree->appendChild("m_Road_Building_left_to_complete", new QMoMTreeItemModel<int8_t>(&rhs->m_Road_Building_left_to_complete));
    ptree->appendChild("m_XPos_Road_Building_from", new QMoMTreeItemModel<int8_t>(&rhs->m_XPos_Road_Building_from));
    ptree->appendChild("m_YPos_Road_Building_from", new QMoMTreeItemModel<int8_t>(&rhs->m_YPos_Road_Building_from));
    ptree->appendChild("m_Unk_1F", new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_1F));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_HeroAbility* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_HeroAbility>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_bitmask", new QMoMTreeItemModel<uint32_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_ItemText* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_ItemText>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_offset_helpText", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_helpText));
    ptree->appendChild("m_bitmask", new QMoMTreeItemModel<uint32_t>(&rhs->m_bitmask));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_Line* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_Line>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Line", new QMoMTreeItemModel<char[30]>(rhs->m_Line));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_Lines* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_Lines>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_lines = ptree;
    if (40 > 3)
    {
        ptreem_lines = new QMoMTreeItemModelBase("m_lines");
        ptree->appendTree(ptreem_lines, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_lines[" << i << "]";
          ptreem_lines->appendTree(constructTreeItem(&rhs->m_lines[i], oss.str().c_str()), "");
    }
    QMoMTreeItemModelBase* ptreem_bitmask_unitenchantment = ptree;
    if (40 > 3)
    {
        ptreem_bitmask_unitenchantment = new QMoMTreeItemModelBase("m_bitmask_unitenchantment");
        ptree->appendTree(ptreem_bitmask_unitenchantment, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_bitmask_unitenchantment[" << i << "]";
          ptreem_bitmask_unitenchantment->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint32_t>(&rhs->m_bitmask_unitenchantment[i]));
    }
    QMoMTreeItemModelBase* ptreem_icon_pic = ptree;
    if (40 > 3)
    {
        ptreem_icon_pic = new QMoMTreeItemModelBase("m_icon_pic");
        ptree->appendTree(ptreem_icon_pic, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_icon_pic[" << i << "]";
          ptreem_icon_pic->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_icon_pic[i]));
    }
    QMoMTreeItemModelBase* ptreem_helpIndex = ptree;
    if (40 > 3)
    {
        ptreem_helpIndex = new QMoMTreeItemModelBase("m_helpIndex");
        ptree->appendTree(ptreem_helpIndex, "");
    }
    for (unsigned i = 0; i < 40; ++i)
    {
          std::ostringstream oss;
          oss << "m_helpIndex[" << i << "]";
          ptreem_helpIndex->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint16_t>(&rhs->m_helpIndex[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_Mutation* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItemModel<uint8_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItemModel<int8_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_Ranged* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_Ranged>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_rangedType", new QMoMTreeItemModel<eRanged_Type>(&rhs->m_rangedType));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItemModel<int8_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_SpellData* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_SpellData>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItemModel<uint32_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(UnitView_UnitData* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<UnitView_UnitData>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_offset_label", new QMoMTreeItemModel<uint16_t>(&rhs->m_offset_label));
    ptree->appendChild("m_bitmask", new QMoMTreeItemModel<uint16_t>(&rhs->m_bitmask));
    ptree->appendChild("m_lbxIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_lbxIndex));
    ptree->appendChild("m_helpIndex", new QMoMTreeItemModel<int16_t>(&rhs->m_helpIndex));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Unit_Data_Hero_Types* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Unit_Data_Hero_Types>(rhs, context);
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

QMoMTreeItemModelBase* constructTreeItem(Unit_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Unit_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    Unit_Enchantment maskImmolation;
    memset(&maskImmolation, '\0', sizeof(maskImmolation));
    maskImmolation.Immolation = 1;
    if (1 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskImmolation));
    else if (2 == sizeof(maskImmolation))
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskImmolation));
    else
        ptree->appendChild("Immolation", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskImmolation));
    Unit_Enchantment maskGuardian_Wind;
    memset(&maskGuardian_Wind, '\0', sizeof(maskGuardian_Wind));
    maskGuardian_Wind.Guardian_Wind = 1;
    if (1 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGuardian_Wind));
    else if (2 == sizeof(maskGuardian_Wind))
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGuardian_Wind));
    else
        ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGuardian_Wind));
    Unit_Enchantment maskBerserk;
    memset(&maskBerserk, '\0', sizeof(maskBerserk));
    maskBerserk.Berserk = 1;
    if (1 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBerserk));
    else if (2 == sizeof(maskBerserk))
        ptree->appendChild("Berserk", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBerserk));
    else
        ptree->appendChild("Berserk", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBerserk));
    Unit_Enchantment maskCloak_of_Fear;
    memset(&maskCloak_of_Fear, '\0', sizeof(maskCloak_of_Fear));
    maskCloak_of_Fear.Cloak_of_Fear = 1;
    if (1 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskCloak_of_Fear));
    else if (2 == sizeof(maskCloak_of_Fear))
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskCloak_of_Fear));
    else
        ptree->appendChild("Cloak_of_Fear", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskCloak_of_Fear));
    Unit_Enchantment maskBlack_Channels;
    memset(&maskBlack_Channels, '\0', sizeof(maskBlack_Channels));
    maskBlack_Channels.Black_Channels = 1;
    if (1 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBlack_Channels));
    else if (2 == sizeof(maskBlack_Channels))
        ptree->appendChild("Black_Channels", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBlack_Channels));
    else
        ptree->appendChild("Black_Channels", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBlack_Channels));
    Unit_Enchantment maskWraith_Form;
    memset(&maskWraith_Form, '\0', sizeof(maskWraith_Form));
    maskWraith_Form.Wraith_Form = 1;
    if (1 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWraith_Form));
    else if (2 == sizeof(maskWraith_Form))
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWraith_Form));
    else
        ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWraith_Form));
    Unit_Enchantment maskRegeneration;
    memset(&maskRegeneration, '\0', sizeof(maskRegeneration));
    maskRegeneration.Regeneration = 1;
    if (1 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRegeneration));
    else if (2 == sizeof(maskRegeneration))
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRegeneration));
    else
        ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRegeneration));
    Unit_Enchantment maskPath_Finding;
    memset(&maskPath_Finding, '\0', sizeof(maskPath_Finding));
    maskPath_Finding.Path_Finding = 1;
    if (1 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPath_Finding));
    else if (2 == sizeof(maskPath_Finding))
        ptree->appendChild("Path_Finding", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPath_Finding));
    else
        ptree->appendChild("Path_Finding", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPath_Finding));
    Unit_Enchantment maskWater_Walking;
    memset(&maskWater_Walking, '\0', sizeof(maskWater_Walking));
    maskWater_Walking.Water_Walking = 1;
    if (1 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWater_Walking));
    else if (2 == sizeof(maskWater_Walking))
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWater_Walking));
    else
        ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWater_Walking));
    Unit_Enchantment maskResist_Elements;
    memset(&maskResist_Elements, '\0', sizeof(maskResist_Elements));
    maskResist_Elements.Resist_Elements = 1;
    if (1 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Elements));
    else if (2 == sizeof(maskResist_Elements))
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Elements));
    else
        ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Elements));
    Unit_Enchantment maskElemental_Armor;
    memset(&maskElemental_Armor, '\0', sizeof(maskElemental_Armor));
    maskElemental_Armor.Elemental_Armor = 1;
    if (1 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskElemental_Armor));
    else if (2 == sizeof(maskElemental_Armor))
        ptree->appendChild("Elemental_Armor", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskElemental_Armor));
    else
        ptree->appendChild("Elemental_Armor", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskElemental_Armor));
    Unit_Enchantment maskStone_Skin;
    memset(&maskStone_Skin, '\0', sizeof(maskStone_Skin));
    maskStone_Skin.Stone_Skin = 1;
    if (1 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStone_Skin));
    else if (2 == sizeof(maskStone_Skin))
        ptree->appendChild("Stone_Skin", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStone_Skin));
    else
        ptree->appendChild("Stone_Skin", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStone_Skin));
    Unit_Enchantment maskIron_Skin;
    memset(&maskIron_Skin, '\0', sizeof(maskIron_Skin));
    maskIron_Skin.Iron_Skin = 1;
    if (1 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskIron_Skin));
    else if (2 == sizeof(maskIron_Skin))
        ptree->appendChild("Iron_Skin", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskIron_Skin));
    else
        ptree->appendChild("Iron_Skin", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskIron_Skin));
    Unit_Enchantment maskEndurance;
    memset(&maskEndurance, '\0', sizeof(maskEndurance));
    maskEndurance.Endurance = 1;
    if (1 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEndurance));
    else if (2 == sizeof(maskEndurance))
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEndurance));
    else
        ptree->appendChild("Endurance", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEndurance));
    Unit_Enchantment maskSpell_Lock;
    memset(&maskSpell_Lock, '\0', sizeof(maskSpell_Lock));
    maskSpell_Lock.Spell_Lock = 1;
    if (1 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskSpell_Lock));
    else if (2 == sizeof(maskSpell_Lock))
        ptree->appendChild("Spell_Lock", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskSpell_Lock));
    else
        ptree->appendChild("Spell_Lock", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskSpell_Lock));
    Unit_Enchantment maskInvisibility;
    memset(&maskInvisibility, '\0', sizeof(maskInvisibility));
    maskInvisibility.Invisibility = 1;
    if (1 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvisibility));
    else if (2 == sizeof(maskInvisibility))
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvisibility));
    else
        ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvisibility));
    Unit_Enchantment maskWind_Walking;
    memset(&maskWind_Walking, '\0', sizeof(maskWind_Walking));
    maskWind_Walking.Wind_Walking = 1;
    if (1 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWind_Walking));
    else if (2 == sizeof(maskWind_Walking))
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWind_Walking));
    else
        ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWind_Walking));
    Unit_Enchantment maskFlight;
    memset(&maskFlight, '\0', sizeof(maskFlight));
    maskFlight.Flight = 1;
    if (1 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlight));
    else if (2 == sizeof(maskFlight))
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlight));
    else
        ptree->appendChild("Flight", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlight));
    Unit_Enchantment maskResist_Magic;
    memset(&maskResist_Magic, '\0', sizeof(maskResist_Magic));
    maskResist_Magic.Resist_Magic = 1;
    if (1 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskResist_Magic));
    else if (2 == sizeof(maskResist_Magic))
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskResist_Magic));
    else
        ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskResist_Magic));
    Unit_Enchantment maskMagic_Immunity;
    memset(&maskMagic_Immunity, '\0', sizeof(maskMagic_Immunity));
    maskMagic_Immunity.Magic_Immunity = 1;
    if (1 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskMagic_Immunity));
    else if (2 == sizeof(maskMagic_Immunity))
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskMagic_Immunity));
    else
        ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskMagic_Immunity));
    Unit_Enchantment maskFlame_Blade;
    memset(&maskFlame_Blade, '\0', sizeof(maskFlame_Blade));
    maskFlame_Blade.Flame_Blade = 1;
    if (1 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskFlame_Blade));
    else if (2 == sizeof(maskFlame_Blade))
        ptree->appendChild("Flame_Blade", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskFlame_Blade));
    else
        ptree->appendChild("Flame_Blade", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskFlame_Blade));
    Unit_Enchantment maskEldritch_Weapon;
    memset(&maskEldritch_Weapon, '\0', sizeof(maskEldritch_Weapon));
    maskEldritch_Weapon.Eldritch_Weapon = 1;
    if (1 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskEldritch_Weapon));
    else if (2 == sizeof(maskEldritch_Weapon))
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskEldritch_Weapon));
    else
        ptree->appendChild("Eldritch_Weapon", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskEldritch_Weapon));
    Unit_Enchantment maskTrue_Sight;
    memset(&maskTrue_Sight, '\0', sizeof(maskTrue_Sight));
    maskTrue_Sight.True_Sight = 1;
    if (1 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskTrue_Sight));
    else if (2 == sizeof(maskTrue_Sight))
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskTrue_Sight));
    else
        ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskTrue_Sight));
    Unit_Enchantment maskHoly_Weapon;
    memset(&maskHoly_Weapon, '\0', sizeof(maskHoly_Weapon));
    maskHoly_Weapon.Holy_Weapon = 1;
    if (1 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Weapon));
    else if (2 == sizeof(maskHoly_Weapon))
        ptree->appendChild("Holy_Weapon", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Weapon));
    else
        ptree->appendChild("Holy_Weapon", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Weapon));
    Unit_Enchantment maskHeroism;
    memset(&maskHeroism, '\0', sizeof(maskHeroism));
    maskHeroism.Heroism = 1;
    if (1 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHeroism));
    else if (2 == sizeof(maskHeroism))
        ptree->appendChild("Heroism", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHeroism));
    else
        ptree->appendChild("Heroism", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHeroism));
    Unit_Enchantment maskBless;
    memset(&maskBless, '\0', sizeof(maskBless));
    maskBless.Bless = 1;
    if (1 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskBless));
    else if (2 == sizeof(maskBless))
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskBless));
    else
        ptree->appendChild("Bless", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskBless));
    Unit_Enchantment maskLionheart;
    memset(&maskLionheart, '\0', sizeof(maskLionheart));
    maskLionheart.Lionheart = 1;
    if (1 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskLionheart));
    else if (2 == sizeof(maskLionheart))
        ptree->appendChild("Lionheart", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskLionheart));
    else
        ptree->appendChild("Lionheart", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskLionheart));
    Unit_Enchantment maskGiant_Strength;
    memset(&maskGiant_Strength, '\0', sizeof(maskGiant_Strength));
    maskGiant_Strength.Giant_Strength = 1;
    if (1 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskGiant_Strength));
    else if (2 == sizeof(maskGiant_Strength))
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskGiant_Strength));
    else
        ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskGiant_Strength));
    Unit_Enchantment maskPlanar_Travel;
    memset(&maskPlanar_Travel, '\0', sizeof(maskPlanar_Travel));
    maskPlanar_Travel.Planar_Travel = 1;
    if (1 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskPlanar_Travel));
    else if (2 == sizeof(maskPlanar_Travel))
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskPlanar_Travel));
    else
        ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskPlanar_Travel));
    Unit_Enchantment maskHoly_Armor;
    memset(&maskHoly_Armor, '\0', sizeof(maskHoly_Armor));
    maskHoly_Armor.Holy_Armor = 1;
    if (1 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskHoly_Armor));
    else if (2 == sizeof(maskHoly_Armor))
        ptree->appendChild("Holy_Armor", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskHoly_Armor));
    else
        ptree->appendChild("Holy_Armor", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskHoly_Armor));
    Unit_Enchantment maskRighteousness;
    memset(&maskRighteousness, '\0', sizeof(maskRighteousness));
    maskRighteousness.Righteousness = 1;
    if (1 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskRighteousness));
    else if (2 == sizeof(maskRighteousness))
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskRighteousness));
    else
        ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskRighteousness));
    Unit_Enchantment maskInvulnerability;
    memset(&maskInvulnerability, '\0', sizeof(maskInvulnerability));
    maskInvulnerability.Invulnerability = 1;
    if (1 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskInvulnerability));
    else if (2 == sizeof(maskInvulnerability))
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskInvulnerability));
    else
        ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskInvulnerability));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Unit_Type_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Unit_Type_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_PtrName", new QMoMTreeItemModel<uint16_t>(&rhs->m_PtrName));
    ptree->appendChild("m_Melee", new QMoMTreeItemModel<uint8_t>(&rhs->m_Melee));
    ptree->appendChild("m_Ranged", new QMoMTreeItemModel<uint8_t>(&rhs->m_Ranged));
    ptree->appendChild("m_Ranged_Type", new QMoMTreeItemModel<eRanged_Type>(&rhs->m_Ranged_Type));
    ptree->appendChild("m_Ranged_Shots", new QMoMTreeItemModel<uint8_t>(&rhs->m_Ranged_Shots));
    ptree->appendChild("m_To_Hit", new QMoMTreeItemModel<int8_t>(&rhs->m_To_Hit));
    ptree->appendChild("m_Defense", new QMoMTreeItemModel<uint8_t>(&rhs->m_Defense));
    ptree->appendChild("m_Resistance", new QMoMTreeItemModel<uint8_t>(&rhs->m_Resistance));
    ptree->appendChild("m_MoveHalves", new QMoMTreeItemModel<uint8_t>(&rhs->m_MoveHalves));
    ptree->appendChild("m_Cost", new QMoMTreeItemModel<uint16_t>(&rhs->m_Cost));
    ptree->appendChild("m_Upkeep", new QMoMTreeItemModel<uint8_t>(&rhs->m_Upkeep));
    ptree->appendChild("m_Race_Code", new QMoMTreeItemModel<eRace>(&rhs->m_Race_Code));
    ptree->appendChild("m_Building1Required_or_PortraitLbxIndex", new QMoMTreeItemModel<uint8_t>(&rhs->m_Building1Required_or_PortraitLbxIndex));
    ptree->appendChild("m_Building2_or_HeroType", new QMoMTreeItemModel<eHero_TypeCode>(&rhs->m_Building2_or_HeroType));
    ptree->appendChild("m_Unit_picture", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unit_picture));
    ptree->appendChild("m_Hitpoints", new QMoMTreeItemModel<uint8_t>(&rhs->m_Hitpoints));
    ptree->appendChild("m_Scouting", new QMoMTreeItemModel<uint8_t>(&rhs->m_Scouting));
    ptree->appendChild("m_Transport_Capacity", new QMoMTreeItemModel<uint8_t>(&rhs->m_Transport_Capacity));
    ptree->appendChild("m_Nr_Figures", new QMoMTreeItemModel<uint8_t>(&rhs->m_Nr_Figures));
    ptree->appendChild("m_Construction", new QMoMTreeItemModel<uint8_t>(&rhs->m_Construction));
    ptree->appendChild("m_Gaze_Modifier", new QMoMTreeItemModel<int8_t>(&rhs->m_Gaze_Modifier));
    ptree->appendTree(constructTreeItem(&rhs->m_Movement_Flags, "m_Movement_Flags"), "");
    ptree->appendChild("m_Zero_19", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_19));
    ptree->appendTree(constructTreeItem(&rhs->m_Immunity_Flags, "m_Immunity_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attribute_Flags, "m_Attribute_Flags"), "");
    ptree->appendChild("m_Zero_1D", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_1D));
    ptree->appendTree(constructTreeItem(&rhs->m_Ability_Flags, "m_Ability_Flags"), "");
    ptree->appendTree(constructTreeItem(&rhs->m_Attack_Flags, "m_Attack_Flags"), "");
    ptree->appendChild("m_Sound", new QMoMTreeItemModel<uint8_t>(&rhs->m_Sound));
    ptree->appendChild("m_Zero_23", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_23));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Unit_Weapon_Mutation* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Unit_Weapon_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    Unit_Weapon_Mutation maskWeapon_Type;
    memset(&maskWeapon_Type, '\0', sizeof(maskWeapon_Type));
    maskWeapon_Type.Weapon_Type = 3;
    if (1 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskWeapon_Type));
    else if (2 == sizeof(maskWeapon_Type))
        ptree->appendChild("Weapon_Type", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskWeapon_Type));
    else
        ptree->appendChild("Weapon_Type", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskWeapon_Type));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Skin;
    memset(&maskChaos_Channels_Demon_Skin, '\0', sizeof(maskChaos_Channels_Demon_Skin));
    maskChaos_Channels_Demon_Skin.Chaos_Channels_Demon_Skin = 1;
    if (1 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Skin));
    else if (2 == sizeof(maskChaos_Channels_Demon_Skin))
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Skin));
    else
        ptree->appendChild("Chaos_Channels_Demon_Skin", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Skin));
    Unit_Weapon_Mutation maskChaos_Channels_Demon_Wings;
    memset(&maskChaos_Channels_Demon_Wings, '\0', sizeof(maskChaos_Channels_Demon_Wings));
    maskChaos_Channels_Demon_Wings.Chaos_Channels_Demon_Wings = 1;
    if (1 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Demon_Wings));
    else if (2 == sizeof(maskChaos_Channels_Demon_Wings))
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Demon_Wings));
    else
        ptree->appendChild("Chaos_Channels_Demon_Wings", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Demon_Wings));
    Unit_Weapon_Mutation maskChaos_Channels_Fiery_Breath;
    memset(&maskChaos_Channels_Fiery_Breath, '\0', sizeof(maskChaos_Channels_Fiery_Breath));
    maskChaos_Channels_Fiery_Breath.Chaos_Channels_Fiery_Breath = 1;
    if (1 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskChaos_Channels_Fiery_Breath));
    else if (2 == sizeof(maskChaos_Channels_Fiery_Breath))
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskChaos_Channels_Fiery_Breath));
    else
        ptree->appendChild("Chaos_Channels_Fiery_Breath", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskChaos_Channels_Fiery_Breath));
    Unit_Weapon_Mutation maskUndead;
    memset(&maskUndead, '\0', sizeof(maskUndead));
    maskUndead.Undead = 1;
    if (1 == sizeof(maskUndead))
        ptree->appendChild("Undead", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskUndead));
    else if (2 == sizeof(maskUndead))
        ptree->appendChild("Undead", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskUndead));
    else
        ptree->appendChild("Undead", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskUndead));
    Unit_Weapon_Mutation maskStasis_initial;
    memset(&maskStasis_initial, '\0', sizeof(maskStasis_initial));
    maskStasis_initial.Stasis_initial = 1;
    if (1 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_initial));
    else if (2 == sizeof(maskStasis_initial))
        ptree->appendChild("Stasis_initial", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_initial));
    else
        ptree->appendChild("Stasis_initial", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_initial));
    Unit_Weapon_Mutation maskStasis_lingering;
    memset(&maskStasis_lingering, '\0', sizeof(maskStasis_lingering));
    maskStasis_lingering.Stasis_lingering = 1;
    if (1 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new QMoMTreeItemModel<uint8_t>((uint8_t*)rhs, *(uint8_t*)&maskStasis_lingering));
    else if (2 == sizeof(maskStasis_lingering))
        ptree->appendChild("Stasis_lingering", new QMoMTreeItemModel<uint16_t>((uint16_t*)rhs, *(uint16_t*)&maskStasis_lingering));
    else
        ptree->appendChild("Stasis_lingering", new QMoMTreeItemModel<uint32_t>((uint32_t*)rhs, *(uint32_t*)&maskStasis_lingering));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Upkeep_Enchantments* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Upkeep_Enchantments>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("Immolation", new QMoMTreeItemModel<uint16_t>(&rhs->Immolation));
    ptree->appendChild("Guardian_Wind", new QMoMTreeItemModel<uint16_t>(&rhs->Guardian_Wind));
    ptree->appendChild("Berserk", new QMoMTreeItemModel<uint16_t>(&rhs->Berserk));
    ptree->appendChild("Cloak_of_Fear", new QMoMTreeItemModel<uint16_t>(&rhs->Cloak_of_Fear));
    ptree->appendChild("Black_Channels", new QMoMTreeItemModel<uint16_t>(&rhs->Black_Channels));
    ptree->appendChild("Wraith_Form", new QMoMTreeItemModel<uint16_t>(&rhs->Wraith_Form));
    ptree->appendChild("Regeneration", new QMoMTreeItemModel<uint16_t>(&rhs->Regeneration));
    ptree->appendChild("Path_Finding", new QMoMTreeItemModel<uint16_t>(&rhs->Path_Finding));
    ptree->appendChild("Water_Walking", new QMoMTreeItemModel<uint16_t>(&rhs->Water_Walking));
    ptree->appendChild("Resist_Elements", new QMoMTreeItemModel<uint16_t>(&rhs->Resist_Elements));
    ptree->appendChild("Elemental_Armor", new QMoMTreeItemModel<uint16_t>(&rhs->Elemental_Armor));
    ptree->appendChild("Stone_Skin", new QMoMTreeItemModel<uint16_t>(&rhs->Stone_Skin));
    ptree->appendChild("Iron_Skin", new QMoMTreeItemModel<uint16_t>(&rhs->Iron_Skin));
    ptree->appendChild("Endurance", new QMoMTreeItemModel<uint16_t>(&rhs->Endurance));
    ptree->appendChild("Spell_Lock", new QMoMTreeItemModel<uint16_t>(&rhs->Spell_Lock));
    ptree->appendChild("Invisibility", new QMoMTreeItemModel<uint16_t>(&rhs->Invisibility));
    ptree->appendChild("Wind_Walking", new QMoMTreeItemModel<uint16_t>(&rhs->Wind_Walking));
    ptree->appendChild("Flight", new QMoMTreeItemModel<uint16_t>(&rhs->Flight));
    ptree->appendChild("Resist_Magic", new QMoMTreeItemModel<uint16_t>(&rhs->Resist_Magic));
    ptree->appendChild("Magic_Immunity", new QMoMTreeItemModel<uint16_t>(&rhs->Magic_Immunity));
    ptree->appendChild("Flame_Blade", new QMoMTreeItemModel<uint16_t>(&rhs->Flame_Blade));
    ptree->appendChild("Eldritch_Weapon", new QMoMTreeItemModel<uint16_t>(&rhs->Eldritch_Weapon));
    ptree->appendChild("True_Sight", new QMoMTreeItemModel<uint16_t>(&rhs->True_Sight));
    ptree->appendChild("Holy_Weapon", new QMoMTreeItemModel<uint16_t>(&rhs->Holy_Weapon));
    ptree->appendChild("Heroism", new QMoMTreeItemModel<uint16_t>(&rhs->Heroism));
    ptree->appendChild("Bless", new QMoMTreeItemModel<uint16_t>(&rhs->Bless));
    ptree->appendChild("Lionheart", new QMoMTreeItemModel<uint16_t>(&rhs->Lionheart));
    ptree->appendChild("Giant_Strength", new QMoMTreeItemModel<uint16_t>(&rhs->Giant_Strength));
    ptree->appendChild("Planar_Travel", new QMoMTreeItemModel<uint16_t>(&rhs->Planar_Travel));
    ptree->appendChild("Holy_Armor", new QMoMTreeItemModel<uint16_t>(&rhs->Holy_Armor));
    ptree->appendChild("Righteousness", new QMoMTreeItemModel<uint16_t>(&rhs->Righteousness));
    ptree->appendChild("Invulnerability", new QMoMTreeItemModel<uint16_t>(&rhs->Invulnerability));
    ptree->appendChild("Wall_of_Fire", new QMoMTreeItemModel<uint16_t>(&rhs->Wall_of_Fire));
    ptree->appendChild("Chaos_Rift", new QMoMTreeItemModel<uint16_t>(&rhs->Chaos_Rift));
    ptree->appendChild("Dark_Rituals", new QMoMTreeItemModel<uint16_t>(&rhs->Dark_Rituals));
    ptree->appendChild("Evil_Presence", new QMoMTreeItemModel<uint16_t>(&rhs->Evil_Presence));
    ptree->appendChild("Cursed_Lands", new QMoMTreeItemModel<uint16_t>(&rhs->Cursed_Lands));
    ptree->appendChild("Pestilence", new QMoMTreeItemModel<uint16_t>(&rhs->Pestilence));
    ptree->appendChild("Cloud_of_Shadow", new QMoMTreeItemModel<uint16_t>(&rhs->Cloud_of_Shadow));
    ptree->appendChild("Famine", new QMoMTreeItemModel<uint16_t>(&rhs->Famine));
    ptree->appendChild("Flying_Fortress", new QMoMTreeItemModel<uint16_t>(&rhs->Flying_Fortress));
    ptree->appendChild("Nature_Ward", new QMoMTreeItemModel<uint16_t>(&rhs->Nature_Ward));
    ptree->appendChild("Sorcery_Ward", new QMoMTreeItemModel<uint16_t>(&rhs->Sorcery_Ward));
    ptree->appendChild("Chaos_Ward", new QMoMTreeItemModel<uint16_t>(&rhs->Chaos_Ward));
    ptree->appendChild("Life_Ward", new QMoMTreeItemModel<uint16_t>(&rhs->Life_Ward));
    ptree->appendChild("Death_Ward", new QMoMTreeItemModel<uint16_t>(&rhs->Death_Ward));
    ptree->appendChild("Natures_Eye", new QMoMTreeItemModel<uint16_t>(&rhs->Natures_Eye));
    ptree->appendChild("Earth_Gate", new QMoMTreeItemModel<uint16_t>(&rhs->Earth_Gate));
    ptree->appendChild("Stream_of_Life", new QMoMTreeItemModel<uint16_t>(&rhs->Stream_of_Life));
    ptree->appendChild("Gaias_Blessing", new QMoMTreeItemModel<uint16_t>(&rhs->Gaias_Blessing));
    ptree->appendChild("Inspirations", new QMoMTreeItemModel<uint16_t>(&rhs->Inspirations));
    ptree->appendChild("Prosperity", new QMoMTreeItemModel<uint16_t>(&rhs->Prosperity));
    ptree->appendChild("Astral_Gate", new QMoMTreeItemModel<uint16_t>(&rhs->Astral_Gate));
    ptree->appendChild("Heavenly_Light", new QMoMTreeItemModel<uint16_t>(&rhs->Heavenly_Light));
    ptree->appendChild("Consecration", new QMoMTreeItemModel<uint16_t>(&rhs->Consecration));
    ptree->appendChild("Wall_of_Darkness", new QMoMTreeItemModel<uint16_t>(&rhs->Wall_of_Darkness));
    ptree->appendChild("Altar_of_Battle", new QMoMTreeItemModel<uint16_t>(&rhs->Altar_of_Battle));
    ptree->appendChild("Nightshade", new QMoMTreeItemModel<uint16_t>(&rhs->Nightshade));
    ptree->appendChild("Eternal_Night", new QMoMTreeItemModel<uint16_t>(&rhs->Eternal_Night));
    ptree->appendChild("Evil_Omens", new QMoMTreeItemModel<uint16_t>(&rhs->Evil_Omens));
    ptree->appendChild("Zombie_Mastery", new QMoMTreeItemModel<uint16_t>(&rhs->Zombie_Mastery));
    ptree->appendChild("Aura_of_Majesty", new QMoMTreeItemModel<uint16_t>(&rhs->Aura_of_Majesty));
    ptree->appendChild("Wind_Mastery", new QMoMTreeItemModel<uint16_t>(&rhs->Wind_Mastery));
    ptree->appendChild("Suppress_Magic", new QMoMTreeItemModel<uint16_t>(&rhs->Suppress_Magic));
    ptree->appendChild("Time_Stop", new QMoMTreeItemModel<uint16_t>(&rhs->Time_Stop));
    ptree->appendChild("Nature_Awareness", new QMoMTreeItemModel<uint16_t>(&rhs->Nature_Awareness));
    ptree->appendChild("Natures_Wrath", new QMoMTreeItemModel<uint16_t>(&rhs->Natures_Wrath));
    ptree->appendChild("Herb_Mastery", new QMoMTreeItemModel<uint16_t>(&rhs->Herb_Mastery));
    ptree->appendChild("Chaos_Surge", new QMoMTreeItemModel<uint16_t>(&rhs->Chaos_Surge));
    ptree->appendChild("Doom_Mastery", new QMoMTreeItemModel<uint16_t>(&rhs->Doom_Mastery));
    ptree->appendChild("Great_Wasting", new QMoMTreeItemModel<uint16_t>(&rhs->Great_Wasting));
    ptree->appendChild("Meteor_Storm", new QMoMTreeItemModel<uint16_t>(&rhs->Meteor_Storm));
    ptree->appendChild("Armageddon", new QMoMTreeItemModel<uint16_t>(&rhs->Armageddon));
    ptree->appendChild("Tranquility", new QMoMTreeItemModel<uint16_t>(&rhs->Tranquility));
    ptree->appendChild("Life_Force", new QMoMTreeItemModel<uint16_t>(&rhs->Life_Force));
    ptree->appendChild("Crusade", new QMoMTreeItemModel<uint16_t>(&rhs->Crusade));
    ptree->appendChild("Just_Cause", new QMoMTreeItemModel<uint16_t>(&rhs->Just_Cause));
    ptree->appendChild("Holy_Arms", new QMoMTreeItemModel<uint16_t>(&rhs->Holy_Arms));
    ptree->appendChild("Planar_Seal", new QMoMTreeItemModel<uint16_t>(&rhs->Planar_Seal));
    ptree->appendChild("Charm_of_Life", new QMoMTreeItemModel<uint16_t>(&rhs->Charm_of_Life));
    ptree->appendChild("Detect_Magic", new QMoMTreeItemModel<uint16_t>(&rhs->Detect_Magic));
    ptree->appendChild("Awareness", new QMoMTreeItemModel<uint16_t>(&rhs->Awareness));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Wizard* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Wizard>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Portrait", new QMoMTreeItemModel<ePortrait>(&rhs->m_Portrait));
    ptree->appendChild("m_Name", new QMoMTreeItemModel<char[20]>(rhs->m_Name));
    ptree->appendChild("m_Home_Race", new QMoMTreeItemModel<eRace>(&rhs->m_Home_Race));
    ptree->appendChild("m_BannerColor", new QMoMTreeItemModel<eBannerColor>(&rhs->m_BannerColor));
    ptree->appendChild("m_Personality", new QMoMTreeItemModel<ePersonality>(&rhs->m_Personality));
    ptree->appendChild("m_Objective", new QMoMTreeItemModel<eObjective>(&rhs->m_Objective));
    QMoMTreeItemModelBase* ptreem_Unk_01C = ptree;
    if (6 > 3)
    {
        ptreem_Unk_01C = new QMoMTreeItemModelBase("m_Unk_01C");
        ptree->appendTree(ptreem_Unk_01C, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_01C[" << i << "]";
          ptreem_Unk_01C->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_01C[i]));
    }
    ptree->appendChild("m_ResearchCost_SpellofMastery_GUESS", new QMoMTreeItemModel<uint16_t>(&rhs->m_ResearchCost_SpellofMastery_GUESS));
    ptree->appendChild("m_Fame", new QMoMTreeItemModel<uint16_t>(&rhs->m_Fame));
    ptree->appendChild("m_Power_Base", new QMoMTreeItemModel<uint16_t>(&rhs->m_Power_Base));
    ptree->appendChild("m_Unk_028", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_028));
    ptree->appendChild("m_Research_Percentage", new QMoMTreeItemModel<uint8_t>(&rhs->m_Research_Percentage));
    ptree->appendChild("m_Mana_Percentage", new QMoMTreeItemModel<uint8_t>(&rhs->m_Mana_Percentage));
    ptree->appendChild("m_Skill_Percentage", new QMoMTreeItemModel<uint8_t>(&rhs->m_Skill_Percentage));
    ptree->appendChild("m_Mana_generated_by_volcanoes", new QMoMTreeItemModel<uint8_t>(&rhs->m_Mana_generated_by_volcanoes));
    ptree->appendChild("m_X_Coordinate_of_Summoning_Circle", new QMoMTreeItemModel<int16_t>(&rhs->m_X_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Y_Coordinate_of_Summoning_Circle", new QMoMTreeItemModel<int16_t>(&rhs->m_Y_Coordinate_of_Summoning_Circle));
    ptree->appendChild("m_Plane_of_Summoning_Circle", new QMoMTreeItemModel<ePlane>(&rhs->m_Plane_of_Summoning_Circle));
    ptree->appendChild("m_Zero_033", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_033));
    QMoMTreeItemModelBase* ptreem_Research_Spell_candidates = ptree;
    if (8 > 3)
    {
        ptreem_Research_Spell_candidates = new QMoMTreeItemModelBase("m_Research_Spell_candidates");
        ptree->appendTree(ptreem_Research_Spell_candidates, "");
    }
    for (unsigned i = 0; i < 8; ++i)
    {
          std::ostringstream oss;
          oss << "m_Research_Spell_candidates[" << i << "]";
          ptreem_Research_Spell_candidates->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eSpell16>(&rhs->m_Research_Spell_candidates[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_044 = ptree;
    if (4 > 3)
    {
        ptreem_Unk_044 = new QMoMTreeItemModelBase("m_Unk_044");
        ptree->appendTree(ptreem_Unk_044, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_044[" << i << "]";
          ptreem_Unk_044->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_044[i]));
    }
    ptree->appendChild("m_Garrison_average_strength", new QMoMTreeItemModel<int16_t>(&rhs->m_Garrison_average_strength));
    ptree->appendChild("m_Unk_04A", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_04A));
    ptree->appendChild("m_Skill_Left_in_combat", new QMoMTreeItemModel<int16_t>(&rhs->m_Skill_Left_in_combat));
    ptree->appendChild("m_Cost_Left_of_Spell_being_cast", new QMoMTreeItemModel<int16_t>(&rhs->m_Cost_Left_of_Spell_being_cast));
    ptree->appendChild("m_Initial_Cost_of_Spell_being_cast", new QMoMTreeItemModel<int16_t>(&rhs->m_Initial_Cost_of_Spell_being_cast));
    ptree->appendChild("m_Spell_being_cast", new QMoMTreeItemModel<eSpell16>(&rhs->m_Spell_being_cast));
    ptree->appendChild("m_Unused_Casting_Skill_available_this_turn", new QMoMTreeItemModel<int16_t>(&rhs->m_Unused_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Nominal_Casting_Skill_available_this_turn", new QMoMTreeItemModel<int16_t>(&rhs->m_Nominal_Casting_Skill_available_this_turn));
    ptree->appendChild("m_Tax_Rate", new QMoMTreeItemModel<eTax_Rate>(&rhs->m_Tax_Rate));
    ptree->appendChild("m_Number_of_Spellbooks_Nature", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_of_Spellbooks_Nature));
    ptree->appendChild("m_Number_of_Spellbooks_Sorcery", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_of_Spellbooks_Sorcery));
    ptree->appendChild("m_Number_of_Spellbooks_Chaos", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_of_Spellbooks_Chaos));
    ptree->appendChild("m_Number_of_Spellbooks_Life", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_of_Spellbooks_Life));
    ptree->appendChild("m_Number_of_Spellbooks_Death", new QMoMTreeItemModel<int16_t>(&rhs->m_Number_of_Spellbooks_Death));
    ptree->appendTree(constructTreeItem(&rhs->m_Skills, "m_Skills"), "");
    QMoMTreeItemModelBase* ptreem_Heroes_hired_by_wizard = ptree;
    if (gMAX_HIRED_HEROES > 3)
    {
        ptreem_Heroes_hired_by_wizard = new QMoMTreeItemModelBase("m_Heroes_hired_by_wizard");
        ptree->appendTree(ptreem_Heroes_hired_by_wizard, "");
    }
    for (unsigned i = 0; i < gMAX_HIRED_HEROES; ++i)
    {
          std::ostringstream oss;
          oss << "m_Heroes_hired_by_wizard[" << i << "]";
          ptreem_Heroes_hired_by_wizard->appendTree(constructTreeItem(&rhs->m_Heroes_hired_by_wizard[i], oss.str().c_str()), "");
    }
    ptree->appendChild("m_Unk_11E", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_11E));
    QMoMTreeItemModelBase* ptreem_Items_in_Slots = ptree;
    if (4 > 3)
    {
        ptreem_Items_in_Slots = new QMoMTreeItemModelBase("m_Items_in_Slots");
        ptree->appendTree(ptreem_Items_in_Slots, "");
    }
    for (unsigned i = 0; i < 4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Items_in_Slots[" << i << "]";
          ptreem_Items_in_Slots->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Items_in_Slots[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Diplomacy, "m_Diplomacy"), "");
    ptree->appendChild("m_Researching_Left", new QMoMTreeItemModel<int16_t>(&rhs->m_Researching_Left));
    ptree->appendChild("m_Mana_Crystals", new QMoMTreeItemModel<int16_t>(&rhs->m_Mana_Crystals));
    ptree->appendChild("m_Wizard_Casting_Skill", new QMoMTreeItemModel<int32_t>(&rhs->m_Wizard_Casting_Skill));
    ptree->appendChild("m_Researching_Spell", new QMoMTreeItemModel<eSpell>(&rhs->m_Researching_Spell));
    ptree->appendTree(constructTreeItem(&rhs->m_Spells_Known, "m_Spells_Known"), "");
    QMoMTreeItemModelBase* ptreem_Unk_33A = ptree;
    if (26 > 3)
    {
        ptreem_Unk_33A = new QMoMTreeItemModelBase("m_Unk_33A");
        ptree->appendTree(ptreem_Unk_33A, "");
    }
    for (unsigned i = 0; i < 26; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_33A[" << i << "]";
          ptreem_Unk_33A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_33A[i]));
    }
    ptree->appendChild("m_Bitmask_banished_wizards", new QMoMTreeItemModel<uint16_t>(&rhs->m_Bitmask_banished_wizards));
    ptree->appendChild("m_Gold_Coins", new QMoMTreeItemModel<int16_t>(&rhs->m_Gold_Coins));
    ptree->appendChild("m_Unk_358", new QMoMTreeItemModel<int16_t>(&rhs->m_Unk_358));
    ptree->appendChild("m_Astrologer_Magic_Power", new QMoMTreeItemModel<int16_t>(&rhs->m_Astrologer_Magic_Power));
    ptree->appendChild("m_Astrologer_Spell_Research", new QMoMTreeItemModel<int16_t>(&rhs->m_Astrologer_Spell_Research));
    ptree->appendChild("m_Astrologer_Army_Strength", new QMoMTreeItemModel<int16_t>(&rhs->m_Astrologer_Army_Strength));
    ptree->appendChild("m_Astrologer_Power_GUESS", new QMoMTreeItemModel<int16_t>(&rhs->m_Astrologer_Power_GUESS));
    QMoMTreeItemModelBase* ptreem_Historian = ptree;
    if (288 > 3)
    {
        ptreem_Historian = new QMoMTreeItemModelBase("m_Historian");
        ptree->appendTree(ptreem_Historian, "");
    }
    for (unsigned i = 0; i < 288; ++i)
    {
          std::ostringstream oss;
          oss << "m_Historian[" << i << "]";
          ptreem_Historian->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Historian[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->m_Global_Enchantments, "m_Global_Enchantments"), "");
    QMoMTreeItemModelBase* ptreem_Unk_49A = ptree;
    if (42 > 3)
    {
        ptreem_Unk_49A = new QMoMTreeItemModelBase("m_Unk_49A");
        ptree->appendTree(ptreem_Unk_49A, "");
    }
    for (unsigned i = 0; i < 42; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_49A[" << i << "]";
          ptreem_Unk_49A->appendChild(oss.str().c_str(), new QMoMTreeItemModel<uint8_t>(&rhs->m_Unk_49A[i]));
    }
    ptree->appendChild("m_Books_Color", new QMoMTreeItemModel<eRealm_Type>(&rhs->m_Books_Color));
    ptree->appendChild("m_Zero_4C5", new QMoMTreeItemModel<uint8_t>(&rhs->m_Zero_4C5));
    ptree->appendChild("m_Unk_4C6", new QMoMTreeItemModel<uint16_t>(&rhs->m_Unk_4C6));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Wizard_Diplomacy* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Wizard_Diplomacy>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreem_Contacted = ptree;
    if (6 > 3)
    {
        ptreem_Contacted = new QMoMTreeItemModelBase("m_Contacted");
        ptree->appendTree(ptreem_Contacted, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Contacted[" << i << "]";
          ptreem_Contacted->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Contacted[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_12E_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk_12E_Relation = new QMoMTreeItemModelBase("m_Unk_12E_Relation");
        ptree->appendTree(ptreem_Unk_12E_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_12E_Relation[" << i << "]";
          ptreem_Unk_12E_Relation->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Unk_12E_Relation[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_13A_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk_13A_Relation = new QMoMTreeItemModelBase("m_Unk_13A_Relation");
        ptree->appendTree(ptreem_Unk_13A_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_13A_Relation[" << i << "]";
          ptreem_Unk_13A_Relation->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Unk_13A_Relation[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_146_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk_146_Relation = new QMoMTreeItemModelBase("m_Unk_146_Relation");
        ptree->appendTree(ptreem_Unk_146_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_146_Relation[" << i << "]";
          ptreem_Unk_146_Relation->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int16_t>(&rhs->m_Unk_146_Relation[i]));
    }
    QMoMTreeItemModelBase* ptreem_Current_Wizard_Relations = ptree;
    if (6 > 3)
    {
        ptreem_Current_Wizard_Relations = new QMoMTreeItemModelBase("m_Current_Wizard_Relations");
        ptree->appendTree(ptreem_Current_Wizard_Relations, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Current_Wizard_Relations[" << i << "]";
          ptreem_Current_Wizard_Relations->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Current_Wizard_Relations[i]));
    }
    QMoMTreeItemModelBase* ptreem_War_Status = ptree;
    if (6 > 3)
    {
        ptreem_War_Status = new QMoMTreeItemModelBase("m_War_Status");
        ptree->appendTree(ptreem_War_Status, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_War_Status[" << i << "]";
          ptreem_War_Status->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eWar_Status>(&rhs->m_War_Status[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_15E = ptree;
    if (0x24 > 3)
    {
        ptreem_Unk_15E = new QMoMTreeItemModelBase("m_Unk_15E");
        ptree->appendTree(ptreem_Unk_15E, "");
    }
    for (unsigned i = 0; i < 0x24; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_15E[" << i << "]";
          ptreem_Unk_15E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_15E[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_182_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk_182_Relation = new QMoMTreeItemModelBase("m_Unk_182_Relation");
        ptree->appendTree(ptreem_Unk_182_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_182_Relation[" << i << "]";
          ptreem_Unk_182_Relation->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_182_Relation[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_188_Relation = ptree;
    if (6 > 3)
    {
        ptreem_Unk_188_Relation = new QMoMTreeItemModelBase("m_Unk_188_Relation");
        ptree->appendTree(ptreem_Unk_188_Relation, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_188_Relation[" << i << "]";
          ptreem_Unk_188_Relation->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_188_Relation[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_18E = ptree;
    if (18 > 3)
    {
        ptreem_Unk_18E = new QMoMTreeItemModelBase("m_Unk_18E");
        ptree->appendTree(ptreem_Unk_18E, "");
    }
    for (unsigned i = 0; i < 18; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_18E[" << i << "]";
          ptreem_Unk_18E->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_18E[i]));
    }
    QMoMTreeItemModelBase* ptreem_Diplomacy_penalty_GUESS = ptree;
    if (6 > 3)
    {
        ptreem_Diplomacy_penalty_GUESS = new QMoMTreeItemModelBase("m_Diplomacy_penalty_GUESS");
        ptree->appendTree(ptreem_Diplomacy_penalty_GUESS, "");
    }
    for (unsigned i = 0; i < 6; ++i)
    {
          std::ostringstream oss;
          oss << "m_Diplomacy_penalty_GUESS[" << i << "]";
          ptreem_Diplomacy_penalty_GUESS->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Diplomacy_penalty_GUESS[i]));
    }
    QMoMTreeItemModelBase* ptreem_Unk_1A6 = ptree;
    if (0xB4 > 3)
    {
        ptreem_Unk_1A6 = new QMoMTreeItemModelBase("m_Unk_1A6");
        ptree->appendTree(ptreem_Unk_1A6, "");
    }
    for (unsigned i = 0; i < 0xB4; ++i)
    {
          std::ostringstream oss;
          oss << "m_Unk_1A6[" << i << "]";
          ptreem_Unk_1A6->appendChild(oss.str().c_str(), new QMoMTreeItemModel<int8_t>(&rhs->m_Unk_1A6[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(Wizard_Type_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<Wizard_Type_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Wizard_Name", new QMoMTreeItemModel<char[10]>(rhs->m_Wizard_Name));
    ptree->appendChild("m_Life_books", new QMoMTreeItemModel<uint16_t>(&rhs->m_Life_books));
    ptree->appendChild("m_Sorcery_books", new QMoMTreeItemModel<uint16_t>(&rhs->m_Sorcery_books));
    ptree->appendChild("m_Nature_books", new QMoMTreeItemModel<uint16_t>(&rhs->m_Nature_books));
    ptree->appendChild("m_Death_books", new QMoMTreeItemModel<uint16_t>(&rhs->m_Death_books));
    ptree->appendChild("m_Chaos_books", new QMoMTreeItemModel<uint16_t>(&rhs->m_Chaos_books));
    ptree->appendChild("m_Skill", new QMoMTreeItemModel<eSkill16>(&rhs->m_Skill));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(WizardsExe_Game_Data* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<WizardsExe_Game_Data>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_UnitNr_Active", new QMoMTreeItemModel<uint16_t>(&rhs->m_UnitNr_Active));
    ptree->appendChild("m_Current_Turn", new QMoMTreeItemModel<uint16_t>(&rhs->m_Current_Turn));
    ptree->appendChild("m_Number_of_Units", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Units));
    ptree->appendChild("m_Number_of_Cities", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Cities));
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty140m>((eDifficulty140m*)&rhs->m_Difficulty));
    }
    else
    {
        ptree->appendChild("m_Difficulty", new QMoMTreeItemModel<eDifficulty>(&rhs->m_Difficulty));
    }
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItemModel<eMagic_Powerful140m>((eMagic_Powerful140m*)&rhs->m_Magic_Powerful_setting));
    }
    else
    {
        ptree->appendChild("m_Magic_Powerful_setting", new QMoMTreeItemModel<eMagic_Powerful>(&rhs->m_Magic_Powerful_setting));
    }
    if (QMoMTreeItemModelBase::game()->getMoMVersion() >= std::string("v1.40m"))
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItemModel<eLand_Size140m>((eLand_Size140m*)&rhs->m_Land_Size_setting));
    }
    else
    {
        ptree->appendChild("m_Land_Size_setting", new QMoMTreeItemModel<eLand_Size>(&rhs->m_Land_Size_setting));
    }
    ptree->appendChild("m_Number_of_Wizards", new QMoMTreeItemModel<uint16_t>(&rhs->m_Number_of_Wizards));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(WizardsExe_Save_Name* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<WizardsExe_Save_Name>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendChild("m_Name", new QMoMTreeItemModel<char[20]>(rhs->m_Name));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionAbility_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionAbility_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionAttack_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionAttack_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionAttribute_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionAttribute_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionBuilding_Status* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionBuilding_Status>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreea = ptree;
    if (eBuilding_array_MAX > 3)
    {
        ptreea = new QMoMTreeItemModelBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (unsigned i = 0; i < eBuilding_array_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eBuildingStatus>(&rhs->a[i]));
    }
    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionCombat_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionCombat_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint16_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionHero_Abilities* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionHero_Abilities>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionImmunity_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionImmunity_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionItem_Powers* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionItem_Powers>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionList_Hero_stats* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionList_Hero_stats>(rhs, context);
    if (0 == rhs)
        return ptree;

    QMoMTreeItemModelBase* ptreea = ptree;
    if (gMAX_HERO_TYPES > 3)
    {
        ptreea = new QMoMTreeItemModelBase("a");
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

QMoMTreeItemModelBase* constructTreeItem(unionMovement_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionMovement_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionSkills* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionSkills>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    QMoMTreeItemModelBase* ptreea = ptree;
    if (eSkill_MAX > 3)
    {
        ptreea = new QMoMTreeItemModelBase("a");
        ptree->appendTree(ptreea, "");
    }
    for (unsigned i = 0; i < eSkill_MAX; ++i)
    {
          std::ostringstream oss;
          oss << "a[" << i << "]";
          ptreea->appendChild(oss.str().c_str(), new QMoMTreeItemModel<eYesNo8>(&rhs->a[i]));
    }
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionTower_Node_Lair_Flags* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionTower_Node_Lair_Flags>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint8_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionUnit_Enchantment* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionUnit_Enchantment>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint32_t>(&rhs->bits));
    return ptree;
}

QMoMTreeItemModelBase* constructTreeItem(unionUnit_Weapon_Mutation* rhs, const QString& context)
{
    QMoMTreeItemModelBase* ptree = new QMoMTreeItemModelSubtree<unionUnit_Weapon_Mutation>(rhs, context);
    if (0 == rhs)
        return ptree;

    ptree->appendTree(constructTreeItem(&rhs->s, "s"), "");
    ptree->appendChild("bits", new QMoMTreeItemModel<uint8_t>(&rhs->bits));
    return ptree;
}


} // namespace
