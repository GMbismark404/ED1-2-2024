object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearMemoria: TButton
    Left = 8
    Top = 64
    Width = 105
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = CrearMemoriaClick
  end
  object PedirEspacio: TButton
    Left = 8
    Top = 104
    Width = 105
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = PedirEspacioClick
  end
  object LiberarEspacio: TButton
    Left = 8
    Top = 144
    Width = 105
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = LiberarEspacioClick
  end
  object CrearPolinomio: TButton
    Left = 8
    Top = 184
    Width = 105
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 3
    OnClick = CrearPolinomioClick
  end
  object PonerTermino: TButton
    Left = 8
    Top = 224
    Width = 105
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 4
    OnClick = PonerTerminoClick
  end
  object MostrarPolinomio: TButton
    Left = 8
    Top = 264
    Width = 105
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 5
    OnClick = MostrarPolinomioClick
  end
  object Derivar: TButton
    Left = 8
    Top = 304
    Width = 105
    Height = 25
    Caption = 'Derivar'
    TabOrder = 6
    OnClick = DerivarClick
  end
  object Salir: TButton
    Left = 8
    Top = 344
    Width = 105
    Height = 25
    Caption = 'Salir'
    TabOrder = 7
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 128
    Top = 105
    Width = 104
    Height = 23
    TabOrder = 8
    TextHint = 'ci,fono,edad'
  end
  object Edit2: TEdit
    Left = 128
    Top = 145
    Width = 49
    Height = 23
    TabOrder = 9
    TextHint = '0'
  end
  object Edit3: TEdit
    Left = 128
    Top = 225
    Width = 49
    Height = 23
    TabOrder = 10
    TextHint = 'coef'
  end
  object Edit4: TEdit
    Left = 183
    Top = 225
    Width = 49
    Height = 23
    TabOrder = 11
    TextHint = 'exp'
  end
  object Edit5: TEdit
    Left = 128
    Top = 265
    Width = 49
    Height = 23
    TabOrder = 12
    Text = '0'
  end
  object Edit6: TEdit
    Left = 183
    Top = 265
    Width = 49
    Height = 23
    TabOrder = 13
    Text = '11'
  end
end
