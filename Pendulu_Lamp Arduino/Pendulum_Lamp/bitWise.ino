int getPosition (int btp)//Btp stands for bit position
{
  switch (btp)
  {
    case 0:
      return (0);
      break;

    case 1:
      return (1);
      break;

    case 2:
      return (2);
      break;

    case 4:
      return (3);
      break;

    case 8:
      return (4);
      break;

    case 16:
      return (5);
      break;

    case 32:
      return (6);
      break;

    case 64:
      return (7);
      break;

    case 128:
      return (8);
      break;

    default:
      Serial.println ("Sensor Array Exception");
      break;
  }
}

