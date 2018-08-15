<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="refresh" content="3">
<style>
.item1 { grid-area: header; }
.item2 { grid-area: menu; }
.item3 { grid-area: main; }
.item4 { grid-area: right; }
.item5 { grid-area: footer; }

.grid-container {
  display: grid;
  grid-template-areas:
    'header header header header header header'
    'menu main main main right right'
    'menu footer footer footer footer footer';
  grid-gap: 10px;
  background-color: #2196F3;
  padding: 10px;
}
.grid-container > div {
  background-color: yellow;
  text-align: center;
  padding: 20px 0;
  font-size: 30px;
}

h1{text-align: center;
	text-shadow: 3px 2px red;}
</style>
</head>
<body>

<h1>HEALTH MONITORING SYSTEM</h1>


<p>This contains pulse rate blood pressure Ecg reading </p>

<div class="grid-container">
  <div class="item1"><img src="image2.jpg" alt="Mountain View" width="250" height="200">
  
 
 </div>
<div class="item2">
<?php
$myfile = fopen("b.txt", "r") or die("Unable to open file!");
// Output one line until end-of-file
  echo fgets($myfile) . "<br>";
fclose($myfile);
?>
<br ><p2 style="color:blue;">The optimum value of BP is <br>SYS 100-85 DIA 110-130</p2></br>
</div>
  <div class="item3"><?php
$myfile = fopen("p.txt", "r") or die("Unable to open file!");
// Output one line until end-of-file
  echo fgets($myfile) . "<br>";
fclose($myfile);
?>
<br><p2 style="color:blue;">The optimum value of<br>pulse is 70-85</p2>
</div>  
  <div class="item4">
	  
<?php
$myfile = fopen("e.txt", "r") or die("Unable to open file!");
// Output one line until end-of-file
  echo fgets($myfile) . "<br>";
fclose($myfile);
?>
<br><p2 style="color:blue;">The optimum value of ECG is 600-700</p2>
</div>
  <div class="item5">
  <?php
$myfile = fopen("r.txt", "r") or die("Unable to open file!");
// Output one line until end-of-file
  echo fgets($myfile) . "<br>";
fclose($myfile);
?>
  </div>
</div>

</body>
</html>
