/**
 * @file itemForSale.c
 * @ingroup Objects
 *
 * @brief Item for Sale object
 */

#define NENT_DEPRECATED
#include "global.h"
#include "object.h"
#include "functions.h"
#include "hitbox.h"
#include "new_player.h"
#include "message.h"
#include "kinstone.h"

typedef struct {
    /*0x00*/ Entity base;
    /*0x68*/ u8 unk_68[0x18];
    /*0x80*/ u16 unk_80;
    /*0x82*/ u16 unk_82;
} ItemForSaleEntity;

typedef struct {
    u8 before[0x20];
    u8 unk_20[0x4]; // TODO for Entity this is zVelocity which is not an array. spriteAnimation[super->field_0xf-6] does
                    // not match.
} ModifiedParentEntity;

extern u32 sub_080787D8(Entity*);
extern void* sub_080784E4(void);

void ItemForSale_Init(ItemForSaleEntity*);
void ItemForSale_Action1(ItemForSaleEntity*);
void ItemForSale_Action2(ItemForSaleEntity*);
void ItemForSale_Action3(ItemForSaleEntity*);
void sub_08081A5C(ItemForSaleEntity*);
void sub_080819B4(ItemForSaleEntity*);
void sub_08081AB0(void);

void ItemForSale(ItemForSaleEntity* this) {
    static void (*const ItemForSale_Actions[])(ItemForSaleEntity*) = {
        ItemForSale_Init,
        ItemForSale_Action1,
        ItemForSale_Action2,
        ItemForSale_Action3,
    };
    ItemForSale_Actions[super->action](this);
    if (CheckOnScreen(super)) {
        sub_08080CB4(super);
    }
    switch (super->actionDelay) {
        case 1:
        case 2:
            if (super->action == 1) {
                sub_0800445C(super);
            }
            break;
        case 0:
        case 3:
            break;
    }
}

void ItemForSale_Init(ItemForSaleEntity* this) {
    super->action = 1;
    super->spriteSettings.draw = 1;
    super->spritePriority.b1 = 0;
    super->field_0x16 = 0;
#ifdef EU
    SetDefaultPriority(super, 6);
#endif
    super->child = super;
    sub_08081A5C(this);
    switch (super->actionDelay) {
        case 0:
            super->hitbox = (Hitbox*)&gUnk_080FD328;
            break;
        case 1:
            super->hitbox = (Hitbox*)&gHitbox_5;
            break;
    }
}

void ItemForSale_Action1(ItemForSaleEntity* this) {
    if (super->subAction != 0) {
        super->action = 2;
        gUnk_0200AF00.filler25[10] = 2;
    } else {
        if (super->type == 0x36) {
            if (super->interactType != 0) {
                super->interactType = 0;
                super->action = 3;
                gRoomVars.animFlags = 1;
                gPlayerState.queued_action = 7;
            }
        } else {
            if (super->interactType != 0) {
                super->interactType = 0;
                super->subAction = 1;
                sub_08078B48();
                ResetPlayer();
                gPlayerState.heldObject = 4;
                gNewPlayerEntity.unk_74 = super;
                gUnk_0200AF00.filler25[10] = 2;
                MessageClose();
            }
        }
    }
}

void ItemForSale_Action2(ItemForSaleEntity* this) {
    void* ptr;

    gUnk_0200AF00.filler25[10] = 2;
    super->spriteSettings.draw = gPlayerEntity.spriteSettings.draw;
    if ((gPlayerState.heldObject == 0) || (super != gNewPlayerEntity.unk_74)) {
        sub_080819B4(this);
    } else {
        ptr = sub_080784E4();
        if (((*(int*)(ptr + 8) == 0) ||
             ((*(u8*)(ptr + 1) != 1 || (gUnk_0200AF00.filler25[10] = 7, (gPlayerState.field_0x92 & 0x88) == 0)))) &&
            ((gPlayerState.field_0x92 & 0x98) != 0)) {
            sub_080819B4(this);
        }
    }
}

void sub_080819B4(ItemForSaleEntity* this) {
    Entity* parent;
    u8* puVar2;
    struct_0200AF00* ptr;

    if (gRoomVars.shopItemType == 0) {
        if (super->parent != NULL) {
            ((ModifiedParentEntity*)super->parent)->unk_20[super->field_0xf] = 0xff;
        }
        DeleteThisEntity();
    }
    gPlayerState.heldObject = 0;
    gNewPlayerEntity.unk_74 = 0;
    ptr = &gUnk_0200AF00;
    gRoomVars.shopItemType = 0;
    ptr->filler25[7] = 0;
    ptr->filler25[10] = 0;
    gRoomVars.shopItemType2 = 0;
    super->x.HALF.HI = this->unk_80 + gRoomControls.origin_x;
    super->y.HALF.HI = this->unk_82 + gRoomControls.origin_y;
    super->z.WORD = 0;
    super->action = 1;
    super->subAction = 0;
    super->spriteOrientation.flipY = gPlayerEntity.spriteOrientation.flipY;
    super->collisionLayer = 1;
    super->spritePriority.b0 = 4;
    UpdateSpriteForCollisionLayer(super);
    sub_08081A5C(this);
}

void sub_08081A5C(ItemForSaleEntity* this) {
    u32 tmp = sub_080787D8(super);
    if (super->actionDelay == 1) {
        gUnk_03003DF0[tmp].unk4[2] = 0;
    }
}

void ItemForSale_Action3(ItemForSaleEntity* this) {
    if (gRoomVars.animFlags == 0) {
        sub_08081AB0();
        DeleteThisEntity();
    } else if (gRoomVars.animFlags == 2) {
        super->action = 1;
        super->subAction = 0;
        sub_08081AB0();
    }
}

void sub_08081AB0(void) {
    gRoomVars.animFlags = 0;
    gRoomVars.shopItemType = 0;
    gRoomVars.shopItemType2 = 0;
    SetPlayerControl(CONTROL_ENABLED);
}