<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:str="http://exslt.org/strings"
                xmlns:exsl="http://exslt.org/common"
                extension-element-prefixes="exsl str"
                xmlns:dia="http://www.daa.com.au/~james/dia-shape-ns"
                xmlns="http://www.w3.org/2000/svg"
                xmlns:svg="http://www.w3.org/2000/svg"
                xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
                exclude-result-prefixed="svg"
                >
  <xsl:output method="xml" omit-xml-declaration="no" indent="yes" />
  <xsl:strip-space elements="*" />

  <xsl:template match="/">
    <xsl:apply-templates select="//svg|//svg:svg"/>
  </xsl:template>
  
  <xsl:template match="svg|svg:svg">
    <xsl:element name="{local-name()}" namespace="{namespace-uri()}">
      <xsl:apply-templates select="@*"/>
      <g inkscape:groupmode="layer" inkscape:label="shape" id="shape">
        <xsl:apply-templates select="node()"/>
        <!-- copy in text name if there is one -->
        <xsl:if test="../*[name()='textbox']">
          <xsl:variable name="x" select="(../*[name()='textbox']/@x2 + ../*[name()='textbox']/@x1 ) div 2"/>
          <xsl:variable name="y" select="(../*[name()='textbox']/@y2 + ../*[name()='textbox']/@y1 ) div 2"/>
          <text id="textbox" style="font-family:Bitstream Vera Sans;font-weight:normal;font-style:normal;font-stretch:normal;font-variant:normal;font-size:0.5px;text-anchor:start;text-align:start;writing-mode:lr;line-height:125%">
            <xsl:attribute name="x"><xsl:value-of select="$x"/></xsl:attribute>
            <xsl:attribute name="y"><xsl:value-of select="$y"/></xsl:attribute>
            <tspan style="font-family:Bitstream Vera Sans;font-weight:normal;font-style:normal;font-stretch:normal;font-variant:normal;font-size:0.5px;text-anchor:middle;text-align:center;writing-mode:lr;line-height:125%">
              <xsl:attribute name="x"><xsl:value-of select="$x"/></xsl:attribute>
              <xsl:attribute name="y"><xsl:value-of select="$y"/></xsl:attribute>
              <xsl:value-of select="../*[name()='name']"/>
            </tspan>
          </text>
        </xsl:if>
      </g>

      <!-- now import connection points -->
      <g inkscape:groupmode="layer" inkscape:label="connections" id="connections">
        <xsl:variable name="size" select="0.1"/>
        <xsl:for-each select="../*[name()='connections']/*[name()='point']">
          <!-- do tiny rectangles for each one, width width 1 fill no stroke -->
          <rect id="{concat('connection_',position())}" style="stroke: none; fill: #000000" width="{$size}" height="{$size}">
            <xsl:if test="@main">
              <xsl:attribute name="main"><xsl:value-of select="@main"/></xsl:attribute>
            </xsl:if>
            <xsl:attribute name="x"><xsl:value-of select="@x - ($size div 2)"/></xsl:attribute>
            <xsl:attribute name="y"><xsl:value-of select="@y - ($size div 2)"/></xsl:attribute>
          </rect>
        </xsl:for-each>
      </g>
    </xsl:element>
  </xsl:template>
  
  <!-- add fill:none -->
  <xsl:template match="svg:polyline[not(@style)]|polyline[not(@style)]">
    <xsl:attribute name="style">fill:none</xsl:attribute>
  </xsl:template>  

  <!-- formally express all the style assumptions that dia makes and inkscape doesn't -->
  <xsl:template name="style">
    <xsl:param name="style" select="."/>

    <!-- replace :foreground with black -->
    <xsl:for-each select="str:tokenize($style,';')">
      <!-- some shapes are slack and miss the ;, we can tell if they have more than one space after normalizing space -->
      <xsl:variable name="stylet" select="normalize-space(.)"/>
      
      <xsl:variable name="property" select="normalize-space(substring-before($stylet,':'))"/>
      <xsl:variable name="value" select="normalize-space(substring-after($stylet,':'))"/>
      <xsl:choose>
        <!-- for some reason divide stroke width by 10 for inkscape. I think it gets them wrong -->
        <xsl:when test="$property='fill' and $value='default'">
          <xsl:value-of select="$property"/><xsl:text>:none; </xsl:text>
        </xsl:when>
        <xsl:when test="$property='stroke-width'">
          <xsl:text>stroke-width: </xsl:text><xsl:value-of select="$value div 10"/><xsl:text>; </xsl:text>
        </xsl:when>
        <xsl:when test="$value='foreground'">
          <xsl:value-of select="$property"/><xsl:text>:#000000; </xsl:text>
        </xsl:when>
        <xsl:when test="$value='background'">
          <xsl:value-of select="$property"/><xsl:text>:#ffffff; </xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="."/><xsl:text>; </xsl:text>
        </xsl:otherwise>
      </xsl:choose>
      <!-- if there is no fill mentioned, set fill to none -->
    </xsl:for-each>
    <xsl:if test="not(substring-after($style,'fill:'))">fill:none;</xsl:if>
    <xsl:if test="not(substring-after($style,'stroke:'))">stroke:#000000;</xsl:if>
    <xsl:if test="not(substring-after($style,'stroke-width:'))">stroke-width:0.1;</xsl:if>
  </xsl:template>
  
  <xsl:template match="@style">
    <xsl:attribute name="{name()}">
      <xsl:call-template name="style"/>
    </xsl:attribute>  
  </xsl:template>  
  
  <xsl:template match="svg:path[not(@style)]|path[not(@style)]">
    <xsl:copy>
      <xsl:apply-templates select="@*"/>
      <xsl:attribute name="style">
        <xsl:call-template name="style">
          <xsl:with-param name="style" select="''"/>
        </xsl:call-template>
      </xsl:attribute>
      <xsl:apply-templates select="node()"/>
    </xsl:copy>
  </xsl:template>

  <xsl:template match="@*">
    <xsl:copy select="."/>
  </xsl:template>  
  
  <xsl:template match="node()">
    <xsl:copy>
      <xsl:apply-templates select="@*"/>
      <xsl:apply-templates select="node()"/>
    </xsl:copy>
  </xsl:template>
</xsl:transform>
