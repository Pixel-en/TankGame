#include "BoxCollider.h"
#include "SphereCollider.h"
#include "GameObject.h"
#include "Model.h"
#include "Transform.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Collider::Collider():
	pGameObject_(nullptr)
{
}

//ƒfƒXƒgƒ‰ƒNƒ^
Collider::~Collider()
{
}

//” Œ^“¯Žm‚ÌÕ“Ë”»’è
//ˆø”FboxA	‚P‚Â–Ú‚Ì” Œ^”»’è
//ˆø”FboxB	‚Q‚Â–Ú‚Ì” Œ^”»’è
//–ß’lFÚG‚µ‚Ä‚¢‚ê‚Îtrue
bool Collider::IsHitBoxVsBox(BoxCollider* boxA, BoxCollider* boxB)
{

	XMFLOAT3 boxPosA = Transform::Float3Add(boxA->pGameObject_->GetWorldPosition(), boxA->center_);
	XMFLOAT3 boxPosB = Transform::Float3Add(boxB->pGameObject_->GetWorldPosition(), boxB->center_);


	if ((boxPosA.x + boxA->size_.x / 2) > (boxPosB.x - boxB->size_.x / 2) &&
		(boxPosA.x - boxA->size_.x / 2) < (boxPosB.x + boxB->size_.x / 2) &&
		(boxPosA.y + boxA->size_.y / 2) > (boxPosB.y - boxB->size_.y / 2) &&
		(boxPosA.y - boxA->size_.y / 2) < (boxPosB.y + boxB->size_.y / 2) &&
		(boxPosA.z + boxA->size_.z / 2) > (boxPosB.z - boxB->size_.z / 2) &&
		(boxPosA.z - boxA->size_.z / 2) < (boxPosB.z + boxB->size_.z / 2))
	{
		return true;
	}
	return false;
}

//” Œ^‚Æ‹…‘Ì‚ÌÕ“Ë”»’è
//ˆø”Fbox	” Œ^”»’è
//ˆø”Fsphere	‚Q‚Â–Ú‚Ì” Œ^”»’è
//–ß’lFÚG‚µ‚Ä‚¢‚ê‚Îtrue
bool Collider::IsHitBoxVsCircle(BoxCollider* box, SphereCollider* sphere)
{
	XMFLOAT3 circlePos = Transform::Float3Add(sphere->pGameObject_->GetWorldPosition(), sphere->center_);
	XMFLOAT3 boxPos = Transform::Float3Add(box->pGameObject_->GetWorldPosition(), box->center_);



	if (circlePos.x > boxPos.x - box->size_.x - sphere->size_.x &&
		circlePos.x < boxPos.x + box->size_.x + sphere->size_.x &&
		circlePos.y > boxPos.y - box->size_.y - sphere->size_.x &&
		circlePos.y < boxPos.y + box->size_.y + sphere->size_.x &&
		circlePos.z > boxPos.z - box->size_.z - sphere->size_.x &&
		circlePos.z < boxPos.z + box->size_.z + sphere->size_.x )
	{
		return true;
	}

	return false;
}

//‹…‘Ì“¯Žm‚ÌÕ“Ë”»’è
//ˆø”FcircleA	‚P‚Â–Ú‚Ì‹…‘Ì”»’è
//ˆø”FcircleB	‚Q‚Â–Ú‚Ì‹…‘Ì”»’è
//–ß’lFÚG‚µ‚Ä‚¢‚ê‚Îtrue
bool Collider::IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB)
{
	XMFLOAT3 centerA = circleA->center_;
	XMFLOAT3 positionA = circleA->pGameObject_->GetWorldPosition();
	XMFLOAT3 centerB = circleB->center_;
	XMFLOAT3 positionB = circleB->pGameObject_->GetWorldPosition();

	XMVECTOR v = (XMLoadFloat3(&centerA) + XMLoadFloat3(&positionA))
		- (XMLoadFloat3(&centerB) + XMLoadFloat3(&positionB));

	if (XMVector3Length(v).m128_f32[0] <= circleA->size_.x + circleB->size_.x)
	{
		return true;
	}

	return false;
}

//ƒeƒXƒg•\Ž¦—p‚Ì˜g‚ð•`‰æ
//ˆø”Fposition	ƒIƒuƒWƒFƒNƒg‚ÌˆÊ’u
void Collider::Draw(XMFLOAT3 position)
{
	Transform transform;
	transform.position_ = XMFLOAT3(position.x + center_.x, position.y + center_.y, position.z + center_.z);
	transform.scale_ = size_;
	transform.Calclation();
	Model::SetTransform(hDebugModel_, transform);
	Model::Draw(hDebugModel_);


	//transform.rotate_ = pGameObject_->GetRotate();
	//Model::SetTransform(hDebugModel_, transform);
	//Model::Draw(hDebugModel_);
}
