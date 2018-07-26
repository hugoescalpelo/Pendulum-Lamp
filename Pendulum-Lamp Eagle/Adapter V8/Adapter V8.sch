<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="con-3m" urn="urn:adsk.eagle:library:119">
<description>&lt;b&gt;3M Connectors&lt;/b&gt;&lt;p&gt;
PCMCIA-CompactFlash Connectors&lt;p&gt;
Zero Insertion Force Socked&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="PAK100/2500-14" urn="urn:adsk.eagle:footprint:5513/1" library_version="1">
<description>&lt;b&gt;3M (TM) Pak 100 4-Wall Header&lt;/b&gt; Straight&lt;p&gt;
Source: 3M</description>
<wire x1="-12.54" y1="4.2" x2="-6.963" y2="4.2" width="0.2032" layer="21"/>
<wire x1="-6.963" y1="4.2" x2="-3.197" y2="4.2" width="0.2032" layer="21"/>
<wire x1="-3.197" y1="4.2" x2="3.197" y2="4.2" width="0.2032" layer="21"/>
<wire x1="3.197" y1="4.2" x2="6.963" y2="4.2" width="0.2032" layer="21"/>
<wire x1="6.963" y1="4.2" x2="12.54" y2="4.2" width="0.2032" layer="21"/>
<wire x1="12.54" y1="4.2" x2="12.54" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="12.54" y1="-4.2" x2="7.208" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="7.208" y1="-4.2" x2="7.208" y2="-3.9" width="0.2032" layer="21"/>
<wire x1="7.208" y1="-3.9" x2="5.729" y2="-3.9" width="0.2032" layer="21"/>
<wire x1="5.729" y1="-3.9" x2="5.729" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="5.729" y1="-4.2" x2="1.883" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="1.883" y1="-4.2" x2="1.883" y2="-2.65" width="0.2032" layer="21"/>
<wire x1="1.883" y1="-2.65" x2="-1.883" y2="-2.65" width="0.2032" layer="21"/>
<wire x1="-1.883" y1="-2.65" x2="-1.883" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="1.883" y1="-4.2" x2="-1.883" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="-1.883" y1="-4.2" x2="-12.54" y2="-4.2" width="0.2032" layer="21"/>
<wire x1="-12.54" y1="-4.2" x2="-12.54" y2="4.2" width="0.2032" layer="21"/>
<wire x1="-11.415" y1="3.275" x2="-6.97" y2="3.275" width="0.2032" layer="21"/>
<wire x1="-3.195" y1="3.275" x2="3.195" y2="3.275" width="0.2032" layer="21"/>
<wire x1="6.97" y1="3.275" x2="11.415" y2="3.275" width="0.2032" layer="21"/>
<wire x1="11.415" y1="3.275" x2="11.415" y2="-3.275" width="0.2032" layer="21"/>
<wire x1="11.415" y1="-3.275" x2="1.883" y2="-3.275" width="0.2032" layer="21"/>
<wire x1="-1.883" y1="-3.275" x2="-11.415" y2="-3.275" width="0.2032" layer="21"/>
<wire x1="-11.415" y1="-3.275" x2="-11.415" y2="3.275" width="0.2032" layer="21"/>
<wire x1="-6.963" y1="4.2" x2="-6.963" y2="2.65" width="0.2032" layer="21"/>
<wire x1="-6.963" y1="2.65" x2="-3.197" y2="2.65" width="0.2032" layer="21"/>
<wire x1="-3.197" y1="2.65" x2="-3.197" y2="4.2" width="0.2032" layer="21"/>
<wire x1="3.197" y1="4.2" x2="3.197" y2="2.65" width="0.2032" layer="21"/>
<wire x1="3.197" y1="2.65" x2="6.963" y2="2.65" width="0.2032" layer="21"/>
<wire x1="6.963" y1="2.65" x2="6.963" y2="4.2" width="0.2032" layer="21"/>
<pad name="1" x="-7.62" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="2" x="-7.62" y="1.27" drill="1" diameter="1.4224"/>
<pad name="3" x="-5.08" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="4" x="-5.08" y="1.27" drill="1" diameter="1.4224"/>
<pad name="5" x="-2.54" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="6" x="-2.54" y="1.27" drill="1" diameter="1.4224"/>
<pad name="7" x="0" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="8" x="0" y="1.27" drill="1" diameter="1.4224"/>
<pad name="9" x="2.54" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="10" x="2.54" y="1.27" drill="1" diameter="1.4224"/>
<pad name="11" x="5.08" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="12" x="5.08" y="1.27" drill="1" diameter="1.4224"/>
<pad name="13" x="7.62" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="14" x="7.62" y="1.27" drill="1" diameter="1.4224"/>
<text x="-12.7" y="4.572" size="1.27" layer="25">&gt;NAME</text>
<text x="-5.08" y="4.572" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="PAK100/2500-5-14" urn="urn:adsk.eagle:footprint:5512/1" library_version="1">
<description>&lt;b&gt;3M (TM) Pak 100 4-Wall Header&lt;/b&gt; Right Angle&lt;p&gt;
Source: 3M</description>
<wire x1="12.54" y1="1.875" x2="12.54" y2="11.075" width="0.2032" layer="21"/>
<wire x1="12.54" y1="11.075" x2="5.938" y2="11.075" width="0.2032" layer="21"/>
<wire x1="4.459" y1="11.075" x2="5.938" y2="11.075" width="0.2032" layer="21"/>
<wire x1="5.938" y1="11.075" x2="5.938" y2="10.105" width="0.2032" layer="21"/>
<wire x1="5.938" y1="10.105" x2="4.459" y2="10.105" width="0.2032" layer="21"/>
<wire x1="4.459" y1="10.105" x2="4.459" y2="11.075" width="0.2032" layer="21"/>
<wire x1="4.459" y1="11.075" x2="1.883" y2="11.075" width="0.2032" layer="21"/>
<wire x1="1.883" y1="11.075" x2="1.883" y2="4.01" width="0.2032" layer="21"/>
<wire x1="1.883" y1="4.01" x2="-1.883" y2="4.01" width="0.2032" layer="21"/>
<wire x1="-1.883" y1="4.01" x2="-1.883" y2="11.075" width="0.2032" layer="21"/>
<wire x1="1.883" y1="11.075" x2="-1.883" y2="11.075" width="0.2032" layer="21"/>
<wire x1="-1.883" y1="11.075" x2="-12.54" y2="11.075" width="0.2032" layer="21"/>
<wire x1="-12.54" y1="11.075" x2="-12.54" y2="1.875" width="0.2032" layer="21"/>
<wire x1="-8.996" y1="1.875" x2="-12.54" y2="1.875" width="0.2032" layer="21"/>
<wire x1="8.979" y1="1.875" x2="-8.992" y2="1.875" width="0.2032" layer="51"/>
<wire x1="12.54" y1="1.875" x2="8.983" y2="1.875" width="0.2032" layer="21"/>
<pad name="1" x="-7.62" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="2" x="-7.62" y="1.27" drill="1" diameter="1.4224"/>
<pad name="3" x="-5.08" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="4" x="-5.08" y="1.27" drill="1" diameter="1.4224"/>
<pad name="5" x="-2.54" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="6" x="-2.54" y="1.27" drill="1" diameter="1.4224"/>
<pad name="7" x="0" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="8" x="0" y="1.27" drill="1" diameter="1.4224"/>
<pad name="9" x="2.54" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="10" x="2.54" y="1.27" drill="1" diameter="1.4224"/>
<pad name="11" x="5.08" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="12" x="5.08" y="1.27" drill="1" diameter="1.4224"/>
<pad name="13" x="7.62" y="-1.27" drill="1" diameter="1.4224"/>
<pad name="14" x="7.62" y="1.27" drill="1" diameter="1.4224"/>
<text x="-12.7" y="-3.81" size="1.27" layer="25">&gt;NAME</text>
<text x="-5.08" y="-3.81" size="1.27" layer="27">&gt;VALUE</text>
<polygon width="0.2032" layer="21">
<vertex x="-8.9" y="10.945"/>
<vertex x="-6.35" y="10.945"/>
<vertex x="-7.625" y="8.37"/>
</polygon>
</package>
</packages>
<packages3d>
<package3d name="PAK100/2500-14" urn="urn:adsk.eagle:package:5575/1" type="box" library_version="1">
<description>3M (TM) Pak 100 4-Wall Header Straight
Source: 3M</description>
<packageinstances>
<packageinstance name="PAK100/2500-14"/>
</packageinstances>
</package3d>
<package3d name="PAK100/2500-5-14" urn="urn:adsk.eagle:package:5577/1" type="box" library_version="1">
<description>3M (TM) Pak 100 4-Wall Header Right Angle
Source: 3M</description>
<packageinstances>
<packageinstance name="PAK100/2500-5-14"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINV" urn="urn:adsk.eagle:symbol:5508/1" library_version="1">
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="-3.81" y="2.667" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="0" y1="-0.254" x2="2.794" y2="0.254" layer="94"/>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="PIN" urn="urn:adsk.eagle:symbol:5509/1" library_version="1">
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<rectangle x1="0" y1="-0.254" x2="2.794" y2="0.254" layer="94"/>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="2514-" urn="urn:adsk.eagle:component:5614/1" prefix="X" library_version="1">
<description>&lt;b&gt;3M (TM) Pak 100 4-Wall Header&lt;/b&gt;&lt;p&gt;
Source: 3M</description>
<gates>
<gate name="-1" symbol="PINV" x="0" y="0" addlevel="always"/>
<gate name="-2" symbol="PIN" x="0" y="-2.54" addlevel="always"/>
<gate name="-3" symbol="PIN" x="0" y="-5.08" addlevel="always"/>
<gate name="-4" symbol="PIN" x="0" y="-7.62" addlevel="always"/>
<gate name="-5" symbol="PIN" x="0" y="-10.16" addlevel="always"/>
<gate name="-6" symbol="PIN" x="0" y="-12.7" addlevel="always"/>
<gate name="-7" symbol="PIN" x="0" y="-15.24" addlevel="always"/>
<gate name="-8" symbol="PIN" x="0" y="-17.78" addlevel="always"/>
<gate name="-9" symbol="PIN" x="0" y="-20.32" addlevel="always"/>
<gate name="-10" symbol="PIN" x="0" y="-22.86" addlevel="always"/>
<gate name="-11" symbol="PIN" x="0" y="-25.4" addlevel="always"/>
<gate name="-12" symbol="PIN" x="0" y="-27.94" addlevel="always"/>
<gate name="-13" symbol="PIN" x="0" y="-30.48" addlevel="always"/>
<gate name="-14" symbol="PIN" x="0" y="-33.02" addlevel="always"/>
</gates>
<devices>
<device name="" package="PAK100/2500-14">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-10" pin="KL" pad="10"/>
<connect gate="-11" pin="KL" pad="11"/>
<connect gate="-12" pin="KL" pad="12"/>
<connect gate="-13" pin="KL" pad="13"/>
<connect gate="-14" pin="KL" pad="14"/>
<connect gate="-2" pin="KL" pad="2"/>
<connect gate="-3" pin="KL" pad="3"/>
<connect gate="-4" pin="KL" pad="4"/>
<connect gate="-5" pin="KL" pad="5"/>
<connect gate="-6" pin="KL" pad="6"/>
<connect gate="-7" pin="KL" pad="7"/>
<connect gate="-8" pin="KL" pad="8"/>
<connect gate="-9" pin="KL" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5575/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="5" package="PAK100/2500-5-14">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-10" pin="KL" pad="10"/>
<connect gate="-11" pin="KL" pad="11"/>
<connect gate="-12" pin="KL" pad="12"/>
<connect gate="-13" pin="KL" pad="13"/>
<connect gate="-14" pin="KL" pad="14"/>
<connect gate="-2" pin="KL" pad="2"/>
<connect gate="-3" pin="KL" pad="3"/>
<connect gate="-4" pin="KL" pad="4"/>
<connect gate="-5" pin="KL" pad="5"/>
<connect gate="-6" pin="KL" pad="6"/>
<connect gate="-7" pin="KL" pad="7"/>
<connect gate="-8" pin="KL" pad="8"/>
<connect gate="-9" pin="KL" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5577/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="N2514-5002RB" constant="no"/>
<attribute name="OC_FARNELL" value="1788673" constant="no"/>
<attribute name="OC_NEWARK" value="97K6709" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="X1" library="con-3m" library_urn="urn:adsk.eagle:library:119" deviceset="2514-" device="" package3d_urn="urn:adsk.eagle:package:5575/1"/>
<part name="X2" library="con-3m" library_urn="urn:adsk.eagle:library:119" deviceset="2514-" device="" package3d_urn="urn:adsk.eagle:package:5575/1"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="43.18" y="86.36" size="1.778" layer="97">Array</text>
<text x="96.52" y="83.82" size="1.778" layer="97">Circuit</text>
</plain>
<instances>
<instance part="X1" gate="-1" x="48.26" y="76.2"/>
<instance part="X1" gate="-2" x="48.26" y="73.66"/>
<instance part="X1" gate="-3" x="48.26" y="71.12"/>
<instance part="X1" gate="-4" x="48.26" y="68.58"/>
<instance part="X1" gate="-5" x="48.26" y="66.04"/>
<instance part="X1" gate="-6" x="48.26" y="63.5"/>
<instance part="X1" gate="-7" x="48.26" y="60.96"/>
<instance part="X1" gate="-8" x="48.26" y="58.42"/>
<instance part="X1" gate="-9" x="48.26" y="55.88"/>
<instance part="X1" gate="-10" x="48.26" y="53.34"/>
<instance part="X1" gate="-11" x="48.26" y="50.8"/>
<instance part="X1" gate="-12" x="48.26" y="48.26"/>
<instance part="X1" gate="-13" x="48.26" y="45.72"/>
<instance part="X1" gate="-14" x="48.26" y="43.18"/>
<instance part="X2" gate="-1" x="99.06" y="43.18" rot="R180"/>
<instance part="X2" gate="-2" x="99.06" y="45.72" rot="R180"/>
<instance part="X2" gate="-3" x="99.06" y="48.26" rot="R180"/>
<instance part="X2" gate="-4" x="99.06" y="50.8" rot="R180"/>
<instance part="X2" gate="-5" x="99.06" y="53.34" rot="R180"/>
<instance part="X2" gate="-6" x="99.06" y="55.88" rot="R180"/>
<instance part="X2" gate="-7" x="99.06" y="58.42" rot="R180"/>
<instance part="X2" gate="-8" x="99.06" y="60.96" rot="R180"/>
<instance part="X2" gate="-9" x="99.06" y="63.5" rot="R180"/>
<instance part="X2" gate="-10" x="99.06" y="66.04" rot="R180"/>
<instance part="X2" gate="-11" x="99.06" y="68.58" rot="R180"/>
<instance part="X2" gate="-12" x="99.06" y="71.12" rot="R180"/>
<instance part="X2" gate="-13" x="99.06" y="73.66" rot="R180"/>
<instance part="X2" gate="-14" x="99.06" y="76.2" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="X1" gate="-1" pin="KL"/>
<pinref part="X2" gate="-14" pin="KL"/>
<wire x1="53.34" y1="76.2" x2="93.98" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="X1" gate="-3" pin="KL"/>
<wire x1="53.34" y1="71.12" x2="60.96" y2="71.12" width="0.1524" layer="91"/>
<wire x1="60.96" y1="71.12" x2="60.96" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X2" gate="-13" pin="KL"/>
<wire x1="60.96" y1="73.66" x2="93.98" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="X1" gate="-5" pin="KL"/>
<wire x1="53.34" y1="66.04" x2="63.5" y2="66.04" width="0.1524" layer="91"/>
<wire x1="63.5" y1="66.04" x2="63.5" y2="68.58" width="0.1524" layer="91"/>
<pinref part="X2" gate="-11" pin="KL"/>
<wire x1="63.5" y1="68.58" x2="93.98" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="X1" gate="-7" pin="KL"/>
<wire x1="53.34" y1="60.96" x2="66.04" y2="60.96" width="0.1524" layer="91"/>
<wire x1="66.04" y1="60.96" x2="66.04" y2="63.5" width="0.1524" layer="91"/>
<pinref part="X2" gate="-9" pin="KL"/>
<wire x1="66.04" y1="63.5" x2="93.98" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="X1" gate="-9" pin="KL"/>
<wire x1="53.34" y1="55.88" x2="68.58" y2="55.88" width="0.1524" layer="91"/>
<wire x1="68.58" y1="55.88" x2="68.58" y2="58.42" width="0.1524" layer="91"/>
<pinref part="X2" gate="-7" pin="KL"/>
<wire x1="68.58" y1="58.42" x2="93.98" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="X1" gate="-11" pin="KL"/>
<wire x1="53.34" y1="50.8" x2="71.12" y2="50.8" width="0.1524" layer="91"/>
<wire x1="71.12" y1="50.8" x2="71.12" y2="53.34" width="0.1524" layer="91"/>
<pinref part="X2" gate="-5" pin="KL"/>
<wire x1="71.12" y1="53.34" x2="93.98" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="X1" gate="-13" pin="KL"/>
<wire x1="53.34" y1="45.72" x2="73.66" y2="45.72" width="0.1524" layer="91"/>
<wire x1="73.66" y1="45.72" x2="73.66" y2="48.26" width="0.1524" layer="91"/>
<pinref part="X2" gate="-3" pin="KL"/>
<wire x1="73.66" y1="48.26" x2="93.98" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="X1" gate="-14" pin="KL"/>
<pinref part="X2" gate="-1" pin="KL"/>
<wire x1="53.34" y1="43.18" x2="93.98" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="X1" gate="-2" pin="KL"/>
<wire x1="53.34" y1="73.66" x2="58.42" y2="73.66" width="0.1524" layer="91"/>
<wire x1="58.42" y1="73.66" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<wire x1="58.42" y1="78.74" x2="86.36" y2="78.74" width="0.1524" layer="91"/>
<wire x1="86.36" y1="78.74" x2="86.36" y2="55.88" width="0.1524" layer="91"/>
<pinref part="X2" gate="-2" pin="KL"/>
<wire x1="86.36" y1="55.88" x2="86.36" y2="50.8" width="0.1524" layer="91"/>
<wire x1="86.36" y1="50.8" x2="86.36" y2="45.72" width="0.1524" layer="91"/>
<wire x1="86.36" y1="45.72" x2="93.98" y2="45.72" width="0.1524" layer="91"/>
<pinref part="X2" gate="-4" pin="KL"/>
<wire x1="93.98" y1="50.8" x2="86.36" y2="50.8" width="0.1524" layer="91"/>
<junction x="86.36" y="50.8"/>
<pinref part="X2" gate="-6" pin="KL"/>
<wire x1="93.98" y1="55.88" x2="86.36" y2="55.88" width="0.1524" layer="91"/>
<junction x="86.36" y="55.88"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="X1" gate="-4" pin="KL"/>
<wire x1="53.34" y1="68.58" x2="55.88" y2="68.58" width="0.1524" layer="91"/>
<wire x1="55.88" y1="68.58" x2="55.88" y2="81.28" width="0.1524" layer="91"/>
<wire x1="55.88" y1="81.28" x2="83.82" y2="81.28" width="0.1524" layer="91"/>
<wire x1="83.82" y1="81.28" x2="83.82" y2="71.12" width="0.1524" layer="91"/>
<pinref part="X2" gate="-8" pin="KL"/>
<wire x1="83.82" y1="71.12" x2="83.82" y2="66.04" width="0.1524" layer="91"/>
<wire x1="83.82" y1="66.04" x2="83.82" y2="60.96" width="0.1524" layer="91"/>
<wire x1="83.82" y1="60.96" x2="93.98" y2="60.96" width="0.1524" layer="91"/>
<pinref part="X2" gate="-10" pin="KL"/>
<wire x1="93.98" y1="66.04" x2="83.82" y2="66.04" width="0.1524" layer="91"/>
<junction x="83.82" y="66.04"/>
<pinref part="X2" gate="-12" pin="KL"/>
<wire x1="93.98" y1="71.12" x2="83.82" y2="71.12" width="0.1524" layer="91"/>
<junction x="83.82" y="71.12"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
