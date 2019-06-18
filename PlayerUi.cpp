/*=============================================================================



-------------------------------------------------------------------------------
	���@�����
		�����

	���@�쐬��
		2017/08/30
------------------------------------------------------------------------------- 
	���@�X�V��
		2017/08/30
=============================================================================*/

/*-----------------------------------------------------------------------------
	�w�b�_�t�@�C��
-----------------------------------------------------------------------------*/
#include "DirectX.h"
#include "TextureManager.h"
#include "Mode.h"
#include "GameScene.h"
#include "Scene.h"
#include "Sprite2D.h"
#include "PlayerUi.h"

#define MAX_POS (470.0f)

/*-----------------------------------------------------------------------------
�֐���:		CPlayerUI* CPlayerUI::Create(int Priolity)
����:
�߂�l:		return ground;	�N���X�̃|�C���^
����:		����
-----------------------------------------------------------------------------*/
CPlayerUI* CPlayerUI::Create(int Priolity)
{
	CPlayerUI* playerui;

	playerui = new CPlayerUI(Priolity);

	playerui->Init();

	return playerui;
}

/*-----------------------------------------------------------------------------
�֐���:		void CPlayerUI::Init(void)
����:
�߂�l:
����:		������
-----------------------------------------------------------------------------*/
void CPlayerUI::Init(void)
{
	CSprite2D::Init();

	CSprite2D::SetAnimationTime(0.15f);
}

/*-----------------------------------------------------------------------------
�֐���:		void CPlayerUI::Uninit(void)
����:
�߂�l:
����:		�I��
-----------------------------------------------------------------------------*/
void CPlayerUI::Uninit(void)
{
	CSprite2D::Uninit();
}

/*-----------------------------------------------------------------------------
�֐���:		void CTruck::Update(void)
����:
�߂�l:
����:		�X�V
-----------------------------------------------------------------------------*/
void CPlayerUI::Update(void)
{
	D3DXVECTOR3 pos = CScene::GetPosition();

	pos.y += 0.15f;

	if (pos.y > MAX_POS)
	{
		pos.y = MAX_POS;
		CGameScene::GameClear();
	}

	CScene::SetPosition(pos);

	CSprite2D::TextureAnimation();

	CSprite2D::Update();
}

/*-----------------------------------------------------------------------------
�֐���:		void CTruck::Draw(void)
����:
�߂�l:
����:		�`��
-----------------------------------------------------------------------------*/
void CPlayerUI::Draw(void)
{
	CSprite2D::Draw();
}