object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 780
  ClientWidth = 1091
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  WindowState = wsMaximized
  TextHeight = 15
  object CrearMemoria: TButton
    Left = 8
    Top = 42
    Width = 105
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = CrearMemoriaClick
  end
  object PedirEspacio: TButton
    Left = 8
    Top = 73
    Width = 105
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = PedirEspacioClick
  end
  object LiberarEspacio: TButton
    Left = 8
    Top = 104
    Width = 105
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = LiberarEspacioClick
  end
  object CrearPolinomio: TButton
    Left = 8
    Top = 225
    Width = 105
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 3
    OnClick = CrearPolinomioClick
  end
  object PonerTermino: TButton
    Left = 8
    Top = 256
    Width = 105
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 4
    OnClick = PonerTerminoClick
  end
  object MostrarPolinomio: TButton
    Left = 8
    Top = 287
    Width = 105
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 5
    OnClick = MostrarPolinomioClick
  end
  object Derivar: TButton
    Left = 8
    Top = 318
    Width = 105
    Height = 25
    Caption = 'Derivar'
    TabOrder = 6
    OnClick = DerivarClick
  end
  object Salir: TButton
    Left = 8
    Top = 380
    Width = 105
    Height = 25
    Caption = 'Salir'
    TabOrder = 7
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 128
    Top = 76
    Width = 104
    Height = 23
    TabOrder = 8
    TextHint = 'ci,fono,edad'
  end
  object Edit2: TEdit
    Left = 128
    Top = 105
    Width = 49
    Height = 23
    TabOrder = 9
    TextHint = '0'
  end
  object Edit3: TEdit
    Left = 128
    Top = 134
    Width = 49
    Height = 23
    TabOrder = 10
    TextHint = 'dir'
  end
  object Edit4: TEdit
    Left = 183
    Top = 134
    Width = 49
    Height = 23
    TabOrder = 11
    Text = '->'
  end
  object Edit5: TEdit
    Left = 238
    Top = 134
    Width = 49
    Height = 23
    TabOrder = 12
    TextHint = 'valo'
  end
  object Edit6: TEdit
    Left = 128
    Top = 167
    Width = 49
    Height = 23
    TabOrder = 13
    Text = '0'
  end
  object PonerDato: TButton
    Left = 8
    Top = 135
    Width = 105
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 14
    OnClick = PonerDatoClick
  end
  object MostrarSM: TButton
    Left = 8
    Top = 166
    Width = 105
    Height = 25
    Caption = 'Mostrar SM'
    TabOrder = 15
    OnClick = MostrarSMClick
  end
  object Edit7: TEdit
    Left = 183
    Top = 167
    Width = 49
    Height = 23
    TabOrder = 16
    Text = '11'
  end
  object Edit8: TEdit
    Left = 128
    Top = 259
    Width = 49
    Height = 23
    TabOrder = 17
    TextHint = 'coef'
  end
  object Edit9: TEdit
    Left = 183
    Top = 259
    Width = 49
    Height = 23
    TabOrder = 18
    TextHint = 'exp'
  end
  object Edit10: TEdit
    Left = 128
    Top = 288
    Width = 49
    Height = 23
    TabOrder = 19
    Text = '0'
  end
  object Edit11: TEdit
    Left = 183
    Top = 288
    Width = 49
    Height = 23
    TabOrder = 20
    Text = '11'
  end
  object GraficarPolinomio: TButton
    Left = 8
    Top = 349
    Width = 105
    Height = 25
    Caption = 'Graficar Polinomio'
    TabOrder = 21
    OnClick = GraficarPolinomioClick
  end
  object Edit12: TEdit
    Left = 128
    Top = 351
    Width = 49
    Height = 23
    TabOrder = 22
    Text = '-5'
  end
  object Edit13: TEdit
    Left = 183
    Top = 351
    Width = 49
    Height = 23
    TabOrder = 23
    Text = '5'
  end
  object Button1: TButton
    Left = 38
    Top = 472
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 24
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 38
    Top = 512
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 25
    OnClick = Button2Click
  end
end
