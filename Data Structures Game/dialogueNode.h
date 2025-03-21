#ifndef DIALOGUENODE_H
#define DIALOGUENODE_H

#include <string>
#include <vector>

class dialogueNode {
public:
    std::string NPCDialogue;
    std::string playerChoices;
    std::vector<int> nextDialogues;

    // Constructor
    dialogueNode(std::string npcTalk = "", std::string playerChoiceList = "", std::vector<int> nextList = {})
        : NPCDialogue(npcTalk), playerChoices(playerChoiceList), nextDialogues(nextList) {}
};

#endif 
