#include "talkingNPC.h"
#include <iostream>

void talkingNPC::printDialogue(int currentDialogue) {
    if (currentDialogue < 0 || currentDialogue >= dialogueTree.size()) {
        std::cout << "Dialogue ended.\n";
        return;
    }

    dialogueNode& node = dialogueTree[currentDialogue];
    std::cout << name << ": " << node.NPCDialogue << "\n";
    std::cout << node.playerChoices << "\n";

    int choice;
    std::cin >> choice;

    if (choice >= 0 && choice < node.nextDialogues.size()) {
        printDialogue(node.nextDialogues[choice]);
    }
    else {
        std::cout << "Invalid choice. Dialogue ended.\n";
    }
}