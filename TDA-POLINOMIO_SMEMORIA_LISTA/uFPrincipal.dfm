object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 797
  ClientWidth = 1056
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
    Width = 113
    Height = 25
    Caption = 'CrearMemoria'
    TabOrder = 0
    OnClick = CrearMemoriaClick
  end
  object PedirEspacio: TButton
    Left = 8
    Top = 104
    Width = 113
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = PedirEspacioClick
  end
  object LiberarEspacio: TButton
    Left = 8
    Top = 144
    Width = 113
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = LiberarEspacioClick
  end
  object CrearPolinomio: TButton
    Left = 8
    Top = 264
    Width = 113
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 3
    OnClick = CrearPolinomioClick
  end
  object PonerTermino: TButton
    Left = 8
    Top = 304
    Width = 113
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 4
    OnClick = PonerTerminoClick
  end
  object MostrarPolinomio: TButton
    Left = 8
    Top = 344
    Width = 113
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 5
    OnClick = MostrarPolinomioClick
  end
  object Derivar: TButton
    Left = 8
    Top = 384
    Width = 113
    Height = 25
    Caption = 'Derivar'
    TabOrder = 6
    OnClick = DerivarClick
  end
  object Salir: TButton
    Left = 8
    Top = 424
    Width = 113
    Height = 25
    Caption = 'Salir'
    TabOrder = 7
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 136
    Top = 105
    Width = 104
    Height = 23
    TabOrder = 8
    TextHint = 'ci,fono,edad'
  end
  object Edit2: TEdit
    Left = 136
    Top = 145
    Width = 49
    Height = 23
    TabOrder = 9
    TextHint = '0'
  end
  object Edit3: TEdit
    Left = 136
    Top = 186
    Width = 49
    Height = 23
    TabOrder = 10
    TextHint = 'dir'
  end
  object Edit4: TEdit
    Left = 191
    Top = 186
    Width = 49
    Height = 23
    TabOrder = 11
    Text = '->'
  end
  object Edit5: TEdit
    Left = 246
    Top = 186
    Width = 49
    Height = 23
    TabOrder = 12
    TextHint = 'valor'
  end
  object Edit6: TEdit
    Left = 136
    Top = 305
    Width = 49
    Height = 23
    TabOrder = 13
    TextHint = 'coef'
  end
  object PonerDato: TButton
    Left = 8
    Top = 185
    Width = 113
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 14
    OnClick = PonerDatoClick
  end
  object Edit7: TEdit
    Left = 191
    Top = 305
    Width = 49
    Height = 23
    TabOrder = 15
    TextHint = 'exp'
  end
  object Edit8: TEdit
    Left = 136
    Top = 345
    Width = 49
    Height = 23
    TabOrder = 16
    Text = '0'
  end
  object Edit9: TEdit
    Left = 191
    Top = 345
    Width = 49
    Height = 23
    TabOrder = 17
    Text = '11'
  end
  object Evaluar: TButton
    Left = 8
    Top = 488
    Width = 113
    Height = 25
    Caption = 'Evaluar'
    TabOrder = 18
    OnClick = EvaluarClick
  end
  object Button1: TButton
    Left = 165
    Top = 488
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 19
    OnClick = Button1Click
  end
  object CrearLista: TButton
    Left = 8
    Top = 225
    Width = 113
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 20
    OnClick = CrearListaClick
  end
  object Button2: TButton
    Left = 165
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 21
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 165
    Top = 576
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 22
    OnClick = Button3Click
  end
end
