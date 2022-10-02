#include "Misc.hpp"
#include "../../Utils/Output/Output.hpp"

void Misc::SetRank(int rank) {
    Players::LocalPlayer->GetComponent("NolanRankController")->CallMethodSafe<void*>("SetRank", rank);
}

void Misc::WalkInlobby(bool walk) {
    /*
    if (!Players::LocalPlayer->GetComponent("UltimateCharacterLocomotionHandler")) {
        Unity::il2cppClass* Character = IL2CPP::Class::Find("Opsive.UltimateCharacterController.Character::UltimateCharacterLocomotionHandler");
        Unity::CGameObject* UltimateCharacterLocomotionHandler =
        if (!UltimateCharacterLocomotionHandler) {
            return;
        }

        Players::LocalPlayer->AddComponent(UltimateCharacterLocomotionHandler);
    }
    */
}

void Misc::UnlimitedUV(bool active) {
    try {
        Unity::CComponent* NolanBehaviour = Players::LocalPlayer->GetComponent("NolanBehaviour");
        if (!NolanBehaviour) {
            return;
        }
        NolanBehaviour->CallMethodSafe<void*>("SetPurgatory", active);
    }
    catch (...) {
        settings::unlimited_uv = false;
        print("Unlimited UV error");
    }
}

void Misc::SetSteamName(std::string name) {
    Unity::CGameObject* MenuController = Unity::GameObject::Find("MenuController");
    if (!MenuController) {
        return;
    }

    Unity::CComponent* Menu = MenuController->GetComponent("Horror.Menu");
    if (!Menu) {
        return;
    }

    Menu->SetMemberValue<Unity::System_String*>("steamName", IL2CPP::String::New(name));
}

void Misc::SetServerName(std::string name) {
    Unity::CGameObject* MenuController = Unity::GameObject::Find("MenuController");
    if (!MenuController) {
        return;
    }

    Unity::CComponent* Menu = MenuController->GetComponent("Horror.Menu");
    if (!Menu) {
        return;
    }

    Unity::CComponent* serverNameText = Menu->GetMemberValue<Unity::CComponent*>("serverNameText");
    if (!serverNameText) {
        return;
    }

    serverNameText->SetMemberValue<Unity::System_String*>("m_Text", IL2CPP::String::New(name));
}
