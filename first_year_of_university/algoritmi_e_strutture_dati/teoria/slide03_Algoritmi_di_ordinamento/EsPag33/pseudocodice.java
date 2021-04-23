



/*

  Si assuma che dato un array con lunghezza 10, array.length ritorni 10.


  // V1
  reorder (Colors[] colorsArr) --> void
    for (int pos = 0; pos < colorsArr.length; pos++)
      if (colorsArr[pos] == GREEN) headChange (colorsArr, pos)
      else if (colorsArr[pos] == RED) bootmChange(colorsArr, pos)

  headChange (Colors[] colorsArr, int pos) --> void
    Color tmp = colorsArr[0];
    colorsArr[0] = colorsArr[pos]
    colros[pos] = tmp

  bootmChange (Colors[] colorsArr, int pos) --> void
    Color tmp = colorsArr[colorsArr.length - 1];
    colorsArr[colorsArr.length - 1] = colorsArr[pos]
    colros[pos] = tmp


    
  // V2
  reorder (Colors[] colorsArr) --> void
    for (int pos = 0; pos < colorsArr.length; pos++)
      if (colorsArr[pos] == GREEN) change (colorsArr, pos, 0)
      else if (colorsArr[pos] == RED) change (colorsArr, pos, colorsArrlength - 1)

  change (Colors[] colorsArr, int startPos, int finalPos) --> void
    Color tmp = colorsArr[finalPos];
    colorsArr[finalPos] = colorsArr[pos]
    colros[pos] = tmp

*/
