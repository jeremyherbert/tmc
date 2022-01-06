#ifndef PROJECTILE_H
#define PROJECTILE_H

extern Entity* CreateProjectile(u32);

void DarkNutSwordSlash(Entity*);
void RockProjectile(Entity*);
void BoneProjectile(Entity*);
void MoblinSpear(Entity*);
void DekuSeedProjectile(Entity*);
void Projectile5(Entity*);
void DirtBallProjectile(Entity*);
void WindProjectile(Entity*);
void FireProjectile(Entity*);
void IceProjectile(Entity*);
void GleerokProjectile(Entity*);
void KeatonDagger(Entity*);
void GuardLineOfSight(Entity*);
void ArrowProjectile(Entity*);
void MazaalEnergyBeam(Entity*);
void OctorokBossProjectile(Entity*);
void StalfosProjectile(Entity*);
void LakituCloudProjectile(Entity*);
void LakituLightning(Entity*);
void MandiblesProjectile(Entity*);
void RemovableDust(Entity*);
void SpiderWeb(Entity*);
void TorchTrapProjectile(Entity*);
void GuruguruBarProjectile(Entity*);
void V1DarkMagicProjectile(Entity*);
void BallAndChain(Entity*);
void V1FireProjectile(Entity*);
void CannonballProjectile(Entity*);
void V1EyeLaser(Entity*);
void Winder(Entity*);
void SpikedRollers(Entity*);
void V2Projectile(Entity*);
void V3HandProjectile(Entity*);
void V3ElectricProjectile(Entity*);
void GyorgTail(Entity*);
void GyorgMaleEnergyProjectile(Entity*);
void V3TennisBallProjectile(Entity*);

typedef enum {
    /*00*/ DARK_NUT_SWORD_SLASH,
    /*01*/ ROCK_PROJECTILE,
    /*02*/ BONE_PROJECTILE,
    /*03*/ MOBLIN_SPEAR,
    /*04*/ DEKU_SEED_PROJECTILE,
    /*05*/ PROJECTILE_5,
    /*06*/ DIRT_BALL_PROJECTILE,
    /*07*/ WIND_PROJECTILE,
    /*08*/ FIRE_PROJECTILE,
    /*09*/ ICE_PROJECTILE,
    /*0A*/ GLEEROK_PROJECTILE,
    /*0B*/ KEATON_DAGGER,
    /*0C*/ GUARD_LINE_OF_SIGHT,
    /*0D*/ ARROW_PROJECTILE,
    /*0E*/ MAZAAL_ENERGY_BEAM,
    /*0F*/ OCTOROK_BOSS_PROJECTILE,
    /*10*/ STALFOS_PROJECTILE,
    /*11*/ LAKITU_CLOUD_PROJECTILE,
    /*12*/ LAKITU_LIGHTNING,
    /*13*/ MANDIBLES_PROJECTILE,
    /*14*/ REMOVABLE_DUST,
    /*15*/ SPIDER_WEB,
    /*16*/ TORCH_TRAP_PROJECTILE,
    /*17*/ GURUGURU_BAR_PROJECTILE,
    /*18*/ V1_DARK_MAGIC_PROJECTILE,
    /*19*/ BALL_AND_CHAIN,
    /*1A*/ V1_FIRE_PROJECTILE,
    /*1B*/ CANNONBALL_PROJECTILE,
    /*1C*/ V1_EYE_LASER,
    /*1D*/ WINDER,
    /*1E*/ SPIKED_ROLLERS,
    /*1F*/ V2_PROJECTILE,
    /*20*/ V3_HAND_PROJECTILE,
    /*21*/ V3_ELECTRIC_PROJECTILE,
    /*22*/ GYORG_TAIL,
    /*23*/ GYORG_MALE_ENERGY_PROJECTILE,
    /*24*/ V3_TENNIS_BALL_PROJECTILE,
} Projectile;

#endif