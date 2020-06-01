import processing.serial.*;

Serial btserial;

PShape l, r, flecha;
float varin;
boolean over;
boolean click;
float pos0=2, pos1=2, pos2=2, pos3=2, pos4=2, pos5=2, pos6=2, pos7=2, pos8=2;
float datain, senIn, datasen;
String bufferin, ID="uno", ID2="dos", data, data2;


void setup() {
  btserial=new Serial(this, Serial.list()[2], 9600);

  printArray(Serial.list());
  background(20);
  size(600, 200, P2D);
  smooth();
}
/*
btserial.write("S"+pos0);
 
 
 if(btserial.available()>0)
 {bufferin=null;
 bufferin=btserial.readStringUntil('\n');
 if(bufferin!=null){
 println("ID= "+ID+" ID2= "+ID2);
 */

void draw() {

  textAlign(LEFT);
  fill(255);
  text("Arduino + HC05", 10, 20);


  textAlign(CENTER);
  text("Led", 100, 140);
  text("Servo", 400, 165);
  text("SHARP IR", 230, 35);
  text("Distancia:", 230, 80);
  fill(0);
  rectMode(CENTER);
  rect(230, 94, 58, 18);
  fill(255);
  if (senIn>80) {
    text("F.D.R", 230, 100);
  } else {
    text(int(senIn), 230, 100);
  }

  //image(img1,430,-10,200,60);
  //image(img2,0,160);
  //image(img3,448,170,150,33);

  // LED
  stroke(126);
  fill(200);
  ellipseMode(CENTER);
  if (mouseX>50 && mouseX<150 && mouseY>50 && mouseY<150)
  {
    fill(255);
  }

  if (ID2.equals("D") && senIn>20 && senIn<30) {
    fill(255, 0, 0);
  }
  if (ID2.equals("D") && (senIn>=30 || senIn<=20)) {
    fill(200);
  }
  ellipse(100, 100, 50, 50);

  //Sensor SHARP
  rectMode(CENTER);
  fill(126);
  rect(230, 50, 60, 20);
  rect(230, 60, 25, 7);
  fill(150);
  rect(230, 50, 58, 18);
  fill(0);
  ellipse(210, 50, 15, 15);
  fill(255, 0, 0);
  ellipse(250, 50, 15, 15);


  //Radar o Movimiento del Servo
  stroke(0);
  strokeWeight(3);
  //fill(56,206,56);
  fill(100);
  arc(400, 150, 200, 200, -PI, 0);
  //stroke(100,100,100);
  stroke(40);
  strokeWeight(1);
  line(400, 150, 400+(100*(cos(radians(22.5)))), 150-(100*(radians(22.5))));
  line(400, 150, 400+(100*(cos(PI/4))), 150-(100*(sin(PI/4))));
  line(400, 150, 400+(100*(cos(3*PI/8))), 150-(100*(sin(3*PI/8))));
  line(400, 150, 400+(100*(cos(PI/2))), 150-(100*(sin(PI/2))));
  line(400, 150, 400+(100*(cos(5*PI/8))), 150-(100*(sin(5*PI/8))));
  line(400, 150, 400+(100*(cos(3*PI/4))), 150-(100*(sin(3*PI/4))));
  line(400, 150, 400+(100*(cos(7*PI/8))), 150-(100*(sin(7*PI/8))));



  if (mouseX>488 && mouseX<508 && mouseY>138 && mouseY<158)
  {
    over=true;
    if (datain!=pos0) {
      fill(0, 255, 0);
    } 
    if (over && mousePressed) {
      click=true;
      pos0=180.00;
    } 
    if (click) {
      btserial.write("S"+pos0);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==180) {
    fill(255, 255, 255);
  }    
  ellipse(498, 148, 20, 20); //Elipse en 180


  if (mouseX>470 && mouseX<500 && mouseY>102 && mouseY<122)
  {
    over=true;
    if (datain!=pos1) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos1=157.50;
    } 
    if (click) {
      btserial.write("S"+pos1);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==157) {
    fill(255, 255, 255);
  }
  ellipse(490, 112, 20, 20);//Elipse en 157.5


  if (mouseX>459 && mouseX<479 && mouseY>69 && mouseY<89)
  {
    over=true;
    if (datain!=pos2) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos2=135.000;
    } 
    if (click) {
      btserial.write("S"+pos2);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==135) {
    fill(255, 255, 255);
  }
  ellipse(469, 79, 20, 20);//Elipse en 135


  if (mouseX>427 && mouseX<447 && mouseY>47 && mouseY<67)
  {
    over=true;
    if (datain!=pos3) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos3=112.500;
    } 
    if (click) {
      btserial.write("S"+pos3);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==112) {
    fill(255, 255, 255);
  }
  ellipse(437, 57, 20, 20);//Elipse en 112.5
  fill(2, 165, 0); 

  if (mouseX>390 && mouseX<410 && mouseY>40 && mouseY<60)
  {
    over=true;
    if (datain!=pos4) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos4=90.000;
    } 
    if (click) {
      btserial.write("S"+pos4);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==90) {
    fill(255, 255, 255);
  }
  ellipse(400, 50, 20, 20);// Elipse en 90

  if (mouseX>351 && mouseX<371 && mouseY>47 && mouseY<67)
  {
    over=true;
    if (datain!=pos5) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos5=67.500;
    } 
    if (click) {
      btserial.write("S"+pos5);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==67) {
    fill(255, 255, 255);
  }
  ellipse(361, 57, 20, 20);// Elipse en 67.5

  if (mouseX>319 && mouseX<339 && mouseY>69 && mouseY<89)
  {
    over=true;
    if (datain!=pos6) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos6=45;
    } 
    if (click) {
      btserial.write("S"+pos6);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==45) {
    fill(255, 255, 255);
  }
  ellipse(329, 79, 20, 20); // Elipse en 45

  if (mouseX>300 && mouseX<320 && mouseY>102 && mouseY<122)
  {
    over=true;
    if (datain!=pos6) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos7=22.5;
    } 
    if (click) {
      btserial.write("S"+pos7);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==22.5) {
    fill(255, 255, 255);
  }
  ellipse(310, 112, 20, 20);// Elipse en 22.5


  if (mouseX>291 && mouseX<311 && mouseY>138 && mouseY<158)
  {
    over=true;
    if (datain!=pos8) {
      fill(0, 255, 0);
    }
    if (over && mousePressed) {
      click=true;
      pos8=0;
    } 
    if (click) {
      btserial.write("S"+pos8);
    }
  } else {
    fill(2, 165, 0);
  }
  if (ID!=null && ID.equals("S") && datain==0) {
    fill(255, 255, 255);
  } 
  ellipse(301, 148, 20, 20);// Elipse en 0

  if (btserial.available()>0)
  {
    bufferin=null;
    bufferin=btserial.readStringUntil('\n');
    if (bufferin!=null) {
     
      println(bufferin);
    }
  }
  /*
  if (btserial.available()>0)
   {
   bufferin=null;
   bufferin=btserial.readStringUntil('\n');
   if (bufferin!=null) {
   print("WHAT CAME");
   println("ID= "+ID+" ID2= "+ID2);
   if (bufferin.substring(0, 1).equals("S")) { //S180 D29
   ID="S";
   data=bufferin.substring(1);
   float indata=float(data);
   datain=indata;
   btserial.clear();
   }
   if (bufferin.substring(0, 1).equals("D")) {
   ID2="D";
   data2=bufferin.substring(1);
   float indata2=float(data2);
   senIn=indata2;
   println(datain);
   btserial.clear();
   }
   }
   }
   */
}  


void mouseReleased() {
  over=false;
  click=false;
}
