object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 780
  ClientWidth = 982
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearMemoria: TButton
    Left = 8
    Top = 24
    Width = 120
    Height = 25
    Caption = 'CrearMemoria'
    TabOrder = 0
    OnClick = CrearMemoriaClick
  end
  object PedirEspacioSM: TButton
    Left = 8
    Top = 64
    Width = 120
    Height = 25
    Caption = 'Pedir Espacio SM'
    TabOrder = 1
    OnClick = PedirEspacioSMClick
  end
  object CrearConjA: TButton
    Left = 8
    Top = 144
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto A'
    TabOrder = 2
    OnClick = CrearConjAClick
  end
  object CrearConjB: TButton
    Left = 8
    Top = 184
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto B'
    TabOrder = 3
    OnClick = CrearConjBClick
  end
  object CrearConjC: TButton
    Left = 8
    Top = 224
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto C'
    TabOrder = 4
    OnClick = CrearConjCClick
  end
  object InsertaElemento: TButton
    Left = 8
    Top = 264
    Width = 120
    Height = 49
    Caption = 'Insertar Elemento'
    TabOrder = 5
    OnClick = InsertaElementoClick
  end
  object MostrarConjunto: TButton
    Left = 8
    Top = 328
    Width = 120
    Height = 49
    Caption = 'Mostrar Conjunto'
    TabOrder = 6
    OnClick = MostrarConjuntoClick
  end
  object UnirEnC: TButton
    Left = 8
    Top = 392
    Width = 120
    Height = 49
    Caption = 'Unir en C'
    TabOrder = 7
    OnClick = UnirEnCClick
  end
  object IntersectarEnC: TButton
    Left = 8
    Top = 456
    Width = 120
    Height = 51
    Caption = 'Interserctar en C'
    TabOrder = 8
    OnClick = IntersectarEnCClick
  end
  object MostrarMemoriaConj: TButton
    Left = 8
    Top = 521
    Width = 120
    Height = 25
    Caption = 'Mostar Memoria'
    TabOrder = 9
    OnClick = MostrarMemoriaConjClick
  end
  object Salir: TButton
    Left = 8
    Top = 560
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 10
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 144
    Top = 65
    Width = 121
    Height = 23
    TabOrder = 11
  end
  object Edit2: TEdit
    Left = 144
    Top = 264
    Width = 121
    Height = 23
    TabOrder = 12
    TextHint = 'A,B,C'
  end
  object Edit3: TEdit
    Left = 144
    Top = 293
    Width = 121
    Height = 23
    TabOrder = 13
    TextHint = 'Elemento'
  end
  object Edit4: TEdit
    Left = 144
    Top = 341
    Width = 121
    Height = 23
    TabOrder = 14
    TextHint = 'A,B,C'
  end
  object CrearLista: TButton
    Left = 8
    Top = 103
    Width = 120
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 15
    OnClick = CrearListaClick
  end
  object Button1: TButton
    Left = 144
    Top = 640
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 16
    OnClick = Button1Click
  end
end
