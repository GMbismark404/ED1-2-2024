object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 704
  ClientWidth = 950
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearSMemoria: TButton
    Left = 8
    Top = 16
    Width = 130
    Height = 25
    Caption = 'Crear SMemoria'
    TabOrder = 0
    OnClick = CrearSMemoriaClick
  end
  object PedirEspacioSM: TButton
    Left = 8
    Top = 55
    Width = 130
    Height = 25
    Caption = 'Pedir Espacio SM'
    TabOrder = 1
    OnClick = PedirEspacioSMClick
  end
  object CrearConjA: TButton
    Left = 8
    Top = 94
    Width = 130
    Height = 25
    Caption = 'Crear Conjunto A'
    TabOrder = 2
    OnClick = CrearConjAClick
  end
  object CrearConjB: TButton
    Left = 8
    Top = 133
    Width = 130
    Height = 25
    Caption = 'Crear Conjunto B'
    TabOrder = 3
    OnClick = CrearConjBClick
  end
  object CrearConjC: TButton
    Left = 8
    Top = 172
    Width = 130
    Height = 25
    Caption = 'Crear Conjunto C'
    TabOrder = 4
    OnClick = CrearConjCClick
  end
  object InsertarElementoConj: TButton
    Left = 8
    Top = 211
    Width = 130
    Height = 54
    Caption = 'Insertar elemento'
    TabOrder = 5
    OnClick = InsertarElementoConjClick
  end
  object MostrarConjunto: TButton
    Left = 8
    Top = 271
    Width = 130
    Height = 54
    Caption = 'Mostrar Conjunto'
    TabOrder = 6
    OnClick = MostrarConjuntoClick
  end
  object UnirEnC: TButton
    Left = 8
    Top = 331
    Width = 130
    Height = 54
    Caption = 'Unir En C'
    TabOrder = 7
    OnClick = UnirEnCClick
  end
  object IntersectarEnC: TButton
    Left = 8
    Top = 391
    Width = 130
    Height = 54
    Caption = 'Intersectar En C'
    TabOrder = 8
    OnClick = IntersectarEnCClick
  end
  object MostrarSMemoria: TButton
    Left = 8
    Top = 464
    Width = 130
    Height = 25
    Caption = 'Mostrar Memoria SM'
    TabOrder = 9
    OnClick = MostrarSMemoriaClick
  end
  object Salir: TButton
    Left = 8
    Top = 504
    Width = 130
    Height = 25
    Caption = 'Salir'
    TabOrder = 10
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 152
    Top = 56
    Width = 121
    Height = 23
    TabOrder = 11
  end
  object Edit2: TEdit
    Left = 152
    Top = 211
    Width = 121
    Height = 23
    TabOrder = 12
    TextHint = 'A,B,C'
  end
  object Edit3: TEdit
    Left = 152
    Top = 240
    Width = 121
    Height = 23
    TabOrder = 13
    TextHint = 'elemento'
  end
  object Edit4: TEdit
    Left = 152
    Top = 286
    Width = 121
    Height = 23
    TabOrder = 14
    TextHint = 'A,B,C'
  end
  object Button1: TButton
    Left = 63
    Top = 584
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 15
    OnClick = Button1Click
  end
end
