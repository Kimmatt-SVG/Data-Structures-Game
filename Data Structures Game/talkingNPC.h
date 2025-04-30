#ifndef TALKINGNPC_H
#define TALKINGNPC_H

#include <string>
#include <vector>
class dialogueNode {
public:
    std::string NPCDialogue;
    std::string playerChoices;
    std::vector<int> nextDialogues;
    dialogueNode(std::string npcTalk = "", std::string playerChoiceList = "", std::vector<int> nextList = {})
        : NPCDialogue(npcTalk), playerChoices(playerChoiceList), nextDialogues(nextList) {}
};
class talkingNPC {
public:
    std::string name;
    std::vector<dialogueNode> dialogueTree;
    talkingNPC(std::string npcName = "", int treeSize = 0) : name(npcName) {
        dialogueTree.resize(treeSize);
    }
    void printDialogue(int currentDialogue);
};

class roadsideBeggar : public talkingNPC {
public:
    roadsideBeggar() : talkingNPC("Roadside Beggar", 4) {
        dialogueTree[0] = dialogueNode(
            "Spare some coins for a poor lad?",
            "0. Give 10 gold\n1. Ignore him\n2. Threaten him",
            { 1, 2, 3 }
        );

        dialogueTree[1] = dialogueNode(
            "Thank you, kind soul! May God bless you!",
            "0. Walk away",
            { -1 } // End of dialogue
        );

        dialogueTree[2] = dialogueNode(
            "WAAAAAAHHHH",
            "0. Walk away from the deranged lad",
            { -1 } // End of dialogue
        );

        dialogueTree[3] = dialogueNode(
            "You dare threaten me? IMMA CRY!",
            "0. Apologize\n1. Continue threatening",
            { 1, 2 }
        );
    }
};

#endif 
