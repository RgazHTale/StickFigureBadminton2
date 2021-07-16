import QtQuick 2.0
import Felgo 3.0
import "../scenes"


EntityBase {
    id:score
    entityType: "score"
    width: 150
    height: 50

    property int score1: 0
    property int score2: 0

    Image {
        id: background
        source: "../../assets/res/s.png"
        anchors.fill: parent
    }

    Row{
        id:row
        anchors.centerIn: parent

        Text {
            id: textScore1
            text: score1
            color: "red"
            font.pixelSize: 50
        }

        Text{
            text: "-"
            color: "red"
            font.pixelSize: 50
        }

        Text{
            id: textScore2
            text: score2
            color: "red"
            font.pixelSize: 50
        }
    }

    //判定获胜者
    function compare(){
        if(score1 > score2){
            player = "player1";
            champion= "The winner is player1";
        }
        if(score1 < score2){
            player = "player2";
           champion= "The winner is player2";
        }
        if(score1 == score2){
            champion = "Dogfall!";
        }
    }
}
