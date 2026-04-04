use <smooth_prim.scad>

$fn=50;

board_extra_size = 1;
board_height = 14;
board_width = board_extra_size*2+53.5;
board_length = board_extra_size*2+75;
case_extra_width = 4; // the side width will be the half of this value
keycap_length = 19;
switches_box_length = 14.2;
encoder_box_length = 12.2;
display_box = [22.6,5.8,20];
usb_c = [11,16.5,case_extra_width];


difference() {
    translate([-(board_length+case_extra_width)/2,-(board_width+case_extra_width)/2,-((board_height+case_extra_width)/2)]) {
    SmoothXYCube([board_length+case_extra_width,board_width+case_extra_width,board_height+case_extra_width],3);
    };
    translate([0,0,-case_extra_width/2]){
    cube([board_length,board_width,board_height+case_extra_width],center = true);}
    color("green"){
    for (x = [-1:2:1]){
        for (y = [-1:2:1]) {
            translate([((board_length/2)-3.5-board_extra_size)*x,((board_width/2)-6.5-board_extra_size)*y,0]){
                cylinder(h=board_height+case_extra_width*2+1,d=3.4,center=true);
    }}}
    translate([0,(board_width/2 - board_extra_size)-keycap_length,0]){
    union(){
    for (x = [-1:1]){
        for (y = [-1:2:1]) {
            translate([keycap_length*x,(keycap_length/2)*y,0]){
                cube([switches_box_length,switches_box_length,board_height+case_extra_width*2+1],center=true);
    }}}}}
    translate([-(board_length/2 - 17.5 - board_extra_size),-((board_width/2)-7.5 - board_extra_size),0]){
    cube([encoder_box_length,encoder_box_length,board_height+case_extra_width*2+1],center=true);
    }
    translate([(board_length/2 - 16.1 - board_extra_size - display_box[0]/2),-(board_width/2-display_box[1]/2-2.5-board_extra_size),0]){
    cube(display_box,center=true);
    }
    }
    color("red"){
    translate([board_length/2-29.5-board_extra_size,-board_width/2,board_height/2+(case_extra_width/2)-20.1]){
    rotate([90,0,180]){
    translate([-1,-1.5,-case_extra_width/2]){
    SmoothXYCube(usb_c,2){}}}}}
}
