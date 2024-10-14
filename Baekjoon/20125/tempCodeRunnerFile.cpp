int leftHand = 0;
  for(int i = heartCol - 1; i >= 0; i--) {
    if(cookie[heartRow][i] != '*') {
      break;
    }

    leftHand++;
  }

  int rightHand = 0;
  for(int i = heartCol - 1; i < n; i++) {
    if(cookie[heartRow][i] != '*') {
      break;
    }

    rightHand++;
  }

  int waist = 0;
  for(int i = heartRow - 1; i < n; i++) {
    if(cookie[i][heartCol] != '*') {
      
      break;
    }

    waist++;
  }

  int leftLeg = 0;
  for(int i = heartRow + waist - 1; i < n; i++) {
    if(cookie[i][heartCol - 1] != '*') {
      break;
    }

    leftLeg++;
  }

  int rightLeg = 0;
  for(int i = heartRow + waist - 1; i < n; i++) {
    if(cookie[i][heartCol + 1] != '*') {
      break;
    }

    rightLeg++;
  }

  printf("%d %d\n", heartRow, heartCol);
  printf("%d %