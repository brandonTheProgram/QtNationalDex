#include "Moveset.h"

Moveset::Moveset(){}

Moveset::Moveset(const vector<Attack>& ATTACK_DEX, const vector<string>& MOVES,
                 const vector<unsigned int>& LVLS){
    unsigned int index      = 0;
    unsigned int levelIndex = 0;
    auto         size       = ATTACK_DEX.size();
    bool         found      = false;

    LvlAttack newAttack;

     //PROCESSING - for every move that the Pokemon has, find it in the
     //			   attackdex and store it as a TM move or a level move
     for(auto moveIt: MOVES){
         while(!found && (index != unsigned(size))){
             if(!(ATTACK_DEX[index].name.compare(moveIt))){

                 //If the move found is a TM or TR, store it
                 if((ATTACK_DEX[index].TM == 1 ||
                     ATTACK_DEX[index].TR == 1) && (LVLS[levelIndex] == 0)){
                     this->TMMoveset.push_back(ATTACK_DEX[index]);
                 }
                 //If the move is a level move, then store the level and attack
                 else{
                     newAttack.attack = ATTACK_DEX[index];
                     newAttack.lvl    = LVLS      [levelIndex];

                     this->lvlMoveset.push_back(newAttack);

                     levelIndex++;
                 }

                 found = true;
             }
             else{
                 ++index;
             }
         }
         index = 0;
         found = false;
     }
}

Moveset::~Moveset(){
    vector<LvlAttack>().swap(this->lvlMoveset);
    vector<Attack>   ().swap(this->TMMoveset);

    this->lvlMoveset.clear();
    this->TMMoveset .clear();
}

void Moveset::InitializeMoveSets(const vector<Attack>& ATTACK_DEX,
                                 const vector<string>& MOVES,
                                 const vector<unsigned int>& LVLS){
     unsigned int index      = 0;
     unsigned int levelIndex = 0;
     auto         size       = ATTACK_DEX.size();
     bool         found      = false;

     LvlAttack newAttack;

     //PROCESSING - for every move that the Pokemon has, find it in the
     //			   attackdex and store it as a TM move or a level move
     for(auto moveIt: MOVES){
         while(!found && (index != unsigned(size))){
             if(!(ATTACK_DEX[index].name.compare(moveIt))){

                 //If the move found is a TM or TR, store it
                 if((ATTACK_DEX[index].TM == 1 ||
                     ATTACK_DEX[index].TR == 1) && (LVLS[levelIndex] == 0)){
                     this->TMMoveset.push_back(ATTACK_DEX[index]);
                 }
                 //If the move is a level move, then store the level and attack
                 else{
                     newAttack.attack = ATTACK_DEX[index];
                     newAttack.lvl    = LVLS      [levelIndex];

                     this->lvlMoveset.push_back(newAttack);

                     levelIndex++;
                 }

                 found = true;
             }
             else{
                 ++index;
             }
         }

         if(!found){
             std::cout <<moveIt.data() << " was not found, check input data\n\n";
         }

         index = 0;
         found = false;
     }
}

QString Moveset::PrintTM() const{
    using namespace movesetGlobalConsts;

    QString s;

    QTextStream out(&s);

    QString tm;

    out << left;

    //If the Pokemon knows TM moves, then output them
    if(!TMMoveset.empty()){
        out << "TM/TR Attacks\n\n";

        out << qSetFieldWidth(LVL_COL)    << "TM/TR #"     << " "
            << qSetFieldWidth(NAME_COL)   << "Attack Name" << " "
            << qSetFieldWidth(TYPE_COL)   << "Type"		   << " "
            << qSetFieldWidth(CAT_COL)    << "Cat."		   << " "
            << qSetFieldWidth(ATK_COL)    << "Att."		   << " "
            << qSetFieldWidth(ACC_COL)    << "Acc."		   << " "
            << qSetFieldWidth(PP_COL)     << "PP"	       << " "
            << qSetFieldWidth(EFFECT_COL) << "Effect %";

        out << endl << endl;

        for(auto it: TMMoveset){
            //Punctuate the TM number
            if(it.TMNum < 10 && it.TM){
                tm = ("TM0" + QString::number(it.TMNum));
            }
            else if(it.TM){
                tm = ("TM"  + QString::number(it.TMNum));
            }
            else if(it.TRNum < 10 && it.TR){
                tm = ("TR0" + QString::number(it.TRNum));
            }
            else{
                tm = ("TR"  + QString::number(it.TRNum));
            }

            out << qSetFieldWidth(LVL_COL)    << tm
                << " "
                << qSetFieldWidth(NAME_COL)   << QString::fromStdString(it.name)
                << " "
                << qSetFieldWidth(TYPE_COL)   << QString::fromStdString(it.type)
                << " "
                << qSetFieldWidth(CAT_COL)<< QString::fromStdString(it.category)
                << " "
                << qSetFieldWidth(ATK_COL)    << it.pwr		 << " "
                << qSetFieldWidth(ACC_COL)    << it.acc		 << " "
                << qSetFieldWidth(PP_COL)     << it.pp		 << " "
                << qSetFieldWidth(EFFECT_COL) << it.effRate	 << " " << endl;

            out << qSetFieldWidth(DES_COL) << "  "
                << QString::fromStdString(it.desc) << endl << endl;
        }

        out << endl;
    }

    out << right << qSetFieldWidth(0);

    return out.readAll();
}

QString Moveset::PrintLvl() const
{
    using namespace movesetGlobalConsts;

    QString s;

    QTextStream out(&s);

    out << left;

    //If the Pokemon knows moves by leveling up, then output them
    if(!lvlMoveset.empty()){
        out << endl << endl << (GENERATION) << " Level Up\n\n";

        out << qSetFieldWidth(LVL_COL)    << "Level"        << " "
            << qSetFieldWidth(NAME_COL)   << "Attack Name"  << " "
            << qSetFieldWidth(TYPE_COL)   << "Type"		  << " "
            << qSetFieldWidth(CAT_COL)    << "Cat."		  << " "
            << qSetFieldWidth(ATK_COL)    << "Att."		  << " "
            << qSetFieldWidth(ACC_COL)    << "Acc."		  << " "
            << qSetFieldWidth(PP_COL)     << "PP"			  << " "
            << qSetFieldWidth(EFFECT_COL) << "Effect %";

        out << endl << endl;

        for(auto it: lvlMoveset){

            out << qSetFieldWidth(LVL_COL)    << it.lvl                 << " "
                << qSetFieldWidth(NAME_COL)
                        << QString::fromStdString(it.attack.name)	    << " "
                << qSetFieldWidth(TYPE_COL)
                        << QString::fromStdString(it.attack.type)	    << " "
                << qSetFieldWidth(CAT_COL)
                        << QString::fromStdString(it.attack.category)   << " "
                << qSetFieldWidth(ATK_COL)
                        << it.attack.pwr                                << " "
                << qSetFieldWidth(ACC_COL)
                        << it.attack.acc                                << " "
                << qSetFieldWidth(PP_COL)
                        << it.attack.pp                                 << " "
                << qSetFieldWidth(EFFECT_COL)
                        << it.attack.effRate                            << endl;

            out << qSetFieldWidth(DES_COL) << " "
                << QString::fromStdString(it.attack.desc) << endl << endl;
        }

        out << endl;
    }

    out << right << qSetFieldWidth(0);

    return out.readAll();
}
