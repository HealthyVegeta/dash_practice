# dash_practice
언리얼의 기본 캐릭터를 이용하여 대쉬를 구현하는 C++ 프로젝트입니다.

## Preview
![Dash](./images/dash_anim.gif)

## Dash 기능구현

```
void ADashCharacter::Dash()
{
  if ((Controller != nullptr) && !OnDash)
  {
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    
    GetCharacterMovement()->BrakingFrictionFactor = 0.f;
    LaunchCharacter(Direction * DashDistance, true, true);
    OnDash = true;
    GetWorldTimerManager().SetTimer(UnusedHandle, this, &ADashCharacter::StopDashing, 0.1f, false);
  }
}
```

* `LaunchCharacter()` 함수를 이용해 dash 구현.
* `GetWorldTimerManager().SetTimer()` 를 통해 StopDashing 함수를 호출하도록 함.
* 항상 동일한 이동을 의도하여 `BrakingFrictionFactor` 를 0으로 두어 마찰력 제어.

```
void ADashCharacter::StopDashing() {
  GetCharacterMovement()->StopMovementImmediately();
  GetWorldTimerManager().SetTimer(UnusedHandle, this, &ADashCharacter::ResetDash, 0.2f, false);
  GetCharacterMovement()->BrakingFrictionFactor = 2.f;
}
```

* `StopMovementImmediately()` 함수를 이용해 움직임 제어.
* `GetWorldTimerManager().SetTimer()` 를 통해 ResetDash 함수를 호출하여 `OnDash` Property를 `false` 로 변경.


## Dash 애니메이션 구현

![image](https://user-images.githubusercontent.com/12293789/116813961-71a24680-ab91-11eb-82e0-52be2e000b17.png)

* 기본 Run 애니메이션의 특정 모션을 추출하여 Pose_Asset으로 만든 뒤 다시 애니메이션으로 생성


![image](https://user-images.githubusercontent.com/12293789/116815083-d9a75b80-ab96-11eb-99ef-fb9a240c38db.png)

* 애니메이션 블루프린트의 이벤트 그래프에 OnDash value 상태구현

![image](https://user-images.githubusercontent.com/12293789/116815126-11ae9e80-ab97-11eb-8fc1-69099cb11af5.png)

* OnDash 를 이용하여 Dash State 구현

